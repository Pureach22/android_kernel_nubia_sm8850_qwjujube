__int64 __fastcall gen7_err_callback(__int64 *a1, int a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned int v5; // w20
  unsigned int v6; // w21
  int v8; // w20
  int v9; // w21

  v2 = *a1;
  if ( a2 > 23 )
  {
    switch ( a2 )
    {
      case 24:
        result = __ratelimit(&gen7_err_callback__rs_25, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(v2, "UCHE: Out of bounds access\n");
        break;
      case 25:
        result = __ratelimit(&gen7_err_callback__rs_27, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(v2, "UCHE: Trap interrupt\n");
        break;
      case 28:
        v5 = kgsl_regmap_read(a1 + 1650);
        v6 = kgsl_regmap_read(a1 + 1650);
        result = __ratelimit(&gen7_err_callback__rs_29, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(
                   v2,
                   "TSB: Write error interrupt: Address: 0x%lx MID: %lu\n",
                   v5 | ((v6 & 0x1FFFFLL) << 32),
                   (unsigned __int64)v6 >> 23);
        break;
      default:
LABEL_16:
        result = __ratelimit(&gen7_err_callback__rs_31, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(v2, "Unknown interrupt %d\n", a2);
        return result;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 1:
        v8 = kgsl_regmap_read(a1 + 1650);
        v9 = kgsl_regmap_read(a1 + 1650);
        result = __ratelimit(&gen7_err_callback__rs, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(v2, "CP: AHB bus error, CP_RL_ERROR_DETAILS_0:0x%x CP_RL_ERROR_DETAILS_1:0x%x\n", v8, v9);
        break;
      case 6:
        result = __ratelimit(&gen7_err_callback__rs_21, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(v2, "RBBM: ATB ASYNC overflow\n");
        break;
      case 22:
        result = __ratelimit(&gen7_err_callback__rs_23, "gen7_err_callback");
        if ( (_DWORD)result )
          return dev_crit(v2, "RBBM: ATB bus overflow\n");
        return result;
      default:
        goto LABEL_16;
    }
  }
  return result;
}
