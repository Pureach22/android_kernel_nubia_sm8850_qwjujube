__int64 __fastcall dot11f_pack_tlv_p2_p_device_id(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  int v9; // w8
  __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= 9 )
  {
    if ( *a2 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 3;
      *a5 += 3;
      qdf_mem_copy(a3 + 3, a2 + 1, 6u);
      v9 = *a5 + 6;
      *a5 = v9;
      if ( v7 )
      {
        v10 = v9 - v6 - 3;
        qdf_mem_copy(v7, &v10, 2u);
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
