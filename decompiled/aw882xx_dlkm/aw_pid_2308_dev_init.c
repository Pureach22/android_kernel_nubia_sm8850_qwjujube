__int64 __fastcall aw_pid_2308_dev_init(__int64 result)
{
  *(_DWORD *)(result + 28) = 128;
  qmemcpy((void *)(result + 128), "aw882xx_pid_2308_monitor.bin", 28);
  *(_QWORD *)(result + 1216) = aw_pid_2308_get_voltage_offset;
  *(_QWORD *)(result + 1176) = aw_direct_reg_val_to_db;
  *(_QWORD *)(result + 1184) = aw_direct_db_val_to_reg;
  *(_WORD *)(result + 1112) = 11832;
  *(_QWORD *)(result + 1048) = 0xFFFFBFFF00000005LL;
  *(_QWORD *)(result + 1056) = 0x4000;
  *(_QWORD *)(result + 1040) = "btn 2308 psm";
  *(_QWORD *)(result + 1072) = 0xFFFF7FFF00000005LL;
  *(_QWORD *)(result + 1080) = 0x8000;
  *(_QWORD *)(result + 1064) = "btn 2308 mpd";
  *(_QWORD *)(result + 1096) = 0xFFFFFF0F0000005ELL;
  *(_QWORD *)(result + 1104) = 80;
  *(_QWORD *)(result + 1088) = "btn 2308 dsmzth";
  return result;
}
