__int64 __fastcall sdhci_msm_vreg_init_reg(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  int v5; // w8
  unsigned int v6; // w19

  if ( !*(_QWORD *)(a2 + 8) )
  {
    v4 = devm_regulator_get(a1, *(_QWORD *)(a2 + 24));
    *(_QWORD *)(a2 + 8) = v4;
    if ( v4 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( *(_BYTE *)(a2 + 85) != 1 )
      {
LABEL_6:
        if ( (int)regulator_count_voltages(v4) >= 1 )
        {
          if ( (v5 = *(unsigned __int8 *)(a2 + 84), *(_BYTE *)(a2 + 83) = 1, v5 == 1) && !*(_DWORD *)(a2 + 68)
            || !*(_DWORD *)(a2 + 76) )
          {
            printk(&unk_FFA6, "sdhci_msm_vreg_init_reg");
            return (unsigned int)-22;
          }
        }
        return 0;
      }
      v4 = devm_regulator_get(a1, a2 + 32);
      *(_QWORD *)(a2 + 16) = v4;
      if ( v4 <= 0xFFFFFFFFFFFFF000LL )
      {
        v4 = *(_QWORD *)(a2 + 8);
        goto LABEL_6;
      }
    }
    v6 = v4;
    printk(&unk_1064F, "sdhci_msm_vreg_init_reg");
    return v6;
  }
  return 0;
}
