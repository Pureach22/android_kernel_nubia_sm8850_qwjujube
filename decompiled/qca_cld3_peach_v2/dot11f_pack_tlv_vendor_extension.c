__int64 __fastcall dot11f_pack_tlv_vendor_extension(__int64 a1, _BYTE *a2, _WORD *a3, unsigned int a4, int *a5)
{
  int v5; // w24
  __int64 result; // x0
  char *v8; // x20
  unsigned int v12; // w21
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a5;
  v13 = 0;
  if ( a4 >= 7 )
  {
    if ( *a2 )
    {
      *a3 = 18704;
      v8 = (char *)a3 + 7;
      v12 = a4 - 4;
      *a5 += 4;
      qdf_mem_copy(a3 + 2, a2 + 1, 3u);
      *a5 += 3;
      result = pack_tlv_core(a1, (__int64)a2, v8, v12, a5, (__int64)&TLVS_VendorExtension, &v13);
      if ( a3 != (_WORD *)-2LL )
        a3[1] = bswap32(*a5 - v5 - 4) >> 16;
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
