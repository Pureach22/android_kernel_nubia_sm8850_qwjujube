__int64 __fastcall wmi_fils_sk_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 888LL) = send_roam_scan_send_hlp_cmd_tlv;
  return result;
}
