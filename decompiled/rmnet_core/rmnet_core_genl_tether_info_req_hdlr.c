__int64 __fastcall rmnet_core_genl_tether_info_req_hdlr(__int64 a1, __int64 a2)
{
  __int64 v2; // x1
  bool v3; // cc
  __int64 result; // x0
  __int16 v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && (v2 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 40LL)) != 0 )
  {
    v5 = 0;
    v3 = (int)nla_memcpy(&v5, v2, 2) < 1;
    result = 0xFFFFFFFFLL;
    if ( !v3 && HIBYTE(v5) )
    {
      rmnet_module_hook_perf_tether_cmd(1, (unsigned __int8)v5);
      result = 0;
    }
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
