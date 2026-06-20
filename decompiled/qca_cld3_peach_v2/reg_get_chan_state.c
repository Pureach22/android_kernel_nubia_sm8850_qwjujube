__int64 __fastcall reg_get_chan_state(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 pdev_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 result; // x0
  const char *v26; // x2
  const char *v27; // x3
  unsigned int v28; // w1
  __int64 v29; // x0
  _QWORD v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pdev_obj = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !pdev_obj )
  {
    v26 = "%s: reg pdev private obj is NULL";
    v27 = "reg_get_chan_state";
    v28 = 2;
    goto LABEL_6;
  }
  if ( a2 > 0x29 )
  {
    if ( !a3 )
    {
      if ( a2 <= 0x65 )
      {
        result = *(unsigned int *)(pdev_obj + 36LL * a2 + 8);
        goto LABEL_8;
      }
      goto LABEL_7;
    }
    if ( a2 > 0x65 )
    {
LABEL_7:
      result = 4;
      goto LABEL_8;
    }
    v29 = *(_QWORD *)(pdev_obj + 56728);
    v30[0] = 0;
    if ( (unsigned int)reg_get_superchan_entry(v29, a2, v30) )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Failed to get super channel entry for freq_idx %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "reg_get_chan_state_on_given_pwr_mode",
        a2);
      goto LABEL_7;
    }
    if ( a3 == -1 )
      a3 = *(_DWORD *)((char *)&off_0 + v30[0] + 4);
    if ( a3 - 13 > 0xFFFFFFF3 )
    {
      result = *(unsigned int *)(v30[0] + 4LL * a3 + 216);
      goto LABEL_8;
    }
    v26 = "%s: pwr_type invalid";
    v27 = "reg_get_chan_state_on_given_pwr_mode";
    v28 = 8;
LABEL_6:
    qdf_trace_msg(0x51u, v28, v26, v16, v17, v18, v19, v20, v21, v22, v23, v27);
    goto LABEL_7;
  }
  v24 = pdev_obj + 36LL * a2;
  if ( (a4 & 1) != 0 )
  {
    result = *(unsigned int *)(v24 + 8);
  }
  else
  {
    result = *(unsigned int *)(v24 + 8);
    if ( ((*(_BYTE *)(v24 + 25) & 1) != 0 || *(_BYTE *)(v24 + 26) == 1) && !(_DWORD)result )
      result = 2;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
