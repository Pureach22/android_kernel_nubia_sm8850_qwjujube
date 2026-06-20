__int64 __fastcall qtb500_log_outstanding_transactions(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  unsigned int v3; // w20
  int v4; // w23
  __int64 v5; // x0

  if ( *(_DWORD *)(result + 84) )
  {
    v1 = *(_QWORD *)(result + 32);
    v2 = result;
    v3 = 0;
    v4 = 3088;
    do
    {
      v5 = readq_relaxed_0(v1 + v4);
      result = dev_err(*(_QWORD *)(v2 + 16), "port %d outstanding transactions bitmap: 0x%llx\n", v3++, v5);
      v4 += 16;
    }
    while ( v3 < *(_DWORD *)(v2 + 84) );
  }
  return result;
}
