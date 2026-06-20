unsigned __int64 __fastcall qcom_smem_get_soc_id(_DWORD *a1)
{
  unsigned __int64 result; // x0
  _DWORD *v3; // x9
  __int64 v4; // x10
  _QWORD *v5; // x8
  unsigned int v6; // w11
  __int64 v7; // x10
  __int64 v8; // x9

  if ( !_smem )
    return -517;
  if ( *(_DWORD *)(_smem + 16) <= 0x89u )
    goto LABEL_18;
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
    v7 = (unsigned int)v3[602];
    v8 = (unsigned int)v3[601];
    if ( (unsigned __int64)(v8 + v7) <= *v5 )
    {
      result = *(v5 - 1) + v8;
      if ( result < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_5;
      return result;
    }
LABEL_18:
    __break(0x800u);
    return -22;
  }
  result = qcom_smem_get_private((_QWORD *)_smem, (unsigned __int64 *)(_smem + 40), 137, nullptr);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_5:
    *a1 = *(_DWORD *)(result + 4);
    return 0;
  }
  return result;
}
