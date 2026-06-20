__int64 __fastcall sme_neighbor_roam_is11r_assoc(__int64 a1, unsigned int a2)
{
  __int64 v2; // x0
  __int64 v4; // [xsp+8h] [xbp-28h] BYREF
  __int64 v5; // [xsp+10h] [xbp-20h]
  __int64 v6; // [xsp+18h] [xbp-18h]
  __int64 v7; // [xsp+20h] [xbp-10h]
  __int64 v8; // [xsp+28h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 21552);
  v6 = 0;
  v7 = 0;
  v4 = 0;
  v5 = 0;
  wlan_cm_roam_cfg_get_value(v2, a2, 0x15u, &v4);
  _ReadStatusReg(SP_EL0);
  return (unsigned __int8)v5;
}
