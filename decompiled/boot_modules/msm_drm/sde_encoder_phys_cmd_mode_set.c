__int64 __fastcall sde_encoder_phys_cmd_mode_set(__int64 a1, __int64 a2, __int64 *a3, _BYTE *a4)
{
  __int64 v4; // x22
  __int64 v6; // x9
  __int64 v8; // x10
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x11
  char v19; // w8
  int v20; // w4
  int v21; // w21
  int v22; // w23
  int v23; // w26
  int v24; // w7
  __int64 v25; // x9
  __int64 v26; // x8
  unsigned __int64 v27; // x5
  unsigned __int64 v28; // x5
  __int64 result; // x0
  _QWORD v30[4]; // [xsp+0h] [xbp-20h] BYREF

  v30[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 512);
  memset(v30, 0, 24);
  if ( a1 && a2 && a3 )
  {
    v6 = a3[1];
    v8 = *a3;
    *(_QWORD *)(a1 + 536) = a3[2];
    *(_QWORD *)(a1 + 528) = v6;
    *(_QWORD *)(a1 + 520) = v8;
    v10 = a3[5];
    v11 = a3[3];
    v12 = a3[4];
    *(_QWORD *)(a1 + 568) = a3[6];
    *(_QWORD *)(a1 + 560) = v10;
    *(_QWORD *)(a1 + 552) = v12;
    *(_QWORD *)(a1 + 544) = v11;
    v13 = a3[9];
    v14 = a3[7];
    v15 = a3[8];
    *(_QWORD *)(a1 + 600) = a3[10];
    *(_QWORD *)(a1 + 592) = v13;
    *(_QWORD *)(a1 + 584) = v15;
    *(_QWORD *)(a1 + 576) = v14;
    v16 = a3[13];
    v17 = a3[11];
    v18 = a3[12];
    *(_QWORD *)(a1 + 632) = a3[14];
    v19 = _drm_debug;
    *(_QWORD *)(a1 + 624) = v16;
    *(_QWORD *)(a1 + 616) = v18;
    *(_QWORD *)(a1 + 608) = v17;
    if ( (v19 & 4) != 0 )
    {
      if ( *(_QWORD *)a1 )
        v20 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v20 = -1;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d caching mode:\n", v20, *(_DWORD *)(a1 + 672) - 1);
    }
    drm_mode_debug_printmodeline(a3);
    v21 = *(_DWORD *)(a1 + 664);
    sde_rm_init_hw_iter(v30, *(unsigned int *)(*(_QWORD *)a1 + 24LL), 5);
    if ( v21 == 3 )
      v22 = 2;
    else
      v22 = 1;
    v23 = v22;
    do
    {
      if ( (sde_rm_get_hw(v4 + 2144, v30) & 1) != 0 )
      {
        v25 = *(_QWORD *)(a1 + 416);
        v26 = v30[0];
        if ( v25 && v25 != v30[0] )
        {
          *a4 = 1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_encoder_phys_cmd_mode_set",
            833,
            -1,
            *(_DWORD *)(*(_QWORD *)(a1 + 416) + 64LL),
            *(_DWORD *)(v26 + 64),
            -1059143953,
            v24,
            v30[0]);
          v26 = v30[0];
        }
        *(_QWORD *)(a1 + 416) = v26;
      }
      --v23;
    }
    while ( v23 );
    v27 = *(_QWORD *)(a1 + 416);
    if ( v27 && v27 < 0xFFFFFFFFFFFFF001LL )
    {
      sde_rm_init_hw_iter(v30, *(unsigned int *)(*(_QWORD *)a1 + 24LL), 8);
      do
      {
        if ( (sde_rm_get_hw(v4 + 2144, v30) & 1) != 0 )
          *(_QWORD *)(a1 + 424) = v30[0];
        --v22;
      }
      while ( v22 );
      v28 = *(_QWORD *)(a1 + 424);
      if ( v28 && v28 < 0xFFFFFFFFFFFFF001LL )
      {
        sde_encoder_phys_cmd_setup_irq_hw_idx(a1);
        result = sde_encoder_helper_get_kickoff_timeout_ms(*(__int64 **)a1);
        *(_DWORD *)(a1 + 992) = result;
      }
      else
      {
        result = printk(&unk_220CFA, "sde_encoder_phys_cmd_mode_set");
        *(_QWORD *)(a1 + 424) = 0;
      }
    }
    else
    {
      result = printk(&unk_23858B, "sde_encoder_phys_cmd_mode_set");
      *(_QWORD *)(a1 + 416) = 0;
    }
  }
  else
  {
    result = printk(&unk_211DA1, "sde_encoder_phys_cmd_mode_set");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
