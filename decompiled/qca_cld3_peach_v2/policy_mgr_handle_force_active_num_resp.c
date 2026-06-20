__int64 __fastcall policy_mgr_handle_force_active_num_resp(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  unsigned int v22; // w21
  unsigned int v23; // w21
  unsigned int v24; // w23
  unsigned int v25; // w22
  unsigned int v26; // w22
  unsigned int v27; // w20
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned __int8 *)(a4 + 32);
  v28[0] = 0;
  if ( v8 == 1 )
  {
    ml_nlink_set_curr_force_active_num_state(a1, a2, *(unsigned __int8 *)(a3 + 118), *(unsigned __int16 *)(a3 + 114));
    policy_mgr_update_dynamic_inactive_bitmap(a1, a2, a3, a4);
    result = policy_mgr_handle_vdev_active_inactive_resp(a1, a2, a3, a4);
    goto LABEL_120;
  }
  ml_nlink_convert_vdev_bitmap_to_linkid_bitmap(a1, a2, *(unsigned int *)(a3 + 44), a3 + 84, v28, (char *)v28 + 4);
  result = ml_nlink_set_curr_force_active_num_state(a1, a2, *(unsigned int *)(a3 + 52), LODWORD(v28[0]));
  if ( (*(_BYTE *)(a3 + 102) & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: Enable ML vdev(s) as sent in req",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "policy_mgr_handle_force_active_num_resp");
    v21 = *(_DWORD *)(a3 + 44);
    if ( !v21 )
      goto LABEL_120;
    v22 = *(_DWORD *)(a3 + 84);
    if ( v22 )
    {
      if ( (v22 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0);
      if ( v22 != 1 )
      {
        if ( (v22 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 1u);
        if ( v22 >= 4 )
        {
          if ( (v22 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 2u);
          if ( v22 >= 8 )
          {
            if ( (v22 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 3u);
            if ( v22 >= 0x10 )
            {
              if ( (v22 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 4u);
              if ( v22 >= 0x20 && (v22 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 5u);
            }
          }
        }
      }
      v21 = *(_DWORD *)(a3 + 44);
    }
    if ( v21 < 2 )
      goto LABEL_120;
    v23 = *(_DWORD *)(a3 + 88);
    if ( v23 )
    {
      if ( (v23 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x20u);
      if ( v23 != 1 )
      {
        if ( (v23 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x21u);
        if ( v23 >= 4 )
        {
          if ( (v23 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x22u);
          if ( v23 >= 8 )
          {
            if ( (v23 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x23u);
            if ( v23 >= 0x10 )
            {
              if ( (v23 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x24u);
              if ( v23 >= 0x20 && (v23 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x25u);
            }
          }
        }
      }
      v21 = *(_DWORD *)(a3 + 44);
    }
  }
  else
  {
    if ( !*(_DWORD *)(a4 + 8) )
      goto LABEL_120;
    v24 = *(_DWORD *)(a4 + 12);
    v25 = *(_DWORD *)(a3 + 84) ^ v24;
    if ( v24 )
    {
      if ( (v24 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0);
      if ( v24 != 1 )
      {
        if ( (v24 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 1u);
        if ( v24 >= 4 )
        {
          if ( (v24 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 2u);
          if ( v24 >= 8 )
          {
            if ( (v24 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 3u);
            if ( v24 >= 0x10 )
            {
              if ( (v24 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 4u);
              if ( v24 >= 0x20 && (v24 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 5u);
            }
          }
        }
      }
    }
    if ( v25 )
    {
      if ( (v25 & 1) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0);
      if ( v25 != 1 )
      {
        if ( (v25 & 2) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 1u);
        if ( v25 >= 4 )
        {
          if ( (v25 & 4) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 2u);
          if ( v25 >= 8 )
          {
            if ( (v25 & 8) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 3u);
            if ( v25 >= 0x10 )
            {
              if ( (v25 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 4u);
              if ( v25 >= 0x20 && (v25 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 5u);
            }
          }
        }
      }
    }
    if ( *(_DWORD *)(a4 + 8) < 2u )
      goto LABEL_120;
    v26 = *(_DWORD *)(a4 + 16);
    v27 = *(_DWORD *)(a3 + 88) ^ v26;
    if ( v26 )
    {
      if ( (v26 & 1) != 0 )
        result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x20u);
      if ( v26 != 1 )
      {
        if ( (v26 & 2) != 0 )
          result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x21u);
        if ( v26 >= 4 )
        {
          if ( (v26 & 4) != 0 )
            result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x22u);
          if ( v26 >= 8 )
          {
            if ( (v26 & 8) != 0 )
              result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x23u);
            if ( v26 >= 0x10 )
            {
              if ( (v26 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x24u);
              if ( v26 >= 0x20 && (v26 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, 0x25u);
            }
          }
        }
      }
    }
    if ( v27 )
    {
      if ( (v27 & 1) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x20u);
      if ( v27 != 1 )
      {
        if ( (v27 & 2) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x21u);
        if ( v27 >= 4 )
        {
          if ( (v27 & 4) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x22u);
          if ( v27 >= 8 )
          {
            if ( (v27 & 8) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x23u);
            if ( v27 >= 0x10 )
            {
              if ( (v27 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x24u);
              if ( v27 >= 0x20 && (v27 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x25u);
            }
          }
        }
      }
    }
    v21 = *(_DWORD *)(a4 + 8);
  }
  if ( v21 <= 2 )
  {
LABEL_120:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return policy_mgr_handle_force_inactive_num_resp(result, v10, v11, v12);
}
