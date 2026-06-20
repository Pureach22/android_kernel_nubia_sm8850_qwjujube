void *__fastcall qdf_register_drv_supported_callback(void *result)
{
  is_drv_supported_cb = result;
  return result;
}
