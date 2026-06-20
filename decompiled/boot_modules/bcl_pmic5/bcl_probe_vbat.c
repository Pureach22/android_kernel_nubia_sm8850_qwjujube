unsigned __int64 __fastcall bcl_probe_vbat(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  unsigned int v5; // w8
  __int64 v6; // x21
  __int64 v7; // x23
  int v8; // [xsp+0h] [xbp-10h] BYREF
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  result = _mutex_init(a2 + 440, "&vbat->state_trans_lock", &bcl_vbat_init___key);
  v5 = *(unsigned __int8 *)(a2 + 18);
  *(_QWORD *)(a2 + 592) = a2;
  *(_DWORD *)(a2 + 416) = 0;
  *(_BYTE *)(a2 + 488) = 0;
  *(_QWORD *)(a2 + 584) = 0;
  if ( v5 < 4 )
  {
    if ( !a2 )
    {
      result = printk(&unk_8411, "bcl_pmic5", "bcl_read_register");
      goto LABEL_17;
    }
    result = regmap_read(*(_QWORD *)(a2 + 8), (unsigned int)*(unsigned __int16 *)(a2 + 16) + 114, &v8);
    if ( (result & 0x80000000) != 0 )
    {
      result = printk(&unk_8594, "bcl_pmic5", "bcl_read_register");
      goto LABEL_17;
    }
    if ( (_DWORD)result || !v8 )
      goto LABEL_17;
    v6 = a2 + 496;
    v9 = 0;
    *(_QWORD *)(a2 + 568) = 0;
    *(_QWORD *)(a2 + 552) = 0;
    *(_QWORD *)(a2 + 560) = 0;
    *(_QWORD *)(a2 + 576) = 0;
    *(_QWORD *)(a2 + 520) = 0;
    *(_QWORD *)(a2 + 528) = bcl_write_vbat_tz;
    *(_QWORD *)(a2 + 536) = 0;
    *(_QWORD *)(a2 + 544) = 0;
    *(_QWORD *)(a2 + 496) = 0;
    *(_QWORD *)(a2 + 504) = bcl_read_vbat_tz;
    *(_QWORD *)(a2 + 512) = 0;
    goto LABEL_10;
  }
  if ( (*(_BYTE *)(a2 + 20) & 1) == 0 )
    goto LABEL_17;
  v6 = a2 + 496;
  v9 = 0;
  *(_QWORD *)(a2 + 568) = 0;
  *(_QWORD *)(a2 + 552) = 0;
  *(_QWORD *)(a2 + 560) = 0;
  *(_QWORD *)(a2 + 576) = 0;
  *(_QWORD *)(a2 + 520) = 0;
  *(_QWORD *)(a2 + 528) = bcl_write_vbat_tz;
  *(_QWORD *)(a2 + 536) = 0;
  *(_QWORD *)(a2 + 544) = 0;
  *(_QWORD *)(a2 + 496) = 0;
  *(_QWORD *)(a2 + 504) = bcl_read_vbat_tz;
  *(_QWORD *)(a2 + 512) = 0;
  if ( a2 )
  {
LABEL_10:
    v7 = *(_QWORD *)(a2 + 1888);
    if ( (regmap_read(*(_QWORD *)(a2 + 8), *(__int16 *)(v7 + 12) + (unsigned int)*(unsigned __int16 *)(a2 + 16), &v9)
        & 0x80000000) != 0 )
    {
      printk(&unk_8594, "bcl_pmic5", "bcl_read_register");
    }
    else if ( v9 )
    {
      *(_DWORD *)(a2 + 436) = *(_DWORD *)(v7 + 20) + 25 * v9;
    }
    goto LABEL_13;
  }
  printk(&unk_8411, "bcl_pmic5", "bcl_read_register");
LABEL_13:
  result = devm_thermal_of_zone_register(a1 + 16, 2, a2 + 416, v6);
  *(_QWORD *)(a2 + 584) = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_16:
    *(_QWORD *)(a2 + 584) = 0;
    goto LABEL_17;
  }
  result = thermal_zone_device_enable();
  if ( (_DWORD)result )
  {
    result = thermal_zone_device_unregister(*(_QWORD *)(a2 + 584));
    goto LABEL_16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
