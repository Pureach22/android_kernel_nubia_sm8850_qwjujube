__int64 __fastcall hdd_get_tsf_cb(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *link_info_by_vdev; // x0
  __int64 v13; // x20
  __int64 *v14; // x21
  _QWORD *v15; // x22
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  _QWORD *v26; // x20
  unsigned int v27; // w19
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  _DWORD *v37; // x8
  __int64 v38; // x1
  const char *v39; // x2
  __int64 v41; // x24
  __int64 v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x6
  __int64 v52; // x20
  const char *v53; // x2
  __int64 v54; // x8
  __int64 v55; // x9
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  if ( !a1 || !a2 )
  {
    v39 = "%s: HDD context is not valid";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v39, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_tsf_cb");
    return 4294967274LL;
  }
  if ( !(unsigned int)_wlan_hdd_validate_context(a1, (__int64)"hdd_get_tsf_cb", a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(a1, *a2);
    if ( link_info_by_vdev )
    {
      v13 = *link_info_by_vdev;
      v14 = (__int64 *)(*link_info_by_vdev + 52816LL);
      v15 = (_QWORD *)(*link_info_by_vdev + 38936LL);
      context = _cds_get_context(71, (__int64)"hdd_set_delta_tsf", a3, a4, a5, a6, a7, a8, a9, a10);
      if ( a2[8] )
      {
        if ( *(_QWORD *)(v13 + 39392) )
        {
          v25 = *a2;
          v26 = context;
          v27 = a2[1] - a2[3];
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %u tsf_low %u qtimer_low %u delta_tsf %u",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "hdd_set_delta_tsf",
            v25);
          if ( v26 && *v26 )
          {
            v36 = *(_QWORD *)(*v26 + 8LL);
            if ( v36 )
            {
              v37 = *(_DWORD **)(v36 + 200);
              if ( v37 )
              {
                v38 = *(unsigned __int8 *)(v14[2] + 8);
                if ( *(v37 - 1) != 1340911981 )
                  __break(0x8228u);
                ((void (__fastcall *)(_QWORD *, __int64, _QWORD))v37)(v26, v38, v27);
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              2u,
              "%s: Invalid instance",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "cdp_set_delta_tsf");
          }
        }
        else
        {
          v52 = jiffies;
          if ( hdd_set_delta_tsf___last_ticks_96 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: adapter %u tsf_auto_report disabled",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "hdd_set_delta_tsf",
              *(unsigned __int8 *)(v14[2] + 8));
            hdd_set_delta_tsf___last_ticks_96 = v52;
            return 0;
          }
        }
        return 0;
      }
      v41 = jiffies;
      if ( hdd_set_delta_tsf___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(0x33u, 8u, "%s: Not TSF auto report", v17, v18, v19, v20, v21, v22, v23, v24, "hdd_set_delta_tsf");
        hdd_set_delta_tsf___last_ticks = v41;
      }
      if ( v13 )
      {
        v42 = *(_QWORD *)(v13 + 24);
        if ( v42 )
        {
          if ( *(_DWORD *)(v42 + 3232) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: tsf cb handle event, device_mode is %d",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "hdd_get_tsf_cb",
              *(unsigned int *)(v13 + 40));
            if ( a2[10] )
            {
              *(_DWORD *)(v13 + 39148) = a2[9];
              *(_DWORD *)(v13 + 39152) = a2[7];
              *(_DWORD *)(v13 + 39156) = 1;
              v51 = a2[10];
            }
            else
            {
              v51 = 0;
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: vdev_id %u tsf_id %u tsf_id_valid %u mac_id %u",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "wlan_hdd_tsf_reg_update_details",
              *(unsigned __int8 *)(*(_QWORD *)(v13 + 52832) + 8LL),
              a2[9],
              v51,
              a2[7]);
            *v15 = *(_QWORD *)(a2 + 1);
            *(_QWORD *)(v13 + 38960) = *(_QWORD *)(a2 + 5);
            v54 = 1000LL * *(_QWORD *)(a2 + 3);
            v55 = *v14;
            *(_QWORD *)(v13 + 38944) = v54;
            *(_QWORD *)(v13 + 39352) = v54 - v55;
            hdd_update_tsf(v13);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev=%u, tsf_low=%u, tsf_high=%u ptsf->soc_timer_low=%u ptsf->soc_timer_high=%u",
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              "hdd_get_tsf_cb",
              *a2,
              a2[1],
              a2[2],
              a2[3],
              a2[4]);
            return 0;
          }
          v53 = "%s: TSF is not initialized";
        }
        else
        {
          v53 = "%s: invalid hdd context";
        }
      }
      else
      {
        v53 = "%s: invalid adapter";
      }
      qdf_trace_msg(0x33u, 2u, v53, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_tsf_is_initialized");
      v39 = "%s: tsf is not init, ignore tsf event";
    }
    else
    {
      v39 = "%s: failed to find adapter";
    }
    goto LABEL_15;
  }
  return 4294967274LL;
}
