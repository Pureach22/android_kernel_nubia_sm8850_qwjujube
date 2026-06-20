__int64 __fastcall dp_catalog_hpd_config_hpd(_BYTE *a1, char a2)
{
  _BYTE *v2; // x20
  __int64 v3; // x19
  __int64 v5; // x23
  _DWORD *v6; // x8
  _BYTE *v7; // x0
  _BYTE *v8; // x22
  int v9; // w21
  _DWORD *v10; // x8
  __int64 v11; // x3
  _DWORD **v12; // x8
  _BYTE *v13; // x0
  __int64 v14; // x1
  _DWORD *v15; // x8
  __int64 v16; // x3
  _DWORD *v17; // x8
  _DWORD *v18; // x8
  _DWORD *v19; // x8
  _DWORD *v20; // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = a1 - 1296;
    v3 = *((_QWORD *)a1 - 160);
    if ( (a2 & 1) != 0 )
    {
      v5 = *((_QWORD *)a1 - 148);
      v6 = *((_DWORD **)a1 - 147);
      v7 = a1 - 1296;
      if ( *(v6 - 1) != -1879227436 )
        __break(0x8228u);
      v8 = a1 - 1168;
      v9 = ((__int64 (__fastcall *)(_BYTE *, __int64, __int64))v6)(v7, v3, 24);
      v10 = *((_DWORD **)a1 - 146);
      if ( *(v10 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(_BYTE *, __int64, __int64, __int64))v10)(v2, v3, 8, 15);
      if ( *a1 == 1 && *(_BYTE *)(v5 + 741) != 1 )
        v11 = 2;
      else
        v11 = 10;
      v17 = *(_DWORD **)v8;
      if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(_BYTE *, __int64, __int64, __int64))v17)(v2, v3, 12, v11);
      v18 = *(_DWORD **)v8;
      if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(_BYTE *, __int64, __int64, _QWORD))v18)(v2, v3, 24, v9 | 0x10000u);
      v19 = *(_DWORD **)v8;
      if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(_BYTE *, __int64, __int64, __int64))v19)(v2, v3, 28, 65536250);
      v20 = *(_DWORD **)v8;
      if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(_BYTE *, __int64, __int64, __int64))v20)(v2, v3, 32, 32770000);
      v15 = *(_DWORD **)v8;
      v13 = v2;
      v14 = v3;
      v16 = 1;
    }
    else
    {
      v12 = (_DWORD **)(a1 - 1168);
      v13 = a1 - 1296;
      v14 = v3;
      v15 = *v12;
      v16 = 0;
    }
    if ( *(v15 - 1) != -626862723 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(_BYTE *, __int64, _QWORD, __int64))v15)(v13, v14, 0, v16);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_hpd_config_hpd");
  }
}
