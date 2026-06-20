__int64 __fastcall wcd939x_config_2Vpk_mode(__int64 result, __int64 a2, int a3)
{
  int v3; // w8
  __int64 v4; // x19
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a2 + 313);
  v10[0] = 0;
  if ( v3 != 1 )
    goto LABEL_17;
  v4 = result;
  result = wcd_mbhc_get_impedance(*(_QWORD *)(a2 + 256), (char *)v10 + 4, v10);
  if ( !(_DWORD)result )
  {
    if ( a3 == 2 )
    {
      if ( HIDWORD(v10[0]) < 0x104 )
        goto LABEL_17;
      snd_soc_component_update_bits(v4, 12595, 31, 2);
      v6 = v4;
      v7 = 12598;
      v8 = 31;
    }
    else
    {
      if ( a3 != 1 )
      {
        snd_soc_component_update_bits(v4, 12595, 64, 64);
        v6 = v4;
        v7 = 12595;
        v8 = 128;
        if ( HIDWORD(v10[0]) > 0x103 )
          v9 = 128;
        else
          v9 = 0;
        goto LABEL_16;
      }
      if ( HIDWORD(v10[0]) < 0x104 )
      {
        v6 = v4;
        v7 = 12466;
        v8 = 15;
        v9 = 13;
        goto LABEL_16;
      }
      snd_soc_component_update_bits(v4, 12296, 2, 2);
      v6 = v4;
      v7 = 12466;
      v8 = 15;
    }
    v9 = 2;
LABEL_16:
    result = snd_soc_component_update_bits(v6, v7, v8, v9);
    goto LABEL_17;
  }
  result = __ratelimit(&wcd939x_config_2Vpk_mode__rs, "wcd939x_config_2Vpk_mode");
  if ( (_DWORD)result )
    result = dev_err(*(_QWORD *)(v4 + 24), "%s: Unable to get impedance for 2Vpk mode", "wcd939x_config_2Vpk_mode");
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
