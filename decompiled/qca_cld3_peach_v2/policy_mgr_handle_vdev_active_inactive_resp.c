__int64 __fastcall policy_mgr_handle_vdev_active_inactive_resp(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  int v8; // w23
  int v9; // w22
  __int64 result; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  unsigned int v18; // w8
  unsigned int v19; // w21
  unsigned int v20; // w21
  unsigned int v21; // w8
  unsigned int v22; // w21
  unsigned int v23; // w21
  __int16 v24; // [xsp+4h] [xbp-1Ch] BYREF
  _WORD v25[2]; // [xsp+8h] [xbp-18h] BYREF
  int v26; // [xsp+Ch] [xbp-14h] BYREF
  char v27; // [xsp+10h] [xbp-10h]
  __int16 v28; // [xsp+14h] [xbp-Ch]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a4[11];
  v27 = 0;
  v28 = 0;
  v26 = 0;
  v25[0] = 0;
  v24 = 0;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 && (unsigned int)(*(_DWORD *)(a3 + 32) - 5) <= 1 )
    v8 = a4[12];
  ml_nlink_get_dynamic_inactive_links(a1, a2, v25, &v24);
  v9 = v25[0] | (unsigned __int16)v8;
  ml_nlink_convert_linkid_bitmap_to_vdev_bitmap(a1, a2, v9, (int)&v26, (_DWORD)a4 + 20, (_DWORD)a4 + 24);
  result = ml_nlink_convert_linkid_bitmap_to_vdev_bitmap(a1, a2, v26 & (unsigned int)~v9, 0, (int)a4 + 8, (int)a4 + 12);
  v18 = a4[5];
  if ( v18 )
  {
    v19 = a4[6];
    if ( v19 )
    {
      if ( (v19 & 1) != 0 )
        result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0);
      if ( v19 != 1 )
      {
        if ( (v19 & 2) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 1u);
        if ( v19 >= 4 )
        {
          if ( (v19 & 4) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 2u);
          if ( v19 >= 8 )
          {
            if ( (v19 & 8) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 3u);
            if ( v19 >= 0x10 )
            {
              if ( (v19 & 0x10) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 4u);
              if ( v19 >= 0x20 && (v19 & 0x20) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 5u);
            }
          }
        }
      }
      v18 = a4[5];
    }
    if ( v18 >= 2 )
    {
      v20 = a4[7];
      if ( v20 )
      {
        if ( (v20 & 1) != 0 )
          result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x20u);
        if ( v20 != 1 )
        {
          if ( (v20 & 2) != 0 )
            result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x21u);
          if ( v20 >= 4 )
          {
            if ( (v20 & 4) != 0 )
              result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x22u);
            if ( v20 >= 8 )
            {
              if ( (v20 & 8) != 0 )
                result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x23u);
              if ( v20 >= 0x10 )
              {
                if ( (v20 & 0x10) != 0 )
                  result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x24u);
                if ( v20 >= 0x20 && (v20 & 0x20) != 0 )
                  result = policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, 0x25u);
              }
            }
          }
        }
        v18 = a4[5];
      }
      if ( v18 > 2 )
        goto LABEL_87;
    }
  }
  v21 = a4[2];
  if ( !v21 )
    goto LABEL_86;
  v22 = a4[3];
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
    v21 = a4[2];
  }
  if ( v21 < 2 )
    goto LABEL_86;
  v23 = a4[4];
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
    v21 = a4[2];
  }
  if ( v21 > 2 )
  {
LABEL_87:
    __break(0x5512u);
    return policy_mgr_get_ml_sta_and_p2p_cli_go_sap_info(result, v11, v12, v13, v14, v15, v16, v17);
  }
  else
  {
LABEL_86:
    _ReadStatusReg(SP_EL0);
  }
  return result;
}
