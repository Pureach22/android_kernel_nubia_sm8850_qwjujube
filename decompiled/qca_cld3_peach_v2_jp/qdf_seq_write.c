__int64 __fastcall qdf_seq_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  __int64 result; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  void (__fastcall *v8)(__int64, __int64, __int64); // x9
  __int64 v9; // x19
  __int64 v10; // x0

  if ( !a3 )
    return 0;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 128LL);
  if ( !v3 || !*(_QWORD *)(v3 + 8) )
    return 0;
  result = _qdf_mem_malloc(a3 + 1, "qdf_seq_write", 269);
  if ( result )
  {
    *(_BYTE *)(result + a3) = 0;
    v6 = result;
    v7 = simple_write_to_buffer();
    v8 = *(void (__fastcall **)(__int64, __int64, __int64))(v3 + 8);
    v9 = v7;
    v10 = *(_QWORD *)(v3 + 16);
    if ( *((_DWORD *)v8 - 1) != -1157633645 )
      __break(0x8229u);
    v8(v10, v6, a3 + 1);
    _qdf_mem_free(v6);
    return v9;
  }
  return result;
}
