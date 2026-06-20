__int64 __fastcall msm_framebuffer_bo(__int64 a1)
{
  const void *v1; // x30

  if ( a1 )
    return drm_gem_fb_get_obj();
  _drm_err("from:%pS null fb\n", v1);
  return -22;
}
