__int64 __fastcall extract_ndp_host_event_tlv(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v3 = *a2;
  v5 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         **(_QWORD **)(a1 + 760),
         *(unsigned int *)(*a2 + 4),
         20);
  *(_QWORD *)a3 = v5;
  if ( v5 )
  {
    *(_BYTE *)(a3 + 8) = *(_BYTE *)(v3 + 8) & 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: vdev is null", v6, v7, v8, v9, v10, v11, v12, v13, "extract_ndp_host_event_tlv");
    return 4;
  }
}
