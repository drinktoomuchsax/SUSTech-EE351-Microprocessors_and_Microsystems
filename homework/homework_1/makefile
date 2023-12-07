# Make all: run all three targets
all: sort_file find_log delete_lock_file

# Make sort_file: list the file/directories with respect to the file size
sort_file:
	ls -S

# Make find_log: find the log file in your home directory (you may create some dummies)
find_log:
	find ~/ -name "*.log"

# Make delete_lock_file: find the lock files in your home directory and then delete them.
delete_lock_file:
	find ~/ -name "*.lock" -delete
