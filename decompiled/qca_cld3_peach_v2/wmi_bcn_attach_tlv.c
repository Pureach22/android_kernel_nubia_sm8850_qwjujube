__int64 __fastcall wmi_bcn_attach_tlv(__int64 result)
{
  *(_QWORD *)(*(_QWORD *)(result + 728) + 1344LL) = send_bcn_buf_ll_cmd_tlv;
  return result;
}
