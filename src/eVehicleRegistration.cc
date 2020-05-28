#include <nan.h>
#include <string.h>
#include <iostream>
#include "eVehicleRegistrationAPI.h"
#include "eVehicleRegistrationCOM.h"

void startup(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  unsigned long initializeState = sdStartup(0);

  v8::Local<v8::Function> success = info[0].As<v8::Function>();
  v8::Local<v8::Function> error = info[1].As<v8::Function>();

  if (initializeState != S_OK)
  {
    v8::Local<v8::Value> argv[1] = {Nan::New(std::to_string(initializeState)).ToLocalChecked()};
    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), error, 1, argv);
    return;
  }

  v8::Local<v8::Value> argv[1] = {Nan::New("S_OK").ToLocalChecked()};
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), success, 1, argv);
}

void cleanup(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  sdCleanup();
  info.GetReturnValue().Set(Nan::New("Cleaning up done").ToLocalChecked());
}

unsigned long prepareReader()
{
  unsigned long statusCode = sdStartup(0);

  if (statusCode != S_OK)
  {
    return statusCode;
  }

  char readerName[64] = "";
  long nameSize = sizeof(char) * 64;
  statusCode = GetReaderName(0, &readerName[0], &nameSize);

  if (statusCode != S_OK)
  {
    return statusCode;
  }

  statusCode = SelectReader(&readerName[0]);

  if (statusCode != S_OK)
  {
    return statusCode;
  }

  statusCode = sdProcessNewCard();

  return statusCode;
}

void readDocumentData(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  unsigned long statusCode = prepareReader();

  v8::Local<v8::Function> success = info[0].As<v8::Function>();
  v8::Local<v8::Function> error = info[1].As<v8::Function>();

  if (statusCode != S_OK)
  {
    v8::Local<v8::Value> argv[1] = {Nan::New(std::to_string(statusCode)).ToLocalChecked()};
    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), error, 1, argv);

    sdCleanup();
    return;
  }

  SD_DOCUMENT_DATA *data = new SD_DOCUMENT_DATA();
  sdReadDocumentData(data);

  v8::Local<v8::Object> jsonObject = Nan::New<v8::Object>();

  Nan::Set(
      jsonObject,
      Nan::New("stateIssuing").ToLocalChecked(),
      Nan::New(data->stateIssuing).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("competentAuthority").ToLocalChecked(),
      Nan::New(data->competentAuthority).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("authorityIssuing").ToLocalChecked(),
      Nan::New(data->authorityIssuing).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("unambiguousNumber").ToLocalChecked(),
      Nan::New(data->unambiguousNumber).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("issuingDate").ToLocalChecked(),
      Nan::New(data->issuingDate).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("expiryDate").ToLocalChecked(),
      Nan::New(data->expiryDate).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("serialNumber").ToLocalChecked(),
      Nan::New(data->serialNumber).ToLocalChecked());

  sdCleanup();
  delete data;

  v8::Local<v8::Value> argv[1] = {jsonObject};
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), success, 1, argv);
}

void readPersonalData(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  unsigned long statusCode = prepareReader();

  v8::Local<v8::Function> success = info[0].As<v8::Function>();
  v8::Local<v8::Function> error = info[1].As<v8::Function>();

  if (statusCode != S_OK)
  {
    v8::Local<v8::Value> argv[1] = {Nan::New(std::to_string(statusCode)).ToLocalChecked()};
    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), error, 1, argv);

    sdCleanup();
    return;
  }

  SD_PERSONAL_DATA *data = new SD_PERSONAL_DATA();
  sdReadPersonalData(data);

  v8::Local<v8::Object> jsonObject = Nan::New<v8::Object>();

  Nan::Set(
      jsonObject,
      Nan::New("ownersPersonalNo").ToLocalChecked(),
      Nan::New(data->ownersPersonalNo).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("ownersSurnameOrBusinessName").ToLocalChecked(),
      Nan::New(data->ownersSurnameOrBusinessName).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("ownerName").ToLocalChecked(),
      Nan::New(data->ownerName).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("ownerAddress").ToLocalChecked(),
      Nan::New(data->ownerAddress).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("usersPersonalNo").ToLocalChecked(),
      Nan::New(data->usersPersonalNo).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("usersSurnameOrBusinessName").ToLocalChecked(),
      Nan::New(data->usersSurnameOrBusinessName).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("usersName").ToLocalChecked(),
      Nan::New(data->usersName).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("usersAddress").ToLocalChecked(),
      Nan::New(data->usersAddress).ToLocalChecked());

  sdCleanup();
  delete data;

  v8::Local<v8::Value> argv[1] = {jsonObject};
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), success, 1, argv);
}

