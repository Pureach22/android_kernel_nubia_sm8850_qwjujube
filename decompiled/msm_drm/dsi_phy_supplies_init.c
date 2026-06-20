__int64 __fastcall dsi_phy_supplies_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  int dt_vreg_data; // w0
  unsigned int v7; // w22
  int v8; // w8
  int v9; // w24
  unsigned __int64 v10; // x0
  int v12; // w8
  int v13; // w23
  unsigned __int64 v14; // x0
  __int64 v16; // x24
  int v17; // w23
  bool v18; // cf
  unsigned int v19; // w21

  v4 = devm_kmalloc(a1 + 16, 80, 3520);
  *(_QWORD *)(a2 + 784) = v4;
  if ( v4 )
  {
    v5 = (_QWORD *)(a2 + 800);
    strcpy((char *)(v4 + 8), "gdsc");
    *(_DWORD *)(a2 + 792) = 1;
    dt_vreg_data = dsi_pwr_get_dt_vreg_data(a1 + 16, a2 + 800, "qcom,phy-supply-entries");
    if ( dt_vreg_data )
    {
      v7 = dt_vreg_data;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_%d: failed to get host power supplies, rc = %d\n",
        *(_DWORD *)(a2 + 8),
        dt_vreg_data);
LABEL_29:
      devm_kfree(a1 + 16);
      *(_QWORD *)(a2 + 784) = 0;
      *(_DWORD *)(a2 + 792) = 0;
      return v7;
    }
    if ( *(_DWORD *)(a2 + 792) )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = v8;
        v10 = devm_regulator_get(a1 + 16, *(_QWORD *)(a2 + 784) + 80LL * v8 + 8);
        v7 = v10;
        if ( v10 >= 0xFFFFFFFFFFFFF001LL && (_DWORD)v10 != 0 )
          break;
        *(_QWORD *)(*(_QWORD *)(a2 + 784) + 80LL * v9) = v10;
        v8 = v9 + 1;
        if ( (unsigned int)(v9 + 1) >= *(_DWORD *)(a2 + 792) )
          goto LABEL_12;
      }
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_%d: failed to get %s regulator\n",
        *(_DWORD *)(a2 + 8),
        (const char *)(*(_QWORD *)(a2 + 784) + 80LL * v9 + 8));
      goto LABEL_28;
    }
LABEL_12:
    if ( *(_DWORD *)(a2 + 808) )
    {
      v12 = 0;
      while ( 1 )
      {
        v13 = v12;
        v14 = devm_regulator_get(a1 + 16, *v5 + 80LL * v12 + 8);
        if ( v14 >= 0xFFFFFFFFFFFFF001LL && (_DWORD)v14 != 0 )
          break;
        *(_QWORD *)(*(_QWORD *)(a2 + 800) + 80LL * v13) = v14;
        v12 = v13 + 1;
        if ( (unsigned int)(v13 + 1) >= *(_DWORD *)(a2 + 808) )
          return 0;
      }
      v7 = v14;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_%d: failed to get %s regulator\n",
        *(_DWORD *)(a2 + 8),
        (const char *)(*(_QWORD *)(a2 + 800) + 80LL * v13 + 8));
      if ( ((v13 - 1) & 0x80000000) == 0 )
      {
        v16 = 80LL * (unsigned int)(v13 - 1);
        v17 = -v13;
        do
        {
          devm_regulator_put(*(_QWORD *)(*v5 + v16));
          v18 = __CFADD__(v17++, 1);
          v16 -= 80;
        }
        while ( !v18 );
      }
      if ( *(_DWORD *)(a2 + 792) )
      {
        v19 = 0;
        do
          devm_regulator_put(*(_QWORD *)(*(_QWORD *)(a2 + 784) + 80LL * (int)v19++));
        while ( v19 < *(_DWORD *)(a2 + 792) );
      }
LABEL_28:
      devm_kfree(a1 + 16);
      *(_QWORD *)(a2 + 800) = 0;
      *(_DWORD *)(a2 + 808) = 0;
      goto LABEL_29;
    }
  }
  return 0;
}
