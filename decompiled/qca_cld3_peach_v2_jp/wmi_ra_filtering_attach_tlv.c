__int64 __fastcall wmi_ra_filtering_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 1216LL) = send_wow_sta_ra_filter_cmd_tlv;
  return result;
}
