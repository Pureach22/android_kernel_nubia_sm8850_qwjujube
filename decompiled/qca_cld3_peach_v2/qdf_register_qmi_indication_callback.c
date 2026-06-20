void *__fastcall qdf_register_qmi_indication_callback(void *result)
{
  qmi_indication_cb = result;
  return result;
}
