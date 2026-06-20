__int64 __fastcall icnss_stats_show(__int64 a1)
{
  __int64 v1; // x21
  const char *v3; // x0
  const char *v4; // x0
  const char *v5; // x0
  const char *v6; // x0
  const char *v7; // x0
  const char *v8; // x0
  const char *v9; // x0
  const char *v10; // x0
  const char *v11; // x0
  const char *v12; // x0
  const char *v13; // x0
  const char *v14; // x0
  const char *v15; // x0
  const char *v16; // x0
  const char *v17; // x0
  const char *v18; // x0
  const char *v19; // x0
  const char *v20; // x0
  unsigned __int64 v21; // x23
  int v22; // w24
  int v23; // w20
  const char *v24; // x1
  __int64 v25; // x0
  __int64 v26; // x2
  bool v27; // cc

  v1 = *(_QWORD *)(a1 + 128);
  ((void (*)(void))seq_printf)();
  seq_printf(a1, "%24s: %u\n", "ind_register_resp", *(_DWORD *)(v1 + 2568));
  seq_printf(a1, "%24s: %u\n", "ind_register_err", *(_DWORD *)(v1 + 2572));
  seq_printf(a1, "%24s: %u\n", "cap_req", *(_DWORD *)(v1 + 2604));
  seq_printf(a1, "%24s: %u\n", "cap_resp", *(_DWORD *)(v1 + 2608));
  seq_printf(a1, "%24s: %u\n", "cap_err", *(_DWORD *)(v1 + 2612));
  seq_printf(a1, "%24s: %u\n", "pin_connect_result", *(_DWORD *)(v1 + 2616));
  seq_printf(a1, "%24s: %u\n", "cfg_req", *(_DWORD *)(v1 + 2620));
  seq_printf(a1, "%24s: %u\n", "cfg_resp", *(_DWORD *)(v1 + 2624));
  seq_printf(a1, "%24s: %u\n", "cfg_req_err", *(_DWORD *)(v1 + 2628));
  seq_printf(a1, "%24s: %u\n", "mode_req", *(_DWORD *)(v1 + 2632));
  seq_printf(a1, "%24s: %u\n", "mode_resp", *(_DWORD *)(v1 + 2636));
  seq_printf(a1, "%24s: %u\n", "mode_req_err", *(_DWORD *)(v1 + 2640));
  seq_printf(a1, "%24s: %u\n", "ini_req", *(_DWORD *)(v1 + 2644));
  seq_printf(a1, "%24s: %u\n", "ini_resp", *(_DWORD *)(v1 + 2648));
  seq_printf(a1, "%24s: %u\n", "ini_req_err", *(_DWORD *)(v1 + 2652));
  seq_printf(a1, "%24s: %u\n", "recovery.pdr_fw_crash", *(_DWORD *)(v1 + 2508));
  seq_printf(a1, "%24s: %u\n", "recovery.pdr_host_error", *(_DWORD *)(v1 + 2512));
  seq_printf(a1, "%24s: %u\n", "recovery.root_pd_crash", *(_DWORD *)(v1 + 2516));
  seq_printf(a1, "%24s: %u\n", "recovery.root_pd_shutdown", *(_DWORD *)(v1 + 2520));
  seq_write(a1, "\n<------------------ PM stats ------------------->\n", 51);
  seq_printf(a1, "%24s: %u\n", "pm_suspend", *(_DWORD *)(v1 + 2524));
  seq_printf(a1, "%24s: %u\n", "pm_suspend_err", *(_DWORD *)(v1 + 2528));
  seq_printf(a1, "%24s: %u\n", "pm_resume", *(_DWORD *)(v1 + 2532));
  seq_printf(a1, "%24s: %u\n", "pm_resume_err", *(_DWORD *)(v1 + 2536));
  seq_printf(a1, "%24s: %u\n", "pm_suspend_noirq", *(_DWORD *)(v1 + 2540));
  seq_printf(a1, "%24s: %u\n", "pm_suspend_noirq_err", *(_DWORD *)(v1 + 2544));
  seq_printf(a1, "%24s: %u\n", "pm_resume_noirq", *(_DWORD *)(v1 + 2548));
  seq_printf(a1, "%24s: %u\n", "pm_resume_noirq_err", *(_DWORD *)(v1 + 2552));
  seq_printf(a1, "%24s: %u\n", "pm_stay_awake", *(_DWORD *)(v1 + 2556));
  seq_printf(a1, "%24s: %u\n", "pm_relax", *(_DWORD *)(v1 + 2560));
  if ( *(_QWORD *)(v1 + 304) == 43981 )
  {
    seq_write(a1, "\n<------------------ MSA stats ------------------->\n", 52);
    seq_printf(a1, "%24s: %u\n", "msa_info_req", *(_DWORD *)(v1 + 2576));
    seq_printf(a1, "%24s: %u\n", "msa_info_resp", *(_DWORD *)(v1 + 2580));
    seq_printf(a1, "%24s: %u\n", "msa_info_err", *(_DWORD *)(v1 + 2584));
    seq_printf(a1, "%24s: %u\n", "msa_ready_req", *(_DWORD *)(v1 + 2588));
    seq_printf(a1, "%24s: %u\n", "msa_ready_resp", *(_DWORD *)(v1 + 2592));
    seq_printf(a1, "%24s: %u\n", "msa_ready_err", *(_DWORD *)(v1 + 2596));
    seq_printf(a1, "%24s: %u\n", "msa_ready_ind", *(_DWORD *)(v1 + 2600));
    seq_write(a1, "\n<------------------ Rejuvenate stats ------------------->\n", 59);
    seq_printf(a1, "%24s: %u\n", "rejuvenate_ind", *(_DWORD *)(v1 + 2656));
    seq_printf(a1, "%24s: %u\n", "rejuvenate_ack_req", *(_DWORD *)(v1 + 2660));
    seq_printf(a1, "%24s: %u\n", "rejuvenate_ack_resp", *(_DWORD *)(v1 + 2664));
    seq_printf(a1, "%24s: %u\n", "rejuvenate_ack_err", *(_DWORD *)(v1 + 2668));
    if ( *(_DWORD *)(v1 + 2656) )
    {
      seq_write(a1, "\n<---------------- Rejuvenate Info ----------------->\n", 54);
      seq_printf(a1, "Number of Rejuvenations: %u\n", *(_DWORD *)(v1 + 2656));
      seq_printf(a1, "Cause for Rejuvenation: 0x%x\n", *(unsigned __int8 *)(v1 + 2979));
      seq_printf(a1, "Requesting Sub-System: 0x%x\n", *(unsigned __int8 *)(v1 + 2980));
      seq_printf(a1, "Line Number: %u\n", *(unsigned __int16 *)(v1 + 2982));
      seq_printf(a1, "Function Name: %s\n", (const char *)(v1 + 3120));
    }
  }
  seq_write(a1, "\n<------------------ IRQ stats ------------------->\n", 52);
  seq_printf(a1, "%4s %4s %8s %8s %8s %8s\n", "CE_ID", "IRQ", "Request", "Free", "Enable", "Disable");
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    0,
    *(_DWORD *)(v1 + 348),
    *(_DWORD *)(v1 + 2316),
    *(_DWORD *)(v1 + 2320),
    *(_DWORD *)(v1 + 2324),
    *(_DWORD *)(v1 + 2328));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    1,
    *(_DWORD *)(v1 + 352),
    *(_DWORD *)(v1 + 2332),
    *(_DWORD *)(v1 + 2336),
    *(_DWORD *)(v1 + 2340),
    *(_DWORD *)(v1 + 2344));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    2,
    *(_DWORD *)(v1 + 356),
    *(_DWORD *)(v1 + 2348),
    *(_DWORD *)(v1 + 2352),
    *(_DWORD *)(v1 + 2356),
    *(_DWORD *)(v1 + 2360));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    3,
    *(_DWORD *)(v1 + 360),
    *(_DWORD *)(v1 + 2364),
    *(_DWORD *)(v1 + 2368),
    *(_DWORD *)(v1 + 2372),
    *(_DWORD *)(v1 + 2376));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    4,
    *(_DWORD *)(v1 + 364),
    *(_DWORD *)(v1 + 2380),
    *(_DWORD *)(v1 + 2384),
    *(_DWORD *)(v1 + 2388),
    *(_DWORD *)(v1 + 2392));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    5,
    *(_DWORD *)(v1 + 368),
    *(_DWORD *)(v1 + 2396),
    *(_DWORD *)(v1 + 2400),
    *(_DWORD *)(v1 + 2404),
    *(_DWORD *)(v1 + 2408));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    6,
    *(_DWORD *)(v1 + 372),
    *(_DWORD *)(v1 + 2412),
    *(_DWORD *)(v1 + 2416),
    *(_DWORD *)(v1 + 2420),
    *(_DWORD *)(v1 + 2424));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    7,
    *(_DWORD *)(v1 + 376),
    *(_DWORD *)(v1 + 2428),
    *(_DWORD *)(v1 + 2432),
    *(_DWORD *)(v1 + 2436),
    *(_DWORD *)(v1 + 2440));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    8,
    *(_DWORD *)(v1 + 380),
    *(_DWORD *)(v1 + 2444),
    *(_DWORD *)(v1 + 2448),
    *(_DWORD *)(v1 + 2452),
    *(_DWORD *)(v1 + 2456));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    9,
    *(_DWORD *)(v1 + 384),
    *(_DWORD *)(v1 + 2460),
    *(_DWORD *)(v1 + 2464),
    *(_DWORD *)(v1 + 2468),
    *(_DWORD *)(v1 + 2472));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    10,
    *(_DWORD *)(v1 + 388),
    *(_DWORD *)(v1 + 2476),
    *(_DWORD *)(v1 + 2480),
    *(_DWORD *)(v1 + 2484),
    *(_DWORD *)(v1 + 2488));
  seq_printf(
    a1,
    "%4d: %4u %8u %8u %8u %8u\n",
    11,
    *(_DWORD *)(v1 + 392),
    *(_DWORD *)(v1 + 2492),
    *(_DWORD *)(v1 + 2496),
    *(_DWORD *)(v1 + 2500),
    *(_DWORD *)(v1 + 2504));
  if ( (*(_QWORD *)(v1 + 1832) & 4) != 0 )
  {
    seq_write(a1, "\n<---------------- FW Capability ----------------->\n", 52);
    seq_printf(a1, "Chip ID: 0x%x\n", *(_DWORD *)(v1 + 1840));
    seq_printf(a1, "Chip family: 0x%x\n", *(_DWORD *)(v1 + 1844));
    seq_printf(a1, "Board ID: 0x%x\n", *(_DWORD *)(v1 + 1848));
    seq_printf(a1, "SOC Info: 0x%x\n", *(_DWORD *)(v1 + 1852));
    seq_printf(a1, "Firmware Version: 0x%x\n", *(_DWORD *)(v1 + 1856));
    seq_printf(a1, "Firmware Build Timestamp: %s\n", (const char *)(v1 + 1860));
    seq_printf(a1, "Firmware Build ID: %s\n", (const char *)(v1 + 1896));
    seq_printf(a1, "RD card chain cap: %d\n", *(_DWORD *)(v1 + 6100));
    seq_printf(a1, "PHY HE channel width cap: %d\n", *(_DWORD *)(v1 + 6104));
    seq_printf(a1, "PHY QAM cap: %d\n", *(_DWORD *)(v1 + 6108));
  }
  seq_write(a1, "\n<----------------- Events stats ------------------->\n", 54);
  seq_printf(a1, "%24s %16s %16s\n", "Events", "Posted", "Processed");
  v3 = (const char *)icnss_driver_event_to_str(0);
  seq_printf(a1, "%24s %16u %16u\n", v3, *(_DWORD *)(v1 + 2156), *(_DWORD *)(v1 + 2160));
  v4 = (const char *)icnss_driver_event_to_str(1);
  seq_printf(a1, "%24s %16u %16u\n", v4, *(_DWORD *)(v1 + 2164), *(_DWORD *)(v1 + 2168));
  v5 = (const char *)icnss_driver_event_to_str(2);
  seq_printf(a1, "%24s %16u %16u\n", v5, *(_DWORD *)(v1 + 2172), *(_DWORD *)(v1 + 2176));
  v6 = (const char *)icnss_driver_event_to_str(3);
  seq_printf(a1, "%24s %16u %16u\n", v6, *(_DWORD *)(v1 + 2180), *(_DWORD *)(v1 + 2184));
  v7 = (const char *)icnss_driver_event_to_str(4);
  seq_printf(a1, "%24s %16u %16u\n", v7, *(_DWORD *)(v1 + 2188), *(_DWORD *)(v1 + 2192));
  v8 = (const char *)icnss_driver_event_to_str(5);
  seq_printf(a1, "%24s %16u %16u\n", v8, *(_DWORD *)(v1 + 2196), *(_DWORD *)(v1 + 2200));
  v9 = (const char *)icnss_driver_event_to_str(6);
  seq_printf(a1, "%24s %16u %16u\n", v9, *(_DWORD *)(v1 + 2204), *(_DWORD *)(v1 + 2208));
  v10 = (const char *)icnss_driver_event_to_str(7);
  seq_printf(a1, "%24s %16u %16u\n", v10, *(_DWORD *)(v1 + 2212), *(_DWORD *)(v1 + 2216));
  v11 = (const char *)icnss_driver_event_to_str(8);
  seq_printf(a1, "%24s %16u %16u\n", v11, *(_DWORD *)(v1 + 2220), *(_DWORD *)(v1 + 2224));
  v12 = (const char *)icnss_driver_event_to_str(9);
  seq_printf(a1, "%24s %16u %16u\n", v12, *(_DWORD *)(v1 + 2228), *(_DWORD *)(v1 + 2232));
  v13 = (const char *)icnss_driver_event_to_str(10);
  seq_printf(a1, "%24s %16u %16u\n", v13, *(_DWORD *)(v1 + 2236), *(_DWORD *)(v1 + 2240));
  v14 = (const char *)icnss_driver_event_to_str(11);
  seq_printf(a1, "%24s %16u %16u\n", v14, *(_DWORD *)(v1 + 2244), *(_DWORD *)(v1 + 2248));
  v15 = (const char *)icnss_driver_event_to_str(12);
  seq_printf(a1, "%24s %16u %16u\n", v15, *(_DWORD *)(v1 + 2252), *(_DWORD *)(v1 + 2256));
  v16 = (const char *)icnss_driver_event_to_str(13);
  seq_printf(a1, "%24s %16u %16u\n", v16, *(_DWORD *)(v1 + 2260), *(_DWORD *)(v1 + 2264));
  v17 = (const char *)icnss_driver_event_to_str(14);
  seq_printf(a1, "%24s %16u %16u\n", v17, *(_DWORD *)(v1 + 2268), *(_DWORD *)(v1 + 2272));
  v18 = (const char *)icnss_driver_event_to_str(15);
  seq_printf(a1, "%24s %16u %16u\n", v18, *(_DWORD *)(v1 + 2276), *(_DWORD *)(v1 + 2280));
  v19 = (const char *)icnss_driver_event_to_str(16);
  seq_printf(a1, "%24s %16u %16u\n", v19, *(_DWORD *)(v1 + 2284), *(_DWORD *)(v1 + 2288));
  v20 = (const char *)icnss_driver_event_to_str(17);
  seq_printf(a1, "%24s %16u %16u\n", v20, *(_DWORD *)(v1 + 2292), *(_DWORD *)(v1 + 2296));
  seq_printf(
    a1,
    "\nSerial Number: 0x%llx",
    *(unsigned int *)(v1 + 6132) | ((unsigned __int64)*(unsigned __int16 *)(v1 + 6128) << 32));
  seq_printf(a1, "\nState: 0x%lx(", *(_QWORD *)(v1 + 1832));
  v21 = *(_QWORD *)(v1 + 1832);
  if ( v21 )
  {
    v22 = 0;
    v23 = 0;
    do
    {
      if ( (v21 & 1) != 0 )
      {
        if ( v22 )
          seq_write(a1, " | ", 3);
        ++v22;
        switch ( v23 )
        {
          case 0:
            v24 = "FW CONN";
            goto LABEL_39;
          case 1:
            v24 = "POWER ON";
            goto LABEL_32;
          case 2:
            v24 = "FW READY";
LABEL_32:
            v25 = a1;
            v26 = 8;
            goto LABEL_10;
          case 3:
            v24 = "DRIVER PROBED";
            goto LABEL_9;
          case 4:
            v24 = "FW TEST MODE";
            goto LABEL_22;
          case 5:
            v24 = "PM SUSPEND";
            goto LABEL_36;
          case 6:
            v24 = "PM SUSPEND NOIRQ";
            goto LABEL_41;
          case 7:
            v24 = "SSR REGISTERED";
            goto LABEL_45;
          case 8:
            v24 = "PDR REGISTERED";
            goto LABEL_45;
          case 9:
            v24 = "PD RESTART";
            goto LABEL_36;
          case 10:
            v24 = "WLAN FW EXISTS";
            goto LABEL_45;
          case 11:
            v24 = "SHUTDOWN DONE";
            goto LABEL_9;
          case 12:
            v24 = "HOST TRIGGERED PDR";
            v25 = a1;
            v26 = 18;
            goto LABEL_10;
          case 13:
            v24 = "FW DOWN";
LABEL_39:
            v25 = a1;
            v26 = 7;
            goto LABEL_10;
          case 14:
            v24 = "DRIVER UNLOADING";
LABEL_41:
            v25 = a1;
            v26 = 16;
            goto LABEL_10;
          case 15:
            v24 = "FW REJUVENATE";
            goto LABEL_9;
          case 16:
            v24 = "MODE ON DONE";
LABEL_22:
            v25 = a1;
            v26 = 12;
            goto LABEL_10;
          case 17:
            v24 = "BLOCK SHUTDOWN";
            goto LABEL_45;
          case 18:
            v24 = "PDR TRIGGERED";
            goto LABEL_9;
          case 19:
            v24 = "IMS_CONNECTED";
            goto LABEL_9;
          case 20:
            v24 = "DEL SERVER";
LABEL_36:
            v25 = a1;
            v26 = 10;
            goto LABEL_10;
          case 21:
            v24 = "COLD BOOT CALIBRATION";
            v25 = a1;
            v26 = 21;
            goto LABEL_10;
          case 22:
            v24 = "DMS_CONNECTED";
LABEL_9:
            v25 = a1;
            v26 = 13;
            goto LABEL_10;
          case 23:
            v24 = "SLATE SSR REGISTERED";
            v25 = a1;
            v26 = 20;
            goto LABEL_10;
          case 24:
            v24 = "ICNSS SLATE UP";
LABEL_45:
            v25 = a1;
            v26 = 14;
            goto LABEL_10;
          case 25:
            v24 = "ICNSS SLATE READY";
            v25 = a1;
            v26 = 17;
            goto LABEL_10;
          case 26:
            v24 = "ICNSS LOW POWER";
            v25 = a1;
            v26 = 15;
            goto LABEL_10;
          case 27:
            v24 = "ICNSS_SOC_WAKE_DONE";
            v25 = a1;
            v26 = 19;
LABEL_10:
            seq_write(v25, v24, v26);
            break;
          case 28:
            seq_write(a1, "ICNSS_REBOOT_REGISTERED", 23);
            goto LABEL_50;
          default:
LABEL_50:
            seq_printf(a1, "UNKNOWN-%d", v23);
            break;
        }
      }
      v27 = v21 > 1;
      ++v23;
      v21 >>= 1;
    }
    while ( v27 );
  }
  seq_write(a1, ")\n", 2);
  return 0;
}
