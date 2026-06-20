__int64 __fastcall qcom_remove_sysmon_subdev(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x8
  __int64 v3; // x0
  __int64 v4; // x9

  if ( result )
  {
    v1 = result;
    mutex_lock(&sysmon_lock);
    v2 = *(_QWORD **)(v1 + 120);
    v3 = v1 + 112;
    if ( *v2 == v1 + 112 && (v4 = *(_QWORD *)v3, *(_QWORD *)(*(_QWORD *)v3 + 8LL) == v3) )
    {
      *(_QWORD *)(v4 + 8) = v2;
      *v2 = v4;
    }
    else
    {
      _list_del_entry_valid_or_report();
    }
    *(_QWORD *)(v1 + 112) = 0xDEAD000000000100LL;
    *(_QWORD *)(v1 + 120) = 0xDEAD000000000122LL;
    mutex_unlock(&sysmon_lock);
    blocking_notifier_chain_unregister(&sysmon_notifiers, v1 + 200);
    rproc_remove_subdev(*(_QWORD *)(v1 + 48), v1);
    if ( *(_DWORD *)(v1 + 144) != -22 )
      qmi_handle_release(v1 + 432);
    return kfree(v1);
  }
  return result;
}
