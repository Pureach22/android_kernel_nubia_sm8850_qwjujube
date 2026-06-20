__int64 __fastcall wlan_hdd_chan_info_cb(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x20
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x21
  int v21; // w8
  unsigned int v22; // w22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w25
  __int64 v40; // x4
  __int64 v41; // x5
  unsigned int v42; // w24
  __int64 v43; // x5
  unsigned int v44; // w23
  unsigned int v45; // w26
  unsigned __int64 i; // x23
  unsigned int *v47; // x22
  unsigned __int16 *bonded_chan_entry; // x0
  unsigned int v49; // w27
  __int64 v50; // x22
  unsigned int v51; // w28
  unsigned int v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // [xsp+10h] [xbp-20h] BYREF
  __int64 v62; // [xsp+18h] [xbp-18h]
  __int64 v63; // [xsp+20h] [xbp-10h]
  __int64 v64; // [xsp+28h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"wlan_hdd_chan_info_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  result = _wlan_hdd_validate_context(context, "wlan_hdd_chan_info_cb");
  if ( !(_DWORD)result )
  {
    v20 = (unsigned int *)context[217];
    if ( !v20 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: chan_info is NULL",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "wlan_hdd_chan_info_cb");
      goto LABEL_2;
    }
    if ( (*((_BYTE *)a1 + 33) & 1) == 0 )
    {
      for ( i = 0; ; ++i )
      {
        v47 = &v20[25 * i];
        if ( *v47 == *a1 )
        {
          result = hdd_update_chan_info(context, &v20[25 * i], a1);
          if ( !*v47 || i >= 0x65 )
            goto LABEL_2;
        }
        else if ( i > 0x64 )
        {
          goto LABEL_2;
        }
      }
    }
    v21 = *((unsigned __int8 *)a1 + 32);
    v22 = *((unsigned __int8 *)a1 + 28);
    LODWORD(v63) = 0;
    v61 = 0;
    v62 = 0;
    if ( v21 <= 3 )
    {
      if ( v21 == 1 )
      {
        v43 = *a1;
        v42 = 0;
        v44 = *a1;
        v45 = *a1;
        goto LABEL_33;
      }
      if ( v21 == 2 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(*a1) )
        {
          wlan_cm_get_associated_ch_info(*context, v22, 1, &v61);
          v39 = HIDWORD(v62);
          v40 = a1[7];
          v41 = *a1;
          if ( !HIDWORD(v62) )
          {
            result = qdf_trace_msg(
                       0x68u,
                       8u,
                       "%s: vdev %d : Invalid sec 2g freq for freq:%d",
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       "wlan_hdd_fill_subband_scan_info",
                       v40,
                       v41);
            goto LABEL_2;
          }
          v42 = 1;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %d :assoc freq %d sec_2g_freq:%d, bw %d",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "wlan_hdd_fill_subband_scan_info",
            v40,
            v41,
            HIDWORD(v62),
            1);
          v43 = *a1;
          if ( (unsigned int)v43 >= v39 )
            v44 = v39;
          else
            v44 = *a1;
          if ( (unsigned int)v43 <= v39 )
            v45 = v39;
          else
            v45 = *a1;
          goto LABEL_33;
        }
        v42 = 1;
LABEL_31:
        bonded_chan_entry = wlan_reg_get_bonded_chan_entry(*a1, v42, 0, v23, v24, v25, v26, v27, v28, v29, v30);
        if ( !bonded_chan_entry )
        {
          result = qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: vdev %d: bonded_chan_array is NULL for freq %d, ch_width %d",
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     "wlan_hdd_fill_subband_scan_info",
                     v22,
                     *a1,
                     v42);
          goto LABEL_2;
        }
        v44 = *bonded_chan_entry;
        v45 = bonded_chan_entry[1];
        v43 = *a1;
LABEL_33:
        v49 = *((unsigned __int8 *)a1 + 32);
        result = qdf_trace_msg(
                   0x33u,
                   8u,
                   "%s: vdev %d: freq :%d bw %d, range [%d-%d], num_freq:%d",
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   "wlan_hdd_fill_subband_scan_info",
                   v22,
                   v43,
                   v42,
                   v44,
                   v45,
                   v49,
                   v61,
                   v62,
                   v63,
                   v64);
        v50 = 0;
        v51 = 0;
        while ( 1 )
        {
          if ( *v20 )
          {
            if ( v44 > v45 || v51 >= v49 || v51 > 0xF )
              goto LABEL_2;
            if ( *v20 == v44 )
            {
              v52 = a1[v51 + 9];
              *a1 = v44;
              a1[4] = v52;
              hdd_update_chan_info(context, v20, a1);
              result = qdf_trace_msg(
                         0x33u,
                         8u,
                         "%s: updated info for freq:%u rcc:%d at index:%d",
                         v53,
                         v54,
                         v55,
                         v56,
                         v57,
                         v58,
                         v59,
                         v60,
                         "wlan_hdd_fill_subband_scan_info",
                         *v20,
                         v20[4],
                         (unsigned int)v50);
              v44 += 20;
              ++v51;
            }
          }
          ++v50;
          v20 += 25;
          if ( v50 == 102 )
            goto LABEL_2;
        }
      }
LABEL_27:
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: vdev %d: Invalid scanned_ch_width",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "wlan_hdd_fill_subband_scan_info",
                 v22);
      goto LABEL_2;
    }
    if ( v21 == 4 )
    {
      v42 = 2;
    }
    else
    {
      if ( v21 != 8 )
        goto LABEL_27;
      v42 = 3;
    }
    wlan_reg_is_24ghz_ch_freq(*a1);
    goto LABEL_31;
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
