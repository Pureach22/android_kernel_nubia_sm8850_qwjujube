__int64 __fastcall dot11f_pack_tlv_listen_channel(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  int v11; // w8
  __int16 v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= 8 )
  {
    if ( *a2 )
    {
      v6 = *a5;
      v7 = a3 + 1;
      *a3 = 6;
      *a5 += 3;
      qdf_mem_copy(a3 + 3, a2 + 1, 3u);
      *a5 += 3;
      a3[6] = a2[4];
      ++*a5;
      a3[7] = a2[5];
      v11 = *a5 + 1;
      *a5 = v11;
      if ( v7 )
      {
        v12 = v11 - v6 - 3;
        qdf_mem_copy(v7, &v12, 2u);
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
