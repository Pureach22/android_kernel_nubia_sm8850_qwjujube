__int64 __fastcall ucfg_cm_abort_roam_scan(__int64 a1, unsigned int a2)
{
  __int64 v3; // x20
  __int64 result; // x0
  char v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 80);
  v5[0] = 0;
  ucfg_mlme_is_roam_scan_offload_enabled(v3, v5);
  result = 0;
  if ( v5[0] == 1 )
    result = cm_roam_send_rso_cmd(v3, a2, 5u, 0x18u);
  _ReadStatusReg(SP_EL0);
  return result;
}
