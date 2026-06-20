__int64 __fastcall hal_srng_get_entrysize(__int64 a1, int a2)
{
  return 4 * (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(a1 + 74256) + 36LL * a2 + 6);
}
