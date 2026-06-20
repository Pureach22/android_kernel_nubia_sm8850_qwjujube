__int64 __fastcall aw_pid_2013_dev_init(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64, unsigned int *); // x8
  __int64 v3; // x0
  int v4; // w10
  int v5; // w9
  __int64 *v6; // x8
  __int64 v7; // x1
  void *v8; // x0
  __int64 *v9; // x8
  __int64 result; // x0
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 28) = 125;
  *(_DWORD *)(a1 + 56) = 48;
  *(_QWORD *)(a1 + 1176) = aw_6_0P125_reg_val_to_db;
  *(_QWORD *)(a1 + 1184) = aw_6_0P125_db_val_to_reg;
  qmemcpy((void *)(a1 + 128), "aw882xx_pid_2013_monitor.bin", 28);
  *(_QWORD *)(a1 + 1008) = 0x4000;
  *(_QWORD *)(a1 + 424) = 0xFFFFBFFF00000006LL;
  *(_QWORD *)(a1 + 432) = 0x4000;
  *(_QWORD *)(a1 + 516) = 0x3E800000050LL;
  *(_DWORD *)(a1 + 444) = 120;
  *(_DWORD *)(a1 + 448) = -1024;
  *(_QWORD *)(a1 + 468) = 0xFFFF03FFFFFFFDFFLL;
  *(_DWORD *)(a1 + 524) = 0x2000;
  *(_QWORD *)(a1 + 480) = 0xFFFFFC0000000079LL;
  *(_DWORD *)(a1 + 476) = 1;
  *(_DWORD *)(a1 + 512) = 1;
  *(_QWORD *)(a1 + 260) = 0xFFFFFF7F00000004LL;
  *(_DWORD *)(a1 + 408) = 255;
  *(_DWORD *)(a1 + 456) = 255;
  *(_QWORD *)(a1 + 276) = 0xFFFFFFCF00000061LL;
  *(_QWORD *)(a1 + 284) = 16;
  *(_DWORD *)(a1 + 492) = 255;
  *(_QWORD *)(a1 + 504) = 0xFFFF03FFFFFFFDFFLL;
  *(_QWORD *)(a1 + 548) = 0xFFFFFFFB00000055LL;
  *(_QWORD *)(a1 + 556) = 0x400000000LL;
  *(_QWORD *)(a1 + 612) = 720;
  *(_DWORD *)(a1 + 268) = 0;
  *(_DWORD *)(a1 + 976) = 255;
  *(_QWORD *)(a1 + 1000) = 0xFFFFBFFF00000012LL;
  *(_QWORD *)(a1 + 992) = "btn 2013 dither";
  *(_DWORD *)(a1 + 1024) = 255;
  *(_QWORD *)(a1 + 216) = 0x7800000001LL;
  *(_QWORD *)(a1 + 224) = 0x8000FFFF7FFFLL;
  v2 = *(void (__fastcall **)(__int64, __int64, unsigned int *))(a1 + 1160);
  v3 = *(_QWORD *)(a1 + 120);
  v11 = 0;
  if ( *((_DWORD *)v2 - 1) != 1983062130 )
    __break(0x8228u);
  v2(v3, 122, &v11);
  v4 = v11 & 0x1C00;
  v5 = ~(v11 >> 13) & 7;
  if ( v4 == 7168 || !v5 )
  {
    v9 = *(__int64 **)(a1 + 112);
    *(_DWORD *)(a1 + 260) = 255;
    *(_DWORD *)(a1 + 276) = 255;
    v7 = v9[14];
    if ( v4 == 7168 && v5 )
    {
      if ( !v7 )
        v7 = *v9;
      v8 = &unk_27553;
    }
    else
    {
      if ( !v7 )
        v7 = *v9;
      v8 = &unk_25EF7;
    }
  }
  else
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = v6[14];
    if ( !v7 )
      v7 = *v6;
    v8 = &unk_23334;
  }
  result = printk(v8, v7, "aw_pid_2013_efver_check");
  _ReadStatusReg(SP_EL0);
  return result;
}
