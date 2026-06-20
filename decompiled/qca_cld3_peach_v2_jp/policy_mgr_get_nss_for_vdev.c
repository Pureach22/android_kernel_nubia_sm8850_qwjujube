__int64 __fastcall policy_mgr_get_nss_for_vdev(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v13; // w21
  __int64 context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x8
  const char *v26; // x2

  if ( a2 >= 7 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Unsupported policy mgr mode (%d)",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "policy_mgr_get_qdf_mode_from_pm",
      a2);
    return 16;
  }
  v13 = dword_9E73F8[a2];
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v26 = "%s: Invalid Context";
LABEL_10:
    qdf_trace_msg(0x4Fu, 2u, v26, v16, v17, v18, v19, v20, v21, v22, v23, "policy_mgr_get_nss_for_vdev");
    return 16;
  }
  v24 = *(_DWORD **)(context + 392);
  if ( !v24 )
  {
    v26 = "%s: sme_get_nss_for_vdev callback is NULL";
    goto LABEL_10;
  }
  if ( *(v24 - 1) != 724409125 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD, __int64, __int64))v24)(v13, a3, a4);
  return 0;
}
