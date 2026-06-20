__int64 __fastcall pmo_core_disable_arp_offload_in_fwr(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w20
  unsigned int v39; // w20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  if ( a1 )
  {
    result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( !(_DWORD)result )
    {
      if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 2LL) & 1) != 0 )
      {
        if ( (pmo_core_is_vdev_supports_offload(a1) & 1) != 0 )
        {
          if ( (unsigned int)wlan_vdev_is_up() )
          {
            v38 = 4;
          }
          else
          {
            v39 = *(unsigned __int8 *)(a1 + 104);
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: Disable arp offload in fwr vdev id: %d vdev: %pK",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "pmo_core_disable_arp_offload_in_fwr",
              *(unsigned __int8 *)(a1 + 104),
              a1);
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: enter",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "pmo_core_do_disable_arp_offload");
            if ( *(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) )
            {
              if ( a2 == 10 || a2 == 1 )
              {
                v38 = pmo_tgt_disable_arp_offload_req(a1, v39);
              }
              else
              {
                qdf_trace_msg(
                  0x4Du,
                  2u,
                  "%s: invalid pmo trigger",
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  "pmo_core_do_disable_arp_offload");
                v38 = 4;
              }
            }
            else
            {
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: psoc_ctx is NULL",
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                "pmo_core_do_disable_arp_offload");
              v38 = 29;
            }
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: exit",
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              "pmo_core_do_disable_arp_offload");
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: vdev in invalid opmode for arp offload %d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "pmo_core_arp_offload_sanity",
            *(unsigned int *)(a1 + 16));
          v38 = 4;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: user disabled arp offload using ini",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "pmo_core_arp_offload_sanity");
        v38 = 4;
      }
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
      return v38;
    }
  }
  else
  {
    qdf_trace_msg(0x4Du, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_disable_arp_offload_in_fwr");
    return 29;
  }
  return result;
}
