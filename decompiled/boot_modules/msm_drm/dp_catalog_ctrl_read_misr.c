__int64 __fastcall dp_catalog_ctrl_read_misr(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x22
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x21
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w23
  __int64 i; // x24
  _DWORD *v11; // x8
  _DWORD *v12; // x8
  _DWORD *v13; // x8
  int v14; // w9
  __int64 v15; // x2
  unsigned int (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 v17; // x22
  __int64 (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v19)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v20)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v21)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v22)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v23)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v25)(__int64, __int64, __int64); // x8
  int v26; // w8
  __int64 result; // x0
  __int64 v28; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 192);
    v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
    v4 = a1 - 232;
    v7 = a1 - 232;
    if ( *((_DWORD *)v3 - 1) != -1879227436 )
      __break(0x8228u);
    v8 = v3(v7, v2, 268);
    if ( (_DWORD)v8 )
    {
      v9 = 272;
      for ( i = 8; i != 16; ++i )
      {
        a2[i] = 0;
        v11 = *(_DWORD **)(a1 - 112);
        if ( *(v11 - 1) != -1879227436 )
          __break(0x8228u);
        a2[i] |= ((unsigned __int8 (__fastcall *)(__int64, __int64, _QWORD))v11)(v4, v2, v9);
        v12 = *(_DWORD **)(a1 - 112);
        if ( *(v12 - 1) != -1879227436 )
          __break(0x8228u);
        a2[i] |= ((unsigned __int8 (__fastcall *)(__int64, __int64, _QWORD))v12)(v4, v2, v9 + 4) << 8;
        v13 = *(_DWORD **)(a1 - 112);
        if ( *(v13 - 1) != -1879227436 )
          __break(0x8228u);
        v14 = ((unsigned __int8 (__fastcall *)(__int64, __int64, _QWORD))v13)(v4, v2, v9 + 8) << 16;
        v15 = v9 + 12;
        a2[i] |= v14;
        v16 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
        if ( *((_DWORD *)v16 - 1) != -1879227436 )
          __break(0x8228u);
        v9 += 16;
        a2[i] |= v16(v4, v2, v15) << 24;
      }
      v17 = *(_QWORD *)(a1 - 208);
      v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v18 - 1) != -1879227436 )
        __break(0x8228u);
      *a2 = v18(v4, v17, 212);
      v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v19 - 1) != -1879227436 )
        __break(0x8228u);
      a2[1] = v19(v4, v17, 216);
      v20 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v20 - 1) != -1879227436 )
        __break(0x8228u);
      a2[2] = v20(v4, v17, 220);
      v21 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v21 - 1) != -1879227436 )
        __break(0x8228u);
      a2[3] = v21(v4, v17, 224);
      v22 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v22 - 1) != -1879227436 )
        __break(0x8228u);
      a2[4] = v22(v4, v17, 228);
      v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v23 - 1) != -1879227436 )
        __break(0x8228u);
      a2[5] = v23(v4, v17, 232);
      v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v24 - 1) != -1879227436 )
        __break(0x8228u);
      a2[6] = v24(v4, v17, 236);
      v25 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v25 - 1) != -1879227436 )
        __break(0x8228u);
      v26 = v25(v4, v17, 240);
      result = 0;
      a2[7] = v26;
    }
    else
    {
      ipc_log_context = get_ipc_log_context(v8);
      ipc_log_string(ipc_log_context, "[w][%-4d]phy misr not ready!", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_26102A, "dp_catalog_ctrl_read_misr");
      return 4294967285LL;
    }
  }
  else
  {
    v28 = get_ipc_log_context(0);
    ipc_log_string(v28, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_ctrl_read_misr");
    return 4294967274LL;
  }
  return result;
}
