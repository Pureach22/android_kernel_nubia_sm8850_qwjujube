__int64 __fastcall lt9611uxc_connector_mode_valid(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x8
  _QWORD *v4; // x22
  _QWORD *v6; // x23
  _DWORD *v7; // x20
  int v8; // w21

  if ( (*(_BYTE *)(a1 + 3642) & 1) != 0 )
  {
    if ( *(unsigned __int16 *)(a2 + 14) == *(unsigned __int16 *)(a1 + 2958)
      && *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(a1 + 2948) )
    {
      return 0;
    }
  }
  else
  {
    v3 = *(_QWORD **)(a1 + 2808);
    v4 = (_QWORD *)(a1 + 2808);
    if ( v3 != (_QWORD *)(a1 + 2808) )
    {
      while ( 1 )
      {
        v6 = (_QWORD *)*v3;
        if ( *(unsigned __int16 *)(a2 + 14) == *((unsigned __int16 *)v3 - 25)
          && *(unsigned __int16 *)(a2 + 4) == *((unsigned __int16 *)v3 - 30) )
        {
          v7 = v3 - 8;
          v8 = drm_mode_vrefresh(a2);
          if ( v8 == (unsigned int)drm_mode_vrefresh(v7) && *(_DWORD *)a2 == *v7 )
            break;
        }
        v3 = v6;
        if ( v6 == v4 )
          return 4294967294LL;
      }
      return 0;
    }
  }
  return 4294967294LL;
}
