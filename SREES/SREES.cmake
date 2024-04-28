set(NAVIGATORTEST_NAME SREES)				#Naziv prvog projekta u solution-u

file(GLOB NAVIGATORTEST_SOURCES  ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB NAVIGATORTEST_INCS  ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
set(NAVIGATORTEST_PLIST  ${CMAKE_CURRENT_LIST_DIR}/src/Info.plist)
file(GLOB NAVIGATORTEST_INC_TD  ${MY_INC}/td/*.h)
file(GLOB NAVIGATORTEST_INC_GUI ${MY_INC}/gui/*.h)

# add executable
add_executable(${NAVIGATORTEST_NAME} ${NAVIGATORTEST_INCS} ${NAVIGATORTEST_SOURCES} ${NAVIGATORTEST_INC_TD}  ${NAVIGATORTEST_INC_GUI})

source_group("inc"            FILES ${NAVIGATORTEST_INCS})
source_group("src"            FILES ${NAVIGATORTEST_SOURCES})
source_group("inc\\td"        FILES ${NAVIGATORTEST_INC_TD})
source_group("inc\\gui"        FILES ${NAVIGATORTEST_INC_GUI})


target_link_libraries(${NAVIGATORTEST_NAME} debug ${MU_LIB_DEBUG} debug ${NATGUI_LIB_DEBUG} 
								optimized ${MU_LIB_RELEASE}  optimized ${NATGUI_LIB_RELEASE})

setTargetPropertiesForGUIApp(${NAVIGATORTEST_NAME} ${NAVIGATORTEST_PLIST})

setIDEPropertiesForExecutable(${NAVIGATORTEST_NAME})

setPlatformDLLPath(${NAVIGATORTEST_NAME})

#MU_DEBUG, MU_RELEASE, MU_64BIT, MU_32BIT
addMUCompileDefinitions(${NAVIGATORTEST_NAME})
