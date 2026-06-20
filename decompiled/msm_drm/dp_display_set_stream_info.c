__int64 __fastcall dp_display_set_stream_info(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  int *v10; // x27
  void (*v15)(void); // x8
  _DWORD *v16; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  char v21; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    if ( a3 >= 2 )
    {
      if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v19 = 0;
      ipc_log_string(v19, "[e][%-4d]invalid stream id:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a3);
      printk(&unk_26EFE9, "dp_display_set_stream_info");
      return 4294967274LL;
    }
    else if ( a5 + a4 >= 0x41 )
    {
      if ( !g_dp_display || (v20 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v20 = 0;
      ipc_log_string(
        v20,
        "[e][%-4d]invalid channel info received. start:%d, slots:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        a4,
        a5);
      printk(&unk_24BC4E, "dp_display_set_stream_info");
      return 4294967274LL;
    }
    else
    {
      v10 = (int *)(a1 - 1156);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_set_stream_info",
        2725,
        8,
        4369,
        *(_DWORD *)(a1 - 1156),
        a3,
        a4,
        a5);
      mutex_lock(a1 + 560);
      v15 = *(void (**)(void))(*(_QWORD *)(a1 - 984) + 96LL);
      if ( *((_DWORD *)v15 - 1) != 1700246105 )
        __break(0x8228u);
      v15();
      if ( a2 )
      {
        v16 = *(_DWORD **)(a2 + 1104);
        if ( *(v16 - 1) != -515628725 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v16)(a2, a3, a4, a5, a6, a7);
      }
      mutex_unlock(a1 + 560);
      sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_set_stream_info", 2739, 8, 8738, *v10, 0, -1059143953, v21);
      return 0;
    }
  }
  else
  {
    if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v18 = 0;
    ipc_log_string(v18, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_set_stream_info");
    return 4294967274LL;
  }
}
