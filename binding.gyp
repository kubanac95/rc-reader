{
  "targets": [
    {
      "target_name": "eVehicleRegistration",
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "sources": [
        "./src/eVehicleRegistration.cc",
        "./src/eVehicleRegistrationAPI.dll",
        "./scr/eVehicleRegistrationCOM.dll"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "libraries": [ 
        "<(module_root_dir)/src/eVehicleRegistrationAPI.lib"
      ],
      "conditions": [        
        ["OS==\"win\"", {
          "libraries": [ "<(module_root_dir)/src/eVehicleRegistrationAPI.lib" ],
          "copies": [
            {
              "destination": "<(module_root_dir)/build/Release/",
              "files": [ "<(module_root_dir)/src/eVehicleRegistrationAPI.dll" ]
            }
          ]
        }]
      ]
    }
  ]
}
