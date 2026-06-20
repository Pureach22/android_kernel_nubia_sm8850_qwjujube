__int64 __fastcall sde_crtc_property_is_dirty(_QWORD *a1, unsigned int a2)
{
  return msm_property_is_dirty(*a1 + 2600LL, a1 + 96, a2) & 1;
}
