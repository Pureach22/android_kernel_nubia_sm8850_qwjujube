__int64 __fastcall hdcp1_app_unload(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8

  if ( !*(_QWORD *)a1 )
    return printk(&unk_C81E);
  if ( (*(_BYTE *)(a1 + 24) & 1) == 0 )
    return printk(&unk_CA1D);
  result = a1 + 8;
  if ( *(_QWORD *)(a1 + 8) )
  {
    result = qseecom_shutdown_app(result);
    if ( (_DWORD)result )
      result = printk(&unk_CE51);
  }
  if ( --hdcp1_app_started )
    goto LABEL_9;
  result = qseecom_shutdown_app(&hdcp1_qseecom_handle_g);
  if ( !(_DWORD)result )
  {
    hdcp1_qseecom_handle_g = 0;
LABEL_9:
    v3 = *(_DWORD *)(a1 + 24);
    *(_QWORD *)a1 = 0;
    *(_DWORD *)(a1 + 24) = v3 & 0xFFFFFFFE;
    return result;
  }
  return printk(&unk_C7A3);
}
