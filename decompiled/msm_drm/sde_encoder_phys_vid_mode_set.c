__int64 __fastcall sde_encoder_phys_vid_mode_set(__int64 a1, __int64 a2, __int64 *a3, _BYTE *a4)
{
  __int64 v4; // x22
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x11
  int v18; // w4
  __int64 v19; // x8
  int v20; // w5
  __int64 result; // x0
  int v22; // w21
  int v23; // w23
  int v24; // w26
  int v25; // w7
  __int64 v26; // x9
  __int64 v27; // x8
  unsigned __int64 v28; // x5
  unsigned __int64 v29; // x5
  _QWORD v30[4]; // [xsp+0h] [xbp-20h] BYREF

  v30[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v30, 0, 24);
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 512);
    if ( v4 )
    {
      if ( !a3 )
        goto LABEL_12;
      v7 = a3[1];
      v8 = *a3;
      *(_QWORD *)(a1 + 536) = a3[2];
      *(_QWORD *)(a1 + 528) = v7;
      *(_QWORD *)(a1 + 520) = v8;
      v9 = a3[5];
      v10 = a3[3];
      v11 = a3[4];
      *(_QWORD *)(a1 + 568) = a3[6];
      *(_QWORD *)(a1 + 560) = v9;
      *(_QWORD *)(a1 + 552) = v11;
      *(_QWORD *)(a1 + 544) = v10;
      v12 = a3[9];
      v13 = a3[7];
      v14 = a3[8];
      *(_QWORD *)(a1 + 600) = a3[10];
      *(_QWORD *)(a1 + 592) = v12;
      *(_QWORD *)(a1 + 584) = v14;
      *(_QWORD *)(a1 + 576) = v13;
      v15 = a3[13];
      v16 = a3[11];
      v17 = a3[12];
      *(_QWORD *)(a1 + 632) = a3[14];
      *(_QWORD *)(a1 + 624) = v15;
      *(_QWORD *)(a1 + 616) = v17;
      *(_QWORD *)(a1 + 608) = v16;
      drm_mode_debug_printmodeline(a3);
      if ( (_drm_debug & 4) == 0 )
      {
LABEL_12:
        v22 = *(_DWORD *)(a1 + 664);
        sde_rm_init_hw_iter(v30, *(unsigned int *)(*(_QWORD *)a1 + 24LL), 5);
        if ( v22 == 3 )
          v23 = 2;
        else
          v23 = 1;
        v24 = v23;
        do
        {
          if ( (sde_rm_get_hw(v4 + 2144, v30) & 1) != 0 )
          {
            v26 = *(_QWORD *)(a1 + 416);
            v27 = v30[0];
            if ( v26 && v26 != v30[0] )
            {
              *a4 = 1;
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "sde_encoder_phys_vid_mode_set",
                1442,
                -1,
                *(_DWORD *)(*(_QWORD *)(a1 + 416) + 64LL),
                *(_DWORD *)(v27 + 64),
                -1059143953,
                v25,
                v30[0]);
              v27 = v30[0];
            }
            *(_QWORD *)(a1 + 416) = v27;
          }
          --v24;
        }
        while ( v24 );
        v28 = *(_QWORD *)(a1 + 416);
        if ( !v28 || v28 >= 0xFFFFFFFFFFFFF001LL )
        {
          result = printk(&unk_25E825, "sde_encoder_phys_vid_mode_set");
          *(_QWORD *)(a1 + 416) = 0;
          goto LABEL_37;
        }
        sde_rm_init_hw_iter(v30, *(unsigned int *)(*(_QWORD *)a1 + 24LL), 8);
        do
        {
          if ( (sde_rm_get_hw(v4 + 2144, v30) & 1) != 0 )
            *(_QWORD *)(a1 + 424) = v30[0];
          --v23;
        }
        while ( v23 );
        v29 = *(_QWORD *)(a1 + 424);
        if ( !v29 || v29 >= 0xFFFFFFFFFFFFF001LL )
        {
          result = printk(&unk_220CFA, "sde_encoder_phys_vid_mode_set");
          *(_QWORD *)(a1 + 424) = 0;
          goto LABEL_37;
        }
        if ( (*(_DWORD *)(a1 + 1020) & 0x80000000) != 0 )
        {
          *(_DWORD *)(a1 + 1016) = *(_DWORD *)(a1 + 672);
          if ( (*(_DWORD *)(a1 + 1132) & 0x80000000) == 0 )
          {
LABEL_32:
            if ( (*(_DWORD *)(a1 + 1188) & 0x80000000) == 0 )
              goto LABEL_33;
            goto LABEL_40;
          }
        }
        else if ( (*(_DWORD *)(a1 + 1132) & 0x80000000) == 0 )
        {
          goto LABEL_32;
        }
        *(_DWORD *)(a1 + 1128) = *(_DWORD *)(a1 + 672);
        if ( (*(_DWORD *)(a1 + 1188) & 0x80000000) == 0 )
        {
LABEL_33:
          if ( (*(_DWORD *)(a1 + 2252) & 0x80000000) == 0 )
            goto LABEL_34;
          goto LABEL_41;
        }
LABEL_40:
        *(_DWORD *)(a1 + 1184) = *(_DWORD *)(a1 + 672);
        if ( (*(_DWORD *)(a1 + 2252) & 0x80000000) == 0 )
        {
LABEL_34:
          if ( (*(_DWORD *)(a1 + 1244) & 0x80000000) == 0 )
            goto LABEL_35;
          goto LABEL_42;
        }
LABEL_41:
        *(_DWORD *)(a1 + 2248) = *(_DWORD *)(a1 + 672);
        if ( (*(_DWORD *)(a1 + 1244) & 0x80000000) == 0 )
        {
LABEL_35:
          if ( (*(_DWORD *)(a1 + 1300) & 0x80000000) == 0 )
          {
LABEL_36:
            result = sde_encoder_helper_get_kickoff_timeout_ms(*(__int64 **)a1);
            *(_DWORD *)(a1 + 992) = result;
            goto LABEL_37;
          }
LABEL_43:
          *(_DWORD *)(a1 + 1296) = *(_DWORD *)(a1 + 672);
          goto LABEL_36;
        }
LABEL_42:
        *(_DWORD *)(a1 + 1240) = *(_DWORD *)(a1 + 672);
        if ( (*(_DWORD *)(a1 + 1300) & 0x80000000) == 0 )
          goto LABEL_36;
        goto LABEL_43;
      }
      if ( *(_QWORD *)a1 )
      {
        v18 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
        v19 = *(_QWORD *)(a1 + 424);
        if ( v19 )
        {
LABEL_7:
          v20 = *(_DWORD *)(v19 + 32) - 1;
LABEL_11:
          _drm_dev_dbg(0, 0, 0, "enc%d intf%d caching mode:\n", v18, v20);
          goto LABEL_12;
        }
      }
      else
      {
        v18 = -1;
        v19 = *(_QWORD *)(a1 + 424);
        if ( v19 )
          goto LABEL_7;
      }
      v20 = -1;
      goto LABEL_11;
    }
  }
  result = printk(&unk_24FFFB, "sde_encoder_phys_vid_mode_set");
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
