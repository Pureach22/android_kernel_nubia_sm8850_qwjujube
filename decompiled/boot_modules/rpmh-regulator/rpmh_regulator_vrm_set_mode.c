__int64 __fastcall rpmh_regulator_vrm_set_mode(__int64 a1, int a2)
{
  __int64 drvdata; // x0
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v6; // x9
  int v7; // w21
  __int64 v8; // x22
  __int64 v9; // x9
  unsigned int v10; // w20
  int v11; // w8
  int v12; // w22
  int v14; // w8

  drvdata = rdev_get_drvdata();
  v4 = *(_QWORD *)(drvdata + 336);
  v5 = drvdata;
  v6 = *(unsigned int *)(v4 + 240);
  if ( (int)v6 < 1 )
  {
LABEL_5:
    printk(&unk_9757, "rpmh_regulator_vrm_set_mode", *(_QWORD *)(drvdata + 8));
    return (unsigned int)-22;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    v9 = 12 * v6;
    while ( *(_DWORD *)(*(_QWORD *)(v4 + 232) + 4LL + v8) != a2 )
    {
      v8 += 12;
      ++v7;
      if ( v9 == v8 )
        goto LABEL_5;
    }
    mutex_lock(v4 + 24);
    v11 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 336) + 232LL) + v8);
    v12 = *(_DWORD *)(v5 + 356);
    *(_DWORD *)(v5 + 364) |= 4u;
    *(_DWORD *)(v5 + 356) = v11;
    v10 = rpmh_regulator_send_aggregate_requests(v5);
    if ( v10 )
    {
      printk(&unk_908D, "rpmh_regulator_vrm_set_mode_index", *(_QWORD *)(v5 + 8));
      v14 = *(_DWORD *)(v5 + 364);
      *(_DWORD *)(v5 + 356) = v12;
      *(_DWORD *)(v5 + 364) = v14 | 4;
    }
    else
    {
      *(_DWORD *)(v5 + 368) = v7;
    }
    mutex_unlock(*(_QWORD *)(v5 + 336) + 24LL);
  }
  return v10;
}
