__int64 __fastcall hdcp1_app_load(__int64 a1)
{
  __int64 v2; // x8
  unsigned int started; // w0
  int v4; // w10
  __int64 result; // x0
  unsigned int v6; // w21
  unsigned int v7; // w19

  v2 = hdcp1_qseecom_handle_g;
  if ( !hdcp1_qseecom_handle_g )
  {
    started = qseecom_start_app(&hdcp1_qseecom_handle_g, *(_QWORD *)(a1 + 32), 4096);
    if ( started )
    {
      v7 = started;
      printk(&unk_C1B0);
      return v7;
    }
    v2 = hdcp1_qseecom_handle_g;
  }
  v4 = hdcp1_app_started;
  *(_QWORD *)a1 = v2;
  hdcp1_app_started = v4 + 1;
  result = qseecom_start_app(a1 + 8, "ops", 4096);
  if ( (_DWORD)result )
  {
    v6 = result;
    printk(&unk_CEAF);
    result = v6;
    *(_QWORD *)(a1 + 8) = 0;
  }
  *(_DWORD *)(a1 + 24) |= 1u;
  return result;
}
