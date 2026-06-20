__int64 __fastcall wcd9378_soc_codec_resume(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v1 )
    *(_BYTE *)(v1 + 396) = 0;
  return 0;
}
