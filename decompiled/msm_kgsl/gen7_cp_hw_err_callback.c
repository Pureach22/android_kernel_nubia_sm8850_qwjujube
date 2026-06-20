__int64 __fastcall gen7_cp_hw_err_callback(__int64 *a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  int v4; // w20
  int v5; // w22
  int v6; // w22
  unsigned int v7; // w22
  int v8; // w8
  int v9; // w22
  int v10; // w22
  unsigned int v11; // w21
  const char *v12; // x2
  const char *v13; // x2

  v2 = *a1;
  result = kgsl_regmap_read(a1 + 1650);
  v4 = result;
  if ( (result & 1) != 0
    && (kgsl_regmap_write(a1 + 1650, 1),
        v5 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&gen7_cp_hw_err_callback__rs, "gen7_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(v2, "CP opcode error interrupt | opcode=0x%8.8x\n", v5);
    if ( (v4 & 2) == 0 )
      goto LABEL_6;
  }
  else if ( (v4 & 2) == 0 )
  {
    goto LABEL_6;
  }
  result = __ratelimit(&gen7_cp_hw_err_callback__rs_35, "gen7_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(v2, "CP ucode error interrupt\n");
LABEL_6:
  if ( (v4 & 4) != 0
    && (v6 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&gen7_cp_hw_err_callback__rs_37, "gen7_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(v2, "CP | Ringbuffer HW fault | status=%x\n", v6);
    if ( (v4 & 0x10) == 0 )
      goto LABEL_10;
  }
  else if ( (v4 & 0x10) == 0 )
  {
    goto LABEL_10;
  }
  v7 = kgsl_regmap_read(a1 + 1650);
  result = __ratelimit(&gen7_cp_hw_err_callback__rs_39, "gen7_cp_hw_err_callback");
  if ( (_DWORD)result )
  {
    if ( (v7 & 0x100000) != 0 )
      v12 = "READ";
    else
      v12 = "WRITE";
    result = dev_crit(v2, "CP | Protected mode error | %s | addr=%x | status=%x\n", v12, v7 & 0x3FFFF, v7);
  }
LABEL_10:
  if ( (v4 & 0x40) != 0
    && (result = __ratelimit(&gen7_cp_hw_err_callback__rs_43, "gen7_cp_hw_err_callback"), (_DWORD)result) )
  {
    result = dev_crit(v2, "CP VSD decoder parity error\n");
    if ( (v4 & 0x80) == 0 )
      goto LABEL_15;
  }
  else if ( (v4 & 0x80) == 0 )
  {
    goto LABEL_15;
  }
  result = __ratelimit(&gen7_cp_hw_err_callback__rs_45, "gen7_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(v2, "CP Illegal instruction error\n");
LABEL_15:
  if ( (*(_BYTE *)(a1[1783] + 33) & 0x40) == 0 )
    goto LABEL_29;
  if ( (v4 & 0x100) != 0
    && (result = __ratelimit(&gen7_cp_hw_err_callback__rs_47, "gen7_cp_hw_err_callback"), (_DWORD)result) )
  {
    result = dev_crit(v2, "CP Opcode error LPAC\n");
    if ( (v4 & 0x200) == 0 )
      goto LABEL_21;
  }
  else if ( (v4 & 0x200) == 0 )
  {
    goto LABEL_21;
  }
  result = __ratelimit(&gen7_cp_hw_err_callback__rs_49, "gen7_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(v2, "CP ucode error LPAC\n");
LABEL_21:
  if ( (v4 & 0x400) != 0
    && (result = __ratelimit(&gen7_cp_hw_err_callback__rs_51, "gen7_cp_hw_err_callback"), (_DWORD)result) )
  {
    result = dev_crit(v2, "CP hw fault LPAC\n");
    if ( (v4 & 0x800) != 0 )
    {
LABEL_24:
      result = __ratelimit(&gen7_cp_hw_err_callback__rs_53, "gen7_cp_hw_err_callback");
      if ( (_DWORD)result )
        result = dev_crit(v2, "CP register protection LPAC\n");
    }
  }
  else if ( (v4 & 0x800) != 0 )
  {
    goto LABEL_24;
  }
  if ( (v4 & 0x1000) != 0 )
  {
    result = __ratelimit(&gen7_cp_hw_err_callback__rs_55, "gen7_cp_hw_err_callback");
    if ( (_DWORD)result )
      result = dev_crit(v2, "CP illegal instruction LPAC\n");
  }
LABEL_29:
  v8 = *(_DWORD *)a1[1783];
  if ( v8 == 459520 || v8 == 462336 || v8 == 463104 )
    return result;
  if ( (v4 & 0x2000) != 0
    && (kgsl_regmap_write(a1 + 1650, 1),
        v9 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&gen7_cp_hw_err_callback__rs_57, "gen7_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(v2, "CP opcode error BV | opcode=0x%8.8x\n", v9);
    if ( (v4 & 0x4000) == 0 )
      goto LABEL_37;
  }
  else if ( (v4 & 0x4000) == 0 )
  {
    goto LABEL_37;
  }
  result = __ratelimit(&gen7_cp_hw_err_callback__rs_59, "gen7_cp_hw_err_callback");
  if ( (_DWORD)result )
    result = dev_crit(v2, "CP ucode error BV\n");
LABEL_37:
  if ( (v4 & 0x8000) != 0
    && (v10 = kgsl_regmap_read(a1 + 1650),
        result = __ratelimit(&gen7_cp_hw_err_callback__rs_61, "gen7_cp_hw_err_callback"),
        (_DWORD)result) )
  {
    result = dev_crit(v2, "CP BV | Ringbuffer HW fault | status=%x\n", v10);
    if ( (v4 & 0x10000) != 0 )
    {
LABEL_40:
      v11 = kgsl_regmap_read(a1 + 1650);
      result = __ratelimit(&gen7_cp_hw_err_callback__rs_63, "gen7_cp_hw_err_callback");
      if ( (_DWORD)result )
      {
        if ( (v11 & 0x100000) != 0 )
          v13 = "READ";
        else
          v13 = "WRITE";
        result = dev_crit(v2, "CP BV | Protected mode error | %s | addr=%x | status=%x\n", v13, v11 & 0x3FFFF, v11);
      }
    }
  }
  else if ( (v4 & 0x10000) != 0 )
  {
    goto LABEL_40;
  }
  if ( (v4 & 0x20000) != 0 )
  {
    result = __ratelimit(&gen7_cp_hw_err_callback__rs_65, "gen7_cp_hw_err_callback");
    if ( (_DWORD)result )
      return dev_crit(v2, "CP illegal instruction BV\n");
  }
  return result;
}
