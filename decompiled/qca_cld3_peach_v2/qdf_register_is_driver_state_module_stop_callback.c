void *__fastcall qdf_register_is_driver_state_module_stop_callback(void *result)
{
  is_driver_state_module_stop_cb = result;
  return result;
}
