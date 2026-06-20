__int64 __fastcall qtb500_tbu_halt_poll(__int64 a1)
{
  __int64 v2; // x19
  char v4; // w0
  __int64 v5; // x21
  __int64 v6; // x0

  if ( (*(_BYTE *)(a1 + 80) & 1) != 0 )
    return 0;
  v2 = *(_QWORD *)(a1 + 32);
  v4 = readq(v2 + 1048);
  if ( (v4 & 1) == 0 )
  {
    v5 = 100001;
    while ( --v5 >= 0 )
    {
      __yield();
      v4 = readq(v2 + 1048);
      if ( (v4 & 1) != 0 )
        goto LABEL_9;
    }
    v4 = readq(v2 + 1048);
  }
LABEL_9:
  if ( (v4 & 1) != 0 )
    return 0;
  dev_err(*(_QWORD *)(a1 + 16), "Couldn't halt QTB\n");
  v6 = readq_relaxed_0(v2 + 1040);
  writeq_relaxed_0(v6 & 0xFFFFFFFFFFFFFFFELL, v2 + 1040);
  return 4294967186LL;
}
