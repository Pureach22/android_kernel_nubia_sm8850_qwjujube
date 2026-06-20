__int64 init_module()
{
  unsigned int v0; // w19

  v0 = tracepoint_probe_register(&_tracepoint_android_vh_try_fixup_sea, can_fixup_sea, 0);
  if ( v0 )
  {
    printk(&unk_76BA);
  }
  else
  {
    android_rvh_probe_register(
      &_tracepoint_android_rvh_bitmap_find_best_next_area,
      bitmap_find_best_next_zero_area_off,
      0);
    cma_for_each_area(cma_best_fit_setup, 0);
  }
  return v0;
}
