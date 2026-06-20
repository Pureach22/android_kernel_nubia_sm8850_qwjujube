__int64 __fastcall sme_set_roam_config_enable(__int64 a1, unsigned int a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-28h] BYREF
  __int64 v7; // [xsp+10h] [xbp-20h]
  __int64 v8; // [xsp+18h] [xbp-18h]
  __int64 v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 8);
  v8 = 0;
  v9 = 0;
  v6 = 0;
  v7 = 0;
  if ( *(_BYTE *)(v3 + 1708) == 1 )
  {
    v4 = *(_QWORD *)(a1 + 21552);
    LOBYTE(v7) = a3 != 0;
    result = wlan_cm_roam_cfg_set_value(v4, a2, 9u, (unsigned int *)&v6);
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
