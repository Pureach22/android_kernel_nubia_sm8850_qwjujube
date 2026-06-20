__int64 __fastcall sde_connector_set_prop_out_fb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 result; // x0

  v3 = *(_QWORD *)(a2 + 440);
  if ( v3 )
  {
    drm_mode_object_put(v3 + 24);
    *(_QWORD *)(a2 + 440) = 0;
    if ( a1 )
    {
      mutex_lock(a1 + 3392);
      if ( *(_DWORD *)(a1 + 3344) < 0xCu )
        v7 = 0;
      else
        v7 = *(_QWORD *)(*(_QWORD *)(a1 + 3336) + 176LL);
      mutex_unlock(a1 + 3392);
    }
    else
    {
      v7 = -1;
    }
    *(_QWORD *)(a2 + 832) = v7;
  }
  v8 = drm_framebuffer_lookup(*(_QWORD *)a1, 0, (unsigned int)a3);
  v9 = v8;
  *(_QWORD *)(a2 + 440) = v8;
  if ( a3 && !v8 )
  {
    printk(&unk_2357E4, "_sde_connector_set_prop_out_fb");
    return 4294967282LL;
  }
  else
  {
    result = 0;
    if ( !a3 && !v9 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "cleared fb_id\n");
      return 0;
    }
  }
  return result;
}
