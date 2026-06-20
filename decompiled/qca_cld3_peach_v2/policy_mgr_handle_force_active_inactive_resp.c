__int64 __fastcall policy_mgr_handle_force_active_inactive_resp(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w8
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x3
  __int64 result; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  unsigned int v16; // w8
  unsigned int v17; // w21
  unsigned int v18; // w21
  unsigned int v19; // w8
  unsigned int v20; // w21
  unsigned int v21; // w21
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int8 *)(a4 + 32);
  v22 = 0;
  if ( v8 == 1 )
  {
    v9 = *(unsigned __int16 *)(a3 + 114);
    if ( *(_BYTE *)(a3 + 100) )
      v10 = 0;
    else
      v10 = 2;
    ml_nlink_set_curr_force_active_state(a1, a2, v9, v10);
    if ( *(_BYTE *)(a3 + 101) )
      v11 = 0;
    else
      v11 = 2;
    ml_nlink_set_curr_force_inactive_state(a1, a2, *(unsigned __int16 *)(a3 + 116), v11);
    policy_mgr_update_dynamic_inactive_bitmap(a1, a2, a3, a4);
    result = policy_mgr_handle_vdev_active_inactive_resp(a1, a2, a3, a4);
LABEL_91:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, *(unsigned int *)(a3 + 48), a3 + 92, a4 + 44, &v22);
  ml_nlink_set_curr_force_inactive_state(a1, a2, *(unsigned int *)(a4 + 44), 2);
  ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, *(unsigned int *)(a3 + 44), a3 + 84, a4 + 40, &v22);
  result = ml_nlink_set_curr_force_active_state(a1, a2, *(unsigned int *)(a4 + 40), 2);
  v16 = *(_DWORD *)(a4 + 20);
  if ( !v16 )
    goto LABEL_90;
  v17 = *(_DWORD *)(a4 + 24);
  if ( v17 )
  {
    if ( (v17 & 1) != 0 )
      result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0);
    if ( v17 != 1 )
    {
      if ( (v17 & 2) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 1u);
      if ( v17 >= 4 )
      {
        if ( (v17 & 4) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 2u);
        if ( v17 >= 8 )
        {
          if ( (v17 & 8) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 3u);
          if ( v17 >= 0x10 )
          {
            if ( (v17 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 4u);
            if ( v17 >= 0x20 && (v17 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 5u);
          }
        }
      }
    }
    v16 = *(_DWORD *)(a4 + 20);
  }
  if ( v16 < 2 )
    goto LABEL_90;
  v18 = *(_DWORD *)(a4 + 28);
  if ( v18 )
  {
    if ( (v18 & 1) != 0 )
      result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x20u);
    if ( v18 != 1 )
    {
      if ( (v18 & 2) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x21u);
      if ( v18 >= 4 )
      {
        if ( (v18 & 4) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x22u);
        if ( v18 >= 8 )
        {
          if ( (v18 & 8) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x23u);
          if ( v18 >= 0x10 )
          {
            if ( (v18 & 0x10) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x24u);
            if ( v18 >= 0x20 && (v18 & 0x20) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x25u);
          }
        }
      }
    }
    v16 = *(_DWORD *)(a4 + 20);
  }
  if ( v16 <= 2 )
  {
LABEL_90:
    v19 = *(_DWORD *)(a4 + 8);
    if ( !v19 )
      goto LABEL_91;
    v20 = *(_DWORD *)(a4 + 12);
    if ( v20 )
    {
      if ( (v20 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0);
      if ( v20 != 1 )
      {
        if ( (v20 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 1u);
        if ( v20 >= 4 )
        {
          if ( (v20 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 2u);
          if ( v20 >= 8 )
          {
            if ( (v20 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 3u);
            if ( v20 >= 0x10 )
            {
              if ( (v20 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 4u);
              if ( v20 >= 0x20 && (v20 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 5u);
            }
          }
        }
      }
      v19 = *(_DWORD *)(a4 + 8);
    }
    if ( v19 < 2 )
      goto LABEL_91;
    v21 = *(_DWORD *)(a4 + 16);
    if ( v21 )
    {
      if ( (v21 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x20u);
      if ( v21 != 1 )
      {
        if ( (v21 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x21u);
        if ( v21 >= 4 )
        {
          if ( (v21 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x22u);
          if ( v21 >= 8 )
          {
            if ( (v21 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x23u);
            if ( v21 >= 0x10 )
            {
              if ( (v21 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x24u);
              if ( v21 >= 0x20 && (v21 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x25u);
            }
          }
        }
      }
      v19 = *(_DWORD *)(a4 + 8);
    }
    if ( v19 <= 2 )
      goto LABEL_91;
  }
  __break(0x5512u);
  return policy_mgr_update_dynamic_inactive_bitmap(result, v13, v14, v15);
}
