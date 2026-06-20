__int64 __fastcall wlan_mlme_get_bw_no_punct(__int64 a1, __int64 a2, unsigned __int16 *a3, unsigned int *a4)
{
  __int64 psoc_ext_obj_fl; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int next_lower_bandwidth; // w21
  unsigned int puncture_by_bw; // w0
  __int64 result; // x0
  unsigned int v36; // w22
  unsigned __int16 v37[2]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v38; // [xsp+14h] [xbp-Ch] BYREF
  char v39; // [xsp+16h] [xbp-Ah]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37[0] = 0;
  v39 = 0;
  v38 = 0;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    goto LABEL_14;
  if ( *(_BYTE *)(psoc_ext_obj_fl + 3600) != 1 )
    goto LABEL_14;
  wlan_reg_read_current_country(a1, &v38, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( !wlan_reg_is_6ghz_chan_freq(*a3) )
    goto LABEL_14;
  if ( !a3[16] )
    goto LABEL_14;
  if ( (unsigned int)qdf_mem_cmp(&v38, "US", 2u) )
    goto LABEL_14;
  if ( (unsigned int)mlme_get_best_6g_power_type(a2, v17, v18, v19, v20, v21, v22, v23, v24) )
    goto LABEL_14;
  if ( (unsigned int)(*((_DWORD *)a3 + 7) - 31) > 9 )
    goto LABEL_14;
  next_lower_bandwidth = *((_DWORD *)a3 + 6);
  if ( next_lower_bandwidth == 8 )
    goto LABEL_14;
  while ( 1 )
  {
    puncture_by_bw = wlan_reg_extract_puncture_by_bw(
                       *((_DWORD *)a3 + 6),
                       a3[16],
                       *a3,
                       *((_DWORD *)a3 + 5),
                       next_lower_bandwidth,
                       v37,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32);
    if ( puncture_by_bw || !v37[0] )
      break;
    next_lower_bandwidth = wlan_get_next_lower_bandwidth(next_lower_bandwidth);
    if ( next_lower_bandwidth == 8 )
    {
      puncture_by_bw = 0;
      break;
    }
  }
  if ( next_lower_bandwidth != *((_DWORD *)a3 + 6) )
  {
    v36 = puncture_by_bw;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: freq %d ccfs2 %d punct 0x%x BW old %d, new %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wlan_mlme_get_bw_no_punct",
      *a3,
      *((unsigned int *)a3 + 5),
      a3[16],
      next_lower_bandwidth);
    result = v36;
    *a4 = next_lower_bandwidth;
    a3[16] = 0;
  }
  else
  {
LABEL_14:
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
