__int64 __fastcall csr_roam_issue_deauth_sta_cmd(__int64 a1, __int64 a2, unsigned int *a3)
{
  return csr_roam_issue_discon_sta_roam_cmd(a1, a2, 2u, a3);
}
