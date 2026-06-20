bool __fastcall sde_vm_owns_hw(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9
  int v3; // w8

  v1 = *(_QWORD *)(a1 + 6384);
  v2 = *(_DWORD *)(v1 + 56);
  v3 = *(_DWORD *)(v1 + 60);
  return !v2 && v3 < 0;
}
