__int64 __fastcall dp_ctrl_off(__int64 result)
{
  __int64 v1; // x19
  void (*v2)(void); // x8
  void (*v3)(void); // x8
  void (*v4)(void); // x8
  __int64 v5; // x0
  __int64 (*v6)(void); // x8
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x19
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v1 = result;
    if ( *(_BYTE *)(result + 257) == 1 )
    {
      v2 = *(void (**)(void))(*(_QWORD *)(result + 176) + 240LL);
      if ( *((_DWORD *)v2 - 1) != 289804815 )
        __break(0x8228u);
      v2();
      dp_ctrl_configure_source_link_params(v1, 0);
      v3 = *(void (**)(void))(*(_QWORD *)(v1 + 176) + 56LL);
      if ( *((_DWORD *)v3 - 1) != -1041116529 )
        __break(0x8228u);
      v3();
      __dsb(0xEu);
      v4 = *(void (**)(void))(*(_QWORD *)(v1 + 160) + 48LL);
      if ( *((_DWORD *)v4 - 1) != -1712294539 )
        __break(0x8228u);
      v4();
      v5 = *(_QWORD *)(v1 + 184);
      v6 = *(__int64 (**)(void))(v5 + 416);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -928861002 )
          __break(0x8228u);
        v5 = v6();
        if ( (v5 & 0x80000000) != 0 )
        {
          ipc_log_context = get_ipc_log_context(v5);
          ipc_log_string(ipc_log_context, "[e][%-4d]pll unprepare failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          v5 = printk(&unk_24ECF1, "dp_ctrl_disable_link_clock");
        }
      }
      *(_DWORD *)(v1 + 257) = 0;
      *(_QWORD *)(v1 + 284) = 0;
      *(_QWORD *)(v1 + 292) = 0;
      v7 = get_ipc_log_context(v5);
      StatusReg = _ReadStatusReg(SP_EL0);
      result = ipc_log_string(v7, "[d][%-4d]DP off done\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]DP off done\n", *(_DWORD *)(StatusReg + 1800));
    }
  }
  return result;
}
