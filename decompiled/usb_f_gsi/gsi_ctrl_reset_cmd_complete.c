__int64 __fastcall gsi_ctrl_reset_cmd_complete(__int64 a1, __int64 a2)
{
  return gsi_ctrl_send_cpkt_tomodem(*(_QWORD *)(a2 + 56), *(const void **)a2, 0);
}
