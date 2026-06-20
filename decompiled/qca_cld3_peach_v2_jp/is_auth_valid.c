__int64 __fastcall is_auth_valid(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 result; // x0

  v2 = *(unsigned __int16 *)(a1 + 2);
  if ( (v2 | 2) != 3 )
  {
    result = 1;
    if ( v2 == 4 )
      goto LABEL_6;
LABEL_5:
    if ( v2 != 2 )
      goto LABEL_9;
    goto LABEL_6;
  }
  result = *(_DWORD *)(a2 + 88) != 2;
  if ( v2 != 4 )
    goto LABEL_5;
LABEL_6:
  if ( *(_DWORD *)(a2 + 88) == 1 )
    result = 0;
  else
    result = (unsigned int)result;
LABEL_9:
  if ( (unsigned int)(v2 - 3) <= 1 && *(_BYTE *)(a1 + 6) != 16 )
  {
    if ( *(_WORD *)a1 == 1 )
      return (unsigned int)result;
    else
      return 0;
  }
  return result;
}
