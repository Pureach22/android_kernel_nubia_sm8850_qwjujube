__int64 __fastcall dynamic_funnel_probe(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0

  result = funnel_probe(a1, (__int64)(a1 + 114), a3, a4, a5, a6, a7, a8);
  if ( !(_DWORD)result )
  {
    _pm_runtime_idle(a1, 5);
    return 0;
  }
  return result;
}
