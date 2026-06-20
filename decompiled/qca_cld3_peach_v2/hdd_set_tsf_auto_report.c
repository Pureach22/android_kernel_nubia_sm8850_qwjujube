__int64 __fastcall hdd_set_tsf_auto_report(
        _QWORD *a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v11; // w19
  _QWORD *v13; // x21
  int v14; // w22
  int v15; // w2
  int v16; // w0
  int v17; // w1
  unsigned int v18; // w0
  __int64 v19; // x22
  __int64 v21; // x24
  __int64 v22; // x9
  __int64 v23; // x8
  unsigned __int64 v26; // x10
  unsigned __int64 v33; // x10

  v11 = a2;
  v13 = a1 + 4924;
  v14 = *(unsigned __int8 *)(*(_QWORD *)(a1[3] + 104LL) + 18LL);
  if ( (((a1[4924] != 0) ^ a2) & 1) != 0 )
  {
    v15 = a2 & 1;
    v16 = *(unsigned __int8 *)(a1[6604] + 8LL);
    if ( (a2 & 1) != 0 )
      v17 = 11;
    else
      v17 = 12;
    v18 = wma_cli_set_command(v16, v17, v15, 3);
    if ( v18 )
    {
      v19 = jiffies;
      if ( hdd_set_tsf_auto_report___last_ticks_29 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: source %d enable %d failed: %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "hdd_set_tsf_auto_report",
          a3,
          v11 & 1,
          v18);
        hdd_set_tsf_auto_report___last_ticks_29 = v19;
      }
      return 4294967181LL;
    }
  }
  else
  {
    v21 = jiffies;
    if ( hdd_set_tsf_auto_report___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: source %d current %d and no action is required",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "hdd_set_tsf_auto_report",
        a3);
      hdd_set_tsf_auto_report___last_ticks = v21;
    }
  }
  v22 = a3 >> 6;
  v23 = 1LL << a3;
  if ( (v11 & 1) != 0 )
  {
    _X9 = &v13[v22];
    __asm { PRFM            #0x11, [X9] }
    do
      v26 = __ldxr(_X9);
    while ( __stxr(v26 | v23, _X9) );
  }
  else
  {
    _X9 = &v13[v22];
    __asm { PRFM            #0x11, [X9] }
    do
      v33 = __ldxr(_X9);
    while ( __stxr(v33 & ~v23, _X9) );
  }
  if ( v14 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s:  enable %d, tsf autoreport status %lu",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_set_tsf_auto_report",
      v11 & 1,
      *v13);
  return 0;
}
