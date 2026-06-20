__int64 __fastcall sde_wb_get_num_of_displays(__int64 a1)
{
  _UNKNOWN **v2; // x9
  unsigned int v3; // w20
  __int64 v4; // x10

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  mutex_lock(&sde_wb_list_lock);
  v2 = (_UNKNOWN **)sde_wb_list;
  if ( sde_wb_list == (_UNKNOWN *)&sde_wb_list )
  {
    v3 = 0;
  }
  else
  {
    v3 = 0;
    do
    {
      v4 = (__int64)*(v2 - 4);
      v2 = (_UNKNOWN **)*v2;
      if ( v4 == a1 )
        ++v3;
    }
    while ( v2 != &sde_wb_list );
  }
  mutex_unlock(&sde_wb_list_lock);
  return v3;
}
