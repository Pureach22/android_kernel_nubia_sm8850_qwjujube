__int64 __fastcall set_demura_feature(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  void (*v4)(void); // x8
  int v7; // w8
  __int64 result; // x0
  unsigned int v9; // w8
  __int64 v10; // x0

  if ( !a1 )
    return 4294967274LL;
  v3 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v3 >= 3 )
  {
    __break(0x5512u);
    v10 = MEMORY[0x2526E50]();
    return set_demura_backlight(v10);
  }
  else
  {
    v4 = *(void (**)(void))(a1 + 8 * v3 + 1048);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1841204718 )
        __break(0x8228u);
      v4();
      if ( a3 )
      {
        v7 = *(_DWORD *)(a3 + 7588);
        result = 0;
        if ( *a2 )
          v9 = v7 | 4;
        else
          v9 = v7 & 0xFFFFFFFB;
        *(_DWORD *)(a3 + 7588) = v9;
      }
      else
      {
        _drm_err("invalid args feature %d\n", 2);
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
