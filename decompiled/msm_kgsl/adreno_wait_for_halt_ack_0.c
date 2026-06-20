__int64 __fastcall adreno_wait_for_halt_ack_0(__int64 *a1, __int64 a2, int a3)
{
  unsigned int v5; // w20
  __int64 region; // x0
  __int64 v7; // x22
  __int64 (**v8)(void); // x8
  __int64 (*v9)(void); // x8
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x23
  int v13; // w4
  __int64 v14; // x8
  unsigned int v15; // w21
  unsigned int v16; // w1
  int v17; // w8
  int v18; // w10
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v5 = a2;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  region = kgsl_regmap_get_region(a1 + 1650, a2);
  v7 = region;
  if ( region )
  {
    v8 = *(__int64 (***)(void))(region + 16);
    if ( v8 )
    {
      v9 = *v8;
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -664046789 )
          __break(0x8228u);
        region = v9();
      }
    }
  }
  v10 = ktime_get(region);
  v11 = kgsl_regmap_poll_read(v7, v5, &v20);
  if ( (_DWORD)v11 )
  {
LABEL_12:
    v13 = v20;
LABEL_13:
    v14 = *a1;
    v15 = v11;
    dev_err(v14, "GBIF/VBIF Halt ack timeout: reg=%08x mask=%08x status=%08x\n", v5, a3, v13);
    v16 = v15;
    goto LABEL_22;
  }
  v12 = v10 + 100000000;
  while ( 1 )
  {
    if ( (a3 & ~v20) == 0 )
    {
      v16 = 0;
      goto LABEL_22;
    }
    if ( ktime_get(v11) > v12 )
      break;
    usleep_range_state(26, 100, 2);
    __yield();
    v11 = kgsl_regmap_poll_read(v7, v5, &v20);
    if ( (_DWORD)v11 )
      goto LABEL_12;
  }
  LODWORD(v11) = kgsl_regmap_poll_read(v7, v5, &v20);
  v13 = v20;
  v17 = v11;
  if ( (v20 & a3) == a3 )
    v18 = 0;
  else
    v18 = -110;
  if ( !(_DWORD)v11 )
    LODWORD(v11) = v18;
  if ( v17 )
    goto LABEL_13;
  v16 = 0;
  if ( (v20 & a3) != a3 )
    goto LABEL_13;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v16;
}
