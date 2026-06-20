__int64 __fastcall pmic_arb_init_apid_v5(__int64 *a1, unsigned int a2)
{
  __int64 v3; // x20
  __int16 v4; // w0
  int v5; // w8
  __int64 v6; // x2
  __int64 v7; // x8

  if ( a2 )
  {
    dev_err(a1[5], "Unsupported buses count %d detected\n", a2);
    return 4294967274LL;
  }
  v3 = *a1;
  *((_WORD *)a1 + 26) = 0;
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(v3 + 24) + 4LL));
  v5 = *((unsigned __int16 *)a1 + 26);
  *((_DWORD *)a1 + 14) = v4 & 0x7FF;
  v6 = (v4 & 0x7FFu) + v5;
  if ( (int)v6 > *(_DWORD *)(v3 + 64) )
  {
    dev_err(a1[5], "Unsupported APID count %d detected\n", v6);
    return 4294967274LL;
  }
  v7 = *a1;
  *((_WORD *)a1 + 81) = 0;
  *((_WORD *)a1 + 80) = *(_WORD *)(v7 + 64) - 1;
  pmic_arb_read_apid_map_v5(a1);
  return 0;
}
