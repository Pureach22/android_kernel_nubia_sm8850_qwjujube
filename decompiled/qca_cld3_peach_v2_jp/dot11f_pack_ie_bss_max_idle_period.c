__int64 __fastcall dot11f_pack_ie_bss_max_idle_period(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w19
  int v10; // w9
  __int16 v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 3 )
    {
      v6 = *a5;
      *a3 = 90;
      *a5 += 2;
      v11 = *(_WORD *)(a2 + 2);
      qdf_mem_copy(a3 + 2, &v11, 2u);
      result = 0;
      *a5 += 2;
      a3[4] = *(_BYTE *)(a2 + 4);
      v10 = *a5 + 1;
      *a5 = v10;
      if ( a3 != (_BYTE *)-1LL )
        a3[1] = v10 - v6 - 2;
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
