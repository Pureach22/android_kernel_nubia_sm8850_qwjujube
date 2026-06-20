__int64 __fastcall policy_mgr_update_nan_vdev_mac_info(__int64 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  int v14; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v15[12]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v16; // [xsp+18h] [xbp-18h]
  _QWORD v17[2]; // [xsp+20h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)&v15[8] = 0;
  v16 = 0;
  v14 = a2;
  *(_QWORD *)v15 = a3;
  v17[0] = 0;
  if ( !(unsigned int)policy_mgr_get_old_and_new_hw_index(a1, (_DWORD *)v17 + 1, v17) )
  {
    if ( LODWORD(v17[0]) == 0xFFFF )
    {
      v12 = "%s: HW mode is not yet initialized";
      goto LABEL_5;
    }
    if ( !(unsigned int)policy_mgr_get_hw_mode_from_idx(a1, v17[0], (__int64)&v15[4]) )
    {
      policy_mgr_update_hw_mode_conn_info(a1, 1u, (__int64)&v14, *(unsigned __int64 *)&v15[4], v16, 0, 0);
      result = 0;
      goto LABEL_6;
    }
  }
  v12 = "%s: Failed to get HW mode index";
LABEL_5:
  qdf_trace_msg(0x4Fu, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_current_hw_mode");
  result = 16;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
