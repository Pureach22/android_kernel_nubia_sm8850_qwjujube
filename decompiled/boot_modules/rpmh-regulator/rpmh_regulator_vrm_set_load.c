__int64 __fastcall rpmh_regulator_vrm_set_load(__int64 a1, int a2)
{
  __int64 drvdata; // x0
  __int64 v4; // x8
  __int64 v5; // x19
  int v6; // w9
  int v7; // w21
  int v8; // w22
  int v9; // w8
  unsigned int v10; // w20
  int v12; // w8

  drvdata = rdev_get_drvdata();
  v4 = *(_QWORD *)(drvdata + 336);
  v5 = drvdata;
  v6 = *(_DWORD *)(v4 + 240);
  v7 = (v6 - 1) & ((v6 - 1) >> 31);
  while ( --v6 >= 1 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v4 + 232) + 12LL * (v6 & 0x7FFFFFFF) + 8) <= a2 )
    {
      v7 = v6;
      break;
    }
  }
  mutex_lock(v4 + 24);
  v8 = *(_DWORD *)(v5 + 356);
  v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 336) + 232LL) + 12LL * v7);
  *(_DWORD *)(v5 + 364) |= 4u;
  *(_DWORD *)(v5 + 356) = v9;
  v10 = rpmh_regulator_send_aggregate_requests(v5);
  if ( v10 )
  {
    printk(&unk_908D, "rpmh_regulator_vrm_set_mode_index", *(_QWORD *)(v5 + 8));
    v12 = *(_DWORD *)(v5 + 364);
    *(_DWORD *)(v5 + 356) = v8;
    *(_DWORD *)(v5 + 364) = v12 | 4;
  }
  else
  {
    *(_DWORD *)(v5 + 368) = v7;
  }
  mutex_unlock(*(_QWORD *)(v5 + 336) + 24LL);
  return v10;
}
