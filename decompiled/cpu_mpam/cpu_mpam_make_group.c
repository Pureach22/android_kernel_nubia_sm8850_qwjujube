__int64 __fastcall cpu_mpam_make_group(__int64 a1, __int64 a2)
{
  int next_zero_area_off; // w21
  __int64 v4; // x20
  __int64 v5; // x0
  int v6; // w12
  __int64 v7; // x11
  _QWORD *v8; // x10
  int v9; // w12
  __int64 v10; // x11
  __int64 v11; // x10
  int v12; // w12
  __int64 v13; // x11
  __int64 v14; // x10
  int v15; // w8
  __int64 v16; // x11
  __int64 v17; // x10
  void *v18; // x2
  unsigned __int64 StatusReg; // x23
  __int64 v21; // x24
  __int64 (__fastcall *v22)(_QWORD, _QWORD); // x0

  next_zero_area_off = bitmap_find_next_zero_area_off(part_id_free_bitmap, 48, 0, 1, 0, 0);
  if ( next_zero_area_off > 48 )
    return -12;
  v4 = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 152);
  if ( !v4 )
    return -12;
  while ( 1 )
  {
    *(_QWORD *)(part_id_free_bitmap + 8LL * ((unsigned int)next_zero_area_off >> 6)) |= 1LL << next_zero_area_off;
    *(_DWORD *)(v4 + 136) = next_zero_area_off;
    *(_DWORD *)(v4 + 140) = 0x7FFFFFFF;
    if ( mpam_msc_cnt < 0 )
    {
      *(_QWORD *)(v4 + 144) = 0;
      return -12;
    }
    v5 = _kmalloc_noprof(16LL * (unsigned int)mpam_msc_cnt, 3520);
    *(_QWORD *)(v4 + 144) = v5;
    if ( !v5 )
      return -12;
    if ( mpam_msc_cnt < 1 )
      break;
    v6 = mpam_msc_cnt;
    v7 = qword_80D8;
    v8 = *(_QWORD **)(v4 + 144);
    *v8 = mpam_default_val;
    v8[1] = v7;
    if ( v6 < 2 )
      break;
    v9 = mpam_msc_cnt;
    v10 = qword_80E8;
    v11 = *(_QWORD *)(v4 + 144);
    *(_QWORD *)(v11 + 16) = qword_80E0;
    *(_QWORD *)(v11 + 24) = v10;
    if ( v9 < 3 )
      break;
    v12 = mpam_msc_cnt;
    v13 = qword_80F8;
    v14 = *(_QWORD *)(v4 + 144);
    *(_QWORD *)(v14 + 32) = qword_80F0;
    *(_QWORD *)(v14 + 40) = v13;
    if ( v12 < 4 )
      break;
    v15 = mpam_msc_cnt;
    v16 = qword_8108;
    v17 = *(_QWORD *)(v4 + 144);
    *(_QWORD *)(v17 + 48) = qword_8100;
    *(_QWORD *)(v17 + 56) = v16;
    if ( v15 < 5 )
      break;
    _fortify_panic(16, -1, 16);
    StatusReg = _ReadStatusReg(SP_EL0);
    v21 = *(_QWORD *)(StatusReg + 80);
    v22 = _kmalloc_noprof;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v4 = _kmalloc_cache_noprof(v22, 3520, 152);
    *(_QWORD *)(StatusReg + 80) = v21;
    if ( !v4 )
      return -12;
  }
  ((void (__fastcall *)(_QWORD))cpu_mpam_reset_param)((unsigned int)next_zero_area_off);
  if ( can_monitor == 1 )
    v18 = &cpu_mpam_item_type;
  else
    v18 = &cpu_mpam_item_type_legacy;
  config_group_init_type_name(v4, a2, v18);
  return v4;
}
