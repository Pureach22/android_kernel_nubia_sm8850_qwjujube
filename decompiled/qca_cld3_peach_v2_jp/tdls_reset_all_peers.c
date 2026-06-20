__int64 __fastcall tdls_reset_all_peers(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  unsigned __int8 *v21; // x21
  __int64 v22; // x0
  __int64 all_peer; // x0
  unsigned int *v24; // x8
  __int64 v25; // x22
  int v26; // w26
  char *v27; // x23
  __int64 v28; // x24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v39; // x28
  unsigned __int8 *v40; // x27
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+0h] [xbp-10h]

  if ( !a1 || (v10 = *a1) == 0 )
  {
    qdf_trace_msg(0, 2u, "%s: invalid param", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_reset_all_peers");
    return _qdf_mem_free((__int64)a1);
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*a1, 0xAu);
  if ( !comp_private_obj )
    goto LABEL_12;
  v20 = *(_QWORD *)(v10 + 152);
  if ( !v20 || (v21 = (unsigned __int8 *)comp_private_obj, (v22 = *(_QWORD *)(v20 + 80)) == 0) )
  {
    qdf_trace_msg(0, 2u, "%s: can't get psoc", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_vdev_get_tdls_soc_obj");
LABEL_12:
    qdf_trace_msg(
      0,
      2u,
      "%s: tdls objects are NULL ",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tdls_process_reset_all_peers");
    goto LABEL_13;
  }
  all_peer = wlan_objmgr_psoc_get_comp_private_obj(v22, 0xAu);
  if ( !all_peer || (*(_DWORD *)(v10 + 16) & 0xFFFFFFFD) != 0 )
    goto LABEL_12;
  v24 = (unsigned int *)*(unsigned __int16 *)(all_peer + 200);
  v25 = all_peer;
  if ( !*(_WORD *)(all_peer + 200) )
  {
LABEL_13:
    wlan_objmgr_vdev_release_ref(*a1, 0x10u, v24, v12, v13, v14, v15, v16, v17, v18, v19);
    return _qdf_mem_free((__int64)a1);
  }
  v26 = v21[968];
  v27 = (char *)(all_peer + 35);
  v28 = 1;
  while ( v28 != 9 )
  {
    if ( *(v27 - 2) == 1 && (unsigned __int8)*(v27 - 3) == v26 )
    {
      all_peer = tdls_find_all_peer(v25, v27);
      if ( all_peer )
      {
        v39 = all_peer + 24;
        v40 = (unsigned __int8 *)all_peer;
        LODWORD(v57) = *(unsigned __int8 *)(all_peer + 29);
        qdf_trace_msg(
          0,
          4u,
          "%s: vdev %d indicate TDLS teardown %02x:%02x:%02x:**:**:%02x",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "tdls_process_reset_all_peers",
          *(unsigned __int8 *)(*(_QWORD *)v21 + 104LL),
          *(unsigned __int8 *)(all_peer + 24),
          *(unsigned __int8 *)(all_peer + 25),
          *(unsigned __int8 *)(all_peer + 26),
          v57);
        if ( (unsigned int)tdls_indicate_teardown((__int64 *)v21, v40, 0x1Au, v41, v42, v43, v44, v45, v46, v47, v48) )
        {
          LODWORD(v57) = v40[29];
          all_peer = qdf_trace_msg(
                       0,
                       2u,
                       "%s: vdev %d teardown indication failed for peer %02x:%02x:%02x:**:**:%02x",
                       v49,
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       v55,
                       v56,
                       "tdls_process_reset_all_peers",
                       *(unsigned __int8 *)(*(_QWORD *)v21 + 104LL),
                       v40[24],
                       v40[25],
                       v40[26],
                       v57);
        }
        else
        {
          tdls_reset_peer(v21, v39);
          tdls_decrement_peer_count(v10, v25, v30, v31, v32, v33, v34, v35, v36, v37);
          *(_WORD *)(v27 - 3) = 255;
          *(v27 - 1) = -1;
          all_peer = (__int64)qdf_mem_set(v27, 6u, 0);
        }
      }
    }
    v24 = (unsigned int *)*(unsigned __int16 *)(v25 + 200);
    v27 += 9;
    if ( (unsigned int)v24 <= (unsigned __int16)v28++ )
      goto LABEL_13;
  }
  __break(0x5512u);
  return tdls_handle_link_unforce(all_peer);
}
