__int64 __fastcall qmi_rmnet_qos_exit_pre(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 *v3; // x21
  void *v4; // x2

  if ( result )
  {
    v1 = result;
    v2 = result + 56;
    v3 = *(__int64 **)(result + 56);
    if ( v3 != (__int64 *)(result + 56) )
    {
      do
      {
        *((_BYTE *)v3 + 121) = 1;
        timer_delete_sync(v3 + 10);
        *((_BYTE *)v3 + 148) = 1;
        result = timer_delete_sync(v3 + 19);
        v3 = (__int64 *)*v3;
      }
      while ( v3 != (__int64 *)v2 );
    }
    v4 = qos_cleanup_list;
    if ( *((_UNKNOWN ***)qos_cleanup_list + 1) != &qos_cleanup_list
      || (_UNKNOWN **)v1 == &qos_cleanup_list
      || qos_cleanup_list == (_UNKNOWN *)v1 )
    {
      return _list_add_valid_or_report(v1, &qos_cleanup_list, qos_cleanup_list);
    }
    else
    {
      *((_QWORD *)qos_cleanup_list + 1) = v1;
      *(_QWORD *)v1 = v4;
      *(_QWORD *)(v1 + 8) = &qos_cleanup_list;
      qos_cleanup_list = (_UNKNOWN *)v1;
    }
  }
  return result;
}
