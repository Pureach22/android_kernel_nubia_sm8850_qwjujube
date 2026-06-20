__int64 __fastcall fwol_release_rx_event(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x19

  if ( !a1 )
    return qdf_trace_msg(0x66u, 2u, "%s: event is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "fwol_release_rx_event");
  if ( *a1 )
  {
    v9 = a1;
    wlan_objmgr_psoc_release_ref(*a1, 0x47u, a2, a3, a4, a5, a6, a7, a8, a9);
    a1 = v9;
  }
  return _qdf_mem_free((__int64)a1);
}
