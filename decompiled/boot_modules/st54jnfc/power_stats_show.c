__int64 __fastcall power_stats_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x0
  int v26; // w10
  __int64 v27; // x4
  __int64 v28; // x9
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x11

  v3 = *(_QWORD *)(a1 + 152);
  mutex_lock(v3 + 72);
  v5 = *(_QWORD *)(v3 + 680);
  *(_DWORD *)(v3 + 752) = *(_DWORD *)(v3 + 536);
  v6 = *(_QWORD *)(v3 + 688);
  *(_QWORD *)(v3 + 888) = v5;
  v7 = *(_QWORD *)(v3 + 696);
  *(_QWORD *)(v3 + 896) = v6;
  v8 = *(_QWORD *)(v3 + 704);
  *(_QWORD *)(v3 + 904) = v7;
  v9 = *(_QWORD *)(v3 + 648);
  *(_QWORD *)(v3 + 912) = v8;
  v10 = *(_QWORD *)(v3 + 656);
  *(_QWORD *)(v3 + 856) = v9;
  v11 = *(_QWORD *)(v3 + 664);
  *(_QWORD *)(v3 + 864) = v10;
  v12 = *(_QWORD *)(v3 + 672);
  *(_QWORD *)(v3 + 872) = v11;
  v13 = *(_QWORD *)(v3 + 640);
  *(_QWORD *)(v3 + 880) = v12;
  v14 = *(_QWORD *)(v3 + 632);
  *(_QWORD *)(v3 + 848) = v13;
  v15 = *(_QWORD *)(v3 + 624);
  *(_QWORD *)(v3 + 840) = v14;
  v16 = *(_QWORD *)(v3 + 616);
  *(_QWORD *)(v3 + 832) = v15;
  v17 = *(_QWORD *)(v3 + 608);
  *(_QWORD *)(v3 + 824) = v16;
  v18 = *(_QWORD *)(v3 + 600);
  *(_QWORD *)(v3 + 816) = v17;
  v19 = *(_QWORD *)(v3 + 592);
  *(_QWORD *)(v3 + 808) = v18;
  v20 = *(_QWORD *)(v3 + 584);
  *(_QWORD *)(v3 + 800) = v19;
  v21 = *(_QWORD *)(v3 + 576);
  *(_QWORD *)(v3 + 792) = v20;
  v22 = *(_QWORD *)(v3 + 568);
  *(_QWORD *)(v3 + 784) = v21;
  v23 = *(_QWORD *)(v3 + 560);
  *(_QWORD *)(v3 + 776) = v22;
  v24 = *(_QWORD *)(v3 + 552);
  *(_QWORD *)(v3 + 768) = v23;
  *(_QWORD *)(v3 + 760) = v24;
  mutex_unlock(v3 + 72);
  v25 = ktime_get_with_offset(1);
  v26 = *(_DWORD *)(v3 + 752);
  v27 = *(_QWORD *)(v3 + 768);
  v28 = v25 / 1000000;
  if ( v26 == 1 )
  {
    v29 = *(_QWORD *)(v3 + 800) + v28 - *(_QWORD *)(v3 + 808);
    goto LABEL_7;
  }
  if ( !v26 )
  {
    v29 = *(_QWORD *)(v3 + 800);
    v27 = v27 + v28 - *(_QWORD *)(v3 + 776);
LABEL_7:
    v31 = *(_QWORD *)(v3 + 832);
    v30 = *(_QWORD *)(v3 + 840);
    return (int)scnprintf(
                  a3,
                  4096,
                  "NFC subsystem\n"
                  "Idle mode:\n"
                  "\tCumulative count: 0x%llx\n"
                  "\tCumulative duration msec: 0x%llx\n"
                  "\tLast entry timestamp msec: 0x%llx\n"
                  "\tLast exit timestamp msec: 0x%llx\n"
                  "Active mode:\n"
                  "\tCumulative count: 0x%llx\n"
                  "\tCumulative duration msec: 0x%llx\n"
                  "\tLast entry timestamp msec: 0x%llx\n"
                  "\tLast exit timestamp msec: 0x%llx\n"
                  "Active Reader/Writer mode:\n"
                  "\tCumulative count: 0x%llx\n"
                  "\tCumulative duration msec: 0x%llx\n"
                  "\tLast entry timestamp msec: 0x%llx\n"
                  "\tLast exit timestamp msec: 0x%llx\n"
                  "\n"
                  "Error transition header --> payload state machine: 0x%llx\n"
                  "Error transition from an Active state when not in Idle state: 0x%llx\n"
                  "Error transition from Idle state to Idle state: 0x%llx\n"
                  "Warning transition from Active Reader/Writer state to Idle state: 0x%llx\n"
                  "Error transition from Active state to Active state: 0x%llx\n"
                  "Error transition from Idle state to Active state with notification: 0x%llx\n"
                  "Error transition from Active Reader/Writer state to Active Reader/Writer state: 0x%llx\n"
                  "Error transition from Idle state to Active Reader/Writer state with notification: 0x%llx\n"
                  "\n"
                  "Total uptime: 0x%llx Cumulative modes time: 0x%llx\n",
                  *(_QWORD *)(v3 + 760),
                  v27,
                  *(_QWORD *)(v3 + 776),
                  *(_QWORD *)(v3 + 784),
                  *(_QWORD *)(v3 + 792),
                  v29,
                  *(_QWORD *)(v3 + 808),
                  *(_QWORD *)(v3 + 816),
                  *(_QWORD *)(v3 + 824),
                  v31,
                  v30,
                  *(_QWORD *)(v3 + 848),
                  *(_QWORD *)(v3 + 856),
                  *(_QWORD *)(v3 + 864),
                  *(_QWORD *)(v3 + 872),
                  *(_QWORD *)(v3 + 880),
                  *(_QWORD *)(v3 + 888),
                  *(_QWORD *)(v3 + 896),
                  *(_QWORD *)(v3 + 904),
                  *(_QWORD *)(v3 + 912),
                  v28,
                  v27 + v31 + v29);
  }
  v29 = *(_QWORD *)(v3 + 800);
  if ( v26 != 2 )
    goto LABEL_7;
  v30 = *(_QWORD *)(v3 + 840);
  v31 = *(_QWORD *)(v3 + 832) + v28 - v30;
  return (int)scnprintf(
                a3,
                4096,
                "NFC subsystem\n"
                "Idle mode:\n"
                "\tCumulative count: 0x%llx\n"
                "\tCumulative duration msec: 0x%llx\n"
                "\tLast entry timestamp msec: 0x%llx\n"
                "\tLast exit timestamp msec: 0x%llx\n"
                "Active mode:\n"
                "\tCumulative count: 0x%llx\n"
                "\tCumulative duration msec: 0x%llx\n"
                "\tLast entry timestamp msec: 0x%llx\n"
                "\tLast exit timestamp msec: 0x%llx\n"
                "Active Reader/Writer mode:\n"
                "\tCumulative count: 0x%llx\n"
                "\tCumulative duration msec: 0x%llx\n"
                "\tLast entry timestamp msec: 0x%llx\n"
                "\tLast exit timestamp msec: 0x%llx\n"
                "\n"
                "Error transition header --> payload state machine: 0x%llx\n"
                "Error transition from an Active state when not in Idle state: 0x%llx\n"
                "Error transition from Idle state to Idle state: 0x%llx\n"
                "Warning transition from Active Reader/Writer state to Idle state: 0x%llx\n"
                "Error transition from Active state to Active state: 0x%llx\n"
                "Error transition from Idle state to Active state with notification: 0x%llx\n"
                "Error transition from Active Reader/Writer state to Active Reader/Writer state: 0x%llx\n"
                "Error transition from Idle state to Active Reader/Writer state with notification: 0x%llx\n"
                "\n"
                "Total uptime: 0x%llx Cumulative modes time: 0x%llx\n",
                *(_QWORD *)(v3 + 760),
                v27,
                *(_QWORD *)(v3 + 776),
                *(_QWORD *)(v3 + 784),
                *(_QWORD *)(v3 + 792),
                v29,
                *(_QWORD *)(v3 + 808),
                *(_QWORD *)(v3 + 816),
                *(_QWORD *)(v3 + 824),
                v31,
                v30,
                *(_QWORD *)(v3 + 848),
                *(_QWORD *)(v3 + 856),
                *(_QWORD *)(v3 + 864),
                *(_QWORD *)(v3 + 872),
                *(_QWORD *)(v3 + 880),
                *(_QWORD *)(v3 + 888),
                *(_QWORD *)(v3 + 896),
                *(_QWORD *)(v3 + 904),
                *(_QWORD *)(v3 + 912),
                v28,
                v27 + v31 + v29);
}
