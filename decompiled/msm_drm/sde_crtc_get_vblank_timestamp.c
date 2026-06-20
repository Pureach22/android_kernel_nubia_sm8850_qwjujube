__int64 __fastcall sde_crtc_get_vblank_timestamp(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 *v4; // x20
  __int64 *v5; // x22

  if ( a1 )
  {
    v3 = *a1;
    v4 = a1;
    v5 = *(__int64 **)(*a1 + 816);
    if ( v5 != (__int64 *)(*a1 + 816) )
    {
      do
      {
        if ( ((*((_DWORD *)v4 + 1968) >> *((_DWORD *)v5 + 15)) & 1) != 0 )
        {
          if ( (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v5 - 1) & 1) == 0 )
          {
            LOBYTE(a1) = ((__int64 (__fastcall *)(__int64 *, __int64))sde_encoder_get_vblank_timestamp)(v5 - 1, a3);
            return (unsigned __int8)a1 & 1;
          }
          v3 = *v4;
        }
        v5 = (__int64 *)*v5;
      }
      while ( v5 != (__int64 *)(v3 + 816) );
    }
    LOBYTE(a1) = 0;
  }
  return (unsigned __int8)a1 & 1;
}
