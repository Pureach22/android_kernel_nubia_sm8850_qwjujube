__int64 __fastcall bt_ioctl(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v4; // w19
  int v5; // w0
  int v6; // w21
  unsigned int v7; // w20
  int v11; // w19
  int v12; // w8
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x0
  _DWORD *v17; // x8
  const char *SourceSubsystemString; // x25
  const char *UwbPrimaryCrashReason; // x23
  char *UwbSecondaryCrashReason; // x24
  const char *UwbTransportCrashReason; // x0
  int v23; // w19
  int v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( pwr_data && (probe_finished & 1) != 0 )
  {
    result = -515;
    v4 = 0;
    switch ( (int)a2 )
    {
      case 49068:
        goto LABEL_9;
      case 49069:
      case 49121:
        v6 = a2;
        v7 = a3;
        printk(&unk_1306C, "btpower_handle_client_request");
        if ( v6 == 49069 )
        {
          if ( v7 < 3 )
          {
            v17 = &unk_10CF8;
LABEL_34:
            v4 = schedule_client_voting(v17[v7]);
            goto LABEL_9;
          }
          v4 = -1;
        }
        else
        {
          v4 = -1;
          if ( v6 == 49121 && v7 <= 2 )
          {
            v17 = &unk_10D04;
            goto LABEL_34;
          }
        }
LABEL_9:
        result = v4;
        break;
      case 49070:
        v11 = a3;
        printk(&unk_111AB, "bt_ioctl");
        v12 = v11;
        if ( v11 )
        {
          v4 = 0;
          soc_id = v12;
        }
        else
        {
          printk(&unk_12DAA, "bt_ioctl");
          v4 = 0;
          soc_id = 0;
        }
        goto LABEL_9;
      case 49071:
        printk(&unk_12503, "bt_ioctl");
        if ( inline_copy_to_user(a3, pwr_data + 104, 32) )
          goto LABEL_18;
        goto LABEL_8;
      case 49072:
        printk(&unk_11567, a2);
        if ( *(int *)(pwr_data + 16) < 1 )
        {
          printk(&unk_125D2, v13);
          result = -22;
          break;
        }
        HIDWORD(qword_13A6C) = -1;
        v14 = gpio_to_desc(*(unsigned int *)(pwr_data + 16));
        v4 = gpiod_direction_input(v14);
        if ( v4 )
        {
          printk(&unk_125B3, "bt_ioctl");
          printk(&unk_128AC, "bt_ioctl");
        }
        else
        {
          v15 = gpio_to_desc(*(unsigned int *)(pwr_data + 16));
          HIDWORD(qword_13A6C) = gpiod_get_raw_value(v15);
          printk(&unk_1170E, *(unsigned int *)(pwr_data + 16));
        }
        goto LABEL_9;
      case 49073:
        printk(&unk_11CCA, a2);
        log_power_src_val();
        if ( inline_copy_to_user(a3, power_src, 432) )
          goto LABEL_18;
        goto LABEL_8;
      case 49074:
        printk(&unk_1154B, "bt_ioctl");
        if ( inline_copy_from_user((__int64)&fmdStruct, a3, 6u) )
          printk(&unk_13229, "bt_ioctl");
        v4 = ((__int64 (*)(void))perform_fmd_operation)();
        goto LABEL_9;
      case 49088:
        printk(&unk_13985, "bt_ioctl");
        btpower_enable_ipa_vreg(pwr_data);
        goto LABEL_8;
      case 49089:
        v23 = a3;
        printk(&unk_11F15, "bt_ioctl");
        bt_kernel_panic(v23);
      case 49090:
        printk(&unk_10E9A, "bt_ioctl");
        GetUwbPrimaryCrashReason((unsigned __int16)a3);
        GetUwbSecondaryCrashReason(WORD1(a3));
        SourceSubsystemString = GetSourceSubsystemString(WORD2(a3));
        GetUwbTransportCrashReason(SHIBYTE(a3));
        printk(&unk_11F30, "bt_ioctl");
        UwbPrimaryCrashReason = GetUwbPrimaryCrashReason((unsigned __int16)a3);
        UwbSecondaryCrashReason = GetUwbSecondaryCrashReason(WORD1(a3));
        UwbTransportCrashReason = GetUwbTransportCrashReason(SHIBYTE(a3));
        panic(
          "%s: UWB kernel panic PrimaryReason = (0x%02x)[%s] | SecondaryReason = (0x%02x)[%s] |SourceSubsystem = (0x%02x)"
          "[%s] | UwbTransportCrashReason = (0x%02x)[%s]\n",
          "bt_ioctl",
          (unsigned __int16)a3,
          UwbPrimaryCrashReason,
          WORD1(a3),
          UwbSecondaryCrashReason,
          WORD2(a3),
          SourceSubsystemString,
          a3 >> 56,
          UwbTransportCrashReason);
      case 49122:
        v5 = 1;
        goto LABEL_7;
      case 49123:
        v5 = 2;
LABEL_7:
        btpower_register_client(v5, a3);
        goto LABEL_8;
      case 49124:
      case 49125:
        v4 = btpower_process_access_req(a2, a3);
        goto LABEL_9;
      case 49126:
        v24 = *(_DWORD *)(pwr_data + 288);
        printk(&unk_1172F, "bt_ioctl");
        if ( inline_copy_to_user(a3, &v24, 4) )
        {
LABEL_18:
          printk(&unk_13229, "bt_ioctl");
          v4 = -14;
        }
        else
        {
LABEL_8:
          v4 = 0;
        }
        goto LABEL_9;
      default:
        break;
    }
  }
  else
  {
    printk(&unk_12B8B, "bt_ioctl");
    result = -11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
