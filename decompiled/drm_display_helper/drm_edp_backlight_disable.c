__int64 __fastcall drm_edp_backlight_disable(__int64 *a1, __int64 a2)
{
  int v2; // w0

  v2 = drm_edp_backlight_set_enable(a1, a2, 0);
  return v2 & (unsigned int)(v2 >> 31);
}
