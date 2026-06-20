unsigned __int64 __fastcall qcom_smem_get_feature_code(unsigned int *a1)
{
  unsigned __int64 result; // x0
  _DWORD *v3; // x9
  __int64 v4; // x10
  _QWORD *v5; // x8
  unsigned int v6; // w11
  unsigned int v7; // w8
  __int64 v8; // x10
  __int64 v9; // x9

  if ( !_smem )
    return -517;
  if ( *(_DWORD *)(_smem + 16) <= 0x89u )
    goto LABEL_22;
  if ( !*(_QWORD *)(_smem + 40) )
  {
    v3 = *(_DWORD **)(_smem + 888);
    if ( !v3[600] )
      return -6;
    v4 = *(unsigned int *)(_smem + 872);
    if ( !(_DWORD)v4 )
      return -2;
    v5 = (_QWORD *)(_smem + 896);
    v6 = v3[603] & 0xFFFFFFFC;
    while ( v6 && v6 != *((_DWORD *)v5 - 4) )
    {
      --v4;
      v5 += 3;
      if ( !v4 )
        return -2;
    }
    v8 = (unsigned int)v3[602];
    v9 = (unsigned int)v3[601];
    if ( (unsigned __int64)(v9 + v8) <= *v5 )
    {
      result = *(v5 - 1) + v9;
      if ( result >= 0xFFFFFFFFFFFFF001LL )
        return result;
      goto LABEL_5;
    }
LABEL_22:
    __break(0x800u);
    return -22;
  }
  result = qcom_smem_get_private((_QWORD *)_smem, (unsigned __int64 *)(_smem + 40), 137, nullptr);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return result;
LABEL_5:
  if ( *(_DWORD *)result < 0x10u )
    return 4294967201LL;
  v7 = *(_DWORD *)(result + 176);
  result = 0;
  if ( v7 > 0x100 )
    v7 = 0;
  *a1 = v7;
  return result;
}
