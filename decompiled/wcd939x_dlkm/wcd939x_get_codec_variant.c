__int64 __fastcall wcd939x_get_codec_variant(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_QWORD *)(v1 + 152);
  if ( v2 )
    return *(unsigned int *)(v2 + 8);
  dev_err(v1, "%s:wcd939x not probed\n", "wcd939x_get_codec_variant");
  return 0;
}
