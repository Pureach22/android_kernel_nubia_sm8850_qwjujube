__int64 __fastcall rmnet_shs_genl_cleanup(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  int v5; // w1
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 32);
    v7 = 0;
    v4 = *(_QWORD *)(v2 + 64);
    if ( v4 && (int)nla_memcpy(&v7, v4, 4) >= 1 )
    {
      rmnet_shs_wq_cleanup_hash_tbl(1, v7);
      v5 = 620;
    }
    else
    {
      v5 = 621;
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
