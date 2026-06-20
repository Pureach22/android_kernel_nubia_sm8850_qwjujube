bool __fastcall csr_is_wmm_supported(__int64 a1)
{
  return *(_DWORD *)(a1 + 17140) != 2;
}
