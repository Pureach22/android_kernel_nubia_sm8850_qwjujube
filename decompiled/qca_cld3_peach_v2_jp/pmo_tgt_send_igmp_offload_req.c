__int64 __fastcall pmo_tgt_send_igmp_offload_req(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v4 = *(__int64 (__fastcall **)(__int64, __int64))(wlan_objmgr_psoc_get_comp_private_obj(
                                                      *(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL),
                                                      4u)
                                                  + 336);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != 851403317 )
      __break(0x8228u);
    return v4(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_vdev_param_set_req is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "pmo_tgt_send_igmp_offload_req");
    return 29;
  }
}
