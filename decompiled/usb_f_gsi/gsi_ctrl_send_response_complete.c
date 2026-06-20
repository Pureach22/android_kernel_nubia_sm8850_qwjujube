__int64 __fastcall gsi_ctrl_send_response_complete(__int64 a1, __int64 a2)
{
  return gsi_ctrl_send_notification(*(_QWORD *)(a2 + 56));
}
