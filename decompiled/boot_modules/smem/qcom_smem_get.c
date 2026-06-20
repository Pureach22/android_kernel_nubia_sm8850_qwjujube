__int64 __fastcall qcom_smem_get(__int64 a1, unsigned int a2, _QWORD *a3)
{
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // t1
  __int64 v9; // x9
  __int64 v10; // x9
  int v11; // t1
  __int64 v12; // x10
  _QWORD *v13; // x8
  unsigned int v14; // w11
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // t2

  if ( !_smem )
    return -517;
  if ( *(_DWORD *)(_smem + 16) <= a2 )
    goto LABEL_21;
  if ( (unsigned int)a1 <= 0x18 )
  {
    v5 = _smem + 32LL * (unsigned int)a1;
    v7 = *(_QWORD *)(v5 + 72);
    v6 = v5 + 72;
    if ( v7 )
      return qcom_smem_get_private(_smem, v6);
  }
  v6 = _smem + 40;
  if ( *(_QWORD *)(_smem + 40) )
    return qcom_smem_get_private(_smem, v6);
  if ( a2 >= 0x201 )
  {
    __break(0x5512u);
    return qcom_smem_get_private(a1, v6);
  }
  v9 = *(_QWORD *)(_smem + 888) + 16LL * a2;
  v11 = *(_DWORD *)(v9 + 208);
  v10 = v9 + 208;
  if ( !v11 )
    return -6;
  v12 = *(unsigned int *)(_smem + 872);
  if ( !(_DWORD)v12 )
    return -2;
  v13 = (_QWORD *)(_smem + 896);
  v14 = *(_DWORD *)(v10 + 12) & 0xFFFFFFFC;
  while ( v14 && v14 != *((_DWORD *)v13 - 4) )
  {
    --v12;
    v13 += 3;
    if ( !v12 )
      return -2;
  }
  v17 = v10 + 4;
  v15 = *(unsigned int *)(v10 + 4);
  v16 = *(unsigned int *)(v17 + 4);
  if ( (unsigned __int64)(v15 + v16) > *v13 )
  {
LABEL_21:
    __break(0x800u);
    return -22;
  }
  if ( a3 )
    *a3 = v16;
  return *(v13 - 1) + v15;
}
