__int64 __fastcall syna_ts_register_for_panel_events(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 result; // x0
  __int64 v5; // x20

  v2 = panel_event_notifier_register(1, 0, active_panel, syna_ts_panel_notifier_callback, a1);
  if ( !v2 )
    return printk(&unk_3A3A7, "syna_ts_register_for_panel_events", v3);
  v5 = v2;
  result = printk(&unk_3A96E, "syna_ts_register_for_panel_events", active_panel);
  *(_QWORD *)(a1 + 1360) = v5;
  return result;
}
