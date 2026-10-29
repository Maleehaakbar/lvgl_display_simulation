1. lvgl editor gives simulation of ui directly for lvgl on linux sdl2
2. the simulation with zephyr lvgl is little different from it as it includes zephyr and native sim settings.
3. remove the build errors that comes when integrate lvgl editor code to zephyr
4. include all prj.conf confogs for lvgl native_sim


ERRORS
  #include "lvgl.h"
  for use in zephyr, in generated files, replace  "lvgl.h"  with  <lvgl.h>
  as lvgl is included in zephyr as system library not a user library

 

imp point
Design your UI in the lvgl Editor and export to the project's ui/ folder. 
The application detects it automatically and builds it as a library,
 so re-exporting is all it takes to update the interface — no code changes needed

for zephyr, create lvgl editor project for zephyr (dont create vs code project)

when exporting from figma flow, files are also generated under ui/ folder

compile for native_sim 64

comment out       #include "lv_xml/lv_xml.h"  manually

if export font as files, give their path in ui_init(), otherwise make as files=false in xml ,save changes in 
editor and again export code 

Generate code after making changes in lvgl pro editor, then it takes effect

compile from yor project to see output for uour project , not from lvgl editor 

When you export C code from the LVGL Pro Editor, the XML files themselves are not modified, xml files
are then not needed

To use font from a file, need to add file system driver e.g CONFIG_LV_USE_FS_POSIX