void *__fastcall qdf_register_wmi_send_recv_qmi_callback(void *result)
{
  wmi_send_recv_qmi_cb = result;
  return result;
}
