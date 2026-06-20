__int64 __fastcall hdcp2_app_enable_encryption_qseecom(__int64 a1, int a2)
{
  __int64 v2; // x8
  _DWORD *v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w2

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v4 = *(_DWORD **)(v2 + 8);
  *v4 = 4101;
  *(_DWORD *)(a1 + 16) = a2;
  msleep(300);
  v4[1] = *(_DWORD *)(a1 + 40);
  v5 = qseecom_send_command(*(_QWORD *)(a1 + 56), v4, 64, v4 + 16, 64);
  v6 = v5;
  if ( (v5 & 0x80000000) != 0 || v4[16] )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  if ( !v5 )
    *(_DWORD *)(a1 + 48) |= 8u;
  return v6;
}
