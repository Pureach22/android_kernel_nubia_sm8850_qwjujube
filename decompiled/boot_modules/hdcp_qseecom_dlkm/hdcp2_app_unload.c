__int64 __fastcall hdcp2_app_unload(__int64 a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x20
  _DWORD *v4; // x21
  unsigned int v5; // w0
  int v6; // w8
  unsigned int v8; // w19

  v3 = (_QWORD *)(a1 + 56);
  v2 = *(_QWORD *)(a1 + 56);
  if ( v2 )
  {
    v4 = *(_DWORD **)(v2 + 8);
    *v4 = 4108;
    if ( --hdcp2_app_started )
    {
LABEL_9:
      v6 = *(_DWORD *)(a1 + 48);
      *v3 = 0;
      v3[1] = 0;
      *(_DWORD *)(a1 + 48) = v6 & 0xFFFFFFFE;
      return 0;
    }
    if ( (qseecom_send_command(*v3, v4, 64, v4 + 16, 64) & 0x80000000) != 0 || v4[16] )
      printk(&unk_C4E8);
    if ( (unsigned int)qseecom_shutdown_app(a1 + 64) )
      printk(&unk_C3D3);
    hdcpsrm_qseecom_handle_g = 0;
    v5 = qseecom_shutdown_app(v3);
    if ( !v5 )
    {
      qseecom_handle_g = 0;
      goto LABEL_9;
    }
    v8 = v5;
    printk(&unk_C527);
    return v8;
  }
  else
  {
    printk(&unk_CC25);
    if ( !hdcp2_app_started )
      qseecom_shutdown_app(a1 + 64);
    return 4294967274LL;
  }
}
