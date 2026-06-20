__int64 __fastcall wcd938x_soc_codec_remove(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  _DWORD *v3; // x9
  __int64 v4; // x0

  result = *(_QWORD *)(a1 + 24);
  v2 = *(_QWORD *)(result + 152);
  if ( !v2 )
    return dev_err(result, "%s: wcd938x is already NULL\n", "wcd938x_soc_codec_remove");
  v3 = *(_DWORD **)(v2 + 3136);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v2 + 3120);
    if ( *(v3 - 1) != -875060373 )
      __break(0x8229u);
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v3)(v4, v2 + 3096, 0);
  }
  return result;
}
