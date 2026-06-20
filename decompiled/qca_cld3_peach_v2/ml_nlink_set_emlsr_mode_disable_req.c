__int64 __fastcall ml_nlink_set_emlsr_mode_disable_req(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v12; // x8
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 && *(_QWORD *)(v10 + 2224) )
  {
    qdf_mutex_acquire(v10 + 1656);
    v12 = *(_QWORD *)(v10 + 2224);
    v13 = *(_DWORD *)(v12 + 1448);
    *(_DWORD *)(v12 + 1448) = v13 | a2;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: set disable_req to 0x%x from 0x%x by req 0x%x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "ml_nlink_set_emlsr_mode_disable_req");
    qdf_mutex_release(v10 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ml_nlink_set_emlsr_mode_disable_req");
    return 0;
  }
  return v13;
}
