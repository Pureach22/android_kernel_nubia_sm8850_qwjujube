__int64 __fastcall lt9611uxc_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x9
  __int64 v6; // x21
  _QWORD *v7; // x20
  bool v8; // cc
  _QWORD *v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x22

  v1 = *(_QWORD *)(result + 184);
  if ( !v1 )
    return result;
  v2 = result;
  mipi_dsi_detach(*(_QWORD *)(v1 + 312));
  mipi_dsi_device_unregister(*(_QWORD *)(v1 + 312));
  drm_bridge_remove(v1 + 8);
  sysfs_remove_group(v2 + 32, &lt9611uxc_sysfs_attr_grp);
  disable_irq(*(unsigned int *)(v1 + 3116));
  free_irq(*(unsigned int *)(v1 + 3116), v1);
  lt9611uxc_gpio_configure(v1, 0);
  v3 = *(_QWORD *)(v1 + 3152);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v1 + 3148);
    if ( v4 )
    {
      v5 = (unsigned int)(v4 - 1);
      if ( (int)v5 < 0 )
      {
LABEL_11:
        *(_QWORD *)(v1 + 3152) = 0;
        goto LABEL_12;
      }
      v6 = v5 + 1;
      v7 = (_QWORD *)(v3 + 72LL * (unsigned int)v5);
      do
      {
        if ( *v7 )
        {
          regulator_set_voltage(*v7, 0, *((unsigned int *)v7 + 11));
          regulator_put(*v7);
          *v7 = 0;
        }
        v8 = v6-- <= 1;
        v7 -= 9;
      }
      while ( !v8 );
      v3 = *(_QWORD *)(v1 + 3152);
    }
  }
  if ( v3 )
    goto LABEL_11;
LABEL_12:
  v9 = *(_QWORD **)(v1 + 3184);
  *(_DWORD *)(v1 + 3148) = 0;
  if ( v9 != (_QWORD *)(v1 + 3184) )
  {
    do
    {
      v11 = (_QWORD *)*v9;
      v10 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v10 == v9 && (_QWORD *)v11[1] == v9 )
      {
        v11[1] = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *v9 = 0xDEAD000000000100LL;
      v9[1] = 0xDEAD000000000122LL;
      kfree(v9 - 8);
      v9 = v11;
    }
    while ( v11 != (_QWORD *)(v1 + 3184) );
  }
  result = *(_QWORD *)(v1 + 3440);
  if ( result )
    return destroy_workqueue();
  return result;
}
