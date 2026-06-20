__int64 __fastcall lim_auth_response_timer_handler(__int64 a1)
{
  __int64 result; // x0
  _QWORD v2[7]; // [xsp+8h] [xbp-38h] BYREF

  v2[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v2[1], 0, 40);
  v2[0] = 5076;
  result = lim_post_msg_api(a1, (unsigned __int16 *)v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
