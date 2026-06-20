__int64 __fastcall msm_gem_mmap(__int64 a1, __int64 a2)
{
  unsigned int v3; // w19

  v3 = drm_gem_mmap();
  if ( v3 )
    _drm_dev_dbg(0, 0, 1, "mmap failed: %d\n", v3);
  else
    msm_gem_mmap_obj(*(_QWORD *)(a2 + 96), a2);
  return v3;
}
