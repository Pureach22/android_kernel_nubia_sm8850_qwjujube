__int64 __fastcall thermal_dbgfs_config_write(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x2
  unsigned __int64 v8; // x1
  unsigned __int64 v9; // x9
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 zone_by_name; // x0
  _QWORD v21[2]; // [xsp+0h] [xbp-20h] BYREF
  int v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v21[0] = 0;
  v21[1] = 0;
  if ( (unsigned __int64)(a3 - 21) < 0xFFFFFFFFFFFFFFECLL )
    goto LABEL_2;
  v3 = a3;
  _check_object_size(v21, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v6 = a2 & ((__int64)(a2 << 8) >> 8);
  v7 = v3;
  if ( 0x8000000000LL - v3 >= v6 )
  {
    v9 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v15 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v15 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v15);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v9);
    goto LABEL_13;
  }
  do
  {
    if ( v3 - v7 <= 0x14 )
      v8 = 20 - (v3 - v7);
    else
      v8 = 0;
    if ( v8 >= v7 )
    {
      v3 = -14;
      goto LABEL_17;
    }
    _fortify_panic(15, v8, v7);
LABEL_13:
    v7 = _arch_copy_from_user(v21, a2 & 0xFF7FFFFFFFFFFFFFLL, v3);
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
  }
  while ( v7 );
  if ( sscanf((const char *)v21, "%19[^\n\t ]", &tzone_sensor_name) == 1 )
  {
    zone_by_name = thermal_zone_get_zone_by_name(&tzone_sensor_name);
    if ( zone_by_name >= 0xFFFFFFFFFFFFF001LL )
    {
      v3 = zone_by_name;
      printk(&unk_7118, "thermal_config", "thermal_dbgfs_config_write", &tzone_sensor_name, zone_by_name);
    }
  }
  else
  {
LABEL_2:
    v3 = -22;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v3;
}
