__int64 __fastcall digital_cdc_rsc_mgr_hw_vote_reset(__int64 a1)
{
  int v2; // w20
  __int64 result; // x0

  if ( a1 && (is_init_done & 1) != 0 )
  {
    mutex_lock(&hw_vote_lock);
    if ( (_clk_is_enabled(a1) & 1) != 0 )
    {
      v2 = 0;
      do
      {
        clk_disable(a1);
        clk_unprepare(a1);
        --v2;
      }
      while ( (_clk_is_enabled(a1) & 1) != 0 );
      if ( v2 )
      {
        do
        {
          if ( !(unsigned int)clk_prepare(a1) )
          {
            if ( (unsigned int)clk_enable(a1) )
              clk_unprepare(a1);
          }
        }
        while ( !__CFADD__(v2++, 1) );
      }
    }
    return mutex_unlock(&hw_vote_lock);
  }
  else
  {
    result = __ratelimit(&digital_cdc_rsc_mgr_hw_vote_reset__rs, "digital_cdc_rsc_mgr_hw_vote_reset");
    if ( (_DWORD)result )
      return printk(&unk_6FBE, "digital_cdc_rsc_mgr_hw_vote_reset");
  }
  return result;
}
