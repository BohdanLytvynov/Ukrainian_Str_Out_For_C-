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
To be able to use this dll library you should use .dll file and .lib file. 

To use it you need:
- ukrString.h,
- ukrString.dll,
- ukrString.lib files.

1. ukrString.h has all functions and structures definitions to be used in external projects. For that include this .h file to your external project. 
2. ukrString.dll must be placed near your .exe file.
3. And you need to provide a propriate path for Linker to ukrString.lib file.

### Tests
All the units tests were performed. Their resuls can be seen in a test project. 


