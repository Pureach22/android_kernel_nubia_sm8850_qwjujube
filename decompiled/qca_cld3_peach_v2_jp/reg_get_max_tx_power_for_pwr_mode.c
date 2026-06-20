__int64 __fastcall reg_get_max_tx_power_for_pwr_mode(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 result; // x0
  _DWORD *v23; // x11
  int v24; // w10
  __int64 v25; // x8
  __int64 v26; // x11
  __int64 v27; // x13
  _DWORD *v28; // x14
  __int64 v29; // x20
  __int64 v30; // x20
  __int64 v31; // x20

  if ( !a1 )
  {
    v29 = jiffies;
    if ( reg_get_max_tx_power_for_pwr_mode___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: invalid pdev", a3, a4, a5, a6, a7, a8, a9, a10, "reg_get_max_tx_power_for_pwr_mode");
      reg_get_max_tx_power_for_pwr_mode___last_ticks = v29;
      return 4;
    }
    return 4;
  }
  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v31 = jiffies;
    if ( reg_get_max_tx_power_for_pwr_mode___last_ticks_66 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "reg_get_max_tx_power_for_pwr_mode");
      reg_get_max_tx_power_for_pwr_mode___last_ticks_66 = v31;
      return 4;
    }
    return 4;
  }
  v20 = pdev_obj;
  v21 = 41;
  result = 0;
  if ( !a2 )
    v21 = 102;
  v23 = (_DWORD *)(v20 + 16);
  do
  {
    if ( (*(_BYTE *)(v23 - 1) & 1) == 0 && *(v23 - 2) )
    {
      if ( *v23 <= (int)(unsigned __int8)result )
        result = (unsigned int)result;
      else
        result = (unsigned int)*v23;
    }
    --v21;
    v23 += 9;
  }
  while ( v21 );
  if ( a2 )
  {
    LOBYTE(v24) = 0;
    v25 = v20 + 37156;
    v26 = 60;
    v27 = a2;
    do
    {
      if ( a2 == 0xFFFFFFFFLL )
        v27 = *(unsigned int *)(v25 - 212);
      if ( (unsigned __int64)(v27 - 13) >= 0xFFFFFFFFFFFFFFF4LL )
      {
        v28 = (_DWORD *)(v25 + 4 * v27);
        if ( (*(_BYTE *)(v28 - 39) & 1) == 0
          && *v28
          && *(_DWORD *)(v25 + 8 * v27 - 100) > (unsigned int)(unsigned __int8)v24 )
        {
          v24 = *(_DWORD *)(v25 + 8 * v27 - 100);
        }
      }
      --v26;
      v25 += 268;
    }
    while ( v26 );
    if ( (unsigned __int8)v24 <= (unsigned int)(unsigned __int8)result )
      result = (unsigned __int8)result;
    else
      result = (unsigned __int8)v24;
  }
  if ( !(_BYTE)result )
  {
    v30 = jiffies;
    if ( reg_get_max_tx_power_for_pwr_mode___last_ticks_67 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: max_tx_power is zero",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "reg_get_max_tx_power_for_pwr_mode");
      reg_get_max_tx_power_for_pwr_mode___last_ticks_67 = v30;
    }
    return 0;
  }
  return result;
}
