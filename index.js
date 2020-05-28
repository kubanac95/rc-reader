var native = require('./build/Release/eVehicleRegistration');

function readDocumentData() {
  return new Promise(function (resolve, reject) {
    native.readDocumentData(resolve, reject);
  })
};

function readPersonalData() {
  return new Promise(function (resolve, reject) {
    native.readPersonalData(resolve, reject);
  })
};

function readVehicleData() {
  return new Promise(function (resolve, reject) {
    native.readVehicleData(resolve, reject);
  })
};

// readDocumentData()
//   .then((success) => console.log(success))
//   .catch((error) => console.log(error))

module.exports = {
  readVehicleData,
  readDocumentData,
  readPersonalData,
};