import os
import re
import shutil
import subprocess
from datetime import datetime
from pathlib import Path

# Paths can be absolute or relative. 
# For portfolio demonstration, we assume relative paths or environment setup.
SOURCE_DIR = r"../Problemas" 
REPO_DIR = os.getcwd()

def get_file_timestamp(filepath):
    """
    Retrieves the original modification time of the file 
    to preserve history in Git commits.
    """
    try:
        timestamp = os.path.getmtime(filepath)
        dt_object = datetime.fromtimestamp(timestamp)
        return dt_object.isoformat()
    except Exception as e:
        print(f"Warning: Could not get timestamp for {filepath}. Using current time.")
        return datetime.now().isoformat()

def classify_problem(filename):
    """
    Determines the target folder based on the file naming convention.
    Returns the folder name or None if the file should be ignored.
    """
    # Filter out common temporary or non-source files
    if filename.lower() in ["temp.cpp", "test.cpp", "a.cpp"]:
        return None

    # Pattern 1: Codeforces Modern (e.g., 1702E.cpp, 399A.cpp)
    if re.match(r"^\d+[a-zA-Z]", filename):
        return "Codeforces"
    
    # Pattern 2: Codeforces Past (e.g., A_Substring.cpp)
    elif re.match(r"^[A-Z]_", filename):
        return "Codeforces"
    
    # Pattern 3: CSES & Standard (e.g., BookShop.cpp, SlidingWindow.cpp)
    # Assumes CamelCase or PascalCase starting with a letter
    elif re.match(r"^[A-Z]", filename):
        return "CSES"

    # Fallback: OBI, Beecrowd, and unclassified problems
    return "Uncategorized"

def sync_files():
    processed_count = 0
    
    # Ensure source directory exists before running
    if not os.path.exists(SOURCE_DIR):
        print(f"Error: Source directory '{SOURCE_DIR}' not found.")
        return

    for filename in os.listdir(SOURCE_DIR):
        if not filename.endswith(".cpp"):
            continue

        source_path = os.path.join(SOURCE_DIR, filename)
        category = classify_problem(filename)

        if not category:
            continue

        # Prepare destination paths
        target_folder = os.path.join(REPO_DIR, category)
        target_path = os.path.join(target_folder, filename)

        # Create category folder if it doesn't exist
        os.makedirs(target_folder, exist_ok=True)

        # Copy file
        shutil.copy2(source_path, target_path)

        # Git Operations
        # Manually set the GIT_AUTHOR_DATE and GIT_COMMITTER_DATE
        # to reflect the actual time the problem was solved, not the push time.
        timestamp = get_file_timestamp(source_path)
        
        subprocess.run(["git", "add", target_path], cwd=REPO_DIR, check=True)
        
        env = os.environ.copy()
        env["GIT_AUTHOR_DATE"] = timestamp
        env["GIT_COMMITTER_DATE"] = timestamp

        commit_msg = f"Add solution for {filename} ({category})"
        
        # Suppress output for cleaner execution, allow empty commits if file didn't change
        subprocess.run(
            ["git", "commit", "-m", commit_msg], 
            cwd=REPO_DIR, 
            env=env, 
            stdout=subprocess.DEVNULL, 
            stderr=subprocess.DEVNULL
        )
        
        processed_count += 1

    print(f"Sync complete. {processed_count} files processed.")

if __name__ == "__main__":
    sync_files()