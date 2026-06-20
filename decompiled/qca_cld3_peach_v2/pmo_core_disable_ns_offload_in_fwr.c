__int64 __fastcall pmo_core_disable_ns_offload_in_fwr(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int ref; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int *v46; // x8
  const char *v47; // x2
  const char *v48; // x3
  unsigned int v50; // w21
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 comp_private_obj; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_disable_ns_offload_in_fwr");
  if ( a1 )
  {
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( !ref )
    {
      v29 = *(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 8LL) & 1) != 0 )
      {
        if ( (pmo_core_is_vdev_supports_offload(a1, v30, v31, v32, v33, v34, v35, v36, v37) & 1) == 0 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: vdev in invalid opmode for ns offload %d",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "pmo_core_ns_offload_sanity",
            *(unsigned int *)(a1 + 16));
          goto LABEL_13;
        }
        if ( (unsigned int)wlan_vdev_is_up() )
        {
LABEL_13:
          ref = 4;
          goto LABEL_14;
        }
        v46 = (unsigned int *)*(unsigned __int8 *)(v29 + 9);
        if ( a2 == 7 )
        {
          if ( *(_BYTE *)(v29 + 9) )
          {
            *(_BYTE *)(v29 + 9) = 0;
            goto LABEL_17;
          }
          ref = 0;
LABEL_14:
          wlan_objmgr_vdev_release_ref(a1, 0xAu, v46, v30, v31, v32, v33, v34, v35, v36, v37);
          goto LABEL_15;
        }
        if ( ((unsigned __int8)v46 & 1) != 0 )
        {
LABEL_17:
          v50 = *(unsigned __int8 *)(a1 + 168);
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: disable ns offload in fwr vdev id: %d vdev: %pK trigger: %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "pmo_core_disable_ns_offload_in_fwr",
            *(unsigned __int8 *)(a1 + 168),
            a1,
            (unsigned int)a2);
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: enter",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "pmo_core_do_disable_ns_offload");
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 4u);
          if ( a2 > 6 )
          {
            if ( a2 != 10 )
            {
              if ( a2 != 7 )
                goto LABEL_20;
LABEL_25:
              if ( (*(_BYTE *)(comp_private_obj + 13) & 1) == 0 )
              {
                qdf_trace_msg(
                  0x4Du,
                  8u,
                  "%s: active offload is disabled, skip in mode:%d",
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  "pmo_core_do_disable_ns_offload",
                  (unsigned int)a2);
                ref = 0;
                goto LABEL_28;
              }
            }
          }
          else if ( a2 != 1 )
          {
            if ( a2 != 5 )
            {
LABEL_20:
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: invalid pmo trigger",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "pmo_core_do_disable_ns_offload");
              ref = 4;
LABEL_28:
              qdf_trace_msg(
                0x4Du,
                8u,
                "%s: exit",
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                "pmo_core_do_disable_ns_offload");
              goto LABEL_14;
            }
            goto LABEL_25;
          }
          ref = pmo_tgt_disable_ns_offload_req(a1, v50);
          goto LABEL_28;
        }
        v47 = "%s: ns offload dynamically disable";
        v48 = "pmo_core_disable_ns_offload_in_fwr";
      }
      else
      {
        v47 = "%s: ns offload statically disable";
        v48 = "pmo_core_ns_offload_sanity";
      }
      qdf_trace_msg(0x4Du, 8u, v47, v30, v31, v32, v33, v34, v35, v36, v37, v48);
      goto LABEL_13;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_core_disable_ns_offload_in_fwr");
    ref = 4;
  }
LABEL_15:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "pmo_core_disable_ns_offload_in_fwr");
  return ref;
}
