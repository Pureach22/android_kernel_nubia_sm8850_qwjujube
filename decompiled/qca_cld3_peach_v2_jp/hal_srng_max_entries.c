__int64 __fastcall hal_srng_max_entries(__int64 a1, int a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 74256) + 36LL * a2;
  return *(_DWORD *)(v2 + 28) / (unsigned int)*(unsigned __int16 *)(v2 + 6);
}
