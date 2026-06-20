__int64 __fastcall reg_get_best_6g_power_type(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int chan_enum_for_freq; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  unsigned int v27; // w23
  unsigned int v28; // w24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x21
  __int64 v46; // x21
  const char *v47; // x8
  const char *v48; // x5
  unsigned int v49; // w23
  __int64 v50; // x20
  __int64 v51; // x21
  __int64 v52; // x21
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x21
  __int64 v70; // x21
  __int64 v71; // x22
  __int64 v72; // x22
  _BYTE v73[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v74; // [xsp+8h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  chan_enum_for_freq = reg_get_chan_enum_for_freq(a5, a6, a7, a8, a9, a10, a11, a12, a13);
  v73[0] = 0;
  if ( (unsigned int)wlan_mlme_get_rf_mode_force_pwr_type(a1, v73) )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Get rf test mode power type failed",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "reg_get_best_6g_power_type");
LABEL_3:
    result = 11;
    goto LABEL_4;
  }
  v27 = v73[0];
  if ( v73[0] > 2u )
  {
    *a3 = a4;
    if ( a4 < 4 )
    {
      if ( !(unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                            a2,
                            a4,
                            chan_enum_for_freq,
                            v18,
                            v19,
                            v20,
                            v21,
                            v22,
                            v23,
                            v24,
                            v25) )
      {
        v51 = jiffies;
        if ( reg_get_best_6g_power_type___last_ticks_27 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: AP power type: %d , is supported by client",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "reg_get_best_6g_power_type",
            a4);
          result = 0;
          reg_get_best_6g_power_type___last_ticks_27 = v51;
          goto LABEL_4;
        }
        goto LABEL_35;
      }
      goto LABEL_12;
    }
    if ( a4 != 8 )
    {
      if ( (unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                           a2,
                           2u,
                           chan_enum_for_freq,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25) )
      {
        if ( (wlan_cm_get_relaxed_lpi_conn_policy(a1) & 1) == 0
          || (unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                             a2,
                             0,
                             chan_enum_for_freq,
                             v61,
                             v62,
                             v63,
                             v64,
                             v65,
                             v66,
                             v67,
                             v68) )
        {
          v69 = jiffies;
          if ( reg_get_best_6g_power_type___last_ticks_23 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x51u,
              2u,
              "%s: Invalid AP power type: %d, couldn't find suitable power type",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "reg_get_best_6g_power_type",
              a4);
            reg_get_best_6g_power_type___last_ticks_23 = v69;
          }
          goto LABEL_3;
        }
        v72 = jiffies;
        if ( reg_get_best_6g_power_type___last_ticks_22 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: Invalid AP power type: %d , selected power type: %d",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "reg_get_best_6g_power_type",
            a4,
            0);
          reg_get_best_6g_power_type___last_ticks_22 = v72;
        }
        result = 0;
        *a3 = 0;
      }
      else
      {
        v71 = jiffies;
        if ( reg_get_best_6g_power_type___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: Invalid AP power type: %d , selected power type: %d",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "reg_get_best_6g_power_type",
            a4,
            2);
          reg_get_best_6g_power_type___last_ticks = v71;
        }
        result = 0;
        *a3 = 2;
      }
      goto LABEL_4;
    }
    v49 = 1;
    if ( (unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                         a2,
                         1u,
                         chan_enum_for_freq,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25) )
    {
      if ( (unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                           a2,
                           0,
                           chan_enum_for_freq,
                           v29,
                           v30,
                           v31,
                           v32,
                           v33,
                           v34,
                           v35,
                           v36) )
      {
LABEL_12:
        if ( (unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                             a2,
                             2u,
                             chan_enum_for_freq,
                             v29,
                             v30,
                             v31,
                             v32,
                             v33,
                             v34,
                             v35,
                             v36) )
        {
          v45 = jiffies;
          if ( reg_get_best_6g_power_type___last_ticks_31 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x51u,
              2u,
              "%s: AP power type = %d, not supported",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "reg_get_best_6g_power_type",
              a4);
            reg_get_best_6g_power_type___last_ticks_31 = v45;
          }
          goto LABEL_3;
        }
        *a3 = 2;
        v52 = jiffies;
        if ( reg_get_best_6g_power_type___last_ticks_29 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: AP power type = %d, selected power type = %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "reg_get_best_6g_power_type",
            a4,
            2);
          result = 0;
          reg_get_best_6g_power_type___last_ticks_29 = v52;
          goto LABEL_4;
        }
LABEL_35:
        result = 0;
        goto LABEL_4;
      }
      v49 = 0;
    }
    *a3 = v49;
    v50 = jiffies;
    if ( reg_get_best_6g_power_type___last_ticks_25 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: AP power type: %d , is supported by client of power type %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "reg_get_best_6g_power_type",
        8,
        v49);
      result = 0;
      reg_get_best_6g_power_type___last_ticks_25 = v50;
      goto LABEL_4;
    }
    goto LABEL_35;
  }
  if ( v73[0] )
  {
    v28 = v73[0];
    if ( v73[0] != 1 )
    {
      if ( v73[0] != 2 )
        goto LABEL_3;
      v28 = 2;
    }
  }
  else
  {
    v28 = 0;
  }
  if ( a4 <= 2 && v28 != a4
    || (unsigned int)reg_check_if_6g_pwr_type_supp_for_chan(
                       a2,
                       v28,
                       chan_enum_for_freq,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25) )
  {
    v46 = jiffies;
    if ( reg_get_best_6g_power_type_for_rf_test___last_ticks_55 - jiffies + 125 < 0 )
    {
      v47 = "VLP";
      if ( v27 == 1 )
        v47 = "SP";
      if ( v27 )
        v48 = v47;
      else
        v48 = "LPI";
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: AP power type = %d, RF mode power type %s, connection not supported",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "reg_get_best_6g_power_type_for_rf_test",
        a4,
        v48);
      reg_get_best_6g_power_type_for_rf_test___last_ticks_55 = v46;
    }
    goto LABEL_3;
  }
  v70 = jiffies;
  if ( reg_get_best_6g_power_type_for_rf_test___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: RF test mode force power type: %d, selected power type: %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "reg_get_best_6g_power_type_for_rf_test",
      v27,
      v28);
    reg_get_best_6g_power_type_for_rf_test___last_ticks = v70;
  }
  result = 0;
  *a3 = v28;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
