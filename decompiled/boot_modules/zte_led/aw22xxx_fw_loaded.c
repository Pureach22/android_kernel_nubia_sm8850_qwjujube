__int64 __fastcall aw22xxx_fw_loaded(unsigned __int64 *a1, __int64 *a2)
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
  unsigned __int64 v14; // x21
  unsigned int *v15; // x20
  void *v16; // x0
  unsigned __int64 v17; // x14
  __int16 v18; // w11
  unsigned __int8 *v19; // x16
  unsigned __int64 v20; // x17
  __int16 v21; // w0
  __int16 v22; // t1
  unsigned __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x8
  size_t v26; // x1
  size_t v27; // x2
  int v28; // w23
  void *v29; // x0
  int v30; // w22
  void *v31; // x0
  unsigned int v32; // w23
  unsigned int v33; // w8
  size_t v34; // x27
  __int64 v35; // x26
  _BYTE *v36; // x0
  _BYTE *v37; // x28
  __int64 v38; // x1
  void *v39; // x0
  unsigned __int64 v40; // x9
  bool v41; // cf
  size_t v42; // x9
  char v43; // w8
  _BYTE v44[4]; // [xsp+1Ch] [xbp-34h] BYREF
  _BYTE v45[4]; // [xsp+20h] [xbp-30h] BYREF
  char v46[4]; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  __int64 v50; // [xsp+40h] [xbp-10h]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v44[0] = 0;
  printk(&unk_130E1, "aw22xxx_fw_loaded");
  if ( a1 )
  {
    printk(&unk_12B62, "aw22xxx_fw_loaded");
    v6 = *a1;
    v5 = (unsigned __int16 *)a1[1];
    v7 = *a1 - 3;
    if ( *a1 < 3 )
    {
      v9 = 0;
      goto LABEL_10;
    }
    v8 = v6 - 2;
    if ( v6 - 2 >= 2 )
    {
      v9 = 0;
      v11 = 2;
      v10 = 2;
      if ( (unsigned int)v7 <= 0x7FFFFFFC )
      {
        v17 = HIDWORD(v7);
        if ( !v17 )
        {
          v18 = 0;
          v19 = (unsigned __int8 *)v5 + 3;
          v10 = (v8 & 0xFFFFFFFFFFFFFFFELL) + 2;
          v11 = (v8 & 0xFFFFFFFE) + 2;
          v20 = v8 & 0xFFFFFFFFFFFFFFFELL;
          do
          {
            v21 = *(v19 - 1);
            v22 = *v19;
            v19 += 2;
            v20 -= 2LL;
            v18 += v21;
            LOWORD(v17) = v17 + v22;
          }
          while ( v20 );
          v9 = v17 + v18;
          if ( v8 == (v8 & 0xFFFFFFFFFFFFFFFELL) )
          {
LABEL_10:
            if ( v9 != bswap32(*v5) >> 16 )
            {
              printk(&unk_12D49, "aw22xxx_fw_loaded");
              result = release_firmware(a1);
              goto LABEL_67;
            }
            printk(&unk_13168, "aw22xxx_fw_loaded");
            v14 = *a1 + 16;
            v15 = (unsigned int *)_kmalloc_noprof(v14, 3520);
            if ( !v15 )
            {
              release_firmware(a1);
              v16 = &unk_13CD7;
LABEL_66:
              result = printk(v16, "aw22xxx_fw_loaded");
              goto LABEL_67;
            }
            printk(&unk_1374E, "aw22xxx_fw_loaded");
            v23 = a1[1];
            v24 = *(_QWORD *)(v23 + 3);
            v25 = *(_QWORD *)(v23 + 11);
            v47 = v24;
            v48 = v25;
            printk(&unk_12C8B, "aw22xxx_fw_loaded");
            v47 = *(_QWORD *)(a1[1] + 19);
            printk(&unk_13B1A, "aw22xxx_fw_loaded");
            if ( v14 < 4 )
              goto LABEL_72;
            if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 4 )
              goto LABEL_72;
            v15[1] = bswap32(*(_DWORD *)(a1[1] + 27));
            printk(&unk_13DF0, "aw22xxx_fw_loaded");
            if ( v14 < 8 )
              goto LABEL_72;
            if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
              goto LABEL_72;
            v15[2] = __rev16(*(unsigned __int16 *)(a1[1] + 34));
            printk(&unk_13A39, "aw22xxx_fw_loaded");
            if ( v14 < 0xC || (v14 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
              goto LABEL_72;
            v15[3] = *(unsigned __int8 *)(a1[1] + 36);
            printk(&unk_1411B, "aw22xxx_fw_loaded");
            *v15 = __rev16(*(unsigned __int16 *)(a1[1] + 38));
            printk(&unk_13B30, "aw22xxx_fw_loaded");
            v27 = *v15;
            if ( v14 >= 0x10 )
              v26 = v14 - 16;
            else
              v26 = 0;
            if ( v26 < v27 )
LABEL_73:
              _fortify_panic(17, v26);
            memcpy(v15 + 4, (const void *)(a1[1] + 40), v27);
            release_firmware(a1);
            aw22xxx_i2c_write(a2, 1, 85);
            usleep_range_state(2000, 3000, 2);
            printk(&unk_13C1D, "aw22xxx_chip_enable");
            v46[0] = 0;
            aw22xxx_i2c_read(a2, 2, v46);
            v46[0] |= 1u;
            aw22xxx_i2c_write(a2, 2, v46[0]);
            usleep_range_state(2000, 3000, 2);
            v46[0] = 0;
            aw22xxx_i2c_read(a2, 4, v46);
            v46[0] |= 1u;
            aw22xxx_i2c_write(a2, 4, v46[0]);
            aw22xxx_i2c_write(a2, 34, (unsigned __int16)(*(_WORD *)v15 - 1) >> 8);
            aw22xxx_i2c_write(a2, 33, *(_BYTE *)v15 - 1);
            aw22xxx_i2c_write(a2, 36, 7);
            usleep_range_state(5000, 6500, 2);
            aw22xxx_i2c_read(a2, 36, v44);
            if ( v44[0] == 5 )
            {
              aw22xxx_i2c_read(a2, 37, v44);
              v28 = v44[0];
              aw22xxx_i2c_read(a2, 38, v44);
              if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
                goto LABEL_72;
              if ( (v28 | (v44[0] << 8)) == v15[2] )
              {
                printk(&unk_13BDB, "aw22xxx_fw_loaded");
                if ( !*((_BYTE *)a2 + 750) )
                {
                  kfree(v15);
                  aw22xxx_i2c_write(a2, 36, 0);
                  result = aw22xxx_led_init(a2);
                  *((_BYTE *)a2 + 751) = 2;
                  goto LABEL_67;
                }
                if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 4 )
                  goto LABEL_72;
                v29 = &unk_13226;
              }
              else
              {
                printk(&unk_13A51, "aw22xxx_fw_loaded");
                if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 4 )
                  goto LABEL_72;
                v29 = &unk_135B6;
              }
              printk(v29, "aw22xxx_fw_loaded");
            }
            else
            {
              printk(&unk_13769, "aw22xxx_fw_loaded");
              printk(&unk_13B47, "aw22xxx_fw_loaded");
            }
            aw22xxx_i2c_write(a2, 36, 0);
            v45[0] = 0;
            aw22xxx_i2c_write(a2, 255, 0);
            aw22xxx_i2c_write(a2, 1, 85);
            usleep_range_state(2000, 3000, 2);
            printk(&unk_13C1D, "aw22xxx_chip_enable");
            v46[0] = 0;
            aw22xxx_i2c_read(a2, 2, v46);
            v46[0] |= 1u;
            aw22xxx_i2c_write(a2, 2, v46[0]);
            usleep_range_state(2000, 3000, 2);
            v46[0] = 0;
            aw22xxx_i2c_read(a2, 4, v46);
            v46[0] |= 1u;
            aw22xxx_i2c_write(a2, 4, v46[0]);
            aw22xxx_i2c_write(a2, 128, 236);
            aw22xxx_i2c_write(a2, 53, 41);
            if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
              goto LABEL_72;
            aw22xxx_i2c_write(a2, 56, v15[3]);
            aw22xxx_i2c_write(a2, 34, 0);
            aw22xxx_i2c_write(a2, 33, 0);
            aw22xxx_i2c_write(a2, 32, 3);
            aw22xxx_i2c_write(a2, 48, 3);
            aw22xxx_i2c_write(a2, 35, 0);
            if ( (unsigned int)g_ver_var < 0xC )
              msleep(40);
            else
              usleep_range_state(4000, 4500, 2);
            aw22xxx_i2c_write(a2, 48, 0);
            aw22xxx_i2c_write(a2, 34, 64);
            aw22xxx_i2c_write(a2, 33, 0);
            aw22xxx_i2c_write(a2, 48, 2);
            aw22xxx_i2c_write(a2, 35, 0);
            usleep_range_state(6000, 6500, 2);
            aw22xxx_i2c_write(a2, 48, 0);
            aw22xxx_i2c_write(a2, 34, 66);
            aw22xxx_i2c_write(a2, 33, 0);
            aw22xxx_i2c_write(a2, 48, 2);
            aw22xxx_i2c_write(a2, 35, 0);
            usleep_range_state(6000, 6500, 2);
            aw22xxx_i2c_write(a2, 48, 0);
            aw22xxx_i2c_write(a2, 34, 68);
            aw22xxx_i2c_write(a2, 33, 0);
            aw22xxx_i2c_write(a2, 48, 2);
            aw22xxx_i2c_write(a2, 35, 0);
            usleep_range_state(6000, 6500, 2);
            aw22xxx_i2c_write(a2, 48, 0);
            aw22xxx_i2c_write(a2, 32, 0);
            aw22xxx_i2c_write(a2, 32, 3);
            if ( *v15 )
            {
              v32 = 0;
              _ReadStatusReg(SP_EL0);
              do
              {
                aw22xxx_i2c_write(a2, 34, SBYTE1(v32));
                aw22xxx_i2c_write(a2, 33, v32);
                aw22xxx_i2c_write(a2, 17, 1);
                aw22xxx_i2c_write(a2, 48, 4);
                v33 = *v15 - v32;
                if ( v33 >= 0x80 )
                  v34 = 128;
                else
                  v34 = v33;
                v35 = (unsigned int)(v34 + 1);
                v36 = (_BYTE *)_kmalloc_noprof(v35, 3264);
                v37 = v36;
                if ( v36 )
                {
                  v38 = v35 - 1;
                  *v36 = 35;
                  v39 = v36 + 1;
                  if ( v35 - 1 < v34 )
                  {
                    _fortify_panic(17, v38);
LABEL_71:
                    _fortify_panic(16, v38);
LABEL_72:
                    __break(1u);
                    goto LABEL_73;
                  }
                  v40 = v32 + 16LL;
                  v41 = v14 >= v40;
                  v42 = v14 - v40;
                  if ( !v41 )
                    v42 = 0;
                  if ( v42 < v34 )
                    goto LABEL_71;
                  memcpy(v39, (char *)v15 + v32 + 16, v34);
                  if ( (i2c_transfer_buffer_flags(*a2, v37, (unsigned int)(v34 + 1), 0) & 0x80000000) != 0 )
                    printk(&unk_13187, "aw22xxx_i2c_writes");
                  kfree(v37);
                }
                else
                {
                  printk(&unk_13349, "aw22xxx_i2c_writes");
                }
                aw22xxx_i2c_write(a2, 17, 0);
                aw22xxx_i2c_write(a2, 48, 0);
                v32 += v34;
              }
              while ( v32 < *v15 );
            }
            aw22xxx_i2c_write(a2, 32, 0);
            aw22xxx_i2c_write(a2, 1, 85);
            usleep_range_state(2000, 3000, 2);
            printk(&unk_13C1D, "aw22xxx_chip_enable");
            v46[0] = 0;
            aw22xxx_i2c_read(a2, 2, v46);
            v46[0] |= 1u;
            aw22xxx_i2c_write(a2, 2, v46[0]);
            usleep_range_state(2000, 3000, 2);
            v46[0] = 0;
            aw22xxx_i2c_read(a2, 4, v46);
            v46[0] |= 1u;
            aw22xxx_i2c_write(a2, 4, v46[0]);
            aw22xxx_i2c_write(a2, 34, (unsigned __int16)(*(_WORD *)v15 - 1) >> 8);
            aw22xxx_i2c_write(a2, 33, *(_BYTE *)v15 - 1);
            aw22xxx_i2c_write(a2, 36, 7);
            usleep_range_state(5000, 6500, 2);
            aw22xxx_i2c_read(a2, 36, v45);
            if ( v45[0] == 5 )
            {
              aw22xxx_i2c_read(a2, 37, v45);
              v30 = v45[0];
              aw22xxx_i2c_read(a2, 38, v45);
              if ( (v14 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
                goto LABEL_72;
              if ( (v30 | (v45[0] << 8)) != v15[2] )
              {
                printk(&unk_12CA2, "aw22xxx_container_update");
                printk(&unk_13B5D, "aw22xxx_container_update");
                v43 = 3;
                goto LABEL_65;
              }
              v31 = &unk_13BDB;
            }
            else
            {
              v31 = &unk_13769;
            }
            printk(v31, "aw22xxx_container_update");
            aw22xxx_i2c_write(a2, 36, 0);
            v43 = 2;
LABEL_65:
            *((_BYTE *)a2 + 751) = v43;
            kfree(v15);
            *((_BYTE *)a2 + 750) = 0;
            aw22xxx_led_init(a2);
            v16 = &unk_13CF6;
            goto LABEL_66;
          }
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
    goto LABEL_10;
  }
  printk(&unk_12E4B, "aw22xxx_fw_loaded");
  result = release_firmware(0);
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
