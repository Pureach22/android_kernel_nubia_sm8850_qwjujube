void __fastcall lim_tear_down_link_with_ap(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 session_by_session_id; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 hash_entry; // x0
  const char *v18; // x2

  _ReadStatusReg(SP_EL0);
  session_by_session_id = pe_find_session_by_session_id(a1, a2);
  if ( session_by_session_id )
  {
    v16 = session_by_session_id;
    qdf_trace_msg(
      0x35u,
      4u,
      "%s: Session %d Vdev %d reason code %d trigger %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_tear_down_link_with_ap",
      *(unsigned __int16 *)(session_by_session_id + 8),
      *(unsigned __int8 *)(session_by_session_id + 10),
      a3,
      a4);
    if ( (lim_is_sb_disconnect_allowed_fl(v16, (__int64)"lim_tear_down_link_with_ap", 0x194u) & 1) == 0 )
      goto LABEL_9;
    *(_BYTE *)(v16 + 7279) = 0;
    lim_delete_tdls_peers(a1, v16, 0);
    hash_entry = dph_get_hash_entry(a1, 1u, v16 + 360);
    if ( !hash_entry )
      JUMPOUT(0x381988);
    if ( *(_DWORD *)(hash_entry + 24) != 3 && *(_WORD *)(hash_entry + 34) != 4 )
      JUMPOUT(0x3819C0);
    v18 = "%s: Host already issued deauth, do nothing";
  }
  else
  {
    v18 = "%s: Session Does not exist for given sessionID";
  }
  qdf_trace_msg(0x35u, 2u, v18, v8, v9, v10, v11, v12, v13, v14, v15, "lim_tear_down_link_with_ap");
LABEL_9:
  JUMPOUT(0x381958);
}
