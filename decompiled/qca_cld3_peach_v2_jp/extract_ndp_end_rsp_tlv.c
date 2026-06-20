__int64 __fastcall extract_ndp_end_rsp_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x21
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v11 = *(_DWORD **)a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: WMI_NDP_END_RSP_EVENTID(0x%X) received. transaction_id: %d, rsp_status: %d, reason_code: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "extract_ndp_end_rsp_tlv",
    229380,
    *(unsigned int *)(*(_QWORD *)a2 + 4LL),
    *(unsigned int *)(*(_QWORD *)a2 + 8LL),
    *(unsigned int *)(*(_QWORD *)a2 + 12LL));
  v14 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(
          **(_QWORD **)(a1 + 760),
          11,
          20);
  *(_QWORD *)a3 = v14;
  if ( v14 )
  {
    *(_DWORD *)(a3 + 8) = v11[1];
    *(_DWORD *)(a3 + 16) = v11[3];
    *(_DWORD *)(a3 + 12) = v11[2];
    return 0;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: vdev is null", v15, v16, v17, v18, v19, v20, v21, v22, "extract_ndp_end_rsp_tlv");
    return 4;
  }
}
