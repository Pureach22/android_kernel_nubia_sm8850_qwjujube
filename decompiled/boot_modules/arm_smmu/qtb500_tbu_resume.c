__int64 __fastcall qtb500_tbu_resume(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( (*(_BYTE *)(result + 80) & 1) == 0 )
  {
    v1 = *(_QWORD *)(result + 32);
    v2 = readq_relaxed_0(v1 + 1040);
    return writeq_relaxed_0(v2 & 0xFFFFFFFFFFFFFFFELL, v1 + 1040);
  }
  return result;
}
