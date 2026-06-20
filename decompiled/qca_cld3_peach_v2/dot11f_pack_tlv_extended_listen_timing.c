__int64 __fastcall dot11f_pack_tlv_extended_listen_timing(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w21
  void *v7; // x20
  void *v8; // x19
  int v11; // w8
  __int16 v12; // [xsp+Ch] [xbp-14h] BYREF
  __int16 v13[2]; // [xsp+10h] [xbp-10h] BYREF
  __int16 v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= 7 )
  {
    if ( *(_BYTE *)a2 )
    {
      v6 = *a5;
      *a3 = 8;
      v7 = a3 + 5;
      v8 = a3 + 1;
      *a5 += 3;
      v12 = *(_WORD *)(a2 + 2);
      qdf_mem_copy(a3 + 3, &v12, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 4);
      qdf_mem_copy(v7, v13, 2u);
      v11 = *a5 + 2;
      *a5 = v11;
      if ( v8 )
      {
        v14 = v11 - v6 - 3;
        qdf_mem_copy(v8, &v14, 2u);
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
