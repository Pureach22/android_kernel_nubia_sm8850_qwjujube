__int64 __fastcall pmo_tgt_psoc_send_wow_enable_req(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 (__fastcall *v14)(_QWORD); // x20
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  const char *v17; // x2

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v5 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( *(_DWORD *)(comp_private_obj + 492) == 1 )
  {
    v14 = *(__int64 (__fastcall **)(_QWORD))(v5 + 440);
    if ( v14 )
    {
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Sending D0WOW enable command...",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "pmo_tgt_psoc_send_wow_enable_req");
      if ( *((_DWORD *)v14 - 1) != -770124015 )
        __break(0x8234u);
      return v14(a1);
    }
    v17 = "%s: psoc_send_d0wow_enable_req is null";
LABEL_12:
    qdf_trace_msg(0x4Du, 2u, v17, v6, v7, v8, v9, v10, v11, v12, v13, "pmo_tgt_psoc_send_wow_enable_req");
    return 29;
  }
  v16 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 392);
  if ( !v16 )
  {
    v17 = "%s: psoc_send_wow_enable_req is null";
    goto LABEL_12;
  }
  if ( *((_DWORD *)v16 - 1) != 130095212 )
    __break(0x8228u);
  return v16(a1, a2);
}
