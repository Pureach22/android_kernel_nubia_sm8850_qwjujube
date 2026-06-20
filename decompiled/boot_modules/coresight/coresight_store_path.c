__int64 __fastcall coresight_store_path(__int64 a1, __int64 a2)
{
  int v3; // w8
  __int64 v4; // x1
  __int64 result; // x0
  __int64 (*v6)(void); // x8
  unsigned int v7; // w0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 12);
  v8 = 0;
  if ( (unsigned int)(v3 - 2) < 3 )
  {
    v4 = *(_QWORD *)(a1 + 168);
    if ( !v4 )
      v4 = *(_QWORD *)(a1 + 56);
    v8 = hashlen_string(0, v4);
    result = idr_alloc_u32(&path_idr, a2, &v8, v8, 3264);
    if ( (_DWORD)result )
      goto LABEL_12;
    goto LABEL_11;
  }
  if ( v3 )
  {
LABEL_11:
    result = 0;
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = **(__int64 (***)(void))(*(_QWORD *)(a1 + 24) + 16LL);
  if ( *((_DWORD *)v6 - 1) != 335626315 )
    __break(0x8228u);
  v7 = v6();
  if ( v7 < 0x20 )
  {
    *(_QWORD *)((char *)&tracer_path + _per_cpu_offset[v7]) = a2;
    goto LABEL_11;
  }
  __break(0x5512u);
  return coresight_remove_path();
}
