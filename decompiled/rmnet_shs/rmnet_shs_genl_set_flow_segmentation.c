__int64 __fastcall rmnet_shs_genl_set_flow_segmentation(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 32);
    v6[0] = 0;
    v4 = *(_QWORD *)(v2 + 32);
    if ( v4
      && (int)nla_memcpy(v6, v4, 8) >= 1
      && (unsigned int)rmnet_shs_wq_set_flow_segmentation(v6[0], SBYTE4(v6[0])) == 1 )
    {
      rmnet_shs_genl_send_int_to_userspace(a2, 929);
    }
    else
    {
      rmnet_shs_genl_send_int_to_userspace(a2, 920);
    }
    result = 0;
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
