# rc-reader

## 📋 Introduction

RC Reader is a simple Node.js wrapper around [eVehicleRegistration.lib](https://bit.ly/2TOrxXR) used to read Serbian vehicle registration certificates in [ICC](https://en.wikipedia.org/wiki/Smart_card) format with a smart card reader.

## 📖 Installation

This is a [Node.js](https://nodejs.org/en/) module available through the
[npm registry](https://www.npmjs.com/).

Before installing, [download and install Node.js](https://nodejs.org/en/download/).
Node.js v12.14.0 (32 bit) or higher is required.

If this is a brand new project, make sure to create a `package.json` first with
the [`npm init` command](https://docs.npmjs.com/creating-a-package-json-file).

Installation is done using the
[`npm install` command](https://docs.npmjs.com/getting-started/installing-npm-packages-locally):

```
npm install rc-reader
```

## Methods

- [`readVehicleData`](#readVehicleData)
- [`readPersonalData`](#readPersonalData)
- [`readDocumentData`](#readDocumentData)

### `.readVehicleData()`

Returns a `Promise` that resolves to an object containing following fields:

- **dateOfFirstRegistration _(string)_** -- Date of first registration
- **yearOfProduction _(string)_** -- Year of production
- **vehicleMake _(string)_** --
- **vehicleType _(string)_** --
- **commercialDescription _(string)_** --
- **vehicleIDNumber _(string)_** --
- **registrationNumberOfVehicle _(string)_** --
- **maximumNetPower _(string)_** --
- **engineCapacity _(string)_** --
- **typeOfFuel _(string)_** --
- **powerWeightRatio _(string)_** --
- **vehicleMass _(string)_** --
- **maximumPermissibleLadenMass _(string)_** --
- **typeApprovalNumber _(string)_** --
- **numberOfSeats _(string)_** --
- **numberOfStandingPlaces _(string)_** --
- **engineIDNumber _(string)_** --
- **numberOfAxles _(string)_** --
- **vehicleCategory _(string)_** --
- **colourOfVehicle _(string)_** --
- **restrictionToChangeOwner _(string)_** --
- **vehicleLoad _(string)_** --

### `.readPersonalData()`

Returns a `Promise` that resolves to an object containing following fields:

- **ownersPersonalNo _(string)_** --
- **ownersSurnameOrBusinessName _(string)_** --
- **ownerName _(string)_** --
- **ownerAddress _(string)_** --
- **usersPersonalNo _(string)_** --
- **usersSurnameOrBusinessName _(string)_** --
- **usersName _(string)_** --
- **usersAddress _(string)_** --

### `.readDocumentData()`

Returns a `Promise` that resolves to an object containing following fields:

- **stateIssuing _(string)_** --
- **competentAuthority _(string)_** --
- **authorityIssuing _(string)_** --
- **unambiguousNumber _(string)_** --
- **issuingDate _(string)_** --
- **expiryDate _(string)_** --
- **serialNumber _(string)_** --

## 📄 License

RC Reader is MIT licensed, as found in the [LICENSE][l] file.
