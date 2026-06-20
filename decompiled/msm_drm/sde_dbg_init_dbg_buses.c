void *__fastcall sde_dbg_init_dbg_buses(unsigned int a1)
{
  void *v1; // x20
  int v2; // w21
  void *v3; // x22
  __int64 (__fastcall *v4)(); // x23
  __int64 (__fastcall *v5)(); // x24
  void *result; // x0

  if ( a1 >> 30 == 3 )
    v1 = &dbg_bus_sde_ver_c00;
  else
    v1 = &dbg_bus_sde;
  if ( a1 >> 30 == 3 )
    v2 = 25;
  else
    v2 = 24;
  if ( a1 >> 30 == 3 )
    v3 = &dbg_bus_sde_limited_ver_c00;
  else
    v3 = &dbg_bus_sde_limited;
  if ( a1 >> 30 == 3 )
    v4 = sde_dbg_sde_clear_test_point_ver_c00;
  else
    v4 = sde_dbg_sde_clear_test_point;
  qword_294590 = 0;
  if ( a1 >> 30 == 3 )
    v5 = sde_dbg_sde_read_test_point_ver_c00;
  else
    v5 = sde_dbg_sde_read_test_point;
  qword_294570 = 0;
  qword_294578 = 0;
  qword_294550 = 0;
  qword_294558 = 0;
  qword_294548 = 1;
  result = memset(&qword_294398, 0, 0x150u);
  dword_294390 = v2;
  dword_294394 = 22;
  qword_294388 = (__int64)"sde";
  qword_2943A8 = 4096;
  qword_2943E0 = (__int64)"vbif_rt";
  qword_2943E8 = 0xB00000002LL;
  qword_294408 = (__int64)&vbif_dbg_bus;
  qword_294410 = (__int64)&vbif_dbg_bus_limited;
  qword_294400 = 0x8000;
  qword_294420 = (__int64)sde_dbg_vbif_read_test_point;
  qword_294428 = (__int64)sde_dbg_vbif_clear_test_point;
  qword_294430 = (__int64)sde_dbg_vbif_disable_block;
  qword_294438 = (__int64)"dsi";
  qword_294490 = (__int64)"sde_rsc_wrapper";
  qword_294458 = 0x10000;
  qword_294460 = (__int64)&dsi_dbg_bus;
  qword_294478 = (__int64)sde_dbg_dsi_read_test_point;
  qword_294480 = (__int64)sde_dbg_cmn_clear_test_point;
  dword_294440 = 1;
  dword_294498 = 1;
  qword_2944B0 = 0x2000;
  qword_2944B8 = (__int64)&rsc_dbg_bus;
  qword_2944D0 = (__int64)sde_dbg_rsc_read_test_point;
  qword_2944D8 = (__int64)sde_dbg_cmn_clear_test_point;
  qword_294540 = (__int64)"dp_ahb";
  qword_294560 = 0x2000000;
  qword_294568 = (__int64)&dp_dbg_bus;
  qword_294580 = (__int64)sde_dbg_dp_read_test_point;
  qword_294588 = (__int64)sde_dbg_cmn_clear_test_point;
  qword_2944E8 = (__int64)"reg_dma";
  qword_2943B0 = (__int64)v1;
  qword_2943B8 = (__int64)v3;
  qword_294508 = 0x4000;
  qword_294510 = (__int64)&dbg_bus_lutdma;
  dword_2944F0 = 18;
  qword_2943C8 = (__int64)v5;
  qword_2943D0 = (__int64)v4;
  qword_294528 = (__int64)sde_dbg_lutdma_read_test_point;
  qword_294530 = (__int64)sde_dbg_cmn_clear_test_point;
  return result;
}
