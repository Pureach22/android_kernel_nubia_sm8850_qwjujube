__int64 __usercall sub_3034AC@<X0>(__int64 a1@<X0>, unsigned __int64 a2@<X8>)
{
  __int64 v2; // x19

  return wlan_cm_tgt_send_roam_vendor_handoff_config(a1, v2 + (a2 >> 37));
}
