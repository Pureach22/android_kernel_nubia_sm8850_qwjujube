__int64 __fastcall _qdf_frag_cache_drain(__int64 result)
{
  _QWORD *v1; // x19

  if ( *(_QWORD *)result )
  {
    v1 = (_QWORD *)result;
    result = _page_frag_cache_drain(
               ((unsigned __int64)(((__int64)(*(_QWORD *)result << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
             - 0x140000000LL,
               *(unsigned int *)(result + 12));
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
  }
  return result;
}
