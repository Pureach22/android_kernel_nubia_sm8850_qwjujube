__int64 __fastcall dwc3_msm_runtime_resume(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  __int64 v3; // x22
  int v4; // w1
  unsigned __int64 v5; // x0
  unsigned int v6; // w20
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned __int64 v9; // x8
  __int64 v10; // x23
  __int64 v11; // x21
  unsigned int v12; // w8
  unsigned int v19; // w10
  unsigned int v20; // w8
  unsigned int v23; // w10
  __int64 v24; // x21
  unsigned int v25; // w0
  unsigned int v26; // w8
  unsigned int v29; // w10
  __int64 v30; // x8
  __int64 v31; // x21
  unsigned int v32; // w0
  unsigned int v33; // w8
  unsigned int v36; // w10
  __int64 v37; // x8
  unsigned int v38; // w0
  __int64 v39; // x8
  _DWORD *v40; // x8
  __int64 v41; // x0
  void (*v42)(void); // x8
  __int64 v43; // x8
  int v44; // w9
  int v45; // w0
  int v46; // w0
  __int64 v47; // x8
  __int64 v48; // x0
  void (*v49)(void); // x8
  unsigned int v50; // w0
  unsigned int v52; // w0
  __int64 v53; // x20
  int v54; // w0
  unsigned __int64 v57; // x10
  unsigned __int64 v60; // x9

  v1 = *(_QWORD **)(a1 + 152);
  dwc3_dbg_print(v1[157], 0xFFu, "RT Res", 0, (const char *)&unk_16A05);
  v2 = v1[5];
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 168);
    if ( (*((_BYTE *)v1 + 746) & 1) != 0 )
      goto LABEL_6;
  }
  else
  {
    v3 = 0;
    if ( (*((_BYTE *)v1 + 746) & 1) != 0 )
      goto LABEL_6;
  }
  if ( *((_DWORD *)v1 + 188) )
  {
    _X8 = v1 + 86;
    __asm { PRFM            #0x11, [X8] }
    do
      v60 = __ldxr(_X8);
    while ( __stxr(v60 | 8, _X8) );
  }
LABEL_6:
  mutex_lock(v1 + 129);
  if ( !*((_DWORD *)v1 + 208) )
  {
    v6 = 0;
    goto LABEL_113;
  }
  pm_stay_awake(*v1);
  if ( (*((_BYTE *)v1 + 2804) & 1) != 0 )
  {
    v10 = v1[96];
    v11 = *(_QWORD *)v1[352];
    v6 = _pm_runtime_resume(v11, 4);
    if ( (v10 & 4) != 0 )
    {
      if ( (v6 & 0x80000000) != 0 )
      {
        v20 = *(_DWORD *)(v11 + 480);
        do
        {
          if ( !v20 )
            break;
          _X12 = (unsigned int *)(v11 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v23 = __ldxr(_X12);
            if ( v23 != v20 )
              break;
            if ( !__stlxr(v20 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v23 == v20;
          v20 = v23;
        }
        while ( !_ZF );
      }
      else
      {
        v24 = *(_QWORD *)(v1[352] + 8LL);
        v25 = _pm_runtime_resume(v24, 4);
        if ( (v25 & 0x80000000) == 0 )
          goto LABEL_62;
        v26 = *(_DWORD *)(v24 + 480);
        v6 = v25;
        do
        {
          if ( !v26 )
            break;
          _X12 = (unsigned int *)(v24 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v29 = __ldxr(_X12);
            if ( v29 != v26 )
              break;
            if ( !__stlxr(v26 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v29 == v26;
          v26 = v29;
        }
        while ( !_ZF );
      }
      dev_err(*v1, "power state transit failed d3 to d0 with %d\n", v6);
      goto LABEL_112;
    }
    if ( (v6 & 0x80000000) != 0 )
    {
      v12 = *(_DWORD *)(v11 + 480);
      do
      {
        if ( !v12 )
          break;
        _X12 = (unsigned int *)(v11 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v19 = __ldxr(_X12);
          if ( v19 != v12 )
            break;
          if ( !__stlxr(v12 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v19 == v12;
        v12 = v19;
      }
      while ( !_ZF );
      dev_err(*v1, "power state transit failed d1 to d0 with %d\n", v6);
      goto LABEL_112;
    }
  }
  else
  {
    if ( *((_BYTE *)v1 + 736) == 1 && *((_DWORD *)v1 + 185) == 3 )
      v4 = 2;
    else
      v4 = *((_DWORD *)v1 + 176);
    dwc3_msm_update_bus_bw((__int64)v1, v4);
    if ( (v1[96] & 4) != 0 )
    {
      if ( (*((_BYTE *)v1 + 2804) & 1) == 0 )
      {
        v5 = v1[55];
        v6 = -1;
        if ( !v5 || v5 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_112;
        v7 = regulator_enable(v5);
        if ( v7 )
        {
          v6 = v7;
          dev_err(*v1, "unable to enable usb3 gdsc\n");
          if ( (v6 & 0x80000000) != 0 )
            goto LABEL_112;
        }
        else
        {
          qcom_clk_set_flags(v1[42], 2);
        }
      }
      if ( (unsigned int)reset_control_assert(v1[54]) )
        dev_err(*v1, "%s:core_reset assert failed\n", "__dwc3_msm_resume");
      usleep_range_state(1000, 1200, 2);
      if ( (unsigned int)reset_control_deassert(v1[54]) )
        dev_err(*v1, "%s:core_reset deassert failed\n", "__dwc3_msm_resume");
    }
    v8 = dwc3_clk_enable_disable(v1, 1, (v1[96] >> 2) & 1LL);
    if ( (v8 & 0x80000000) != 0 )
    {
      v6 = v8;
      if ( (v1[96] & 4) != 0 && (*((_BYTE *)v1 + 2804) & 1) == 0 )
      {
        v9 = v1[55];
        if ( v9 )
        {
          if ( v9 <= 0xFFFFFFFFFFFFF000LL )
          {
            qcom_clk_set_flags(v1[42], 3);
            if ( (unsigned int)regulator_disable(v1[55]) )
              dev_err(*v1, "unable to disable usb3 gdsc\n");
          }
        }
      }
      goto LABEL_112;
    }
  }
LABEL_62:
  if ( *((_BYTE *)v1 + 756) == 1 && (v1[96] & 1) == 0 )
  {
    disable_irq_nosync(*((unsigned int *)v1 + 131));
    dwc3_msm_set_ss_pwr_events(v1, 0);
  }
  v30 = v1[60];
  if ( v30 )
  {
    v31 = *(_QWORD *)(v30 + 96);
    v32 = _pm_runtime_resume(v31, 4);
    if ( (v32 & 0x80000000) != 0 )
    {
      v33 = *(_DWORD *)(v31 + 480);
      v6 = v32;
      do
      {
        if ( !v33 )
          break;
        _X12 = (unsigned int *)(v31 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v36 = __ldxr(_X12);
          if ( v36 != v33 )
            break;
          if ( !__stlxr(v33 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v36 == v33;
        v33 = v36;
      }
      while ( !_ZF );
      dev_err(*v1, "%s:failed to resume usb3_phy\n", "dwc3_msm_resume");
      goto LABEL_112;
    }
  }
  v37 = v1[59];
  if ( v37 )
  {
    v38 = pm_runtime_resume_and_get(*(_QWORD *)(v37 + 96));
    if ( (v38 & 0x80000000) != 0 )
    {
      v6 = v38;
      dev_err(*v1, "%s:failed to resume usb2_phy\n", "dwc3_msm_resume");
      goto LABEL_112;
    }
  }
  v39 = v1[5];
  if ( v39 )
    v40 = (_DWORD *)(*(_QWORD *)(v39 + 168) + 1232LL);
  else
    v40 = v1 + 141;
  if ( *v40 >= 5u && (v1[96] & 1) != 0 )
  {
    dwc3_set_ssphy_orientation_flag((__int64)v1);
    dwc3_msm_typec_switch_set(v1, *((unsigned int *)v1 + 310));
    if ( *((_BYTE *)v1 + 736) != 1 || (*((_BYTE *)v1 + 758) & 1) != 0 || *((_DWORD *)v1 + 185) != 3 )
    {
      v41 = v1[57];
      if ( v41 )
      {
        v42 = *(void (**)(void))(v41 + 296);
        if ( v42 )
        {
          if ( *((_DWORD *)v42 - 1) != 711694717 )
            __break(0x8228u);
          v42();
        }
      }
    }
    v43 = v1[57];
    if ( v43 )
      *(_DWORD *)(v43 + 16) &= ~2u;
    v44 = *((unsigned __int8 *)v1 + 736);
    v1[96] &= ~1uLL;
    if ( v44 == 1 )
    {
      v45 = readl((unsigned int *)(v1[1] + 49856LL));
      writel(v45 & 0xFFBFFFFF, (unsigned int *)(v1[1] + 49856LL));
      if ( v3 )
      {
        if ( *(_DWORD *)(v3 + 1248) != 13105 || *(_DWORD *)(v3 + 1252) >= 0x3139302Bu )
        {
          v46 = readl((unsigned int *)(v1[1] + 50744LL));
          writel(v46 & 0xDFFFFFFF, (unsigned int *)(v1[1] + 50744LL));
        }
      }
    }
  }
  v47 = v1[56];
  if ( v47 )
  {
    *(_DWORD *)(v47 + 16) &= 0xFFFFFFCF;
    v48 = v1[56];
    *((_DWORD *)v1 + 122) &= 0xFFFFFFCF;
    if ( v48 )
    {
      v49 = *(void (**)(void))(v48 + 296);
      if ( v49 )
      {
        if ( *((_DWORD *)v49 - 1) != 711694717 )
          __break(0x8228u);
        v49();
      }
    }
  }
  else
  {
    *((_DWORD *)v1 + 122) &= 0xFFFFFFCF;
  }
  if ( (v1[96] & 4) != 0 )
  {
    v50 = dwc3_msm_power_collapse_por(v1);
    if ( (v50 & 0x80000000) == 0 )
      goto LABEL_117;
    v6 = v50;
    dev_err(*v1, "%s: Controller was not turned on properly\n", "dwc3_msm_resume");
    if ( *((_BYTE *)v1 + 2804) != 1 )
    {
      dwc3_clk_enable_disable(v1, 0, (v1[96] >> 2) & 1LL);
      dwc3_msm_config_gdsc((__int64)v1, 0);
      goto LABEL_112;
    }
    v52 = dwc3_msm_modeled_d0_to_d3((__int64)v1);
    if ( !v52 )
    {
LABEL_117:
      v1[96] &= ~4uLL;
      goto LABEL_118;
    }
    v6 = v52;
    dev_err(*v1, "power state transit failed d0 to d3 with %d\n", v52);
LABEL_112:
    dwc3_msm_update_bus_bw((__int64)v1, 0);
    pm_relax(*v1);
    _X8 = v1 + 86;
    __asm { PRFM            #0x11, [X8] }
    do
      v57 = __ldxr(_X8);
    while ( __stxr(v57 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
    goto LABEL_113;
  }
LABEL_118:
  *((_DWORD *)v1 + 208) = 0;
  enable_irq(*((unsigned int *)v1 + 131));
  v53 = v1[1];
  v54 = readl((unsigned int *)(v53 + 49664));
  writel(v54 & 0xFFFFFFBF, (unsigned int *)(v53 + 49664));
  if ( (v1[96] & 2) != 0 )
  {
    if ( *((_BYTE *)v1 + 749) == 1 )
    {
      enable_usb_pdc_interrupt(v1, 0);
    }
    else
    {
      configure_nonpdc_usb_interrupt(v1, (char *)v1 + 516, 0);
      configure_nonpdc_usb_interrupt(v1, (char *)v1 + 548, 0);
    }
    v1[96] &= ~2uLL;
  }
  dev_info(*v1, "DWC3 exited from low power mode\n");
  dwc3_pwr_event_handler((__int64)v1);
  msm_dwc3_perf_vote_enable((__int64)v1, 1);
  dwc3_msm_set_clk_sel(v1);
  dwc3_dbg_print(v1[157], 0xFFu, "Ctl Res", *((_DWORD *)v1 + 208), (const char *)&unk_16A05);
  v6 = 0;
LABEL_113:
  mutex_unlock(v1 + 129);
  return v6;
}
