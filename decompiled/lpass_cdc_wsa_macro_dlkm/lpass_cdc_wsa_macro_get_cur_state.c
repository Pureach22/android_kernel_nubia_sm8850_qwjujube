__int64 __fastcall lpass_cdc_wsa_macro_get_cur_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  if ( v2 )
  {
    *a2 = *(unsigned int *)(v2 + 688);
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_cur_state__rs, "lpass_cdc_wsa_macro_get_cur_state") )
      printk(&unk_EB4E, "lpass_cdc_wsa_macro_get_cur_state");
    return 4294967274LL;
  }
}
