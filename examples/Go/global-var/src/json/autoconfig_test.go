package config

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"testing"
)

func TestAutogenConfig(t *testing.T) {
	filename := "../../res/global_property_define.json"
	data, err := ioutil.ReadFile(filename)
	if err != nil {
		t.Fatalf("%v", err)
	}
	var conf GlobalPropertyDefine
	if err = json.Unmarshal(data, &conf); err != nil {
		t.Fatalf("JSON: %v", err)
	}
	fmt.Printf("%v\n", conf)
}
