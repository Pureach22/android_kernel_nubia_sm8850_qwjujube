void *__fastcall qdf_register_self_recovery_callback(void *result)
{
  self_recovery_cb = result;
  return result;
}
