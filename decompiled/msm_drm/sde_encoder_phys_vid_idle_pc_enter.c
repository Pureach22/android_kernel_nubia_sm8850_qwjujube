__int64 __fastcall sde_encoder_phys_vid_idle_pc_enter(__int64 *a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  int v4; // w6
  int v5; // w7
  __int64 v6; // x21
  _QWORD *v7; // x8
  int v8; // w4
  void (*v9)(void); // x8
  void (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x0
  _DWORD *v12; // x8
  __int64 v13; // x0
  __int64 v14; // x22
  void (*v15)(void); // x8
  unsigned int (*v16)(void); // x8
  void (*v17)(void); // x8
  void (*v18)(void); // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = a1[1];
  result = sde_encoder_get_disp_op(*a1);
  if ( (unsigned int)result >= 3 )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))sde_encoder_phys_vid_timing_engine_disable_wait)();
  }
  else
  {
    v6 = (unsigned int)result;
    v7 = (_QWORD *)(a1[53] + 8LL * (unsigned int)result);
    if ( v7[22] && v7[121] && v7[124] && v7[115] )
    {
      if ( *a1 )
        v8 = *(_DWORD *)(*a1 + 24);
      else
        v8 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_vid_idle_pc_enter",
        2394,
        -1,
        v8,
        -1059143953,
        v4,
        v5,
        vars0);
      *(_DWORD *)(*(_QWORD *)(*a1 + 328) + 696LL) = 0;
      v9 = *(void (**)(void))(a1[53] + 8 * v6 + 1016);
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -1839426449 )
          __break(0x8228u);
        v9();
      }
      if ( v2 )
      {
        v10 = *(void (__fastcall **)(__int64, __int64))(v2 + 3248);
        if ( v10 )
        {
          v11 = *(_QWORD *)(v2 + 2760);
          if ( *((_DWORD *)v10 - 1) != -1297827279 )
            __break(0x8228u);
          v10(v11, 1);
        }
        sde_encoder_phys_vid_timing_engine_disable_wait(a1);
        v12 = *(_DWORD **)(v2 + 3248);
        if ( v12 )
        {
          v13 = *(_QWORD *)(v2 + 2760);
          if ( *(v12 - 1) != -1297827279 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v12)(v13, 0);
        }
      }
      else
      {
        sde_encoder_phys_vid_timing_engine_disable_wait(a1);
      }
      sde_connector_osc_clk_ctrl(v2, 1);
      ((void (__fastcall *)(__int64 *, __int64))sde_encoder_phys_vid_setup_backup_esync_engine)(a1, 1);
      v14 = 8 * v6;
      v15 = *(void (**)(void))(a1[53] + 8 * v6 + 968);
      if ( *((_DWORD *)v15 - 1) != -1839426449 )
        __break(0x8228u);
      v15();
      v16 = *(unsigned int (**)(void))(a1[53] + v14 + 992);
      if ( *((_DWORD *)v16 - 1) != 467537577 )
        __break(0x8228u);
      if ( v16() )
      {
        printk(&unk_253986, "sde_encoder_phys_vid_idle_pc_enter");
        v18 = *(void (**)(void))(a1[53] + v14 + 920);
        if ( *((_DWORD *)v18 - 1) != -1839426449 )
          __break(0x8228u);
        v18();
        ((void (__fastcall *)(__int64 *, _QWORD))sde_encoder_phys_vid_setup_backup_esync_engine)(a1, 0);
        v17 = *(void (**)(void))(a1[53] + v14 + 968);
      }
      else
      {
        v17 = *(void (**)(void))(a1[53] + 8 * v6 + 920);
      }
      if ( *((_DWORD *)v17 - 1) != -1839426449 )
        __break(0x8228u);
      v17();
      return sde_connector_esync_clk_ctrl(v2, 0);
    }
    else
    {
      __break(0x800u);
    }
  }
  return result;
}
