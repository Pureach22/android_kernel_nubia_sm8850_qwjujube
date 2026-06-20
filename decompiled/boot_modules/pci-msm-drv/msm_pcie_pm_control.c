__int64 __fastcall msm_pcie_pm_control(int a1, int a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v6; // x19
  __int64 v10; // x0
  int v11; // w3
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x27
  int v15; // w20
  __int64 v17; // x0
  int v18; // w8
  __int64 v19; // x1
  unsigned int v20; // w20
  __int64 v21; // x20
  int v22; // w4
  __int64 v23; // x24
  __int64 *v24; // x8
  __int64 *v25; // x22
  __int64 v26; // x9
  __int64 *v27; // x23
  __int64 **v28; // x9
  __int64 v29; // x2
  __int64 *v30; // x1
  char v31; // w25
  _BYTE *v32; // x24
  void *v33; // x0
  __int64 v34; // x23
  __int64 *v35; // x8
  __int64 *v36; // x20
  __int64 v37; // x9
  __int64 *v38; // x22
  __int64 **v39; // x9
  __int64 v40; // x2
  __int64 *v41; // x1
  char v42; // w24
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x9
  __int64 v45; // x8
  __int64 v46; // x21
  __int64 v47; // x0
  __int64 v48; // x21
  __int64 v49; // x21
  int v50; // w0
  int v51; // w0
  int v52; // w0
  unsigned int v53; // w21
  unsigned int v54; // w22
  unsigned int v55; // w8
  __int64 *v56; // x25
  unsigned int i; // w26
  __int64 v58; // x23
  unsigned int v59; // w8
  __int64 *v60; // x25
  unsigned int j; // w26
  __int64 v62; // x23
  unsigned int v63; // w0
  __int64 v64; // x0
  int v65; // w0
  __int64 *v66; // x28
  unsigned int k; // w25
  __int64 v68; // x24
  int v69; // w0
  __int64 v70; // x21
  int v71; // w0
  int v72; // w0
  char v73; // w21
  __int64 *v74; // x26
  unsigned int m; // w28
  __int64 v76; // x25
  __int64 v77; // x21
  int v78; // w0
  __int64 v79; // x21
  int v80; // w0
  unsigned __int64 v81; // x8
  unsigned __int64 v82; // x9
  __int64 v83; // x8
  unsigned int v84; // w1
  unsigned int v85; // w20
  int v86; // w22
  int v87; // w22
  int v88; // w22
  int v89; // w20
  int v90; // w22
  int v91; // w22
  int v92; // w22
  unsigned int v93; // w21
  __int64 **v94; // x8
  __int64 *v95; // x9
  __int64 *v96; // x1
  unsigned int v97; // w23
  __int64 **v98; // x8
  __int64 *v99; // x9
  __int64 *v100; // x1
  unsigned __int64 v107; // x10
  unsigned __int64 v110; // x10

  if ( !a3 )
  {
    v33 = &unk_2A5B2;
LABEL_64:
    printk(v33);
    return 4294967277LL;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 16) + 232LL) + 200LL);
  if ( !v6 )
  {
    v33 = &unk_2F4AF;
    goto LABEL_64;
  }
  ipc_log_string(
    *(_QWORD *)(v6 + 1704),
    "DBG1:%s: PCIe: RC%d: pm_opt:%d;busnr:%d;options:%d\n",
    "msm_pcie_pm_ctrl_sanity_check",
    *(_DWORD *)(v6 + 1348),
    a1,
    a2,
    a5);
  ipc_log_string(
    *(_QWORD *)(v6 + 1696),
    "%s: PCIe: RC%d: pm_opt:%d;busnr:%d;options:%d\n",
    "msm_pcie_pm_ctrl_sanity_check",
    *(_DWORD *)(v6 + 1348),
    a1,
    a2,
    a5);
  if ( (*(_BYTE *)(v6 + 1356) & 1) == 0 )
  {
    ipc_log_string(
      *(_QWORD *)(v6 + 1704),
      "ERR:%s: RC%d has not been successfully probed yet\n",
      "msm_pcie_pm_ctrl_sanity_check",
      *(_DWORD *)(v6 + 1348));
    ipc_log_string(
      *(_QWORD *)(v6 + 1696),
      "%s: RC%d has not been successfully probed yet\n",
      "msm_pcie_pm_ctrl_sanity_check",
      *(_DWORD *)(v6 + 1348));
    printk(&unk_223F9);
    return 4294966779LL;
  }
  v10 = *(_QWORD *)(v6 + 1704);
  v11 = *(_DWORD *)(v6 + 1348);
  if ( (a1 & 0x41) != 0 && (*(_BYTE *)(v6 + 1992) & 1) == 0 )
  {
    ipc_log_string(v10, "ERR:%s: PCIe: RC%d: drv not supported opt %d.\n", "msm_pcie_pm_ctrl_sanity_check", v11, a1);
    ipc_log_string(
      *(_QWORD *)(v6 + 1696),
      "%s: PCIe: RC%d: drv not supported opt %d.\n",
      "msm_pcie_pm_ctrl_sanity_check",
      *(_DWORD *)(v6 + 1348),
      a1);
    printk(&unk_2D37A);
    return 4294967274LL;
  }
  if ( a1 <= 7 )
  {
    if ( a1 == 1 )
    {
      ipc_log_string(v10, "DBG1:%s: PCIe: RC%d: DRV: user requests for DRV suspend\n", "msm_pcie_pm_control", v11);
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d: DRV: user requests for DRV suspend\n",
        "msm_pcie_pm_control",
        *(_DWORD *)(v6 + 1348));
      flush_work(v6 + 1832);
      v32 = *(_BYTE **)(v6 + 1792);
      if ( !*(_QWORD *)(v6 + 3128) && (*v32 & 1) == 0 )
      {
        ipc_log_string(
          *(_QWORD *)(v6 + 1704),
          "ERR:%s: PCIe: RC%d: DRV: client requests to DRV suspend while not connected\n",
          "msm_pcie_drv_suspend",
          *(_DWORD *)(v6 + 1348));
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d: DRV: client requests to DRV suspend while not connected\n",
          "msm_pcie_drv_suspend",
          *(_DWORD *)(v6 + 1348));
        printk(&unk_2644D);
        return 4294967274LL;
      }
      mutex_lock(v6 + 1424);
      if ( !*(_QWORD *)(v6 + 3128) )
        disable_irq(*(unsigned int *)(v6 + 640));
      if ( (unsigned int)msm_pcie_drv_send_rpmsg(v6, v32 + 1) )
      {
        if ( !*(_QWORD *)(v6 + 3128) )
          enable_irq(*(unsigned int *)(v6 + 640));
        mutex_unlock(v6 + 1424);
        return 4294967280LL;
      }
      if ( (*(_BYTE *)(v6 + 1340) & 1) == 0 )
        msm_msi_config_access(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 816LL), 0);
      v43 = *(unsigned int *)(v6 + 1348);
      *(_BYTE *)(v6 + 1180) = 1;
      v44 = v43 >> 6;
      v45 = 1LL << v43;
      _X9 = (unsigned __int64 *)&pcie_drv[2 * v44 + 2];
      __asm { PRFM            #0x11, [X9] }
      do
        v107 = __ldxr(_X9);
      while ( __stxr(v107 | v45, _X9) );
      v46 = raw_spin_lock_irqsave(v6 + 1472);
      v47 = raw_spin_lock_irqsave(v6 + 1060);
      *(_BYTE *)(v6 + 1056) = 0;
      raw_spin_unlock_irqrestore(v6 + 1060, v47);
      raw_spin_unlock_irqrestore(v6 + 1472, v46);
      mutex_lock(v6 + 1120);
      mutex_lock(v6 + 1480);
      *(_DWORD *)(v6 + 1176) = 3;
      mutex_unlock(v6 + 1480);
      if ( *(_QWORD *)(v6 + 3128) )
      {
        if ( (a5 & 4) == 0 )
        {
          v48 = *(_QWORD *)(v6 + 872);
          writel_relaxed_0(0x80000000LL, v48 + 384);
          readl_relaxed_0((unsigned int *)(v48 + 384));
          v49 = *(_QWORD *)(v6 + 872);
          writel_relaxed_0((*(_DWORD *)(v6 + 1324) * *(_DWORD *)(v6 + 3144)) | 0x80000000, v49 + 384);
          readl_relaxed_0((unsigned int *)(v49 + 384));
        }
        v50 = msm_gpio_mpm_wake_set(*(unsigned int *)(v6 + 3152), 1);
        if ( v50 )
        {
          v86 = v50;
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "ERR:%s: Failed to make clkreq wakeup capable%d\n",
            "msm_pcie_cesta_enable_drv",
            v50);
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: Failed to make clkreq wakeup capable%d\n",
            "msm_pcie_cesta_enable_drv",
            v86);
          printk(&unk_22AF8);
        }
        v51 = pcie_pdc_cfg_irq(*(unsigned int *)(v6 + 3152), 2, 1);
        if ( v51 )
        {
          v87 = v51;
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "ERR:%s: Failed to make clkreq pdc wakeup capable%d\n",
            "msm_pcie_cesta_enable_drv",
            v51);
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: Failed to make clkreq pdc wakeup capable%d\n",
            "msm_pcie_cesta_enable_drv",
            v87);
          printk(&unk_25AEC);
        }
        v52 = msm_pcie_cesta_map_apply(v6, 2);
        if ( v52 )
        {
          v88 = v52;
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "ERR:%s: Failed to move to DRV state %d\n",
            "msm_pcie_cesta_enable_drv",
            v52);
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: Failed to move to DRV state %d\n",
            "msm_pcie_cesta_enable_drv",
            v88);
          printk(&unk_2F446);
        }
        v53 = 800;
        v54 = 500;
      }
      else
      {
        v54 = 0;
        v53 = 0;
      }
      v55 = *(_DWORD *)(v6 + 840);
      if ( v55 )
      {
        v56 = *(__int64 **)(v6 + 848);
        for ( i = 0; i < v55; ++i )
        {
          v58 = *v56;
          if ( *v56 && (*((_BYTE *)v56 + 20) & 1) == 0 )
          {
            clk_disable(*v56);
            clk_unprepare(v58);
            v55 = *(_DWORD *)(v6 + 840);
          }
          v56 += 3;
        }
      }
      v59 = *(_DWORD *)(v6 + 856);
      if ( v59 )
      {
        v60 = *(__int64 **)(v6 + 864);
        for ( j = 0; j < v59; ++j )
        {
          v62 = *v60;
          if ( *v60 && (*((_BYTE *)v60 + 20) & 1) == 0 )
          {
            clk_disable(*v60);
            clk_unprepare(v62);
            v59 = *(_DWORD *)(v6 + 856);
          }
          v60 += 3;
        }
      }
      if ( !(*(_DWORD *)(v6 + 3148) | a5 & 4) )
        msm_pcie_drv_send_rpmsg(v6, v32 + 81);
      v63 = msm_pcie_icc_vote(v6, v54, v53, 1);
      if ( !v63 )
      {
        if ( (*(_BYTE *)(v6 + 1342) & 1) == 0 )
        {
          msm_pcie_genpd_gdsc_disable(v6, *(_QWORD *)(v6 + 40));
          if ( *(_QWORD *)(v6 + 24) )
            regulator_disable();
        }
        msm_pcie_vreg_deinit(v6);
        v64 = v6 + 1120;
LABEL_165:
        mutex_unlock(v64);
        mutex_unlock(v6 + 1424);
        return 0;
      }
      goto LABEL_153;
    }
    if ( a1 != 2 )
    {
      if ( a1 != 4 )
      {
LABEL_154:
        ipc_log_string(v10, "ERR:%s: PCIe: RC%d: unsupported pm operation:%d.\n", "msm_pcie_pm_control", v11, a1);
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d: unsupported pm operation:%d.\n",
          "msm_pcie_pm_control",
          *(_DWORD *)(v6 + 1348),
          a1);
        printk(&unk_2661A);
        return 4294967277LL;
      }
      ipc_log_string(v10, "DBG1:%s: User of RC%d requests to resume the link\n", "msm_pcie_pm_control", v11);
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: User of RC%d requests to resume the link\n",
        "msm_pcie_pm_control",
        *(_DWORD *)(v6 + 1348));
      if ( *(_DWORD *)(v6 + 1176) == 3 )
      {
        v14 = *(_QWORD *)(v6 + 1792);
        mutex_lock(v6 + 1424);
        mutex_lock(v6 + 1120);
        if ( ((*(_QWORD *)((char *)&pcie_drv[2] + (((unsigned __int64)*(unsigned int *)(v6 + 1348) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v6 + 1348))
            & 1) != 0
          && !*(_DWORD *)(v6 + 3148) )
        {
          v15 = msm_pcie_drv_send_rpmsg(v6, v14 + 121);
        }
        else
        {
          v15 = 0;
        }
        msm_pcie_vreg_init(v6);
        ipc_log_string(
          *(_QWORD *)(v6 + 1704),
          "DBG1:%s: PCIe: RC%d:enable gdsc-core\n",
          "msm_pcie_drv_resume",
          *(_DWORD *)(v6 + 1348));
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d:enable gdsc-core\n",
          "msm_pcie_drv_resume",
          *(_DWORD *)(v6 + 1348));
        if ( (*(_BYTE *)(v6 + 1342) & 1) == 0 )
        {
          v63 = msm_pcie_genpd_gdsc_enable(v6, *(_QWORD *)(v6 + 40));
          if ( *(_QWORD *)(v6 + 24) )
          {
            v65 = regulator_enable(*(_QWORD *)(v6 + 24));
            if ( v65 )
            {
              v89 = v65;
              ipc_log_string(
                *(_QWORD *)(v6 + 1704),
                "ERR:%s: PCIe: RC%d: failed to enable GDSC: ret %d\n",
                "msm_pcie_drv_resume",
                *(_DWORD *)(v6 + 1348),
                v65);
              ipc_log_string(
                *(_QWORD *)(v6 + 1696),
                "%s: PCIe: RC%d: failed to enable GDSC: ret %d\n",
                "msm_pcie_drv_resume",
                *(_DWORD *)(v6 + 1348),
                v89);
              printk(&unk_24854);
              v63 = v89;
              goto LABEL_153;
            }
          }
          else if ( v63 )
          {
            goto LABEL_153;
          }
        }
        ipc_log_string(
          *(_QWORD *)(v6 + 1704),
          "DBG1:%s: PCIe: RC%d:set ICC path vote\n",
          "msm_pcie_drv_resume",
          *(_DWORD *)(v6 + 1348));
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d:set ICC path vote\n",
          "msm_pcie_drv_resume",
          *(_DWORD *)(v6 + 1348));
        v63 = msm_pcie_icc_vote(v6, 500, 800, 0);
        if ( !v63 )
        {
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "DBG1:%s: PCIe: RC%d:turn on unsuppressible clks\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: PCIe: RC%d:turn on unsuppressible clks\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          if ( *(_DWORD *)(v6 + 856) )
          {
            v66 = *(__int64 **)(v6 + 864);
            for ( k = 0; k < *(_DWORD *)(v6 + 856); ++k )
            {
              v68 = *v66;
              if ( !*v66 || (*((_BYTE *)v66 + 20) & 1) != 0 )
                goto LABEL_109;
              if ( !(unsigned int)clk_prepare(*v66) )
              {
                if ( !(unsigned int)clk_enable(v68) )
                  goto LABEL_109;
                clk_unprepare(v68);
              }
              ipc_log_string(
                *(_QWORD *)(v6 + 1704),
                "DBG1:%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                "msm_pcie_drv_resume",
                *(_DWORD *)(v6 + 1348),
                (const char *)v66[1]);
              ipc_log_string(
                *(_QWORD *)(v6 + 1696),
                "%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                "msm_pcie_drv_resume",
                *(_DWORD *)(v6 + 1348),
                (const char *)v66[1]);
LABEL_109:
              v66 += 3;
            }
          }
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "DBG1:%s: PCIe: RC%d:turn on unsuppressible clks Done.\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: PCIe: RC%d:turn on unsuppressible clks Done.\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          if ( *(_QWORD *)(v6 + 3128) )
          {
            v69 = msm_pcie_cesta_map_apply(v6, 1);
            if ( v69 )
            {
              v90 = v69;
              ipc_log_string(
                *(_QWORD *)(v6 + 1704),
                "ERR:%s: Failed to move to D0 State %d\n",
                "msm_pcie_cesta_disable_drv",
                v69);
              ipc_log_string(
                *(_QWORD *)(v6 + 1696),
                "%s: Failed to move to D0 State %d\n",
                "msm_pcie_cesta_disable_drv",
                v90);
              printk(&unk_30A69);
            }
            v70 = *(_QWORD *)(v6 + 872);
            writel_relaxed_0(0, v70 + 384);
            readl_relaxed_0((unsigned int *)(v70 + 384));
            v71 = msm_gpio_mpm_wake_set(*(unsigned int *)(v6 + 3152), 0);
            if ( v71 )
            {
              v91 = v71;
              ipc_log_string(
                *(_QWORD *)(v6 + 1704),
                "ERR:%s: Fail to remove clkreq wakeup capable%d\n",
                "msm_pcie_cesta_disable_drv",
                v71);
              ipc_log_string(
                *(_QWORD *)(v6 + 1696),
                "%s: Fail to remove clkreq wakeup capable%d\n",
                "msm_pcie_cesta_disable_drv",
                v91);
              printk(&unk_23932);
            }
            v72 = pcie_pdc_cfg_irq(*(unsigned int *)(v6 + 3152), 2, 0);
            if ( v72 )
            {
              v92 = v72;
              ipc_log_string(
                *(_QWORD *)(v6 + 1704),
                "ERR:%s: Fail to remove clkreq pdc wakeup capable%d\n",
                "msm_pcie_cesta_disable_drv",
                v72);
              ipc_log_string(
                *(_QWORD *)(v6 + 1696),
                "%s: Fail to remove clkreq pdc wakeup capable%d\n",
                "msm_pcie_cesta_disable_drv",
                v92);
              printk(&unk_303BA);
            }
          }
          v73 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v6 + 872) + 688LL));
          if ( (v73 & 2) != 0 )
          {
            ipc_log_string(
              *(_QWORD *)(v6 + 1704),
              "DBG1:%s: PCIe: RC%d: CLKREQ Override detected\n",
              "msm_pcie_drv_resume",
              *(_DWORD *)(v6 + 1348));
            ipc_log_string(
              *(_QWORD *)(v6 + 1696),
              "%s: PCIe: RC%d: CLKREQ Override detected\n",
              "msm_pcie_drv_resume",
              *(_DWORD *)(v6 + 1348));
            if ( *(_QWORD *)(v6 + 1016) )
            {
              if ( *(_QWORD *)(v6 + 1048) )
              {
                ipc_log_string(
                  *(_QWORD *)(v6 + 1704),
                  "DBG1:%s: PCIe: RC%d: setting PCIe PIPE MUX to XO\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v6 + 1696),
                  "%s: PCIe: RC%d: setting PCIe PIPE MUX to XO\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                clk_set_parent(*(_QWORD *)(v6 + 1016), *(_QWORD *)(v6 + 1048));
              }
              if ( *(_QWORD *)(v6 + 1024) )
              {
                ipc_log_string(
                  *(_QWORD *)(v6 + 1704),
                  "DBG1:%s: PCIe: RC%d: setting PCIe PIPE MUX to PCIe PIPE\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v6 + 1696),
                  "%s: PCIe: RC%d: setting PCIe PIPE MUX to PCIe PIPE\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                clk_set_parent(*(_QWORD *)(v6 + 1016), *(_QWORD *)(v6 + 1024));
              }
            }
            if ( *(_QWORD *)(v6 + 1032) )
            {
              if ( *(_QWORD *)(v6 + 1048) )
              {
                ipc_log_string(
                  *(_QWORD *)(v6 + 1704),
                  "DBG1:%s: PCIe: RC%d: setting PCIe phy aux MUX to XO\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v6 + 1696),
                  "%s: PCIe: RC%d: setting PCIe phy aux MUX to XO\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                clk_set_parent(*(_QWORD *)(v6 + 1032), *(_QWORD *)(v6 + 1048));
              }
              if ( *(_QWORD *)(v6 + 1040) )
              {
                ipc_log_string(
                  *(_QWORD *)(v6 + 1704),
                  "DBG1:%s: PCIe: RC%d: setting PCIe phy aux MUX to phy aux clk\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                ipc_log_string(
                  *(_QWORD *)(v6 + 1696),
                  "%s: PCIe: RC%d: setting PCIe phy aux MUX to phy aux clk\n",
                  "msm_pcie_drv_resume",
                  *(_DWORD *)(v6 + 1348));
                clk_set_parent(*(_QWORD *)(v6 + 1032), *(_QWORD *)(v6 + 1040));
              }
            }
          }
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "DBG1:%s: PCIe: RC%d:turn on pipe clk\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: PCIe: RC%d:turn on pipe clk\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          if ( *(_DWORD *)(v6 + 840) )
          {
            v74 = *(__int64 **)(v6 + 848);
            for ( m = 0; m < *(_DWORD *)(v6 + 840); ++m )
            {
              v76 = *v74;
              if ( !*v74 || (*((_BYTE *)v74 + 20) & 1) != 0 )
                goto LABEL_136;
              if ( !(unsigned int)clk_prepare(*v74) )
              {
                if ( !(unsigned int)clk_enable(v76) )
                  goto LABEL_136;
                clk_unprepare(v76);
              }
              ipc_log_string(
                *(_QWORD *)(v6 + 1704),
                "DBG1:%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                "msm_pcie_drv_resume",
                *(_DWORD *)(v6 + 1348),
                (const char *)v74[1]);
              ipc_log_string(
                *(_QWORD *)(v6 + 1696),
                "%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                "msm_pcie_drv_resume",
                *(_DWORD *)(v6 + 1348),
                (const char *)v74[1]);
LABEL_136:
              v74 += 3;
            }
          }
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "DBG1:%s: PCIe: RC%d:turn on pipe clk, Done\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: PCIe: RC%d:turn on pipe clk, Done\n",
            "msm_pcie_drv_resume",
            *(_DWORD *)(v6 + 1348));
          if ( (v73 & 2) != 0 )
          {
            v77 = *(_QWORD *)(v6 + 872);
            v78 = readl_relaxed_0((unsigned int *)(v77 + 688));
            writel_relaxed_0(v78 & 0xFFFFFFFD, v77 + 688);
            readl_relaxed_0((unsigned int *)(v77 + 688));
            v79 = *(_QWORD *)(v6 + 872);
            v80 = readl_relaxed_0((unsigned int *)(v79 + 688));
            writel_relaxed_0(v80 & 0xFFFFFFF7, v79 + 688);
            readl_relaxed_0((unsigned int *)(v79 + 688));
          }
          if ( ((*(_QWORD *)((char *)&pcie_drv[2] + (((unsigned __int64)*(unsigned int *)(v6 + 1348) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v6 + 1348))
              & 1) != 0
            && !v15 )
          {
            msm_pcie_drv_send_rpmsg(v6, v14 + 41);
            v81 = *(unsigned int *)(v6 + 1348);
            v82 = v81 >> 6;
            v83 = 1LL << v81;
            _X9 = (unsigned __int64 *)&pcie_drv[2 * v82 + 2];
            __asm { PRFM            #0x11, [X9] }
            do
              v110 = __ldxr(_X9);
            while ( __stxr(v110 & ~v83, _X9) );
          }
          v84 = ((unsigned int)readl_relaxed_0((unsigned int *)(*(_QWORD *)(v6 + 904) + 128LL)) >> 16) & 0xF;
          *(_DWORD *)(v6 + 1252) = v84;
          msm_pcie_scale_link_bandwidth(v6, v84);
          *(_BYTE *)(v6 + 1180) = 0;
          raw_spin_lock_irq(v6 + 1060);
          *(_BYTE *)(v6 + 1056) = 1;
          raw_spin_unlock_irq(v6 + 1060);
          mutex_lock(v6 + 1480);
          *(_DWORD *)(v6 + 1176) = 1;
          mutex_unlock(v6 + 1480);
          if ( (*(_BYTE *)(v6 + 1340) & 1) == 0 )
            msm_msi_config_access(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 816LL), 1);
          if ( !*(_QWORD *)(v6 + 3128) )
            enable_irq(*(unsigned int *)(v6 + 640));
          v63 = 0;
        }
LABEL_153:
        v85 = v63;
        mutex_unlock(v6 + 1120);
        mutex_unlock(v6 + 1424);
        return v85;
      }
      v34 = *(_QWORD *)(v6 + 8);
      mutex_lock(v6 + 1424);
      mutex_lock(v6 + 1072);
      v35 = *(__int64 **)(v6 + 1600);
      v36 = (__int64 *)(v6 + 1600);
      do
      {
        if ( v35 == v36 )
          goto LABEL_178;
        v37 = v35[2];
        v38 = v35;
        v35 = (__int64 *)*v35;
      }
      while ( v37 != a3 );
      v39 = (__int64 **)v38[1];
      if ( *v39 == v38 && (__int64 *)v35[1] == v38 )
      {
        v35[1] = (__int64)v39;
        *v39 = v35;
      }
      else
      {
        _list_del_entry_valid_or_report(v38);
      }
      v40 = v6 + 1584;
      *v38 = 0xDEAD000000000100LL;
      v38[1] = 0xDEAD000000000122LL;
      v41 = *(__int64 **)(v6 + 1592);
      if ( v38 == (__int64 *)(v6 + 1584) || v41 == v38 || *v41 != v40 )
      {
        _list_add_valid_or_report(v38, v41, v40);
        if ( v38 )
          goto LABEL_62;
      }
      else
      {
        *(_QWORD *)(v6 + 1592) = v38;
        *v38 = v40;
        v38[1] = (__int64)v41;
        *v41 = (__int64)v38;
        if ( v38 )
        {
LABEL_62:
          v42 = 0;
          goto LABEL_179;
        }
      }
LABEL_178:
      ipc_log_string(
        *(_QWORD *)(v6 + 1704),
        "DBG1:%s: PCIe: RC%d: ep BDF 0x%04x not in susp list\n",
        "msm_pcie_handle_pm_resume",
        *(_DWORD *)(v6 + 1348),
        *(_DWORD *)(a3 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 248LL) << 8));
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d: ep BDF 0x%04x not in susp list\n",
        "msm_pcie_handle_pm_resume",
        *(_DWORD *)(v6 + 1348),
        *(_DWORD *)(a3 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 248LL) << 8));
      v38 = nullptr;
      v42 = 1;
