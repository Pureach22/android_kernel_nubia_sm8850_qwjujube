__int64 __fastcall cam_synx_obj_signal_obj(__int64 a1)
{
  int v1; // w22
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x23

  v1 = *(_DWORD *)(a1 + 4);
  v3 = 0;
  v4 = 0;
  v5 = 22528;
  do
  {
    raw_spin_lock_bh(g_cam_synx_obj_dev + v5);
    if ( *(_DWORD *)(g_cam_synx_obj_dev + v3 + 68) && *(_DWORD *)(g_cam_synx_obj_dev + v3 + 64) == v1 )
    {
      raw_spin_unlock_bh(g_cam_synx_obj_dev + v5);
      return cam_synx_obj_internal_signal(v4, a1);
    }
    raw_spin_unlock_bh(g_cam_synx_obj_dev + v5);
    ++v4;
    v5 += 4;
    v3 += 88;
  }
  while ( v4 != 256 );
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x1000000000LL,
    1,
    "cam_synx_obj_signal_obj",
    632,
    "Failed to find synx obj: %u",
    *(_DWORD *)(a1 + 4));
  return 4294967274LL;
}
