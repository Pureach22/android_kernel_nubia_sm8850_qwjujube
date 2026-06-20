__int64 __fastcall sde_crtc_get_msm_mode(__int64 **a1)
{
  __int64 v2; // x0
  __int64 *v3; // x21
  __int64 result; // x0
  char v5; // w8
  __int64 v6; // x8

  v2 = **a1;
  v3 = *(__int64 **)(v2 + 816);
  if ( v3 == (__int64 *)(v2 + 816) )
    return 0;
  while ( 1 )
  {
    if ( ((*((_DWORD *)a1 + 5) >> *((_DWORD *)v3 + 15)) & 1) != 0 )
    {
      v5 = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v3 - 1);
      v2 = **a1;
      if ( (v5 & 1) == 0 )
        break;
    }
    v3 = (__int64 *)*v3;
    if ( v3 == (__int64 *)(v2 + 816) )
      return 0;
  }
  result = sde_encoder_get_connector(v2, v3 - 1);
  if ( result )
  {
    v6 = *(_QWORD *)(result + 2512);
    if ( v6 )
      return v6 + 3232;
    else
      return 0;
  }
  return result;
}
