__int64 __fastcall wmi_interop_issues_ap_attach_tlv(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 728);
  *(_QWORD *)(v1 + 2904) = extract_interop_issues_ap_ev_param_tlv;
  *(_QWORD *)(v1 + 2912) = send_set_rap_ps_cmd_tlv;
  return result;
}
