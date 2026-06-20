__int64 __fastcall wlan_twt_check_responder_bit(__int64 a1, unsigned __int8 a2, int a3, unsigned __int8 a4)
{
  unsigned int v4; // w19

  v4 = a4;
  if ( a3 == 3 )
    return (a4 >> 2) & 1;
  if ( a3 != 1 )
    return 0;
  if ( policy_mgr_is_vdev_ll_lt_sap(a1, a2) )
    return (v4 >> 1) & 1;
  return v4 & 1;
}
