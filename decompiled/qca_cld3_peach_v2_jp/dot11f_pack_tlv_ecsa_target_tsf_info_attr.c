__int64 __fastcall dot11f_pack_tlv_ecsa_target_tsf_info_attr(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned int a4,
        int *a5)
{
  __int64 result; // x0
  int v6; // w19
  _BYTE *v7; // x20
  int v11; // w8
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= 0xB )
  {
    if ( *(_BYTE *)a2 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 14;
      *a5 += 2;
      a3[2] = *(_BYTE *)(a2 + 1);
      ++*a5;
      v12 = *(_DWORD *)(a2 + 4);
      qdf_mem_copy(a3 + 3, &v12, 4u);
      v12 = *(_DWORD *)(a2 + 8);
      qdf_mem_copy(a3 + 7, &v12, 4u);
      result = 0;
      v11 = *a5 + 8;
      *a5 = v11;
      if ( v7 )
        *v7 = v11 - v6 - 2;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 268435461;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
