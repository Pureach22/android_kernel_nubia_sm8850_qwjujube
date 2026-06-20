__int64 __fastcall wsa883x_soc_codec_resume(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v1 )
    *(_BYTE *)(v1 + 35) = 0;
  return 0;
}
