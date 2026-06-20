__int64 __fastcall sub_75AC38(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return _qdf_page_pool_alloc_page(a1, a2, a3, a4, a5, a6, a7, a8 & 0xFFFF0000FFFFFFFFLL | 0xA7C100000000LL);
}
