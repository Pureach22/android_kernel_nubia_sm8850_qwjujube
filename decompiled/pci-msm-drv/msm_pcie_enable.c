__int64 __fastcall msm_pcie_enable(const char ***a1)
{
  unsigned int v2; // w20
  const char **v3; // x1
  const char *v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w0
  int v7; // w25
  __int64 v8; // x26
  int v9; // w0
  __int64 v10; // x24
  unsigned int v11; // w0
  unsigned int v12; // w0
  int v13; // w0
  unsigned int v14; // w0
  const char **v16; // x8
  unsigned int v17; // w0
  __int64 v18; // x0
  unsigned int v19; // w21
  __int64 v20; // x0
  __int64 v21; // x21
  const char **v22; // x22
  void *v23; // x0
  int v24; // w22
  const char **v25; // x9
  const char *v26; // x21

  if ( a1 )
  {
    ipc_log_string(a1[213], "DBG1:%s: RC%d: entry\n", "msm_pcie_enable", *((_DWORD *)a1 + 337));
    ipc_log_string(a1[212], "%s: RC%d: entry\n", "msm_pcie_enable", *((_DWORD *)a1 + 337));
  }
  *((_DWORD *)a1 + 382) = 0;
  *((_BYTE *)a1 + 1216) = 0;
  mutex_lock(a1 + 140);
  if ( *((_DWORD *)a1 + 294) == 1 )
  {
    if ( a1 )
    {
      ipc_log_string(
        a1[213],
        "ERR:%s: PCIe: the link of RC%d is already enabled\n",
        "msm_pcie_enable",
        *((_DWORD *)a1 + 337));
      ipc_log_string(
        a1[212],
        "%s: PCIe: the link of RC%d is already enabled\n",
        "msm_pcie_enable",
        *((_DWORD *)a1 + 337));
    }
    printk(&unk_28006);
    v2 = 0;
    goto LABEL_59;
  }
  if ( a1 )
  {
    ipc_log_string(
      a1[213],
      "INFO:%s: PCIe: Assert the reset of endpoint of RC%d.\n",
      "msm_pcie_enable",
      *((_DWORD *)a1 + 337));
    ipc_log_string(
      a1[212],
      "%s: PCIe: Assert the reset of endpoint of RC%d.\n",
      "msm_pcie_enable",
      *((_DWORD *)a1 + 337));
  }
  printk(&unk_23B65);
  msm_pcie_config_perst((__int64)a1, 1);
  usleep_range_state(*((unsigned int *)a1 + 328), *((unsigned int *)a1 + 329), 2);
  v2 = msm_pcie_vreg_init(a1);
  if ( !v2 )
  {
    v3 = a1[5];
    if ( v3 || a1[6] )
    {
      if ( a1 )
      {
        ipc_log_string(a1[213], "DBG1:%s: RC%d: entry\n", "msm_pcie_genpd_gdsc_init", *((_DWORD *)a1 + 337));
        ipc_log_string(a1[212], "%s: RC%d: entry\n", "msm_pcie_genpd_gdsc_init", *((_DWORD *)a1 + 337));
        v3 = a1[5];
      }
      v2 = msm_pcie_genpd_gdsc_enable(a1, v3);
      if ( v2 || !(unsigned int)msm_pcie_genpd_gdsc_enable(a1, a1[6]) )
      {
        if ( !a1 )
          goto LABEL_21;
      }
      else
      {
        v2 = msm_pcie_genpd_gdsc_disable(a1, a1[5]);
        if ( !a1 )
        {
LABEL_21:
          if ( v2 )
            goto LABEL_58;
          if ( a1 )
          {
            ipc_log_string(a1[213], "DBG1:%s: RC%d: entry\n", "msm_pcie_clk_init", *((_DWORD *)a1 + 337));
            ipc_log_string(a1[212], "%s: RC%d: entry\n", "msm_pcie_clk_init", *((_DWORD *)a1 + 337));
          }
          if ( a1[127] && a1[128] )
            clk_set_parent();
          v5 = msm_pcie_icc_vote(a1, 500, 800, 0);
          if ( v5 )
          {
            __dsb(0xEu);
            v2 = v5;
            goto LABEL_57;
          }
          if ( !*((_DWORD *)a1 + 214) )
          {
LABEL_49:
            v2 = 0;
            goto LABEL_50;
          }
          v7 = 0;
          while ( 1 )
          {
            v8 = (__int64)&a1[108][3 * v7];
            if ( *(_QWORD *)v8 )
            {
              if ( *(_DWORD *)(v8 + 16) )
              {
                v9 = clk_set_rate();
                if ( v9 )
                {
                  v2 = v9;
                  if ( a1 )
                  {
                    ipc_log_string(
                      a1[213],
                      "ERR:%s: PCIe: RC%d can't set rate for clk %s: %d.\n",
                      "msm_pcie_clk_init",
                      *((_DWORD *)a1 + 337),
                      *(const char **)(v8 + 8),
                      v9);
                    ipc_log_string(
                      a1[212],
                      "%s: PCIe: RC%d can't set rate for clk %s: %d.\n",
                      "msm_pcie_clk_init",
                      *((_DWORD *)a1 + 337),
                      *(const char **)(v8 + 8),
                      v2);
                  }
                  printk(&unk_256E2);
LABEL_102:
                  if ( a1 )
                  {
                    ipc_log_string(
                      a1[213],
                      "DBG1:%s: RC%d disable clocks for error handling.\n",
                      "msm_pcie_clk_init",
                      *((_DWORD *)a1 + 337));
                    ipc_log_string(
                      a1[212],
                      "%s: RC%d disable clocks for error handling.\n",
                      "msm_pcie_clk_init",
                      *((_DWORD *)a1 + 337));
                  }
                  if ( v7 )
                  {
                    v24 = v7 - 1;
                    do
                    {
                      v25 = a1[108];
                      v26 = v25[3 * v24];
                      if ( v26 )
                      {
                        clk_disable(v25[3 * v24]);
                        clk_unprepare(v26);
                      }
                      --v24;
                    }
                    while ( v24 != -1 );
                  }
                  if ( a1[127] && a1[131] )
                    clk_set_parent();
LABEL_50:
                  if ( a1 )
                  {
                    ipc_log_string(a1[213], "DBG1:%s: RC%d: exit\n", "msm_pcie_clk_init", *((_DWORD *)a1 + 337));
                    ipc_log_string(a1[212], "%s: RC%d: exit\n", "msm_pcie_clk_init", *((_DWORD *)a1 + 337));
                  }
                  __dsb(0xEu);
                  if ( !v2 )
                  {
                    if ( !a1[391]
                      || (dword_4BC = *((_DWORD *)a1 + 248) + 1,
                          dword_4C0 = dword_4BC,
                          dword_4C8 = dword_4BC,
                          (v13 = msm_pcie_cesta_map_apply(a1, 1)) == 0) )
                    {
                      v14 = msm_pcie_core_phy_reset(a1);
                      __dsb(0xEu);
                      v2 = v14;
                      if ( v14 )
                        goto LABEL_56;
                      if ( *((_DWORD *)a1 + 336) )
                        msm_pcie_parf_cesta_config(a1);
                      v16 = a1[383];
                      if ( v16 )
                      {
                        if ( *((_DWORD *)v16 - 1) != -316352679 )
                          __break(0x8228u);
                        ((void (__fastcall *)(const char ***))v16)(a1);
                      }
                      v17 = msm_pcie_enable_link(a1);
                      if ( v17 )
                      {
                        v2 = v17;
                        if ( (((unsigned __int64)(unsigned int)msm_pcie_keep_resources_on >> *((_DWORD *)a1 + 337)) & 1) == 0 )
                        {
                          v18 = *((unsigned int *)a1 + 82);
                          if ( (_DWORD)v18 )
                          {
                            v19 = 1 - *((_DWORD *)a1 + 84);
                            v20 = gpio_to_desc(v18);
                            gpiod_set_raw_value(v20, v19);
                          }
                          v21 = *((unsigned int *)a1 + 322);
                          if ( (_DWORD)v21 )
                          {
                            v22 = a1[110];
                            writel_relaxed_0(0, (char *)v22 + v21);
                            readl_relaxed_0((unsigned int *)((char *)v22 + v21));
                          }
                          msm_pcie_disable_cesta(a1);
                          msm_pcie_pipe_clk_deinit(a1);
                          goto LABEL_56;
                        }
                      }
                      else if ( *((_BYTE *)a1 + 1357) == 1 )
                      {
                        if ( (*((_BYTE *)a1 + 1340) & 1) == 0 )
                          msm_msi_config((__int64)a1[1][102]);
                        msm_pcie_config_link_pm(a1);
                        v2 = 0;
                      }
                      else
                      {
                        v2 = 0;
                      }
                      goto LABEL_59;
                    }
                    v2 = v13;
                    if ( a1 )
                    {
                      ipc_log_string(a1[213], "ERR:%s: Fail to go to D0 State %d\n", "msm_pcie_enable_cesta", v13);
                      ipc_log_string(a1[212], "%s: Fail to go to D0 State %d\n", "msm_pcie_enable_cesta", v2);
                    }
                    printk(&unk_2C1CF);
LABEL_56:
                    msm_pcie_clk_deinit(a1);
                  }
LABEL_57:
                  msm_pcie_gdsc_deinit(a1);
LABEL_58:
                  msm_pcie_vreg_deinit(a1);
                  goto LABEL_59;
                }
                if ( a1 )
                  ipc_log_string(
                    a1[212],
                    "DBG2:%s: PCIe: RC%d set rate for clk %s.\n",
                    "msm_pcie_clk_init",
                    *((_DWORD *)a1 + 337),
                    *(const char **)(v8 + 8));
              }
              v10 = *(_QWORD *)v8;
              v11 = clk_prepare(*(_QWORD *)v8);
              if ( v11 )
              {
                v2 = v11;
LABEL_96:
                if ( a1 )
                {
                  ipc_log_string(
                    a1[213],
                    "ERR:%s: PCIe: RC%d failed to enable clk %s\n",
                    "msm_pcie_clk_init",
                    *((_DWORD *)a1 + 337),
                    *(const char **)(v8 + 8));
                  ipc_log_string(
                    a1[212],
                    "%s: PCIe: RC%d failed to enable clk %s\n",
                    "msm_pcie_clk_init",
                    *((_DWORD *)a1 + 337),
                    *(const char **)(v8 + 8));
                }
                printk(&unk_2279E);
                goto LABEL_102;
              }
              v12 = clk_enable(v10);
              if ( v12 )
              {
                v2 = v12;
                clk_unprepare(v10);
                goto LABEL_96;
              }
              if ( a1 )
                ipc_log_string(
                  a1[212],
                  "DBG2:%s: enable clk %s for RC%d.\n",
                  "msm_pcie_clk_init",
                  *(const char **)(v8 + 8),
                  *((_DWORD *)a1 + 337));
            }
            if ( (unsigned int)++v7 >= *((_DWORD *)a1 + 214) )
              goto LABEL_49;
          }
        }
      }
      v4 = "msm_pcie_genpd_gdsc_init";
      ipc_log_string(
        a1[213],
        "DBG1:%s: RC%d: exit ret %d\n",
        "msm_pcie_genpd_gdsc_init",
        *((unsigned int *)a1 + 337),
        v2);
LABEL_20:
      ipc_log_string(a1[212], "%s: RC%d: exit ret %d\n", v4, *((_DWORD *)a1 + 337), v2);
      goto LABEL_21;
    }
    if ( a1 )
    {
      ipc_log_string(a1[213], "DBG1:%s: RC%d: entry\n", "msm_pcie_reg_gdsc_init", *((_DWORD *)a1 + 337));
      ipc_log_string(a1[212], "%s: RC%d: entry\n", "msm_pcie_reg_gdsc_init", *((_DWORD *)a1 + 337));
    }
    if ( a1[3] && (v6 = regulator_enable()) != 0 )
    {
      v2 = v6;
      if ( a1 )
      {
        ipc_log_string(
          a1[213],
          "ERR:%s: PCIe: fail to enable GDSC-CORE for RC%d (%s)\n",
          "msm_pcie_reg_gdsc_init",
          *((_DWORD *)a1 + 337),
          **a1);
        ipc_log_string(
          a1[212],
          "%s: PCIe: fail to enable GDSC-CORE for RC%d (%s)\n",
          "msm_pcie_reg_gdsc_init",
          *((_DWORD *)a1 + 337),
          **a1);
      }
      v23 = &unk_26F93;
    }
    else
    {
      if ( !a1[4] )
      {
        v2 = 0;
        if ( !a1 )
          goto LABEL_21;
        goto LABEL_63;
      }
      v2 = regulator_enable();
      if ( !v2 )
        goto LABEL_35;
      if ( a1 )
      {
        ipc_log_string(
          a1[213],
          "ERR:%s: PCIe: fail to enable GDSC-PHY for RC%d (%s)\n",
          "msm_pcie_reg_gdsc_init",
          *((_DWORD *)a1 + 337),
          **a1);
        ipc_log_string(
          a1[212],
          "%s: PCIe: fail to enable GDSC-PHY for RC%d (%s)\n",
          "msm_pcie_reg_gdsc_init",
          *((_DWORD *)a1 + 337),
          **a1);
      }
      printk(&unk_28FD5);
      if ( !a1[3] || (v2 = regulator_disable()) == 0 )
      {
LABEL_35:
        if ( !a1 )
          goto LABEL_21;
        goto LABEL_63;
      }
      if ( a1 )
      {
        ipc_log_string(
          a1[213],
          "ERR:%s: PCIe: fail to disable GDSC-CORE for RC%d (%s)\n",
          "msm_pcie_reg_gdsc_init",
          *((_DWORD *)a1 + 337),
          **a1);
        ipc_log_string(
          a1[212],
          "%s: PCIe: fail to disable GDSC-CORE for RC%d (%s)\n",
          "msm_pcie_reg_gdsc_init",
          *((_DWORD *)a1 + 337),
          **a1);
      }
      v23 = &unk_2EF3F;
    }
    printk(v23);
    if ( !a1 )
      goto LABEL_21;
LABEL_63:
    v4 = "msm_pcie_reg_gdsc_init";
    ipc_log_string(a1[213], "DBG1:%s: RC%d: exit ret %d\n", "msm_pcie_reg_gdsc_init", *((unsigned int *)a1 + 337), v2);
    goto LABEL_20;
  }
LABEL_59:
  mutex_unlock(a1 + 140);
  if ( a1 )
  {
    ipc_log_string(a1[213], "DBG1:%s: RC%d: exit\n", "msm_pcie_enable", *((_DWORD *)a1 + 337));
    ipc_log_string(a1[212], "%s: RC%d: exit\n", "msm_pcie_enable", *((_DWORD *)a1 + 337));
  }
  return v2;
}
