__int64 __fastcall hdcp2_app_query_stream_qseecom(__int64 a1, int a2)
{
  __int64 v2; // x8
  _DWORD *v4; // x20
  int v5; // w8
  unsigned int v6; // w0
  unsigned int v7; // w2

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v4 = *(_DWORD **)(v2 + 8);
  *v4 = 4102;
  v5 = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 16) = a2;
  v4[1] = v5;
  v6 = qseecom_send_command(*(_QWORD *)(a1 + 56), v4, 64, v4 + 16, 192);
  v7 = v6;
  if ( (v6 & 0x80000000) != 0 || v4[16] )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  if ( !v6 )
  {
    memcpy(*(void **)(a1 + 104), v4 + 20, (unsigned int)v4[19]);
    v7 = 0;
    *(_DWORD *)(a1 + 32) = v4[19];
    *(_DWORD *)a1 = v4[18];
  }
  return v7;
}
