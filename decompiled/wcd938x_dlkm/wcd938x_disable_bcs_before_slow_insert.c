__int64 __fastcall wcd938x_disable_bcs_before_slow_insert(__int64 result, char a2)
{
  __int64 v2; // x9
  __int64 (__fastcall *v3)(__int64, __int64, bool); // x8
  __int64 v4; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
  v3 = *(__int64 (__fastcall **)(__int64, __int64, bool))(v2 + 3128);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v2 + 3120);
    if ( *((_DWORD *)v3 - 1) != -17866579 )
      __break(0x8228u);
    return v3(v4, 5, (a2 & 1) == 0);
  }
  return result;
}
