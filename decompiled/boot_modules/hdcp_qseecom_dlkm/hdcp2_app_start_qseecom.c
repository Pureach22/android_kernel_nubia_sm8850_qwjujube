__int64 __fastcall hdcp2_app_start_qseecom(__int64 a1, int a2)
{
  unsigned int v3; // w2
  __int64 v4; // x8
  _DWORD *v5; // x20
  __int64 v6; // x8
  int v7; // w8
  unsigned int v8; // w0
  int v9; // w9
  unsigned int (__fastcall *v10)(_QWORD); // x8
  void *v11; // x0

  if ( !a1 )
    goto LABEL_17;
  *(_DWORD *)(a1 + 16) = a2;
  v3 = hdcp2_app_load();
  if ( v3 )
    return v3;
  if ( (*(_BYTE *)(a1 + 76) & 1) != 0 )
    goto LABEL_13;
  v4 = *(_QWORD *)(a1 + 56);
  if ( !v4 )
  {
    v11 = &unk_CC25;
    goto LABEL_18;
  }
  v5 = *(_DWORD **)(v4 + 8);
  *v5 = 4112;
  v6 = *(_QWORD *)(a1 + 56);
  if ( !v6 || !*(_QWORD *)(v6 + 8) )
  {
LABEL_17:
    v11 = &unk_C81E;
LABEL_18:
    printk(v11);
    return (unsigned int)-22;
  }
  v7 = *(_DWORD *)(a1 + 48);
  if ( (v7 & 1) == 0 )
  {
    v11 = &unk_C830;
    goto LABEL_18;
  }
  if ( (v7 & 2) != 0 )
  {
    printk(&unk_CB0D);
    v10 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 120);
    if ( v10 )
      goto LABEL_14;
    goto LABEL_24;
  }
  v5[1] = *(_DWORD *)(a1 + 80);
  v8 = qseecom_send_command(*(_QWORD *)(a1 + 56), v5, 64, v5 + 16, 64);
  v3 = v8;
  if ( (v8 & 0x80000000) != 0 || v5[16] )
  {
    printk(&unk_C4E8);
    return (unsigned int)-22;
  }
  if ( v8 )
    return v3;
  v9 = *(_DWORD *)(a1 + 48);
  *(_DWORD *)(a1 + 72) = v5[18];
  *(_DWORD *)(a1 + 48) = v9 | 2;
LABEL_13:
  v10 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 120);
  if ( !v10 )
  {
LABEL_24:
    v11 = &unk_C2B6;
    goto LABEL_18;
  }
LABEL_14:
  if ( *((_DWORD *)v10 - 1) != 1649215283 )
    __break(0x8228u);
  return v10(a1);
}
