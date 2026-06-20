__int64 __fastcall dp_panel_deinit_panel_info(__int64 a1, char a2)
{
  __int64 v3; // x0
  _QWORD *v4; // t1
  __int64 v5; // x20
  __int64 v6; // x8
  _QWORD *v7; // x9
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x0

  if ( (a2 & 1) != 0 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[d][%-4d]retain states in src initiated power down request\n",
      *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]retain states in src initiated power down request\n",
        *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    v4 = *(_QWORD **)(a1 + 96);
    v3 = a1 + 96;
    *(_QWORD *)(v3 - 8) = 0;
    v5 = *(_QWORD *)(v3 + 1120);
    if ( *v4 )
      v3 = sde_free_edid();
    if ( a1 )
    {
      *(_QWORD *)(a1 + 920) = 0;
      *(_QWORD *)(a1 + 912) = 2;
      *(_DWORD *)(a1 + 928) = 0;
    }
    else
    {
      v11 = get_ipc_log_context(v3);
      ipc_log_string(v11, "[e][%-4d]invalid input. stream_id: %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 2);
      printk(&unk_2725D8, "dp_panel_set_stream_info");
    }
    memset((void *)(a1 + 104), 0, 0x300u);
    *(_QWORD *)(v5 + 80) = 0;
    *(_QWORD *)(v5 + 88) = 0;
    *(_QWORD *)(v5 + 96) = 0;
    *(_QWORD *)(v5 + 104) = 0;
    *(_QWORD *)(v5 + 112) = 0;
    *(_QWORD *)(v5 + 120) = 0;
    *(_QWORD *)(v5 + 128) = 0;
    *(_QWORD *)(v5 + 136) = 0;
    *(_QWORD *)(v5 + 144) = 0;
    *(_QWORD *)(v5 + 152) = 0;
    *(_QWORD *)(v5 + 68) = 0;
    *(_QWORD *)(v5 + 32) = 0;
    *(_QWORD *)(v5 + 40) = 0;
    *(_QWORD *)(v5 + 48) = 0;
    *(_QWORD *)(v5 + 56) = 0;
    *(_DWORD *)(v5 + 64) = 0;
    v6 = *(_QWORD *)(a1 + 944);
    *(_BYTE *)(a1 + 1232) = 0;
    *(_DWORD *)(v6 + 4640) = 0;
    *(_BYTE *)(v6 + 4644) = 0;
    *(_BYTE *)(v6 + 4672) = 0;
    *(_BYTE *)(v6 + 4744) = 0;
    v7 = *(_QWORD **)(v6 + 2512);
    *(_QWORD *)(v6 + 4648) = 0;
    *(_QWORD *)(v6 + 4653) = 0;
    v7[398] = 0;
    v7[397] = 0;
    v7[396] = 0;
    v7[395] = 0;
    v7[394] = 0;
    v7[393] = 0;
    v7[392] = 0;
    v7[391] = 0;
    v7[390] = 0;
    v7[389] = 0;
    v7[399] = 0;
    v7[400] = 0;
    v7[401] = 0;
    v7[402] = 0;
    v7[403] = 0;
    *(_QWORD *)(a1 + 900) = 0;
  }
  return 0;
}
