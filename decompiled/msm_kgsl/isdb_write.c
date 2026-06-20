__int64 __fastcall isdb_write(__int64 result, unsigned int a2)
{
  _DWORD *v2; // x9

  v2 = (_DWORD *)(result + a2);
  v2[65541] = 2049;
  __dsb(0xEu);
  v2[65537] = 3;
  __dsb(0xEu);
  v2[65539] = 1;
  return result;
}
