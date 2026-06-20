__int64 __fastcall wcd9378_codec_get_dev_num(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 56);
    if ( v2 )
      return *(unsigned __int8 *)(v2 + 64);
  }
  printk(&unk_132D2, "wcd9378_codec_get_dev_num");
  return 4294967274LL;
}
