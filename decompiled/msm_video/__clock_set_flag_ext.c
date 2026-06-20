__int64 __fastcall _clock_set_flag_ext(__int64 a1, char *s2, unsigned int a3)
{
  __int64 v3; // x8
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x22

  v3 = *(_QWORD *)(a1 + 3904);
  v5 = *(_QWORD *)(v3 + 64);
  v6 = v5 + 72LL * *(unsigned int *)(v3 + 72);
  if ( v5 >= v6 )
  {
LABEL_4:
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_819B3, "err ", 0xFFFFFFFFLL, "codec", "__clock_set_flag_ext");
    return 4294967274LL;
  }
  while ( strcmp(*(const char **)(v5 + 8), s2) )
  {
    v5 += 72LL;
    if ( v5 >= v6 )
      goto LABEL_4;
  }
  if ( a3 >= 6 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_7FE07, "err ", 0xFFFFFFFFLL, "codec", "qcom_clk_get_branch_flag");
    return 4294967274LL;
  }
  qcom_clk_set_flags(*(_QWORD *)v5, a3);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_8DD82, "high", 0xFFFFFFFFLL, "codec", "__clock_set_flag_ext");
  return 0;
}
