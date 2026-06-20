__int64 __fastcall hdcp1_start_qseecom(__int64 a1, unsigned int *a2, unsigned int *a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  _DWORD *v8; // x22
  unsigned int v9; // w1
  unsigned int v10; // w20
  void *v11; // x0
  void *v12; // x0

  if ( !a2 || !a3 )
  {
    v11 = &unk_BD48;
LABEL_17:
    printk(v11);
    return 4294967274LL;
  }
  if ( !a1 )
  {
    v11 = &unk_C81E;
    goto LABEL_17;
  }
  if ( (*(_BYTE *)(a1 + 16) & 1) == 0 )
  {
    v11 = &unk_C3AD;
    goto LABEL_17;
  }
  if ( (*(_BYTE *)(a1 + 24) & 1) != 0 )
    return 0;
  result = hdcp1_app_load(a1);
  if ( (_DWORD)result )
    return result;
  v7 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    printk(&unk_C470);
    v10 = -22;
    goto LABEL_24;
  }
  if ( (*(_BYTE *)(a1 + 24) & 1) == 0 )
  {
    printk(&unk_C830);
    v10 = -22;
    goto LABEL_24;
  }
  **(_DWORD **)(v7 + 8) = 202;
  v8 = *(_DWORD **)(v7 + 8);
  if ( (qseecom_send_command() & 0x80000000) != 0 )
  {
    v12 = &unk_C76B;
LABEL_23:
    printk(v12);
    v10 = -126;
    goto LABEL_24;
  }
  if ( v8[17] )
  {
    v12 = &unk_C63A;
    goto LABEL_23;
  }
  *a2 = bswap32(v8[18]);
  v9 = bswap32(v8[19]);
  *a3 = v9;
  result = hdcp1_validate_aksv(*a2, v9);
  if ( (_DWORD)result )
  {
    v10 = result;
    printk(&unk_BDBF);
LABEL_24:
    hdcp1_app_unload(a1);
    return v10;
  }
  return result;
}
