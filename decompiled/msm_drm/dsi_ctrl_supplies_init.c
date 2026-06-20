unsigned __int64 __fastcall dsi_ctrl_supplies_init(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  int dt_vreg_data; // w0
  _QWORD *v6; // x22
  __int64 v7; // x0
  unsigned __int64 v8; // x23
  int v10; // w8
  int v11; // w24
  unsigned __int64 v12; // x0
  int v13; // w8
  int v14; // w24
  unsigned __int64 v15; // x0
  __int64 v16; // x25
  int v17; // w24
  bool v18; // cf
  unsigned int v19; // w22

  v2 = (_QWORD *)(a2 + 2400);
  dt_vreg_data = dsi_pwr_get_dt_vreg_data(a1 + 16, a2 + 2400, "qcom,core-supply-entries");
  if ( dt_vreg_data )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: %s: failed to get digital supply, rc = %d\n",
      *(const char **)(a2 + 16),
      dt_vreg_data);
  v6 = (_QWORD *)(a2 + 2416);
  v7 = dsi_pwr_get_dt_vreg_data(a1 + 16, a2 + 2416, "qcom,ctrl-supply-entries");
  if ( (_DWORD)v7 )
  {
    v8 = v7;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get host power supplies, rc = %d\n",
      *(const char **)(a2 + 16),
      v7);
    if ( !*v2 )
    {
LABEL_6:
      *(_QWORD *)(a2 + 2400) = 0;
      *(_DWORD *)(a2 + 2408) = 0;
      return v8;
    }
LABEL_5:
    devm_kfree(a1 + 16);
    goto LABEL_6;
  }
  if ( *(_DWORD *)(a2 + 2408) )
  {
    v10 = 0;
    while ( 1 )
    {
      v11 = v10;
      v12 = devm_regulator_get(a1 + 16, *v2 + 80LL * v10 + 8);
      if ( v12 >= 0xFFFFFFFFFFFFF001LL )
        break;
      *(_QWORD *)(*(_QWORD *)(a2 + 2400) + 80LL * v11) = v12;
      v10 = v11 + 1;
      if ( (unsigned int)(v11 + 1) >= *(_DWORD *)(a2 + 2408) )
        goto LABEL_11;
    }
    v8 = v12;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get %s regulator\n",
      *(const char **)(a2 + 16),
      (const char *)(*(_QWORD *)(a2 + 2400) + 80LL * v11 + 8));
LABEL_24:
    devm_kfree(a1 + 16);
    *(_QWORD *)(a2 + 2416) = 0;
    *(_DWORD *)(a2 + 2424) = 0;
    if ( !*v2 )
      goto LABEL_6;
    goto LABEL_5;
  }
LABEL_11:
  if ( *(_DWORD *)(a2 + 2424) )
  {
    v13 = 0;
    while ( 1 )
    {
      v14 = v13;
      v15 = devm_regulator_get(a1 + 16, *v6 + 80LL * v13 + 8);
      if ( v15 >= 0xFFFFFFFFFFFFF001LL )
        break;
      *(_QWORD *)(*(_QWORD *)(a2 + 2416) + 80LL * v14) = v15;
      v13 = v14 + 1;
      if ( (unsigned int)(v14 + 1) >= *(_DWORD *)(a2 + 2424) )
        return 0;
    }
    v8 = v15;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to get %s regulator\n",
      *(const char **)(a2 + 16),
      (const char *)(*(_QWORD *)(a2 + 2416) + 80LL * v14 + 8));
    if ( ((v14 - 1) & 0x80000000) == 0 )
    {
      v16 = 80LL * (unsigned int)(v14 - 1);
      v17 = -v14;
      do
      {
        devm_regulator_put(*(_QWORD *)(*v6 + v16));
        v18 = __CFADD__(v17++, 1);
        v16 -= 80;
      }
      while ( !v18 );
    }
    if ( *(_DWORD *)(a2 + 2408) )
    {
      v19 = 0;
      do
        devm_regulator_put(*(_QWORD *)(*(_QWORD *)(a2 + 2400) + 80LL * (int)v19++));
      while ( v19 < *(_DWORD *)(a2 + 2408) );
    }
    goto LABEL_24;
  }
  return 0;
}
