__int64 __fastcall qmi_rmnet_work_init(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x0
  int v3; // w8
  __int64 (__fastcall *v5)(); // x8
  _QWORD *v6; // x1
  __int64 *v7; // x2
  unsigned __int64 v13; // x10

  if ( !rmnet_ps_wq )
  {
    v1 = result;
    result = alloc_workqueue("rmnet_powersave_work", 32, 1);
    rmnet_ps_wq = result;
    if ( result )
    {
      v2 = (_QWORD *)_kmalloc_cache_noprof(rtnl_is_locked, 2336, 128);
      rmnet_work = (__int64)v2;
      if ( v2 )
      {
        *v2 = 0xFFFFFFFE00000LL;
        v3 = dfc_ps_ext;
        v2[1] = v2 + 1;
        _ZF = v3 == 0;
        v5 = qmi_rmnet_check_stats;
        v2[2] = v2 + 1;
        if ( !_ZF )
          v5 = qmi_rmnet_check_stats_2;
        v2[3] = v5;
        init_timer_key(v2 + 4, &delayed_work_timer_fn, 0x200000, 0, 0);
        v6 = (_QWORD *)(rmnet_work + 112);
        v7 = (__int64 *)(rmnet_work + 120);
        *(_QWORD *)(rmnet_work + 104) = v1;
        rmnet_get_packets(v1, v6, v7);
        rmnet_work_quit = 0;
        result = rmnet_get_qmi_pt(*(_QWORD *)(rmnet_work + 104));
        if ( result )
        {
          _X8 = (unsigned __int64 *)(result + 64);
          __asm { PRFM            #0x11, [X8] }
          do
            v13 = __ldxr(_X8);
          while ( __stxr(v13 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        }
        rmnet_work_inited = 1;
      }
      else
      {
        result = destroy_workqueue(rmnet_ps_wq);
        rmnet_ps_wq = 0;
      }
    }
  }
  return result;
}
