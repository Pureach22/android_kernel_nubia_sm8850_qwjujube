__int64 __fastcall lpass_cdc_tx_macro_event_handler(__int64 a1, __int16 a2, int a3)
{
  __int64 v6; // x19
  __int64 result; // x0
  __int64 v8; // x21
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10[0] = 0;
  if ( (lpass_cdc_tx_macro_get_data(a1, v10, &v9, "lpass_cdc_tx_macro_event_handler") & 1) != 0 )
  {
    if ( a2 == 10 )
    {
      v8 = v9;
      if ( *(_BYTE *)(v9 + 2684) == 1 )
        snd_soc_component_update_bits(a1, 1068, 64, (unsigned int)(a3 << 6));
      result = 0;
      if ( a3 )
        *(_BYTE *)(v8 + 2685) = 1;
      else
        *(_BYTE *)(v8 + 2685) = 0;
    }
    else if ( a2 == 7 )
    {
      lpass_cdc_rsc_clk_reset(v10[0], 0);
      result = 0;
    }
    else if ( a2 == 4
           && ((v6 = v10[0], (*(_WORD *)(v10[0] + 488LL) & 7) != 0) || *(_DWORD *)(v10[0] + 500LL) != 2)
           && !(unsigned int)lpass_cdc_runtime_suspend(v10[0]) )
    {
      _pm_runtime_disable(v6, 1);
      _pm_runtime_set_status(v6, 2);
      pm_runtime_enable(v6);
      result = 0;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
