void __fastcall sde_encoder_phys_wb_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v12; // x20
  __int64 v13; // x22
  __int64 v14; // x0
  unsigned int disp_op; // w0
  long double v16; // q0
  unsigned int v17; // w21
  int v18; // w4
  __int64 v19; // x8
  int v20; // w5
  void (__fastcall *v21)(__int64, __int64 *, long double); // x8
  __int64 v22; // x8
  int v23; // w4
  __int64 v24; // x8
  int v25; // w5

  _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(a1 + 2680);
  v13 = *(_QWORD *)(a1 + 2936);
  v14 = *(_QWORD *)a1;
  a10 = 0;
  a11 = 0;
  a9 = 0;
  disp_op = sde_encoder_get_disp_op(v14);
  if ( *(_DWORD *)(a1 + 832) == 1 )
    JUMPOUT(0x1AF434);
  v17 = disp_op;
  if ( (_drm_debug & 4) == 0 )
  {
LABEL_11:
    if ( *(_QWORD *)(a1 + 416) && *(_QWORD *)a1 && *(_QWORD *)(a1 + 512) && *(_QWORD *)(a1 + 2904) )
    {
      if ( *(_BYTE *)(a1 + 2912) == 1 )
      {
        if ( v17 >= 3 )
          JUMPOUT(0x1AF4B4);
        v21 = *(void (__fastcall **)(__int64, __int64 *, long double))(v12 + 8LL * v17 + 424);
        if ( v21 )
        {
          if ( *((_DWORD *)v21 - 1) != 1904575617 )
            __break(0x8228u);
          v21(v12, &a9, v16);
        }
        if ( (*(_BYTE *)(a1 + 2290) & 1) == 0 )
        {
          *(_WORD *)(v13 + 7560) = 0;
          *(_BYTE *)(v13 + 7562) = 0;
          sde_core_perf_crtc_update_llcc(*(__int64 **)(a1 + 2936));
        }
      }
      if ( *(_BYTE *)(a1 + 2290) == 1 )
      {
        sde_encoder_phys_wb_setup_cwb(a1, 0, v16);
        sde_encoder_phys_wb_update_cwb_flush(a1, 0);
        v22 = *(_QWORD *)(a1 + 2936);
        *(_DWORD *)(a1 + 832) = 0;
        if ( *(_BYTE *)(*(_QWORD *)(v22 + 2008) + 9LL) == 1 )
        {
          sde_encoder_phys_wb_irq_ctrl(a1, 1);
          JUMPOUT(0x1AF344);
        }
        JUMPOUT(0x1AF448);
      }
      JUMPOUT(0x1AF374);
    }
    if ( (_drm_debug & 4) == 0 )
LABEL_35:
      JUMPOUT(0x1AF278);
    if ( *(_QWORD *)a1 )
    {
      v23 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_33;
    }
    else
    {
      v23 = -1;
      if ( !a1 )
        goto LABEL_33;
    }
    v24 = *(_QWORD *)(a1 + 2864);
    if ( v24 )
    {
      v25 = *(_DWORD *)(v24 + 12) - 1;
LABEL_34:
      _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] invalid hw; skipping extra commit\n", v23, v25);
      goto LABEL_35;
    }
LABEL_33:
    v25 = -1;
    goto LABEL_34;
  }
  if ( *(_QWORD *)a1 )
  {
    v18 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    if ( !a1 )
      goto LABEL_9;
  }
  else
  {
    v18 = -1;
    if ( !a1 )
      goto LABEL_9;
  }
  v19 = *(_QWORD *)(a1 + 2864);
  if ( v19 )
  {
    v20 = *(_DWORD *)(v19 + 12) - 1;
LABEL_10:
    *(double *)&v16 = _drm_dev_dbg(
                        0,
                        0,
                        0,
                        "[enc:%d, wb:%d] clone_mode:%d, kickoff_cnt:%u\n",
                        v18,
                        v20,
                        *(unsigned __int8 *)(a1 + 2290),
                        *(_DWORD *)(a1 + 876));
    goto LABEL_11;
  }
LABEL_9:
  v20 = -1;
  goto LABEL_10;
}
