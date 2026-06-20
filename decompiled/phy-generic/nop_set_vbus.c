__int64 __fastcall nop_set_vbus(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  bool v4; // w8

  v2 = *(_QWORD *)(**(_QWORD **)(a1 + 16) + 152LL);
  result = *(_QWORD *)(v2 + 408);
  if ( result )
  {
    if ( (a2 & 1) != 0 )
    {
      if ( (*(_BYTE *)(v2 + 416) & 1) == 0 )
      {
        result = regulator_enable();
        v4 = (_DWORD)result == 0;
LABEL_7:
        *(_BYTE *)(v2 + 416) = v4;
        return result;
      }
    }
    else if ( *(_BYTE *)(v2 + 416) )
    {
      result = regulator_disable(result);
      v4 = 0;
      goto LABEL_7;
    }
    return 0;
  }
  return result;
}
