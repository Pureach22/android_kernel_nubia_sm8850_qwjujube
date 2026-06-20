__int64 __fastcall sde_crtc_reset_sw_state(unsigned __int64 *a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x20
  __int64 *v4; // x21
  __int64 i; // x9
  __int64 result; // x0
  unsigned __int64 v13; // x9
  unsigned __int64 v16; // x9

  v1 = *a1;
  v2 = a1[251];
  v4 = *(__int64 **)(*a1 + 840);
  for ( i = *a1 + 840; v4 != (__int64 *)i; i = v1 + 840 )
  {
    if ( ((*(_DWORD *)(a1[251] + 12) >> *((_DWORD *)v4 + 437)) & 1) != 0 )
    {
      sde_plane_set_revalidate(v4 - 1, 1);
      v1 = *a1;
    }
    v4 = (__int64 *)*v4;
  }
  result = sde_crtc_clear_cached_mixer_cfg(a1);
  _X8 = a1 + 756;
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 | 2, _X8) );
  if ( *(_DWORD *)(v2 + 2048) )
  {
    _X8 = (unsigned __int64 *)(v2 + 1792);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 | 1, _X8) );
  }
  *(_QWORD *)(v2 + 748) = 0;
  *(_QWORD *)(v2 + 756) = 0;
  *(_QWORD *)(v2 + 732) = 0;
  *(_QWORD *)(v2 + 740) = 0;
  *(_QWORD *)(v2 + 716) = 0;
  *(_QWORD *)(v2 + 724) = 0;
  *(_QWORD *)(v2 + 700) = 0;
  *(_QWORD *)(v2 + 708) = 0;
  *(_QWORD *)(v2 + 692) = 0;
  return result;
}
