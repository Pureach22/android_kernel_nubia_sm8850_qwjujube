__int64 __fastcall dp_debug_set_sim_mode(__int64 a1, char a2)
{
  __int64 ipc_log_context; // x0
  void (*v5)(void); // x8
  void (*v6)(void); // x8
  void (*v7)(void); // x8
  int v8; // w8
  __int64 v9; // x0
  void (*v10)(void); // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 StatusReg; // x20
  const char *v16; // x19
  __int64 result; // x0
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  if ( (a2 & 1) != 0 )
  {
    *(_BYTE *)(a1 + 160) = 1;
    dp_debug_enable_sim_mode(a1, 31);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 24) == 1 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[w][%-4d]sim mode off before hotplug disconnect\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_2377C9, "dp_debug_set_sim_mode");
      v5 = *(void (**)(void))(*(_QWORD *)(a1 + 104) + 48LL);
      if ( *((_DWORD *)v5 - 1) != -517830654 )
        __break(0x8228u);
      v5();
      *(_BYTE *)(a1 + 24) = 0;
    }
    v6 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 80LL);
    if ( *((_DWORD *)v6 - 1) != 532007358 )
      __break(0x8228u);
    v6();
    v7 = *(void (**)(void))(*(_QWORD *)(a1 + 352) + 32LL);
    if ( *((_DWORD *)v7 - 1) != -1878159161 )
      __break(0x8228u);
    v7();
    v8 = *(_DWORD *)(a1 + 28);
    *(_BYTE *)(a1 + 160) = 0;
    *(_DWORD *)(a1 + 20) = 0;
    if ( (v8 & 0x1F) != 0 )
    {
      v9 = *(_QWORD *)(a1 + 424);
      *(_DWORD *)(a1 + 28) = v8 & 0xFFFFFFE0;
      dp_sim_set_sim_mode(v9);
      dp_sim_update_port_num(*(_QWORD *)(a1 + 424), 0);
      if ( !*(_DWORD *)(a1 + 28) )
      {
        v10 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 88LL);
        if ( *((_DWORD *)v10 - 1) != -1759750187 )
          __break(0x8228u);
        v10();
      }
    }
  }
  drm_connector_list_iter_begin(***(_QWORD ***)(a1 + 144), v18);
  while ( 1 )
  {
    v11 = drm_connector_list_iter_next(v18);
    if ( !v11 )
      break;
    if ( *(_QWORD *)(*(_QWORD *)(v11 + 2760) + 16LL) == **(_QWORD **)(a1 + 144) )
    {
      v12 = *(_QWORD *)(v11 + 2768);
      if ( v12 )
        *(_WORD *)(v12 + 980) = 0;
    }
  }
  v13 = drm_connector_list_iter_end(v18);
  v14 = get_ipc_log_context(v13);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (a2 & 1) != 0 )
    v16 = "[ON]";
  else
    v16 = "[OFF]";
  ipc_log_string(v14, "[i][%-4d]%s\n", *(_DWORD *)(StatusReg + 1800), v16);
  if ( (_drm_debug & 4) != 0 )
    result = printk(&unk_241D69, *(unsigned int *)(StatusReg + 1800));
  else
    result = printk(&unk_279553, "dp_debug_set_sim_mode");
  _ReadStatusReg(SP_EL0);
  return result;
}
