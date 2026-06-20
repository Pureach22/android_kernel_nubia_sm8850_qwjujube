__int64 __fastcall get_hfi_codec(__int64 result)
{
  __int64 v1; // x3

  v1 = *(unsigned int *)(result + 312);
  if ( (int)v1 <= 7 )
  {
    if ( (_DWORD)v1 == 1 )
    {
      if ( *(_DWORD *)(result + 308) == 1 )
        return 2;
      else
        return 1;
    }
    if ( (_DWORD)v1 != 2 )
    {
      if ( (_DWORD)v1 == 4 )
        return 5;
      goto LABEL_21;
    }
LABEL_15:
    if ( *(_DWORD *)(result + 308) == 1 )
      return 4;
    else
      return 3;
  }
  if ( (int)v1 > 31 )
  {
    if ( (_DWORD)v1 == 32 )
      return 6;
    if ( (_DWORD)v1 == 64 )
    {
      if ( *(_DWORD *)(result + 308) == 1 )
        return 10;
      else
        return 9;
    }
    goto LABEL_21;
  }
  if ( (_DWORD)v1 == 8 )
    goto LABEL_15;
  if ( (_DWORD)v1 == 16 )
    return 7;
LABEL_21:
  if ( result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8B276, "err ", result + 340, v1, *(unsigned int *)(result + 308));
    return 0;
  }
  return result;
}
