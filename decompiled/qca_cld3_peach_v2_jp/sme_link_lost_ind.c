__int64 __fastcall sme_link_lost_ind(__int64 result, unsigned int *a2)
{
  __int64 v3; // x20
  unsigned int v4; // w1
  __int64 v5; // x0
  __int64 (__fastcall *v6)(__int64, unsigned int *); // x8
  __int64 v7; // x0
  _QWORD v8[5]; // [xsp+8h] [xbp-28h] BYREF

  v3 = result;
  v8[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v8, 0, 32);
  if ( a2 )
  {
    v4 = *a2;
    v5 = *(_QWORD *)(result + 21552);
    HIDWORD(v8[0]) = a2[1];
    result = wlan_cm_roam_cfg_set_value(v5, v4, 0x1Au, (unsigned int *)v8);
  }
  v6 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v3 + 14312);
  if ( v6 )
  {
    v7 = *(_QWORD *)(v3 + 12760);
    if ( *((_DWORD *)v6 - 1) != -1332002087 )
      __break(0x8228u);
    result = v6(v7, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
