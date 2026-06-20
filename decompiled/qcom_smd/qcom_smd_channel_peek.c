unsigned __int64 __fastcall qcom_smd_channel_peek(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x19
  __int64 v6; // x20
  unsigned int *v7; // x9
  __int64 v8; // x9
  int v9; // w10
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x22
  __int64 v12; // x10
  __int64 v13; // x1
  unsigned __int64 v14; // x9

  v3 = *(_QWORD *)(a1 + 72);
  v4 = a3;
  v6 = a2;
  if ( v3 )
    v7 = (unsigned int *)(v3 + 80);
  else
    v7 = (unsigned int *)(*(_QWORD *)(a1 + 64) + 32LL);
  v8 = *v7;
  v9 = *(_DWORD *)(a1 + 128);
  v10 = (unsigned int)(v9 - v8);
  if ( v10 >= a3 )
    v11 = a3;
  else
    v11 = (unsigned int)(v9 - v8);
  if ( !v11 )
  {
    if ( v10 >= a3 )
      return v4;
    v13 = *(_QWORD *)(a1 + 120);
    v14 = a3;
    if ( v3 )
      goto LABEL_13;
LABEL_16:
    _memcpy_fromio(v6, v13, a3);
    return v4;
  }
  v12 = *(_QWORD *)(a1 + 120);
  if ( !v3 )
  {
    _memcpy_fromio(a2, v12 + v8, v11);
    if ( v10 >= v4 )
      return v4;
    v13 = *(_QWORD *)(a1 + 120);
    v6 += v11;
    a3 = v4 - v11;
    goto LABEL_16;
  }
  _ioread32_copy(a2, v12 + v8, v11 >> 2);
  if ( v10 < v4 )
  {
    v13 = *(_QWORD *)(a1 + 120);
    v6 += v11;
    v14 = v4 - v11;
LABEL_13:
    _ioread32_copy(v6, v13, v14 >> 2);
  }
  return v4;
}
