__int64 __fastcall dp_bridge_mode_fixup(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x1
  __int64 v7; // x22
  _DWORD *v8; // x8
  void (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x1
  __int16 v11; // w8
  __int16 v12; // w11
  __int16 v13; // w9
  __int16 v14; // w10
  __int16 v15; // w12
  unsigned int v16; // w20
  __int16 v17; // w8
  __int16 v18; // w8
  __int16 v19; // w10
  int v20; // w13
  __int16 v21; // w8
  int v22; // w9
  __int16 v23; // w12
  __int16 v24; // w10
  int v25; // w8
  __int16 v26; // w10
  __int16 v27; // w11
  int v28; // w9
  __int16 v29; // w10
  int v30; // w10
  __int64 ipc_log_context; // x0
  void *v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  _DWORD s[200]; // [xsp+8h] [xbp-328h] BYREF
  __int64 v37; // [xsp+328h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v33 = &unk_21CA0C;
LABEL_21:
    printk(v33, "dp_bridge_mode_fixup");
    v16 = 0;
    goto LABEL_17;
  }
  if ( !a1[38] )
  {
    v34 = get_ipc_log_context();
    ipc_log_string(v34, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v33 = &unk_2344C7;
    goto LABEL_21;
  }
  v6 = a1[140];
  if ( !v6 )
  {
    v35 = get_ipc_log_context();
    ipc_log_string(v35, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v33 = &unk_248981;
    goto LABEL_21;
  }
  v7 = a1[39];
  v8 = *(_DWORD **)(v7 + 272);
  if ( *(v8 - 1) != 271107547 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, __int64, _DWORD *))v8)(v7, v6, a2, s);
  v9 = *(void (__fastcall **)(__int64, __int64))(v7 + 304);
  v10 = a1[140];
  if ( *((_DWORD *)v9 - 1) != -250558756 )
    __break(0x8228u);
  v9(v7, v10);
  v11 = s[0];
  v12 = s[1];
  v13 = s[3];
  v14 = s[4];
  v15 = s[2];
  *(_QWORD *)(a3 + 16) = 0;
  *(_QWORD *)(a3 + 24) = 0;
  v16 = 1;
  *(_WORD *)(a3 + 4) = v11;
  v17 = v13 + v11;
  *(_WORD *)(a3 + 14) = v12;
  *(_WORD *)(a3 + 6) = v17;
  v18 = v14 + v17;
  v20 = s[9];
  v19 = s[10];
  *(_WORD *)(a3 + 8) = v18;
  v21 = v15 + v18;
  v22 = s[5];
  v23 = s[6];
  *(_WORD *)(a3 + 12) = v19;
  v24 = s[7];
  *(_WORD *)(a3 + 10) = v21;
  v25 = s[12];
  v26 = v24 + v12;
  v27 = s[8];
  *(_WORD *)(a3 + 16) = v26;
  if ( v22 )
    v28 = 2;
  else
    v28 = 1;
  v29 = v27 + v26;
  *(_DWORD *)a3 = v25;
  *(_WORD *)(a3 + 18) = v29;
  *(_WORD *)(a3 + 20) = v23 + v29;
  if ( v20 )
    v30 = 8;
  else
    v30 = 4;
  *(_QWORD *)(a3 + 104) = 0;
  *(_QWORD *)(a3 + 112) = 0;
  *(_QWORD *)(a3 + 88) = 0;
  *(_QWORD *)(a3 + 96) = 0;
  *(_DWORD *)(a3 + 24) = v30 | v28;
  *(_QWORD *)(a3 + 72) = 0;
  *(_QWORD *)(a3 + 80) = 0;
  *(_QWORD *)(a3 + 56) = 0;
  *(_QWORD *)(a3 + 64) = 0;
  *(_QWORD *)(a3 + 40) = 0;
  *(_QWORD *)(a3 + 48) = 0;
  *(_QWORD *)(a3 + 32) = 0;
  *(_BYTE *)(a3 + 62) = 72;
  drm_mode_set_name(a3);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v16;
}
