__int64 __fastcall sme_release_command(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 16) = 0;
  return csr_ll_insert_tail(a1 + 12856);
}
