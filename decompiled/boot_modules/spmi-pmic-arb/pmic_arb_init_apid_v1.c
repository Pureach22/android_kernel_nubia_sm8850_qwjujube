__int64 __fastcall pmic_arb_init_apid_v1(__int64 a1, int a2)
{
  __int64 v3; // x8
  __int64 v4; // x0

  if ( a2 )
  {
    dev_err(*(_QWORD *)(a1 + 40), "Unsupported buses count %d detected\n", a2);
    return 4294967274LL;
  }
  else
  {
    v3 = *(unsigned int *)(*(_QWORD *)a1 + 64LL);
    if ( (v3 & 0x80000000) != 0 )
      return 4294967284LL;
    v4 = devm_kmalloc(*(_QWORD *)(a1 + 40), 4 * v3, 3520);
    if ( !v4 )
    {
      return 4294967284LL;
    }
    else
    {
      *(_WORD *)(a1 + 162) = 0;
      *(_QWORD *)(a1 + 64) = v4;
      *(_WORD *)(a1 + 160) = *(_WORD *)(*(_QWORD *)a1 + 64LL) - 1;
      return 0;
    }
  }
}
