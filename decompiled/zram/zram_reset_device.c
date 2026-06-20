__int64 __fastcall zram_reset_device(__int64 a1)
{
  __int64 v2; // x8
  char v3; // w12
  __int64 v4; // x8
  unsigned __int64 v5; // x12
  unsigned __int64 v6; // x12
  __int64 v7; // x14
  bool v8; // cf
  _QWORD *v9; // x13
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x21
  __int64 v12; // x20
  _QWORD *v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  char *v16; // x0

  down_write(a1 + 32);
  v2 = *(_QWORD *)(a1 + 216);
  *(_QWORD *)(a1 + 96) = 0;
  if ( v2 )
  {
    set_capacity_and_notify(*(_QWORD *)(a1 + 24), 0);
    v3 = 0;
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 64LL);
    do
    {
      v5 = (unsigned int)(-1LL << v3) & _cpu_possible_mask;
      if ( !(_DWORD)v5 )
        break;
      v6 = __clz(__rbit64(v5));
      v7 = _per_cpu_offset[v6];
      v8 = v6 >= 0x1F;
      v3 = v6 + 1;
      v9 = (_QWORD *)(v7 + *(_QWORD *)(v4 + 32));
      v9[17] = 0;
      v9[18] = 0;
      v9[15] = 0;
      v9[16] = 0;
      v9[13] = 0;
      v9[14] = 0;
      v9[11] = 0;
      v9[12] = 0;
      v9[9] = 0;
      v9[10] = 0;
      v9[7] = 0;
      v9[8] = 0;
      v9[5] = 0;
      v9[6] = 0;
      v9[3] = 0;
      v9[4] = 0;
      v9[1] = 0;
      v9[2] = 0;
      *v9 = 0;
    }
    while ( !v8 );
    v10 = *(_QWORD *)(a1 + 216);
    if ( v10 >= 0x1000 )
    {
      v11 = v10 >> 12;
      v12 = 0;
      do
        zram_free_page(a1, v12++);
      while ( v11 != v12 );
    }
    zs_destroy_pool(*(_QWORD *)(a1 + 8));
    vfree(*(_QWORD *)a1);
    v13 = *(_QWORD **)(a1 + 16);
    *(_QWORD *)(a1 + 216) = 0;
    *(_QWORD *)(a1 + 16) = 0;
    if ( v13 )
    {
      zcomp_destroy(v13);
      --*(_BYTE *)(a1 + 232);
    }
    v14 = *(_QWORD *)(a1 + 240);
    *(_QWORD *)(a1 + 200) = 0;
    *(_QWORD *)(a1 + 208) = 0;
    *(_QWORD *)(a1 + 184) = 0;
    *(_QWORD *)(a1 + 192) = 0;
    *(_QWORD *)(a1 + 168) = 0;
    *(_QWORD *)(a1 + 176) = 0;
    *(_QWORD *)(a1 + 152) = 0;
    *(_QWORD *)(a1 + 160) = 0;
    *(_QWORD *)(a1 + 136) = 0;
    *(_QWORD *)(a1 + 144) = 0;
    *(_QWORD *)(a1 + 120) = 0;
    *(_QWORD *)(a1 + 128) = 0;
    *(_QWORD *)(a1 + 104) = 0;
    *(_QWORD *)(a1 + 112) = 0;
    if ( v14 )
    {
      filp_close(v14, 0);
      v15 = *(_QWORD *)(a1 + 24);
      *(_QWORD *)(a1 + 240) = 0;
      *(_QWORD *)(a1 + 264) = 0;
      *(_QWORD *)(v15 + 72) = &zram_devops;
      kvfree(*(_QWORD *)(a1 + 272));
      *(_QWORD *)(a1 + 272) = 0;
    }
    v16 = *(char **)(a1 + 224);
    if ( v16 != "lzo-rle" )
      kfree(v16);
    *(_QWORD *)(a1 + 224) = "lzo-rle";
  }
  return up_write(a1 + 32);
}
