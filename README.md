# ESP32_SerialKeyboardHiD
Hey! All this was made by a Colombian Furry soo... Make sure to respect them!
## The ESP32 Takes the String you wrote in serial and writes character by character in the device connected to the bluetooth connection made by the ESP32 (only characters, not media, or others as F11... **Still, wait for update**)
## [EDUCATIONAL PURPOUSES ONLY PLEASE USE IT BY YOUR OWN RISK]

### Libraries needed:
Github;
ESP32-BLE-CompositeHID By Mysfit *Use the fork i made so the click function may work!*
https://github.com/IloThaFurPup/ESP32-BLE-CompositeHID
GitHub > Install .ZIP > Arduino IDE > Include library > Include .ZIP library > Chose installed .ZIP
Library manager (Arduino IDE);
Callback by Tom Steward
NimBLE-Arduino by h2zero
esp32 by espriff systems

I learned HTML (hints of JS and CSS), C++ and Python by my self so please support me! <333
IG: IloThaFurPup ^w^
YouTube: IloThaFurPup, I teach about microcontrollers 
Love yall!!! <3 Good luck!!!
New note: Fuck all the ones who dont teach the code and just "uhhhh use this example". 
if you are making a video you should explain the code for others, sucker. 
That's why i will start explaining my codes as soon as i can afford to (16/1/25)


⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  [ASCII by unknown]
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡘⢧⡀⠀⠀⢰⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡾⠁⠀⠙⢦⡀⢸⡏⠻⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣣⡆⠀⠀⠀⠙⠺⡇⠀⠀⠙⠳⠦⡀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣠⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠿⠒⠦⠴⠒⠓⠂⠀⠀⠀⠀⠀⠐⠒⠚⠛⠋⠉⠉⠉⠁⠀⠀⠀⠀⠉⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠛⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠙⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⢀⣠⣄⡀⠀⠀⠀⠀⢀⣠⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠃⠀⠀⠀⣰⠏⢉⣼⣧⠀⠀⠀⢠⣿⣅⠀⠀⢹⡆⠀⠀⠀⠀⠀⠀⢠⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡯⠀⢸⣿⣿⠀⠀⠀⣾⣿⣿⠀⠀⠀⣷⠀⠀⠀⠀⠀⢀⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠛⠁⢀⠈⠁⠀⢸⣿⣿⠀⠀⠀⢹⣿⣿⠀⠀⠀⠉⠀⠀⠀⠈⠛⢿⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⢸⣧⣴⣀⣄⠉⣁⠐⣳⢀⣨⣟⠋⠀⠀⣀⣴⣠⠀⠀⠀⢀⡼⠃⠀⠀⠀⢰⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⢶⡎⢳⣌⡉⠀⠀⠙⠻⣯⣉⢉⣿⠄⠀⠀⢉⣬⡿⠃⠀⠀⢾⡀⠀⠀⠀⠀⣸⠃⠙⠳⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⣀⡈⠙⠛⢳⡶⣤⣤⣭⣽⣭⡴⣶⠛⣿⣥⡄⢠⣤⣤⣼⡇⠀⡄⣾⠀⣿⠀⠀⠀⠀⠙⢦⡄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢰⡟⠛⠺⠷⢤⣤⣿⣿⣿⣤⡾⠟⣃⡿⠀⠀⠀⠀⠀⠀⠘⠃⡿⢀⡗⠀⠀⠀⠀⠀⠈⢻⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣆⠀⠀⠀⢸⣏⣌⡙⡇⠀⠀⠺⣦⠀⠀⠀⠀⠀⠀⣼⣄⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠹⣇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⣷⠀⠀⠀⠛⠛⠛⠁⠀⠀⣾⠁⠀⠀⠀⠀⠀⢰⡟⢹⣆⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡏⠁⠀⠀⠀⠀⣤⠀⠀⠀⢰⣾⠀⠀⠀⠀⠀⣠⡟⠀⠀⠿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⡟⠛⠛⠀⣠⡟⠀⠀⠀⢸⢹⡄⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⣿⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⣿⡇⠀⠀⠀⢸⠸⣇⣀⡴⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢻⠀⡄
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠀⠀⠀⣿⠀⠀⠀⠀⣿⠀⠻⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⢼⣰⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡶⠶⠛⠋⣿⠀⠀⢠⡏⠀⠀⠀⠀⡿⠀⠀⠙⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⢁⡿⠾⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⠿⠀⠀⠀⣿⠀⠀⣸⠃⠀⠀⠀⢠⡏⠀⠀⠀⠀⢹⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠈⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣟⠁⠀⠀⠀⠀⢶⣿⠀⢠⡟⠀⠀⠀⠀⢸⠅⠀⠀⠀⠀⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠃⠀⠀⠀⠀⠘⣿⢀⡾⠁⠀⠀⠀⠀⣿⠀⠀⠀⠀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠿⢦⣄⡀⠀⠀⠀⠀⡏⣼⠃⠀⠀⠀⠀⢀⡿⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣴⠟⠓⠤⡀⠈⠹⣦⡀⠀⠐⣷⣷⡇⠀⢠⡄⠀⣼⣃⣀⣀⣀⠀⠀⡇⠀⠀⠀⠲⣄⡀⠀⠀⠀⣈⡽⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⠿⠅⣀⠀⠀⠈⠳⡄⠸⣧⠀⣠⡿⠿⢷⢤⣬⣿⡾⠛⠉⠉⠉⠉⠷⣴⡇⠀⠀⠀⠀⠈⠙⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣠⡾⢁⡀⠀⠀⠑⢄⠀⠀⠸⣄⣿⠟⠉⠀⠀⠀⠀⠀⢸⣇⠤⠤⠦⠤⠤⢀⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢀⣴⠋⠀⠀⠈⠑⢄⠀⠀⢣⠀⣠⡟⠁⠀⠀⠀⠀⠀⠀⠀⢸⠇⠀⠀⠀⠀⠀⠀⠉⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢰⡏⣴⠉⠑⣢⣄⠀⠀⢳⣀⣴⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠈⠿⣏⠀⠀⢿⠀⣳⣤⡶⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀⣀⡀⠀⠀⠀⠀⢹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠋⠙⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠉⠓⠢⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀⠀⣀⣀⡀⠀⣸⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⢰⡇⠀⠀⢿⢑⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣷⣀⣤⣼⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

We will be able to write what we put in the serial to the connected computer!
