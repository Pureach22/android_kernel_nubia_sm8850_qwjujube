__int64 __fastcall reg_process_ch_avoid_event(__int64 a1, unsigned int *a2)
{
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  const char *v14; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x24
  unsigned int *v26; // x25
  _DWORD *v27; // x26
  unsigned int v28; // w8
  unsigned int ref; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  unsigned int v39; // w20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v14 = "%s: reg psoc private obj is NULL";
    goto LABEL_5;
  }
  v13 = psoc_obj;
  if ( (reg_check_coex_unsafe_nb_user_prefer(a1) & 1) != 0 )
  {
    v14 = "%s: skipping LTE Coex unsafe channel change";
LABEL_5:
    qdf_trace_msg(0x51u, 2u, v14, v5, v6, v7, v8, v9, v10, v11, v12, "reg_process_ch_avoid_event");
    return 16;
  }
  if ( !*(_DWORD *)(v13 + 93084) )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: skipping all LTE Coex unsafe channel range",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "reg_process_ch_avoid_event");
    return 0;
  }
  qdf_trace_msg(0x51u, 8u, "%s: band count %d", v5, v6, v7, v8, v9, v10, v11, v12, "reg_process_ch_avoid_event", *a2);
  qdf_mem_set((void *)(v13 + 92404), 0x2A8u, 0);
  qdf_mem_set((void *)(v13 + 91684), 0x2D0u, 0);
  LODWORD(v24) = *a2;
  if ( *a2 )
  {
    v25 = 0;
    v26 = a2 + 1;
    v27 = (_DWORD *)(v13 + 92412);
    do
    {
      if ( *(_DWORD *)(v13 + 93084) == 2 )
      {
        if ( v25 >= 0x2A )
          goto LABEL_23;
        v28 = *v26;
        if ( *v26 >= *(_DWORD *)(channel_map + 168) && v28 <= *(_DWORD *)(channel_map + 492) )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: skipping 5Ghz LTE Coex unsafe channel range",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "reg_process_ch_avoid_event");
          goto LABEL_11;
        }
      }
      else
      {
        if ( v25 > 0x29 )
        {
LABEL_23:
          __break(0x5512u);
          JUMPOUT(0x1FAF1C);
        }
        v28 = *v26;
      }
      *(v27 - 1) = v28;
      *v27 = v26[1];
LABEL_11:
      v24 = *a2;
      ++v25;
      v26 += 4;
      v27 += 4;
    }
    while ( v25 < v24 );
  }
  *(_DWORD *)(v13 + 92404) = v24;
  *(_BYTE *)(v13 + 91680) = 1;
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0x16u, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( ref )
  {
    v38 = ref;
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: error taking psoc ref cnt",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "reg_process_ch_avoid_event");
    return v38;
  }
  else
  {
    v39 = wlan_objmgr_iterate_obj_list(a1, 1, reg_update_unsafe_ch, 0, 1, 0x16u);
    wlan_objmgr_psoc_release_ref(a1, 0x16u, v40, v41, v42, v43, v44, v45, v46, v47);
    return v39;
  }
}
