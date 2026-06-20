__int64 __fastcall hdcp2_feature_supported_qseecom(__int64 a1)
{
  int v3; // w26
  __int64 v4; // x8
  _DWORD *v5; // x25
  _DWORD *v6; // x24
  int v7; // w0
  void *v8; // x0
  int v9; // w8
  unsigned int v10; // w20

  if ( !a1 )
  {
    printk(&unk_CF99);
    return 0;
  }
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 )
    return 1;
  if ( (unsigned int)hdcp2_app_load(a1) )
    return 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = *(_QWORD *)(a1 + 56);
    if ( !v4 )
    {
      v8 = &unk_CC25;
      goto LABEL_17;
    }
    v5 = *(_DWORD **)(v4 + 8);
    *v5 = 4111;
    v6 = v5 + 16;
    if ( (*(_BYTE *)(a1 + 48) & 1) == 0 )
    {
      v8 = &unk_C830;
LABEL_17:
      printk(v8);
      if ( qseecomd_down != 1 )
        goto LABEL_25;
      goto LABEL_13;
    }
    v7 = qseecom_send_command(*(_QWORD *)(a1 + 56), v5, 64, v6, 64);
    if ( (v7 & 0x80000000) == 0 && !v5[16] )
      break;
    printk(&unk_C4E8);
    if ( *v6 != -4103 )
    {
      v9 = 0;
      qseecomd_down = 0;
      goto LABEL_21;
    }
    qseecomd_down = 1;
LABEL_13:
    msleep(100);
    if ( *(_DWORD *)(a1 + 128) < (unsigned int)++v3 )
    {
      if ( qseecomd_down == 1 )
        printk(&unk_D01F);
LABEL_25:
      v9 = 0;
      goto LABEL_21;
    }
  }
  v9 = 0;
  qseecomd_down = 0;
  if ( !v7 )
  {
    v9 = 1;
    *(_BYTE *)(a1 + 44) = 1;
  }
LABEL_21:
  v10 = v9;
  hdcp2_app_unload(a1);
  return v10;
}
