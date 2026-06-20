__int64 __fastcall _sdhci_msm_check_write(__int64 a1, unsigned __int16 a2, int a3)
{
  unsigned int v3; // w8
  unsigned __int16 v4; // w19
  __int16 v5; // w8
  __int64 v6; // x20
  unsigned __int16 v7; // w21
  int v8; // w8
  int v9; // w8
  __int64 v10; // x19
  __int64 v11; // x20
  int v12; // w8
  unsigned int v13; // w0
  int v15; // w8

  v3 = 0;
  v4 = a2;
  if ( a3 <= 40 )
  {
    if ( a3 == 12 )
    {
      v3 = 0;
      *(_DWORD *)(a1 + 1636) = a2;
      return v3;
    }
    if ( a3 != 14 )
      return v3;
    if ( (a2 & 8) != 0 )
    {
      v5 = *(_WORD *)(a1 + 2156);
      if ( (_BYTE)v5 )
      {
        if ( (v5 & 8) == 0 )
        {
          v6 = a1;
          v7 = a2;
          _const_udelay(34360);
          a2 = v7;
          a1 = v6;
        }
      }
    }
    v8 = *(unsigned __int8 *)(a1 + 1632);
    *(_WORD *)(a1 + 2156) = v4;
    if ( v8 == 1 )
    {
      if ( (*(_BYTE *)(a1 + 1636) & 0x10) != 0 )
      {
        v9 = HIBYTE(a2) & 0x3F;
        if ( v9 != 19 && v9 != 21 )
        {
          v10 = *(_QWORD *)(a1 + 1624);
          v11 = a1;
          v15 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v10 + 60)));
          v13 = v15 & 0xFFF5FFFF | 0x20000;
          if ( v13 == v15 )
            return 0;
          goto LABEL_19;
        }
      }
      v10 = *(_QWORD *)(a1 + 1624);
      v11 = a1;
      v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v10 + 60)));
      v13 = v12 & 0xFFF5FFFF | 0x80000;
      if ( v13 != v12 )
LABEL_19:
        writel_relaxed(v13, (unsigned int *)(*(_QWORD *)(v11 + 24) + *(unsigned int *)(v10 + 60)));
    }
    return 0;
  }
  switch ( a3 )
  {
    case ')':
      if ( a2 )
        v3 = 2;
      else
        v3 = 1;
      goto LABEL_27;
    case '/':
      v3 = 0;
      if ( (a2 & 1) != 0 && *(_BYTE *)(a1 + 824) )
      {
        v3 = 1;
LABEL_27:
        *(_BYTE *)(a1 + 1600) = 0;
        __dsb(0xFu);
      }
      break;
    case '>':
      if ( (a2 & 8) != 0 )
        v3 = 4;
      else
        v3 = 8;
      goto LABEL_27;
  }
  return v3;
}
