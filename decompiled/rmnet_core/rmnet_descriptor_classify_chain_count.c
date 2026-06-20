unsigned __int64 __fastcall rmnet_descriptor_classify_chain_count(unsigned __int64 result, __int64 a2)
{
  _QWORD *v2; // x8

  v2 = (_QWORD *)(a2 + 8LL * ((unsigned __int8)result / 0xAu) + 2608);
  if ( result > 0x3B )
    v2 = (_QWORD *)(a2 + 2656);
  *v2 += result;
  return result;
}
