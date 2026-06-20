__int64 __fastcall clk_rpmh_prepare(__int64 a1)
{
  mutex_lock(&rpmh_clk_lock);
  LODWORD(a1) = clk_rpmh_aggregate_state_send_command(a1, 1);
  mutex_unlock(&rpmh_clk_lock);
  return (unsigned int)a1;
}
