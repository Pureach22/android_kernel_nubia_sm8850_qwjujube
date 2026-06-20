__int64 __fastcall aw9620x_fw_update(__int64 a1, unsigned __int8 a2, __int64 a3, unsigned int a4, int a5)
{
  int v10; // w24
  __int64 v11; // x1
  int v12; // w0
  __int64 v13; // x1
  unsigned int v14; // w24
  __int64 result; // x0
  __int64 v16; // x1
  unsigned int v17; // w23
  __int64 v19; // x1
  int all_val; // w0
  __int64 v21; // x1
  unsigned int v22; // w9
  int v23; // w8
  unsigned int v24; // w10
  int v25; // w11
  int v26; // w12
  int v27; // w11
  unsigned int v28; // w23
  __int64 v29; // x1
  int v30; // w0
  __int64 v31; // x1
  int v32; // w0
  __int64 v33; // x1
  __int64 v34; // x1
  __int64 v35; // x1
  int v36; // w0
  __int64 v37; // x1
  int v38; // w24
  int v39; // w25
  __int64 v40; // x1
  int v41; // w24
  unsigned int v42; // w25
  int v43; // w0
  __int64 v44; // x1
  int v45; // w0
  __int64 v46; // x1
  int v47; // w0
  __int64 v48; // x1
  __int64 v49; // [xsp+8h] [xbp-28h] BYREF
  __int64 v50; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v51; // [xsp+18h] [xbp-18h] BYREF
  __int64 v52; // [xsp+1Ch] [xbp-14h]
  unsigned int v53; // [xsp+24h] [xbp-Ch]
  __int64 v54; // [xsp+28h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2;
  dev_printk(
    &unk_134C0,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] fw_len = %d,app_version = 0x%x\n",
    "aw9620x_fw_update",
    2567,
    a4,
    a5);
  if ( v10 )
    goto LABEL_7;
  v11 = *(_QWORD *)(a1 + 48);
  v51 = 0;
  dev_printk(&unk_142BB, v11, "[%s:%d] enter\n", "aw9620x_fw_version_cmp", 1826);
  v12 = aw9620x_i2c_read(a1, 6672, &v51);
  v13 = *(_QWORD *)(a1 + 48);
  if ( v12 < 0 )
  {
    dev_printk(&unk_142BB, v13, "[%s:%d] read firmware version err\n", "aw9620x_fw_version_cmp", 1830);
    goto LABEL_7;
  }
  v14 = v51;
  dev_printk(&unk_142BB, v13, "[%s:%d] REG_FWVER :0x%08x bin_fwver :0x%08x!\n", "aw9620x_fw_version_cmp", 1834, v51, a5);
  if ( v14 != a5 )
  {
LABEL_7:
    v16 = *(_QWORD *)(a1 + 48);
    v49 = 0;
    dev_printk(&unk_142BB, v16, "[%s:%d] enter\n", "aw9620x_send_all_update_cmd", 2420);
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] 1.Send online upgrade command\n",
      "aw9620x_send_all_update_cmd",
      2424);
    v51 = 0;
    if ( !(unsigned int)aw9620x_i2c_write(a1, 0x4408u, 2) )
    {
      v17 = 0;
      do
      {
        if ( (unsigned int)aw9620x_i2c_read(a1, 6676, &v51) )
        {
          dev_printk(
            &unk_134C0,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] REG_CMD_SEND_TIRG err\n",
            "aw9620x_send_online_cmd",
            2317);
          goto LABEL_33;
        }
        if ( v51 == 50331648 )
        {
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] enter SLEEP MODE OK!\n",
            "aw9620x_send_online_cmd",
            2321);
          goto LABEL_19;
        }
        usleep_range_state(1000, 1010, 2);
      }
      while ( v17++ < 0x63 );
      if ( (unsigned int)aw9620x_i2c_read(a1, 6672, &v51) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] REG_CMD_SEND_TIRG err\n", "aw9620x_send_online_cmd", 2330);
        goto LABEL_33;
      }
      v19 = *(_QWORD *)(a1 + 48);
      if ( v51 != 50331648 )
      {
        dev_printk(&unk_134C0, v19, "[%s:%d] enter AW_PUB_VER SLEEP MODE err\n", "aw9620x_send_online_cmd", 2336);
        goto LABEL_33;
      }
      dev_printk(&unk_142BB, v19, "[%s:%d] enterA W_PUB_VER SLEEP MODE OK!\n", "aw9620x_send_online_cmd", 2334);
