__int64 __fastcall aw882xx_dev_remove(__int64 a1)
{
  aw882xx_monitor_deinit(a1 + 672);
  aw882xx_cali_deinit(a1 + 648);
  if ( !*(_DWORD *)(a1 + 52) )
    misc_deregister(&misc_algo_auth);
  return 0;
}
