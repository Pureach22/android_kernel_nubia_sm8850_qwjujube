void *__fastcall qdf_register_is_driver_unloading_callback(void *result)
{
  is_driver_unloading_cb = result;
  return result;
}
