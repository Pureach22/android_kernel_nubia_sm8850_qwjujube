__int64 __fastcall a5xx_cp_hw_err_callback(_QWORD *a1)
{
  __int64 result; // x0
  char v3; // w20
  int v4; // w21
  int v5; // w21
  unsigned int v6; // w21
  int v7; // w20
  const char *v8; // x2

  result = kgsl_regmap_read(a1 + 1650);
  v3 = result;
  if ( (result & 1) != 0
    && (kgsl_regmap_write(a1 + 1650, 0),
        kgsl_regmap_read(a1 + 1650),
        v4 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&a5xx_cp_hw_err_callback__rs, "a5xx_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(*a1, "ringbuffer opcode error | possible opcode=0x%8.8X\n", v4);
    if ( (v3 & 2) == 0 )
      goto LABEL_6;
  }
  else if ( (v3 & 2) == 0 )
  {
    goto LABEL_6;
  }
  result = __ratelimit(&a5xx_cp_hw_err_callback__rs_25, "a5xx_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(*a1, "ringbuffer reserved bit error interrupt\n");
LABEL_6:
  if ( (v3 & 4) != 0
    && (v5 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&a5xx_cp_hw_err_callback__rs_27, "a5xx_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(*a1, "CP | Ringbuffer HW fault | status=%x\n", v5);
    if ( (v3 & 8) == 0 )
      goto LABEL_11;
  }
  else if ( (v3 & 8) == 0 )
  {
    goto LABEL_11;
  }
  result = __ratelimit(&a5xx_cp_hw_err_callback__rs_29, "a5xx_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(*a1, "CP | DMA error\n");
LABEL_11:
  if ( (v3 & 0x10) == 0
    || (v6 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&a5xx_cp_hw_err_callback__rs_31, "a5xx_cp_hw_err_callback"),
        !(_DWORD)result) )
  {
    if ( (v3 & 0x20) == 0 )
      return result;
    goto LABEL_14;
  }
  if ( (v6 & 0x1000000) != 0 )
    v8 = "WRITE";
  else
    v8 = "READ";
  result = dev_crit(*a1, "CP | Protected mode error| %s | addr=%x | status=%x\n", v8, (v6 >> 2) & 0x3FFFF, v6);
  if ( (v3 & 0x20) != 0 )
  {
LABEL_14:
    v7 = kgsl_regmap_read(a1 + 1650);
    result = __ratelimit(&a5xx_cp_hw_err_callback__rs_33, "a5xx_cp_hw_err_callback");
    if ( (_DWORD)result )
      return dev_crit(*a1, "ringbuffer AHB error interrupt | status=%x\n", v7);
  }
  return result;
}
