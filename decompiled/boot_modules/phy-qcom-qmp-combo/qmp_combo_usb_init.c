__int64 __fastcall qmp_combo_usb_init(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w20
  __int64 v5; // x23
  int v6; // w8
  unsigned int v7; // w21
  __int64 v8; // x22

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 208);
  if ( *(_DWORD *)(v1 + 276) == 4 )
  {
    v3 = 0;
  }
  else
  {
    v3 = qmp_combo_com_init((_QWORD *)v1, 0);
    if ( !v3 )
    {
      v3 = qmp_combo_usb_power_on(a1);
      if ( v3 )
      {
        v5 = *(_QWORD *)(v1 + 8);
        v6 = *(_DWORD *)(v1 + 256) - 1;
        *(_DWORD *)(v1 + 256) = v6;
        if ( !v6 )
        {
          v7 = *(_DWORD *)(v1 + 168);
          v8 = *(_QWORD *)(v1 + 160);
          clk_bulk_disable(v7, v8);
          clk_bulk_unprepare(v7, v8);
          regulator_bulk_disable(*(unsigned int *)(v5 + 272), *(_QWORD *)(v1 + 200));
        }
      }
      else
      {
        ++*(_DWORD *)(v1 + 280);
      }
    }
  }
  mutex_unlock(v1 + 208);
  return v3;
}
