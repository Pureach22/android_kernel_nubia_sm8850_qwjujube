__int64 sub_1E3870()
{
  __int64 v0; // x13
  unsigned int v1; // w21

  atomic_store(v1, (unsigned int *)(v0 - 220));
  return dsi_display_drm_ext_atomic_check();
}
