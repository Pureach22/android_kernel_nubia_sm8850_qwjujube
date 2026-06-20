__int64 __fastcall reg_chan_in_range(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x10
  unsigned int v10; // w11
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 result; // x0

  v6 = 0;
  v7 = a1;
  do
  {
    if ( *(_DWORD *)v7 - (*(unsigned __int16 *)(v7 + 20) >> 1) >= a2 )
      break;
    ++v6;
    v7 += 36;
  }
  while ( v6 != 102 );
  v8 = 0;
  v9 = a1;
  do
  {
    if ( *(_DWORD *)v9 - (*(unsigned __int16 *)(v9 + 20) >> 1) >= a4 )
      break;
    ++v8;
    v9 += 36;
  }
  while ( v8 != 102 );
  v10 = *(_DWORD *)(a1 + 3636) + (*(unsigned __int16 *)(a1 + 3656) >> 1);
  v11 = 101;
  if ( v10 <= a3 )
  {
LABEL_10:
    if ( v10 <= a5 )
      goto LABEL_16;
LABEL_11:
    v12 = 101;
    while ( v12 )
    {
      --v12;
      if ( *(_DWORD *)(a1 + 36LL * (unsigned int)v12) + (*(unsigned __int16 *)(a1 + 36LL * (unsigned int)v12 + 20) >> 1) <= a5 )
        goto LABEL_17;
    }
    LODWORD(v12) = 102;
    if ( (unsigned int)v6 > a6 )
      goto LABEL_18;
    goto LABEL_21;
  }
  while ( v11 )
  {
    --v11;
    if ( *(_DWORD *)(a1 + 36LL * (unsigned int)v11) + (*(unsigned __int16 *)(a1 + 36LL * (unsigned int)v11 + 20) >> 1) <= a3 )
      goto LABEL_10;
  }
  LODWORD(v11) = 102;
  if ( v10 > a5 )
    goto LABEL_11;
LABEL_16:
  LODWORD(v12) = 101;
LABEL_17:
  if ( (unsigned int)v6 > a6 )
  {
LABEL_18:
    result = 0;
    if ( (unsigned int)v8 > a6 )
      return result;
    goto LABEL_31;
  }
LABEL_21:
  result = (_DWORD)v6 != 102 && (_DWORD)v11 != 102 && (unsigned int)v11 >= a6;
  if ( (unsigned int)v8 <= a6 )
  {
LABEL_31:
    if ( (_DWORD)v8 != 102 && (_DWORD)v12 != 102 && (unsigned int)v12 >= a6 )
      return 1;
    else
      return (unsigned int)result;
  }
  return result;
}
