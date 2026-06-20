__int64 cleanup_module()
{
  __int64 result; // x0

  result = qh;
  if ( qh )
  {
    if ( !*(_QWORD *)(qh + 8)
      || (_qptm_destroy_hierarchy(*(_QWORD *)(qh + 24)),
          powercap_unregister_control_type(*(_QWORD *)(qh + 8)),
          result = qh,
          *(_QWORD *)(qh + 8) = 0,
          *(_QWORD *)(result + 24) = 0,
          result) )
    {
      if ( *(_QWORD *)(result + 16) )
      {
        kfree(*(_QWORD *)(result + 16));
        result = qh;
      }
    }
    result = kfree(result);
    qh = 0;
  }
  return result;
}
