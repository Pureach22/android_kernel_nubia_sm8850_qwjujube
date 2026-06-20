__int64 __fastcall clk_rpmh_unprepare(__int64 a1)
{
  mutex_lock(&rpmh_clk_lock);
  clk_rpmh_aggregate_state_send_command(a1, 0);
  return mutex_unlock(&rpmh_clk_lock);
}
