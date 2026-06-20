__int64 __fastcall fan_level_set(unsigned __int8 *a1, unsigned __int8 a2)
{
  int v2; // w19
  __int64 v4; // x21
  void *v5; // x0
  __int64 v6; // x3
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x0
  int raw_value; // w0
  __int64 v11; // x3
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x9
  int v15; // w10
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 (__fastcall *v20)(__int64, __int64, __int64 *, __int64); // x8
  __int64 result; // x0
  unsigned int v22; // w20
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  __int64 v24; // [xsp+8h] [xbp-18h]
  __int64 v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v2 = a2;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a1 == a2 )
  {
    printk(&unk_8351, "NB_FAN", "fan_level_set", 148);
    result = 0;
    goto LABEL_18;
  }
  v4 = *(_QWORD *)(chip + 72);
  if ( a2 )
  {
    if ( !v4 || (unsigned int)regulator_is_enabled(*(_QWORD *)(chip + 72)) )
      goto LABEL_8;
    regulator_enable(v4);
    msleep(10);
    v5 = &unk_82EC;
    v6 = 237;
  }
  else
  {
    if ( !v4 || !(unsigned int)regulator_is_enabled(*(_QWORD *)(chip + 72)) )
      goto LABEL_8;
    regulator_disable(v4);
    v5 = &unk_7912;
    v6 = 229;
  }
  printk(v5, "NB_FAN", "nb_fan_power_set", v6);
LABEL_8:
  v7 = *(_QWORD *)(*((_QWORD *)a1 + 13) + 64LL);
  v24 = (unsigned int)(8000 * v2);
  v25 = v7;
  BYTE4(v25) = v2 != 0;
  v8 = *(_QWORD *)(chip + 8);
  v23 = 40000;
  v9 = gpio_to_desc(*(unsigned int *)(v8 + 16));
  raw_value = gpiod_get_raw_value(v9);
  if ( v2 == 5 )
  {
    if ( raw_value == 1 )
    {
      v12 = gpio_to_desc(*(unsigned int *)(*(_QWORD *)(chip + 8) + 16LL));
      gpiod_direction_output_raw(v12, 0);
    }
    v13 = *((_QWORD *)a1 + 13);
    v14 = *(_QWORD *)(v13 + 64);
    v15 = *(_DWORD *)(v13 + 40);
    v16 = *(_QWORD *)(v13 + 32);
    v24 = 0;
    HIWORD(v25) = HIWORD(v14);
    LODWORD(v25) = v15;
    v23 = v16;
    WORD2(v25) = 0;
  }
  else if ( !raw_value )
  {
    v17 = gpio_to_desc(*(unsigned int *)(*(_QWORD *)(chip + 8) + 16LL));
    gpiod_direction_output_raw(v17, 1);
  }
  v18 = *((_QWORD *)a1 + 13);
  v19 = *(_QWORD *)(v18 + 24);
  v20 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(*(_QWORD *)(v19 + 912) + 24LL);
  if ( *((_DWORD *)v20 - 1) != -573532208 )
    __break(0x8228u);
  result = v20(v19, v18, &v23, v11);
  if ( (result & 0x80000000) != 0 )
  {
    v22 = result;
    printk(&unk_7E98, "NB_FAN", "fan_level_set", 191);
    result = v22;
  }
  else
  {
    *a1 = v2;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
