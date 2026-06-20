__int64 __fastcall _get_offset_idx(unsigned int a1, __int64 a2)
{
  __int64 v3; // x2
  __int64 v4; // x1

  if ( a1 > 3 || (unsigned int)a2 > 8 || a1 && (_DWORD)a2 == 8 || a1 >= 2 && (_DWORD)a2 == 7 )
  {
    _drm_err("invalid depth %d index %d\n", a2, a1);
    return 0;
  }
  v3 = (a1 + 1) << a2;
  v4 = a1 << a2;
  if ( (unsigned int)v3 >= 0x101 )
  {
    _drm_err("invalid offset %d end %d > 256\n", v4, v3);
    return 0;
  }
  return ((_DWORD)v4 << 8) | ((_DWORD)v4 << 16) | (unsigned int)v4;
}
