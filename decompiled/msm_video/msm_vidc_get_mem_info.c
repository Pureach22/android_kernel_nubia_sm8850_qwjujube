__int64 __fastcall msm_vidc_get_mem_info(__int64 result, int a2, __int64 a3)
{
  if ( a2 <= 10 )
  {
    if ( a2 > 8 )
    {
      if ( a2 == 9 )
        result += 3096;
      else
        result += 3112;
      return result;
    }
    if ( a2 == 7 )
    {
      result += 3064;
      return result;
    }
    if ( a2 == 8 )
    {
      result += 3080;
      return result;
    }
  }
  else
  {
    if ( a2 <= 12 )
    {
      if ( a2 == 11 )
        result += 3128;
      else
        result += 3144;
      return result;
    }
    switch ( a2 )
    {
      case 13:
        result += 3160;
        return result;
      case 14:
        result += 3176;
        return result;
      case 15:
        result += 3192;
        return result;
    }
  }
  if ( result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_9780D, "err ", result + 340, a3, (unsigned int)a2);
    return 0;
  }
  return result;
}
