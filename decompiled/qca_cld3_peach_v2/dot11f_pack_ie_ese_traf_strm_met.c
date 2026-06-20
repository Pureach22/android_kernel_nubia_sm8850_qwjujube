__int64 __fastcall dot11f_pack_ie_ese_traf_strm_met(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v9; // w8
  __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 4 )
    {
      v6 = *a5;
      *a3 = -35;
      v7 = a3 + 1;
      *a5 += 2;
      a3[2] = 0;
      ++*a5;
      a3[3] = 64;
      ++*a5;
      a3[4] = -106;
      ++*a5;
      a3[5] = 7;
      ++*a5;
      a3[6] = *(_BYTE *)(a2 + 1);
      ++*a5;
      a3[7] = *(_BYTE *)(a2 + 2);
      ++*a5;
      v10 = *(_WORD *)(a2 + 4);
      qdf_mem_copy(a3 + 8, &v10, 2u);
      result = 0;
      v9 = *a5 + 2;
      *a5 = v9;
      if ( v7 )
        *v7 = v9 - v6 - 2;
    }
    else
    {
      result = 268435461;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
