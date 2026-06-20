__int64 __fastcall pmo_core_enable_arp_offload_in_fwr(
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
  __int64 v39; // x8
  unsigned int v40; // w20
  const char *v41; // x2
  const char *v42; // x3

  if ( !a1 )
  {
    qdf_trace_msg(0x4Du, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_enable_arp_offload_in_fwr");
    return 29;
  }
  result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 2LL) & 1) != 0 )
    {
      if ( (pmo_core_is_vdev_supports_offload(a1) & 1) == 0 )
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
        goto LABEL_16;
      }
      if ( (unsigned int)wlan_vdev_is_up() )
      {
LABEL_16:
        v40 = 4;
        goto LABEL_17;
      }
      v38 = *(unsigned __int8 *)(a1 + 104);
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Enable arp offload in fwr vdev id: %d vdev: %pK",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "pmo_core_enable_arp_offload_in_fwr",
        *(unsigned __int8 *)(a1 + 104),
        a1);
      v39 = *(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      if ( !v39 )
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: psoc_ctx is NULL",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "pmo_core_do_enable_arp_offload");
        v40 = 29;
        goto LABEL_17;
      }
      if ( !a2 || a2 == 10 )
        goto LABEL_11;
      if ( a2 == 4 )
      {
        if ( (*(_BYTE *)(v39 + 13) & 1) == 0 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: active offload is disabled, skip in mode %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "pmo_core_do_enable_arp_offload",
            4);
          v40 = 0;
          goto LABEL_17;
        }
LABEL_11:
        v40 = pmo_tgt_enable_arp_offload_req(a1, v38);
LABEL_17:
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
        return v40;
      }
      v41 = "%s: invalid pmo trigger";
      v42 = "pmo_core_do_enable_arp_offload";
    }
    else
    {
      v41 = "%s: user disabled arp offload using ini";
      v42 = "pmo_core_arp_offload_sanity";
    }
    qdf_trace_msg(0x4Du, 2u, v41, v13, v14, v15, v16, v17, v18, v19, v20, v42);
    goto LABEL_16;
  }
  return result;
}
