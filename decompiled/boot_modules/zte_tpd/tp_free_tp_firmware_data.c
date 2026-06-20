__int64 tp_free_tp_firmware_data()
{
  __int64 v0; // x19
  __int64 result; // x0

  v0 = tpd_cdev;
  result = *(_QWORD *)(tpd_cdev + 2720);
  if ( result )
  {
    if ( *(_QWORD *)(result + 8) )
    {
      vfree(*(_QWORD *)(result + 8));
      *(_QWORD *)(*(_QWORD *)(v0 + 2720) + 8LL) = 0;
      **(_QWORD **)(v0 + 2720) = 0;
      result = *(_QWORD *)(v0 + 2720);
    }
    result = kfree(result);
    *(_QWORD *)(v0 + 2720) = 0;
  }
  *(_DWORD *)(v0 + 1096) = 0;
  return result;
}
