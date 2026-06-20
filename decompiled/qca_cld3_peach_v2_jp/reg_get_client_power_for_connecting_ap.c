__int64 __fastcall reg_get_client_power_for_connecting_ap(
        __int64 a1,
        unsigned int a2,
        int a3,
        char a4,
        _WORD *a5,
        _WORD *a6,
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
  __int64 v29; // x21
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w8
  __int64 v40; // x11
  __int64 v41; // x10
  _DWORD *v42; // x11
  __int64 v43; // x12
  char *v44; // x8
  __int64 v45; // x9
  __int64 v47; // x20

  pdev_obj = reg_get_pdev_obj(a1, a7, a8, a9, a10, a11, a12, a13, a14);
  if ( !pdev_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev priv obj is NULL",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "reg_get_client_power_for_connecting_ap");
    return 16;
  }
  v29 = pdev_obj;
  v30 = reg_get_pdev_obj(a1, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( !v30 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev reg component is NULL",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "reg_get_cur_6g_client_type");
    v39 = 0;
    if ( a2 < 4 )
      goto LABEL_6;
    goto LABEL_20;
  }
  v39 = *(_DWORD *)(v30 + 58208);
  if ( v39 > 1 )
    v39 = 0;
  if ( a2 >= 4 )
  {
LABEL_20:
    __break(0x5512u);
LABEL_21:
    v47 = jiffies;
    if ( reg_get_6g_chan_psd_eirp_power___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: mas_chan_list is NULL",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "reg_get_6g_chan_psd_eirp_power");
      reg_get_6g_chan_psd_eirp_power___last_ticks = v47;
    }
    return 16;
  }
LABEL_6:
  *a5 = 0;
  v40 = 2160LL * v39 + 4320LL * a2 + v29;
  v41 = v40 + 19660;
  v42 = (_DWORD *)(v40 + 19676);
  v43 = 60;
  while ( *(v42 - 4) != a3 )
  {
    --v43;
    v42 += 9;
    if ( !v43 )
    {
      if ( (a4 & 1) != 0 )
        goto LABEL_10;
      return 0;
    }
  }
  *a5 = *v42;
  if ( (a4 & 1) == 0 )
    return 0;
LABEL_10:
  if ( !v41 )
    goto LABEL_21;
  v44 = (char *)(2160LL * v39 + 4320LL * a2 + v29 + 19688);
  v45 = 60;
  while ( *((_DWORD *)v44 - 7) != a3 )
  {
    --v45;
    v44 += 36;
    if ( !v45 )
      return 16;
  }
  *a6 = *v44;
  return 0;
}
