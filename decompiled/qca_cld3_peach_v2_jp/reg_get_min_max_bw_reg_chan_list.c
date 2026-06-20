__int64 __fastcall reg_get_min_max_bw_reg_chan_list(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _WORD *a4,
        _WORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 pdev_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 result; // x0
  __int16 v30; // w8
  const char *v31; // x2
  const char *v32; // x3
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // w1
  _QWORD v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pdev_obj = reg_get_pdev_obj(a1, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !pdev_obj )
  {
    v31 = "%s: reg pdev private obj is NULL";
    v32 = "reg_get_min_max_bw_reg_chan_list";
LABEL_21:
    v35 = 2;
LABEL_22:
    qdf_trace_msg(0x51u, v35, v31, v19, v20, v21, v22, v23, v24, v25, v26, v32);
    goto LABEL_23;
  }
  if ( a2 <= 0x29 )
  {
    v27 = reg_get_pdev_obj(a1, v19, v20, v21, v22, v23, v24, v25, v26);
    if ( v27 )
    {
      v28 = v27;
      if ( a4 )
        *a4 = *(_WORD *)(v27 + 36LL * a2 + 20);
      if ( a5 )
        goto LABEL_7;
      goto LABEL_25;
    }
    goto LABEL_20;
  }
  if ( !a3 )
  {
    v34 = reg_get_pdev_obj(a1, v19, v20, v21, v22, v23, v24, v25, v26);
    if ( !v34 )
    {
LABEL_20:
      v31 = "%s: reg pdev private obj is NULL";
      v32 = "reg_get_min_max_bw_on_cur_chan_list";
      goto LABEL_21;
    }
    if ( a2 <= 0x65 )
    {
      if ( a4 )
        *a4 = *(_WORD *)(v34 + 36LL * a2 + 20);
      if ( a5 )
      {
        v28 = v34;
LABEL_7:
        result = 0;
        v30 = *(_WORD *)(v28 + 36LL * a2 + 22);
LABEL_8:
        *a5 = v30;
        goto LABEL_24;
      }
LABEL_25:
      result = 0;
      goto LABEL_24;
    }
LABEL_23:
    result = 16;
    goto LABEL_24;
  }
  if ( a2 > 0x65 )
    goto LABEL_23;
  v33 = *(_QWORD *)(pdev_obj + 56728);
  v36[0] = 0;
  if ( (unsigned int)reg_get_superchan_entry(v33, a2, v36) )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: Failed to get super channel entry for freq_idx %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "reg_get_min_max_bw_on_given_pwr_mode",
      a2);
    goto LABEL_23;
  }
  if ( a3 == -1 )
    a3 = *(_DWORD *)((char *)&off_0 + v36[0] + 4);
  if ( a3 - 13 <= 0xFFFFFFF3 )
  {
    v31 = "%s: pwr_type invalid";
    v32 = "reg_get_min_max_bw_on_given_pwr_mode";
    v35 = 8;
    goto LABEL_22;
  }
  if ( a4 )
    *a4 = *(_WORD *)(v36[0] + 2LL * a3 + 8);
  result = 0;
  if ( a5 )
  {
    v30 = *(_WORD *)(v36[0] + 2LL * a3 + 34);
    goto LABEL_8;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
