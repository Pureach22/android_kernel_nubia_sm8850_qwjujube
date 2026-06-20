void __fastcall ipareg_construct_nat_uc_shared_cfg(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | (*(_DWORD *)a2 << 16);
  *a3 = v3;
  *a3 = *(unsigned __int16 *)(a2 + 4) | v3;
}
