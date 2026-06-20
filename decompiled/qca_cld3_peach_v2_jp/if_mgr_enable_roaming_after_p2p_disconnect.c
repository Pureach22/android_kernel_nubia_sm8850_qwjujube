__int64 __fastcall if_mgr_enable_roaming_after_p2p_disconnect(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v5; // x0
  unsigned __int8 v6; // w8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  _DWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 152);
  if ( v3 && (v5 = *(_QWORD *)(v3 + 80)) != 0 )
  {
    v6 = *(_BYTE *)(a2 + 104);
    v17[0] = a3;
    v17[1] = v6;
    if ( (cfg_p2p_is_roam_config_disabled(v5, a2) & 1) != 0 && *(_DWORD *)(a2 + 16) == 2 )
    {
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: P2P client disconnected, enable roam",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "if_mgr_enable_roaming_after_p2p_disconnect");
      result = wlan_objmgr_pdev_iterate_obj_list(
                 a1,
                 2,
                 (void (__fastcall *)(__int64, __int64, __int64))if_mgr_enable_roaming_on_vdev,
                 (__int64)v17,
                 0,
                 0x4Eu);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
