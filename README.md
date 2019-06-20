# Automatic File Organizer
It also takes in mind duplicates and renames them by adding a number to duplicate entries

## build
No external dependencies needed, just run the make command
`make`

`Usage: sortplus [-h help menu] [-t dry test run] [-o organize files] [directory]`

Example: `./sortplus -t /home/user/Desktop #This command gives you a preview of how the files will be organized`

```
avi/
    family_vacation.avi
    restored_family_video.avi
mp3/
    fun_podcast.mp3
    my_podcast.mp3
    voicereminder.mp3
txt/
    gear_serial_numbers.txt
````

and so on

`./sortplus -o /home/user/Desktop`

will move the files and group them by extension in their own folder as demostrated in the test output from the command before
