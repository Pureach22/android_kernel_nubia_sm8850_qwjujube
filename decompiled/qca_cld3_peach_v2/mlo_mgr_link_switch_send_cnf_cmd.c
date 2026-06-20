__int64 __fastcall mlo_mgr_link_switch_send_cnf_cmd(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v12; // x5
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 (__fastcall *v22)(__int64, unsigned int *); // x8
  unsigned int v23; // w19
  const char *v24; // x2

  if ( a2[1] )
    v12 = "fail";
  else
    v12 = "success";
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: VDEV %d link switch completed, %s",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "mlo_mgr_link_switch_send_cnf_cmd",
    *a2,
    v12);
  v21 = *(_QWORD *)(a1 + 2128);
  if ( v21 == -1984 || (v22 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v21 + 2048)) == nullptr )
  {
    v23 = 4;
    v24 = "%s: handler is not registered";
    goto LABEL_11;
  }
  if ( *((_DWORD *)v22 - 1) != 1127800684 )
    __break(0x8228u);
  v23 = v22(a1, a2);
  if ( v23 )
  {
    v24 = "%s: Link switch status update to FW failed";
LABEL_11:
    qdf_trace_msg(0x8Fu, 2u, v24, v13, v14, v15, v16, v17, v18, v19, v20, "mlo_mgr_link_switch_send_cnf_cmd");
  }
  return v23;
}
