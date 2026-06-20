__int64 __fastcall dsi_ctrl_dev_remove(__int64 a1)
{
  __int64 v2; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  __int64 v5; // x11
  _QWORD *v6; // x10
  __int64 v7; // x1
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 168);
  mutex_lock(&dsi_ctrl_list_lock);
  v3 = dsi_ctrl_list;
  while ( v3 != &dsi_ctrl_list )
  {
    v4 = v3;
    v5 = *(v3 - 1);
    v3 = (_QWORD *)*v3;
    if ( v5 == v2 )
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
      break;
    }
  }
  mutex_unlock(&dsi_ctrl_list_lock);
  mutex_lock(v2 + 32);
  if ( v2 )
  {
    mutex_lock(v2 + 32);
    if ( *(_QWORD *)v2 )
    {
      v7 = *(unsigned int *)(v2 + 1660);
      if ( (v7 & 0x80000000) == 0 )
      {
        devm_free_irq(*(_QWORD *)v2 + 16LL, v7, v2);
        *(_DWORD *)(v2 + 1660) = -1;
      }
    }
    mutex_unlock(v2 + 32);
  }
  dsi_ctrl_supplies_deinit(v2);
  dsi_ctrl_clocks_deinit(v2);
  *(_DWORD *)(v2 + 2852) = 0;
  mutex_unlock(v2 + 32);
  result = devm_kfree(a1 + 16);
  *(_QWORD *)(a1 + 168) = 0;
  return result;
}
