__int64 __fastcall adreno_wait_for_halt_ack_1(_QWORD *a1, int a2)
{
  __int64 region; // x0
  __int64 v5; // x21
  __int64 (**v6)(void); // x8
  __int64 (*v7)(void); // x8
  __int64 v8; // x22
  __int64 result; // x0
  __int64 v10; // x22
  int v11; // w4
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  region = kgsl_regmap_get_region(a1 + 1650, 15430);
  v5 = region;
  if ( region )
  {
    v6 = *(__int64 (***)(void))(region + 16);
    if ( v6 )
    {
      v7 = *v6;
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != -664046789 )
          __break(0x8228u);
        region = v7();
      }
    }
  }
  v8 = ktime_get(region);
  result = kgsl_regmap_poll_read(v5, 15430, &v12);
  if ( (_DWORD)result )
  {
LABEL_12:
    v11 = v12;
LABEL_13:
    result = dev_err(*a1, "GBIF/VBIF Halt ack timeout: reg=%08x mask=%08x status=%08x\n", 15430, a2, v11);
  }
  else
  {
    v10 = v8 + 100000000;
    while ( (a2 & ~v12) != 0 )
    {
      if ( ktime_get(result) > v10 )
      {
        result = kgsl_regmap_poll_read(v5, 15430, &v12);
        v11 = v12;
        if ( (_DWORD)result || (v12 & a2) != a2 )
          goto LABEL_13;
        break;
      }
      usleep_range_state(26, 100, 2);
      __yield();
      result = kgsl_regmap_poll_read(v5, 15430, &v12);
      if ( (_DWORD)result )
        goto LABEL_12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
