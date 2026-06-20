__int64 __fastcall cscfg_configfs_del_config(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 88);
  if ( result )
  {
    result = configfs_unregister_group();
    *(_QWORD *)(a1 + 88) = 0;
  }
  return result;
}
