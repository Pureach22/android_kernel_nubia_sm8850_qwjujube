__int64 __fastcall a6xx_err_callback(_QWORD *a1, int a2)
{
  __int64 result; // x0

  if ( a2 > 23 )
  {
    switch ( a2 )
    {
      case 24:
        result = __ratelimit(&a6xx_err_callback__rs_22, "a6xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "UCHE: Out of bounds access\n");
        break;
      case 25:
        result = __ratelimit(&a6xx_err_callback__rs_24, "a6xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "UCHE: Trap interrupt\n");
        break;
      case 28:
        result = __ratelimit(&a6xx_err_callback__rs_26, "a6xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "TSB: Write error interrupt\n");
        break;
      default:
LABEL_16:
        result = __ratelimit(&a6xx_err_callback__rs_28, "a6xx_err_callback");
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
        result = __ratelimit(&a6xx_err_callback__rs, "a6xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "CP: AHB bus error\n");
        break;
      case 6:
        result = __ratelimit(&a6xx_err_callback__rs_18, "a6xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "RBBM: ATB ASYNC overflow\n");
        break;
      case 22:
        result = __ratelimit(&a6xx_err_callback__rs_20, "a6xx_err_callback");
        if ( (_DWORD)result )
          return dev_crit(*a1, "RBBM: ATB bus overflow\n");
        return result;
      default:
        goto LABEL_16;
    }
  }
  return result;
}
