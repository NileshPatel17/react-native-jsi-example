import { NativeModules } from 'react-native';

const { JsiExample: NativeMethods } = NativeModules;

const JsiExample = {
  add: NativeMethods.add,
  multiply: NativeMethods.multiply,
  multiplyJsi: global.multiplyJsi,
  multiplyWithCallback: global.multiplyWithCallback,
  helloWorld: global.helloWorld,
};

export default JsiExample;
