__int64 __fastcall wcd939x_soc_codec_remove(__int64 a1)
{
  __int64 v1; // x0
  _QWORD *v2; // x19
  __int64 result; // x0
  _DWORD *v4; // x8
  __int64 v5; // x0

  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_QWORD **)(v1 + 152);
  if ( !v2 )
    return dev_err(v1, "%s: wcd939x is already NULL\n", "wcd939x_soc_codec_remove");
  result = v2[414];
  if ( result )
    result = proc_remove(result);
  v4 = (_DWORD *)v2[395];
  if ( v4 )
  {
    v5 = v2[393];
    if ( *(v4 - 1) != -875060373 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD))v4)(v5, v2 + 390, 0);
  }
  return result;
}
