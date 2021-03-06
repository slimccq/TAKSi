package config

import (
	"fmt"
	"io/ioutil"
	"testing"
)

func TestAutogenConfig(t *testing.T) {
	filename := "../../res/box_probability_define.csv"
	data, err := ioutil.ReadFile(filename)
	if err != nil {
		t.Fatalf("%v", err)
	}

	conflist, err := LoadBoxProbabilityDefineList(data)
	if err != nil {
		t.Fatalf("%v", err)
	}
	for _, cfg := range conflist {
		fmt.Printf("%v\n", cfg)
	}
}
