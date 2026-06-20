__int64 __fastcall syna_tcm_enable_predict_reading(__int64 a1, char a2, __int64 a3)
{
  const char *v4; // x2

  if ( a1 )
  {
    *(_BYTE *)(a1 + 890) = a2 & 1;
    *(_DWORD *)(a1 + 892) = 0;
    if ( (a2 & 1) != 0 )
      v4 = "enabled";
    else
      v4 = "disabled";
    printk(unk_356A9, "syna_tcm_enable_predict_reading", v4);
    return 0;
  }
  else
  {
    printk(unk_3365A, "syna_tcm_enable_predict_reading", a3);
    return 4294967055LL;
  }
}
