__int64 __fastcall sap_update_vlp_deprority_chan(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int thresh_priority_freq; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  unsigned __int64 v40; // x23
  int *v41; // x24
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w5
  __int64 v51; // x4
  __int16 v52; // [xsp+4h] [xbp-Ch] BYREF
  char v53; // [xsp+6h] [xbp-Ah]
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 21624);
  v13 = *a2;
  v53 = 0;
  v52 = 0;
  wlan_reg_read_current_country(v12, &v52, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (unsigned __int8)wlan_reg_get_num_rules_of_ap_pwr_type(
                          *(_QWORD *)(a1 + 21632),
                          2u,
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21) )
  {
    thresh_priority_freq = wlan_reg_get_thresh_priority_freq(
                             *(_QWORD *)(a1 + 21632),
                             v22,
                             v23,
                             v24,
                             v25,
                             v26,
                             v27,
                             v28,
                             v29);
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: country %.2s vlp_cut_off freq %u",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "sap_update_vlp_deprority_chan",
               &v52,
               thresh_priority_freq);
    if ( *((_BYTE *)a2 + 8) )
    {
      v40 = 0;
      v41 = (int *)(v13 + 12);
      do
      {
        result = wlan_reg_is_vlp_depriority_freq(*(_QWORD *)(a1 + 21632), *(v41 - 3));
        if ( (result & 1) != 0 )
        {
          v50 = *v41;
          v51 = (unsigned int)*(v41 - 3);
          *((_BYTE *)v41 + 9) = 1;
          *v41 = 10 * v50 / 0x64u + v50;
          result = qdf_trace_msg(
                     0x39u,
                     8u,
                     "%s: freq %d org_weight %u updated weightage %u",
                     v42,
                     v43,
                     v44,
                     v45,
                     v46,
                     v47,
                     v48,
                     v49,
                     "sap_update_vlp_deprority_chan",
                     v51);
        }
        ++v40;
        v41 += 6;
      }
      while ( v40 < *((unsigned __int8 *)a2 + 8) );
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: Current country %.2s don't support VLP",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "sap_update_vlp_deprority_chan",
               &v52);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
