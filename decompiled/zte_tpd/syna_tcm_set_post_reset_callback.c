__int64 __fastcall syna_tcm_set_post_reset_callback(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 )
  {
    *(_QWORD *)(a1 + 9184) = a2;
    *(_QWORD *)(a1 + 9176) = a3;
    return 0;
  }
  else
  {
    printk(&unk_3365A, "syna_tcm_set_post_reset_callback", a3);
    return 4294967055LL;
  }
}
