__int64 __fastcall rpmh_regulator_arc_set_voltage_sel(__int64 a1, int a2)
{
  __int64 drvdata; // x19
  int v4; // w8
  int v5; // w21
  unsigned int v6; // w20
  int v8; // w8

  drvdata = rdev_get_drvdata();
  mutex_lock(*(_QWORD *)(drvdata + 336) + 24LL);
  v4 = *(_DWORD *)(drvdata + 364);
  v5 = *(_DWORD *)(drvdata + 348);
  *(_DWORD *)(drvdata + 348) = a2;
  *(_DWORD *)(drvdata + 364) = v4 | 1;
  v6 = rpmh_regulator_send_aggregate_requests(drvdata);
  if ( v6 )
  {
    printk(&unk_8D9E, "rpmh_regulator_arc_set_voltage_sel", *(_QWORD *)(drvdata + 8));
    v8 = *(_DWORD *)(drvdata + 364);
    *(_DWORD *)(drvdata + 348) = v5;
    *(_DWORD *)(drvdata + 364) = v8 | 1;
  }
  mutex_unlock(*(_QWORD *)(drvdata + 336) + 24LL);
  return v6;
}
