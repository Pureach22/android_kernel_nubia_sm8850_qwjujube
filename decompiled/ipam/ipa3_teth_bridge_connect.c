__int64 __fastcall ipa3_teth_bridge_connect(__int64 a1)
{
  const char *v1; // x8
  int v2; // w10
  __int64 v3; // x19
  __int64 v4; // x20
  unsigned int v5; // w0
  __int64 result; // x0
  unsigned int v7; // w19
  _QWORD v8[3]; // [xsp+8h] [xbp-28h] BYREF
  int v9; // [xsp+20h] [xbp-10h]
  int v10; // [xsp+24h] [xbp-Ch]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = "MODEM (USB RMNET_CV2X)";
  v2 = *(_DWORD *)(a1 + 8);
  v8[2] = 0;
  v10 = 0;
  v9 = 2;
  if ( v2 != 2 )
    v1 = "MODEM (USB RMNET)";
  v3 = ipa3_teth_ctx;
  if ( v2 == 2 )
    v4 = 164;
  else
    v4 = 160;
  v8[0] = v1;
  v8[1] = 0;
  LOBYTE(v10) = 1;
  v5 = ipa_pm_register((__int64)v8, (unsigned int *)(ipa3_teth_ctx + v4));
  if ( v5 )
  {
    v7 = v5;
    printk(&unk_3D0EF4, "ipa3_teth_bridge_connect");
    result = v7;
  }
  else
  {
    result = ipa_pm_activate_sync(*(_DWORD *)(v3 + v4));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
