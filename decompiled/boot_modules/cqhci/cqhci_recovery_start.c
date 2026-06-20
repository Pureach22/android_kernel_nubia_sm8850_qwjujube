__int64 __fastcall cqhci_recovery_start(__int64 a1)
{
  _BYTE *v1; // x20
  __int64 result; // x0
  __int64 (__fastcall *v4)(__int64, __int64); // x8

  v1 = *(_BYTE **)(a1 + 1464);
  if ( (v1[61] & 1) == 0 )
    __break(0x800u);
  result = cqhci_halt(a1, 500);
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v1 + 32LL);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -289083512 )
      __break(0x8228u);
    result = v4(a1, 1);
  }
  *(_BYTE *)(a1 + 1477) = 0;
  return result;
}
