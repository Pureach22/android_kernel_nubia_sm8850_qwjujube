__int64 init_module()
{
  return led_trigger_register(&pattern_led_trigger);
}
