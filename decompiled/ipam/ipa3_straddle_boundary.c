bool __fastcall ipa3_straddle_boundary(int a1, int a2, int a3)
{
  __int64 v5; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w9
  int v10; // w10

  v5 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d start=%u end=%u boundary=%u\n", "ipa3_straddle_boundary", 10260, a1, a2, a3);
      v5 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v5 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d start=%u end=%u boundary=%u\n", "ipa3_straddle_boundary", 10260, a1, a2, a3);
  }
  v9 = (a3 - 1 + a2) & -a3;
  v10 = (a3 - 1 + a1) & -a3;
  do
    v10 += a3;
  while ( v10 - a3 < (unsigned int)(v9 - a3) );
  return v9 == v10;
}
