__int64 __fastcall sde_crtc_vblank(__int64 *a1, char a2)
{
  __int64 v4; // x20
  int v5; // w0
  __int64 *i; // x23
  __int64 v7; // x8
  __int64 *j; // x22
  unsigned int v10; // w8
  int v11; // w21
  unsigned int v18; // w10
  int v19; // w7
  char v20; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_crtc_vblank_enable",
      5834,
      -1,
      *((_DWORD *)a1 + 28),
      a2 & 1,
      *((unsigned __int8 *)a1 + 4512),
      *(_DWORD *)(a1[251] + 20),
      *((_DWORD *)a1 + 1968));
    if ( (a2 & 1) != 0 )
    {
      v4 = *(_QWORD *)(*a1 + 8);
      v5 = _pm_runtime_resume(v4, 4);
      if ( v5 < 0 )
      {
        v10 = *(_DWORD *)(v4 + 480);
        v11 = v5;
        do
        {
          if ( !v10 )
            break;
          _X12 = (unsigned int *)(v4 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v18 = __ldxr(_X12);
            if ( v18 != v10 )
              break;
            if ( !__stlxr(v10 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v18 == v10;
          v10 = v18;
        }
        while ( !_ZF );
        printk(&unk_24C43E, "_sde_crtc_vblank_enable");
        sde_evtlog_log(sde_dbg_base_evtlog, "_sde_crtc_vblank_enable", 5842, -1, v11, 60333, -1059143953, v19, v20);
        printk(&unk_2655AA, "sde_crtc_vblank");
      }
      else
      {
        mutex_lock(a1 + 577);
        for ( i = *(__int64 **)(*a1 + 816); i != (__int64 *)(*a1 + 816); i = (__int64 *)*i )
        {
          if ( ((*((_DWORD *)a1 + 1968) >> *((_DWORD *)i + 15)) & 1) != 0
            && (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1) & 1) == 0 )
          {
            sde_encoder_register_vblank_callback(i - 1, sde_crtc_vblank_cb, a1);
          }
        }
        mutex_unlock(a1 + 577);
      }
    }
    else
    {
      mutex_lock(a1 + 577);
      v7 = *a1;
      for ( j = *(__int64 **)(*a1 + 816); j != (__int64 *)(v7 + 816); j = (__int64 *)*j )
      {
        if ( ((*((_DWORD *)a1 + 1968) >> *((_DWORD *)j + 15)) & 1) != 0
          && (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(j - 1) & 1) == 0 )
        {
          sde_encoder_register_vblank_callback(j - 1, 0, 0);
        }
        v7 = *a1;
      }
      mutex_unlock(a1 + 577);
      _pm_runtime_idle(*(_QWORD *)(*a1 + 8), 4);
    }
    return 0;
  }
  else
  {
    printk(&unk_25E167, "sde_crtc_vblank");
    return 4294967274LL;
  }
}
