__int64 __fastcall dsi_phy_driver_remove(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  __int64 v5; // x11
  _QWORD *v6; // x10
  __int64 result; // x0
  int v8; // w3

  v1 = *(_QWORD *)(a1 + 168);
  if ( a1 && v1 )
  {
    mutex_lock(&dsi_phy_list_lock);
    v3 = dsi_phy_list;
    while ( v3 != &dsi_phy_list )
    {
      v4 = v3;
      v5 = *(v3 - 1);
      v3 = (_QWORD *)*v3;
      if ( v5 == v1 )
      {
        v6 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v6 == v4 && (_QWORD *)v3[1] == v4 )
        {
          v3[1] = v6;
          *v6 = v3;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        devm_kfree(a1 + 16);
        break;
      }
    }
    mutex_unlock(&dsi_phy_list_lock);
    mutex_lock(v1 + 32);
    dsi_phy_settings_deinit(v1);
    dsi_phy_supplies_deinit(v1);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: unmap registers\n", *(_DWORD *)(v1 + 8));
    mutex_unlock(v1 + 32);
    result = devm_kfree(a1 + 16);
    *(_QWORD *)(a1 + 168) = 0;
  }
  else
  {
    if ( v1 )
      v8 = *(_DWORD *)(v1 + 8);
    else
      v8 = -1;
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Invalid device\n", v8);
  }
  return result;
}
