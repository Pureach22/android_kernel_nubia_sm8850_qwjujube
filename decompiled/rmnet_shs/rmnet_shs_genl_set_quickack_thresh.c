__int64 __fastcall rmnet_shs_genl_set_quickack_thresh(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  int v5; // w20
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 32);
    v7[0] = 0;
    v4 = *(_QWORD *)(v2 + 48);
    if ( v4 )
    {
      v5 = 930;
      if ( (int)nla_memcpy(v7, v4, 8) >= 1 )
      {
        if ( rmnet_shs_wq_set_quickack_thresh() )
          v5 = 931;
        else
          v5 = 930;
      }
    }
    else
    {
      v5 = 930;
    }
    rmnet_shs_genl_send_int_to_userspace(a2, v5);
    result = 0;
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
