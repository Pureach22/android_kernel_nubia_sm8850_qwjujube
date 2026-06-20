__int64 __fastcall wsa883x_codec_get_dev_num(__int64 a1)
{
  __int64 v1; // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v1 )
    return *(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 64LL);
  printk(&unk_AE3B, "wsa883x_codec_get_dev_num");
  return 4294967274LL;
}
