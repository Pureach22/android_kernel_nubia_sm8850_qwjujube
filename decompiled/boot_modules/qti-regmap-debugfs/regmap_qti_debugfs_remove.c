__int64 __fastcall regmap_qti_debugfs_remove(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  _QWORD *v5; // x8
  __int64 v6; // x9

  v2 = debugfs_lookup("address", *(_QWORD *)(a1[2] + 280LL));
  dput();
  debugfs_remove(v2);
  v3 = debugfs_lookup("count", *(_QWORD *)(a1[2] + 280LL));
  dput();
  debugfs_remove(v3);
  v4 = debugfs_lookup("data", *(_QWORD *)(a1[2] + 280LL));
  dput();
  debugfs_remove(v4);
  v5 = (_QWORD *)a1[1];
  if ( (_QWORD *)*v5 == a1 && (v6 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
  {
    *(_QWORD *)(v6 + 8) = v5;
    *v5 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  return kfree(a1);
}
