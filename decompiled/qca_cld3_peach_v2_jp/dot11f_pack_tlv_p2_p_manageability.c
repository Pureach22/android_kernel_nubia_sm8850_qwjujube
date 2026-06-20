__int64 __fastcall dot11f_pack_tlv_p2_p_manageability(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w8
  int v7; // w9
  __int16 v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= 4 )
  {
    if ( *a2 )
    {
      v6 = *a5;
      result = (__int64)(a3 + 1);
      *a3 = 10;
      *a5 += 3;
      a3[3] = a2[1];
      v7 = *a5 + 1;
      *a5 = v7;
      if ( a3 == (_BYTE *)-1LL )
        goto LABEL_7;
      v8 = v7 - v6 - 3;
      qdf_mem_copy((void *)result, &v8, 2u);
    }
    result = 0;
    goto LABEL_7;
  }
  result = 268435461;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
