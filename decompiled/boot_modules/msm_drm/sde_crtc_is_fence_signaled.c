__int64 __fastcall sde_crtc_is_fence_signaled(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 *v2; // x20

  v1 = *a1;
  v2 = *(__int64 **)(*a1 + 840LL);
  if ( v2 == (__int64 *)(*a1 + 840LL) )
    return 1;
  while ( ((*(_DWORD *)(a1[251] + 12LL) >> *((_DWORD *)v2 + 437)) & 1) == 0 )
  {
LABEL_3:
    v2 = (__int64 *)*v2;
    if ( v2 == (__int64 *)(v1 + 840) )
      return 1;
  }
  if ( (sde_plane_is_sw_fence_signaled(v2 - 1) & 1) != 0 )
  {
    v1 = *a1;
    goto LABEL_3;
  }
  return 0;
}
