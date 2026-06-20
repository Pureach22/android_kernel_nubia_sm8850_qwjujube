__int64 *__fastcall get_meta_buffer(__int64 *result, __int64 a2)
{
  __int64 v2; // x4
  __int64 v3; // x8
  __int64 *v4; // x8

  v2 = *(unsigned int *)(a2 + 24);
  if ( (_DWORD)v2 == 1 )
  {
    v3 = 328;
LABEL_5:
    v4 = &result[v3];
    result = v4;
    while ( 1 )
    {
      result = (__int64 *)*result;
      if ( result == v4 )
        break;
      if ( *((_DWORD *)result + 8) == *(_DWORD *)(a2 + 32) )
        return result;
    }
    return nullptr;
  }
  if ( (_DWORD)v2 == 2 )
  {
    v3 = 333;
    goto LABEL_5;
  }
  if ( !result )
    return result;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_88043, "err ", (char *)result + 340, "get_meta_buffer", v2);
  return nullptr;
}
