__int64 __fastcall sde_cp_crtc_disable(_QWORD *a1)
{
  __int64 v2; // x20

  if ( !a1 )
    return _drm_err("invalid crtc handle");
  mutex_lock(a1 + 583);
  v2 = vzalloc_noprof(16396);
  if ( v2 )
    msm_property_set_blob(a1 + 325, a1 + 983, v2, (unsigned int)(*(_DWORD *)(v2 + 0x4000) + 1), 4);
  a1[1001] = 0;
  a1[1000] = 0;
  a1[999] = 0;
  a1[998] = 0;
  a1[997] = 0;
  mutex_unlock(a1 + 583);
  return vfree(v2);
}
