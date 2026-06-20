__int64 __fastcall pmo_core_icmp_check_offload(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int *v12; // x8
  __int64 v13; // x19
  unsigned int v14; // w19

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
  if ( v3 )
  {
    v12 = (unsigned int *)*(unsigned int *)(v3 + 16);
    if ( (_DWORD)v12 )
    {
      v13 = v3;
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: ICMP offload is supported in STA mode only",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "pmo_core_icmp_check_offload");
      v3 = v13;
      v14 = 4;
    }
    else
    {
      v14 = 0;
    }
    wlan_objmgr_vdev_release_ref(v3, 0xAu, v12, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is NULL. vdev_id is %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "pmo_core_icmp_check_offload",
      v2);
    return 4;
  }
  return v14;
}
