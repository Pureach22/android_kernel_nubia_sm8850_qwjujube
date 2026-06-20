__int64 __fastcall cnss_stats_show(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 v3; // x24
  int v4; // w25
  int v5; // w21
  const char *v6; // x1
  __int64 v7; // x0
  __int64 v8; // x2
  bool v9; // cc
  int host_sol_value; // w0
  int dev_sol_value; // w0
  int direct_cx_host_sol_value; // w0

  v1 = *(_QWORD *)(a1 + 128);
  seq_printf(
    a1,
    "\nSerial Number: 0x%llx",
    *(unsigned int *)(v1 + 7848) | ((unsigned __int64)*(unsigned __int16 *)(v1 + 7844) << 32));
  seq_printf(a1, "\nState: 0x%lx(", *(_QWORD *)(v1 + 552));
  v3 = *(_QWORD *)(v1 + 552);
  if ( v3 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      if ( (v3 & 1) != 0 )
      {
        if ( v4 )
          seq_write(a1, " | ", 3);
        ++v4;
        switch ( v5 )
        {
          case 0:
            v6 = "QMI_WLFW_CONNECTED";
            goto LABEL_29;
          case 1:
            v6 = "FW_MEM_READY";
            goto LABEL_35;
          case 2:
            v6 = "FW_READY";
            goto LABEL_50;
          case 3:
            v6 = "IN_COLD_BOOT_CAL";
            goto LABEL_4;
          case 4:
            v6 = "DRIVER_LOADING";
            goto LABEL_42;
          case 5:
            v6 = "DRIVER_UNLOADING";
            goto LABEL_4;
          case 6:
            v6 = "IDLE_RESTART";
            goto LABEL_35;
          case 7:
            v6 = "IDLE_SHUTDOWN";
            goto LABEL_39;
          case 8:
            v6 = "DRIVER_PROBED";
            goto LABEL_39;
          case 9:
            v6 = "DRIVER_RECOVERY";
            goto LABEL_48;
          case 10:
            v6 = "FW_BOOT_RECOVERY";
            goto LABEL_4;
          case 11:
            v6 = "DEV_ERR";
            v7 = a1;
            v8 = 7;
            goto LABEL_5;
          case 12:
            v6 = "DRIVER_DEBUG";
LABEL_35:
            v7 = a1;
            v8 = 12;
            goto LABEL_5;
          case 13:
            v6 = "COEX_CONNECTED";
            goto LABEL_42;
          case 14:
            v6 = "IMS_CONNECTED";
            goto LABEL_39;
          case 15:
            v6 = "IN_SUSPEND_RESUME";
            goto LABEL_22;
          case 16:
            v6 = "IN_REBOOT";
            goto LABEL_46;
          case 17:
            v6 = "COLD_BOOT_CAL_DONE";
LABEL_29:
            v7 = a1;
            v8 = 18;
            goto LABEL_5;
          case 18:
            v6 = "IN_PANIC";
            goto LABEL_50;
          case 19:
            v6 = "DEL_SERVER_IN_PROGRESS";
            goto LABEL_44;
          case 20:
            v6 = "DMS_CONNECTED";
LABEL_39:
            v7 = a1;
            v8 = 13;
            goto LABEL_5;
          case 21:
            v6 = "DAEMON_CONNECTED";
            goto LABEL_4;
          case 22:
            v6 = "PCI PROBE DONE";
            goto LABEL_42;
          case 23:
          case 26:
            v6 = "DRIVER REGISTERED";
LABEL_22:
            v7 = a1;
            v8 = 17;
            goto LABEL_5;
          case 24:
            v6 = "WLAN HW DISABLED";
LABEL_4:
            v7 = a1;
            v8 = 16;
            goto LABEL_5;
          case 25:
            v6 = "FS READY";
LABEL_50:
            v7 = a1;
            v8 = 8;
            goto LABEL_5;
          case 27:
            v6 = "DMS_DEL_SERVER";
LABEL_42:
            v7 = a1;
            v8 = 14;
            goto LABEL_5;
          case 28:
            v6 = "POWER OFF";
LABEL_46:
            v7 = a1;
            v8 = 9;
            goto LABEL_5;
          case 29:
            v6 = "SHUTDOWN DEVICE";
LABEL_48:
            v7 = a1;
            v8 = 15;
            goto LABEL_5;
          case 30:
            v6 = "POWERING ON";
            v7 = a1;
            v8 = 11;
            goto LABEL_5;
          case 31:
            v6 = "DOWNLOAD SEC_IN_BOOTUP";
LABEL_44:
            v7 = a1;
            v8 = 22;
LABEL_5:
            seq_write(v7, v6, v8);
            break;
          default:
            seq_printf(a1, "UNKNOWN-%d", v5);
            break;
        }
      }
      v9 = v3 > 1;
      ++v5;
      v3 >>= 1;
    }
    while ( v9 );
  }
  seq_write(a1, ")\n", 2);
  host_sol_value = cnss_get_host_sol_value(v1);
  seq_printf(a1, "\nHost SOL: %d", host_sol_value);
  dev_sol_value = cnss_get_dev_sol_value(v1);
  seq_printf(a1, "\nDev SOL: %d", dev_sol_value);
  direct_cx_host_sol_value = cnss_get_direct_cx_host_sol_value(v1);
  seq_printf(a1, "\nDirect CX Host SOL: %d", direct_cx_host_sol_value);
  return 0;
}
