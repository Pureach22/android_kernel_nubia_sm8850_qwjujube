__int64 __fastcall gen7_fenced_write(_QWORD *a1, int a2, unsigned int a3, int a4)
{
  __int64 v8; // x8
  __int64 v9; // x25
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x23
  int v12; // w24
  unsigned int v13; // w27
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  __int64 result; // x0
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1[1783];
  v17 = 0;
  v9 = *(_QWORD *)(v8 + 40);
  kgsl_regmap_write(a1 + 1650, a3);
  v10 = *(__int64 (__fastcall **)(_QWORD))(v9 + 152);
  if ( *((_DWORD *)v10 - 1) != -944375624 )
    __break(0x8228u);
  v11 = v10(a1);
  v12 = 0;
  v13 = 0;
  while ( 1 )
  {
    __dsb(0xFu);
    gmu_core_regread(a1, 146195, &v17);
    if ( (v17 & a4) == 0 )
      break;
    _const_udelay(42950);
    kgsl_regmap_write(a1 + 1650, a3);
    ++v13;
    v12 += 10;
    if ( v13 == 200 )
    {
      v14 = *(__int64 (__fastcall **)(_QWORD))(v9 + 152);
      if ( *((_DWORD *)v14 - 1) != -944375624 )
        __break(0x8228u);
      v15 = v14(a1);
      dev_err(
        *a1,
        "Timed out waiting %d usecs to write fenced register 0x%x, timestamps: %llx %llx\n",
        2000,
        a2,
        v11,
        v15);
      result = 4294967186LL;
      goto LABEL_12;
    }
  }
  if ( v13 >= 0x64 )
    dev_info(*a1, "Waited %d usecs to write fenced register 0x%x\n", v12, a2);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
