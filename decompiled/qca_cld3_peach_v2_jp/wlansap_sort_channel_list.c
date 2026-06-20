__int64 __fastcall wlansap_sort_channel_list(
        unsigned __int8 a1,
        _QWORD *a2,
        _BYTE *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( context )
  {
    result = sap_sort_channel_list(
               (__int64)context,
               a1,
               a2,
               a3,
               nullptr,
               nullptr,
               a4 & 1,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: vdev %d failed to sort sap channel list",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlansap_sort_channel_list",
        a1);
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid MAC context",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlansap_sort_channel_list");
    return 29;
  }
  return result;
}
