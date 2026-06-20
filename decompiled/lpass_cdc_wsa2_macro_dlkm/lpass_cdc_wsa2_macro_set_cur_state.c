__int64 __fastcall lpass_cdc_wsa2_macro_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x20

  v2 = *(_QWORD *)(a1 + 944);
  if ( !v2 || !*(_QWORD *)v2 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_set_cur_state__rs, "lpass_cdc_wsa2_macro_set_cur_state") )
      printk(&unk_F0CD, "lpass_cdc_wsa2_macro_set_cur_state");
    return 4294967274LL;
  }
  if ( *(unsigned int *)(v2 + 564) < a2 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_set_cur_state__rs_296, "lpass_cdc_wsa2_macro_set_cur_state") )
      dev_err(*(_QWORD *)v2, "%s: incorrect requested state:%lu\n", "lpass_cdc_wsa2_macro_set_cur_state", a2);
    return 4294967274LL;
  }
  *(_DWORD *)(v2 + 560) = a2;
  queue_work_on(32, system_wq, v2 + 568);
  return 0;
}
