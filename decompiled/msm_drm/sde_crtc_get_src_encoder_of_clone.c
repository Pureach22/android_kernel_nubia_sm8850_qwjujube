__int64 *__fastcall sde_crtc_get_src_encoder_of_clone(__int64 *a1)
{
  __int64 v1; // x8
  __int64 *i; // x21
  __int64 *v4; // x20

  if ( a1 )
  {
    v1 = *a1;
    if ( *a1 )
    {
      for ( i = *(__int64 **)(v1 + 816); i != (__int64 *)(v1 + 816); i = (__int64 *)*i )
      {
        if ( ((*((_DWORD *)a1 + 1968) >> *((_DWORD *)i + 15)) & 1) != 0 )
        {
          v4 = i - 1;
          if ( (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1) & 1) == 0 )
            return v4;
          v1 = *a1;
        }
      }
    }
  }
  return nullptr;
}
