__int64 __fastcall dot11f_pack_tlv_notice_of_absence(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  int v10; // w8
  __int16 v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)(unsigned __int8)a2[3] + 5 <= a4 )
  {
    if ( *a2 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 12;
      *a5 += 3;
      a3[3] = a2[1];
      ++*a5;
      a3[4] = a2[2];
      ++*a5;
      qdf_mem_copy(a3 + 5, a2 + 4, (unsigned __int8)a2[3]);
      v10 = *a5 + (unsigned __int8)a2[3];
      *a5 = v10;
      if ( v7 )
      {
        v11 = v10 - v6 - 3;
        qdf_mem_copy(v7, &v11, 2u);
      }
    }
    result = 0;
  }
  else
  {
    result = 268435461;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
