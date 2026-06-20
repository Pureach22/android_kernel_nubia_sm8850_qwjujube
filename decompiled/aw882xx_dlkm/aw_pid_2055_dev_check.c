__int64 __fastcall aw_pid_2055_dev_check(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v2; // x26
  _QWORD *v3; // x23
  __int64 v5; // x0
  _DWORD *v6; // x8
  void (__fastcall *v7)(__int64, __int64, int *); // x8
  __int64 v8; // x0
  bool v9; // zf
  void (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 result; // x0
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 128) = *(_QWORD *)"aw882xx_pid_2055_monitor.bin";
  v1 = a1 + 128;
  v2 = (_QWORD *)(a1 + 548);
  *(_DWORD *)(a1 + 28) = 125;
  v3 = (_QWORD *)(a1 + 556);
  *(_DWORD *)(a1 + 152) = 1852400174;
  v5 = *(_QWORD *)(a1 + 120);
  *(_DWORD *)(v1 - 72) = 48;
  *(_QWORD *)(v1 + 1048) = aw_6_0P125_reg_val_to_db;
  *(_QWORD *)(v1 + 1056) = aw_6_0P125_db_val_to_reg;
  *(_QWORD *)(v1 + 296) = 0xFFFFBFFF00000006LL;
  *(_QWORD *)(v1 + 304) = 0x4000;
  *(_DWORD *)(v1 + 484) = 720;
  v13 = 0;
  qmemcpy((void *)(v1 + 8), "pid_2055_monitor", 16);
  *v2 = 0xFFFFFFFB00000052LL;
  *v3 = 0x400000000LL;
  *(_DWORD *)(v1 + 280) = 255;
  *(_QWORD *)(v1 + 880) = 0x4000;
  *(_QWORD *)(v1 + 848) = 0xFFFFFFEF0000003CLL;
  *(_QWORD *)(v1 + 856) = 16;
  *(_QWORD *)(v1 + 840) = "btn 2055 bop";
  *(_QWORD *)(v1 + 864) = "btn 2055 dither";
  *(_DWORD *)(v1 + 896) = 255;
  *(_QWORD *)(v1 + 872) = 0xFFFFBFFF00000017LL;
  *(_DWORD *)(v1 + 112) = 0x8000;
  *(_QWORD *)(v1 + 88) = 0x7800000002LL;
  *(_QWORD *)(v1 + 96) = 0x8000FFFF7FFFLL;
  *(_QWORD *)(v1 + 104) = 0xFFFF7FFF00000079LL;
  v6 = *(_DWORD **)(v1 + 1024);
  if ( *(v6 - 1) != -1860236611 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, __int64))v6)(v5, 0, 21930);
  usleep_range_state(1000, 1100, 2);
  v7 = *(void (__fastcall **)(__int64, __int64, int *))(v1 + 1032);
  v8 = *(_QWORD *)(v1 - 8);
  if ( *((_DWORD *)v7 - 1) != 1983062130 )
    __break(0x8228u);
  v7(v8, 35, &v13);
  *(_DWORD *)(v1 - 100) = 125;
  *(_QWORD *)(v1 + 88) = 0x7800000002LL;
  *(_DWORD *)(v1 - 72) = 48;
  *(_QWORD *)(v1 + 1048) = aw_6_0P125_reg_val_to_db;
  *(_QWORD *)(v1 + 1056) = aw_6_0P125_db_val_to_reg;
  qmemcpy((void *)v1, "aw882xx_pid_2055_monitor.bin", 28);
  *(_QWORD *)(v1 + 296) = 0xFFFFBFFF00000006LL;
  *(_QWORD *)(v1 + 304) = 0x4000;
  *(_DWORD *)(v1 + 484) = 720;
  *(_DWORD *)(v1 + 280) = 255;
  *(_QWORD *)(v1 + 880) = 0x4000;
  *v2 = 0xFFFFFFFB00000052LL;
  *v3 = 0x400000000LL;
  *(_QWORD *)(v1 + 864) = "btn 2055 dither";
  *(_DWORD *)(v1 + 896) = 255;
  *(_QWORD *)(v1 + 848) = 0xFFFFFFEF0000003CLL;
  *(_QWORD *)(v1 + 856) = 16;
  *(_QWORD *)(v1 + 840) = "btn 2055 bop";
  *(_QWORD *)(v1 + 96) = 0x8000FFFF7FFFLL;
  *(_QWORD *)(v1 + 104) = 0xFFFF7FFF00000079LL;
  *(_QWORD *)(v1 + 872) = 0xFFFFBFFF00000017LL;
  v9 = v13 == 26376;
  *(_DWORD *)(v1 + 112) = 0x8000;
  if ( v9 )
  {
    *(_DWORD *)(a1 + 4) = 132442;
    *(_DWORD *)(a1 + 312) = 255;
    qmemcpy((void *)v1, "aw882xx_pid_2055a_monitor.bin", 29);
    *(_DWORD *)(a1 + 564) = 255;
    *(_DWORD *)(a1 + 576) = 255;
  }
  usleep_range_state(2000, 2010, 2);
  v10 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
  v11 = *(_QWORD *)(a1 + 120);
  if ( *((_DWORD *)v10 - 1) != -1860236611 )
    __break(0x8228u);
  v10(v11, 115, 7488);
  result = usleep_range_state(3000, 3010, 2);
  _ReadStatusReg(SP_EL0);
  return result;
}
