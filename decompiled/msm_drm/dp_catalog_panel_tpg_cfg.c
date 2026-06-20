__int64 __fastcall dp_catalog_panel_tpg_cfg(_DWORD *a1, unsigned int a2)
{
  unsigned int v2; // w8
  bool v4; // zf
  __int64 v5; // x8
  __int64 v6; // x20
  _DWORD *v7; // x22
  __int64 v8; // x3
  unsigned int v9; // w23
  _DWORD *v10; // x8
  __int64 v12; // x3
  _DWORD *v13; // x8
  __int64 v14; // x3
  _DWORD *v15; // x8
  _DWORD *v16; // x8
  _DWORD *v17; // x8
  _DWORD *v18; // x8
  __int64 v19; // x3
  _DWORD *v20; // x8
  _DWORD *v21; // x8
  __int64 v22; // x3
  _DWORD *v23; // x8
  __int64 v24; // x3
  _DWORD *v25; // x8
  _DWORD *v26; // x8
  _DWORD *v27; // x8
  _DWORD *v28; // x8
  _DWORD *v29; // x8
  _DWORD *v30; // x8
  _DWORD *v31; // x8
  _DWORD *v32; // x8
  __int64 v33; // x3
  _DWORD *v34; // x8
  _DWORD *v35; // x8
  _DWORD *v36; // x8
  int v37; // w0
  _DWORD *v38; // x8
  __int64 result; // x0
  _DWORD *v40; // x22
  __int64 v41; // x1
  _DWORD *v42; // x8
  _DWORD *v43; // x8
  _DWORD *v44; // x8
  int v45; // w0
  _DWORD *v46; // x8
  __int64 v47; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = a1[51];
    if ( v2 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        a1[51]);
      return printk(&unk_272496, "dp_catalog_panel_tpg_cfg");
    }
    else
    {
      v4 = v2 == 0;
      v5 = 0x3FFFFFFFFFFFFF88LL;
      if ( v4 )
        v5 = 0x3FFFFFFFFFFFFF78LL;
      v6 = *(_QWORD *)&a1[v5];
      if ( a2 )
      {
        v7 = a1 - 112;
        v8 = (unsigned int)a1[45];
        v9 = 1 << a2;
        v10 = *((_DWORD **)a1 - 56);
        if ( *(v10 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v10)(a1 - 144, v6, 24, v8);
        v12 = (unsigned int)(a1[40] * a1[41]);
        v13 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v13)(a1 - 144, v6, 28, v12);
        v14 = (unsigned int)(a1[40] * a1[44]);
        v15 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v15)(a1 - 144, v6, 36, v14);
        v16 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v16)(a1 - 144, v6, 32, 0);
        v17 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v17)(a1 - 144, v6, 40, 0);
        v18 = *(_DWORD **)v7;
        v19 = (unsigned int)a1[46];
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v18)(a1 - 144, v6, 76, v19);
        v20 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v20)(a1 - 144, v6, 80, 0);
        v21 = *(_DWORD **)v7;
        v22 = (unsigned int)a1[42];
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v21)(a1 - 144, v6, 44, v22);
        v23 = *(_DWORD **)v7;
        v24 = (unsigned int)a1[43];
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v23)(a1 - 144, v6, 52, v24);
        v25 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v25)(a1 - 144, v6, 48, 0);
        v26 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v26)(a1 - 144, v6, 56, 0);
        v27 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v27)(a1 - 144, v6, 60, 0);
        v28 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v28)(a1 - 144, v6, 68, 0);
        v29 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v29)(a1 - 144, v6, 64, 0);
        v30 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v30)(a1 - 144, v6, 72, 0);
        v31 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v31)(a1 - 144, v6, 88, 0);
        __dsb(0xEu);
        v32 = *(_DWORD **)v7;
        if ( a2 <= 9 )
          v33 = v9;
        else
          v33 = 256;
        if ( *(v32 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v32)(a1 - 144, v6, 96, v33);
        v34 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, __int64))v34)(a1 - 144, v6, 100, 5);
        __dsb(0xEu);
        v35 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, _QWORD, __int64))v35)(a1 - 144, v6, 0, 1);
        v36 = *((_DWORD **)a1 - 57);
        if ( *(v36 - 1) != -1879227436 )
          __break(0x8228u);
        v37 = ((__int64 (__fastcall *)(_DWORD *, __int64, __int64))v36)(a1 - 144, v6, 16);
        v38 = *(_DWORD **)v7;
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != -626862723 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v38)(a1 - 144, v6, 16, v37 | 1u);
        __dsb(0xEu);
      }
      else
      {
        v40 = a1 - 112;
        v41 = *(_QWORD *)&a1[v5];
        v42 = *((_DWORD **)a1 - 56);
        if ( *(v42 - 1) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v42)(a1 - 144, v41, 96, 0);
        v43 = *(_DWORD **)v40;
        if ( *(_DWORD *)(*(_QWORD *)v40 - 4LL) != -626862723 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD *, __int64, _QWORD, _QWORD))v43)(a1 - 144, v6, 0, 0);
        v44 = *((_DWORD **)a1 - 57);
        if ( *(v44 - 1) != -1879227436 )
          __break(0x8228u);
        v45 = ((__int64 (__fastcall *)(_DWORD *, __int64, __int64))v44)(a1 - 144, v6, 16);
        v46 = *(_DWORD **)v40;
        if ( *(_DWORD *)(*(_QWORD *)v40 - 4LL) != -626862723 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(_DWORD *, __int64, __int64, _QWORD))v46)(a1 - 144, v6, 16, v45 & 0xFFFFFFFE);
        __dsb(0xEu);
      }
    }
  }
  else
  {
    v47 = get_ipc_log_context(0);
    ipc_log_string(v47, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_tpg_cfg");
  }
  return result;
}
