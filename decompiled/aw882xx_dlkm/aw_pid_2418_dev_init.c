__int64 __fastcall aw_pid_2418_dev_init(__int64 result)
{
  *(_DWORD *)(result + 28) = 128;
  *(_QWORD *)(result + 1064) = "btn 2418 mpd";
  qmemcpy((void *)(result + 128), "aw882xx_pid_2418_monitor.bin", 28);
  *(_QWORD *)(result + 1096) = 0xFFFFFF0F00000052LL;
  *(_QWORD *)(result + 1104) = 80;
  *(_QWORD *)(result + 1088) = "btn 2418 dsmzth";
  *(_QWORD *)(result + 1216) = aw_pid_2418_get_voltage_offset;
  *(_QWORD *)(result + 424) = 0xFFFFFFDF00000008LL;
  *(_QWORD *)(result + 432) = 32;
  *(_QWORD *)(result + 1176) = aw_direct_reg_val_to_db;
  *(_QWORD *)(result + 1184) = aw_direct_db_val_to_reg;
  *(_QWORD *)(result + 564) = 0x17B100000020LL;
  *(_DWORD *)(result + 572) = 1023;
  *(_QWORD *)(result + 1048) = 0xFFFFBFFF00000005LL;
  *(_QWORD *)(result + 1056) = 0x4000;
  *(_QWORD *)(result + 576) = 0xFFFFFDFF00000021LL;
  *(_QWORD *)(result + 1040) = "btn 2418 psm";
  *(_DWORD *)(result + 584) = 64512;
  *(_QWORD *)(result + 1072) = 0xFFFF7FFF00000005LL;
  *(_QWORD *)(result + 1000) = 0xFFFF7FFF00000025LL;
  *(_QWORD *)(result + 1080) = 0x8000;
  *(_QWORD *)(result + 1008) = 0x8000;
  *(_QWORD *)(result + 992) = "btn 2418 dither";
  *(_QWORD *)(result + 548) = 0xFFFFDFFF00000025LL;
  *(_QWORD *)(result + 556) = 0x200000000000LL;
  *(_WORD *)(result + 1112) = 11568;
  *(_QWORD *)(result + 588) = 0xFFFF07FF00000042LL;
  *(_QWORD *)(result + 1024) = 0xFFFFFFFE00000052LL;
  *(_QWORD *)(result + 1032) = 1;
  *(_QWORD *)(result + 1016) = "btn 2418 noise gate";
  *(_QWORD *)(result + 216) = 0x7600000001LL;
  *(_QWORD *)(result + 224) = 0x8000FFFF7FFFLL;
  return result;
}
