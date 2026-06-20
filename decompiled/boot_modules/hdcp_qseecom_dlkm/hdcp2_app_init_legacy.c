__int64 __fastcall hdcp2_app_init_legacy(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v2; // x19
  unsigned int v3; // w2

  if ( !a1 || (v1 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    printk(&unk_CC25);
    return (unsigned int)-22;
  }
  v2 = *(_DWORD **)(v1 + 8);
  *v2 = 4107;
  if ( (*(_BYTE *)(a1 + 76) & 1) == 0 )
  {
    printk(&unk_BF1F);
    return (unsigned int)-22;
  }
  if ( (*(_BYTE *)(a1 + 48) & 1) != 0 )
  {
    printk(&unk_C130);
    return 0;
  }
  else
  {
    v3 = qseecom_send_command(*(_QWORD *)(a1 + 56), v2, 64, v2 + 16, 192);
    if ( (v3 & 0x80000000) != 0 || v2[16] )
    {
      printk(&unk_C4E8);
      return (unsigned int)-22;
    }
  }
  return v3;
}
