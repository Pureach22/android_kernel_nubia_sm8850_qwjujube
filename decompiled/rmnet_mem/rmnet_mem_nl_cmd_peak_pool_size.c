__int64 __fastcall rmnet_mem_nl_cmd_peak_pool_size(__int64 a1, __int64 a2)
{
  __int64 v2; // x10
  __int64 v3; // x19
  int v4; // w0
  __int64 v6; // [xsp+0h] [xbp-20h] BYREF
  __int64 v7; // [xsp+8h] [xbp-18h]
  int v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 32);
  v8 = 0;
  v6 = 0;
  v7 = 0;
  ++qword_8E10;
  if ( *(_QWORD *)(v2 + 16) )
  {
    v3 = a2;
    nla_memcpy(&v6, *(_QWORD *)(v2 + 16), 20);
    if ( (v8 & 1) != 0 && (unsigned int)(v6 - 1) <= 0x3E7 )
      rmnet_mem_pb_ind_max = (unsigned int)v6;
    if ( (v8 & 2) != 0 && (unsigned int)(HIDWORD(v6) - 1) <= 0x3E7 )
      qword_8F58 = HIDWORD(v6);
    a2 = v3;
    if ( (v8 & 4) != 0 && (unsigned int)(v7 - 1) <= 0x3E7 )
      qword_8F60 = (unsigned int)v7;
    if ( (v8 & 8) != 0 && (unsigned int)(HIDWORD(v7) - 1) <= 0x3E7 )
      qword_8F68 = HIDWORD(v7);
    v4 = 400;
  }
  else
  {
    v4 = 401;
  }
  rmnet_mem_genl_send_int_to_userspace_no_info(v4, a2);
  _ReadStatusReg(SP_EL0);
  return 0;
}
