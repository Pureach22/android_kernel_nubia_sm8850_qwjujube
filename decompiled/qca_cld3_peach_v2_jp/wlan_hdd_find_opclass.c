__int64 __fastcall wlan_hdd_find_opclass(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  sme_get_opclass(a1, a2, a3, v4);
  _ReadStatusReg(SP_EL0);
  return v4[0];
}
