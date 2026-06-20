__int64 __fastcall aw8693x_container_update(__int64 a1, int *a2)
{
  _DWORD *v4; // x23
  unsigned int v5; // w8
  unsigned int v6; // w8
  int v7; // w22
  int i; // w8
  int v9; // w8
  unsigned int v10; // w21
  int v11; // w22
  int v12; // w8
  int v13; // w26
  unsigned int v14; // w21
  int v15; // w9
  __int64 v16; // x4
  unsigned int v17; // w20
  _BYTE v19[4]; // [xsp+0h] [xbp-410h] BYREF
  _WORD v20[2]; // [xsp+4h] [xbp-40Ch] BYREF
  _BYTE s[1024]; // [xsp+8h] [xbp-408h] BYREF
  __int64 v22; // [xsp+408h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  mutex_lock(a1 + 752);
  *(_WORD *)(a1 + 1118) = 516;
  aw8693x_stop(a1);
  i2c_w_bits(a1, 69, 4294967291LL, 4);
  usleep_range_state(500, 600, 2);
  v4 = a2 + 1;
  *(_DWORD *)(a1 + 1112) = __rev16(*(unsigned __int16 *)((char *)a2 + *(unsigned __int8 *)(a1 + 1119) + 4));
  printk(&unk_14216, "haptic_hv", 1623, "aw8693x_container_update");
  v5 = *(_DWORD *)(a1 + 1112);
  v19[1] = v5 >> 1;
  v19[2] = v5 - (v5 >> 2);
  v19[0] = (v5 >> 5) & 0xF0 | ((unsigned __int16)(v5 - (v5 >> 2)) >> 8) & 0xF;
  i2c_w_bytes(a1, 47, v19, 3);
  i2c_r_bytes(a1, 47, v19, 3);
  printk(&unk_152FC, "haptic_hv", 1637, "aw8693x_container_update");
  printk(&unk_14924, "haptic_hv", 1640, "aw8693x_container_update");
  v6 = *(_DWORD *)(a1 + 1112);
  v20[0] = bswap32(v6) >> 16;
  i2c_w_bits(a1, 45, 4294967264LL, v6 >> 8);
  i2c_w_bytes(a1, 46, (char *)v20 + 1, 1);
  v20[0] = bswap32(*(unsigned __int16 *)(a1 + 1112)) >> 16;
  i2c_w_bytes(a1, 64, v20, 2);
  v7 = *(unsigned __int8 *)(a1 + 1118);
  for ( i = *a2; v7 < *a2; v7 += v10 )
  {
    v9 = i - v7;
    if ( v9 >= 2048 )
      v10 = 2048;
    else
      v10 = v9;
    i2c_w_bytes(a1, 66, (char *)v4 + v7, v10);
    i = *a2;
  }
  v20[0] = bswap32(*(unsigned __int16 *)(a1 + 1112)) >> 16;
  i2c_w_bytes(a1, 64, v20, 2);
  v11 = *(unsigned __int8 *)(a1 + 1118);
  v12 = *a2;
  if ( *a2 > v11 )
  {
    while ( 2 )
    {
      v13 = v12 - v11;
      if ( v12 - v11 >= 1024 )
        v14 = 1024;
      else
        v14 = v12 - v11;
      i2c_r_bytes(a1, 66, s, v14);
      v15 = v13;
      v16 = 0;
      if ( v13 >= 1024LL )
        v15 = 1024;
      do
      {
        if ( (unsigned int)v16 > 0x3FF )
          __break(1u);
        if ( s[v16] != *((_BYTE *)v4 + v11 + v16) )
        {
          printk(&unk_13F1B, "haptic_hv", 1584, "aw8693x_check_ram_data");
          printk(&unk_14B06, "haptic_hv", 1671, "aw8693x_container_update");
          v17 = -34;
          goto LABEL_18;
        }
        ++v16;
      }
      while ( v15 != (_DWORD)v16 );
      v12 = *a2;
      v11 += v14;
      if ( v11 < *a2 )
        continue;
      break;
    }
  }
  printk(&unk_169D1, "haptic_hv", 1673, "aw8693x_container_update");
  v17 = 0;
LABEL_18:
  i2c_w_bits(a1, 69, 4294967291LL, 0);
  mutex_unlock(a1 + 752);
  _ReadStatusReg(SP_EL0);
  return v17;
}
