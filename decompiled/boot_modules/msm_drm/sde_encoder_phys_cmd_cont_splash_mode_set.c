__int64 __fastcall sde_encoder_phys_cmd_cont_splash_mode_set(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x9
  __int64 v9; // x11
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x11
  __int64 v13; // x11
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x20
  __int64 v19; // x21
  void (__fastcall *v20)(__int64, __int64); // x9
  __int64 v21; // x0
  void (__fastcall *v22)(__int64, __int64); // x9
  __int64 v23; // x0
  void (__fastcall *v24)(_QWORD); // x8

  if ( !a1 || !a2 )
    return printk(&unk_211DA1, "sde_encoder_phys_cmd_cont_splash_mode_set");
  result = sde_encoder_get_disp_op(*(_QWORD *)a1);
  v5 = *a2;
  v6 = a2[1];
  *(_QWORD *)(a1 + 536) = a2[2];
  *(_QWORD *)(a1 + 520) = v5;
  *(_QWORD *)(a1 + 528) = v6;
  v7 = a2[4];
  v9 = a2[5];
  v8 = a2[6];
  *(_QWORD *)(a1 + 544) = a2[3];
  *(_QWORD *)(a1 + 568) = v8;
  *(_QWORD *)(a1 + 560) = v9;
  *(_QWORD *)(a1 + 552) = v7;
  v10 = a2[8];
  v12 = a2[9];
  v11 = a2[10];
  *(_QWORD *)(a1 + 576) = a2[7];
  *(_QWORD *)(a1 + 600) = v11;
  *(_QWORD *)(a1 + 592) = v12;
  *(_QWORD *)(a1 + 584) = v10;
  v13 = a2[13];
  v14 = a2[11];
  v15 = a2[12];
  *(_QWORD *)(a1 + 632) = a2[14];
  v16 = *(_QWORD *)(a1 + 416);
  *(_QWORD *)(a1 + 608) = v14;
  *(_QWORD *)(a1 + 624) = v13;
  *(_QWORD *)(a1 + 616) = v15;
  *(_DWORD *)(a1 + 832) = 4;
  if ( v16 )
  {
    v17 = *(_QWORD *)(a1 + 496);
    if ( v17 )
    {
      if ( *(_DWORD *)(a1 + 664) == 3 )
        return sde_encoder_phys_cmd_setup_irq_hw_idx(a1);
      v18 = *(_QWORD *)(a1 + 424);
      if ( *(_BYTE *)(a1 + 2288) == 1 && v18 )
      {
        if ( (unsigned int)result < 3 )
        {
          v19 = (unsigned int)result;
          v20 = *(void (__fastcall **)(__int64, __int64))(v18 + 8LL * (unsigned int)result + 608);
          if ( v20 )
          {
            v21 = *(_QWORD *)(a1 + 424);
            if ( *((_DWORD *)v20 - 1) != 1676198544 )
              __break(0x8229u);
            v20(v21, a1 + 2688);
LABEL_22:
            v24 = *(void (__fastcall **)(_QWORD))(v18 + 8 * v19 + 1112);
            if ( v24 )
            {
              if ( *((_DWORD *)v24 - 1) != -1596594834 )
                __break(0x8228u);
              v24(v18);
            }
            return sde_encoder_phys_cmd_setup_irq_hw_idx(a1);
          }
LABEL_17:
          v22 = *(void (__fastcall **)(__int64, __int64))(v17 + 8 * v19 + 208);
          if ( v22 )
          {
            v23 = *(_QWORD *)(a1 + 496);
            if ( *((_DWORD *)v22 - 1) != 1894309192 )
              __break(0x8229u);
            v22(v23, a1 + 2688);
          }
          if ( !v18 )
            return sde_encoder_phys_cmd_setup_irq_hw_idx(a1);
          goto LABEL_22;
        }
      }
      else if ( (unsigned int)result <= 2 )
      {
        v19 = (unsigned int)result;
        goto LABEL_17;
      }
      __break(0x5512u);
      return sde_encoder_phys_cmd_mode_fixup();
    }
  }
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "invalid ctl:%d pp:%d\n", v16 == 0, *(_QWORD *)(a1 + 496) == 0);
  return result;
}
