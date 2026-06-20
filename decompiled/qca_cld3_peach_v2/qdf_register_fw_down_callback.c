void *__fastcall qdf_register_fw_down_callback(void *result)
{
  is_fw_down_cb = result;
  return result;
}
