__int64 __fastcall hdcp2_app_tx_init_legacy(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v3; // x20
  int v4; // w8
  unsigned int v5; // w0
  unsigned int v6; // w2
  int v7; // w8

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v3 = *(_DWORD **)(v1 + 8);
  *v3 = 4097;
  v4 = *(_DWORD *)(a1 + 48);
  if ( (v4 & 1) == 0 )
  {
    printk(&unk_C94C);
    return (unsigned int)-22;
  }
  if ( (v4 & 4) != 0 )
  {
    printk(&unk_BDDE);
    return 0;
  }
  v5 = qseecom_send_command(*(_QWORD *)(a1 + 56), v3, 64, v3 + 16, 192);
  v6 = v5;
  if ( (v5 & 0x80000000) != 0 || v3[16] )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  if ( !v5 )
  {
    *(_QWORD *)(a1 + 24) = v3 + 21;
    *(_DWORD *)(a1 + 32) = v3[20];
    *(_DWORD *)a1 = v3[19];
    v7 = *(_DWORD *)(a1 + 48) | 4;
    *(_DWORD *)(a1 + 40) = v3[18];
    *(_DWORD *)(a1 + 48) = v7;
  }
  return v6;
}
