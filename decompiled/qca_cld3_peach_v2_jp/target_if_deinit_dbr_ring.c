__int64 __fastcall target_if_deinit_dbr_ring(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w23
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x9
  __int64 v27; // x19
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x20
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x0
  __int64 comp_private_obj; // x0
  __int64 *v63; // x21
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x26
  _DWORD *v73; // x22
  __int64 v74; // x23
  __int64 v75; // x24
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned __int64 v84; // x27
  __int64 *v85; // x28
  __int64 v86; // x20
  __int64 v87; // x24
  __int64 v88; // x25
  __int64 v89; // t1
  __int64 result; // x0
  const char *v91; // x2
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // [xsp+8h] [xbp-8h]

  v16 = a4;
  v17 = qdf_trace_msg(0x5Bu, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "target_if_deinit_dbr_ring");
  if ( v16 >= 3 )
  {
    __break(0x5512u);
    v94 = MEMORY[0x3F63BA0](v17);
    return target_if_direct_buf_rx_psoc_create_handler(v94);
  }
  v26 = *(_QWORD *)(a2 + 8) + 112LL * a3;
  v27 = v26 + 56LL * a4;
  if ( !v27 )
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: dir buf rx module param is null",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_deinit_dbr_ring");
    return 16;
  }
  qdf_trace_msg(
    0x5Bu,
    8u,
    "%s: mod_param %pK, dbr_ring_cap %pK",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "target_if_deinit_dbr_ring",
    v26 + 56LL * a4,
    *(_QWORD *)(v27 + 16));
  if ( (*(_BYTE *)(v27 + 48) & 1) == 0 )
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: module(%d) srng(%d) was not initialized",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "target_if_deinit_dbr_ring",
      a3,
      a4);
    return 0;
  }
  qdf_trace_msg(0x5Bu, 8u, "%s: enter", v28, v29, v30, v31, v32, v33, v34, v35, "target_if_dbr_deinit_srng");
  v36 = *(_QWORD *)(v27 + 32);
  qdf_trace_msg(
    0x5Bu,
    8u,
    "%s: dbr buf pool %pK",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "target_if_dbr_deinit_srng",
    v36);
  qdf_trace_msg(0x5Bu, 8u, "%s: enter", v45, v46, v47, v48, v49, v50, v51, v52, "target_if_dbr_deinit_ring");
  v61 = *(_QWORD *)(a1 + 80);
  if ( v61 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v61, 8u);
    if ( comp_private_obj )
    {
      v63 = (__int64 *)comp_private_obj;
      qdf_trace_msg(
        0x5Bu,
        8u,
        "%s: dbr_psoc_obj %pK",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "target_if_dbr_deinit_ring",
        comp_private_obj);
      v72 = *(_QWORD *)(v27 + 24);
      if ( v72 )
      {
        v95 = v36;
        qdf_trace_msg(0x5Bu, 8u, "%s: enter", v64, v65, v66, v67, v68, v69, v70, v71, "target_if_dbr_empty_ring");
        v74 = *(_QWORD *)(v27 + 16);
        v73 = *(_DWORD **)(v27 + 24);
        v75 = *(_QWORD *)(v27 + 32);
        qdf_trace_msg(
          0x5Bu,
          8u,
          "%s: dbr_ring_cfg %pK, ring_cap %pK buf_pool %pK",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "target_if_dbr_empty_ring",
          v73,
          v74,
          v75);
        if ( *v73 != 1 )
        {
          v84 = 0;
          v85 = (__int64 *)(v75 + 16);
          do
          {
            v86 = v63[1];
            v87 = *(v85 - 1);
            v88 = *(int *)(v74 + 4);
            qdf_mem_dp_rx_skb_cnt_dec();
            qdf_mem_dp_rx_skb_dec(v88);
            qdf_mem_skb_total_dec(v88);
            dma_unmap_page_attrs(*(_QWORD *)(v86 + 40), v87, v88, 2, 0);
            v89 = *v85;
            v85 += 4;
            _qdf_mem_free(v89);
            ++v84;
          }
          while ( v84 < (unsigned int)(*v73 - 1) );
        }
        hal_srng_cleanup(*v63, *(_QWORD *)(v72 + 56), 0);
        _qdf_mem_free_consistent(v63[1], *(_QWORD *)(v63[1] + 40), *(_DWORD *)(v72 + 4));
        v36 = v95;
      }
      goto LABEL_16;
    }
    v91 = "%s: dir buf rx psoc object is null";
  }
  else
  {
    v91 = "%s: psoc is null";
  }
  qdf_trace_msg(0x5Bu, 2u, v91, v53, v54, v55, v56, v57, v58, v59, v60, "target_if_dbr_deinit_ring");
LABEL_16:
  if ( *(_QWORD *)(v27 + 32) )
    _qdf_mem_free(v36);
  v92 = *(_QWORD *)(v27 + 16);
  *(_QWORD *)(v27 + 32) = 0;
  if ( v92 )
    _qdf_mem_free(v92);
  v93 = *(_QWORD *)(v27 + 24);
  *(_QWORD *)(v27 + 16) = 0;
  if ( v93 )
    _qdf_mem_free(v93);
  result = 0;
  *(_QWORD *)(v27 + 24) = 0;
  *(_BYTE *)(v27 + 48) = 0;
  return result;
}
