__int64 __fastcall policy_mgr_is_mcc_on_any_sta_vdev(__int64 a1)
{
  int mode_specific_conn_info; // w20
  __int64 result; // x0
  int v4; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int8 v5; // [xsp+4h] [xbp-Ch]
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v4 = 0;
  mode_specific_conn_info = (unsigned __int8)policy_mgr_get_mode_specific_conn_info(a1, 0, (unsigned __int64)&v4, 0);
  if ( !mode_specific_conn_info )
    goto LABEL_5;
  if ( (policy_mgr_is_mcc_with_this_vdev_id(a1, v4, nullptr) & 1) == 0 )
  {
    if ( mode_specific_conn_info != 1 )
    {
      if ( (policy_mgr_is_mcc_with_this_vdev_id(a1, BYTE1(v4), nullptr) & 1) != 0 )
        goto LABEL_3;
      if ( mode_specific_conn_info != 2 )
      {
        if ( (policy_mgr_is_mcc_with_this_vdev_id(a1, BYTE2(v4), nullptr) & 1) != 0 )
          goto LABEL_3;
        if ( mode_specific_conn_info != 3 )
        {
          if ( (policy_mgr_is_mcc_with_this_vdev_id(a1, HIBYTE(v4), nullptr) & 1) != 0 )
            goto LABEL_3;
          if ( mode_specific_conn_info != 4 )
          {
            if ( (policy_mgr_is_mcc_with_this_vdev_id(a1, v5, nullptr) & 1) != 0 )
              goto LABEL_3;
            if ( mode_specific_conn_info != 5 )
              __break(0x5512u);
          }
        }
      }
    }
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
LABEL_3:
  result = 1;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
