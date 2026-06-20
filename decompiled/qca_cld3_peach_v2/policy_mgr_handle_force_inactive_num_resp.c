__int64 __fastcall policy_mgr_handle_force_inactive_num_resp(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  unsigned int v13; // w22
  unsigned int v14; // w23
  unsigned int v15; // w22
  unsigned int v16; // w21
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int8 *)(a4 + 32);
  v17[0] = 0;
  if ( v8 == 1 )
  {
    ml_nlink_set_curr_force_inactive_num_state(a1, a2, *(unsigned __int8 *)(a3 + 118), *(unsigned __int16 *)(a3 + 114));
    policy_mgr_update_dynamic_inactive_bitmap(a1, a2, a3, a4);
    result = policy_mgr_handle_vdev_active_inactive_resp(a1, a2, a3, a4);
LABEL_78:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, *(unsigned int *)(a3 + 44), a3 + 84, v17, (char *)v17 + 4);
  result = ml_nlink_set_curr_force_inactive_num_state(a1, a2, *(unsigned int *)(a3 + 52), LODWORD(v17[0]));
  if ( !*(_DWORD *)(a4 + 20) )
    goto LABEL_78;
  v13 = *(_DWORD *)(a4 + 24);
  v14 = *(_DWORD *)(a3 + 84) ^ v13;
  if ( v14 )
  {
    if ( (v14 & 1) != 0 )
      result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0);
    if ( v14 != 1 )
    {
      if ( (v14 & 2) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 1u);
      if ( v14 >= 4 )
      {
        if ( (v14 & 4) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 2u);
        if ( v14 >= 8 )
        {
          if ( (v14 & 8) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 3u);
          if ( v14 >= 0x10 )
          {
            if ( (v14 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 4u);
            if ( v14 >= 0x20 && (v14 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 5u);
          }
        }
      }
    }
  }
  if ( v13 )
  {
    if ( (v13 & 1) != 0 )
      result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0);
    if ( v13 != 1 )
    {
      if ( (v13 & 2) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 1u);
      if ( v13 >= 4 )
      {
        if ( (v13 & 4) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 2u);
        if ( v13 >= 8 )
        {
          if ( (v13 & 8) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 3u);
          if ( v13 >= 0x10 )
          {
            if ( (v13 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 4u);
            if ( v13 >= 0x20 && (v13 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 5u);
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(a4 + 20) < 2u )
    goto LABEL_78;
  v15 = *(_DWORD *)(a4 + 28);
  v16 = *(_DWORD *)(a3 + 88) ^ v15;
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
  }
  if ( v15 )
  {
    if ( (v15 & 1) != 0 )
      result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x20u);
    if ( v15 != 1 )
    {
      if ( (v15 & 2) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x21u);
      if ( v15 >= 4 )
      {
        if ( (v15 & 4) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x22u);
        if ( v15 >= 8 )
        {
          if ( (v15 & 8) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x23u);
          if ( v15 >= 0x10 )
          {
            if ( (v15 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x24u);
            if ( v15 >= 0x20 && (v15 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x25u);
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(a4 + 20) <= 2u )
    goto LABEL_78;
  __break(0x5512u);
  return policy_mgr_handle_no_force_resp(result, v10, v11, v12);
}
