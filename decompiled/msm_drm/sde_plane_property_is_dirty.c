__int64 __fastcall sde_plane_property_is_dirty(_QWORD *a1, unsigned int a2)
{
  return msm_property_is_dirty(*a1 + 3344LL, a1 + 22, a2) & 1;
}
