__int64 __fastcall target_if_tdls_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x20
  const char *v23; // x2
  __int64 result; // x0
  _DWORD *v25; // x8
  _QWORD v26[3]; // [xsp+8h] [xbp-18h] BYREF

  v26[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  v26[1] = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_tdls_event_handler",
      a1,
      a2);
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v23 = "%s: null psoc";
    goto LABEL_11;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    v23 = "%s: null wmi_handle";
    goto LABEL_11;
  }
  v22 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_vdev_tdls_ev_param(v21, a2, v26) )
  {
    v23 = "%s: Failed to extract wmi tdls event";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v23, v12, v13, v14, v15, v16, v17, v18, v19, "target_if_tdls_event_handler");
    goto LABEL_12;
  }
  if ( *(_QWORD *)(v22 + 2136) == -1064 || (v25 = *(_DWORD **)(*(_QWORD *)(v22 + 2136) + 1064LL)) == nullptr )
  {
    result = 0;
    goto LABEL_13;
  }
  if ( *(v25 - 1) != -1883272899 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *))v25)(v22, v26);
  if ( (_DWORD)result )
  {
    v23 = "%s: fail to handle tdls event";
    goto LABEL_11;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