LABEL_179:
      mutex_unlock(v6 + 1072);
      if ( *(_BYTE *)(v6 + 1692) == 1 )
      {
        ipc_log_string(
          *(_QWORD *)(v6 + 1704),
          "ERR:%s: PCIe: RC%d: requested to resume when link is already powered on.\n",
          "msm_pcie_handle_pm_resume",
          *(_DWORD *)(v6 + 1348));
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d: requested to resume when link is already powered on.\n",
          "msm_pcie_handle_pm_resume",
          *(_DWORD *)(v6 + 1348));
        printk(&unk_22B4D);
        v97 = 0;
      }
      else
      {
        v97 = msm_pcie_pm_resume(v34);
        if ( v97 )
        {
          ipc_log_string(
            *(_QWORD *)(v6 + 1704),
            "ERR:%s: PCIe: RC%d: user failed to resume the link.\n",
            "msm_pcie_handle_pm_resume",
            *(_DWORD *)(v6 + 1348));
          ipc_log_string(
            *(_QWORD *)(v6 + 1696),
            "%s: PCIe: RC%d: user failed to resume the link.\n",
            "msm_pcie_handle_pm_resume",
            *(_DWORD *)(v6 + 1348));
          printk(&unk_275A9);
          mutex_lock(v6 + 1072);
          if ( (v42 & 1) == 0 )
          {
            v98 = (__int64 **)v38[1];
            if ( *v98 == v38 && (v99 = (__int64 *)*v38, *(__int64 **)(*v38 + 8) == v38) )
            {
              v99[1] = (__int64)v98;
              *v98 = v99;
            }
            else
            {
              _list_del_entry_valid_or_report(v38);
            }
            *v38 = 0xDEAD000000000100LL;
            v38[1] = 0xDEAD000000000122LL;
            v100 = *(__int64 **)(v6 + 1608);
            if ( v38 == v36 || v100 == v38 || (__int64 *)*v100 != v36 )
            {
              _list_add_valid_or_report(v38, v100, v6 + 1600);
            }
            else
            {
              *(_QWORD *)(v6 + 1608) = v38;
              *v38 = (__int64)v36;
              v38[1] = (__int64)v100;
              *v100 = (__int64)v38;
            }
          }
          mutex_unlock(v6 + 1072);
        }
        ipc_log_string(
          *(_QWORD *)(v6 + 1704),
          "DBG1:%s: PCIe: RC%d: user succeeded to resume the link.\n",
          "msm_pcie_handle_pm_resume",
          *(_DWORD *)(v6 + 1348));
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: PCIe: RC%d: user succeeded to resume the link.\n",
          "msm_pcie_handle_pm_resume",
          *(_DWORD *)(v6 + 1348));
        *(_BYTE *)(v6 + 1180) = 0;
      }
      mutex_unlock(v6 + 1424);
      return v97;
    }
    ipc_log_string(v10, "DBG1:%s: User of RC%d requests to suspend the link\n", "msm_pcie_pm_control", v11);
    ipc_log_string(
      *(_QWORD *)(v6 + 1696),
      "%s: User of RC%d requests to suspend the link\n",
      "msm_pcie_pm_control",
      *(_DWORD *)(v6 + 1348));
    v22 = *(_DWORD *)(v6 + 1176);
    v23 = *(_QWORD *)(v6 + 8);
    if ( v22 != 1 )
    {
      ipc_log_string(
        *(_QWORD *)(v6 + 1704),
        "DBG1:%s: PCIe: RC%d: requested to suspend when link is not enabled:%d.\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348),
        v22);
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d: requested to suspend when link is not enabled:%d.\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348),
        *(_DWORD *)(v6 + 1176));
    }
    if ( (*(_BYTE *)(v6 + 1692) & 1) == 0 )
    {
      ipc_log_string(
        *(_QWORD *)(v6 + 1704),
        "ERR:%s: PCIe: RC%d: requested to suspend when link is powered down:%d.\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348),
        *(_DWORD *)(v6 + 1176));
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d: requested to suspend when link is powered down:%d.\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348),
        *(_DWORD *)(v6 + 1176));
      printk(&unk_231D3);
      return 0;
    }
    mutex_lock(v6 + 1424);
    mutex_lock(v6 + 1072);
    v24 = *(__int64 **)(v6 + 1584);
    v25 = (__int64 *)(v6 + 1584);
    do
    {
      if ( v24 == v25 )
        goto LABEL_162;
      v26 = v24[2];
      v27 = v24;
      v24 = (__int64 *)*v24;
    }
    while ( v26 != a3 );
    v28 = (__int64 **)v27[1];
    if ( *v28 == v27 && (__int64 *)v24[1] == v27 )
    {
      v24[1] = (__int64)v28;
      *v28 = v24;
    }
    else
    {
      _list_del_entry_valid_or_report(v27);
    }
    v29 = v6 + 1600;
    *v27 = 0xDEAD000000000100LL;
    v27[1] = 0xDEAD000000000122LL;
    v30 = *(__int64 **)(v6 + 1608);
    if ( v27 == (__int64 *)(v6 + 1600) || v30 == v27 || *v30 != v29 )
    {
      _list_add_valid_or_report(v27, v30, v29);
      if ( v27 )
      {
LABEL_41:
        v31 = 0;
        if ( (a5 & 0x10) != 0 )
          goto LABEL_166;
        goto LABEL_163;
      }
    }
    else
    {
      *(_QWORD *)(v6 + 1608) = v27;
      *v27 = v29;
      v27[1] = (__int64)v30;
      *v30 = (__int64)v27;
      if ( v27 )
        goto LABEL_41;
    }
