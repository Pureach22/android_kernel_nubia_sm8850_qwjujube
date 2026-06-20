__int64 __fastcall wlan_cm_send_roam_linkspeed_state(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w20
  __int64 result; // x0
  __int16 v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v1 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    v2 = *(_QWORD *)v1;
    v5 = *(_WORD *)(v1 + 8);
    v3 = wlan_cm_tgt_send_roam_linkspeed_state(v2, &v5);
    _qdf_mem_free(v1);
    result = v3;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
