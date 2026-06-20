bool __fastcall csr_is_ndi_started(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8

  return a2 <= 5 && (v2 = *(_QWORD *)(a1 + 17296) + 96LL * a2) != 0 && *(_DWORD *)(v2 + 4) == 6;
}
