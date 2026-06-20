__int64 __fastcall scm_add_channel_flags(__int64 result, __int64 a2, unsigned __int8 *a3, char a4, char a5)
{
  __int64 v5; // x22
  __int64 v7; // x24
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w8
  _DWORD *v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _DWORD *v29; // x19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w10
  __int16 v39; // w11
  _DWORD *v40; // x23
  _DWORD *v41; // x23
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v5 = *(_QWORD *)(result + 152);
  if ( !v5 )
    return result;
  v7 = *a3;
  result = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v5 + 80), 3u);
  if ( !result )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    return qdf_trace_msg(
             0x15u,
             2u,
             "%s: scan_obj is NULL",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "scm_add_channel_flags");
  }
  v19 = *(_DWORD *)(result + 1740);
  if ( v19 > 3 )
  {
    if ( (unsigned int)(v19 - 4) >= 2 )
      return result;
    if ( (a5 & 1) == 0 )
    {
      v38 = *(unsigned __int16 *)(result + 23984);
      if ( *(unsigned __int8 *)(result + 1744) == (unsigned __int16)(v38 + 1) )
        v39 = 0;
      else
        v39 = v38 + 1;
      *(_WORD *)(result + 23984) = v39;
      if ( v38 )
      {
        if ( (_DWORD)v7 )
        {
          v40 = (_DWORD *)(a2 + 12);
          do
          {
            if ( wlan_reg_is_6ghz_chan_freq(*(v40 - 2)) )
              *v40 = 1;
            --v7;
            v40 += 3;
          }
          while ( v7 );
        }
      }
      else if ( v19 == 4 && (_DWORD)v7 )
      {
        v41 = (_DWORD *)(a2 + 12);
        do
        {
          if ( wlan_reg_is_6ghz_chan_freq(*(v41 - 2))
            && (wlan_reg_is_6ghz_psc_chan_freq(*(v41 - 2), v42, v43, v44, v45, v46, v47, v48, v49) & 1) == 0 )
          {
            *v41 = 1;
          }
          --v7;
          v41 += 3;
        }
        while ( v7 );
      }
    }
    return ((__int64 (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))scm_add_all_valid_6g_channels)(
             v5,
             a2,
             a3,
             a4 & 1);
  }
  if ( v19 != 1 )
  {
    if ( v19 != 2 )
    {
      if ( v19 == 3 && (_DWORD)v7 )
      {
        v20 = (_DWORD *)(a2 + 12);
        do
        {
          result = wlan_reg_is_6ghz_chan_freq(*(v20 - 2));
          if ( (result & 1) != 0 )
            *v20 = 1;
          --v7;
          v20 += 3;
        }
        while ( v7 );
      }
      return result;
    }
    return ((__int64 (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))scm_add_all_valid_6g_channels)(
             v5,
             a2,
             a3,
             a4 & 1);
  }
  if ( (_DWORD)v7 )
  {
    v29 = (_DWORD *)(a2 + 12);
    do
    {
      result = wlan_reg_is_6ghz_chan_freq(*(v29 - 2));
      if ( (result & 1) != 0 )
      {
        result = wlan_reg_is_6ghz_psc_chan_freq(*(v29 - 2), v30, v31, v32, v33, v34, v35, v36, v37);
        if ( (result & 1) == 0 )
          *v29 = 1;
      }
      --v7;
      v29 += 3;
    }
    while ( v7 );
  }
  return result;
}
