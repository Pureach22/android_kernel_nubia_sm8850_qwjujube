__int64 __fastcall wlan_hdd_send_mlo_station_stats(
        __int64 a1,
        __int64 a2,
        int *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  int v25; // w9
  unsigned __int64 StatusReg; // x8
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x1
  __int64 v37; // x0
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  __int64 v48; // x0
  unsigned __int64 v49; // x25
  __int64 v50; // x23
  __int64 v51; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 result; // x0
  __int64 v80; // x21
  __int64 v81; // x19
  __int64 v82; // [xsp+0h] [xbp-20h] BYREF
  __int64 v83[3]; // [xsp+8h] [xbp-18h] BYREF

  v83[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (wlan_hdd_is_mlo_connection(*(_QWORD *)(a1 + 52824), a5, a6, a7, a8, a9, a10, a11, a12) & 1) != 0 )
  {
    v24 = *a3;
    v25 = *((unsigned __int16 *)a3 + 2);
    v82 = 0;
    v83[0] = 0;
    if ( v24 | v25 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a2 + 32);
      }
      else
      {
        raw_spin_lock_bh(a2 + 32);
        *(_QWORD *)(a2 + 40) |= 1uLL;
      }
      hdd_get_front_adapter_no_lock(a2, v83);
      if ( v83[0] )
      {
        hdd_adapter_dev_hold_debug(v83[0], 0x3Eu, v27, v28, v29, v30, v31, v32, v33, v34, v35);
        v36 = v83[0];
      }
      else
      {
        v36 = 0;
      }
      hdd_get_next_adapter_no_lock(a2, v36, &v82);
      if ( v82 )
        hdd_adapter_dev_hold_debug(v82, 0x3Eu, v38, v39, v40, v41, v42, v43, v44, v45, v46);
      v47 = *(_QWORD *)(a2 + 40);
      if ( (v47 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 40) = v47 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 32);
        v48 = v83[0];
        if ( v83[0] )
        {
LABEL_15:
          v49 = _ReadStatusReg(SP_EL0);
          do
          {
            while ( 1 )
            {
              v50 = v48 + 52832;
              if ( v48 != -52832 )
              {
                v51 = 0;
                while ( !v51 )
                {
                  if ( *a3 == *(_DWORD *)(v50 + 300)
                    && *((unsigned __int16 *)a3 + 2) == *(unsigned __int16 *)(v50 + 304) )
                  {
                    hdd_adapter_dev_put_debug(v48, 0x3Eu, v16, v17, v18, v19, v20, v21, v22, v23);
                    if ( v82 )
                      hdd_adapter_dev_put_debug(v82, 0x3Eu, v71, v72, v73, v74, v75, v76, v77, v78);
                    v37 = v50;
                    goto LABEL_39;
                  }
                  v50 += 4528;
                  v51 = -4528;
                  if ( !v50 )
                    break;
                }
              }
              hdd_adapter_dev_put_debug(v48, 0x3Eu, v16, v17, v18, v19, v20, v21, v22, v23);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v49 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v49 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(a2 + 32);
              }
              else
              {
                raw_spin_lock_bh(a2 + 32);
                *(_QWORD *)(a2 + 40) |= 1uLL;
              }
              v83[0] = v82;
              hdd_get_next_adapter_no_lock(a2, v82, &v82);
              hdd_validate_next_adapter(v83, &v82, 0x3Eu, v53, v54, v55, v56, v57, v58, v59, v60);
              if ( v82 )
                hdd_adapter_dev_hold_debug(v82, 0x3Eu, v61, v62, v63, v64, v65, v66, v67, v68, v69);
              v70 = *(_QWORD *)(a2 + 40);
              if ( (v70 & 1) != 0 )
                break;
              raw_spin_unlock(a2 + 32);
              v48 = v83[0];
              if ( !v83[0] )
                goto LABEL_41;
            }
            *(_QWORD *)(a2 + 40) = v70 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 32);
            v48 = v83[0];
          }
          while ( v83[0] );
        }
      }
      else
      {
        raw_spin_unlock(a2 + 32);
        v48 = v83[0];
        if ( v83[0] )
          goto LABEL_15;
      }
    }
LABEL_41:
    if ( *(_QWORD *)(a1 + 24) )
    {
      v80 = jiffies;
      if ( wlan_is_mlo_aggregated_stats_allowed___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: mlo_vdev_stats: failed to get bss peer mld mac",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_is_mlo_aggregated_stats_allowed");
        wlan_is_mlo_aggregated_stats_allowed___last_ticks = v80;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid hdd_ctx",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_is_mlo_aggregated_stats_allowed");
    }
    v81 = jiffies;
    if ( wlan_hdd_send_mlo_station_stats___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Invalid bssid",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_hdd_send_mlo_station_stats");
      wlan_hdd_send_mlo_station_stats___last_ticks = v81;
    }
    result = 4294967274LL;
    goto LABEL_48;
  }
  qdf_trace_msg(0x33u, 8u, "Fetching station stats for legacy connection", v16, v17, v18, v19, v20, v21, v22, v23);
  v37 = *(_QWORD *)(a1 + 52824);
LABEL_39:
  wlan_hdd_get_sta_stats(v37, a3, a4);
  result = 0;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
