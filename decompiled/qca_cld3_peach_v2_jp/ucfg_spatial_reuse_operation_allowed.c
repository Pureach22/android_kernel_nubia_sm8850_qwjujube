__int64 __fastcall ucfg_spatial_reuse_operation_allowed(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 v21[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  result = 29;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = *(unsigned __int8 *)(a2 + 104);
    v21[0] = 0;
    if ( !(unsigned int)policy_mgr_get_connection_count(a1) )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: No active vdev",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "ucfg_spatial_reuse_operation_allowed");
      goto LABEL_9;
    }
    result = policy_mgr_get_mac_id_by_session_id(a1, v4, v21);
    if ( !(_DWORD)result )
    {
      if ( (unsigned int)policy_mgr_get_conc_vdev_on_same_mac(a1, v4, v21[0]) != 255
        && (policy_mgr_sr_same_mac_conc_enabled(a1, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
      {
        result = 11;
        goto LABEL_10;
      }
LABEL_9:
      result = 0;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
