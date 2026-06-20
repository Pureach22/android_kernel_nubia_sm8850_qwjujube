__int64 __fastcall policy_mgr_handle_force_active_resp(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w8
  __int64 v9; // x3
  __int64 result; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  unsigned int v14; // w8
  unsigned int v15; // w21
  unsigned int v16; // w21
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)(a4 + 32);
  v17 = 0;
  if ( v7 == 1 )
  {
    if ( *(_BYTE *)(a3 + 100) )
      v9 = 0;
    else
      v9 = 2;
    ml_nlink_set_curr_force_active_state(a1, a2, *(unsigned __int16 *)(a3 + 114), v9);
    policy_mgr_update_dynamic_inactive_bitmap(a1, a2, a3, a4);
    result = policy_mgr_handle_vdev_active_inactive_resp(a1, a2, a3, a4);
LABEL_47:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, *(unsigned int *)(a3 + 44), a3 + 84, a4 + 40, &v17);
  result = ml_nlink_set_curr_force_active_state(a1, a2, *(unsigned int *)(a4 + 40), 2);
  v14 = *(_DWORD *)(a4 + 8);
  if ( !v14 )
    goto LABEL_47;
  v15 = *(_DWORD *)(a4 + 12);
  if ( v15 )
  {
    if ( (v15 & 1) != 0 )
      result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0);
    if ( v15 != 1 )
    {
      if ( (v15 & 2) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 1u);
      if ( v15 >= 4 )
      {
        if ( (v15 & 4) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 2u);
        if ( v15 >= 8 )
        {
          if ( (v15 & 8) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 3u);
          if ( v15 >= 0x10 )
          {
            if ( (v15 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 4u);
            if ( v15 >= 0x20 && (v15 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 5u);
          }
        }
      }
    }
    v14 = *(_DWORD *)(a4 + 8);
  }
  if ( v14 < 2 )
    goto LABEL_47;
  v16 = *(_DWORD *)(a4 + 16);
  if ( v16 )
  {
    if ( (v16 & 1) != 0 )
      result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x20u);
    if ( v16 != 1 )
    {
      if ( (v16 & 2) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x21u);
      if ( v16 >= 4 )
      {
        if ( (v16 & 4) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x22u);
        if ( v16 >= 8 )
        {
          if ( (v16 & 8) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x23u);
          if ( v16 >= 0x10 )
          {
            if ( (v16 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x24u);
            if ( v16 >= 0x20 && (v16 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x25u);
          }
        }
      }
    }
    v14 = *(_DWORD *)(a4 + 8);
  }
  if ( v14 <= 2 )
    goto LABEL_47;
  __break(0x5512u);
  return policy_mgr_handle_force_inactive_resp(result, v11, v12, v13);
}
