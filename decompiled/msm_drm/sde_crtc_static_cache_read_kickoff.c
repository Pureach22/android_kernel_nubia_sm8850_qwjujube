__int64 __fastcall sde_crtc_static_cache_read_kickoff(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x9
  unsigned int v4; // w21
  _QWORD *v5; // x23
  __int64 v6; // x22
  unsigned int v7; // w23
  int fps; // w0
  _QWORD *i; // x24
  unsigned int v10; // w0
  int v11; // w20
  __int64 v12; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v1 = *(_QWORD *)result;
    v2 = result;
    if ( *(_QWORD *)result )
    {
      v3 = *(_QWORD *)(v1 + 56);
      if ( v3 )
      {
        v4 = *(_DWORD *)(result + 160);
        if ( v4 >= 0x11 )
        {
          __break(0x5512u);
          return sde_crtc_cancel_delayed_work();
        }
        if ( *(_DWORD *)(result + 7856) == 4 )
        {
          v5 = *(_QWORD **)(v1 + 816);
          v6 = v3 + 1128;
          if ( v5 == (_QWORD *)(v1 + 816) )
          {
            v7 = 999;
          }
          else
          {
            do
            {
              if ( v5[9] == v2 )
              {
                if ( !(unsigned int)sde_encoder_in_cont_splash(v5 - 1) )
                {
                  fps = sde_encoder_get_fps(v5 - 1);
                  v1 = *(_QWORD *)v2;
                  v7 = fps + 999;
                  goto LABEL_14;
                }
                v1 = *(_QWORD *)v2;
              }
              v5 = (_QWORD *)*v5;
            }
            while ( v5 != (_QWORD *)(v1 + 816) );
            v7 = 999;
LABEL_14:
            if ( !v1 )
            {
              printk(&unk_25E167, "sde_crtc_get_fps_mode");
LABEL_23:
              v10 = 0;
LABEL_24:
              v11 = v7 / v10;
              v12 = _msecs_to_jiffies(v7 / v10);
              kthread_queue_delayed_work(v6 + 80LL * v4 + 24, v2 + 7776, v12);
              return sde_evtlog_log(
                       sde_dbg_base_evtlog,
                       "sde_crtc_static_cache_read_kickoff",
                       9221,
                       -1,
                       *(_DWORD *)(v2 + 112),
                       *(_DWORD *)(v2 + 7856),
                       v11,
                       -1059143953,
                       vars0);
            }
          }
          for ( i = *(_QWORD **)(v1 + 816); i != (_QWORD *)(v1 + 816); i = (_QWORD *)*i )
          {
            if ( i[9] == v2 )
            {
              if ( !(unsigned int)sde_encoder_in_cont_splash(i - 1) )
              {
                v10 = sde_encoder_get_fps(i - 1);
                goto LABEL_24;
              }
              v1 = *(_QWORD *)v2;
            }
          }
          goto LABEL_23;
        }
      }
    }
  }
  return result;
}
