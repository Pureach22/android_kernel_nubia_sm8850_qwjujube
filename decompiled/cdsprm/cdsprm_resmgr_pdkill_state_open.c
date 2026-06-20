__int64 __fastcall cdsprm_resmgr_pdkill_state_open(__int64 a1, __int64 a2)
{
  return single_open(a2, cdsprm_resmgr_pdkill_state_show, *(_QWORD *)(a1 + 696));
}
