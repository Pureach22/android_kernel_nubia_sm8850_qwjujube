__int64 __fastcall ml_post_get_link_state_msg(__int64 a1)
{
  __int64 result; // x0
  _QWORD v2[7]; // [xsp+8h] [xbp-38h] BYREF

  v2[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  v2[1] = a1;
  v2[4] = 0;
  v2[5] = 0;
  v2[2] = ml_get_link_state_req_cb;
  v2[3] = ml_get_link_state_req_flush_cb;
  result = scheduler_post_message_debug(
             0x48u,
             0x1Fu,
             72,
             (unsigned __int16 *)v2,
             0x4DBu,
             (__int64)"ml_post_get_link_state_msg");
  _ReadStatusReg(SP_EL0);
  return result;
}
