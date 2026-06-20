__int64 __fastcall nan_is_enable_allowed(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w0

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: nan psoc priv object is NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "nan_get_discovery_state");
LABEL_8:
      v23 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
              a1,
              5,
              a2,
              3,
              0,
              a3);
      return v23 & 1;
    }
    if ( !*(_DWORD *)(comp_private_obj + 272) )
      goto LABEL_8;
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc object object is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "nan_is_enable_allowed");
  }
  v23 = 0;
  return v23 & 1;
}
