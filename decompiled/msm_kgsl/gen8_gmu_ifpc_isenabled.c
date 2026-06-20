bool __fastcall gen8_gmu_ifpc_isenabled(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 - 816);
  return v1 == 3 || v1 == 6;
}
