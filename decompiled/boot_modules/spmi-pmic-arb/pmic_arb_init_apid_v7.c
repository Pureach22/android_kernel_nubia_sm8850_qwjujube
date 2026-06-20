__int64 __fastcall pmic_arb_init_apid_v7(__int64 a1, int a2)
{
  __int64 v2; // x20
  __int64 v4; // x8
  __int16 v5; // w0
  __int16 v6; // w0
  int v7; // w8
  __int64 v8; // x8

  v2 = *(_QWORD *)a1;
  if ( a2 == 1 )
  {
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(v2 + 24) + 4LL));
    v4 = 8;
    *(_WORD *)(a1 + 52) = v5 & 0x7FF;
  }
  else
  {
    if ( a2 )
    {
      dev_err(*(_QWORD *)(a1 + 40), "Unsupported buses count %d detected\n");
      return 4294967274LL;
    }
    *(_WORD *)(a1 + 52) = 0;
    v4 = 4;
  }
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(v2 + 24) + v4));
  v7 = *(unsigned __int16 *)(a1 + 52);
  *(_DWORD *)(a1 + 56) = v6 & 0x7FF;
  if ( (v6 & 0x7FF) + v7 > *(_DWORD *)(v2 + 64) )
  {
    dev_err(*(_QWORD *)(a1 + 40), "Unsupported APID count %d detected\n");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)a1;
  *(_WORD *)(a1 + 162) = 0;
  *(_WORD *)(a1 + 160) = *(_WORD *)(v8 + 64) - 1;
  pmic_arb_read_apid_map_v5(a1);
  return 0;
}
