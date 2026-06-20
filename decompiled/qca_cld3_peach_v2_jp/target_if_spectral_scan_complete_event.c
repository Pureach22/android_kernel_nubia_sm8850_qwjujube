__int64 __fastcall target_if_spectral_scan_complete_event(
        __int64 *a1,
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
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 v24; // x20
  const char *v25; // x2

  if ( !a1 )
  {
    v24 = jiffies;
    if ( target_if_spectral_scan_complete_event___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: target if spectral object is null",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_spectral_scan_complete_event");
      target_if_spectral_scan_complete_event___last_ticks = v24;
    }
    return 29;
  }
  v10 = *a1;
  if ( !v10 )
  {
    v25 = "%s: pdev object is NULL";
LABEL_18:
    qdf_trace_msg(0x56u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_spectral_scan_complete_event");
    return 29;
  }
  v11 = *(_QWORD *)(v10 + 80);
  if ( !v11 )
  {
    v25 = "%s: psoc is null";
    goto LABEL_18;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    v25 = "%s: rx_ops is null";
    goto LABEL_18;
  }
  if ( !a2 )
  {
    v25 = "%s: spectral event is null";
    goto LABEL_18;
  }
  v13 = *(__int64 (**)(void))(v12 + 320);
  if ( *((_DWORD *)v13 - 1) != -1923167218 )
    __break(0x8228u);
  result = v13();
  if ( (_DWORD)result )
  {
    v23 = jiffies;
    if ( target_if_spectral_scan_complete_event___last_ticks_64 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Failed to notify userspace about scan completion.",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "target_if_spectral_scan_complete_event");
      target_if_spectral_scan_complete_event___last_ticks_64 = v23;
    }
    return 16;
  }
  return result;
}
