__int64 __fastcall bt_power_remove(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x19

  v1 = *(_QWORD *)(a1 + 168);
  probe_finished = 0;
  if ( v1 )
    rfkill_unregister(v1);
  rfkill_destroy(v1);
  *(_QWORD *)(a1 + 168) = 0;
  v3 = pwr_data;
  v4 = *(unsigned int *)(pwr_data + 136);
  if ( (int)v4 >= 1 )
  {
    v5 = 0;
    v6 = 48 * v4;
    do
    {
      if ( *(_QWORD *)(*(_QWORD *)(v3 + 56) + v5) )
      {
        regulator_put(*(_QWORD *)(*(_QWORD *)(v3 + 56) + v5));
        v3 = pwr_data;
      }
      v5 += 48;
    }
    while ( v6 != v5 );
  }
  if ( *(_BYTE *)(v3 + 176) == 1 )
  {
    destroy_workqueue(*(_QWORD *)(v3 + 296));
    v3 = pwr_data;
  }
  return kfree(v3);
}
