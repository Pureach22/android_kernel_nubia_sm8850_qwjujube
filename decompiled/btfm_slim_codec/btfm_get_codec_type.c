__int64 __fastcall btfm_get_codec_type(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 72) = (unsigned __int8)usecase_codec;
  return 1;
}
