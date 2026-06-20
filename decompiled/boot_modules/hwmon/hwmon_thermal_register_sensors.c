__int64 __fastcall hwmon_thermal_register_sensors(_QWORD *a1)
{
  __int64 v1; // x22
  __int64 v2; // x25
  __int64 v3; // x8
  __int64 *v4; // x24
  __int64 v5; // x21
  _QWORD *v7; // x23
  int v8; // w20
  int v9; // w8
  unsigned int v10; // w26
  _DWORD *v11; // x8
  __int64 v12; // x0
  _QWORD *v13; // x27
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x28
  int v16; // w0
  _QWORD *v17; // x2

  v1 = a1[114];
  v2 = *(_QWORD *)(v1 + 8);
  v4 = (__int64 *)(v2 + 8);
  v3 = *(_QWORD *)(v2 + 8);
  if ( v3 )
  {
    v5 = a1[19];
    v7 = a1 + 115;
    v8 = 1;
    do
    {
      if ( *(_DWORD *)v3 == 1 )
      {
        v9 = **(_DWORD **)(v3 + 8);
        if ( v9 )
        {
          v10 = 0;
          do
          {
            if ( (v9 & 2) != 0 )
            {
              v11 = **(_DWORD ***)v1;
              if ( *(v11 - 1) != 575386056 )
                __break(0x8228u);
              if ( ((unsigned __int16 (__fastcall *)(__int64, __int64, __int64, _QWORD))v11)(v5, 1, 1, v10) )
              {
                v12 = devm_kmalloc(a1, 40, 3520);
                if ( !v12 )
                {
                  LODWORD(v15) = -12;
                  return (unsigned int)v15;
                }
                v13 = (_QWORD *)v12;
                *(_QWORD *)(v12 + 16) = a1;
                *(_DWORD *)(v12 + 24) = v10;
                v14 = devm_thermal_of_zone_register(a1, v10, v12, &hwmon_thermal_ops);
                v15 = v14;
                if ( v14 < 0xFFFFFFFFFFFFF001LL )
                {
                  v16 = _devm_add_action(a1, hwmon_thermal_remove_sensor, v13, "hwmon_thermal_remove_sensor");
                  if ( v16 )
                  {
                    LODWORD(v15) = v16;
                    return (unsigned int)v15;
                  }
                  v17 = (_QWORD *)*v7;
                  v13[4] = v15;
                  if ( (_QWORD *)v17[1] != v7 || v13 == v7 || v17 == v13 )
                  {
                    _list_add_valid_or_report(v13, v7);
                  }
                  else
                  {
                    v17[1] = v13;
                    *v13 = v17;
                    v13[1] = v7;
                    *v7 = v13;
                  }
                }
                else
                {
                  if ( v14 != -19 )
                    return (unsigned int)v15;
                  dev_info(a1, "temp%d_input not attached to any thermal zone\n", v10 + 1);
                  devm_kfree(a1, v13);
                }
              }
            }
            v9 = *(_DWORD *)(*(_QWORD *)(*v4 + 8) + 4LL * (int)++v10);
          }
          while ( v9 );
        }
      }
      v4 = (__int64 *)(v2 + 8LL * ++v8);
      v3 = *v4;
    }
    while ( *v4 );
  }
  LODWORD(v15) = 0;
  return (unsigned int)v15;
}
