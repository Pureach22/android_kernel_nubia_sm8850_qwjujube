__int64 __fastcall sde_encoder_phys_vid_idle_pc_exit(__int64 a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  int v4; // w6
  int v5; // w7
  __int64 v6; // x22
  _QWORD *v7; // x8
  int v8; // w4
  __int64 v9; // x21
  __int64 v10; // x23
  void (__fastcall *v11)(__int64, __int64, __int64, __int64); // x8
  __int64 v12; // x2
  __int64 v13; // x9
  void (__fastcall *v14)(__int64, __int64, __int64, __int64); // x8
  __int64 v15; // x2
  __int64 v16; // x21
  void (*v17)(void); // x8
  unsigned int (*v18)(void); // x8
  void (*v19)(void); // x8
  void (*v20)(void); // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = *(_QWORD *)(a1 + 8);
  result = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( (unsigned int)result >= 3 )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))sde_encoder_phys_vid_setup_timing_engine)();
  }
  else
  {
    v6 = (unsigned int)result;
    v7 = (_QWORD *)(*(_QWORD *)(a1 + 424) + 8LL * (unsigned int)result);
    if ( v7[22] && v7[121] && v7[124] && v7[115] )
    {
      if ( *(_QWORD *)a1 )
        v8 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v8 = -1;
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_phys_vid_idle_pc_exit", 2448, -1, v8, -1059143953, v4, v5, vars0);
      v9 = *(_QWORD *)(a1 + 416);
      v10 = *(_QWORD *)(a1 + 424);
      *(_BYTE *)(a1 + 2348) = 1;
      sde_connector_esync_clk_ctrl(v2, 1);
      sde_encoder_phys_vid_setup_timing_engine(a1);
      ((void (__fastcall *)(__int64, __int64))sde_encoder_phys_vid_setup_esync_engine)(a1, 1);
      v11 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v9 + 1192 + 8 * v6);
      if ( v11 )
      {
        v12 = *(unsigned int *)(v10 + 32);
        if ( *((_DWORD *)v11 - 1) != 949740941 )
          __break(0x8228u);
        v11(v9, 7, v12, 1);
      }
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 496) + 56LL);
      if ( v13 )
      {
        v14 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v9 + 1192 + 8 * v6);
        if ( v14 )
        {
          v15 = *(unsigned int *)(v13 + 32);
          if ( *((_DWORD *)v14 - 1) != 949740941 )
            __break(0x8228u);
          v14(v9, 3, v15, 1);
        }
      }
      v16 = 8 * v6;
      v17 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8 * v6 + 920);
      if ( *((_DWORD *)v17 - 1) != -1839426449 )
        __break(0x8228u);
      v17();
      v18 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 424) + v16 + 992);
      if ( *((_DWORD *)v18 - 1) != 467537577 )
        __break(0x8228u);
      if ( v18() )
      {
        printk(&unk_277013, "sde_encoder_phys_vid_idle_pc_exit");
        v20 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + v16 + 968);
        if ( *((_DWORD *)v20 - 1) != -1839426449 )
          __break(0x8228u);
        v20();
        ((void (__fastcall *)(__int64, _QWORD))sde_encoder_phys_vid_setup_backup_esync_engine)(a1, 0);
        v19 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + v16 + 920);
      }
      else
      {
        v19 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8 * v6 + 968);
      }
      if ( *((_DWORD *)v19 - 1) != -1839426449 )
        __break(0x8228u);
      v19();
      return sde_connector_osc_clk_ctrl(v2, 0);
    }
    else
    {
      __break(0x800u);
    }
  }
  return result;
}
