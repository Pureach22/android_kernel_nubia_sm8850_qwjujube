__int64 __fastcall cm_roam_offload_enabled(__int64 a1)
{
  char v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  wlan_mlme_get_roaming_offload(a1, v2);
  _ReadStatusReg(SP_EL0);
  return (unsigned __int8)v2[0];
}
