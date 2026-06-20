__int64 __fastcall target_if_nan_event_flush_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x8

  if ( a1 && (v9 = *(__int64 **)(a1 + 8)) != nullptr )
  {
    wlan_objmgr_psoc_release_ref(*v9, 0x14u, a2, a3, a4, a5, a6, a7, a8, a9);
    _qdf_mem_free(*(_QWORD *)(a1 + 8));
    *(_QWORD *)(a1 + 8) = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Empty message for NAN Discovery event",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_nan_event_flush_cb");
    return 4;
  }
}
