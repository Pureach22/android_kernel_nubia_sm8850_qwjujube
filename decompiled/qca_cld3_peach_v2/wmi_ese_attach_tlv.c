__int64 __fastcall wmi_ese_attach_tlv(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 728);
  *(_QWORD *)(v1 + 896) = send_plm_stop_cmd_tlv;
  *(_QWORD *)(v1 + 904) = send_plm_start_cmd_tlv;
  return result;
}
