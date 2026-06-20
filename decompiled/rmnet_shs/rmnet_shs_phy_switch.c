__int64 __fastcall rmnet_shs_phy_switch(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int8 v8; // w19
  __int64 result; // x0
  char v11; // w1
  _QWORD v12[16]; // [xsp+0h] [xbp-80h] BYREF

  v8 = a2;
  v12[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v12[8], 0, 56);
  result = rmnet_is_real_dev_registered(a1, a2, a3, a4, a5, a6, a7, a8, 0, 0, 0, 0, 0, 0, 0, 0);
  if ( (_DWORD)result )
  {
    if ( change_rps(*(_QWORD *)(a1 + 232), v8) )
    {
      result = 0xFFFFFFFFLL;
    }
    else
    {
      v11 = BYTE2(dword_19499);
      BYTE2(dword_19499) = v8;
      BYTE1(dword_19499) = v11;
      byte_19496 = 1 << v8;
      rmnet_shs_create_phy_msg_resp(v12);
      rmnet_shs_genl_msg_direct_send_to_userspace(v12);
      result = 0;
    }
  }
  else
  {
    ++qword_1A480;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
