__int64 __fastcall a6xx_cp_hw_err_callback(_QWORD *a1)
{
  __int64 result; // x0
  char v3; // w20
  int v4; // w21
  int v5; // w21
  int v6; // w21
  const char *v7; // x2

  result = kgsl_regmap_read(a1 + 1650);
  v3 = result;
  if ( (result & 1) != 0
    && (kgsl_regmap_write(a1 + 1650, 1),
        v4 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&a6xx_cp_hw_err_callback__rs, "a6xx_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(*a1, "CP opcode error interrupt | opcode=0x%8.8x\n", v4);
    if ( (v3 & 2) == 0 )
      goto LABEL_6;
  }
  else if ( (v3 & 2) == 0 )
  {
    goto LABEL_6;
  }
  result = __ratelimit(&a6xx_cp_hw_err_callback__rs_32, "a6xx_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(*a1, "CP ucode error interrupt\n");
LABEL_6:
  if ( (v3 & 4) != 0
    && (v5 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&a6xx_cp_hw_err_callback__rs_34, "a6xx_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(*a1, "CP | Ringbuffer HW fault | status=%x\n", v5);
    if ( (v3 & 0x10) == 0 )
      goto LABEL_10;
  }
  else if ( (v3 & 0x10) == 0 )
  {
    goto LABEL_10;
  }
  v6 = kgsl_regmap_read(a1 + 1650);
  result = __ratelimit(&a6xx_cp_hw_err_callback__rs_36, "a6xx_cp_hw_err_callback");
  if ( (_DWORD)result )
  {
    if ( (v6 & 0x100000) != 0 )
      v7 = "READ";
    else
      v7 = "WRITE";
    result = dev_crit(*a1, "CP | Protected mode error | %s | addr=%x | status=%x\n", v7, v6 & 0x3FFFF, v6);
  }
LABEL_10:
  if ( (v3 & 0x20) != 0
    && (result = __ratelimit(&a6xx_cp_hw_err_callback__rs_40, "a6xx_cp_hw_err_callback"), (_DWORD)result) )
  {
    result = dev_crit(*a1, "CP AHB error interrupt\n");
    if ( (v3 & 0x40) == 0 )
      goto LABEL_15;
  }
  else if ( (v3 & 0x40) == 0 )
  {
    goto LABEL_15;
  }
  result = __ratelimit(&a6xx_cp_hw_err_callback__rs_42, "a6xx_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(*a1, "CP VSD decoder parity error\n");
LABEL_15:
  if ( v3 < 0 )
  {
    result = __ratelimit(&a6xx_cp_hw_err_callback__rs_44, "a6xx_cp_hw_err_callback");
    if ( (_DWORD)result )
      return dev_crit(*a1, "CP Illegal instruction error\n");
  }
  return result;
}
