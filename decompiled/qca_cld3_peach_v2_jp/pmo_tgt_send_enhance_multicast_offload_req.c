__int64 __fastcall pmo_tgt_send_enhance_multicast_offload_req(__int64 a1, char a2)
{
  __int64 (__fastcall *v4)(__int64, bool); // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  const char *v14; // x2

  v4 = *(__int64 (__fastcall **)(__int64, bool))(wlan_objmgr_psoc_get_comp_private_obj(
                                                   *(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL),
                                                   4u)
                                               + 200);
  if ( !v4 )
  {
    v13 = 29;
    v14 = "%s: send_enhance_multicast_offload is null";
    goto LABEL_7;
  }
  if ( *((_DWORD *)v4 - 1) != -988222069 )
    __break(0x8228u);
  v13 = v4(a1, a2 != 0);
  if ( v13 )
  {
    v14 = "%s: Failed to config enhance multicast offload";
LABEL_7:
    qdf_trace_msg(0x4Du, 2u, v14, v5, v6, v7, v8, v9, v10, v11, v12, "pmo_tgt_send_enhance_multicast_offload_req");
  }
  return v13;
}
