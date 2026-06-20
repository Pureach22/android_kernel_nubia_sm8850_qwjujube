__int64 __fastcall ram_load(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int16 *v5; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x14
  unsigned __int64 v8; // x13
  unsigned __int16 v9; // w11
  unsigned __int64 v10; // x10
  int v11; // w12
  int v12; // w12
  __int16 v13; // w13
  int v14; // w21
  unsigned __int64 v15; // x22
  _DWORD *v16; // x0
  _DWORD *v17; // x21
  unsigned __int64 v18; // x14
  __int16 v19; // w11
  unsigned __int8 *v20; // x16
  unsigned __int64 v21; // x17
  __int16 v22; // w0
  __int16 v23; // t1
  size_t v24; // x2
  _DWORD *v25; // x8
  int v26; // w8
  __int64 v27; // x0

  ++ram_load_load_cont;
  if ( !a1 )
  {
    printk(&unk_14D82, "haptic_hv", 1769, "ram_load");
    result = release_firmware(0);
    if ( (unsigned __int8)ram_load_load_cont <= 0x14u )
    {
      queue_delayed_work_on(32, system_wq, a2 + 960, 250);
      return printk(&unk_14DA5, "haptic_hv", 1775, "ram_load");
    }
    return result;
  }
  printk(&unk_15EE4, "haptic_hv", 1780, "ram_load");
  v6 = *(_QWORD *)a1;
  v5 = *(unsigned __int16 **)(a1 + 8);
  v7 = *(_QWORD *)a1 - 3LL;
  if ( *(_QWORD *)a1 >= 3u )
  {
    v8 = v6 - 2;
    if ( v6 - 2 >= 2 )
    {
      v9 = 0;
      v11 = 2;
      v10 = 2;
      if ( (unsigned int)v7 <= 0x7FFFFFFC )
      {
        v18 = HIDWORD(v7);
        if ( !v18 )
        {
          v19 = 0;
          v20 = (unsigned __int8 *)v5 + 3;
          v10 = (v8 & 0xFFFFFFFFFFFFFFFELL) + 2;
          v11 = (v8 & 0xFFFFFFFE) + 2;
          v21 = v8 & 0xFFFFFFFFFFFFFFFELL;
          do
          {
            v22 = *(v20 - 1);
            v23 = *v20;
            v20 += 2;
            v21 -= 2LL;
            v19 += v22;
            LOWORD(v18) = v18 + v23;
          }
          while ( v21 );
          v9 = v18 + v19;
          if ( v8 == (v8 & 0xFFFFFFFFFFFFFFFELL) )
            goto LABEL_9;
        }
      }
    }
    else
    {
      v9 = 0;
      v10 = 2;
      v11 = 2;
    }
    v12 = v11 + 1;
    do
    {
      v13 = *((unsigned __int8 *)v5 + v10);
      v10 = v12++;
      v9 += v13;
    }
    while ( v6 > v10 );
LABEL_9:
    v14 = v9;
    goto LABEL_11;
  }
  v14 = 0;
LABEL_11:
  if ( v14 != bswap32(*v5) >> 16 )
  {
    printk(&unk_13FDD, "haptic_hv", 1785, "ram_load");
    return release_firmware(a1);
  }
  printk(&unk_163E2, "haptic_hv", 1789, "ram_load");
  *(_DWORD *)(a2 + 1108) = v14;
  v15 = *(_QWORD *)a1 + 4LL;
  v16 = (_DWORD *)_kmalloc_noprof(v15, 3520);
  v17 = v16;
  if ( !v16 )
  {
    release_firmware(a1);
    return printk(&unk_145E8, "haptic_hv", 1796, "ram_load");
  }
  if ( v15 < 4 )
  {
    __break(1u);
    goto LABEL_31;
  }
  v24 = *(_QWORD *)a1;
  *v16 = *(_QWORD *)a1;
  if ( v15 - 4 < v24 )
  {
LABEL_31:
    v27 = _fortify_panic(17);
    return get_ram_num(v27);
  }
  memcpy(v16 + 1, *(const void **)(a1 + 8), v24);
  release_firmware(a1);
  v25 = *(_DWORD **)(*(_QWORD *)(a2 + 1480) + 48LL);
  if ( *(v25 - 1) != -781186032 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _DWORD *))v25)(a2, v17) )
  {
    printk(&unk_16147, "haptic_hv", 1804, "ram_load");
  }
  else
  {
    v26 = *v17 - *(unsigned __int8 *)(a2 + 1118);
    *(_BYTE *)(a2 + 6) = 1;
    *(_DWORD *)(a2 + 1104) = v26;
    printk(&unk_1575E, "haptic_hv", 1809, "ram_load");
    get_ram_num(a2);
  }
  return kfree(v17);
}
