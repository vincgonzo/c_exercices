rule ExampleRule {
    strings:
        $a = "test"
    condition:
        $a
}