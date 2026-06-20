__int64 cleanup_module()
{
  return led_trigger_unregister(&pattern_led_trigger);
}
