__int64 __fastcall reg_get_6g_chan_ap_power(
        __int64 a1,
        int a2,
        _BYTE *a3,
        _WORD *a4,
        _WORD *a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 pdev_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  unsigned int v30; // w9
  const char *v31; // x2
  const char *v32; // x3
  __int64 v33; // x0
  __int64 result; // x0
  unsigned int v35; // w25
  __int64 v36; // x8
  __int64 v37; // x26
  __int64 v38; // x9
  __int64 v39; // x0
  __int64 v40; // x8
  const char *v41; // x2
  int v42; // w8
  char *v43; // x8
  __int64 v44; // x9
  __int64 v45; // x20

  pdev_obj = reg_get_pdev_obj(a1, a7, a8, a9, a10, a11, a12, a13, a14);
  if ( !pdev_obj )
  {
    v31 = "%s: pdev priv obj is NULL";
    v32 = "reg_get_6g_chan_ap_power";
    goto LABEL_20;
  }
  v29 = pdev_obj;
  if ( (a6 & 1) == 0 )
  {
    v33 = reg_get_pdev_obj(a1, v21, v22, v23, v24, v25, v26, v27, v28);
    if ( v33 )
    {
      v30 = *(_DWORD *)(v33 + 58204);
      if ( v30 > 3 )
        return 16;
      goto LABEL_8;
    }
    v31 = "%s: pdev reg component is NULL";
    v32 = "reg_get_cur_6g_ap_pwr_type";
LABEL_20:
    qdf_trace_msg(0x51u, 2u, v31, v21, v22, v23, v24, v25, v26, v27, v28, v32);
    return 16;
  }
  v30 = 2;
LABEL_8:
  v35 = v30;
  *a4 = 0;
  v36 = v29 + 2160LL * v30;
  v37 = v36 + 11020;
  v38 = -2160;
  while ( *(_DWORD *)(v36 + v38 + 13180) != a2 )
  {
    v38 += 36;
    if ( !v38 )
    {
      if ( a1 )
        goto LABEL_12;
LABEL_18:
      v41 = "%s: pdev is NULL";
LABEL_22:
      qdf_trace_msg(0x51u, 2u, v41, v21, v22, v23, v24, v25, v26, v27, v28, "reg_is_6g_psd_power");
LABEL_23:
      *a3 = 0;
      return 0;
    }
  }
  *a4 = *(_DWORD *)(v29 + 2160LL * v35 + v38 + 13196);
  if ( !a1 )
    goto LABEL_18;
LABEL_12:
  v39 = reg_get_pdev_obj(a1, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( !v39 )
  {
    v41 = "%s: pdev priv obj is NULL";
    goto LABEL_22;
  }
  v40 = 0;
  while ( (*(_BYTE *)(v39 + v40 + 1524) & 1) != 0 )
  {
    v40 += 36;
    if ( v40 == 2160 )
      goto LABEL_23;
  }
  v42 = *(unsigned __int8 *)(v39 + v40 + 1539);
  *a3 = v42;
  if ( v42 != 1 )
    return 0;
  if ( v37 )
  {
    result = 16;
    v43 = (char *)(v29 + 2160LL * v35 + 11048);
    v44 = 60;
    while ( *((_DWORD *)v43 - 7) != a2 )
    {
      --v44;
      v43 += 36;
      if ( !v44 )
        return result;
    }
    *a5 = *v43;
    return 0;
  }
  else
  {
    v45 = jiffies;
    if ( reg_get_6g_chan_psd_eirp_power___last_ticks - jiffies + 125 >= 0 )
      return 16;
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: mas_chan_list is NULL",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "reg_get_6g_chan_psd_eirp_power");
    reg_get_6g_chan_psd_eirp_power___last_ticks = v45;
    return 16;
  }
}
