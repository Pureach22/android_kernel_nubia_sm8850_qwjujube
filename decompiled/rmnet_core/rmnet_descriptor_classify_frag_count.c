unsigned __int64 __fastcall rmnet_descriptor_classify_frag_count(unsigned __int64 result, __int64 a2)
{
  _QWORD *v2; // x8

  if ( result > 1 )
  {
    v2 = (_QWORD *)(a2 + 8 * (result >> 2) + 2672);
    if ( result >= 0x10 )
      v2 = (_QWORD *)(a2 + 2704);
  }
  else
  {
    v2 = (_QWORD *)(a2 + 2664);
  }
  *v2 += result;
  return result;
}
