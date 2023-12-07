# homework1 shell problem @drinktoomuchsax

disMenu(){
echo ""
echo "1. List all files in the present working directory"
echo "2. Display today's date and time"
echo "3. Display whether a file is a 'simple' file or a 'directory'"
echo "4. Create a backup for a file"
echo "5. Start an ftp session"
echo "6. Start your LED control program"
echo "7. Exit"
echo ""
}

disMenu

select choice in list date check backup ftp startLED quit
do
    case $choice in
        list) ls
                disMenu;;
        date) date;;
        check) echo "Enter the file path: "
            read file_path
           if [ -f $file_path ]; then
               echo "The file is a simple file."
           elif [ -d $file_path ]; then
               echo "The file is a directory."
           else
               echo "The file does not exist."
           fi;;
        backup) read -p "Enter the file path: " file_path
           cp $file_path $file_path.bak;;
        ftp)echo "Enter domain name or IP address "
            read IP
            ftp $IP;;
        startLED) ./hw1;;
        quit) exit;;
        *) echo "Invalid choice. Try again.";;
    esac
done