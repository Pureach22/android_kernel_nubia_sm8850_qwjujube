__int64 __fastcall handle_system_response(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int *v3; // x21
  unsigned int v6; // w9
  unsigned int *v7; // x22
  unsigned int v8; // w23
  __int64 result; // x0
  unsigned int v10; // w22

  v2 = *(_DWORD *)(a2 + 28);
  if ( !v2 )
    return 0;
  v3 = (unsigned int *)(a2 + 32);
  v6 = 0;
  v7 = (unsigned int *)(a2 + 32);
  while ( 1 )
  {
    if ( (v7[2] & 8) != 0 )
      goto LABEL_25;
    if ( v7[1] - 83886081 <= 0xFFFFFD )
      break;
    ++v6;
    v7 = (unsigned int *)((char *)v7 + *v7);
    if ( v6 >= v2 )
    {
      v8 = 0;
      v7 = (unsigned int *)(a2 + 32);
      while ( (v7[2] & 8) == 0 )
      {
        if ( v7[1] - 50331649 <= 0xFFFFFD )
        {
          result = handle_system_property(a1, v7);
          if ( (_DWORD)result )
            return result;
          v2 = *(_DWORD *)(a2 + 28);
        }
        ++v8;
        v7 = (unsigned int *)((char *)v7 + *v7);
        if ( v8 >= v2 )
        {
          if ( !v2 )
            return 0;
          v10 = 0;
          while ( (v3[2] & 8) == 0 )
          {
            if ( v3[1] - 16777217 <= 0xFFFFFD )
            {
              result = handle_system_init(a1, v3);
              if ( (_DWORD)result )
                return result;
              v2 = *(_DWORD *)(a2 + 28);
            }
            ++v10;
            result = 0;
            v3 = (unsigned int *)((char *)v3 + *v3);
            if ( v10 >= v2 )
              return result;
          }
          v7 = v3;
          break;
        }
      }
LABEL_25:
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_91007, "err ", 0xFFFFFFFFLL, "codec", "handle_system_response");
      ((void (__fastcall *)(__int64, unsigned int *))handle_system_error)(a1, v7);
      return 0;
    }
  }
  result = ((__int64 (__fastcall *)(__int64, unsigned int *))handle_system_error)(a1, v7);
  if ( (_DWORD)result )
    return result;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8D1E7, "err ", 0xFFFFFFFFLL, "codec", "handle_system_response");
  return 0;
}
