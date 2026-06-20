__int64 __fastcall a5xx_err_callback(_QWORD *a1, int a2)
{
  __int64 result; // x0
  unsigned int v4; // w20
  unsigned int v5; // w20
  unsigned int v6; // w20
  const char *v8; // x2

  if ( a2 > 5 )
  {
    if ( a2 <= 23 )
    {
      if ( a2 == 6 )
      {
        result = __ratelimit(&a5xx_err_callback__rs_11, "a5xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "RBBM: ATB ASYNC overflow\n");
        return result;
      }
      if ( a2 == 22 )
      {
        result = __ratelimit(&a5xx_err_callback__rs_13, "a5xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "RBBM: ATB bus overflow\n");
        return result;
      }
    }
    else
    {
      switch ( a2 )
      {
        case 24:
          result = __ratelimit(&a5xx_err_callback__rs_15, "a5xx_err_callback");
          if ( (_DWORD)result )
            return dev_crit(*a1, "UCHE: Out of bounds access\n");
          return result;
        case 25:
          result = __ratelimit(&a5xx_err_callback__rs_17, "a5xx_err_callback");
          if ( (_DWORD)result )
            return dev_crit(*a1, "UCHE: Trap interrupt\n");
          return result;
        case 28:
          result = __ratelimit(&a5xx_err_callback__rs_19, "a5xx_err_callback");
          if ( (_DWORD)result )
            return dev_crit(*a1, "GPMU: Voltage droop\n");
          return result;
      }
    }
LABEL_33:
    result = __ratelimit(&a5xx_err_callback__rs_21, "a5xx_err_callback");
    if ( (_DWORD)result )
      return dev_crit(*a1, "Unknown interrupt %d\n", (unsigned int)a2);
    return result;
  }
  if ( a2 > 2 )
  {
    if ( a2 == 3 )
    {
      v5 = kgsl_regmap_read(a1 + 1650);
      result = __ratelimit(&a5xx_err_callback__rs_5, "a5xx_err_callback");
      if ( (_DWORD)result )
        return dev_crit(*a1, "RBBM | ME master split timeout | status=%x\n", v5);
    }
    else if ( a2 == 4 )
    {
      v6 = kgsl_regmap_read(a1 + 1650);
      result = __ratelimit(&a5xx_err_callback__rs_7, "a5xx_err_callback");
      if ( (_DWORD)result )
        return dev_crit(*a1, "RBBM | PFP master split timeout | status=%x\n", v6);
    }
    else
    {
      result = __ratelimit(&a5xx_err_callback__rs_9, "a5xx_err_callback");
      if ( (_DWORD)result )
        return dev_crit(*a1, "RBBM: ME master split timeout\n");
    }
    return result;
  }
  if ( a2 != 1 )
  {
    if ( a2 == 2 )
    {
      result = __ratelimit(&a5xx_err_callback__rs_3, "a5xx_err_callback");
      if ( (_DWORD)result )
        return dev_crit(*a1, "RBBM: AHB transfer timeout\n");
      return result;
    }
    goto LABEL_33;
  }
  v4 = kgsl_regmap_read(a1 + 1650);
  if ( (unsigned int)__ratelimit(&a5xx_err_callback__rs, "a5xx_err_callback") )
  {
    if ( (v4 & 0x10000000) != 0 )
      v8 = "WRITE";
    else
      v8 = "READ";
    dev_crit(
      *a1,
      "RBBM | AHB bus error | %s | addr=%x | ports=%x:%x\n",
      v8,
      (v4 >> 2) & 0x3FFFF,
      (v4 >> 20) & 3,
      HIBYTE(v4) & 0xF);
  }
  return kgsl_regmap_write(a1 + 1650, 16);
}
