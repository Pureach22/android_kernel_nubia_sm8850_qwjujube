void *__fastcall qdf_register_drv_connected_callback(void *result)
{
  is_drv_connected_cb = result;
  return result;
}
