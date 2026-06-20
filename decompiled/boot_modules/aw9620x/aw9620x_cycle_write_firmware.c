__int64 __fastcall aw9620x_cycle_write_firmware(__int64 a1, __int64 a2, int a3)
{
  int v5; // w8
  int v6; // w21
  const char *v7; // x22
  size_t v8; // x23
  unsigned int v9; // w6
  size_t v10; // x21
  _BYTE *v11; // x20
  int v12; // w24
  unsigned int v13; // w27
  unsigned __int64 v14; // x8
  __int64 v15; // x26
  __int64 v16; // x8
  __int64 v17; // x1
  unsigned __int64 v18; // x8
  _BYTE *v19; // x9
  char v20; // w12
  char v21; // w13
  unsigned __int64 v22; // x10
  char v23; // w11
  __int64 v25; // x1
  unsigned __int64 v26; // x8
  _BYTE *v27; // x9
  char v28; // w12
  char v29; // w13
  size_t v30; // x10
  char v31; // w11
  unsigned __int64 StatusReg; // x24
  __int64 v33; // x26
  int v34; // [xsp+0h] [xbp-30h]
  unsigned int v35; // [xsp+10h] [xbp-20h]
  __int64 v36; // [xsp+18h] [xbp-18h]
  unsigned __int64 v37; // [xsp+20h] [xbp-10h]

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_cycle_write_firmware", 2069);
  v5 = a3 & 3;
  if ( (a3 & 3) != 0 )
  {
    v6 = 4 - v5;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] word_comp_len = %d\n",
      "aw9620x_cycle_write_firmware",
      2073,
      4 - v5);
  }
  else
  {
    v6 = 0;
  }
  LODWORD(v7) = v6 + a3;
  v8 = (unsigned int)(v6 + a3 + 8);
  v34 = v6 + a3 + 8;
  v9 = (v6 + a3) / 0xFC0u;
  v10 = (v6 + a3) % 0xFC0u;
  v35 = (unsigned int)v7 / 0xFC0;
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] firmware_len = %d cycle_cnt = %d cycle_cnt_last_len = %d send_all_len = %d\n",
    "aw9620x_cycle_write_firmware",
    2082,
    (_DWORD)v7,
    v9,
    v10,
    v34);
  v11 = (_BYTE *)_kmalloc_noprof((unsigned int)((_DWORD)v7 + 8), 3520);
  if ( !v11 )
  {
LABEL_54:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] devm_kzalloc err\n", "aw9620x_cycle_write_firmware", 2086);
    return 0;
  }
  while ( 1 )
  {
    v12 = 268443648;
    v13 = 1;
    memset(v11, 1, v8);
    if ( (unsigned int)v7 >= 0xFC0 )
    {
      v14 = v8 - 8;
      v15 = 0;
      if ( v8 < 8 )
        v14 = 0;
      v7 = "aw9620x_cycle_write_firmware";
      v37 = v14;
      if ( v35 <= 1 )
        v16 = 1;
      else
        v16 = v35;
      v36 = v16;
      while ( 2 )
      {
        if ( !v8 )
          goto LABEL_51;
        *v11 = HIBYTE(v13);
        if ( v8 == 1 )
          goto LABEL_51;
        v11[1] = BYTE2(v13);
        if ( v8 == 2 )
          goto LABEL_51;
        v11[2] = BYTE1(v13);
        if ( v8 < 4 )
          goto LABEL_51;
        v11[3] = v13;
        if ( v8 == 4 )
          goto LABEL_51;
        v11[4] = HIBYTE(v12);
        if ( v8 == 5 )
          goto LABEL_51;
        v11[5] = BYTE2(v12);
        if ( v8 < 7 )
          goto LABEL_51;
        v11[6] = BYTE1(v12);
        if ( v8 == 7 )
          goto LABEL_51;
        v17 = *(_QWORD *)(a1 + 48);
        v11[7] = v12;
        dev_printk(
          &unk_142BB,
          v17,
          "[%s:%d] cnt = %d tranfer head info 0x%02x 0x%02x 0x%02x 0x%02x\n",
          "aw9620x_cycle_write_firmware",
          2108,
          v15,
          HIBYTE(v13),
          BYTE2(v13),
          BYTE1(v13),
          (unsigned __int8)v13);
        dev_printk(
          &unk_142BB,
          *(_QWORD *)(a1 + 48),
          "[%s:%d] cnt = %d tranfer head info 0x%02x 0x%02x 0x%02x 0x%02x\n",
          "aw9620x_cycle_write_firmware",
          2108,
          v15,
          (unsigned __int8)v11[4],
          (unsigned __int8)v11[5],
          (unsigned __int8)v11[6],
          (unsigned __int8)v11[7]);
        dev_printk(
          &unk_142BB,
          *(_QWORD *)(a1 + 48),
          "[%s:%d] half_cache_len = %d\n",
          "aw9620x_cycle_write_firmware",
          2111,
          4032);
        if ( v37 <= 0xFBF )
          goto LABEL_52;
        memcpy(v11 + 8, (const void *)(a2 + 4032 * v15), 0xFC0u);
        v18 = 11;
        do
        {
          if ( v8 <= v18 - 3 || v8 <= v18 )
            goto LABEL_51;
          v19 = &v11[v18];
          v20 = v11[v18 - 3];
          v21 = v11[v18 - 1];
          v11[v18 - 3] = v11[v18];
          v22 = v18 - 11;
          v23 = v11[v18 - 2];
          v18 += 4LL;
          *v19 = v20;
          *(v19 - 2) = v21;
          *(v19 - 1) = v23;
        }
        while ( v22 < 0xFBC );
        if ( v15 == 2 )
        {
          dev_printk(
            &unk_134C0,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] flash addr write err, addr=0x%08X, len=0x%04X\n",
            "aw9620x_cycle_write_firmware",
            2119,
            268451712,
            4032);
LABEL_50:
          kfree(v11);
          return 0xFFFFFFFFLL;
        }
        if ( (unsigned int)aw9620x_send_once_cmd(a1, 1u, 2u, (__int64)v11, 0xFC8u) )
        {
          dev_printk(
            &unk_134C0,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] send_transfer_cmd_once err\n",
            "aw9620x_cycle_write_firmware",
            2125);
          goto LABEL_50;
        }
        ++v15;
        v12 += 4032;
        ++v13;
        if ( v15 != v36 )
          continue;
        break;
      }
    }
    if ( !(_DWORD)v10 )
      break;
    if ( !v8 )
      goto LABEL_51;
    *v11 = HIBYTE(v13);
    if ( v8 == 1 )
      goto LABEL_51;
    v11[1] = BYTE2(v13);
    if ( v8 == 2 )
      goto LABEL_51;
    v11[2] = BYTE1(v13);
    if ( v8 < 4 )
      goto LABEL_51;
    v11[3] = v13;
    if ( v8 == 4 )
      goto LABEL_51;
    v11[4] = HIBYTE(v12);
    if ( v8 == 5 )
      goto LABEL_51;
    v11[5] = BYTE2(v12);
    if ( v8 < 7 )
      goto LABEL_51;
    v11[6] = BYTE1(v12);
    if ( v8 == 7 )
      goto LABEL_51;
    v25 = *(_QWORD *)(a1 + 48);
    v7 = (const char *)&unk_142BB;
    v11[7] = v12;
    dev_printk(
      &unk_142BB,
      v25,
      "[%s:%d] last_len = %d tranfer head info 0x%02x 0x%02x 0x%02x 0x%02x\n",
      "aw9620x_cycle_write_firmware",
      2149,
      v10,
      HIBYTE(v13),
      BYTE2(v13),
      BYTE1(v13),
      (unsigned __int8)v13);
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] last_len = %d tranfer head info 0x%02x 0x%02x 0x%02x 0x%02x\n",
      "aw9620x_cycle_write_firmware",
      2149,
      v10,
      (unsigned __int8)v11[4],
      (unsigned __int8)v11[5],
      (unsigned __int8)v11[6],
      (unsigned __int8)v11[7]);
    if ( v8 - 8 >= v10 )
    {
      memcpy(v11 + 8, (const void *)(a2 + 4032 * v35), v10);
      v26 = 11;
      while ( v8 > v26 - 3 && v8 > v26 )
      {
        v27 = &v11[v26];
        v28 = v11[v26 - 3];
        v29 = v11[v26 - 1];
        v11[v26 - 3] = v11[v26];
        v30 = v26 - 7;
        v31 = v11[v26 - 2];
        v26 += 4LL;
        *v27 = v28;
        *(v27 - 2) = v29;
        *(v27 - 1) = v31;
        if ( v30 >= v10 )
        {
          if ( (unsigned int)(v12 + v10) > 0x10003FFF )
          {
            dev_printk(
              &unk_134C0,
              *(_QWORD *)(a1 + 48),
              "[%s:%d] flash addr write err, addr=0x%08X, len=0x%04X\n",
              "aw9620x_cycle_write_firmware",
              2159,
              v12,
              v10);
          }
          else
          {
            if ( !(unsigned int)aw9620x_send_once_cmd(a1, 1u, 2u, (__int64)v11, (int)v10 + 8) )
              goto LABEL_29;
            dev_printk(
              &unk_142BB,
              *(_QWORD *)(a1 + 48),
              "[%s:%d] send_transfer_cmd_once err\n",
              "aw9620x_cycle_write_firmware",
              2166);
          }
          goto LABEL_50;
        }
      }
LABEL_51:
      __break(1u);
LABEL_52:
      _fortify_panic(17);
      _fortify_panic(15);
    }
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v33 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &aw9620x_cycle_write_firmware__alloc_tag;
    v11 = (_BYTE *)_kmalloc_noprof(v8, 3520);
    *(_QWORD *)(StatusReg + 80) = v33;
    if ( !v11 )
      goto LABEL_54;
  }
LABEL_29:
  kfree(v11);
  return 0;
}
