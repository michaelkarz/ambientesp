def main():
 print("opending file...")
 f = open('C:/Users/krypt/Documents/Arduino/AmbientESP/Html/index.html', 'r')
 str = f.read()
 f.close()
 str = str.replace('\n','\t\\r\\n\\\n')
 str = str.replace('"','\\"')
 # str = str.replace('data-slider-value=\\"30\\"','data-slider-value=\\"%4\\"')
 # str = str.replace('data-slider-value=\\"125\\"','data-slider-value=\\"%5\\"')
 # str = str.replace('data-slider-value=\\"124\\"','data-slider-value=\\"%6\\"')
 str = ('// Webpage.h\n#ifndef _WEBPAGE_h\n#define _WEBPAGE_h\n\nconst char* website = \n\n\"') + str + '";\n#endif'

 t = open('C:/Users/krypt/Documents/Arduino/AmbientESP/Webpage.h', 'w')
 t.write(str)
 t.close()
 # print(str)
 print("*h. file generated...")

 
 
 print("opending file...")
 f = open('C:/Users/krypt/Documents/Arduino/AmbientESP/Html/setup.html', 'r')
 str = f.read()
 f.close()
 str = str.replace('\n','\t\\r\\n\\\n')
 str = str.replace('"','\\"')
 str = ('// Webpage.h\n#ifndef _SETUPPAGE_h\n#define _SETUPPAGE_h\n\nconst char* setup_html = \n\n\"') + str + '";\n#endif'

 t = open('C:/Users/krypt/Documents/Arduino/AmbientESP/SetupHTML.h', 'w')
 t.write(str)
 t.close()
 # print(str)
 print("*h. file generated...")

if __name__ == "__main__":
 main()
