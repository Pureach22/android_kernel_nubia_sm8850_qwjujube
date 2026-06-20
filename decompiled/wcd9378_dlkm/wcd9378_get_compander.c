__int64 __fastcall wcd9378_get_compander(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x9

  v3 = *(_QWORD *)(a1 + 120);
  v2 = *(_QWORD *)(a1 + 128);
  v4 = 392;
  result = 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  if ( *(_DWORD *)(v3 + 20) )
    v4 = 393;
  *(_QWORD *)(a2 + 72) = *(unsigned __int8 *)(v6 + v4);
  return result;
}
