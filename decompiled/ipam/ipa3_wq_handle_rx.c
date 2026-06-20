__int64 __fastcall ipa3_wq_handle_rx(_QWORD *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  int v4; // w8
  unsigned __int64 v11; // x8

  _ReadStatusReg(SP_EL0);
  result = ipa3_inc_client_enable_clks();
  if ( (ipa_net_initialized & 1) != 0 )
  {
    v3 = a1[24];
    if ( v3 )
    {
      result = napi_schedule_prep(a1[24]);
      if ( (result & 1) != 0 )
        result = _napi_schedule(v3);
      goto LABEL_10;
    }
    v4 = *(_DWORD *)(a1[179] + 4LL);
    if ( v4 == 121 )
    {
      result = napi_schedule_prep(a1 + 120);
      if ( (result & 1) != 0 )
        result = _napi_schedule(a1 + 120);
      goto LABEL_10;
    }
  }
  else
  {
    v4 = *(_DWORD *)(a1[179] + 4LL);
  }
  if ( v4 == 105 )
  {
    _X9 = a1 + 61;
    __asm { PRFM            #0x11, [X9] }
    do
      v11 = __ldxr(_X9);
    while ( __stlxr(v11 | 1, _X9) );
    __dmb(0xBu);
    if ( (v11 & 1) == 0 )
      result = _tasklet_schedule(a1 + 60);
  }
  else
  {
    result = ipa3_handle_rx(a1 - 24);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
