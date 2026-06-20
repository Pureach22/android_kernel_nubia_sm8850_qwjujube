__int64 __fastcall pmo_tgt_psoc_send_host_wakeup_ind(__int64 a1)
{
  __int64 comp_private_obj; // x20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 (__fastcall *v12)(_QWORD); // x8
  __int64 (__fastcall *v13)(_QWORD); // x20
  const char *v15; // x2

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v3 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v12 = *(__int64 (__fastcall **)(_QWORD))(v3 + 424);
  if ( *(_BYTE *)(comp_private_obj + 15) == 1 && *(_DWORD *)(comp_private_obj + 492) == 1 )
  {
    v13 = *(__int64 (__fastcall **)(_QWORD))(v3 + 448);
    if ( v13 )
    {
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Sending D0WOW disable command...",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "pmo_tgt_psoc_send_host_wakeup_ind");
      if ( *((_DWORD *)v13 - 1) != -770124015 )
        __break(0x8234u);
      return v13(a1);
    }
    v15 = "%s: psoc_send_d0wow_disable_req is null";
LABEL_13:
    qdf_trace_msg(0x4Du, 2u, v15, v4, v5, v6, v7, v8, v9, v10, v11, "pmo_tgt_psoc_send_host_wakeup_ind");
    return 29;
  }
  if ( !v12 )
  {
    v15 = "%s: psoc_send_host_wakeup_ind is null";
    goto LABEL_13;
  }
  if ( *((_DWORD *)v12 - 1) != -770124015 )
    __break(0x8228u);
  return v12(a1);
}
