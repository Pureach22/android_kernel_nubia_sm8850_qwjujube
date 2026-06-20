__int64 __fastcall gsi_ctrl_cmd_complete(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 56);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 48) + 48LL);
  result = gsi_ctrl_send_cpkt_tomodem(v2, *(const void **)a2, *(unsigned int *)(a2 + 88));
  *(_BYTE *)(v3 + 488) &= ~1u;
  return result;
}
