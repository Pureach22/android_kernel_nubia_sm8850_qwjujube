__int64 __fastcall hif_enable(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w20
  __int64 v4; // x0

  if ( a1 )
  {
    v2 = hif_enable_bus(a1);
    if ( !v2 )
    {
      if ( (ce_srng_based(a1) & 1) != 0
        && (v4 = hal_attach(a1, *(_QWORD *)(a1 + 576)), (*(_QWORD *)(a1 + 2560) = v4) == 0) )
      {
        qdf_trace_msg(61, 2, "%s: hal attach failed", "hif_enable");
      }
      else
      {
        if ( !(unsigned int)hif_bus_configure(a1) )
        {
          *(_QWORD *)(a1 + 3952) = hif_recovery_notifier_cb;
          *(_QWORD *)(a1 + 3976) = a1;
          qdf_hang_event_register_notifier(a1 + 3952);
          *(_BYTE *)(a1 + 584) = 1;
          qdf_trace_msg(61, 8, "%s: OK", "hif_enable");
          return 0;
        }
        qdf_trace_msg(61, 2, "%s: Target probe failed", "hif_enable");
        if ( (ce_srng_based(a1) & 1) != 0 )
        {
          hal_detach(*(_QWORD *)(a1 + 2560));
          *(_QWORD *)(a1 + 2560) = 0;
        }
      }
      hif_disable_bus(a1);
      return 16;
    }
    v3 = v2;
    qdf_trace_msg(61, 2, "%s: hif_enable_bus error = %d", "hif_enable", v2);
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: hif_ctx = NULL", "hif_enable");
    return 29;
  }
  return v3;
}
