__int64 __fastcall dsi_display_panel_te_irq_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  char v10; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_panel_te_irq_handler", 483, -1, 13107, -1059143953, a7, a8, v10);
    complete_all(a2 + 128);
  }
  return 1;
}
