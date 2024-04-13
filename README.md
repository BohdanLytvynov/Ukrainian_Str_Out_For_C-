### Ukrainian String
When we write some console app and we need to use ukrainian localization, we have no opportunity to do this. The reasons for it are:
- Console works using special old code page MS DOS.
- But nowdays Windows Operating Sysem uses new code page, called 1251. All the information in modern programs uses 1251.
Like all the files in modern OS Windows.

Cause of this 2 reasons we have incorrect display for ukrainian language. To improve it slightly we can create a mechanism that can change codes of characters from 1251 to MS Dos during dislay.
This also gives us an opportunity to use new symbol elements. For example the famous ukrainian letters, such as i є ї. We need to change symbols only when we display ukrString. 

### What Additional Features Used Here
Here I used the RAII paradigm structure, called smart_allocator<T>, which is simillar to the unique_pointer. This structure helps us o maintain memory usage. 
In this project smart_allocator<T> is used to store the characters of the string in a form of the c-string. 

### DLL and Proper Linking
For correct usage of this library dll file for Smart_allocator must be put to the place where the executable file is located. Smart_allocator.obj file is located in objfiles folder.
For Linker .ob file must be used. 

There is an ukrString.h file in the include folder. It can be used to provide all the opportunities of this structure. All the functions in this structure are commented properly.

### Tests
All the units tests were performed. Their resuls can be seen in a test project. 


