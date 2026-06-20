__int64 __fastcall sde_crtc_dump_fences(__int64 result)
{
  __int64 v1; // x8
  __int64 *v2; // x20
  __int64 *v3; // x19

  v1 = *(_QWORD *)result;
  v2 = *(__int64 **)(*(_QWORD *)result + 840LL);
  if ( v2 != (__int64 *)(*(_QWORD *)result + 840LL) )
  {
    v3 = (__int64 *)result;
    do
    {
      if ( ((*(_DWORD *)(v3[251] + 12) >> *((_DWORD *)v2 + 437)) & 1) != 0 )
      {
        result = sde_plane_dump_input_fence(v2 - 1);
        v1 = *v3;
      }
      v2 = (__int64 *)*v2;
    }
    while ( v2 != (__int64 *)(v1 + 840) );
  }
  return result;
}
