__int64 __fastcall cm_trigger_panic_on_cmd_timeout(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v1 = *(_QWORD *)(result + 216);
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 80) )
    {
      v2 = result;
      result = qdf_is_recovering();
      if ( (result & 1) == 0 )
      {
        result = qdf_is_fw_down(v3, v4, v5, v6, v7, v8, v9, v10);
        if ( (result & 1) == 0 )
        {
          wlan_objmgr_vdev_get_comp_private_obj(v2, 0);
          return _qdf_trigger_self_recovery();
        }
      }
    }
  }
  return result;
}
