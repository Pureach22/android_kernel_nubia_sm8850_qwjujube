__int64 __fastcall a5xx_clear_pending_transactions(_QWORD *a1)
{
  __int64 region; // x0
  __int64 v3; // x20
  __int64 (**v4)(void); // x8
  __int64 (*v5)(void); // x8
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x21
  int v9; // w4
  unsigned int v10; // w20
  int v11; // w8
  int v12; // w10
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_regmap_write(a1 + 1650, 15);
  v14 = 0;
  region = kgsl_regmap_get_region(a1 + 1650, 12417);
  v3 = region;
  if ( region )
  {
    v4 = *(__int64 (***)(void))(region + 16);
    if ( v4 )
    {
      v5 = *v4;
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != -664046789 )
          __break(0x8228u);
        region = v5();
      }
    }
  }
  v6 = ktime_get(region);
  v7 = kgsl_regmap_poll_read(v3, 12417, &v14);
  if ( (_DWORD)v7 )
  {
LABEL_12:
    v9 = v14;
LABEL_13:
    v10 = v7;
    dev_err(*a1, "GBIF/VBIF Halt ack timeout: reg=%08x mask=%08x status=%08x\n", 12417, 15, v9);
    goto LABEL_22;
  }
  v8 = v6 + 100000000;
  while ( 1 )
  {
    if ( (~v14 & 0xF) == 0 )
    {
      v10 = 0;
      goto LABEL_22;
    }
    if ( ktime_get(v7) > v8 )
      break;
    usleep_range_state(26, 100, 2);
    __yield();
    v7 = kgsl_regmap_poll_read(v3, 12417, &v14);
    if ( (_DWORD)v7 )
      goto LABEL_12;
  }
  LODWORD(v7) = kgsl_regmap_poll_read(v3, 12417, &v14);
  v9 = v14;
  v11 = v7;
  if ( (v14 & 0xF) == 0xF )
    v12 = 0;
  else
    v12 = -110;
  if ( !(_DWORD)v7 )
    LODWORD(v7) = v12;
  if ( v11 )
    goto LABEL_13;
  v10 = 0;
  if ( (v14 & 0xF) != 0xF )
    goto LABEL_13;
LABEL_22:
  kgsl_regmap_write(a1 + 1650, 0);
  _ReadStatusReg(SP_EL0);
  return v10;
}
