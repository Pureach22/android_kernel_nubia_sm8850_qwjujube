__int64 __fastcall cnss_request_firmware_update_timer(_QWORD *a1, __int64 a2, __int64 a3)
{
  int qmi_timeout; // w0
  __int64 v7; // x22
  __int64 v8; // x0

  qmi_timeout = cnss_get_qmi_timeout(a1);
  v7 = jiffies;
  v8 = _msecs_to_jiffies((unsigned int)(qmi_timeout + 65000));
  mod_timer(a1 + 784, v8 + v7);
  return firmware_request_nowarn(a2, a3, *a1 + 16LL);
}
