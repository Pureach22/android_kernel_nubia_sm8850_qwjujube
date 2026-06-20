__int64 __fastcall hif_disable(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    qdf_hang_event_unregister_notifier(result + 3952);
    hif_nointrs(v1);
    if ( (*(_BYTE *)(v1 + 584) & 1) != 0 )
      hif_stop(v1);
    else
      hif_shutdown_device(v1);
    if ( (ce_srng_based(v1) & 1) != 0 )
    {
      hal_detach(*(_QWORD *)(v1 + 2560));
      *(_QWORD *)(v1 + 2560) = 0;
    }
    hif_disable_bus(v1);
    hif_wlan_disable(v1);
    *(_BYTE *)(v1 + 649) = 0;
    return qdf_trace_msg(61, 8, "%s: X", "hif_disable");
  }
  return result;
}
