__int64 __fastcall tdls_add_peer(__int64 *a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x19
  __int64 comp_private_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  __int64 v26; // x21
  __int64 *v27; // x25
  char opclass_from_bandwidth; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  const char *v41; // x2
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int8 *v50; // x1
  unsigned __int8 *v51; // x21
  __int64 v52; // x21
  char v53[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD *v54[2]; // [xsp+10h] [xbp-10h] BYREF

  v54[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v53[0] = 0;
  result = _qdf_mem_malloc(0x2C0u, "tdls_add_peer", 267);
  if ( !result )
    goto LABEL_14;
  if ( !*a1 )
  {
    v41 = "%s: NULL vdev";
    goto LABEL_11;
  }
  v13 = *(_QWORD *)(*a1 + 152);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    v41 = "%s: can't get psoc";
LABEL_11:
    qdf_trace_msg(0, 2u, v41, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_12;
  }
  v15 = result;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v14, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_12:
    qdf_trace_msg(0, 2u, "%s: NULL tdls soc object", v17, v18, v19, v20, v21, v22, v23, v24, "tdls_add_peer");
    goto LABEL_13;
  }
  v25 = comp_private_obj;
  v26 = ((unsigned __int8)(a2[1] ^ *a2 ^ a2[2] ^ a2[3]) ^ (unsigned __int8)(a2[4] ^ a2[5])) & 0xF;
  v27 = &a1[3 * v26];
  qdf_mem_copy((void *)(v15 + 24), a2, 6u);
  *(_QWORD *)(v15 + 16) = a1;
  tdls_fill_pref_off_chan_info(a1, v25, v15);
  opclass_from_bandwidth = tdls_get_opclass_from_bandwidth(
                             *a1,
                             *(unsigned int *)(v15 + 492),
                             *(_BYTE *)(v15 + 496),
                             v53);
  *(_BYTE *)(v15 + 30) = 0;
  *(_BYTE *)(v15 + 490) = opclass_from_bandwidth;
  if ( *((_DWORD *)v27 + 6) >= *((_DWORD *)v27 + 7) )
  {
    v54[0] = nullptr;
    if ( !(unsigned int)qdf_list_peek_front(v27 + 1, v54) )
    {
      while ( 1 )
      {
        v50 = (unsigned __int8 *)v54[0];
        if ( v54[0] )
        {
          if ( !*((_DWORD *)v54[0] + 9) )
            break;
        }
        if ( (unsigned int)qdf_list_peek_next(v27 + 1, v54[0], v54) )
          goto LABEL_16;
      }
      if ( *((_BYTE *)v54[0] + 672) == 1 )
      {
        v51 = (unsigned __int8 *)v54[0];
        qdf_trace_msg(
          0,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x: destroy  idle timer ",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "tdls_remove_first_idle_peer",
          *((unsigned __int8 *)v54[0] + 24),
          *((unsigned __int8 *)v54[0] + 25),
          *((unsigned __int8 *)v54[0] + 26),
          *((unsigned __int8 *)v54[0] + 29));
        qdf_mc_timer_stop((__int64)(v51 + 504));
        qdf_mc_timer_destroy((__int64)(v51 + 504));
        v50 = v51;
      }
      v52 = (__int64)v50;
      qdf_trace_msg(
        0,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x: free peer",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "tdls_remove_first_idle_peer",
        v50[24],
        v50[25],
        v50[26],
        v50[29]);
      qdf_list_remove_node((__int64)(v27 + 1), v54[0]);
      _qdf_mem_free(v52);
      goto LABEL_7;
    }
LABEL_16:
    qdf_trace_msg(
      0,
      2u,
      "%s: list size exceed max and remove idle peer failed, key %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "tdls_add_peer",
      (unsigned int)v26);
    _qdf_mem_free(v15);
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
LABEL_7:
  qdf_list_insert_back(v27 + 1, (_QWORD *)v15);
  if ( a2 )
  {
    v37 = *a2;
    v38 = a2[1];
    v39 = a2[2];
    v40 = a2[5];
  }
  else
  {
    v39 = 0;
    v37 = 0;
    v38 = 0;
    v40 = 0;
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: add tdls peer: %02x:%02x:%02x:**:**:%02x",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "tdls_add_peer",
    v37,
    v38,
    v39,
    v40);
  result = v15;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
