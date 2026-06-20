__int64 __fastcall wb_display_get_displays(void *a1, __int64 a2, unsigned int a3)
{
  _UNKNOWN **v6; // x9
  unsigned int v7; // w22

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  if ( a2 && a3 )
  {
    mutex_lock(&sde_wb_list_lock);
    v6 = (_UNKNOWN **)sde_wb_list;
    if ( sde_wb_list == (_UNKNOWN *)&sde_wb_list )
    {
      v7 = 0;
    }
    else
    {
      v7 = 0;
      do
      {
        if ( *(v6 - 4) == a1 )
          *(_QWORD *)(a2 + 8LL * (int)v7++) = v6 - 4;
        v6 = (_UNKNOWN **)*v6;
      }
      while ( v6 != &sde_wb_list && v7 < a3 );
    }
    mutex_unlock(&sde_wb_list_lock);
  }
  else
  {
    if ( !a2 )
      printk(&unk_223EF5, "wb_display_get_displays");
    return 0;
  }
  return v7;
}
