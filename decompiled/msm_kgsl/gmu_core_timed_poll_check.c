__int64 __fastcall gmu_core_timed_poll_check(__int64 a1, __int64 a2, int a3, int a4, int a5)
{
  unsigned int v8; // w21
  __int64 region; // x0
  __int64 v10; // x22
  __int64 (**v11)(void); // x8
  __int64 (*v12)(void); // x8
  __int64 v13; // x24
  __int64 result; // x0
  unsigned int v15; // w23
  __int64 v16; // x24
  unsigned int v17; // w8
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v8 = a2;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  region = kgsl_regmap_get_region(a1 + 13200, a2);
  v10 = region;
  if ( region )
  {
    v11 = *(__int64 (***)(void))(region + 16);
    if ( v11 )
    {
      v12 = *v11;
      if ( v12 )
      {
        if ( *((_DWORD *)v12 - 1) != -664046789 )
          __break(0x8228u);
        region = v12();
      }
    }
  }
  v13 = ktime_get(region);
  result = kgsl_regmap_poll_read(v10, v8, &v18);
  if ( !(_DWORD)result )
  {
    v15 = 1000 * a4;
    v16 = v13 + 1000LL * v15;
    while ( 1 )
    {
      if ( (v18 & a5) == a3 )
      {
        result = 0;
        goto LABEL_8;
      }
      if ( v15 && ktime_get(result) > v16 )
        break;
      usleep_range_state(26, 100, 2);
      __yield();
      result = kgsl_regmap_poll_read(v10, v8, &v18);
      if ( (_DWORD)result )
        goto LABEL_8;
    }
    LODWORD(result) = kgsl_regmap_poll_read(v10, v8, &v18);
    if ( (v18 & a5) == a3 )
      v17 = 0;
    else
      v17 = -110;
    if ( (_DWORD)result )
      result = (unsigned int)result;
    else
      result = v17;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
