__int64 __fastcall wlan_cm_roam_link_speed_update(__int64 a1, char a2, char a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v18)(__int64); // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = nullptr;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  result = _qdf_mem_malloc(0x10u, "wlan_cm_roam_link_speed_update", 414);
  if ( result )
  {
    v7 = result;
    *(_QWORD *)result = a1;
    *(_BYTE *)(result + 9) = a3 & 1;
    *(_BYTE *)(result + 8) = a2;
    v17 = result;
    v18 = wlan_cm_send_roam_linkspeed_state;
    result = scheduler_post_message_debug(
               0x1Fu,
               0x48u,
               72,
               (unsigned __int16 *)&v16,
               0x1ABu,
               (__int64)"wlan_cm_roam_link_speed_update");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: post msg failed",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_cm_roam_link_speed_update");
      result = _qdf_mem_free(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
