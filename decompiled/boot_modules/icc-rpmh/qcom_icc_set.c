__int64 __fastcall qcom_icc_set(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  _QWORD *v4; // x20
  int v5; // w11
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9
  __int64 v12; // x19
  __int64 v13; // x19
  __int64 v14; // x19
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned __int64 v17; // x8
  int v18; // w19
  unsigned int v20; // w22

  if ( a1 )
    a2 = a1;
  v3 = *(_QWORD *)(a2 + 112);
  v4 = *(_QWORD **)(a2 + 32);
  if ( *(_WORD *)(v3 + 442) && *(_WORD *)(v3 + 444) )
  {
    v5 = *(_DWORD *)(a2 + 100);
    v6 = *(_DWORD *)(a2 + 96) * *(unsigned __int16 *)(v3 + 442);
    *(_DWORD *)(a2 + 96) = v6;
    *(_DWORD *)(a2 + 96) = v6 / *(unsigned __int16 *)(v3 + 444);
    v7 = v5 * *(unsigned __int16 *)(v3 + 442);
    *(_DWORD *)(a2 + 100) = v7;
    *(_DWORD *)(a2 + 100) = v7 / *(unsigned __int16 *)(v3 + 444);
  }
  if ( !*(_QWORD *)(v3 + 424) )
    goto LABEL_24;
  v9 = *(_DWORD *)(a2 + 96);
  v8 = *(_DWORD *)(a2 + 100);
  if ( v9 > v8 )
    v8 = v9;
  v10 = 1000LL * v8;
  v11 = *(unsigned __int16 *)(v3 + 270);
  if ( v10 / v11 >= 0xFFFFFFFF )
    v12 = 0xFFFFFFFFLL;
  else
    v12 = v10 / v11;
  if ( v10 < v11 )
  {
    if ( *(_BYTE *)(v3 + 440) == 1 && *(_BYTE *)(v3 + 441) == 1 )
    {
      v13 = *(_QWORD *)(v3 + 424);
      clk_disable();
      clk_unprepare(v13);
      *(_BYTE *)(v3 + 441) = 0;
    }
    goto LABEL_24;
  }
  if ( (unsigned int)clk_set_rate() )
    dev_warn(v4[13], "Failed to set %s rate to %llu for %s\n", *(const char **)(v3 + 432), v12, *(const char **)v3);
  if ( *(_BYTE *)(v3 + 440) != 1 || (*(_BYTE *)(v3 + 441) & 1) != 0 )
    goto LABEL_24;
  v14 = *(_QWORD *)(v3 + 424);
  v15 = clk_prepare(v14);
  if ( v15 )
  {
    v20 = v15;
LABEL_30:
    dev_err(v4[13], "Failed to enable %s for %s\n", *(const char **)(v3 + 432), *(const char **)v3);
    return v20;
  }
  v16 = clk_enable(v14);
  if ( v16 )
  {
    v20 = v16;
    clk_unprepare(v14);
    goto LABEL_30;
  }
  *(_BYTE *)(v3 + 441) = 1;
LABEL_24:
  if ( v4[24] )
  {
    v17 = 0;
    v18 = 1;
    do
    {
      qcom_icc_bcm_voter_commit(*(_QWORD *)(v4[23] + 8 * v17));
      v17 = v18++;
    }
    while ( v4[24] > v17 );
  }
  return 0;
}
