__int64 __fastcall pmo_core_psoc_wakeup_host_event_received(
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
  __int64 comp_private_obj; // x0
  __int64 v10; // x1

  if ( !a1 )
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: psoc is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "pmo_core_psoc_wakeup_host_event_received");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  *(_DWORD *)(comp_private_obj + 492) = 0;
  return qdf_event_set(comp_private_obj + 536, v10);
}
