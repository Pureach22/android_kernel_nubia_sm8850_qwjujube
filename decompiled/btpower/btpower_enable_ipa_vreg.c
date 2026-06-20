__int64 __fastcall btpower_enable_ipa_vreg(__int64 a1)
{
  void *v1; // x0
  const char *v2; // x3
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v6; // [xsp+10h] [xbp-40h]
  __int64 v7; // [xsp+18h] [xbp-38h]
  __int64 v8; // [xsp+20h] [xbp-30h]
  __int64 v9; // [xsp+28h] [xbp-28h]
  __int64 v10; // [xsp+30h] [xbp-20h]
  __int64 v11; // [xsp+38h] [xbp-18h]
  __int64 v12; // [xsp+40h] [xbp-10h]
  __int64 v13; // [xsp+48h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( btpower_enable_ipa_vreg_config_done == 1 )
  {
    v1 = &unk_11DF7;
LABEL_5:
    result = printk(v1, "btpower_enable_ipa_vreg");
    goto LABEL_6;
  }
  v2 = *(const char **)(a1 + 168);
  if ( !v2 )
  {
    v1 = &unk_13537;
    goto LABEL_5;
  }
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  *(_QWORD *)s = 0;
  v6 = 0;
  snprintf(s, 0x40u, "{class: wlan_pdc, res: %s.%s, %s: %d}", v2, "e", "upval", 1);
  printk(&unk_113DC, "btpower_aop_set_vreg_param");
  if ( (qmp_send(*(_QWORD *)(a1 + 152), s, 64) & 0x80000000) != 0 )
  {
    result = printk(&unk_13130, "btpower_aop_set_vreg_param");
  }
  else
  {
    result = printk(&unk_12FF3, "btpower_enable_ipa_vreg");
    btpower_enable_ipa_vreg_config_done = 1;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
