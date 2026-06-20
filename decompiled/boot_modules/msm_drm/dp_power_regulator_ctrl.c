__int64 __fastcall dp_power_regulator_ctrl(_QWORD *a1, char a2)
{
  __int64 v2; // x24
  unsigned int v5; // w22
  __int64 v6; // x0
  __int64 v7; // x23
  const char *v8; // x19
  __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x8
  int v12; // w20
  __int64 v13; // x0
  void *v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w22
  int v17; // w25
  __int64 v18; // x24
  __int64 v19; // x0
  __int64 v21; // x0
  unsigned __int64 StatusReg; // x20
  int v23; // w20
  __int64 ipc_log_context; // x0

  v2 = *a1;
  v5 = a2 & 1;
  v6 = *(_QWORD *)(*a1 + 24LL);
  v7 = v2 + 16;
  if ( (a2 & 1) != 0 )
    v8 = "enable";
  else
    v8 = "disable";
  v9 = msm_dss_enable_vreg(v6, *(unsigned int *)(v2 + 16), a2 & 1);
  if ( (_DWORD)v9 )
  {
    v16 = v9;
    v17 = 0;
    v18 = 0;
  }
  else
  {
    v9 = msm_dss_enable_vreg(*(_QWORD *)(v2 + 72), *(unsigned int *)(v2 + 64), v5);
    if ( (_DWORD)v9 )
    {
      v16 = v9;
      v17 = 0;
      v18 = 1;
    }
    else
    {
      v9 = msm_dss_enable_vreg(*(_QWORD *)(v2 + 120), *(unsigned int *)(v2 + 112), v5);
      if ( (_DWORD)v9 )
      {
        v16 = v9;
        v17 = 1;
        v18 = 2;
      }
      else
      {
        v9 = msm_dss_enable_vreg(*(_QWORD *)(v2 + 168), *(unsigned int *)(v2 + 160), v5);
        if ( (_DWORD)v9 )
        {
          v16 = v9;
          v17 = 1;
          v18 = 3;
        }
        else
        {
          v9 = msm_dss_enable_vreg(*(_QWORD *)(v2 + 216), *(unsigned int *)(v2 + 208), v5);
          if ( (_DWORD)v9 )
          {
            v16 = v9;
            v17 = 1;
            v18 = 4;
          }
          else
          {
            v9 = msm_dss_enable_vreg(*(_QWORD *)(v2 + 264), *(unsigned int *)(v2 + 256), v5);
            if ( !(_DWORD)v9 )
            {
              v10 = a1[11];
              if ( !v10 || v10 > 0xFFFFFFFFFFFFF000LL )
              {
                v11 = a1[12];
                if ( !v11 || v11 > 0xFFFFFFFFFFFFF000LL )
                  goto LABEL_39;
                if ( !v10 )
                {
                  v15 = a1[12];
                  if ( (a2 & 1) != 0 )
                    v10 = _pm_runtime_resume(v15, 4);
                  else
                    v10 = _pm_runtime_idle(v15, 4);
                  if ( (v10 & 0x80000000) == 0 )
                    goto LABEL_39;
                  v23 = v10;
                  ipc_log_context = get_ipc_log_context(v10);
                  ipc_log_string(
                    ipc_log_context,
                    "[e][%-4d]Fail to %s pd_dp_phy_gdsc regulator ret = %d\n",
                    *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                    v8,
                    v23);
                  v14 = &unk_27C24D;
                  goto LABEL_20;
                }
              }
              if ( (a2 & 1) != 0 )
              {
                v10 = regulator_enable();
                if ( (_DWORD)v10 )
                  goto LABEL_19;
              }
              else
              {
                v10 = regulator_disable();
                if ( (_DWORD)v10 )
                {
LABEL_19:
                  v12 = v10;
                  v13 = get_ipc_log_context(v10);
                  ipc_log_string(
                    v13,
                    "[e][%-4d]Fail to %s dp_phy_gdsc regulator ret = %d\n",
                    *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
                    v8,
                    v12);
                  v14 = &unk_24E9D0;
LABEL_20:
                  v10 = printk(v14, "dp_power_phy_gdsc");
                }
              }
LABEL_39:
              v21 = get_ipc_log_context(v10);
              StatusReg = _ReadStatusReg(SP_EL0);
              ipc_log_string(
                v21,
                "[d][%-4d]skipping: '%s' vregs for %s\n",
                *(_DWORD *)(StatusReg + 1800),
                v8,
                "DP_PLL_PM");
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dp-debug][%-4d]skipping: '%s' vregs for %s\n",
                  *(_DWORD *)(StatusReg + 1800),
                  v8,
                  "DP_PLL_PM");
              return 0;
            }
            v16 = v9;
            v17 = 1;
            v18 = 5;
          }
        }
      }
    }
  }
  v19 = get_ipc_log_context(v9);
  ipc_log_string(
    v19,
    "[e][%-4d]failed to '%s' vregs for %s\n",
    *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
    v8,
    off_2806C8[v18]);
  printk(&unk_2480B0, "dp_power_regulator_ctrl");
  if ( (_DWORD)v18 )
  {
    if ( (a2 & 1) != 0 )
    {
      msm_dss_enable_vreg(
        *(_QWORD *)(v7 + 48LL * (unsigned int)(v18 - 1) + 8),
        *(unsigned int *)(v7 + 48LL * (unsigned int)(v18 - 1)),
        0);
      if ( v17 )
      {
        msm_dss_enable_vreg(
          *(_QWORD *)(v7 + 48LL * (unsigned int)(v18 - 2) + 8),
          *(unsigned int *)(v7 + 48LL * (unsigned int)(v18 - 2)),
          0);
        if ( (unsigned __int64)(v18 - 1) >= 2 )
        {
          msm_dss_enable_vreg(
            *(_QWORD *)(v7 + 48LL * (unsigned int)(v18 - 3) + 8),
            *(unsigned int *)(v7 + 48LL * (unsigned int)(v18 - 3)),
            0);
          if ( (unsigned __int64)(v18 - 2) >= 2 )
          {
            msm_dss_enable_vreg(
              *(_QWORD *)(v7 + 48LL * (unsigned int)(v18 - 4) + 8),
              *(unsigned int *)(v7 + 48LL * (unsigned int)(v18 - 4)),
              0);
            if ( (unsigned __int64)(v18 - 3) >= 2 )
              msm_dss_enable_vreg(
                *(_QWORD *)(v7 + 48LL * (unsigned int)(v18 - 5) + 8),
                *(unsigned int *)(v7 + 48LL * (unsigned int)(v18 - 5)),
                0);
          }
        }
      }
    }
  }
  return v16;
}
