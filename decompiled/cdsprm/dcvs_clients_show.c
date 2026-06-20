__int64 __fastcall dcvs_clients_show(__int64 a1)
{
  int v2; // w0

  v2 = ((__int64 (__fastcall *)(_QWORD, __int64))cdsprm_sysmon_dcvs_clients_votes)(0, 1);
  if ( v2 )
    seq_printf(a1, "cdsprm_sysmon_dcvs_clients_votes() failed. Error : %d\n", v2);
  else
    seq_write(a1, "Check kernel log for cdsprm_sysmon_dcvs_clients_votes() output\n", 63);
  return 0;
}
