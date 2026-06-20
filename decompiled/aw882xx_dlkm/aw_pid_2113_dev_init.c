__int64 __fastcall aw_pid_2113_dev_init(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v3; // x0
  __int64 result; // x0

  *(_DWORD *)(a1 + 28) = 128;
  qmemcpy((void *)(a1 + 128), "aw882xx_pid_2113_monitor.bin", 28);
  *(_DWORD *)(a1 + 56) = 48;
  *(_QWORD *)(a1 + 1176) = aw_6_0P125_reg_val_to_db;
  *(_QWORD *)(a1 + 1184) = aw_6_0P125_db_val_to_reg;
  *(_QWORD *)(a1 + 1200) = aw_pid_2113_reg_force_set;
  *(_QWORD *)(a1 + 1208) = aw_pid_2113_frcset_check;
  *(_QWORD *)(a1 + 400) = "btn 2113 uls hmute";
  *(_QWORD *)(a1 + 408) = 0xFFFFBFFF00000004LL;
  *(_DWORD *)(a1 + 516) = 80;
  *(_DWORD *)(a1 + 524) = 0x2000;
  *(_DWORD *)(a1 + 520) = 1000;
  *(_QWORD *)(a1 + 416) = 0x4000;
  *(_QWORD *)(a1 + 424) = 0xFFFFFFBF00000008LL;
  *(_QWORD *)(a1 + 432) = 64;
  *(_QWORD *)(a1 + 444) = 0xFFFFFC0000000078LL;
  *(_QWORD *)(a1 + 452) = 0x7C00000000LL;
  *(_QWORD *)(a1 + 460) = 4294966272LL;
  *(_QWORD *)(a1 + 468) = 0xFFFF03FFFFFFFDFFLL;
  *(_QWORD *)(a1 + 476) = 0x7900000001LL;
  *(_QWORD *)(a1 + 484) = 4294966272LL;
  *(_QWORD *)(a1 + 492) = 0xFFFFFC000000007DLL;
  *(_QWORD *)(a1 + 500) = 0xFFFFFDFF00000000LL;
  *(_QWORD *)(a1 + 508) = 0x1FFFF03FFLL;
  *(_QWORD *)(a1 + 548) = 0xFFFFFFBF00000054LL;
  *(_QWORD *)(a1 + 556) = 0x4000000000LL;
  *(_DWORD *)(a1 + 612) = 720;
  *(_QWORD *)(a1 + 984) = 32;
  *(_QWORD *)(a1 + 976) = 0xFFFFFFDF0000003CLL;
  v2 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
  v3 = *(_QWORD *)(a1 + 120);
  *(_QWORD *)(a1 + 968) = "btn 2113 bop";
  if ( *((_DWORD *)v2 - 1) != -1860236611 )
    __break(0x8228u);
  v2(v3, 115, 7488);
  result = usleep_range_state(3000, 3010, 2);
  *(_QWORD *)(a1 + 1008) = 0x4000;
  *(_QWORD *)(a1 + 252) = 0x800000000LL;
  *(_QWORD *)(a1 + 244) = 0xFFF700000014LL;
  *(_QWORD *)(a1 + 1000) = 0xFFFFBFFF00000014LL;
  *(_QWORD *)(a1 + 992) = "btn 2113 dither";
  *(_DWORD *)(a1 + 1024) = 255;
  return result;
}
