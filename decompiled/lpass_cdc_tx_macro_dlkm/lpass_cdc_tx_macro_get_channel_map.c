__int64 __fastcall lpass_cdc_tx_macro_get_channel_map(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int64 v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 96);
  v11 = 0;
  v12[0] = 0;
  if ( (lpass_cdc_tx_macro_get_data(v6, v12, &v11, (__int64)"lpass_cdc_tx_macro_get_channel_map") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_8;
  }
  v7 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)(v7 - 1) >= 3 )
  {
    result = __ratelimit(&lpass_cdc_tx_macro_get_channel_map__rs, "lpass_cdc_tx_macro_get_channel_map");
    if ( (_DWORD)result )
    {
      dev_err(v12[0], "%s: Invalid AIF\n", "lpass_cdc_tx_macro_get_channel_map");
      result = 0;
    }
    goto LABEL_8;
  }
  v8 = v11;
  *a3 = *(_QWORD *)(v11 + 8 * v7 + 2544);
  v9 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v9 <= 3 )
  {
    result = 0;
    *a2 = *(_QWORD *)(v8 + 8 * v9 + 2576);
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return lpass_cdc_tx_mute_stream();
}
