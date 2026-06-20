__int64 __fastcall qpnp_tm_init(__int64 *a1)
{
  int v2; // w8
  __int64 v3; // x0
  unsigned int updated; // w0
  char v5; // w8
  int v6; // w10
  int v7; // w11
  __int64 v8; // x0
  int v9; // w8
  int v10; // w8
  int v11; // w10
  int v12; // w9
  __int64 v13; // x10
  unsigned int v14; // w11
  __int64 *v15; // x9
  unsigned __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x9
  int v21; // w20
  __int64 v22; // x0
  __int64 v23; // x5
  __int64 v24; // x3
  unsigned int v25; // w20
  int v26; // w4
  int v27; // w2
  unsigned int v28; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  mutex_lock(a1 + 8);
  v2 = *((_DWORD *)a1 + 12);
  v3 = *a1;
  v29 = 0;
  updated = regmap_read(v3, (unsigned int)(v2 + 64), &v29);
  if ( (updated & 0x80000000) != 0 )
    goto LABEL_35;
  v5 = v29;
  v6 = *((_DWORD *)a1 + 6);
  v7 = *((_DWORD *)a1 + 12);
  a1[4] = 37000;
  v8 = *a1;
  *((_DWORD *)a1 + 10) = v5 & 3;
  v9 = v6 == 192 ? 16 : 8;
  v29 = 0;
  updated = regmap_read(v8, (unsigned int)(v7 + v9), &v29);
  if ( (updated & 0x80000000) != 0 )
    goto LABEL_35;
  v10 = *((_DWORD *)a1 + 6);
  if ( v10 == 8 )
  {
    v11 = 3;
  }
  else
  {
    if ( v10 != 192 )
    {
      v16 = ((unsigned __int64)v29 >> 4) & 7;
      *((_DWORD *)a1 + 11) = v16;
      v12 = alarm_state_map[v16];
      if ( v12 )
        goto LABEL_11;
      goto LABEL_17;
    }
    v11 = 1;
  }
  v12 = v29 & v11;
  *((_DWORD *)a1 + 11) = v29 & v11;
  if ( v12 )
  {
LABEL_11:
    if ( v10 == 192 || (a1[17] & 1) != 0 )
    {
      if ( (unsigned int)(v12 - 4) >= 0xFFFFFFFD )
      {
        v15 = &a1[(unsigned int)(v12 - 1) + 18];
        goto LABEL_24;
      }
    }
    else
    {
      v13 = a1[16];
      if ( v13 )
      {
        v14 = *((_DWORD *)a1 + 10);
        if ( (v14 | v12) <= 3 )
        {
          v15 = (__int64 *)(v13 + 24LL * v14 + 8LL * (unsigned int)(v12 - 1));
LABEL_24:
          v20 = *v15;
LABEL_25:
          a1[4] = v20;
          if ( v10 != 192 )
            goto LABEL_26;
          goto LABEL_18;
        }
      }
    }
    v20 = 0;
    goto LABEL_25;
  }
LABEL_17:
  if ( v10 != 192 )
  {
LABEL_26:
    v21 = *((unsigned __int8 *)a1 + 136);
    mutex_unlock(a1 + 8);
    v22 = a1[2];
    if ( v21 == 1 )
    {
      result = thermal_zone_for_each_trip(v22, qpnp_tm_temp_dac_configure_trip_temp, a1);
      if ( (result & 0x80000000) == 0 )
      {
        v23 = a1[19];
        if ( v23 <= a1[18] )
        {
          v26 = 0;
          v27 = 1;
          v24 = a1[19];
          v23 = a1[18];
        }
        else
        {
          v24 = a1[20];
          if ( v24 > v23 )
            goto LABEL_30;
          v26 = 1;
          v27 = 2;
        }
        dev_err(a1[1], "Threshold %d=%ld <= threshold %d=%ld\n", v27, v24, v26, v23);
        result = 4294967274LL;
        goto LABEL_37;
      }
      goto LABEL_37;
    }
    if ( (unsigned int)thermal_zone_get_crit_temp(v22, &v28) )
      v28 = -274000;
    mutex_lock(a1 + 8);
    updated = qpnp_tm_update_critical_trip_temp(a1, v28);
    if ( (updated & 0x80000000) == 0 )
      goto LABEL_34;
LABEL_35:
    v25 = updated;
    goto LABEL_36;
  }
LABEL_18:
  mutex_unlock(a1 + 8);
  result = thermal_zone_for_each_trip(a1[2], qpnp_tm_temp_lite_configure_trip_temp, a1);
  if ( (result & 0x80000000) == 0 )
  {
    v18 = a1[20];
    v19 = a1[18];
    if ( v18 > v19 )
    {
LABEL_30:
      mutex_lock(a1 + 8);
LABEL_34:
      v25 = regmap_write(*a1, (unsigned int)(*((_DWORD *)a1 + 12) + 70), 128);
      *((_BYTE *)a1 + 112) = 1;
LABEL_36:
      mutex_unlock(a1 + 8);
      result = v25;
      goto LABEL_37;
    }
    dev_err(a1[1], "Threshold 2=%ld <= threshold 0=%ld\n", v18, v19);
    result = 4294967274LL;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
