__int64 __fastcall os_if_spectral_nl_unicast_msg(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v11; // x2
  const char *v12; // x2
  __int64 comp_private_obj; // x0
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w21

  if ( !a1 )
  {
    v12 = "%s: PDEV is NULL!";
LABEL_12:
    qdf_trace_msg(0x48u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_spectral_nl_unicast_msg");
    return 4294967274LL;
  }
  if ( a2 >= 3 )
  {
    v11 = "%s: Invalid Spectral message type %u";
LABEL_4:
    qdf_trace_msg(0x48u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "os_if_spectral_nl_unicast_msg", a2);
    return 4294967274LL;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x13u);
  if ( !comp_private_obj )
  {
    v12 = "%s: PDEV SPECTRAL object is NULL!";
    goto LABEL_12;
  }
  v14 = comp_private_obj + 24;
  v15 = *(_QWORD *)(comp_private_obj + 24 + 8LL * a2);
  if ( !v15 )
  {
    v11 = "%s: Socket buffer is null, msg_type= %u";
    goto LABEL_4;
  }
  *(_DWORD *)(v15 + 52) = 0;
  result = nl_srv_ucast(*(_QWORD *)(v14 + 8LL * a2), *(_DWORD *)(comp_private_obj + 48), 64, 0x1Du, 6u);
  if ( (result & 0x80000000) != 0 )
  {
    v25 = result;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: failed to send to spectral scan app",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "os_if_spectral_nl_unicast_msg");
    result = v25;
  }
  *(_QWORD *)(v14 + 8LL * a2) = 0;
  return result;
}
