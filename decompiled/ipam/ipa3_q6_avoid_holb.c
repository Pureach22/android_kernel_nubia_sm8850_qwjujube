void ipa3_q6_avoid_holb()
{
  int v0; // w9
  unsigned int i; // w19
  unsigned int ep_mapping; // w0
  unsigned int v3; // w20
  int v4; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-18h]
  int v6; // [xsp+10h] [xbp-10h]
  __int16 v7; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 1;
  v6 = 0;
  v0 = *(_DWORD *)(ipa3_ctx + 32240);
  v5 = 0;
  v4 = 0;
  LOWORD(v6) = 1;
  if ( v0 == 16 )
    ipa3_cal_ep_holb_scale_base_val(0, &v4);
  for ( i = 0; i != 134; ++i )
  {
    if ( i == 85
      || i == 115
      || (i & 0xFD) == 0x4D
      || i == 75
      || i == 61
      || (i & 0xFD) == 0x39
      || i == 53
      || (i & 0xFB) == 0x33 )
    {
      ep_mapping = ipa_get_ep_mapping(i);
      if ( ep_mapping != -1 )
      {
        v3 = ep_mapping;
        if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
          ((void (__fastcall *)(__int64, _QWORD, __int16 *))ipahal_write_reg_n_fields)(49, ep_mapping, &v7);
        ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(52, v3, &v4);
        if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
          ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(52, v3, &v4);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
}
