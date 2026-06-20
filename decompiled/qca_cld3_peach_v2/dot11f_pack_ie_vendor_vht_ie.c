__int64 __fastcall dot11f_pack_ie_vendor_vht_ie(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v7; // w23
  __int64 result; // x0
  char *v12; // x2
  _BYTE *v13; // x24
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*a2 )
    goto LABEL_6;
  v7 = *a5;
  v14 = 1;
  result = get_packed_size_core(a1, (__int64)a2, (int *)&v14, IES_vendor_vht_ie);
  if ( (_DWORD)result )
    goto LABEL_7;
  if ( !*a2 )
  {
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  if ( v14 <= a4 )
  {
    *a3 = -35;
    v12 = a3 + 7;
    *a5 += 2;
    a3[2] = 0;
    ++*a5;
    a3[3] = -112;
    ++*a5;
    a3[4] = 76;
    ++*a5;
    a3[5] = 4;
    ++*a5;
    a3[6] = a2[1];
    v13 = a3 + 1;
    ++*a5;
    result = pack_core(a1, (__int64)a2, v12, a4 - 6, a5, (__int64)&FFS_vendor_vht_ie, IES_vendor_vht_ie);
    if ( v13 )
      *v13 = *(_BYTE *)a5 - v7 - 2;
  }
  else
  {
    result = 268435461;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