void readVehicleData(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  unsigned long statusCode = prepareReader();

  v8::Local<v8::Function> success = info[0].As<v8::Function>();
  v8::Local<v8::Function> error = info[1].As<v8::Function>();

  if (statusCode != S_OK)
  {
    v8::Local<v8::Value> argv[1] = {Nan::New(std::to_string(statusCode)).ToLocalChecked()};
    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), error, 1, argv);

    sdCleanup();
    return;
  }

  SD_VEHICLE_DATA *data = new SD_VEHICLE_DATA();
  sdReadVehicleData(data);

  v8::Local<v8::Object> jsonObject = Nan::New<v8::Object>();

  Nan::Set(
      jsonObject,
      Nan::New("dateOfFirstRegistration").ToLocalChecked(),
      Nan::New(data->dateOfFirstRegistration).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("yearOfProduction").ToLocalChecked(),
      Nan::New(data->yearOfProduction).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("vehicleMake").ToLocalChecked(),
      Nan::New(data->vehicleMake).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("vehicleType").ToLocalChecked(),
      Nan::New(data->vehicleType).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("commercialDescription").ToLocalChecked(),
      Nan::New(data->commercialDescription).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("vehicleIDNumber").ToLocalChecked(),
      Nan::New(data->vehicleIDNumber).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("registrationNumberOfVehicle").ToLocalChecked(),
      Nan::New(data->registrationNumberOfVehicle).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("maximumNetPower").ToLocalChecked(),
      Nan::New(data->maximumNetPower).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("engineCapacity").ToLocalChecked(),
      Nan::New(data->engineCapacity).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("typeOfFuel").ToLocalChecked(),
      Nan::New(data->typeOfFuel).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("powerWeightRatio").ToLocalChecked(),
      Nan::New(data->powerWeightRatio).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("vehicleMass").ToLocalChecked(),
      Nan::New(data->vehicleMass).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("maximumPermissibleLadenMass").ToLocalChecked(),
      Nan::New(data->maximumPermissibleLadenMass).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("typeApprovalNumber").ToLocalChecked(),
      Nan::New(data->typeApprovalNumber).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("numberOfSeats").ToLocalChecked(),
      Nan::New(data->numberOfSeats).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("numberOfStandingPlaces").ToLocalChecked(),
      Nan::New(data->numberOfStandingPlaces).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("engineIDNumber").ToLocalChecked(),
      Nan::New(data->engineIDNumber).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("numberOfAxles").ToLocalChecked(),
      Nan::New(data->numberOfAxles).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("vehicleCategory").ToLocalChecked(),
      Nan::New(data->vehicleCategory).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("colourOfVehicle").ToLocalChecked(),
      Nan::New(data->colourOfVehicle).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("restrictionToChangeOwner").ToLocalChecked(),
      Nan::New(data->restrictionToChangeOwner).ToLocalChecked());

  Nan::Set(
      jsonObject,
      Nan::New("vehicleLoad").ToLocalChecked(),
      Nan::New(data->vehicleLoad).ToLocalChecked());

  sdCleanup();
  delete data;

  v8::Local<v8::Value> argv[1] = {jsonObject};
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), success, 1, argv);
}

void InitAll(v8::Local<v8::Object> exports)
{
  v8::Local<v8::Context> context = exports->CreationContext();

  exports->Set(context,
               Nan::New("startup").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(startup)
                   ->GetFunction(context)
                   .ToLocalChecked());

  exports->Set(context,
               Nan::New("cleanup").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(cleanup)
                   ->GetFunction(context)
                   .ToLocalChecked());

  exports->Set(context,
               Nan::New("readDocumentData").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(readDocumentData)
                   ->GetFunction(context)
                   .ToLocalChecked());

  exports->Set(context,
               Nan::New("readPersonalData").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(readPersonalData)
                   ->GetFunction(context)
                   .ToLocalChecked());

  exports->Set(context,
               Nan::New("readVehicleData").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(readVehicleData)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(eVehicleRegistration, InitAll)
