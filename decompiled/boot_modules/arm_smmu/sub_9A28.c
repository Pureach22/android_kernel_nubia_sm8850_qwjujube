__int64 __fastcall sub_9A28(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        _QWORD *a7,
        __int64 a8)
{
  __int64 v8; // x9

  *a7 = a8;
  a7[1] = v8;
  return _traceiter_unmap_pages(a1, a2, a3, a4, a5, a6, a7 - 26);
}
