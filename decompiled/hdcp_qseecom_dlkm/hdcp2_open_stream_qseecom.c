__int64 __fastcall hdcp2_open_stream_qseecom(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, _DWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x20
  int v7; // w8
  unsigned int v8; // w0
  unsigned int v9; // w2
  void *v10; // x0

  if ( !a1 || (v4 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v5 = *(_QWORD *)(v4 + 8);
  *(_DWORD *)v5 = 4116;
  v7 = *(_DWORD *)(a1 + 48);
  if ( (v7 & 2) == 0 )
  {
    v10 = &unk_C788;
LABEL_12:
    printk(v10);
    return (unsigned int)-22;
  }
  if ( (v7 & 4) == 0 )
  {
    v10 = &unk_C91F;
    goto LABEL_12;
  }
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(a1 + 72);
  *(_DWORD *)(v5 + 8) = a2;
  *(_QWORD *)(v5 + 12) = a3;
  v8 = qseecom_send_command(*(_QWORD *)(a1 + 56), v5, 64, v5 + 64, 64);
  v9 = v8;
  if ( (v8 & 0x80000000) != 0 || *(_DWORD *)(v5 + 64) )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  if ( !v8 )
    *a4 = *(_DWORD *)(v5 + 72);
  return v9;
}
