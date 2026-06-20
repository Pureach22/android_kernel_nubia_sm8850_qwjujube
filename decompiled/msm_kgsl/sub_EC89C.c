__int64 __fastcall sub_EC89C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w23
  __int64 v5; // x26
  int v6; // w28

  *(_DWORD *)(v5 - 80) = v4;
  *(_DWORD *)(v5 - 76) = v6;
  return _traceiter_adreno_syncobj_query_reply(a1, a2, a3, a4);
}
