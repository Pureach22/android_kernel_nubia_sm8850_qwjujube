__int64 __fastcall reg_check_if_6g_pwr_type_supp_for_chan(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  unsigned int v24; // w19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20
  __int64 v44; // x24
  __int64 v45; // x8
  __int64 v46; // x25
  __int64 v47; // x21
  __int64 v48; // x22
  unsigned int v49; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( pdev_obj )
  {
    v23 = pdev_obj;
    v24 = (unsigned __int16)reg_convert_enum_to_6g_idx(a3);
    if ( v24 >= 0x3C )
    {
      v33 = jiffies;
      if ( reg_check_if_6g_pwr_type_supp_for_chan___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: sup_idx: %d, chan idx: %d, Invalid channel",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "reg_check_if_6g_pwr_type_supp_for_chan",
          v24,
          a3);
        reg_check_if_6g_pwr_type_supp_for_chan___last_ticks = v33;
      }
LABEL_20:
      result = 11;
      goto LABEL_21;
    }
    v49 = 0;
    reg_get_cur_6g_client_type(a1, &v49, v25, v26, v27, v28, v29, v30, v31, v32);
    if ( v49 == 1 )
    {
      if ( a2 < 3 )
      {
        v43 = a2 + 7;
LABEL_12:
        v44 = jiffies;
        v45 = v23 + 268LL * v24;
        v46 = v45 + 37156;
        v47 = v45 + 37000;
        if ( reg_check_if_6g_pwr_type_supp_for_chan___last_ticks_15 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: 6G channel state: %d, channel flags: %d",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "reg_check_if_6g_pwr_type_supp_for_chan",
            *(unsigned int *)(v46 + 4LL * v43),
            *(unsigned int *)(v47 + 4LL * v43));
          reg_check_if_6g_pwr_type_supp_for_chan___last_ticks_15 = v44;
        }
        if ( reg_is_state_allowed(*(_DWORD *)(v46 + 4LL * v43)) && (*(_DWORD *)(v47 + 4LL * v43) & 1) == 0 )
        {
          result = 0;
          goto LABEL_21;
        }
LABEL_18:
        v48 = jiffies;
        if ( reg_check_if_6g_pwr_type_supp_for_chan___last_ticks_17 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            2u,
            "%s: 6 GHz power type = %d not supported for 6 GHz channel idx = %d",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "reg_check_if_6g_pwr_type_supp_for_chan",
            v43,
            v24);
          reg_check_if_6g_pwr_type_supp_for_chan___last_ticks_17 = v48;
        }
        goto LABEL_20;
      }
    }
    else if ( !v49 && a2 < 4 )
    {
      v43 = dword_B359F8[a2];
      goto LABEL_12;
    }
    v43 = 0;
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: pdev priv obj null",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "reg_check_if_6g_pwr_type_supp_for_chan");
  result = 16;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
