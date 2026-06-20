__int64 __fastcall digital_cdc_rsc_mgr_hw_vote_enable(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w0

  if ( a1 && (is_init_done & 1) != 0 )
  {
    mutex_lock(&hw_vote_lock);
    v2 = clk_prepare(a1);
    if ( !v2 )
    {
      v3 = clk_enable(a1);
      if ( v3 )
      {
        v2 = v3;
        clk_unprepare(a1);
      }
      else
      {
        v2 = 0;
      }
    }
    mutex_unlock(&hw_vote_lock);
    return v2;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&digital_cdc_rsc_mgr_hw_vote_enable__rs, "digital_cdc_rsc_mgr_hw_vote_enable") )
      printk(&unk_6FBE, "digital_cdc_rsc_mgr_hw_vote_enable");
    return 4294967274LL;
  }
}
