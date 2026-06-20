__int64 __fastcall sde_crtc_is_crtc_roi_dirty(_QWORD *a1)
{
  if ( !a1 )
    return (unsigned __int8)a1 & 1;
  if ( *a1 )
  {
    LOBYTE(a1) = msm_property_is_dirty(*a1 + 2600LL, a1 + 96, 18);
    return (unsigned __int8)a1 & 1;
  }
  return 0;
}
