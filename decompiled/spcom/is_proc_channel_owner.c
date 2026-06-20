__int64 __fastcall is_proc_channel_owner(_DWORD *a1, int a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  __int64 v5; // x0

  v2 = a1[59];
  if ( !v2 )
    return 0;
  if ( a1[74] == a2 )
    return 1;
  result = v2 != 1;
  if ( v2 != 1 && a1[75] != a2 )
  {
    result = v2 > 2;
    if ( v2 != 2 && a1[76] != a2 )
    {
      result = v2 > 3;
      if ( v2 != 3 && a1[77] != a2 )
      {
        result = v2 > 4;
        if ( v2 != 4 && a1[78] != a2 )
        {
          result = v2 > 5;
          if ( v2 != 5 )
          {
            __break(0x5512u);
            v5 = MEMORY[0x47B5BAC](result);
            return is_arg_size_expected(v5);
          }
        }
      }
    }
  }
  return result;
}
