__int64 __fastcall dsi_pwr_enable_vregs(__int64 *a1, char a2)
{
  int v2; // w8
  unsigned int i; // w21
  unsigned int v5; // w9
  _QWORD *v6; // x25
  int v7; // w8
  int v8; // w26
  unsigned int v9; // w0
  signed int v10; // w23
  int v11; // w20
  int v12; // w0
  int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x20
  __int64 v16; // x21
  bool v17; // cc
  __int64 v18; // x8
  __int64 v19; // x23
  int v20; // w9
  int v21; // w24
  unsigned int v23; // w22
  __int64 v24; // x20
  __int64 v25; // x21
  __int64 v26; // x8
  __int64 v27; // x10
  int v28; // w9
  int v29; // w24

  v2 = *((_DWORD *)a1 + 2);
  if ( (a2 & 1) == 0 )
  {
    v14 = (unsigned int)(v2 - 1);
    if ( (int)v14 >= 0 )
    {
      v15 = v14 + 1;
      v16 = 80LL * (unsigned int)v14 + 44;
      do
      {
        v18 = *a1;
        v19 = *a1 + v16;
        v20 = *(_DWORD *)(v19 + 28);
        v21 = *(_DWORD *)(v19 + 32);
        if ( v20 )
        {
          usleep_range_state((unsigned int)(1000 * v20), (unsigned int)(1000 * v20 + 10), 2);
          v18 = *a1;
        }
        regulator_disable(*(_QWORD *)(v18 + v16 - 44));
        if ( v21 )
          usleep_range_state((unsigned int)(1000 * v21), (unsigned int)(1000 * v21 + 10), 2);
        regulator_set_load(*(_QWORD *)(*a1 + v16 - 44), *(unsigned int *)(*a1 + v16 + 8));
        if ( (int)regulator_count_voltages(*(_QWORD *)(v19 - 44)) >= 1 )
          regulator_set_voltage(
            *(_QWORD *)(*a1 + v16 - 44),
            *(unsigned int *)(*a1 + v16 + 16),
            *(unsigned int *)(*a1 + v16));
        v17 = v15-- <= 1;
        v16 -= 80;
      }
      while ( !v17 );
    }
    return 0;
  }
  if ( !v2 )
    return 0;
  for ( i = -1; ; ++i )
  {
    v6 = (_QWORD *)(*a1 + 80LL * (int)(i + 1));
    v7 = *((_DWORD *)v6 + 16);
    v8 = *((_DWORD *)v6 + 17);
    if ( v7 )
      usleep_range_state((unsigned int)(1000 * v7), (unsigned int)(1000 * v7 + 10), 2);
    v9 = regulator_set_load(*v6, *((unsigned int *)v6 + 12));
    if ( (v9 & 0x80000000) != 0 )
    {
      v23 = v9;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: Setting optimum mode failed for %s\n",
        (const char *)v6 + 8);
      goto LABEL_28;
    }
    v10 = i + 1;
    v11 = regulator_count_voltages(*v6);
    if ( v11 >= 1 )
    {
      v12 = regulator_set_voltage(*v6, *((unsigned int *)v6 + 10), *((unsigned int *)v6 + 11));
      if ( v12 )
      {
        v23 = v12;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: Set voltage(%s) fail, rc=%d\n",
          (const char *)v6 + 8,
          v12);
        regulator_set_load(*(_QWORD *)(*a1 + 80LL * v10), *(unsigned int *)(*a1 + 80LL * v10 + 52));
        goto LABEL_27;
      }
    }
    v13 = regulator_enable(*v6);
    if ( v13 )
      break;
    if ( *((_DWORD *)v6 + 17) )
      usleep_range_state((unsigned int)(1000 * v8), (unsigned int)(1000 * v8 + 10), 2);
    v5 = i + 2;
    if ( v5 >= *((_DWORD *)a1 + 2) )
      return 0;
  }
  v23 = v13;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: enable failed for %s, rc=%d\n", (const char *)v6 + 8, v13);
  if ( v11 < 1 )
    goto LABEL_28;
LABEL_27:
  regulator_set_voltage(*(_QWORD *)(*a1 + 80LL * v10), 0, *(unsigned int *)(*a1 + 80LL * v10 + 44));
LABEL_28:
  if ( (i & 0x80000000) == 0 )
  {
    v24 = i + 1LL;
    v25 = 80LL * i + 44;
    do
    {
      v26 = *a1;
      v27 = *a1 + v25;
      v28 = *(_DWORD *)(v27 + 28);
      v29 = *(_DWORD *)(v27 + 32);
      if ( v28 )
      {
        usleep_range_state((unsigned int)(1000 * v28), (unsigned int)(1000 * v28 + 10), 2);
        v26 = *a1;
      }
      regulator_disable(*(_QWORD *)(v26 + v25 - 44));
      if ( v29 )
        usleep_range_state((unsigned int)(1000 * v29), (unsigned int)(1000 * v29 + 10), 2);
      regulator_set_load(*(_QWORD *)(*a1 + v25 - 44), *(unsigned int *)(*a1 + v25 + 8));
      if ( (int)regulator_count_voltages(*(_QWORD *)(*a1 + v25 - 44)) >= 1 )
        regulator_set_voltage(*(_QWORD *)(*a1 + v25 - 44), 0, *(unsigned int *)(*a1 + v25));
      v17 = v24-- <= 1;
      v25 -= 80;
    }
    while ( !v17 );
  }
  return v23;
}
