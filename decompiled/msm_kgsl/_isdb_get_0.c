__int64 __fastcall isdb_get_0(__int64 a1, __int64 *a2)
{
  unsigned __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 14240);
  *a2 = (v2 >> 12) & 1;
  return 0;
}
