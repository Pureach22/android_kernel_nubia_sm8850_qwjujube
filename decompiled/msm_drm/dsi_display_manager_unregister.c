double __fastcall dsi_display_manager_unregister(_QWORD *a1)
{
  double result; // d0
  _QWORD *v3; // x8
  _QWORD *v4; // x0
  __int64 v5; // x9

  if ( (*(_BYTE *)(a1[33] + 2212LL) & 1) == 0 )
    return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: no need of a mgr\n");
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: cell_index = %d\n", *(_DWORD *)(a1[21] + 8LL));
  v3 = (_QWORD *)a1[7];
  v4 = a1 + 6;
  if ( (_QWORD *)*v3 == a1 + 6 && (v5 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
  {
    *(_QWORD *)(v5 + 8) = v3;
    *v3 = v5;
  }
  else
  {
    _list_del_entry_valid_or_report(v4);
  }
  a1[6] = 0xDEAD000000000100LL;
  a1[7] = 0xDEAD000000000122LL;
  return result;
}
