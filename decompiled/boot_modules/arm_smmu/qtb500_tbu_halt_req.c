__int64 __fastcall qtb500_tbu_halt_req(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( (*(_BYTE *)(a1 + 80) & 1) == 0 )
  {
    v1 = *(_QWORD *)(a1 + 32);
    v2 = readq_relaxed_0(v1 + 1040);
    writeq_relaxed_0(v2 | 1, v1 + 1040);
  }
  return 0;
}
