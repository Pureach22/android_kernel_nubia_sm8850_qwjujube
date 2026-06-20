__int64 __fastcall sde_hw_dsc_init(int a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x22
  unsigned int v10; // w2
  int v11; // w9
  int v12; // w8
  __int64 v13; // x20
  __int64 result; // x0
  _DWORD *v15; // x19
  __int64 v16; // x19
  __int64 v17; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v19; // x23
  __int64 (__fastcall *v20)(_QWORD, _QWORD, _QWORD); // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v22; // [xsp+10h] [xbp-20h]
  __int64 v23; // [xsp+18h] [xbp-18h]
  __int64 v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, 144);
  if ( !v6 )
  {
LABEL_54:
    result = -12;
    goto LABEL_55;
  }
  while ( 1 )
  {
    v7 = a3[2598];
    if ( !v7 )
      goto LABEL_12;
    if ( a3[2604] == a1 )
    {
      v8 = 2600;
LABEL_5:
      v9 = (unsigned __int64)&a3[v8];
      goto LABEL_6;
    }
    if ( v7 == 1 )
      goto LABEL_12;
    if ( a3[2620] == a1 )
    {
      v8 = 2616;
      goto LABEL_5;
    }
    if ( v7 == 2 )
      goto LABEL_12;
    if ( a3[2636] == a1 )
    {
      v8 = 2632;
      goto LABEL_5;
    }
    if ( v7 == 3 )
      goto LABEL_12;
    if ( a3[2652] == a1 )
    {
      v8 = 2648;
      goto LABEL_5;
    }
    if ( v7 == 4 )
      goto LABEL_12;
    if ( a3[2668] == a1 )
    {
      v8 = 2664;
      goto LABEL_5;
    }
    if ( v7 == 5 )
      goto LABEL_12;
    if ( a3[2684] == a1 )
    {
      v8 = 2680;
      goto LABEL_5;
    }
    if ( v7 == 6 )
      goto LABEL_12;
    if ( a3[2700] == a1 )
    {
      v8 = 2696;
      goto LABEL_5;
    }
    if ( v7 == 7 )
      goto LABEL_12;
    if ( a3[2716] == a1 )
      break;
    if ( v7 == 8 )
      goto LABEL_12;
    if ( a3[2732] == a1 )
    {
      v17 = 2728;
      goto LABEL_39;
    }
    if ( v7 == 9 )
      goto LABEL_12;
    if ( a3[2748] == a1 )
    {
      v17 = 2744;
      goto LABEL_39;
    }
    if ( v7 == 10 )
      goto LABEL_12;
    if ( a3[2764] == a1 )
    {
      v17 = 2760;
      goto LABEL_39;
    }
    if ( v7 == 11 )
      goto LABEL_12;
    if ( a3[2780] == a1 )
    {
      v17 = 2776;
      goto LABEL_39;
    }
    if ( v7 == 12 )
      goto LABEL_12;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    v20 = _init_waitqueue_head;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_dsc_init__alloc_tag;
    v6 = _kmalloc_cache_noprof(v20, 3520, 144);
    *(_QWORD *)(StatusReg + 80) = v19;
    if ( !v6 )
      goto LABEL_54;
  }
  v17 = 2712;
LABEL_39:
  v9 = (unsigned __int64)&a3[v17];
LABEL_6:
  v10 = *(_DWORD *)(v9 + 20);
  v11 = *(_DWORD *)(v9 + 24);
  v12 = *a3;
  *(_QWORD *)v6 = a2;
  *(_DWORD *)(v6 + 8) = v10;
  *(_DWORD *)(v6 + 12) = v11;
  *(_DWORD *)(v6 + 20) = v12;
  *(_DWORD *)(v6 + 24) = 2048;
  if ( !v9 || v9 > 0xFFFFFFFFFFFFF000LL )
  {
LABEL_12:
    kfree(v6);
    result = -22;
    goto LABEL_55;
  }
  *(_DWORD *)(v6 + 32) = a1;
  *(_QWORD *)(v6 + 40) = v9;
  if ( (*(_QWORD *)(v9 + 32) & 4) == 0 )
  {
    if ( (*(_QWORD *)(v9 + 32) & 8) != 0 )
    {
      v13 = v6;
      v23 = 0;
      v24 = 0;
      *(_QWORD *)s = 0;
      v22 = 0;
      sde_dsc1_2_setup_ops(v6 + 48);
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        (const char *)v9,
        *(_DWORD *)(v13 + 8),
        *(_DWORD *)(v13 + 12) + *(_DWORD *)(v13 + 8),
        *(_DWORD *)(v13 + 16));
      snprintf(s, 0x20u, "dsc_enc_%u", *(_DWORD *)(v13 + 32) - 1);
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        s,
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 40) + 56LL) + 20LL) + *(_DWORD *)(v13 + 8),
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 40) + 56LL) + 20LL)
      + *(_DWORD *)(v13 + 8)
      + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 40) + 56LL) + 24LL),
        *(_DWORD *)(v13 + 16));
      snprintf(s, 0x20u, "dsc_ctl_%u", *(_DWORD *)(v13 + 32) - 1);
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        s,
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 40) + 56LL) + 48LL) + *(_DWORD *)(v13 + 8),
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 40) + 56LL) + 48LL)
      + *(_DWORD *)(v13 + 8)
      + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 40) + 56LL) + 52LL),
        *(_DWORD *)(v13 + 16));
      result = v13;
      goto LABEL_55;
    }
    v16 = v6;
    printk(&unk_243E34, "sde_hw_dsc_init");
    v6 = v16;
    goto LABEL_12;
  }
  *(_QWORD *)s = *(_QWORD *)(v9 + 32);
  *(_QWORD *)(v6 + 48) = sde_hw_dsc_disable;
  *(_QWORD *)(v6 + 72) = sde_hw_dsc_config;
  *(_QWORD *)(v6 + 96) = sde_hw_dsc_config_thresh;
  if ( (s[0] & 2) != 0 )
    *(_QWORD *)(v6 + 120) = sde_hw_dsc_bind_pingpong_blk;
  v15 = (_DWORD *)v6;
  sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v9, v10, v11 + v10, *(_DWORD *)(v6 + 16));
  result = (__int64)v15;
  if ( v15[8] == 1 && (*(_QWORD *)(v9 + 32) & 2) != 0 )
  {
    sde_dbg_reg_register_dump_range((__int64)"sde", "dsc_ctl", v15[2] + 6144, v15[2] + 6912, v15[4]);
    result = (__int64)v15;
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
