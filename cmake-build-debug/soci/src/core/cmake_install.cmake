# Install script for directory: /Users/alexey/CLionProjects/untitled/lib/soci/src/core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/soci" TYPE FILE FILES
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/backend-loader.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/bind-values.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/blob-exchange.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/blob.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/boost-fusion.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/boost-gregorian-date.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/boost-optional.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/boost-tuple.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/callbacks.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/column-info.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/connection-parameters.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/connection-pool.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/error.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/exchange-traits.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/fixed-size-ints.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/into-type.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/into.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/is-detected.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/logger.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/noreturn.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/once-temp-type.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/prepare-temp-type.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/procedure.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/query_transformation.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/ref-counted-prepare-info.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/ref-counted-statement.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/row-exchange.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/row.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/rowid-exchange.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/rowid.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/rowset.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/session.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/soci-backend.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/soci-config.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/soci-platform.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/soci-simple.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/soci-types.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/soci.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/statement.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/std-optional.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/transaction.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/type-conversion-traits.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/type-conversion.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/type-holder.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/type-ptr.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/type-wrappers.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/use-type.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/use.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/values-exchange.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/values.h"
    "/Users/alexey/CLionProjects/untitled/lib/soci/include/soci/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/alexey/CLionProjects/untitled/cmake-build-debug/lib/libsoci_core.4.1.0.dylib"
    "/Users/alexey/CLionProjects/untitled/cmake-build-debug/lib/libsoci_core.4.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.4.1.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.4.1.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND "/usr/bin/install_name_tool"
        -id "/usr/local/lib/libsoci_core.4.1.dylib"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/alexey/CLionProjects/untitled/cmake-build-debug/lib/libsoci_core.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/alexey/CLionProjects/untitled/cmake-build-debug/lib/libsoci_core.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsoci_core.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets.cmake"
         "/Users/alexey/CLionProjects/untitled/cmake-build-debug/soci/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI/SOCITargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "/Users/alexey/CLionProjects/untitled/cmake-build-debug/soci/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES "/Users/alexey/CLionProjects/untitled/cmake-build-debug/soci/src/core/CMakeFiles/Export/39447b8616a7e0144dc6bdda034be1e2/SOCITargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SOCI" TYPE FILE FILES
    "/Users/alexey/CLionProjects/untitled/cmake-build-debug/soci/src/core/SOCIConfig.cmake"
    "/Users/alexey/CLionProjects/untitled/cmake-build-debug/soci/src/core/SOCIConfigVersion.cmake"
    )
endif()

