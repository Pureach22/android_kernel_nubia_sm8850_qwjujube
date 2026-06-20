__int64 __fastcall dp_power_client_init(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v5; // x19
  __int64 v6; // x25
  __int64 v7; // x23
  __int64 v9; // x24
  __int64 vreg; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned int v19; // w20
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x21
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0

  if ( !a3 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid drm_dev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26EF51, "dp_power_client_init");
    return 4294967274LL;
  }
  v5 = a1 - 9;
  v6 = *(a1 - 9);
  v7 = *(a1 - 7);
  v9 = v6 + 16;
  vreg = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 24), *(unsigned int *)(v6 + 16), 1);
  if ( (_DWORD)vreg )
  {
    v19 = vreg;
    v20 = get_ipc_log_context(vreg);
    ipc_log_string(
      v20,
      "[e][%-4d]failed to init vregs for %s\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      "DP_CORE_PM");
    v21 = printk(&unk_248192, "dp_power_regulator_init");
  }
  else
  {
    v11 = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 72), *(unsigned int *)(v6 + 64), 1);
    if ( (_DWORD)v11 )
    {
      v19 = v11;
      v22 = get_ipc_log_context(v11);
      ipc_log_string(
        v22,
        "[e][%-4d]failed to init vregs for %s\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        "DP_CTRL_PM");
      v23 = 1;
    }
    else
    {
      v12 = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 120), *(unsigned int *)(v6 + 112), 1);
      if ( (_DWORD)v12 )
      {
        v19 = v12;
        v24 = get_ipc_log_context(v12);
        ipc_log_string(
          v24,
          "[e][%-4d]failed to init vregs for %s\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          "DP_PHY_PM");
        v23 = 2;
      }
      else
      {
        v13 = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 168), *(unsigned int *)(v6 + 160), 1);
        if ( (_DWORD)v13 )
        {
          v19 = v13;
          v25 = get_ipc_log_context(v13);
          ipc_log_string(
            v25,
            "[e][%-4d]failed to init vregs for %s\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            "DP_STREAM0_PM");
          v23 = 3;
        }
        else
        {
          v14 = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 216), *(unsigned int *)(v6 + 208), 1);
          if ( (_DWORD)v14 )
          {
            v19 = v14;
            v26 = get_ipc_log_context(v14);
            ipc_log_string(
              v26,
              "[e][%-4d]failed to init vregs for %s\n",
              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
              "DP_STREAM1_PM");
            v23 = 4;
          }
          else
          {
            v15 = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 264), *(unsigned int *)(v6 + 256), 1);
            if ( (_DWORD)v15 )
            {
              v19 = v15;
              v27 = get_ipc_log_context(v15);
              ipc_log_string(
                v27,
                "[e][%-4d]failed to init vregs for %s\n",
                *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                "DP_LINK_PM");
              v23 = 5;
            }
            else
            {
              v16 = msm_dss_get_vreg(v7 + 16, *(_QWORD *)(v6 + 312), *(unsigned int *)(v6 + 304), 1);
              if ( !(_DWORD)v16 )
              {
                result = dp_power_clk_init(v5, 1);
                if ( !(_DWORD)result )
                {
                  *a1 = a3;
                  a1[1] = a2;
                  return result;
                }
                v19 = result;
                v30 = get_ipc_log_context(result);
                ipc_log_string(v30, "[e][%-4d]failed to init clocks\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
                printk(&unk_2646B0, "dp_power_client_init");
                dp_power_regulator_deinit(v5);
                return v19;
              }
              v19 = v16;
              v28 = get_ipc_log_context(v16);
              ipc_log_string(
                v28,
                "[e][%-4d]failed to init vregs for %s\n",
                *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                "DP_PLL_PM");
              v23 = 6;
            }
          }
        }
      }
    }
    printk(&unk_248192, "dp_power_regulator_init");
    v21 = msm_dss_get_vreg(
            v7 + 16,
            *(_QWORD *)(v9 + 48LL * ((int)v23 - 1) + 8),
            *(unsigned int *)(v9 + 48LL * ((int)v23 - 1)),
            0);
    if ( v23 != 1 )
    {
      v21 = msm_dss_get_vreg(
              v7 + 16,
              *(_QWORD *)(v9 + 48LL * ((int)v23 - 2) + 8),
              *(unsigned int *)(v9 + 48LL * ((int)v23 - 2)),
              0);
      if ( v23 != 2 )
      {
        v21 = msm_dss_get_vreg(
                v7 + 16,
                *(_QWORD *)(v9 + 48LL * ((int)v23 - 3) + 8),
                *(unsigned int *)(v9 + 48LL * ((int)v23 - 3)),
                0);
        if ( v23 != 3 )
        {
          v21 = msm_dss_get_vreg(
                  v7 + 16,
                  *(_QWORD *)(v9 + 48LL * ((int)v23 - 4) + 8),
                  *(unsigned int *)(v9 + 48LL * ((int)v23 - 4)),
                  0);
          if ( v23 != 4 )
          {
            v21 = msm_dss_get_vreg(
                    v7 + 16,
                    *(_QWORD *)(v9 + 48LL * ((int)v23 - 5) + 8),
                    *(unsigned int *)(v9 + 48LL * ((int)v23 - 5)),
                    0);
            if ( v23 != 5 )
              v21 = msm_dss_get_vreg(
                      v7 + 16,
                      *(_QWORD *)(v9 + 48LL * (unsigned int)v23 - 280),
                      *(unsigned int *)(v9 + 48LL * (unsigned int)v23 - 288),
                      0);
          }
        }
      }
    }
  }
  v29 = get_ipc_log_context(v21);
  ipc_log_string(v29, "[e][%-4d]failed to init regulators\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_222FE5, "dp_power_client_init");
  return v19;
}
