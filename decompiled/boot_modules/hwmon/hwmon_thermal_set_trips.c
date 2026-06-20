__int64 hwmon_thermal_set_trips()
{
  __int64 v0; // x0
  _QWORD *v1; // x21
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x9
  __int64 *v3; // x22
  __int64 v4; // x10
  __int64 v5; // x23
  unsigned int v6; // w11
  __int64 v7; // x20
  __int64 v8; // x0
  unsigned int v9; // w8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  unsigned int v12; // w0

  v0 = thermal_zone_device_priv();
  v1 = *(_QWORD **)(*(_QWORD *)(v0 + 16) + 912LL);
  v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*v1 + 24LL);
  if ( !v2 )
    return 0;
  v3 = (__int64 *)v1[1];
  v4 = *v3;
  if ( !*v3 )
    return 0;
  if ( *(_DWORD *)v4 != 1 )
  {
    v6 = 1;
    while ( 1 )
    {
      v4 = v3[v6];
      if ( !v4 )
        return 0;
      v5 = v6++;
      if ( *(_DWORD *)v4 == 1 )
        goto LABEL_8;
    }
  }
  v5 = 0;
LABEL_8:
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 8) + 4LL * *(int *)(v0 + 24)) & 0x20) == 0 )
    goto LABEL_22;
  v7 = v0;
  v8 = *(_QWORD *)(v0 + 16);
  if ( *((_DWORD *)v2 - 1) != -1027269393 )
    __break(0x8229u);
  v9 = v2(v8, 1, 5);
  v0 = v7;
  if ( !v9 || v9 == -95 )
  {
LABEL_22:
    if ( (*(_DWORD *)(*(_QWORD *)(v3[v5] + 8) + 4LL * *(int *)(v0 + 24)) & 0x80) == 0 )
      return 0;
    v10 = *(_QWORD *)(v0 + 16);
    v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*v1 + 24LL);
    if ( *((_DWORD *)v11 - 1) != -1027269393 )
      __break(0x8228u);
    v12 = v11(v10, 1, 7);
    if ( !v12 )
      return 0;
    v9 = v12;
    if ( v12 == -95 )
      return 0;
  }
  return v9;
}
