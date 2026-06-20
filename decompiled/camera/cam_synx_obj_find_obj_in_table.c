__int64 __fastcall cam_synx_obj_find_obj_in_table(int a1, _DWORD *a2)
{
  __int64 v4; // x23
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v7; // x8

  v4 = 0;
  v5 = 0;
  v6 = 22528;
  do
  {
    raw_spin_lock_bh(g_cam_synx_obj_dev + v6);
    v7 = g_cam_synx_obj_dev;
    if ( *(_DWORD *)(g_cam_synx_obj_dev + v4 + 68) && *(_DWORD *)(g_cam_synx_obj_dev + v4 + 64) == a1 )
    {
      *a2 = v5;
      raw_spin_unlock_bh(v7 + v6);
      return 0;
    }
    raw_spin_unlock_bh(g_cam_synx_obj_dev + v6);
    ++v5;
    v6 += 4;
    v4 += 88;
  }
  while ( v5 != 256 );
  return 4294967274LL;
}
