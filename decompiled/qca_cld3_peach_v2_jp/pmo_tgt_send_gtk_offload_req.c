__int64 __fastcall pmo_tgt_send_gtk_offload_req(
        __int64 a1,
        __int64 a2,
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
  __int64 v20; // x8
  __int64 v21; // x21
  __int64 comp_private_obj; // x22
  __int64 (__fastcall *v23)(__int64, __int64); // x23
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x21
  unsigned int v42; // w19
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_tgt_send_gtk_offload_req");
  v20 = *(_QWORD *)(a1 + 152);
  if ( v20 && (v21 = *(_QWORD *)(v20 + 80)) != 0 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v23 = *(__int64 (__fastcall **)(__int64, __int64))(wlan_objmgr_psoc_get_comp_private_obj(v21, 4u) + 256);
    if ( v23 )
    {
      v32 = _qdf_mem_malloc(0x80u, "pmo_tgt_send_gtk_offload_req", 57);
      if ( v32 )
      {
        v41 = v32;
        if ( *(_DWORD *)a2 )
        {
          *(_DWORD *)(comp_private_obj + 1024) = 0;
        }
        else
        {
          *(_DWORD *)(comp_private_obj + 1024) = 1;
          qdf_mem_copy((void *)(v32 + 4), (const void *)(a2 + 4), *(unsigned __int8 *)(a2 + 36));
          *(_BYTE *)(v41 + 36) = *(_BYTE *)(a2 + 36);
          qdf_mem_copy((void *)(v41 + 37), (const void *)(a2 + 37), 0x40u);
          *(_DWORD *)(v41 + 104) = *(_DWORD *)(a2 + 104);
          qdf_mem_copy((void *)(v41 + 112), (const void *)(a2 + 112), 8u);
        }
        qdf_trace_msg(
          0x4Du,
          8u,
          "%s: replay counter %llu",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "pmo_tgt_send_gtk_offload_req",
          *(_QWORD *)(v41 + 112));
        *(_DWORD *)v41 = *(_DWORD *)a2;
        if ( *((_DWORD *)v23 - 1) != -455977467 )
          __break(0x8237u);
        v42 = v23(a1, v41);
        if ( v42 )
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Failed to send gtk offload req event",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "pmo_tgt_send_gtk_offload_req");
        _qdf_mem_free(v41);
      }
      else
      {
        v42 = 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: send_gtk_offload_req is null",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "pmo_tgt_send_gtk_offload_req");
      v42 = 29;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to find psoc from from vdev:%pK",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_tgt_send_gtk_offload_req",
      a1);
    v42 = 4;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v33, v34, v35, v36, v37, v38, v39, v40, "pmo_tgt_send_gtk_offload_req");
  return v42;
}
