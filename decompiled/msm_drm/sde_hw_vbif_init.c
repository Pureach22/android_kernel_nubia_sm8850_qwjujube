__int64 __fastcall sde_hw_vbif_init(int a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x8
  int v10; // w9
  int v11; // w10
  int v12; // w11
  __int64 v13; // x9
  __int64 (__fastcall *v14)(); // x8
  __int64 v15; // x19
  __int64 v17; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v19; // x23
  __int64 (__fastcall *v20)(_QWORD); // x0

  v6 = _kmalloc_cache_noprof(msleep, 3520, 336);
  if ( !v6 )
    return -12;
  while ( 1 )
  {
    v7 = a3[3834];
    if ( !v7 )
      goto LABEL_15;
    if ( a3[3840] == a1 )
    {
      v8 = 3836;
LABEL_5:
      v9 = (unsigned __int64)&a3[v8];
      goto LABEL_6;
    }
    if ( v7 == 1 )
      goto LABEL_15;
    if ( a3[3910] == a1 )
    {
      v8 = 3906;
      goto LABEL_5;
    }
    if ( v7 == 2 )
      goto LABEL_15;
    if ( a3[3980] == a1 )
    {
      v8 = 3976;
      goto LABEL_5;
    }
    if ( v7 == 3 )
      goto LABEL_15;
    if ( a3[4050] == a1 )
    {
      v8 = 4046;
      goto LABEL_5;
    }
    if ( v7 == 4 )
      goto LABEL_15;
    if ( a3[4120] == a1 )
    {
      v8 = 4116;
      goto LABEL_5;
    }
    if ( v7 == 5 )
      goto LABEL_15;
    if ( a3[4190] == a1 )
    {
      v8 = 4186;
      goto LABEL_5;
    }
    if ( v7 == 6 )
      goto LABEL_15;
    if ( a3[4260] == a1 )
    {
      v8 = 4256;
      goto LABEL_5;
    }
    if ( v7 == 7 )
      goto LABEL_15;
    if ( a3[4330] == a1 )
      break;
    if ( v7 == 8 )
      goto LABEL_15;
    if ( a3[4400] == a1 )
    {
      v17 = 4396;
      goto LABEL_36;
    }
    if ( v7 == 9 )
      goto LABEL_15;
    if ( a3[4470] == a1 )
    {
      v17 = 4466;
      goto LABEL_36;
    }
    if ( v7 == 10 )
      goto LABEL_15;
    if ( a3[4540] == a1 )
    {
      v17 = 4536;
      goto LABEL_36;
    }
    if ( v7 == 11 )
      goto LABEL_15;
    if ( a3[4610] == a1 )
    {
      v17 = 4606;
      goto LABEL_36;
    }
    if ( v7 == 12 )
      goto LABEL_15;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    v20 = msleep;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_vbif_init__alloc_tag;
    v6 = _kmalloc_cache_noprof(v20, 3520, 336);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v6 )
      return -12;
  }
  v17 = 4326;
LABEL_36:
  v9 = (unsigned __int64)&a3[v17];
LABEL_6:
  v10 = *(_DWORD *)(v9 + 20);
  v11 = *(_DWORD *)(v9 + 24);
  v12 = *a3;
  *(_QWORD *)v6 = a2;
  *(_DWORD *)(v6 + 8) = v10;
  *(_DWORD *)(v6 + 12) = v11;
  *(_DWORD *)(v6 + 20) = v12;
  *(_DWORD *)(v6 + 24) = 1024;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_15:
    kfree(v6);
    return -22;
  }
  v13 = *(_QWORD *)(v9 + 32);
  *(_DWORD *)(v6 + 32) = a1;
  *(_QWORD *)(v6 + 40) = v9;
  *(_QWORD *)(v6 + 48) = sde_hw_set_limit_conf;
  *(_QWORD *)(v6 + 72) = sde_hw_get_limit_conf;
  *(_QWORD *)(v6 + 144) = sde_hw_set_axi_halt;
  *(_QWORD *)(v6 + 168) = sde_hw_get_axi_halt_status;
  *(_QWORD *)(v6 + 96) = sde_hw_set_xin_halt;
  *(_QWORD *)(v6 + 120) = sde_hw_get_xin_halt_status;
  if ( (v13 & 4) != 0 )
    *(_QWORD *)(v6 + 192) = sde_hw_set_qos_remap;
  if ( (v13 & 8) != 0 )
    v14 = sde_hw_set_mem_type_v1;
  else
    v14 = sde_hw_set_mem_type;
  *(_QWORD *)(v6 + 240) = sde_hw_clear_errors;
  *(_QWORD *)(v6 + 216) = v14;
  *(_QWORD *)(v6 + 264) = sde_hw_set_write_gather_en;
  v15 = v6;
  _mutex_init(v6 + 288, "&c->mutex", &sde_hw_vbif_init___key);
  return v15;
}
