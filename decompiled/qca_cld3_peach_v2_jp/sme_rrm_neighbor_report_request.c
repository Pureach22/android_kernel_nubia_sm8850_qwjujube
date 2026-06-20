__int64 __fastcall sme_rrm_neighbor_report_request(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
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
  __int64 v24; // x8
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x23
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x24

  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Request to send Neighbor report request received ",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "sme_rrm_neighbor_report_request");
  if ( a1 && a2 <= 5u && (v24 = *(_QWORD *)(a1 + 17224)) != 0 && (*(_BYTE *)(v24 + 96LL * a2 + 1) & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 17648) == 1 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Neighbor request already pending.. Not allowed",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_rrm_neighbor_report_request");
      return 3;
    }
    else
    {
      v26 = _qdf_mem_malloc(0x2Eu, "sme_rrm_neighbor_report_request", 1743);
      if ( v26 )
      {
        v35 = v26;
        csr_ll_lock(a1 + 17560, v27, v28, v29, v30, v31, v32, v33, v34);
        while ( 1 )
        {
          v44 = csr_ll_remove_head(a1 + 17560, 0, v36, v37, v38, v39, v40, v41, v42, v43);
          if ( !v44 )
            break;
          v53 = v44;
          _qdf_mem_free(*(_QWORD *)(v44 + 16));
          _qdf_mem_free(v53);
        }
        csr_ll_unlock(a1 + 17560, v45, v46, v47, v48, v49, v50, v51, v52);
        *(_DWORD *)v35 = 3019819;
        wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), a2, (void *)(v35 + 4));
        *(_WORD *)(v35 + 10) = *a3;
        qdf_mem_copy((void *)(v35 + 12), a3 + 1, 0x22u);
        if ( (unsigned int)umac_send_mb_message_to_mac(v35) )
        {
          return 16;
        }
        else
        {
          *(_QWORD *)(a1 + 17832) = *(_QWORD *)(a4 + 8);
          *(_QWORD *)(a1 + 17840) = *(_QWORD *)(a4 + 16);
          *(_BYTE *)(a1 + 17648) = 1;
          qdf_mc_timer_start(a1 + 17656, *(_DWORD *)a4);
          return 0;
        }
      }
      else
      {
        return 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid session %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sme_rrm_neighbor_report_request",
      a2);
    return 4;
  }
}
