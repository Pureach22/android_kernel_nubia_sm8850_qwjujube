__int64 __fastcall lim_del_peer_info(
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
  __int64 **context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 **v21; // x21
  __int64 v22; // x8
  __int64 (*v23)(void); // x8
  char v24; // w22
  __int64 v25; // x8
  __int64 v26; // x23
  unsigned __int16 i; // w24
  const char *v28; // x3
  __int64 hash_entry; // x0
  __int64 v30; // x27
  _QWORD *peer_by_mac; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x28
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  void (__fastcall *v50)(__int64 **, __int64, __int64); // x8
  __int64 v51; // x1
  __int64 v52; // x1
  __int64 v53; // x8
  void (__fastcall *v54)(__int64 **, __int64, __int64, __int64 (__fastcall *)(), __int64); // x8
  __int64 v55; // x2
  __int64 **v56; // x0
  __int64 (__fastcall *v57)(); // x3
  __int64 v58; // x8

  context = (__int64 **)_cds_get_context(71, (__int64)"lim_del_peer_info", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = context;
  if ( !context || !*context )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: invalid instance",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cdp_cfg_get_peer_unmap_conf_support");
LABEL_9:
    v24 = 0;
    goto LABEL_10;
  }
  v22 = (*context)[13];
  if ( !v22 )
    goto LABEL_9;
  v23 = *(__int64 (**)(void))(v22 + 96);
  if ( !v23 )
    goto LABEL_9;
  if ( *((_DWORD *)v23 - 1) != 799902358 )
    __break(0x8228u);
  v24 = v23();
LABEL_10:
  v25 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 216LL);
  if ( !v25 )
    return 16;
  v26 = *(_QWORD *)(v25 + 80);
  if ( !v26 )
    return 16;
  if ( *(_WORD *)(a2 + 376) )
  {
    for ( i = 0; *(unsigned __int16 *)(a2 + 376) > (unsigned int)i; ++i )
    {
      hash_entry = dph_get_hash_entry(a1, i, a2 + 360);
      if ( !hash_entry )
        continue;
      v30 = hash_entry;
      peer_by_mac = wlan_objmgr_get_peer_by_mac(v26, (_BYTE *)(hash_entry + 350), 7u);
      if ( peer_by_mac )
      {
        v40 = (__int64)peer_by_mac;
        v41 = wma_peer_tbl_trans_add_entry(peer_by_mac, 0, 0);
        wlan_objmgr_peer_release_ref(v40, 7u, v41, v42, v43, v44, v45, v46, v47, v48);
      }
      if ( v21 && *v21 )
      {
        v49 = **v21;
        if ( v49 )
        {
          v50 = *(void (__fastcall **)(__int64 **, __int64, __int64))(v49 + 96);
          if ( v50 )
          {
            v51 = *(unsigned __int8 *)(a2 + 10);
            if ( *((_DWORD *)v50 - 1) != -612755781 )
              __break(0x8228u);
            v50(v21, v51, v30 + 350);
          }
        }
        v52 = *(unsigned __int8 *)(a2 + 10);
        if ( (v24 & 1) == 0 )
        {
LABEL_36:
          if ( v21 && *v21 )
          {
            v58 = **v21;
            if ( !v58 )
              continue;
            v54 = *(void (__fastcall **)(__int64 **, __int64, __int64, __int64 (__fastcall *)(), __int64))(v58 + 160);
            if ( !v54 )
              continue;
            v55 = v30 + 350;
            v56 = v21;
            v57 = (__int64 (__fastcall *)())(&off_0 + 1);
            if ( *((_DWORD *)v54 - 1) != -175540032 )
              __break(0x8228u);
LABEL_34:
            v54(v56, v52, v55, v57, 1);
            continue;
          }
          v28 = "cdp_peer_delete";
          goto LABEL_15;
        }
      }
      else
      {
        qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v32, v33, v34, v35, v36, v37, v38, v39, "cdp_peer_teardown");
        v52 = *(unsigned __int8 *)(a2 + 10);
        if ( (v24 & 1) == 0 )
          goto LABEL_36;
      }
      if ( v21 && *v21 )
      {
        v53 = **v21;
        if ( !v53 )
          continue;
        v54 = *(void (__fastcall **)(__int64 **, __int64, __int64, __int64 (__fastcall *)(), __int64))(v53 + 176);
        if ( !v54 )
          continue;
        v55 = v30 + 350;
        v56 = v21;
        v57 = wma_peer_unmap_conf_cb;
        if ( *((_DWORD *)v54 - 1) != 2049932883 )
          __break(0x8228u);
        goto LABEL_34;
      }
      v28 = "cdp_peer_delete_sync";
LABEL_15:
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v32, v33, v34, v35, v36, v37, v38, v39, v28);
    }
  }
  return 0;
}
