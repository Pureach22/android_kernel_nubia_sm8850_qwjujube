__int64 __fastcall debug_spmi_addr_set(__int64 a1, int a2)
{
  *(_DWORD *)(a1 + 184) = a2;
  return 0;
}
