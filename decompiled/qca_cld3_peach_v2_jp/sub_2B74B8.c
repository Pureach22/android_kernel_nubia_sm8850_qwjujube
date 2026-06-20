__int64 __fastcall sub_2B74B8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return cm_roam_send_vendor_handoff_param_req(a1, a2, a3, a4, a5, a6 & 0xFFFFFFFF0000FFFFLL | 0xBF50000);
}
