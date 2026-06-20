__int64 __fastcall dot11f_pack_ie_ric_data_desc(__int64 a1, _BYTE *a2, char *a3, unsigned int a4, _DWORD *a5)
{
  int v5; // w8
  __int64 result; // x0
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (unsigned __int8)*a2;
  v12 = 0;
  if ( !v5 )
    goto LABEL_6;
  result = get_packed_size_core(a1, (__int64)a2, (int *)&v12, IES_RICDataDesc);
  if ( (_DWORD)result )
    goto LABEL_7;
  if ( !*a2 )
  {
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  if ( v12 <= a4 )
    result = pack_core(a1, (__int64)a2, a3, a4, a5, (__int64)&FFS_RICDataDesc, IES_RICDataDesc);
  else
    result = 268435461;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
