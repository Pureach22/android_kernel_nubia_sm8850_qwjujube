__int64 __fastcall target_if_cfr_fill_header(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 result; // x0
  char v8; // w8
  char v9; // w8

  *(_BYTE *)(a1 + 11) = 2;
  *(_QWORD *)a1 = 0x8CFDF0DEADBEAFLL;
  *(_DWORD *)(a1 + 12) = 136;
  *(_BYTE *)(a1 + 9) = 1;
  result = ktime_get_with_offset(0);
  v8 = 9;
  *(_QWORD *)(a1 + 16) = result;
  if ( a3 > 28 )
  {
    if ( (unsigned int)a3 > 0x2B )
      goto LABEL_17;
    if ( ((1LL << a3) & 0xDEC80000000LL) == 0 )
    {
      if ( ((1LL << a3) & 0x1100000000LL) != 0 )
        goto LABEL_13;
      if ( a3 == 33 )
      {
        *(_BYTE *)(a1 + 8) = 8;
        v9 = 31;
        goto LABEL_16;
      }
LABEL_17:
      if ( a3 != 29 || (a4 & 1) != 0 )
      {
LABEL_19:
        v8 = 3;
        goto LABEL_13;
      }
      goto LABEL_20;
    }
LABEL_12:
    v8 = 7;
    goto LABEL_13;
  }
  if ( a3 > 26 )
    goto LABEL_12;
  if ( a3 == 24 )
  {
    *(_BYTE *)(a1 + 8) = 8;
    v9 = 23;
    goto LABEL_16;
  }
  if ( a3 != 25 )
  {
    if ( a3 == 26 )
      goto LABEL_13;
    goto LABEL_19;
  }
LABEL_20:
  v8 = 5;
LABEL_13:
  *(_BYTE *)(a1 + 8) = v8;
  if ( (unsigned int)(a3 - 26) > 0x11 )
    v9 = 24;
  else
    v9 = byte_A2C518[a3 - 26];
LABEL_16:
  *(_BYTE *)(a1 + 10) = v9;
  return result;
}
