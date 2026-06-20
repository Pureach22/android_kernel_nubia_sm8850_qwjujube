__int64 __fastcall do_gbif_halt(_QWORD *a1, __int64 a2, __int64 a3, unsigned int a4, const char *a5)
{
  __int64 v8; // x25
  __int64 result; // x0
  __int64 v10; // x8
  _DWORD *v11; // x8
  __int64 v12; // x8
  _DWORD *v13; // x8

  kgsl_regmap_write(a1 + 1650, a4);
  v8 = jiffies + 25LL;
  while ( 1 )
  {
    result = kgsl_regmap_read(a1 + 1650);
    if ( (a4 & ~(_DWORD)result) == 0 )
      break;
    v10 = a1[11];
    if ( v10 )
    {
      v11 = *(_DWORD **)(v10 + 32);
      if ( v11 )
      {
        if ( *(v11 - 1) != -1954538307 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD))v11)(a1 + 7, 0);
      }
    }
    usleep_range_state(10, 100, 2);
    if ( v8 - jiffies < 0 )
    {
      v12 = a1[11];
      if ( v12 )
      {
        v13 = *(_DWORD **)(v12 + 32);
        if ( v13 )
        {
          if ( *(v13 - 1) != -1954538307 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD))v13)(a1 + 7, 0);
        }
      }
      result = kgsl_regmap_read(a1 + 1650);
      if ( (a4 & ~(_DWORD)result) != 0 )
        return dev_err(*a1, "%s GBIF halt timed out\n", a5);
      return result;
    }
  }
  return result;
}
