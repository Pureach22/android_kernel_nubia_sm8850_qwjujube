__int64 rpmh_regulator_disable()
{
  __int64 drvdata; // x19
  int v1; // w8
  int v2; // w21
  unsigned int v3; // w20
  int v5; // w8

  drvdata = rdev_get_drvdata();
  mutex_lock(*(_QWORD *)(drvdata + 336) + 24LL);
  v1 = *(_DWORD *)(drvdata + 364);
  v2 = *(_DWORD *)(drvdata + 352);
  *(_DWORD *)(drvdata + 352) = 0;
  *(_DWORD *)(drvdata + 364) = v1 | 2;
  v3 = rpmh_regulator_send_aggregate_requests(drvdata);
  if ( v3 )
  {
    printk(&unk_987E, "rpmh_regulator_disable", *(_QWORD *)(drvdata + 8));
    v5 = *(_DWORD *)(drvdata + 364);
    *(_DWORD *)(drvdata + 352) = v2;
    *(_DWORD *)(drvdata + 364) = v5 | 2;
  }
  mutex_unlock(*(_QWORD *)(drvdata + 336) + 24LL);
  return v3;
}
