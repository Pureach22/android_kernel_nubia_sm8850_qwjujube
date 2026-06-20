bool __fastcall policy_mgr_is_conn_lead_to_bw_downgrade(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4)
{
  unsigned int bw; // w20
  _BOOL8 result; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  bw = policy_mgr_get_bw(a4);
  if ( (policy_mgr_is_conn_lead_to_dbs_sbs(a1, a2, a3) & 1) != 0 )
  {
    policy_mgr_get_hw_dbs_max_bw(a1, v10);
    result = bw > HIDWORD(v10[0]) && bw > LODWORD(v10[0]);
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
