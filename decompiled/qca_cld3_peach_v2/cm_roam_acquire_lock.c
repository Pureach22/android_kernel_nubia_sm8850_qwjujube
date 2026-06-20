__int64 __fastcall cm_roam_acquire_lock(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 ext_hdl_fl; // x0

  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 4;
  ext_hdl_fl = cm_get_ext_hdl_fl(a1, (__int64)"cm_roam_acquire_lock", 0x7C4u, a2, a3, a4, a5, a6, a7, a8, a9);
  cm_roam_acquire_lock_rso_cfg = ext_hdl_fl;
  if ( ext_hdl_fl )
    return qdf_mutex_acquire(ext_hdl_fl);
  else
    return 4;
}
