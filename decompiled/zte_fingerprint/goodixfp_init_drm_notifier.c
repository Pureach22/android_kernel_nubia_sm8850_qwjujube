__int64 __fastcall goodixfp_init_drm_notifier(__int64 a1)
{
  __int64 result; // x0
  int i; // w23

  printk(&unk_8F4C);
  result = goodixfp_drm_get_pannel(*(_QWORD *)(*(_QWORD *)(a1 - 136) + 760LL));
  for ( i = 0; i != 25; ++i )
  {
    while ( !(_DWORD)result )
    {
      if ( ++i == 25 )
        goto LABEL_5;
    }
    printk(&unk_8935);
    usleep_range_state(1000000, 1001000, 2);
    result = goodixfp_drm_get_pannel(*(_QWORD *)(*(_QWORD *)(a1 - 136) + 760LL));
  }
  if ( (_DWORD)result )
    result = printk(&unk_94A5);
LABEL_5:
  if ( goodixfp_active_panel )
  {
    printk(&unk_906A);
    result = panel_event_notifier_register(1, 3, goodixfp_active_panel, goodix_fb_state_chg_callback, a1 - 160);
    cookie = result;
    if ( !result )
      return printk(&unk_96EE);
  }
  return result;
}
