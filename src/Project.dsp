# Microsoft Developer Studio Project File - Name="Project" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Project - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Project.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Project.mak" CFG="Project - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Project - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Project - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Project - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Project - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Project - Win32 Release"
# Name "Project - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Ctrol"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ctrol.cpp
# End Source File
# Begin Source File

SOURCE=.\Ctrol_button.cpp
# End Source File
# Begin Source File

SOURCE=.\Ctrol_edit.cpp
# End Source File
# Begin Source File

SOURCE=.\Ctrol_label.cpp
# End Source File
# End Group
# Begin Group "Cwin"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CmanagerWin.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_addgoods.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_check.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_check_correct.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_check_details.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_check_record.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_delivery.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_homepage.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_login.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_out.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_popup.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_query.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_register.cpp
# End Source File
# Begin Source File

SOURCE=.\Cwin_warehousing.cpp
# End Source File
# End Group
# Begin Group "Ctool"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ctool.cpp
# End Source File
# Begin Source File

SOURCE=.\Ctool_form.cpp
# End Source File
# End Group
# Begin Group "Cdata"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Cdata.cpp
# End Source File
# Begin Source File

SOURCE=.\Cgoods.cpp
# End Source File
# Begin Source File

SOURCE=.\Cuser.cpp
# End Source File
# Begin Source File

SOURCE=.\user_admin.cpp
# End Source File
# Begin Source File

SOURCE=.\user_Checkers.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Ctrol_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ctrol.h
# End Source File
# Begin Source File

SOURCE=.\Ctrol_button.h
# End Source File
# Begin Source File

SOURCE=.\Ctrol_edit.h
# End Source File
# Begin Source File

SOURCE=.\Ctrol_label.h
# End Source File
# End Group
# Begin Group "Cwin_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CmanagerWin.h
# End Source File
# Begin Source File

SOURCE=.\Cwin.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_addgoods.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_check.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_check_correct.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_check_details.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_check_record.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_delivery.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_homepage.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_login.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_out.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_popup.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_query.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_register.h
# End Source File
# Begin Source File

SOURCE=.\Cwin_warehousing.h
# End Source File
# End Group
# Begin Group "Ctool_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Ctool.h
# End Source File
# Begin Source File

SOURCE=.\Ctool_form.h
# End Source File
# End Group
# Begin Group "Cdata_H"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Cdata.h
# End Source File
# Begin Source File

SOURCE=.\Cgoods.h
# End Source File
# Begin Source File

SOURCE=.\Cuser.h
# End Source File
# Begin Source File

SOURCE=.\user_admin.h
# End Source File
# Begin Source File

SOURCE=.\user_Checkers.h
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
