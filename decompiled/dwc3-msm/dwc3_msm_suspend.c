__int64 __fastcall dwc3_msm_suspend(_QWORD *a1, char a2)
{
  __int64 v5; // x8
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v11; // x8
  int v12; // w0
  __int64 v13; // x23
  char v14; // w0
  __int64 v15; // x8
  unsigned int v16; // w22
  __int16 v17; // w0
  unsigned int v18; // w23
  int v19; // w25
  __int16 v20; // w0
  char v21; // w23
  unsigned int v22; // w22
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x0
  void (*v26)(void); // x8
  _BOOL4 v27; // w8
  __int64 v28; // x9
  __int64 v29; // x8
  __int64 v30; // x9
  int v31; // w10
  unsigned int v32; // w8
  unsigned int v33; // w8
  int v34; // w22
  int v35; // w23
  __int64 v36; // x9
  int v37; // w8
  __int16 v38; // w0
  int v39; // w8
  unsigned int v40; // w22
  unsigned int *v41; // x9
  int v42; // w9
  __int64 v43; // x9
  int v44; // w8
  __int16 v45; // w0
  unsigned int v46; // w23
  int v47; // w25
  __int16 v48; // w0
  __int64 v49; // x9
  unsigned int v50; // w10
  int v51; // w9
  unsigned int v52; // w0
  int v53; // w0
  int v54; // w0
  int v55; // w0
  __int64 v56; // x8
  unsigned int v57; // w21
  __int16 v58; // w0
  unsigned int v59; // w22
  int v60; // w24
  __int16 v61; // w0
  __int64 v62; // x8
  __int64 v63; // x1
  __int64 v64; // x0
  void (*v65)(void); // x8
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 v68; // x20
  unsigned int v69; // w0
  __int64 v70; // x8
  const char *v71; // x1
  __int64 v72; // x1
  __int64 v73; // x0
  unsigned int v74; // w20
  unsigned __int64 v75; // x8
  unsigned __int64 v81; // x8

  mutex_lock(a1 + 129);
  if ( *((_DWORD *)a1 + 208) )
  {
LABEL_2:
    mutex_unlock(a1 + 129);
    return 0;
  }
  v5 = a1[5];
  if ( v5 )
    v6 = *(_QWORD *)(v5 + 168);
  else
    v6 = 0;
  v7 = irq_to_desc(*((unsigned int *)a1 + 139));
  if ( (*((_BYTE *)a1 + 2804) & 1) == 0 && v7 )
  {
    cancel_delayed_work_sync(a1 + 116);
    if ( *((_BYTE *)a1 + 744) && *((_DWORD *)a1 + 218) )
    {
      cpu_latency_qos_update_request(a1 + 110, 0xFFFFFFFFLL);
      *((_BYTE *)a1 + 744) = 0;
    }
    cpu_latency_qos_remove_request(a1 + 110);
  }
  v8 = a1[5];
  if ( v8 )
  {
    v9 = *(_QWORD *)(v8 + 168);
    if ( v9 )
    {
      if ( (a1[92] & 1) == 0 && (*(_BYTE *)(*(_QWORD *)(v9 + 584) + 28LL) & 1) != 0 )
        goto LABEL_22;
      if ( *((_DWORD *)a1 + 175) == 3 && *((_DWORD *)a1 + 174) == 3 && *(_DWORD *)(*(_QWORD *)(v9 + 848) + 88LL) != 7 )
      {
        printk(&unk_16ADB);
        printk(&unk_17CC2);
LABEL_22:
        mutex_unlock(a1 + 129);
        return 4294967280LL;
      }
    }
  }
  if ( (*((_BYTE *)a1 + 746) & 1) == 0 && *((_DWORD *)a1 + 175) == 3 && *((_DWORD *)a1 + 174) == 2 )
    goto LABEL_22;
  if ( (a1[92] & 1) == 0 && *((_BYTE *)a1 + 737) != 1 )
  {
LABEL_59:
    disable_irq(*((unsigned int *)a1 + 131));
    v24 = a1[5];
    if ( !v24 )
      goto LABEL_60;
    v29 = a1[56];
    v30 = *(_QWORD *)(v24 + 168);
    if ( v29 )
      *(_DWORD *)(v29 + 16) &= 0xFFFFFFCF;
    v31 = *((unsigned __int8 *)a1 + 736);
    v32 = a1[61] & 0xFFFFFFCF;
    *((_DWORD *)a1 + 122) = v32;
    if ( v31 != 1 )
    {
      if ( *((_DWORD *)a1 + 174) == 3 )
      {
        v42 = *(_DWORD *)(*(_QWORD *)(v30 + 848) + 72LL);
        if ( (unsigned int)(v42 - 2) >= 2 )
        {
          if ( v42 != 1 )
            goto LABEL_60;
          v49 = a1[56];
          if ( v49 )
          {
            *(_DWORD *)(v49 + 16) |= 0x20u;
            v32 = *((_DWORD *)a1 + 122);
          }
          v44 = v32 | 0x20;
        }
        else
        {
          v43 = a1[56];
          if ( v43 )
          {
            *(_DWORD *)(v43 + 16) |= 0x10u;
            v32 = *((_DWORD *)a1 + 122);
          }
          v44 = v32 | 0x10;
        }
        *((_DWORD *)a1 + 122) = v44;
      }
LABEL_60:
      v25 = a1[56];
      if ( v25 )
      {
        v26 = *(void (**)(void))(v25 + 296);
        if ( v26 )
        {
          if ( *((_DWORD *)v26 - 1) != 711694717 )
            __break(0x8228u);
          v26();
        }
      }
      if ( *((_BYTE *)a1 + 736) == 1 )
      {
        if ( (a1[61] & 0x30) == 0 )
        {
LABEL_67:
          v27 = 1;
          v28 = a1[5];
          if ( !v28 )
            goto LABEL_88;
          goto LABEL_109;
        }
        v40 = ((unsigned int)readl((unsigned int *)(a1[1] + 4LL)) >> 24) & 0x7F;
        if ( v40 )
        {
          v45 = readl((unsigned int *)(a1[1] + (unsigned int)(*((_DWORD *)a1 + 700) + 1024)));
          if ( (v45 & 2) == 0 || (v45 & 0x3000) == 0 )
          {
            v46 = 0;
            v47 = 1040;
            while ( v40 - 1 != v46 )
            {
              v48 = readl((unsigned int *)(a1[1] + (unsigned int)(v47 + *((_DWORD *)a1 + 700))));
              v47 += 16;
              ++v46;
              if ( (v48 & 2) != 0 && (v48 & 0x3000) != 0 )
                goto LABEL_108;
            }
            v46 = v40;
LABEL_108:
            v27 = v46 < v40;
            v28 = a1[5];
            if ( !v28 )
              goto LABEL_88;
            goto LABEL_109;
          }
          goto LABEL_67;
        }
      }
      v27 = 0;
      v28 = a1[5];
      if ( !v28 )
      {
LABEL_88:
        v41 = (unsigned int *)(a1 + 141);
LABEL_110:
        v50 = *v41;
        v51 = *((unsigned __int8 *)a1 + 756);
        if ( v50 <= 4 || (v27 & v51 & 1) != 0 )
        {
          if ( (v51 & 1) != 0 )
          {
            v52 = readl((unsigned int *)(a1[1] + 1017944LL));
            writel(v52, (unsigned int *)(a1[1] + 1017944LL));
            v53 = readl((unsigned int *)(a1[1] + 1017948LL));
            writel(v53 | 0x1008, (unsigned int *)(a1[1] + 1017948LL));
            enable_irq(*((unsigned int *)a1 + 131));
          }
          goto LABEL_142;
        }
        if ( *((_BYTE *)a1 + 736) == 1 )
        {
          v54 = readl((unsigned int *)(a1[1] + 49856LL));
          writel(v54 | 0x400000, (unsigned int *)(a1[1] + 49856LL));
          if ( v6 )
          {
            if ( *(_DWORD *)(v6 + 1248) != 13105 || *(_DWORD *)(v6 + 1252) >= 0x3139302Bu )
            {
              v55 = readl((unsigned int *)(a1[1] + 50744LL));
              writel(v55 | 0x20000000, (unsigned int *)(a1[1] + 50744LL));
            }
          }
        }
        v56 = a1[1];
        if ( *((_BYTE *)a1 + 736) == 1 )
        {
          v57 = ((unsigned int)readl((unsigned int *)(v56 + 4)) >> 24) & 0x7F;
          if ( v57 )
          {
            v58 = readl((unsigned int *)(a1[1] + (unsigned int)(*((_DWORD *)a1 + 700) + 1024)));
            if ( (v58 & 2) == 0 || (v58 & 0x3000) == 0 )
            {
              v59 = 0;
              v60 = 1040;
              while ( v57 - 1 != v59 )
              {
                v61 = readl((unsigned int *)(a1[1] + (unsigned int)(v60 + *((_DWORD *)a1 + 700))));
                v60 += 16;
                ++v59;
                if ( (v61 & 2) != 0 && (v61 & 0x3000) != 0 )
                {
                  if ( v59 < v57 )
                    goto LABEL_130;
                  goto LABEL_136;
                }
              }
              goto LABEL_136;
            }
            goto LABEL_130;
          }
        }
        else if ( (readl((unsigned int *)(v56 + 50956)) & 6) == 4 )
        {
LABEL_130:
          v62 = a1[57];
          if ( v62 )
            *(_DWORD *)(v62 + 16) |= 2u;
          if ( *((_BYTE *)a1 + 736) )
            v63 = 5;
          else
            v63 = 10;
          phy_set_mode_ext(a1[60], v63, 0);
        }
LABEL_136:
        v64 = a1[57];
        if ( v64 )
        {
          v65 = *(void (**)(void))(v64 + 296);
          if ( v65 )
          {
            if ( *((_DWORD *)v65 - 1) != 711694717 )
              __break(0x8228u);
            v65();
          }
        }
        a1[96] |= 1uLL;
LABEL_142:
        v66 = a1[60];
        if ( v66 )
          _pm_runtime_idle(*(_QWORD *)(v66 + 96), 4);
        v67 = a1[59];
        if ( v67 )
          _pm_runtime_idle(*(_QWORD *)(v67 + 96), 4);
        __dsb(0xEu);
        if ( (a1[92] & 1) == 0 && *((_BYTE *)a1 + 737) != 1 || (a1[79] & 1) != 0 || (a2 & 1) != 0 )
        {
          v68 = 4;
          a1[96] |= 4uLL;
        }
        else
        {
          v68 = a1[96] & 4LL;
        }
        if ( (*((_BYTE *)a1 + 2804) & 1) != 0 )
        {
          v69 = _pm_runtime_idle(*(_QWORD *)a1[352], 4);
          if ( v68 )
          {
            if ( !v69 )
              v69 = _pm_runtime_idle(*(_QWORD *)(a1[352] + 8LL), 4);
            if ( (v69 & 0x80000000) != 0 )
            {
              v70 = *a1;
              v71 = "power state transit failed d0 to d3 with %d\n";
              goto LABEL_173;
            }
          }
          else if ( (v69 & 0x80000000) != 0 )
          {
            v70 = *a1;
            v71 = "power state transit failed d0 to d1 with %d\n";
LABEL_173:
            v74 = v69;
            dev_err(v70, v71);
            mutex_unlock(a1 + 129);
            return v74;
          }
        }
        else
        {
          dwc3_clk_enable_disable(a1, 0, v68 != 0);
          if ( (a1[96] & 4) != 0 && (*((_BYTE *)a1 + 2804) & 1) == 0 )
          {
            v75 = a1[55];
            if ( v75 )
            {
              if ( v75 <= 0xFFFFFFFFFFFFF000LL )
              {
                qcom_clk_set_flags(a1[42], 3);
                if ( (unsigned int)regulator_disable(a1[55]) )
                  dev_err(*a1, "unable to disable usb3 gdsc\n");
              }
            }
          }
          dwc3_msm_update_bus_bw((__int64)a1, 0);
        }
        v72 = *((unsigned int *)a1 + 209);
        v73 = *a1;
        if ( (_DWORD)v72 )
          pm_wakeup_dev_event(v73, v72, 0);
        else
          pm_relax(v73);
        *((_DWORD *)a1 + 208) = 1;
        if ( (*((_BYTE *)a1 + 737) & 1) != 0 || *((_BYTE *)a1 + 736) == 1 )
        {
          if ( *((_BYTE *)a1 + 749) == 1 )
          {
            enable_usb_pdc_interrupt(a1, 1);
          }
          else
          {
            configure_nonpdc_usb_interrupt(a1, (char *)a1 + 516, 1);
            configure_nonpdc_usb_interrupt(a1, (char *)a1 + 548, 1);
          }
          a1[96] |= 2uLL;
        }
        dev_info(*a1, "DWC3 in low power mode\n");
        dwc3_dbg_print(a1[157], 0xFFu, "Ctl Sus", *((_DWORD *)a1 + 208), (const char *)&unk_16A05);
        _X9 = a1 + 86;
        __asm { PRFM            #0x11, [X9] }
        do
          v81 = __ldxr(_X9);
        while ( __stlxr(v81 & 0xFFFFFFFFFFFFFFF7LL, _X9) );
        __dmb(0xBu);
        if ( (v81 & 8) != 0 )
          queue_work_on(32, a1[81], a1 + 82);
        goto LABEL_2;
      }
LABEL_109:
      v41 = (unsigned int *)(*(_QWORD *)(v28 + 168) + 1232LL);
      goto LABEL_110;
    }
    v33 = ((unsigned int)readl((unsigned int *)(a1[1] + 4LL)) >> 24) & 0x7F;
    if ( !v33 )
      goto LABEL_60;
    v34 = 16 * v33;
    v35 = 0;
    while ( 1 )
    {
      v38 = readl((unsigned int *)(a1[1] + (unsigned int)(v35 + *((_DWORD *)a1 + 700) + 1024)));
      if ( (v38 & 1) == 0 )
        goto LABEL_77;
      v39 = v38 & 0x3C00;
      if ( v39 != 3072 )
      {
        if ( v39 == 2048 )
        {
          v36 = a1[56];
          v37 = 32;
          if ( !v36 )
            goto LABEL_76;
LABEL_75:
          *(_DWORD *)(v36 + 16) |= v37;
          goto LABEL_76;
        }
        if ( v39 != 1024 )
          goto LABEL_77;
      }
      v36 = a1[56];
      v37 = 16;
      if ( v36 )
        goto LABEL_75;
LABEL_76:
      *((_DWORD *)a1 + 122) |= v37;
LABEL_77:
      v35 += 16;
      if ( v34 == v35 )
        goto LABEL_60;
    }
  }
  if ( v8 && (*((_BYTE *)a1 + 756) & 1) == 0 )
  {
    _ZF = *(_DWORD *)(*(_QWORD *)(v8 + 168) + 1248LL) == 21811;
    v11 = 53328;
    if ( _ZF )
      v11 = 49508;
    *((_DWORD *)a1 + 207) = (readl((unsigned int *)(a1[1] + v11)) & 0x3C00000) == 12582912;
  }
  if ( (a2 & 1) != 0 )
  {
LABEL_31:
    if ( (readl((unsigned int *)(a1[1] + 1018104LL)) & 0x10) != 0 )
    {
      writel(0x30u, (unsigned int *)(a1[1] + 1017944LL));
      v12 = readl((unsigned int *)(a1[1] + 49664LL));
      writel(v12 | 0x140, (unsigned int *)(a1[1] + 49664LL));
      v13 = jiffies + 2LL;
      do
        v14 = readl((unsigned int *)(a1[1] + 1017944LL));
      while ( (v14 & 0x10) == 0 && v13 - jiffies >= 0 );
      v21 = v14;
      if ( (v14 & 0x10) != 0 )
      {
        v22 = 0;
      }
      else
      {
        dev_err(*a1, "could not transition HS PHY to L2\n");
        v22 = -16;
      }
      writel(0x10u, (unsigned int *)(a1[1] + 1017944LL));
      if ( (v21 & 0x10) == 0 && (a1[92] & 1) != 0 )
        goto LABEL_50;
    }
    goto LABEL_59;
  }
  v15 = a1[1];
  if ( *((_BYTE *)a1 + 736) == 1 )
  {
    v16 = ((unsigned int)readl((unsigned int *)(v15 + 4)) >> 24) & 0x7F;
    if ( !v16 )
      goto LABEL_31;
    v17 = readl((unsigned int *)(a1[1] + (unsigned int)(*((_DWORD *)a1 + 700) + 1024)));
    if ( (v17 & 2) == 0 || (v17 & 0x3000) == 0 )
    {
      v18 = 0;
      v19 = 1040;
      do
      {
        if ( v16 - 1 == v18 )
          goto LABEL_31;
        v20 = readl((unsigned int *)(a1[1] + (unsigned int)(v19 + *((_DWORD *)a1 + 700))));
        v19 += 16;
        ++v18;
      }
      while ( (v20 & 2) == 0 || (v20 & 0x3000) == 0 );
      if ( v18 >= v16 )
        goto LABEL_31;
    }
  }
  else if ( (readl((unsigned int *)(v15 + 50956)) & 6) != 4 )
  {
    goto LABEL_31;
  }
  if ( (a1[79] & 1) != 0 || *((_DWORD *)a1 + 207) )
    goto LABEL_31;
  dev_err(*a1, "Not in P3,aborting LPM sequence\n");
  v22 = -16;
LABEL_50:
  mutex_unlock(a1 + 129);
  if ( *((_BYTE *)a1 + 736) != 1 )
    return v22;
  if ( !v6 )
    return v22;
  v23 = *(_QWORD *)(v6 + 384);
  if ( !v23 )
    return v22;
  _pm_runtime_resume(v23 + 16, 1);
  return v22;
}
