__int64 __fastcall msm_vidc_output_min_count(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0
  int v4; // w8
  __int64 v5; // x9
  int v6; // w10

  v1 = *(_DWORD *)(a1 + 308);
  if ( v1 != 2 )
  {
    if ( v1 != 1 )
      return 0;
    if ( *(_QWORD *)(a1 + 32576) )
      return 1;
    return 4;
  }
  if ( *(_QWORD *)(a1 + 32576) )
    return 1;
  result = *(unsigned int *)(a1 + 38716);
  v4 = *(_DWORD *)(a1 + 312);
  if ( (_DWORD)result )
  {
    if ( v4 == 64 )
      return result;
    v5 = a1;
    v6 = *(_DWORD *)(a1 + 18128);
    if ( (unsigned int)(v6 - 2) <= 0x3E && ((1LL << ((unsigned __int8)v6 - 2)) & 0x4000000000004005LL) != 0
      || v6 == 256
      || *(_QWORD *)(v5 + 20312) )
    {
      if ( v4 == 16 || v4 == 4 )
      {
LABEL_17:
        if ( (unsigned int)result >= 4 )
          return 4;
        else
          return (unsigned int)result;
      }
    }
    else if ( v4 == 16 && *(_QWORD *)(v5 + 34088) )
    {
      goto LABEL_17;
    }
  }
  else
  {
    switch ( v4 )
    {
      case 16:
        return 11;
      case 8:
        return 3;
      case 4:
        return 9;
      default:
        return 4;
    }
  }
  return result;
}
