__int64 __fastcall sde_connector_property_is_dirty(_QWORD *a1, unsigned int a2)
{
  return msm_property_is_dirty(*a1 + 3312LL, a1 + 56, a2) & 1;
}
