__int64 __fastcall arm_tbu_halt_poll(__int64 a1)
{
  unsigned int *v1; // x19
  char v3; // w0
  __int64 v4; // x21
  int v6; // w0

  v1 = *(unsigned int **)(a1 + 32);
  v3 = readl_0(v1 + 8);
  if ( (v3 & 2) != 0 )
  {
LABEL_5:
    if ( (v3 & 2) == 0 )
    {
LABEL_9:
      dev_err(*(_QWORD *)(a1 + 16), "Couldn't halt TBU!\n");
      v6 = readl_relaxed_1(v1);
      writel_relaxed_1(v6 & 0xFFFEFFFF, v1);
      return 4294967186LL;
    }
  }
  else
  {
    v4 = 100001;
    while ( --v4 >= 0 )
    {
      __yield();
      v3 = readl_0(v1 + 8);
      if ( (v3 & 2) != 0 )
        goto LABEL_5;
    }
    if ( (readl_0(v1 + 8) & 2) == 0 )
      goto LABEL_9;
  }
  return 0;
}
