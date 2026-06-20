__int64 __fastcall dot11f_pack_ie_obss_scan_parameters(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, int *a5)
{
  __int64 result; // x0
  int v6; // w20
  void *v7; // x19
  _BYTE *v8; // x21
  int v12; // w8
  _WORD v13[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)a2 )
  {
    if ( a4 >= 0xE )
    {
      v6 = *a5;
      *a3 = 74;
      v7 = a3 + 14;
      v8 = a3 + 1;
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 2);
      qdf_mem_copy(a3 + 2, v13, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 4);
      qdf_mem_copy(a3 + 4, v13, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 6);
      qdf_mem_copy(a3 + 6, v13, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 8);
      qdf_mem_copy(a3 + 8, v13, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 10);
      qdf_mem_copy(a3 + 10, v13, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 12);
      qdf_mem_copy(a3 + 12, v13, 2u);
      *a5 += 2;
      v13[0] = *(_WORD *)(a2 + 14);
      qdf_mem_copy(v7, v13, 2u);
      result = 0;
      v12 = *a5 + 2;
      *a5 = v12;
      if ( v8 )
        *v8 = v12 - v6 - 2;
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
