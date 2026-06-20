unsigned __int64 __fastcall bcl_probe_ibat(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x22
  unsigned __int64 v7; // x21
  __int64 v8; // x2
  const char *v9; // x1
  unsigned __int64 v10; // x0
  unsigned __int64 result; // x0
  int dest; // [xsp+4h] [xbp-1Ch]
  size_t n; // [xsp+8h] [xbp-18h]
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 760);
  dest = 0;
  n = 0;
  v14[0] = 0;
  if ( (unsigned int)of_property_read_string(v4, "nvmem-cell-names", v14) )
    goto LABEL_9;
  v5 = nvmem_cell_get(a1 + 16, v14[0]);
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    v8 = v14[0];
    v9 = "failed to get nvmem cell %s\n";
  }
  else
  {
    v6 = v5;
    v7 = nvmem_cell_read();
    nvmem_cell_put(v6);
    if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(a1 + 16, "nvmem cell length out of range %zu\n", n);
      kfree(v7);
      goto LABEL_9;
    }
    v8 = v14[0];
    v9 = "failed to read nvmem cell %s\n";
  }
  dev_err(a1 + 16, v9, v8);
LABEL_9:
  _mutex_init(a2 + 72, "&ibat->state_trans_lock", &bcl_ibat_init___key);
  *(_DWORD *)(a2 + 124) = 0;
  *(_QWORD *)(a2 + 224) = a2;
  *(_DWORD *)(a2 + 48) = 0;
  *(_BYTE *)(a2 + 120) = 0;
  *(_QWORD *)(a2 + 136) = bcl_read_ibat;
  *(_QWORD *)(a2 + 144) = bcl_set_ibat;
  v10 = devm_thermal_of_zone_register(a1 + 16, 0, a2 + 48, a2 + 128);
  *(_QWORD *)(a2 + 216) = v10;
  if ( v10 < 0xFFFFFFFFFFFFF001LL )
    thermal_zone_device_update();
  else
    *(_QWORD *)(a2 + 216) = 0;
  _mutex_init(a2 + 256, "&ibat->state_trans_lock", &bcl_ibat_init___key);
  *(_QWORD *)(a2 + 408) = a2;
  *(_DWORD *)(a2 + 308) = 1;
  *(_DWORD *)(a2 + 232) = 0;
  *(_BYTE *)(a2 + 304) = 0;
  *(_QWORD *)(a2 + 320) = bcl_read_ibat;
  *(_QWORD *)(a2 + 328) = bcl_set_ibat;
  result = devm_thermal_of_zone_register(a1 + 16, 1, a2 + 232, a2 + 312);
  *(_QWORD *)(a2 + 400) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
    result = thermal_zone_device_update();
  else
    *(_QWORD *)(a2 + 400) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
