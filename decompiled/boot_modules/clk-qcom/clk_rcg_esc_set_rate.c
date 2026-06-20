__int64 __fastcall clk_rcg_esc_set_rate(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  char v6; // w23
  int num_parents; // w0
  int v8; // w22
  __int64 result; // x0
  int v10; // w9
  __int64 v11; // x10
  unsigned __int8 *v12; // x11
  unsigned int v14; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h] BYREF
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_BYTE *)(a1 - 32);
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v14 = 0;
  num_parents = clk_hw_get_num_parents(a1);
  if ( !a2 )
  {
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
  v8 = num_parents;
  result = regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v14);
  if ( !(_DWORD)result )
  {
    v10 = (v14 >> *(_BYTE *)(a1 - 24)) & 7;
    v14 = v10;
    if ( v8 >= 1 )
    {
      v11 = (unsigned int)v8;
      v12 = (unsigned __int8 *)(*(_QWORD *)(a1 - 16) + 1LL);
      while ( v10 != *v12 )
      {
        --v11;
        v12 += 2;
        if ( !v11 )
          goto LABEL_9;
      }
      LOBYTE(v16) = *(v12 - 1);
    }
LABEL_9:
    if ( (int)(a3 / a2) >= 1 && (int)(a3 / a2) <= (int)(1LL << v6) )
    {
      BYTE1(v16) = a3 / a2;
      _clk_rcg_set_rate(a1 - 48, &v15);
      result = 0;
      goto LABEL_14;
    }
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
