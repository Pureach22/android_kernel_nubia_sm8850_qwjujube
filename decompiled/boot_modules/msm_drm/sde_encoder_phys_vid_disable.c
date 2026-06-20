__int64 __fastcall sde_encoder_phys_vid_disable(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x21
  unsigned int v6; // w20
  int v7; // w4
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x0
  void (*v11)(void); // x8
  void (*v12)(void); // x8
  int v13; // w4
  __int64 v14; // [xsp+0h] [xbp+0h] BYREF

  if ( !a1 )
    return printk(&unk_27D811, "sde_encoder_phys_vid_disable");
  v2 = *(_QWORD *)a1;
  if ( !v2 || !*(_QWORD *)v2 || !*(_QWORD *)(*(_QWORD *)v2 + 56LL) )
    return printk(&unk_27D811, "sde_encoder_phys_vid_disable");
  result = sde_encoder_get_disp_op(v2);
  v4 = *(_QWORD *)(a1 + 424);
  if ( !v4 || !*(_QWORD *)(a1 + 416) )
    return printk(&unk_227556, "sde_encoder_phys_vid_disable");
  v5 = *(_QWORD *)a1;
  v6 = result;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v5 )
      v7 = *(_DWORD *)(v5 + 24);
    else
      v7 = -1;
    result = _drm_dev_dbg(0, 0, 0, "enc%d intf%d \n", v7, *(_DWORD *)(v4 + 32) - 1);
  }
  if ( v6 >= 3 )
  {
    __break(0x5512u);
    if ( !&v14 )
      JUMPOUT(0xF7F94);
    JUMPOUT(0x1133A0);
  }
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 424) + 8LL * v6 + 176) )
  {
    if ( *(_DWORD *)(a1 + 664) != 3 )
    {
      if ( *(_DWORD *)(a1 + 832) == 1 )
        return printk(&unk_25ADDA, "sde_encoder_phys_vid_disable");
      v8 = *(_QWORD *)(a1 + 512);
      if ( !v8 || (v9 = *(_QWORD *)(v8 + 152)) == 0 || (*(_BYTE *)(v9 + 20120) & 1) == 0 )
      {
        sde_encoder_phys_vid_timing_engine_disable_wait(a1);
        if ( *(_BYTE *)(v5 + 753) == 1 )
        {
          v10 = *(_QWORD *)(a1 + 424);
          v11 = *(void (**)(void))(v10 + 8LL * v6 + 920);
          if ( v11 )
          {
            if ( *((_DWORD *)v11 - 1) != -1839426449 )
              __break(0x8228u);
            v11();
            v10 = *(_QWORD *)(a1 + 424);
          }
          v12 = *(void (**)(void))(v10 + 8LL * v6 + 968);
          if ( v12 )
          {
            if ( *((_DWORD *)v12 - 1) != -1839426449 )
              __break(0x8228u);
            v12();
          }
          *(_BYTE *)(a1 + 2348) = 0;
          if ( *(_DWORD *)(v5 + 888) == 4 )
            sde_connector_osc_clk_ctrl(*(_QWORD *)(a1 + 8), 0);
        }
        if ( v5 && *(_BYTE *)(v5 + 748) == 1 )
        {
          hrtimer_cancel(a1 + 2416);
          hrtimer_cancel(a1 + 2616);
        }
        sde_encoder_helper_phys_disable((__int64 *)a1, 0);
      }
    }
    if ( *(_QWORD *)a1 )
      v13 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v13 = -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_phys_vid_disable",
               2540,
               -1,
               v13,
               *(_DWORD *)(a1 + 880),
               *(_DWORD *)(a1 + 664),
               -1059143953,
               v14);
    *(_DWORD *)(a1 + 2296) = 0;
    *(_DWORD *)(a1 + 888) = 0;
    *(_DWORD *)(a1 + 832) = 1;
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
