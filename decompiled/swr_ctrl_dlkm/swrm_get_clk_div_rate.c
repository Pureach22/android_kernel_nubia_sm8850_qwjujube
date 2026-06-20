__int64 __fastcall swrm_get_clk_div_rate(__int64 result, int a2)
{
  if ( a2 && (_DWORD)result != 12288000 && (_DWORD)result != 11289600 )
  {
    if ( (_DWORD)result == 9600000 )
    {
      result = 600000;
      if ( a2 >= 600001 )
      {
        if ( (unsigned int)a2 <= 0x493E00 )
          return 4800000;
        else
          return 9600000;
      }
    }
    else
    {
      return (unsigned int)a2;
    }
  }
  return result;
}
