__int64 __fastcall simple_amp_remove(__int64 a1)
{
  _QWORD *v1; // x19
  _DWORD *v2; // x8
  __int64 v3; // x0
  __int64 result; // x0

  if ( a1 && (v1 = *(_QWORD **)(a1 + 224)) != nullptr )
  {
    v2 = (_DWORD *)v1[28];
    if ( v2 )
    {
      v3 = v1[27];
      if ( *(v2 - 1) != -875060373 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v2)(v3, v1 + 24, 0);
    }
    debugfs_remove(v1[62]);
    result = 0;
    v1[62] = 0;
  }
  else
  {
    dev_err(a1 + 72, "%s: simple_amp is NULL\n", "simple_amp_remove");
    return 4294967274LL;
  }
  return result;
}
