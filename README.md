# Cache Cleaner

The program has two main functionalities, **Search** and **Clean**. It automates cleaning cache files -or any other type of files actually, using these two functionalities.


### Search

When specified -in the option menu, the program will look up all the directories that contain **_Cache_** or **_cache_** in their paths, starting from a single directory specified in the **to_be_searched.txt** -if its empty the program will do nothing.

Each path found will then be added to **to_be_cleaned.txt**.


### Clean

This is the second option in the option menu. It cleans all the folders/directories contained in **to_be_cleaned.txt** -if the file is empty nothing will happen.

You can also simply add the paths you want to be cleaned to the .txt file without the need to use **Search**. Keep in mind that after each **Clean** operation the files in **to_be_cleaned.txt** will be removed from the file.

I highly advise that to check the paths in **to_be_cleaned.txt** before cleaning, so that it won’t accidentally delete a sensitive file or any other file that is required for your system to run properly.
