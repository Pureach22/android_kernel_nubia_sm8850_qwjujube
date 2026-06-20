__int64 __fastcall hdcp2_close_stream_qseecom(__int64 a1, int a2)
{
  __int64 v2; // x8
  _DWORD *v3; // x19
  int v4; // w8
  unsigned int v5; // w2

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v3 = *(_DWORD **)(v2 + 8);
  *v3 = 4117;
  v4 = *(_DWORD *)(a1 + 48);
  if ( (v4 & 2) == 0 )
  {
    printk(&unk_C788);
    return (unsigned int)-22;
  }
  if ( (v4 & 4) == 0 )
  {
    printk(&unk_C91F);
    return (unsigned int)-22;
  }
  v3[1] = *(_DWORD *)(a1 + 72);
  v3[2] = a2;
  v5 = qseecom_send_command(*(_QWORD *)(a1 + 56), v3, 64, v3 + 16, 64);
  if ( (v5 & 0x80000000) != 0 || v3[16] )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  return v5;
}
