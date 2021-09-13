/* eslint-disable react-native/no-inline-styles */
import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import JsiExample from 'react-native-jsi-example';

export default function App() {
  const [result, setResult] = React.useState<number | undefined>();
  const [result1, setResult1] = React.useState<number | undefined>();

  React.useEffect(() => {
    JsiExample.multiplyWithCallback(2, 18, (x: number) => {
      setResult(x);
    });
    setResult1(JsiExample.multiplyJsi(2, 8));
  }, []);

  return (
    <View style={styles.container}>
      <Text style={{ fontSize: 30, color: 'blue', marginBottom: 20 }}>
        JSI Example
      </Text>
      <Text>{JsiExample.helloWorld()}</Text>
      <Text>Result: {result}</Text>
      <Text>Result Jsi: {result1}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