LABEL_19:
      if ( (unsigned int)aw9620x_i2c_write(a1, 0x4408u, 20) )
      {
        dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] REG_CMD_SEND_TIRG err\n", "aw9620x_send_online_cmd", 2343);
        goto LABEL_33;
      }
      msleep(1);
      if ( (unsigned int)aw9620x_read_ack_irq(a1) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] read_ack_irq err\n", "aw9620x_send_online_cmd", 2351);
        goto LABEL_33;
      }
      *(_BYTE *)(a1 + 640) = 1;
      if ( (unsigned int)aw9620x_i2c_read(a1, 7216, a1 + 656) )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(a1 + 48),
          "[%s:%d] read AW_BT_VER_INF_VERSION err\n",
          "aw9620x_get_fw_and_bt_info",
          2270);
      }
      else if ( (unsigned int)aw9620x_i2c_read(a1, 7220, a1 + 660) )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(a1 + 48),
          "[%s:%d] read AW_BT_VER_INF_DATE err\n",
          "aw9620x_get_fw_and_bt_info",
          2276);
      }
      else
      {
        all_val = aw9620x_reg_read_all_val(a1, a1 + 664, 2044);
        v21 = *(_QWORD *)(a1 + 48);
        if ( !all_val )
        {
          dev_printk(
            &unk_13D4F,
            v21,
            "[%s:%d] boot version:0x%08x, date:0x%08x, checksum 0x%08x\n",
            "aw9620x_get_fw_and_bt_info",
            2287,
            *(_DWORD *)(a1 + 656),
            *(_DWORD *)(a1 + 660),
            *(_DWORD *)(a1 + 664));
          v22 = 0;
          v23 = 0;
          v24 = -4;
          do
          {
            v24 += 4;
            if ( v24 < a4 )
            {
              v25 = (*(unsigned __int8 *)(a3 + v22 + 3) << 24)
                  | (*(unsigned __int8 *)(a3 + v22 + 2) << 16)
                  | (*(unsigned __int8 *)(a3 + v22 + 1) << 8);
              v26 = *(unsigned __int8 *)(a3 + v22);
              v22 += 4;
              v27 = v25 | v26;
            }
            else
            {
              v27 = -1;
            }
            v23 += v27;
          }
          while ( v24 >> 2 < 0xDFD );
          v28 = -v23;
          v29 = *(_QWORD *)(a1 + 48);
          *(_DWORD *)(a1 + 652) = -v23;
          dev_printk(&unk_13D4F, v29, "[%s:%d] firmwarw checksum 0x%08x\n", "aw9620x_get_fw_and_bt_info", 2297, -v23);
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] 2.send start cmd\n",
            "aw9620x_send_all_update_cmd",
            2440);
          *(_DWORD *)(a1 + 36) = 1;
          v30 = aw9620x_send_once_cmd(a1, 1, 1, 0, 0);
          v31 = *(_QWORD *)(a1 + 48);
          if ( v30 )
          {
            dev_printk(&unk_142BB, v31, "[%s:%d] send_UPDATE_START_CMD_cmd err\n", "aw9620x_send_all_update_cmd", 2446);
            goto LABEL_34;
          }
          dev_printk(
            &unk_142BB,
            v31,
            "[%s:%d] 3.a en fw check erase_last_sector\n",
            "aw9620x_send_all_update_cmd",
            2451);
          v51 = -2143354864;
          *(_DWORD *)(a1 + 36) = 2;
          v32 = aw9620x_send_once_cmd(a1, 2, 2, &v51, 4);
          v33 = *(_QWORD *)(a1 + 48);
          if ( v32 )
          {
            dev_printk(&unk_142BB, v33, "[%s:%d] send_UPDATE_START_CMD_cmd\n", "aw9620x_flash_erase_last_sector", 2401);
            dev_printk(
              &unk_142BB,
              *(_QWORD *)(a1 + 48),
              "[%s:%d] aw9620x_flash_erase_sector err\n",
              "aw9620x_send_all_update_cmd",
              2454);
            goto LABEL_34;
          }
          dev_printk(
            &unk_142BB,
            v33,
            "[%s:%d] cnt : %d, addr = 0x%x\n",
            "aw9620x_flash_erase_last_sector",
            2404,
            64,
            268451712);
          dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] 3.b en fw check\n", "aw9620x_send_all_update_cmd", 2459);
          *(_DWORD *)(a1 + 36) = 4;
          v34 = *(_QWORD *)(a1 + 48);
          v50 = 0;
          dev_printk(&unk_142BB, v34, "[%s:%d] enter\n", "aw9620x_write_firmware_checksum", 2194);
          v35 = *(_QWORD *)(a1 + 48);
          v51 = 0;
          v52 = 0x22202220F83F0010LL;
          v53 = bswap32(v28);
          dev_printk(
            &unk_142BB,
            v35,
            "[%s:%d] 0x%x 0x%x 0x%x 0x%x\n",
            "aw9620x_write_firmware_checksum",
            2219,
            0,
            0,
            0,
            0);
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] 0x%x 0x%x 0x%x 0x%x\n",
            "aw9620x_write_firmware_checksum",
            2219,
            16,
            0,
            63,
            248);
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] 0x%x 0x%x 0x%x 0x%x\n",
            "aw9620x_write_firmware_checksum",
            2219,
            32,
            34,
            32,
            34);
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] 0x%x 0x%x 0x%x 0x%x\n",
            "aw9620x_write_firmware_checksum",
            2219,
            (unsigned __int8)v53,
            BYTE1(v53),
            BYTE2(v53),
            HIBYTE(v53));
          if ( (unsigned int)aw9620x_send_once_cmd(a1, 1, 2, &v51, 16) )
          {
            dev_printk(
              &unk_142BB,
              *(_QWORD *)(a1 + 48),
              "[%s:%d] %s err\n",
              "aw9620x_write_firmware_checksum",
              2227,
              "aw9620x_write_firmware_checksum");
          }
          else if ( (unsigned int)aw9620x_reg_read_all_val(a1, (char *)&v50 + 4, 16376) )
          {
            dev_printk(
              &unk_142BB,
              *(_QWORD *)(a1 + 48),
              "[%s:%d] aw9620x_read check_en err\n",
              "aw9620x_write_firmware_checksum",
              2234);
          }
          else
          {
            v36 = aw9620x_reg_read_all_val(a1, &v50, 16380);
            v37 = *(_QWORD *)(a1 + 48);
            if ( v36 )
            {
              dev_printk(
                &unk_142BB,
                v37,
                "[%s:%d] aw9620x_read check_en err\n",
                "aw9620x_write_firmware_checksum",
                2241);
            }
            else
            {
              v38 = v50;
              v39 = HIDWORD(v50);
              dev_printk(
                &unk_142BB,
                v37,
                "[%s:%d] r_check_en :0x%08x, r_checksum 0x%08x\n",
                "aw9620x_write_firmware_checksum",
                2247,
                HIDWORD(v50),
                v50);
              v40 = *(_QWORD *)(a1 + 48);
              if ( v39 == 539107362 && v38 == v28 )
              {
                dev_printk(
                  &unk_142BB,
                  v40,
                  "[%s:%d] Consistent reading and writing\n",
                  "aw9620x_write_firmware_checksum",
                  2250);
                dev_printk(
                  &unk_142BB,
                  *(_QWORD *)(a1 + 48),
                  "[%s:%d] 4.send Erase Chip Cmd\n",
                  "aw9620x_send_all_update_cmd",
                  2469);
                v41 = 0;
                v42 = 268443648;
                do
                {
                  v51 = bswap32(v42);
                  *(_DWORD *)(a1 + 36) = 2;
                  v43 = aw9620x_send_once_cmd(a1, 2, 2, &v51, 4);
                  v44 = *(_QWORD *)(a1 + 48);
                  if ( v43 )
                  {
                    dev_printk(
                      &unk_142BB,
                      v44,
                      "[%s:%d] send_UPDATE_START_CMD_cmd err i = %d\n",
                      "aw9620x_flash_erase_sector",
                      2376,
                      v41);
                    dev_printk(
                      &unk_142BB,
                      *(_QWORD *)(a1 + 48),
                      "[%s:%d] aw9620x_flash_erase_sector err\n",
                      "aw9620x_send_all_update_cmd",
                      2472);
                    goto LABEL_34;
                  }
                  dev_printk(
                    &unk_142BB,
                    v44,
                    "[%s:%d] cnt : %d, addr = 0x%x\n",
                    "aw9620x_flash_erase_sector",
                    2379,
                    v41++,
                    v42);
                  v42 += 128;
                }
                while ( v41 != 63 );
                dev_printk(
                  &unk_142BB,
                  *(_QWORD *)(a1 + 48),
                  "[%s:%d] 5.Cycle write firmware\n",
                  "aw9620x_send_all_update_cmd",
                  2478);
                *(_DWORD *)(a1 + 36) = 3;
                v45 = aw9620x_cycle_write_firmware(a1, a3, a4);
                v46 = *(_QWORD *)(a1 + 48);
                if ( v45 )
                {
                  dev_printk(&unk_142BB, v46, "[%s:%d] cycle_write_firmware err\n", "aw9620x_send_all_update_cmd", 2482);
                }
                else
                {
                  dev_printk(&unk_142BB, v46, "[%s:%d] 6.send stop\n", "aw9620x_send_all_update_cmd", 2488);
                  *(_DWORD *)(a1 + 36) = 6;
                  v47 = aw9620x_send_stop_cmd(a1);
                  v48 = *(_QWORD *)(a1 + 48);
                  if ( !v47 )
                  {
                    dev_printk(
                      &unk_142BB,
                      v48,
                      "[%s:%d] %s ok, update firmware ok!\n",
                      "aw9620x_send_all_update_cmd",
                      2496,
                      "aw9620x_send_all_update_cmd");
                    dev_printk(
                      &unk_134C0,
                      *(_QWORD *)(a1 + 48),
                      "[%s:%d] prot update fw ok!!!\n",
                      "aw9620x_send_all_update_cmd",
                      2549);
                    goto LABEL_6;
                  }
                  dev_printk(&unk_142BB, v48, "[%s:%d] stop err\n", "aw9620x_send_all_update_cmd", 2492);
                }
                goto LABEL_34;
              }
              dev_printk(
                &unk_134C0,
                v40,
                "[%s:%d] err ! r_check_en != AW_CHECK_EN_VAL || r_checksum != w_checksum\n",
                "aw9620x_write_firmware_checksum",
                2254);
            }
          }
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] aw9620x_write_firmware_checksum err\n",
            "aw9620x_send_all_update_cmd",
            2463);
          goto LABEL_34;
        }
        dev_printk(&unk_134C0, v21, "[%s:%d] read bt_checksum err\n", "aw9620x_get_fw_and_bt_info", 2283);
      }
      dev_printk(
        &unk_142BB,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] aw9620x_get_fw_and_bt_infor\n",
        "aw9620x_send_all_update_cmd",
        2434);
      goto LABEL_34;
    }
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] REG_CMD_SEND_TIRG err\n", "aw9620x_send_online_cmd", 2310);
LABEL_33:
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] 1.Send online upgrade command err\n",
      "aw9620x_send_all_update_cmd",
      2427);
