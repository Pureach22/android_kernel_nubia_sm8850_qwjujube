__int64 __fastcall tdls_process_enable_link(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
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
  __int64 v21; // x22
  __int64 v22; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x5
  __int64 v33; // x21
  __int64 peer; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  __int64 v47; // x22
  __int64 v48; // x8
  int v49; // w9
  __int64 v50; // x0
  __int64 (__fastcall *v51)(__int64, __int64, __int64, __int64); // x9
  __int64 v52; // x1
  __int64 v53; // x3
  unsigned int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w23
  unsigned int *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  const char *v74; // x2
  __int64 v75; // x0
  __int64 v76; // x23
  __int64 v77; // x4
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x0
  void (__fastcall *v95)(_QWORD); // x8
  void (__fastcall *v96)(__int64, __int64, __int64, _BOOL8); // x8
  int v97; // w23
  __int64 v98; // x2
  __int64 v99; // x1
  _BOOL8 v100; // x3

  v9 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev object", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_enable_link");
    v63 = 29;
    goto LABEL_20;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu);
  v20 = *(_QWORD *)(v9 + 152);
  v21 = comp_private_obj;
  if ( !v20 || (v22 = *(_QWORD *)(v20 + 80)) == 0 )
  {
    qdf_trace_msg(0, 2u, "%s: can't get psoc", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_vdev_get_tdls_soc_obj");
    v32 = 0;
LABEL_17:
    qdf_trace_msg(
      0,
      2u,
      "%s: tdls vdev_obj: %pK soc_obj: %pK",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "tdls_process_enable_link",
      v21,
      v32);
    v63 = 29;
    goto LABEL_18;
  }
  v23 = wlan_objmgr_psoc_get_comp_private_obj(v22, 0xAu);
  v32 = v23;
  if ( !v21 || !v23 )
    goto LABEL_17;
  v33 = v23;
  peer = tdls_find_peer(v21, a1 + 8);
  v43 = *(unsigned __int8 *)(a1 + 8);
  v44 = *(unsigned __int8 *)(a1 + 9);
  v45 = *(unsigned __int8 *)(a1 + 10);
  v46 = *(unsigned __int8 *)(a1 + 13);
  if ( peer )
  {
    v47 = peer;
    qdf_trace_msg(
      0,
      8u,
      "%s: enable link for peer %02x:%02x:%02x:**:**:%02x link state %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "tdls_process_enable_link",
      v43,
      v44,
      v45,
      v46,
      *(_DWORD *)(peer + 36));
    if ( (*(_BYTE *)(v47 + 30) & 1) != 0 )
    {
      v48 = v33;
      if ( *(_WORD *)(v33 + 202) == 1 )
      {
        tdls_set_tdls_offchannelmode(v9, 2);
        v48 = v33;
      }
      v49 = *(_DWORD *)(v47 + 36);
      *(_DWORD *)(v47 + 32) = 1;
      if ( v49 != 4 )
      {
        tdls_set_peer_link_status(v47, 4, 0);
        v48 = v33;
      }
      v50 = *(_QWORD *)(v48 + 280);
      v51 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v48 + 288);
      v52 = *(unsigned __int8 *)(v9 + 104);
      v53 = *(unsigned __int8 *)(v47 + 688);
      if ( *((_DWORD *)v51 - 1) != 877836948 )
        __break(0x8229u);
      v54 = v51(v50, v52, a1 + 8, v53);
      if ( v54 )
      {
        v63 = v54;
        qdf_trace_msg(
          0,
          2u,
          "%s: TDLS register peer fail, status %d",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "tdls_process_enable_link",
          v54);
      }
      else
      {
        v75 = _qdf_mem_malloc(0x444u, "tdls_process_enable_link", 1960);
        if ( v75 )
        {
          v76 = v75;
          tdls_extract_peer_state_param(v75, v47);
          if ( (unsigned int)tdls_wma_update_peer_state(v33, v76) )
          {
            _qdf_mem_free(v76);
            v63 = 12;
          }
          else
          {
            tdls_update_6g_power(v9, v33, 1);
            v77 = (unsigned __int16)++*(_WORD *)(v33 + 202);
            qdf_trace_msg(
              0,
              8u,
              "%s: Connected peer count %d",
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              "tdls_increment_peer_count",
              v77);
            v94 = v33;
            if ( *(_WORD *)(v33 + 202) == 1 )
            {
              v95 = *(void (__fastcall **)(_QWORD))(v33 + 600);
              if ( v95 )
              {
                if ( *((_DWORD *)v95 - 1) != 1458356883 )
                  __break(0x8228u);
                v95(v9);
                v94 = v33;
              }
            }
            v96 = *(void (__fastcall **)(__int64, __int64, __int64, _BOOL8))(v94 + 296);
            v97 = *(_DWORD *)(v94 + 156);
            if ( v96 )
            {
              v98 = *(unsigned int *)(v94 + 344);
              v99 = *(unsigned __int8 *)(v9 + 104);
              v100 = *(_DWORD *)(v47 + 36) == 4;
              if ( *((_DWORD *)v96 - 1) != 792568820 )
                __break(0x8228u);
              v96(v94, v99, v98, v100);
              v94 = v33;
            }
            qdf_trace_msg(
              0,
              8u,
              "%s: TDLS buffer sta: %d, uapsd_mask %d",
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              "tdls_process_enable_link",
              v97 & 4,
              *(unsigned int *)(v94 + 140));
            v63 = 0;
          }
        }
        else
        {
          v63 = 2;
        }
      }
      goto LABEL_18;
    }
    v43 = *(unsigned __int8 *)(a1 + 8);
    v44 = *(unsigned __int8 *)(a1 + 9);
    v74 = "%s: invalid entry %02x:%02x:%02x:**:**:%02x";
    v45 = *(unsigned __int8 *)(a1 + 10);
    v46 = *(unsigned __int8 *)(a1 + 13);
  }
  else
  {
    v74 = "%s: %02x:%02x:%02x:**:**:%02x not found, ignore NL80211_TDLS_ENABLE_LINK";
  }
  qdf_trace_msg(0, 2u, v74, v35, v36, v37, v38, v39, v40, v41, v42, "tdls_process_enable_link", v43, v44, v45, v46);
  v63 = 4;
LABEL_18:
  wlan_objmgr_vdev_release_ref(v9, 0x11u, v64, v65, v66, v67, v68, v69, v70, v71, v72);
LABEL_20:
  _qdf_mem_free(a1);
  return v63;
}
