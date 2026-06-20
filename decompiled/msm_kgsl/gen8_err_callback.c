__int64 __fastcall gen8_err_callback(_QWORD *a1, int a2)
{
  __int64 result; // x0
  unsigned int v4; // w20
  unsigned int v5; // w21
  int v6; // w20
  int v7; // w21

  if ( a2 > 23 )
  {
    switch ( a2 )
    {
      case 24:
        result = __ratelimit(&gen8_err_callback__rs_38, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "UCHE: Out of bounds access\n");
        break;
      case 25:
        result = __ratelimit(&gen8_err_callback__rs_40, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "UCHE: Trap interrupt\n");
        break;
      case 28:
        v4 = kgsl_regmap_read(a1 + 1650);
        v5 = kgsl_regmap_read(a1 + 1650);
        result = __ratelimit(&gen8_err_callback__rs_42, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(
                   *a1,
                   "TSB: Write error interrupt: Address: 0x%lx MID: %lu\n",
                   v4 | ((v5 & 0x1FFFFLL) << 32),
                   (unsigned __int64)v5 >> 23);
        break;
      default:
LABEL_16:
        result = __ratelimit(&gen8_err_callback__rs_44, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "Unknown interrupt %d\n", a2);
        return result;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 1:
        v6 = kgsl_regmap_read(a1 + 1650);
        v7 = kgsl_regmap_read(a1 + 1650);
        result = __ratelimit(&gen8_err_callback__rs, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "CP: AHB bus error, CP_RL_ERROR_DETAILS_0:0x%x CP_RL_ERROR_DETAILS_1:0x%x\n", v6, v7);
        break;
      case 6:
        result = __ratelimit(&gen8_err_callback__rs_34, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "RBBM: ATB ASYNC overflow\n");
        break;
      case 22:
        result = __ratelimit(&gen8_err_callback__rs_36, "gen8_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "RBBM: ATB bus overflow\n");
        return result;
      default:
        goto LABEL_16;
    }
  }
  return result;
}
