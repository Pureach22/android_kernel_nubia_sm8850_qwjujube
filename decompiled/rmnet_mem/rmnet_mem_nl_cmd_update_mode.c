__int64 __fastcall rmnet_mem_nl_cmd_update_mode(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x19
  int v5; // w0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 32);
  v7[0] = 0;
  v3 = *(_QWORD *)(v2 + 8);
  if ( v3 )
  {
    v4 = a2;
    nla_memcpy(v7, v3, 8);
    a2 = v4;
    v5 = 400;
  }
  else
  {
    v5 = 401;
  }
  rmnet_mem_genl_send_int_to_userspace_no_info(v5, a2);
  _ReadStatusReg(SP_EL0);
  return 0;
}
