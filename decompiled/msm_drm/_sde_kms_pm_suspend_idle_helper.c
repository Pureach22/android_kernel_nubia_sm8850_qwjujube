__int64 __fastcall sde_kms_pm_suspend_idle_helper(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x8
  signed int v8; // w26
  __int64 v9; // x8
  int v10; // w0
  __int64 v11; // x8
  __int64 result; // x0
  _QWORD v13[3]; // [xsp+8h] [xbp-18h] BYREF

  v13[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 136);
  v3 = *(_QWORD *)(a2 + 152);
  v13[0] = 0;
  v13[1] = 0;
  v4 = *(_QWORD *)(v2 + 56);
  drm_connector_list_iter_begin(v3, v13);
  v5 = drm_connector_list_iter_next(v13);
  if ( v5 )
  {
    v6 = v5;
    do
    {
      v7 = *(_QWORD *)(v6 + 2512);
      if ( v7
        && *(_QWORD *)(v7 + 1472) == 2
        && (((__int64 (__fastcall *)(_QWORD))sde_encoder_in_clone_mode)(*(_QWORD *)(v6 + 2272)) & 1) == 0 )
      {
        v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 2512) + 8LL) + 160LL);
        if ( (unsigned int)v8 >= 0x10 )
          __break(0x5512u);
        v9 = v4 + 1128 + 80LL * v8;
        if ( *(_QWORD *)(v9 + 8) )
          kthread_flush_worker(v9 + 24);
        v10 = sde_encoder_wait_for_event(*(_QWORD *)(v6 + 2272), 1u);
        if ( v10 != -11 )
        {
          if ( v10 )
          {
            printk(&unk_2128E3, "_sde_kms_pm_suspend_idle_helper");
          }
          else
          {
            v11 = v4 + 2408 + 80LL * v8;
            if ( *(_QWORD *)(v11 + 8) )
              kthread_flush_worker(v11 + 24);
            sde_encoder_idle_request(*(_QWORD *)(v6 + 2272));
          }
        }
      }
      v6 = drm_connector_list_iter_next(v13);
    }
    while ( v6 );
  }
  drm_connector_list_iter_end(v13);
  result = ((__int64 (__fastcall *)(__int64))msm_atomic_flush_display_threads)(v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
