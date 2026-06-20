__int64 __fastcall adreno_wait_for_halt_ack_3(__int64 *a1, int a2)
{
  __int64 region; // x0
  __int64 v5; // x21
  __int64 (**v6)(void); // x8
  __int64 (*v7)(void); // x8
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x22
  int v11; // w4
  __int64 v12; // x8
  unsigned int v13; // w20
  unsigned int v14; // w1
  int v15; // w8
  int v16; // w10
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
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
  v9 = kgsl_regmap_poll_read(v5, 15430, &v18);
  if ( (_DWORD)v9 )
  {
LABEL_12:
    v11 = v18;
LABEL_13:
    v12 = *a1;
    v13 = v9;
    dev_err(v12, "GBIF/VBIF Halt ack timeout: reg=%08x mask=%08x status=%08x\n", 15430, a2, v11);
    v14 = v13;
    goto LABEL_22;
  }
  v10 = v8 + 100000000;
  while ( 1 )
  {
    if ( (a2 & ~v18) == 0 )
    {
      v14 = 0;
      goto LABEL_22;
    }
    if ( ktime_get(v9) > v10 )
      break;
    usleep_range_state(26, 100, 2);
    __yield();
    v9 = kgsl_regmap_poll_read(v5, 15430, &v18);
    if ( (_DWORD)v9 )
      goto LABEL_12;
  }
  LODWORD(v9) = kgsl_regmap_poll_read(v5, 15430, &v18);
  v11 = v18;
  v15 = v9;
  if ( (v18 & a2) == a2 )
    v16 = 0;
  else
    v16 = -110;
  if ( !(_DWORD)v9 )
    LODWORD(v9) = v16;
  if ( v15 )
    goto LABEL_13;
  v14 = 0;
  if ( (v18 & a2) != a2 )
    goto LABEL_13;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v14;
}
