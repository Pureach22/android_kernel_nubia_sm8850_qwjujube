__int64 __fastcall wma_tx_abort(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x9
  __int64 *v20; // x21
  unsigned __int8 *vdev_bssid; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _QWORD *context; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  void (*v57)(void); // x8
  __int64 v58; // [xsp+8h] [xbp-18h]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(54, (__int64)"wma_tx_abort", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v19 = *(_QWORD *)(result + 520);
    if ( *(_QWORD *)(v19 + 488LL * a1) )
    {
      v20 = (__int64 *)result;
      vdev_bssid = (unsigned __int8 *)wma_get_vdev_bssid(*(_QWORD *)(v19 + 488LL * a1));
      if ( vdev_bssid )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: vdevid %d bssid %02x:%02x:%02x:**:**:%02x",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wma_tx_abort",
          a1,
          *vdev_bssid,
          vdev_bssid[1],
          vdev_bssid[2],
          vdev_bssid[5],
          v58,
          0,
          v59);
        context = _cds_get_context(54, (__int64)"wma_vdev_set_pause_bit", v30, v31, v32, v33, v34, v35, v36, v37);
        if ( context && !(context[65] + 488LL * a1) )
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Interface is NULL",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "wma_vdev_set_pause_bit");
        v47 = _cds_get_context(71, (__int64)"wma_tx_abort", v39, v40, v41, v42, v43, v44, v45, v46);
        if ( v47 && *v47 )
        {
          v56 = *(_QWORD *)(*v47 + 120LL);
          if ( v56 )
          {
            v57 = *(void (**)(void))(v56 + 48);
            if ( v57 )
            {
              if ( *((_DWORD *)v57 - 1) != 875705606 )
                __break(0x8228u);
              v57();
            }
          }
        }
        else
        {
          qdf_trace_msg(0x89u, 8u, "%s: invalid instance", v48, v49, v50, v51, v52, v53, v54, v55, "cdp_fc_vdev_pause");
        }
        result = wmi_unified_peer_flush_tids_send(*v20);
      }
      else
      {
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: Failed to get bssid for vdev_%d",
                   v22,
                   v23,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   "wma_tx_abort",
                   a1);
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: iface->vdev is NULL",
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 "wma_tx_abort");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
