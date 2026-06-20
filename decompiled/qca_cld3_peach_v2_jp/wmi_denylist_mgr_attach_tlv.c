__int64 __fastcall wmi_denylist_mgr_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 336LL) = send_reject_ap_list_cmd_tlv;
  return result;
}
