__int64 __fastcall wma_post_link_status(__int64 a1, char a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 4) = a2;
  v12[1] = a1;
  memset(&v12[2], 0, 32);
  v12[0] = 5219;
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)v12,
             0xD31u,
             (__int64)"wma_post_link_status");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to post link status ind msg",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wma_post_link_status");
    result = _qdf_mem_free(a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
