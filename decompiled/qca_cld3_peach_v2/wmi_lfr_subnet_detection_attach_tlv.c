__int64 __fastcall wmi_lfr_subnet_detection_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 720LL) = send_set_gateway_params_cmd_tlv;
  return result;
}
