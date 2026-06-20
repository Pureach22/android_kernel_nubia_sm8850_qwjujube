void *__fastcall qdf_register_recovery_reason_update(void *result)
{
  update_recovery_reason_cb = result;
  return result;
}
