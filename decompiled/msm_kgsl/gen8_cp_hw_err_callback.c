__int64 __fastcall gen8_cp_hw_err_callback(_QWORD *a1)
{
  unsigned int *v2; // x23
  int v3; // w20
  __int64 result; // x0
  unsigned int v5; // w8
  int v6; // w20
  unsigned int v7; // w8
  unsigned int v8; // w9
  unsigned int v9; // w20
  unsigned int v10; // w21
  int v11; // w22
  unsigned int v12; // w20
  unsigned int v13; // w8
  unsigned int v14; // w9
  int v15; // w8
  unsigned int v16; // w21
  unsigned int v17; // w21
  const char *v18; // x3
  const char *v19; // x3
  const char *v20; // x2

  v2 = (unsigned int *)(a1 + 3068);
  v3 = kgsl_regmap_read(a1 + 1650);
  result = __ratelimit(&gen8_cp_hw_err_callback__rs, "gen8_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(*a1, "CP fault int_status_global=0x%x\n", v3);
  v5 = v3 & 0x7F;
  if ( v5 > 7 )
  {
    if ( (v3 & 0x7Fu) > 0x1F )
    {
      if ( v5 == 32 )
      {
        v6 = 6;
      }
      else
      {
        v6 = 0;
        if ( v5 == 64 )
          v6 = 7;
      }
    }
    else if ( v5 == 8 )
    {
      v6 = 4;
    }
    else
    {
      v6 = 0;
      if ( v5 == 16 )
        v6 = 5;
    }
    goto LABEL_39;
  }
  if ( (v3 & 0x7Fu) > 1 )
  {
    v6 = v3 & 0x7F;
    if ( v5 != 2 )
    {
      v6 = 0;
      if ( v5 == 4 )
        v6 = 3;
    }
    goto LABEL_39;
  }
  if ( (v3 & 0x7F) == 0 )
  {
    if ( (v3 & 0x7F0000) == 0 )
      return result;
    v7 = v2[17];
    v8 = (__clz(__rbit32(v7)) & 7) << 16;
    if ( v7 )
      v9 = v8;
    else
      v9 = 458752;
    if ( *v2 != v9 )
    {
      kgsl_regmap_write(a1 + 1650, v9);
      __dsb(0xFu);
      *v2 = v9;
    }
    v10 = kgsl_regmap_read(a1 + 1650);
    result = __ratelimit(&gen8_get_cp_swfault_status__rs, "gen8_get_cp_swfault_status");
    if ( (_DWORD)result )
    {
      if ( v10 > 0x1A )
        v19 = "UNKNOWN";
      else
        v19 = off_1665C0[v10];
      result = dev_crit(*a1, "CP SW Fault pipe_id: %u %s\n", 0, v19);
      if ( (v10 & 0x100) == 0 )
        goto LABEL_31;
    }
    else if ( (v10 & 0x100) == 0 )
    {
      goto LABEL_31;
    }
    if ( *v2 )
    {
      kgsl_regmap_write(a1 + 1650, 0);
      __dsb(0xFu);
      *v2 = 0;
    }
    kgsl_regmap_write(a1 + 1650, 1);
    if ( *v2 != v9 )
    {
      kgsl_regmap_write(a1 + 1650, v9);
      __dsb(0xFu);
      *v2 = v9;
    }
    v11 = kgsl_regmap_read(a1 + 1650);
    result = __ratelimit(&gen8_get_cp_swfault_status__rs_80, "gen8_get_cp_swfault_status");
    if ( (_DWORD)result )
      result = dev_crit(*a1, "CP opcode error interrupt | opcode=0x%8.8x\n", v11);
LABEL_31:
    if ( (v10 & 0x400) == 0 )
      goto LABEL_35;
    if ( *v2 != v9 )
    {
      kgsl_regmap_write(a1 + 1650, v9);
      __dsb(0xFu);
      *v2 = v9;
    }
    v12 = kgsl_regmap_read(a1 + 1650);
    result = __ratelimit(&gen8_get_cp_swfault_status__rs_82, "gen8_get_cp_swfault_status");
    if ( (_DWORD)result )
    {
      if ( (v12 & 0x100000LL) != 0 )
        v20 = "READ";
      else
        v20 = "WRITE";
      result = dev_crit(*a1, "CP | Protected mode error | %s | addr=%lx | status=%x\n", v20, v12 & 0x3FFFFLL, v12);
      if ( !*v2 )
        return result;
    }
    else
    {
LABEL_35:
      if ( !*v2 )
        return result;
    }
    result = kgsl_regmap_write(a1 + 1650, 0);
    __dsb(0xFu);
    *v2 = 0;
    return result;
  }
  v6 = v5 == 1;
LABEL_39:
  v13 = v2[17];
  v14 = (__clz(__rbit32(v13)) & 7) << 16;
  if ( v13 )
    v15 = v14;
  else
    v15 = 458752;
  v16 = v15 | (v6 << 12);
  if ( *v2 != v16 )
  {
    kgsl_regmap_write(a1 + 1650, v16);
    __dsb(0xFu);
    *v2 = v16;
  }
  v17 = kgsl_regmap_read(a1 + 1650);
  if ( *v2 )
  {
    kgsl_regmap_write(a1 + 1650, 0);
    __dsb(0xFu);
    *v2 = 0;
  }
  result = __ratelimit(&gen8_get_cp_hwfault_status__rs, "gen8_get_cp_hwfault_status");
  if ( (_DWORD)result )
  {
    if ( v17 > 0xA )
      v18 = "UNKNOWN";
    else
      v18 = off_166568[v17];
    return dev_crit(*a1, "CP HW Fault pipe_id:%u %s\n", v6, v18);
  }
  return result;
}
