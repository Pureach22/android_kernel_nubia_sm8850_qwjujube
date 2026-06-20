__int64 __fastcall syna_tcm_testing_0001_check_device_id(__int64 a1, char *s2, size_t n)
{
  __int64 result; // x0
  int v6; // w22
  int v7; // w24
  int v8; // w23
  size_t v9; // x21
  const char *v10; // x0

  result = 0;
  if ( a1 && s2 )
  {
    v6 = 16 - n;
    if ( 16 - (int)n < 0 )
    {
LABEL_10:
      printk(unk_3CC6C, "syna_tcm_testing_0001_check_device_id", a1);
      return 0;
    }
    else
    {
      v7 = (unsigned __int8)*s2;
      v8 = 0;
      v9 = (unsigned int)n;
      while ( 1 )
      {
        v10 = (const char *)(a1 + v8);
        if ( *(unsigned __int8 *)v10 == v7 && !strncmp(v10, s2, v9) )
          return 1;
        if ( ++v8 > v6 )
          goto LABEL_10;
      }
    }
  }
  return result;
}
