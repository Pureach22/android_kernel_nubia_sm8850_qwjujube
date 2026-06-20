__int64 __fastcall dp_catalog_panel_config_sdp(__int64 a1, char a2)
{
  unsigned int v2; // w8
  __int64 *v4; // x25
  _DWORD **v5; // x23
  __int64 v6; // x21
  _DWORD *v7; // x9
  __int64 v8; // x20
  int v9; // w27
  __int64 v11; // x1
  int v12; // w0
  _DWORD *v13; // x8
  int v14; // w24
  _DWORD **v15; // x26
  int v16; // w23
  __int64 v17; // x2
  _DWORD *v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x0
  _DWORD *v21; // x8
  unsigned int v22; // w8
  __int64 v23; // x19
  _DWORD *v24; // x10
  unsigned int v25; // w21
  __int64 v26; // x1
  _DWORD *v27; // x8
  __int64 ipc_log_context; // x0
  __int64 v30; // x0

  v2 = *(_DWORD *)(a1 + 204);
  if ( v2 >= 2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]invalid stream_id:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 204));
    return printk(&unk_272496, "dp_catalog_panel_config_sdp");
  }
  else
  {
    v5 = (_DWORD **)(a1 - 456);
    v6 = *(_QWORD *)(a1 - 552);
    v7 = *(_DWORD **)(a1 - 456);
    v8 = a1 - 576;
    if ( v2 == 1 )
      v9 = 696;
    else
      v9 = 0;
    v11 = *(_QWORD *)(a1 - 552);
    if ( *(v7 - 1) != -1879227436 )
      __break(0x8229u);
    v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v7)(a1 - 576, v11, (unsigned int)(v9 + 552));
    v13 = *v5;
    v14 = v12;
    if ( *(*v5 - 1) != -1879227436 )
      __break(0x8228u);
    v15 = (_DWORD **)(a1 - 448);
    v16 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v13)(a1 - 576, v6, (unsigned int)(v9 + 556));
    v17 = (unsigned int)(v9 + 552);
    v18 = *(_DWORD **)(a1 - 448);
    if ( (a2 & 1) != 0 )
    {
      if ( *(v18 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v18)(a1 - 576, v6, v17, v14 | 0x20000u);
      v19 = *v15;
      if ( *(*v15 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v19)(
        a1 - 576,
        v6,
        (unsigned int)(v9 + 556),
        v16 | 0x10000u);
      v20 = dp_catalog_panel_setup_vsc_sdp(a1);
    }
    else
    {
      if ( *(v18 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v18)(a1 - 576, v6, v17, v14 & 0xFFFDFFFF);
      v21 = *v15;
      if ( *(*v15 - 1) != -626862723 )
        __break(0x8228u);
      v20 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v21)(
              a1 - 576,
              v6,
              (unsigned int)(v9 + 556),
              v16 & 0xFFFEFFFF);
    }
    v22 = *(_DWORD *)(a1 + 204);
    if ( v22 >= 2 )
    {
      v30 = get_ipc_log_context(v20);
      ipc_log_string(
        v30,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_sdp_update");
    }
    else
    {
      v4 = (__int64 *)(a1 - 552);
      v23 = *(_QWORD *)(a1 - 552);
      v24 = *v15;
      if ( v22 == 1 )
        v25 = 1256;
      else
        v25 = 588;
      v26 = *v4;
      if ( *(v24 - 1) != -626862723 )
        __break(0x822Au);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v24)(v8, v26, v25, 1);
      v27 = *v15;
      if ( *(*v15 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v27)(v8, v23, v25, 0);
    }
  }
}
