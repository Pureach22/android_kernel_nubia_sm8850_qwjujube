__int64 __fastcall qmi_rmnet_burst_fc_check(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0

  result = rmnet_get_qos_pt(a1);
  if ( result )
    return dfc_qmi_burst_check(a1, result, a2, a3, a4);
  return result;
}
