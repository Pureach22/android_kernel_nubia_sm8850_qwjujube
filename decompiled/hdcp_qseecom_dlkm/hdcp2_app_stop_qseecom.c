__int64 __fastcall hdcp2_app_stop_qseecom(__int64 a1)
{
  __int64 v1; // x8
  _DWORD *v3; // x20
  int v4; // w8
  unsigned int v5; // w0
  unsigned int v6; // w2
  char v7; // w9
  __int64 v8; // x8
  _DWORD *v9; // x20
  int v10; // w8
  unsigned int v11; // w0
  void *v12; // x0

  if ( !a1 )
  {
    v12 = &unk_C11E;
    goto LABEL_22;
  }
  v1 = *(_QWORD *)(a1 + 56);
  if ( !v1 )
  {
    v12 = &unk_CC25;
    goto LABEL_22;
  }
  v3 = *(_DWORD **)(v1 + 8);
  *v3 = 4098;
  v4 = *(_DWORD *)(a1 + 48);
  if ( (v4 & 1) == 0 )
    goto LABEL_17;
  if ( (v4 & 4) == 0 )
  {
    v12 = &unk_C91F;
    goto LABEL_22;
  }
  v3[1] = *(_DWORD *)(a1 + 40);
  v5 = qseecom_send_command(*(_QWORD *)(a1 + 56), v3, 64, v3 + 16, 64);
  v6 = v5;
  if ( (v5 & 0x80000000) != 0 || v3[16] )
  {
    v12 = &unk_C4E8;
    goto LABEL_22;
  }
  if ( v5 )
    return v6;
  v7 = *(_BYTE *)(a1 + 76);
  *(_DWORD *)(a1 + 48) &= ~4u;
  if ( (v7 & 1) != 0 )
    return (unsigned int)hdcp2_app_unload(a1);
  v8 = *(_QWORD *)(a1 + 56);
  if ( !v8 )
  {
    v12 = &unk_CC25;
    goto LABEL_22;
  }
  v9 = *(_DWORD **)(v8 + 8);
  *v9 = 4113;
  v10 = *(_DWORD *)(a1 + 48);
  if ( (v10 & 1) == 0 )
  {
LABEL_17:
    v12 = &unk_C830;
LABEL_22:
    printk(v12);
    return (unsigned int)-22;
  }
  if ( (v10 & 2) == 0 )
  {
    v12 = &unk_C788;
    goto LABEL_22;
  }
  v9[1] = *(_DWORD *)(a1 + 72);
  v11 = qseecom_send_command(*(_QWORD *)(a1 + 56), v9, 64, v9 + 16, 64);
  v6 = v11;
  if ( (v11 & 0x80000000) != 0 || v9[16] )
  {
    v12 = &unk_C4E8;
    goto LABEL_22;
  }
  if ( !v11 )
  {
    *(_DWORD *)(a1 + 48) &= ~2u;
    return (unsigned int)hdcp2_app_unload(a1);
  }
  return v6;
}
