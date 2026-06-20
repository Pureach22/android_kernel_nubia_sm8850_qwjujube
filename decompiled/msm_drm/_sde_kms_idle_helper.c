__int64 __fastcall sde_kms_idle_helper(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 v6; // x8
  __int64 v7; // x8
  signed int v8; // w26
  __int64 v9; // x8
  int v10; // w0
  __int64 v11; // x8
  __int64 result; // x0
  _QWORD v13[3]; // [xsp+8h] [xbp-18h] BYREF

  v13[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 136);
  v13[0] = 0;
  v13[1] = 0;
  v3 = *(_QWORD *)(v2 + 56);
  drm_connector_list_iter_begin(a2, v13);
  v4 = drm_connector_list_iter_next(v13);
  if ( v4 )
  {
    v5 = v4;
    do
    {
      v6 = *(_QWORD *)(v5 + 2512);
      if ( v6 )
      {
        v7 = *(_QWORD *)(v6 + 8);
        if ( v7 )
        {
          v8 = *(_DWORD *)(v7 + 160);
          if ( (unsigned int)v8 >= 0x10 )
            __break(0x5512u);
          v9 = v3 + 1128 + 80LL * v8;
          if ( *(_QWORD *)(v9 + 8) )
            kthread_flush_worker(v9 + 24);
          v10 = sde_encoder_wait_for_event(*(_QWORD *)(v5 + 2272), 1u);
          if ( v10 != -11 )
          {
            if ( v10 )
            {
              printk(&unk_2128E3, "_sde_kms_idle_helper");
            }
            else
            {
              v11 = v3 + 2408 + 80LL * v8;
              if ( *(_QWORD *)(v11 + 8) )
                kthread_flush_worker(v11 + 24);
              sde_encoder_idle_request(*(_QWORD *)(v5 + 2272));
            }
          }
        }
      }
      v5 = drm_connector_list_iter_next(v13);
    }
    while ( v5 );
  }
  drm_connector_list_iter_end(v13);
  result = ((__int64 (__fastcall *)(__int64))msm_atomic_flush_display_threads)(v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
