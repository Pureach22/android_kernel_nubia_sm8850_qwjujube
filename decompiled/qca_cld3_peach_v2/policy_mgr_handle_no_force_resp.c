__int64 __fastcall policy_mgr_handle_no_force_resp(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  __int64 v6; // x21
  int v8; // w8
  __int64 v9; // x2
  __int64 result; // x0
  unsigned int v11; // w8
  unsigned int v12; // w21
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v6 = a2;
  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int8 *)(a4 + 32);
  v13[0] = 0;
  if ( v8 == 1 )
  {
    v9 = *(unsigned __int16 *)(a3 + 114);
    v4 = a4;
    if ( *(_WORD *)(a3 + 114) )
    {
      ml_nlink_set_curr_force_inactive_state(a1, a2, v9, 1);
      ml_nlink_set_curr_force_active_state(a1, v6, *(unsigned __int16 *)(a3 + 114), 1);
LABEL_47:
      policy_mgr_update_dynamic_inactive_bitmap(a1, v6, a3, v4);
      result = policy_mgr_handle_vdev_active_inactive_resp(a1, v6, a3, v4);
      goto LABEL_48;
    }
LABEL_46:
    ml_nlink_clr_force_state(a1, v6);
    goto LABEL_47;
  }
  ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, *(unsigned int *)(a3 + 44), a3 + 84, v13, (char *)v13 + 4);
  ml_nlink_set_curr_force_inactive_state(a1, v6, LODWORD(v13[0]), 1);
  ml_nlink_set_curr_force_active_state(a1, v6, LODWORD(v13[0]), 1);
  ml_nlink_set_curr_force_active_num_state(a1, v6, 0, 0);
  result = ml_nlink_set_curr_force_inactive_num_state(a1, v6, 0, 0);
  v11 = *(_DWORD *)(a3 + 44);
  if ( v11 )
  {
    v12 = *(_DWORD *)(a3 + 84);
    if ( v12 )
    {
      if ( (v12 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0);
      if ( v12 != 1 )
      {
        if ( (v12 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 1u);
        if ( v12 >= 4 )
        {
          if ( (v12 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 2u);
          if ( v12 >= 8 )
          {
            if ( (v12 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 3u);
            if ( v12 >= 0x10 )
            {
              if ( (v12 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 4u);
              if ( v12 >= 0x20 && (v12 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 5u);
            }
          }
        }
      }
      v11 = *(_DWORD *)(a3 + 44);
    }
    if ( v11 >= 2 )
    {
      v6 = *(unsigned int *)(a3 + 88);
      if ( (_DWORD)v6 )
      {
        if ( (v6 & 1) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x20u);
        if ( (_DWORD)v6 != 1 )
        {
          if ( (v6 & 2) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x21u);
          if ( (unsigned int)v6 >= 4 )
          {
            if ( (v6 & 4) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x22u);
            if ( (unsigned int)v6 >= 8 )
            {
              if ( (v6 & 8) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x23u);
              if ( (unsigned int)v6 >= 0x10 )
              {
                if ( (v6 & 0x10) != 0 )
                  result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x24u);
                if ( (unsigned int)v6 >= 0x20 && (v6 & 0x20) != 0 )
                  result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x25u);
              }
            }
          }
        }
        v11 = *(_DWORD *)(a3 + 44);
      }
      if ( v11 > 2 )
      {
        __break(0x5512u);
        goto LABEL_46;
      }
    }
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
