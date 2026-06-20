unsigned __int8 *__fastcall hdd_set_disconnect_link_info_cb(
        unsigned __int8 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 *result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8

  context = _cds_get_context(51, (__int64)"hdd_set_disconnect_link_info_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return (unsigned __int8 *)qdf_trace_msg(
                                0x33u,
                                2u,
                                "%s: HDD CTX is NULL",
                                v13,
                                v14,
                                v15,
                                v16,
                                v17,
                                v18,
                                v19,
                                v20,
                                "hdd_set_disconnect_link_info_cb");
  result = (unsigned __int8 *)hdd_get_link_info_by_vdev((__int64)context, a1);
  if ( !result )
    return (unsigned __int8 *)qdf_trace_msg(
                                0x33u,
                                2u,
                                "%s: Link info is NULL for vdev_id %d",
                                v22,
                                v23,
                                v24,
                                v25,
                                v26,
                                v27,
                                v28,
                                v29,
                                "hdd_set_disconnect_link_info_cb",
                                a1);
  v30 = *(_QWORD *)result;
  if ( !*(_DWORD *)(*(_QWORD *)result + 40LL) && ((a2 & 1) != 0 || !*(_QWORD *)(v30 + 57440)) )
  {
    *(_QWORD *)(v30 + 57440) = result;
    return (unsigned __int8 *)qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: vdev_id %d is_disconnect_sent %d",
                                v22,
                                v23,
                                v24,
                                v25,
                                v26,
                                v27,
                                v28,
                                v29,
                                "hdd_set_disconnect_link_info_cb",
                                result[8],
                                a2 & 1);
  }
  return result;
}
