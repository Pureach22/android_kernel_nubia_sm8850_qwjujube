__int64 __fastcall swr_dmic_event_notify(__int64 a1, __int16 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w3
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v7; // x8
  int v8; // w9
  __int64 v10; // x19
  __int64 v11; // x0
  __int64 v12; // x0
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1 )
  {
    v6 = *(_QWORD *)(a1 - 168);
    if ( !v6 || (v7 = *(_QWORD *)(v6 + 224)) == 0 )
    {
      if ( (unsigned int)__ratelimit(&swr_dmic_up__rs, "swr_dmic_up") )
        dev_err(v6 + 72, "%s: swr_dmic is NULL\n", "swr_dmic_up");
      goto LABEL_33;
    }
    v8 = *(_DWORD *)(v7 + 68);
    *(_DWORD *)(v7 + 68) = v8 + 1;
    if ( !v8 )
    {
      v11 = *(_QWORD *)(v7 + 40);
      if ( !v11 )
      {
        if ( (unsigned int)__ratelimit(&enable_wcd_codec_supply__rs, "enable_wcd_codec_supply") )
          printk(&unk_7DE9, "enable_wcd_codec_supply");
        goto LABEL_33;
      }
      result = wcd939x_codec_force_enable_micbias_v2(v11, 1, *(unsigned int *)(v7 + 48));
      if ( (_DWORD)result )
        goto LABEL_34;
    }
    v10 = *(_QWORD *)(a1 - 168);
    v13[0] = 0;
    if ( v10 && *(_QWORD *)(v10 + 224) )
    {
      if ( (unsigned int)swr_get_logical_dev_num(v10, *(_QWORD *)(v10 + 984), v13) )
      {
        usleep_range_state(1000, 1100, 2);
        if ( (unsigned int)swr_get_logical_dev_num(v10, *(_QWORD *)(v10 + 984), v13) )
        {
          usleep_range_state(1000, 1100, 2);
          if ( (unsigned int)swr_get_logical_dev_num(v10, *(_QWORD *)(v10 + 984), v13) )
          {
            usleep_range_state(1000, 1100, 2);
            if ( (unsigned int)swr_get_logical_dev_num(v10, *(_QWORD *)(v10 + 984), v13) )
            {
              usleep_range_state(1000, 1100, 2);
              if ( (unsigned int)swr_get_logical_dev_num(v10, *(_QWORD *)(v10 + 984), v13) )
              {
                usleep_range_state(1000, 1100, 2);
                swr_get_logical_dev_num(v10, *(_QWORD *)(v10 + 984), v13);
              }
            }
          }
        }
      }
      result = 0;
      *(_BYTE *)(v10 + 64) = v13[0];
      goto LABEL_34;
    }
    if ( (unsigned int)__ratelimit(&swr_dmic_reset__rs, "swr_dmic_reset") )
      dev_err(v10 + 72, "%s: swr_dmic is NULL\n", "swr_dmic_reset");
LABEL_33:
    result = 4294967274LL;
    goto LABEL_34;
  }
  if ( a2 )
  {
LABEL_7:
    result = 0;
    goto LABEL_34;
  }
  v2 = *(_QWORD *)(a1 - 168);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 224)) == 0 )
  {
    if ( (unsigned int)__ratelimit(&swr_dmic_down__rs, "swr_dmic_down") )
      dev_err(v2 + 72, "%s: swr_dmic is NULL\n", "swr_dmic_down");
    goto LABEL_33;
  }
  v4 = *(_DWORD *)(v3 + 68) - 1;
  *(_DWORD *)(v3 + 68) = v4;
  if ( v4 < 0 )
  {
    dev_warn(v2 + 72, "%s: mismatch in supply count %d\n", "swr_dmic_down");
    result = 0;
    *(_DWORD *)(v3 + 68) = 0;
    goto LABEL_34;
  }
  if ( v4 )
    goto LABEL_7;
  v12 = *(_QWORD *)(v3 + 40);
  if ( v12 )
  {
    wcd939x_codec_force_enable_micbias_v2(v12, 8, *(unsigned int *)(v3 + 48));
    result = 0;
  }
  else
  {
    result = __ratelimit(&enable_wcd_codec_supply__rs, "enable_wcd_codec_supply");
    if ( (_DWORD)result )
    {
      printk(&unk_7DE9, "enable_wcd_codec_supply");
      result = 0;
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
