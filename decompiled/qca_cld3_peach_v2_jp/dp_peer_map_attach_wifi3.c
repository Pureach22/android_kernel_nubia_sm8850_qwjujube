__int64 __fastcall dp_peer_map_attach_wifi3(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  __int64 v5; // x0
  unsigned int (__fastcall *v9)(_QWORD); // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w20
  void (__fastcall *v28)(_QWORD); // x8

  v5 = *(_QWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 13272) = a2;
  wlan_cfg_set_max_ast_idx(v5, a3);
  v9 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 1240);
  if ( *((_DWORD *)v9 - 1) != -1941278151 )
    __break(0x8228u);
  if ( v9(a1) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: failure in allocating peer tables",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_peer_map_attach_wifi3");
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: max_peers %u, calculated max_peers %u max_ast_index: %u",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_peer_map_attach_wifi3",
      a2,
      *(unsigned int *)(a1 + 13276),
      a3);
    result = dp_peer_find_attach(a1);
    if ( (_DWORD)result )
    {
      v27 = result;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Peer find attach failure",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "dp_peer_map_attach_wifi3");
      v28 = *(void (__fastcall **)(_QWORD))(a1 + 1248);
      if ( *((_DWORD *)v28 - 1) != -1093861181 )
        __break(0x8228u);
      v28(a1);
      return v27;
    }
    else
    {
      *(_BYTE *)(a1 + 18648) = a4;
      *(_BYTE *)(a1 + 18719) = 1;
    }
  }
  return result;
}
