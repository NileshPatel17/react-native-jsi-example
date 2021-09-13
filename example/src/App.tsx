import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
import JsiExample from 'react-native-jsi-example';

export default function App() {
  const [result, setResult] = React.useState<number | undefined>();
  const [resultAdd, setResultAdd] = React.useState<number | undefined>();

  React.useEffect(() => {
    JsiExample.multiply(3, 7).then(setResult);
    JsiExample.add(3, 7).then(setResultAdd);
  }, []);

  return (
    <View style={styles.container}>
      <Text>Result: {result}</Text>
      <Text>Add Result: {resultAdd}</Text>
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
