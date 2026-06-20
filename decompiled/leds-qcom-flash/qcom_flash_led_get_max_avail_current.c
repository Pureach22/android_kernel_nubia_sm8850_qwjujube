__int64 __fastcall qcom_flash_led_get_max_avail_current(__int64 a1, int *a2)
{
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int prop; // w0
  __int64 v6; // x21
  int v7; // w22
  int v8; // w11
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x8
  bool v20; // cc
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned __int64 v23; // x8
  int v24; // w8
  void *v25; // x8
  unsigned int v26; // w19
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  int v28; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 8);
  v28 = 0;
  v27 = 0;
  if ( !*(_QWORD *)(v3 + 120) )
  {
    result = power_supply_get_by_name("battery");
    *(_QWORD *)(v3 + 120) = result;
    if ( !result )
    {
      v24 = 2000;
LABEL_29:
      *a2 = v24;
      goto LABEL_30;
    }
  }
  prop = qti_battery_charger_get_prop("battery", 0, &v28);
  if ( (prop & 0x80000000) != 0 )
  {
    v25 = &unk_8040;
    goto LABEL_34;
  }
  if ( v28 )
  {
    prop = power_supply_get_property(*(_QWORD *)(v3 + 120), 14, &v27);
    if ( (prop & 0x80000000) != 0 )
    {
      v25 = &unk_7E5B;
    }
    else
    {
      v6 = (int)v27;
      prop = power_supply_get_property(*(_QWORD *)(v3 + 120), 17, &v27);
      if ( (prop & 0x80000000) == 0 )
      {
        v7 = v27;
        if ( *(_DWORD *)(v3 + 132) )
        {
          raw_spin_lock(v3 + 128);
          raw_spin_unlock(v3 + 128);
        }
        if ( v28 >= 0 )
          v8 = v28;
        else
          v8 = v28 + 1;
        if ( (int)v6 > 2850000 != v28 < 1LL )
          v9 = (__int64)v8 >> 1;
        else
          v9 = -((__int64)v8 >> 1);
        v10 = (v9 + 1000000LL * (int)v6 - 2850000000000LL) / v28;
        if ( v10 >= 4500000 )
        {
          v13 = 4500000LL * v28;
          v11 = v7 + 4500000;
          v14 = (v13 - 500000) / 1000000;
          v15 = (v13 + 500000) / 0xF4240uLL;
          if ( v28 >= 1 )
            v16 = v15;
          else
            v16 = v14;
          v12 = 900 * (v6 - v16);
        }
        else
        {
          v11 = v10 - -v7;
          v12 = 2565000000LL;
        }
        v17 = v11 * v12;
        v18 = 1950000000;
        result = 0;
        if ( v17 <= 0 )
          v18 = -1950000000;
        v19 = v18 + v17;
        v20 = v19 <= 3899999999LL;
        v21 = v19 / 3900000000LL;
        v22 = 500;
        if ( v20 )
          v22 = -500;
        v23 = (unsigned __int128)((v22 + v21) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
        v24 = (v23 >> 7) + (v23 >> 63);
        if ( v24 >= 2000 )
          v24 = 2000;
        goto LABEL_29;
      }
      v25 = &unk_7D88;
    }
LABEL_34:
    v26 = prop;
    printk(v25, prop);
    result = v26;
    goto LABEL_30;
  }
  result = 0;
  *a2 = 2000;
  *(_BYTE *)(v3 + 146) = 1;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
