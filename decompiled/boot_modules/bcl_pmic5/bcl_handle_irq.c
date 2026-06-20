__int64 __fastcall bcl_handle_irq(int a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x21
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w8
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  int v19; // [xsp+10h] [xbp-10h] BYREF
  int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 168);
  v20 = 0;
  v18 = 0;
  v19 = 0;
  if ( !v2 )
    goto LABEL_16;
  v3 = *(_QWORD *)(a2 + 176);
  if ( v3 )
  {
    if ( (regmap_read(*(_QWORD *)(v3 + 8), (unsigned int)*(unsigned __int16 *)(v3 + 16) + 8, &v20) & 0x80000000) != 0 )
      printk(&unk_8594, "bcl_pmic5", "bcl_read_register");
  }
  else
  {
    printk(&unk_8411, "bcl_pmic5", "bcl_read_register");
  }
  v8 = *(_QWORD *)(v3 + 216);
  if ( v8 || (v8 = *(_QWORD *)(v3 + 1688)) != 0 )
    bcl_read_ibat(v8, &v19);
  v9 = *(_QWORD *)(v3 + 584);
  if ( v9 )
    bcl_read_vbat_tz(v9, &v18);
  if ( (*(_DWORD *)(a2 + 4) & v20) == 0 )
    goto LABEL_16;
  if ( !v3 || (v10 = *(_QWORD *)(v3 + 24)) == 0 )
  {
LABEL_15:
    thermal_zone_device_update(*(_QWORD *)(a2 + 168), 2);
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return 1;
  }
  v11 = *(_DWORD *)(a2 + 76);
  if ( v11 <= 0xA )
  {
    ipc_log_string(
      v10,
      "[%s]: %s: Irq:%d triggered for bcl type:%s. status:%u ibat=%d vbat=%d\n",
      (const char *)(_ReadStatusReg(SP_EL0) + 2320),
      "bcl_handle_irq",
      a1,
      &bcl_int_names[25 * v11],
      v20,
      v19,
      v18);
    goto LABEL_15;
  }
  __break(0x5512u);
  __asm { XAR             V30.2D, V5.2D, V0.2D, #0x12 }
  return bcl_read_lbat();
}
