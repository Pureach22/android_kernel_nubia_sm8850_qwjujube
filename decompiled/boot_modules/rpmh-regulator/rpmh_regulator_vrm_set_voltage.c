__int64 __fastcall rpmh_regulator_vrm_set_voltage(__int64 a1, int a2, int a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x19
  int v7; // w21
  int v8; // w8
  int v9; // w22
  int v10; // w9
  __int64 v11; // x8
  unsigned int v12; // w20
  int v14; // w8

  drvdata = rdev_get_drvdata();
  v6 = drvdata;
  v7 = (a2 + 999) / 1000;
  if ( 1000 * v7 > a3 )
  {
    printk(&unk_91BE, "rpmh_regulator_vrm_set_voltage", *(_QWORD *)(drvdata + 8));
    return (unsigned int)-22;
  }
  else
  {
    mutex_lock(*(_QWORD *)(drvdata + 336) + 24LL);
    v8 = *(_DWORD *)(v6 + 364);
    v9 = *(_DWORD *)(v6 + 348);
    *(_DWORD *)(v6 + 348) = v7;
    v10 = v8 | 1;
    v11 = *(_QWORD *)(v6 + 336);
    *(_DWORD *)(v6 + 364) = v10;
    if ( (*(_BYTE *)(v11 + 264) & 1) != 0 && *(_DWORD *)(v11 + 248) > (unsigned int)a3 )
      *(_BYTE *)(v11 + 213) = 1;
    v12 = rpmh_regulator_send_aggregate_requests(v6);
    if ( v12 )
    {
      printk(&unk_8D73, "rpmh_regulator_vrm_set_voltage", *(_QWORD *)(v6 + 8));
      v14 = *(_DWORD *)(v6 + 364);
      *(_DWORD *)(v6 + 348) = v9;
      *(_DWORD *)(v6 + 364) = v14 | 1;
    }
    mutex_unlock(*(_QWORD *)(v6 + 336) + 24LL);
  }
  return v12;
}