LABEL_34:
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] Write through protocol failed, start write through register\n",
      "aw9620x_send_all_update_cmd",
      2500);
    if ( (unsigned int)aw9620x_i2c_write(a1, 0xFF20u, 1006694801) )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] REG_APB_ACCESS_EN err\n",
        "aw9620x_send_all_update_cmd",
        2504);
    }
    else if ( (unsigned int)aw9620x_i2c_read(a1, 18248, &v49) )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] read REG_BOOT_LOADER_ACTIVE err\n",
        "aw9620x_send_all_update_cmd",
        2510);
    }
    else if ( (_DWORD)v49 && (unsigned int)aw9620x_i2c_write(a1, 0x4748u, 0) )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] write REG_BOOT_LOADER_ACTIVE err\n",
        "aw9620x_send_all_update_cmd",
        2516);
    }
    else if ( (unsigned int)aw9620x_i2c_read(a1, 18244, (char *)&v49 + 4) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] 0x4744 read err\n", "aw9620x_send_all_update_cmd", 2523);
    }
    else if ( HIBYTE(HIDWORD(v49)) && (unsigned int)aw9620x_i2c_write(a1, 0x4744u, HIDWORD(v49) & 0xFFFFFF) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] 0x4744 wr err\n", "aw9620x_send_all_update_cmd", 2530);
    }
    else if ( (unsigned int)aw9620x_i2c_write(a1, 0xFF20u, 1006694417) )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] REG_APB_ACCESS_EN wr err\n",
        "aw9620x_send_all_update_cmd",
        2537);
    }
    else
    {
      if ( a2 != 1 )
      {
        result = 4294967292LL;
        goto LABEL_53;
      }
      dev_printk(
        &unk_142BB,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] aw9620x->direct_updata_flag = AW_TURE\n",
        "aw9620x_send_all_update_cmd",
        2542);
    }
    result = 0xFFFFFFFFLL;
    goto LABEL_53;
  }
  dev_printk(
    &unk_142BB,
    *(_QWORD *)(a1 + 48),
    "[%s:%d] bin fw not greater than soc fw, no update!\n",
    "aw9620x_fw_update",
    2572);
LABEL_6:
  result = 0;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