LABEL_162:
    ipc_log_string(
      *(_QWORD *)(v6 + 1704),
      "DBG1:%s: PCIe: RC%d: ep BDF 0x%04x not in enum list\n",
      "msm_pcie_handle_pm_suspend",
      *(_DWORD *)(v6 + 1348),
      *(_DWORD *)(a3 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 248LL) << 8));
    ipc_log_string(
      *(_QWORD *)(v6 + 1696),
      "%s: PCIe: RC%d: ep BDF 0x%04x not in enum list\n",
      "msm_pcie_handle_pm_suspend",
      *(_DWORD *)(v6 + 1348),
      *(_DWORD *)(a3 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 248LL) << 8));
    v27 = nullptr;
    v31 = 1;
    if ( (a5 & 0x10) != 0 )
      goto LABEL_166;
LABEL_163:
    if ( (__int64 *)*v25 != v25 )
    {
      ipc_log_string(
        *(_QWORD *)(v6 + 1704),
        "DBG1:%s: PCIe: RC%d: request to suspend the link is rejected\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348));
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d: request to suspend the link is rejected\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348));
      v64 = v6 + 1072;
      goto LABEL_165;
    }
LABEL_166:
    *(_BYTE *)(v6 + 1180) = 1;
    v93 = msm_pcie_pm_suspend(v23);
    if ( v93 )
    {
      ipc_log_string(
        *(_QWORD *)(v6 + 1704),
        "ERR:%s: PCIe: RC%d: user failed to suspend the link.\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348));
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d: user failed to suspend the link.\n",
        "msm_pcie_handle_pm_suspend",
        *(_DWORD *)(v6 + 1348));
      printk(&unk_2BFB0);
      *(_BYTE *)(v6 + 1180) = 0;
      if ( (v31 & 1) == 0 )
      {
        v94 = (__int64 **)v27[1];
        if ( *v94 == v27 && (v95 = (__int64 *)*v27, *(__int64 **)(*v27 + 8) == v27) )
        {
          v95[1] = (__int64)v94;
          *v94 = v95;
        }
        else
        {
          _list_del_entry_valid_or_report(v27);
        }
        *v27 = 0xDEAD000000000100LL;
        v27[1] = 0xDEAD000000000122LL;
        v96 = *(__int64 **)(v6 + 1592);
        if ( v27 == v25 || v96 == v27 || (__int64 *)*v96 != v25 )
        {
          _list_add_valid_or_report(v27, v96, v6 + 1584);
        }
        else
        {
          *(_QWORD *)(v6 + 1592) = v27;
          *v27 = (__int64)v25;
          v27[1] = (__int64)v96;
          *v96 = (__int64)v27;
        }
      }
    }
    mutex_unlock(v6 + 1072);
    mutex_unlock(v6 + 1424);
    return v93;
  }
  if ( a1 > 31 )
  {
    if ( a1 == 32 )
    {
      ipc_log_string(v10, "DBG1:%s: User of RC%d requests handling link down.\n", "msm_pcie_pm_control", v11);
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: User of RC%d requests handling link down.\n",
        "msm_pcie_pm_control",
        *(_DWORD *)(v6 + 1348));
      v21 = raw_spin_lock_irqsave(v6 + 1472);
      msm_pcie_handle_linkdown(v6);
      v13 = v6 + 1472;
      v12 = v21;
      goto LABEL_27;
    }
    if ( a1 != 64 )
      goto LABEL_154;
    ipc_log_string(v10, "DBG1:%s: User of RC%d requests handling drv pc options %u.\n", "msm_pcie_pm_control", v11, a5);
    ipc_log_string(
      *(_QWORD *)(v6 + 1696),
      "%s: User of RC%d requests handling drv pc options %u.\n",
      "msm_pcie_pm_control",
      *(_DWORD *)(v6 + 1348),
      a5);
    if ( !*(_QWORD *)(v6 + 3128) )
      msm_pcie_handle_drv_pc_ctrl(v6, a5);
    return 0;
  }
  else
  {
    if ( a1 != 8 )
    {
      if ( a1 == 16 )
      {
        ipc_log_string(v10, "DBG1:%s: User of RC%d cancels the request of alive link.\n", "msm_pcie_pm_control", v11);
        ipc_log_string(
          *(_QWORD *)(v6 + 1696),
          "%s: User of RC%d cancels the request of alive link.\n",
          "msm_pcie_pm_control",
          *(_DWORD *)(v6 + 1348));
        v12 = raw_spin_lock_irqsave(v6 + 1060);
        *(_QWORD *)(v6 + 1064) = v12;
        v13 = v6 + 1060;
        *(_BYTE *)(v6 + 1181) = 0;
LABEL_27:
        raw_spin_unlock_irqrestore(v13, v12);
        return 0;
      }
      goto LABEL_154;
    }
    ipc_log_string(v10, "DBG1:%s: User of RC%d requests to keep the link always alive.\n", "msm_pcie_pm_control", v11);
    ipc_log_string(
      *(_QWORD *)(v6 + 1696),
      "%s: User of RC%d requests to keep the link always alive.\n",
      "msm_pcie_pm_control",
      *(_DWORD *)(v6 + 1348));
    v17 = raw_spin_lock_irqsave(v6 + 1060);
    v18 = *(unsigned __int8 *)(v6 + 1568);
    *(_QWORD *)(v6 + 1064) = v17;
    if ( v18 == 1 )
    {
      ipc_log_string(
        *(_QWORD *)(v6 + 1704),
        "ERR:%s: PCIe: RC%d Link has been suspended before request\n",
        "msm_pcie_pm_control",
        *(_DWORD *)(v6 + 1348));
      ipc_log_string(
        *(_QWORD *)(v6 + 1696),
        "%s: PCIe: RC%d Link has been suspended before request\n",
        "msm_pcie_pm_control",
        *(_DWORD *)(v6 + 1348));
      printk(&unk_2FA69);
      v19 = *(_QWORD *)(v6 + 1064);
      v20 = -1;
    }
    else
    {
      v19 = v17;
      v20 = 0;
      *(_BYTE *)(v6 + 1181) = 1;
    }
    raw_spin_unlock_irqrestore(v6 + 1060, v19);
    return v20;
  }
}
