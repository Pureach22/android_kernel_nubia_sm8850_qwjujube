__int64 __fastcall syna_tcm_clear_data_duplicator(__int64 a1)
{
  if ( a1 )
  {
    memset((void *)(a1 + 5080), 0, 0x1000u);
    return 0;
  }
  else
  {
    printk(unk_3365A, "syna_tcm_clear_data_duplicator", 0LL);
    return 4294967055LL;
  }
}
