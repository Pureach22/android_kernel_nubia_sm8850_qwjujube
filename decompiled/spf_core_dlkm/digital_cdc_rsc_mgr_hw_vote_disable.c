__int64 __fastcall digital_cdc_rsc_mgr_hw_vote_disable(__int64 a1)
{
  __int64 result; // x0

  if ( a1 && (is_init_done & 1) != 0 )
  {
    mutex_lock(&hw_vote_lock);
    clk_disable(a1);
    clk_unprepare(a1);
    return mutex_unlock(&hw_vote_lock);
  }
  else
  {
    result = __ratelimit(&digital_cdc_rsc_mgr_hw_vote_disable__rs, "digital_cdc_rsc_mgr_hw_vote_disable");
    if ( (_DWORD)result )
      return printk(&unk_6FBE, "digital_cdc_rsc_mgr_hw_vote_disable");
  }
  return result;
}
