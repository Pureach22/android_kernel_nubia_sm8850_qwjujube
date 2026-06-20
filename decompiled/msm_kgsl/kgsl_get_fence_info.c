__int64 __fastcall kgsl_get_fence_info(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x27
  __int64 v3; // x8
  unsigned int v4; // w25
  _QWORD *v5; // x26
  int j; // w28
  __int64 v7; // x22
  __int64 v8; // x23
  __int64 (__fastcall *v9)(_QWORD); // x8
  const char *v10; // x24
  __int64 (__fastcall *v11)(_QWORD); // x8
  const char *v12; // x0
  int v13; // w0
  int v14; // w9
  _DWORD *v15; // x8
  int i; // w20
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = result;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 48);
  v3 = *(_QWORD *)(*(_QWORD *)(result + 32) + 24LL);
  v17[0] = v3;
  if ( v3 && *(_UNKNOWN **)(v3 + 8) == &dma_fence_array_ops )
  {
    v4 = *(_DWORD *)(v3 + 68);
    v5 = *(_QWORD **)(v3 + 80);
    if ( !v2 )
      goto LABEL_18;
  }
  else
  {
    v4 = 1;
    v5 = v17;
    if ( !v2 )
    {
LABEL_18:
      if ( v4 )
      {
        for ( i = 0; i != v4; ++i )
          result = kgsl_count_hw_fences(v1, v5[i]);
      }
      goto LABEL_21;
    }
  }
  result = _kmalloc_noprof(74LL * v4, 3520);
  *(_QWORD *)v2 = result;
  if ( !result )
    goto LABEL_18;
  *(_DWORD *)(v2 + 8) = v4;
  if ( v4 )
  {
    for ( j = 0; j != v4; ++j )
    {
      v7 = v5[j];
      v8 = *(_QWORD *)v2 + 74LL * j;
      v9 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v7 + 8) + 8LL);
      if ( *((_DWORD *)v9 - 1) != -352706110 )
        __break(0x8228u);
      v10 = (const char *)v9(v7);
      v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v7 + 8) + 16LL);
      if ( *((_DWORD *)v11 - 1) != -352706110 )
        __break(0x8228u);
      v12 = (const char *)v11(v7);
      v13 = scnprintf(v8, 74, "%s %s", v10, v12);
      if ( *(_QWORD *)(*(_QWORD *)(v7 + 8) + 56LL) )
      {
        v14 = scnprintf(v8 + v13, (unsigned int)(74 - v13), ": ") + v13;
        v15 = *(_DWORD **)(*(_QWORD *)(v7 + 8) + 56LL);
        if ( *(v15 - 1) != -938580849 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v15)(v7, v8 + v14, (unsigned int)(74 - v14));
      }
      result = kgsl_count_hw_fences(v1, v7);
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
