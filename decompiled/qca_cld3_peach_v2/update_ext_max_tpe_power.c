__int64 __fastcall update_ext_max_tpe_power(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x0
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  __int64 v26; // x25
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned __int8 v35; // w8
  __int64 v36; // x25
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int8 v45; // w8
  __int64 v46; // x4
  unsigned __int8 v47; // w8
  unsigned int v48; // [xsp+8h] [xbp-18h] BYREF
  char v49; // [xsp+Ch] [xbp-14h]
  __int16 v50; // [xsp+10h] [xbp-10h]
  __int16 v51; // [xsp+14h] [xbp-Ch]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a1 + 21632);
  v51 = 0;
  v50 = 0;
  v49 = 0;
  v48 = 0;
  wlan_reg_get_cur_6g_ap_pwr_type(v15, &v48, a5, a6, a7, a8, a9, a10, a11, a12);
  result = wlan_reg_get_client_power_for_6ghz_ap();
  v25 = (*(unsigned __int8 *)(a2 + 1) >> 3) & 7;
  if ( v25 <= 1 )
  {
    if ( v25 )
    {
      if ( v25 == 1 )
      {
        *(_BYTE *)(a2 + 11) = *(_BYTE *)(a2 + 11) & 0xF0 | a4 & 0xF;
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: Ext count : %d ",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "update_ext_max_tpe_power",
                   a4);
        if ( a4 )
        {
          v26 = 0;
          while ( 1 )
          {
            wlan_reg_get_client_power_for_6ghz_ap();
            if ( v26 == 15 )
              goto LABEL_20;
            a3 += 20;
            v35 = 2 * v50;
            *(_BYTE *)(a2 + 12 + v26) = 2 * v50;
            result = qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: psd ext max tx power %d",
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       v34,
                       "update_ext_max_tpe_power",
                       v35 & 0xFE);
            if ( a4 == ++v26 )
              goto LABEL_19;
          }
        }
      }
      goto LABEL_19;
    }
    v46 = (unsigned __int8)v51;
    *(_BYTE *)(a2 + 11) = v51;
LABEL_18:
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: non-psd ext max tx power %d",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "update_ext_max_tpe_power",
               v46);
    goto LABEL_19;
  }
  if ( v25 == 2 )
  {
    v47 = 2 * v51;
    *(_BYTE *)(a2 + 11) = 2 * v51;
    v46 = v47 & 0xFE;
    goto LABEL_18;
  }
  if ( v25 == 3 )
  {
    *(_BYTE *)(a2 + 11) = *(_BYTE *)(a2 + 11) & 0xF0 | a4 & 0xF;
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Ext count : %d ",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "update_ext_max_tpe_power",
               a4);
    if ( a4 )
    {
      v36 = 0;
      while ( 1 )
      {
        wlan_reg_get_client_power_for_6ghz_ap();
        if ( v36 == 15 )
          break;
        a3 += 20;
        v45 = 2 * v50;
        *(_BYTE *)(a2 + 12 + v36) = 2 * v50;
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: psd ext max tx power %d",
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   "update_ext_max_tpe_power",
                   v45 & 0xFE);
        if ( a4 == ++v36 )
          goto LABEL_19;
      }
LABEL_20:
      __break(0x5512u);
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
