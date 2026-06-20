__int64 __fastcall gdsc_set_hwmode(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x0
  __int64 v6; // x3
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w8
  __int64 v14; // x1
  __int64 v15; // x0
  int v16; // w0
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 1544);
  if ( (a3 & 1) != 0 )
    v6 = 2;
  else
    v6 = 0;
  result = regmap_update_bits_base(v5, *(unsigned int *)(a1 + 1552), 2, v6, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    v8 = _const_udelay(4295);
    if ( (a3 & 1) == 0 )
    {
      v9 = ktime_get(v8);
      while ( 1 )
      {
        if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
        {
          v10 = (unsigned int)(*(_DWORD *)(a1 + 1552) + 4);
        }
        else
        {
          v10 = *(unsigned int *)(a1 + 1564);
          if ( !(_DWORD)v10 )
            v10 = *(unsigned int *)(a1 + 1552);
        }
        v11 = *(_QWORD *)(a1 + 1544);
        v17 = 0;
        v12 = regmap_read(v11, v10, &v17);
        if ( (_DWORD)v12 )
          break;
        v13 = HIWORD(v17) & 1;
        if ( (*(_WORD *)(a1 + 1602) & 0x20) == 0 )
          v13 = v17 >> 31;
        if ( v13 )
          break;
        if ( ktime_get(v12) - v9 >= 2000000 )
        {
          if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
          {
            v14 = (unsigned int)(*(_DWORD *)(a1 + 1552) + 4);
          }
          else
          {
            v14 = *(unsigned int *)(a1 + 1564);
            if ( !(_DWORD)v14 )
              v14 = *(unsigned int *)(a1 + 1552);
          }
          v15 = *(_QWORD *)(a1 + 1544);
          v17 = 0;
          v16 = regmap_read(v15, v14, &v17);
          if ( !v16 )
          {
            if ( (*(_WORD *)(a1 + 1602) & 0x20) != 0 )
              v16 = HIWORD(v17) & 1;
            else
              v16 = v17 >> 31;
          }
          if ( v16 )
            result = 0;
          else
            result = 4294967186LL;
          goto LABEL_7;
        }
      }
    }
    result = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
