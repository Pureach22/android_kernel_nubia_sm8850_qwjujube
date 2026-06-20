__int64 __fastcall cfg_parse(char *a1)
{
  unsigned int v2; // w20
  __int64 v3; // x26
  __int64 v4; // x21
  __int64 v5; // x28
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x21
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(80, 8, "%s: enter", "cfg_parse");
  if ( _cfg_global_store )
  {
    v2 = qdf_ini_parse(a1);
    if ( v2 )
      qdf_trace_msg(80, 2, "%s: Failed to parse *.ini file @ %s; status:%d", "cfg_ini_parse_to_store", a1, v2);
  }
  else
  {
    v11[0] = 0;
    v2 = cfg_store_alloc(a1, v11);
    if ( !v2 )
    {
      v3 = v11[0];
      *(__int64 *)((char *)&qword_20 + v11[0] + 4) = 0x1E0000000ALL;
      *(__int64 *)((char *)&qword_28 + v3 + 4) = 0x1400000005LL;
      *(__int16 *)((char *)&word_34 + v3) = 257;
      *(_DWORD *)((char *)&qword_38 + v3) = 40;
      *(_WORD *)((char *)&qword_38 + v3 + 4) = 257;
      *(__int16 *)((char *)&word_BC + v3) = 257;
      *(__int64 *)((char *)&qword_40 + v3) = 0x6E00000050LL;
      *(__int64 *)((char *)&qword_40 + v3 + 8) = 0x3C00000019LL;
      *(__int64 *)((char *)&qword_50 + v3) = 0x280000003CLL;
      *(__int64 *)((char *)&qword_50 + v3 + 8) = 40;
      *(__int64 *)((char *)&qword_60 + v3) = 0x100000014LL;
      *(int *)((char *)&dword_68 + v3) = 4;
      *(_UNKNOWN **)((char *)&off_18 + v3 + 4) = (_UNKNOWN *)0x300000005LL;
      *(__int64 *)((char *)&qword_70 + v3) = 0x280000006ELL;
      *(__int64 *)((char *)&qword_70 + v3 + 8) = 0x3200000064LL;
      *(int *)((char *)&dword_80 + v3) = 25;
      *(__int64 *)((char *)&qword_D4 + v3) = 0x10000EA60LL;
      *(__int64 *)((char *)&qword_88 + v3) = 0x10000001ELL;
      *(__int64 *)((char *)&qword_88 + v3 + 8) = 0;
      *(__int64 *)((char *)&qword_E4 + v3) = 0x271000000003LL;
      *(int *)((char *)&dword_EC + v3) = 60000;
      v4 = v3 + 665;
      *(__int64 *)((char *)&qword_A8 + v3) = 0x200000004LL;
      *(__int64 *)((char *)&qword_F4 + v3) = 0x3C00007530LL;
      *(__int64 *)((char *)&qword_B4 + v3) = 0xE100000000ALL;
      *(__int64 *)((char *)&qword_FC + v3) = 0x100000002LL;
      *(_QWORD *)(v3 + 260) = 1;
      *(_QWORD *)(v3 + 268) = 0x100000000LL;
      *(__int64 *)((char *)&qword_C0 + v3) = 0x60000001ELL;
      *(_QWORD *)(v3 + 276) = 0x80000001ELL;
      *(_QWORD *)(v3 + 284) = 0x20000000100LL;
      *(_QWORD *)(v3 + 292) = 0x20000000000008LL;
      *(_QWORD *)(v3 + 300) = 0x4000000040LL;
      *(__int64 *)((char *)&qword_CC + v3) = 0xA00000003LL;
      *(_QWORD *)(v3 + 308) = 0x300000008LL;
      *(__int64 *)((char *)&qword_320 + v3) = 0xA00000003LL;
      *(_QWORD *)(v3 + 316) = 0x200000003LL;
      *(_QWORD *)(v3 + 812) = 0;
      *(_QWORD *)(v3 + 324) = 0x100000000002LL;
      *(_QWORD *)(v3 + 332) = 0x100000001000LL;
      *(_QWORD *)(v3 + 340) = 0x100000001000LL;
      *(_QWORD *)(v3 + 828) = 0x100000000LL;
      *(_QWORD *)(v3 + 348) = 0x100000000400LL;
      *(_QWORD *)(v3 + 356) = 3;
      *(_QWORD *)(v3 + 364) = 0x6400000000LL;
      *(_QWORD *)(v3 + 372) = 0x100000001000LL;
      *(_QWORD *)(v3 + 380) = 0x100000001000LL;
      *(__int64 *)((char *)&qword_238 + v3) = 0x100000000400LL;
      *(_QWORD *)(v3 + 388) = 0x80000001000LL;
      *(_QWORD *)(v3 + 396) = 0x80000000800LL;
      *(_QWORD *)(v3 + 404) = 0x80000000800LL;
      *(_QWORD *)(v3 + 412) = 0x2000;
      *(_QWORD *)(v3 + 420) = 3000;
      *(__int64 *)((char *)&qword_230 + v3) = 0x80000001000LL;
      *(_QWORD *)(v3 + 428) = 0x10100000001LL;
      byte_1C8[v3] = 1;
      *(__int64 *)((char *)&qword_1B8 + v3) = 0;
      *(__int64 *)((char *)&qword_1B8 + v3 + 8) = 0x101010100000000LL;
      *(_QWORD *)(v3 + 460) = 0x20000000400LL;
      byte_36[v3] = 0;
      *(_QWORD *)(v3 + 468) = 0x100000000020LL;
      *(__int64 *)((char *)&qword_248 + v3) = 0xF0000000ALL;
      *(_QWORD *)(v3 + 476) = 0x40000000080LL;
      *((_BYTE *)&qword_38 + v3 + 6) = 0;
      *(_QWORD *)(v3 + 484) = 0x80000000100LL;
      *(_QWORD *)(v3 + 492) = 0x80000000800LL;
      *(_QWORD *)(v3 + 500) = 0x80000000800LL;
      *(__int64 *)((char *)&qword_250 + v3) = 0xBB800000800LL;
      *(_QWORD *)(v3 + 508) = 0x10000000080LL;
      *(__int64 *)((char *)&qword_220 + v3) = 0x40000000400LL;
      *(__int64 *)((char *)&qword_268 + v3) = 0x8000001000LL;
      *(__int64 *)((char *)&qword_228 + v3) = 0x4000000C000LL;
      *(int *)((char *)&dword_270 + v3) = 0x1000000;
      *(_QWORD *)(v3 + 628) = 0xA00000020LL;
      *(__int64 *)((char *)&qword_280 + v3) = 7;
      *(int *)((char *)&dword_288 + v3) = 0x10000;
      *(__int64 *)((char *)&qword_290 + v3) = 0x1FFFF0001FFFFLL;
      *(_QWORD *)(v3 + 516) = 0x100000000400LL;
      *(__int64 *)((char *)&qword_2A0 + v3) = 0x20000000ALL;
      *(__int64 *)((char *)&qword_240 + v3) = 1024;
      *(__int64 *)((char *)&qword_2B0 + v3) = 0x40000001000LL;
      *(__int64 *)((char *)&qword_2B8 + v3) = 2048;
      *(__int64 *)((char *)&qword_2C0 + v3) = 0x40000000000LL;
      *(int *)((char *)&dword_258 + v3) = 1024;
      *(__int64 *)((char *)&qword_2C8 + v3) = 0x12C00000400LL;
      *(int *)((char *)&dword_2E4 + v3) = 15;
      *(_QWORD *)(v3 + 748) = 1024;
      *(__int64 *)((char *)&qword_218 + v3) = 0x1000000000000LL;
      *(_QWORD *)(v3 + 756) = 0x200000001LL;
      byte_6C[v3] = 1;
      *(_QWORD *)(v3 + 764) = 0x8000000003LL;
      *(__int16 *)((char *)&word_84 + v3) = 256;
      *(_QWORD *)(v3 + 772) = 0x68000000010LL;
      *(_QWORD *)(v3 + 780) = 0x1000000000000LL;
      *(int *)((char *)&dword_98 + v3) = 0;
      *(__int64 *)((char *)&qword_318 + v3) = 0x96000007D0LL;
      *(_QWORD *)(v3 + 836) = 0x1E0000001ELL;
      byte_9C[v3] = 1;
      *(_QWORD *)(v3 + 844) = 0x1F40000001ELL;
      *(int *)((char *)&dword_A0 + v3) = 0;
      *(_QWORD *)(v3 + 852) = 0x320000012CLL;
      byte_A4[v3] = 1;
      *(_QWORD *)(v3 + 860) = 0x6000003E8LL;
      *(__int16 *)((char *)&word_B0 + v3) = 0;
      *(_QWORD *)(v3 + 868) = 0x30000000ALL;
      *(int *)((char *)&dword_36C + v3) = 30;
      *(_QWORD *)(v3 + 884) = 0x60600000200LL;
      *(_QWORD *)(v3 + 892) = 0x1400000000LL;
      *(_QWORD *)(v3 + 900) = 0x100000001LL;
      *(_QWORD *)(v3 + 908) = 0x1400000002LL;
      byte_C8[v3] = 0;
      *(_QWORD *)(v3 + 916) = 0x1400000003LL;
      *(int *)((char *)&dword_DC + v3) = 0;
      *(_QWORD *)(v3 + 924) = 0xA00000002LL;
      byte_E0[v3] = 0;
      *(_QWORD *)(v3 + 932) = 0x200000019LL;
      *(_QWORD *)(v3 + 940) = 0x300000005LL;
      *(_QWORD *)(v3 + 1212) = 0x1010000001ALL;
      *(_QWORD *)(v3 + 948) = 0x140000001ELL;
      byte_F0[v3] = 1;
      *(_QWORD *)(v3 + 956) = 0x4600000037LL;
      byte_1B4[v3] = 0;
      v5 = v3 + 9164;
      *(_QWORD *)(v3 + 964) = 0x5000000050LL;
      *(__int16 *)((char *)&word_20C + v3) = 0;
      v6 = v3 + 4920;
      *(_QWORD *)(v3 + 972) = 0x500000019LL;
      *(__int64 *)((char *)&qword_210 + v3) = 0;
      *(_QWORD *)(v3 + 980) = 0x4C00000005LL;
      byte_25C[v3] = 0;
      *(__int64 *)((char *)&qword_260 + v3) = 0x100000001LL;
      *(_QWORD *)(v3 + 988) = 0x6432190CFFFFFFB5LL;
      byte_27C[v3] = 0;
      *(__int16 *)((char *)&word_28C + v3) = 256;
      byte_298[v3] = 1;
      *(_QWORD *)(v3 + 996) = 0x6443005032190CLL;
      *(_DWORD *)(v3 + 665) = 0;
      *(int *)((char *)&dword_2A8 + v3) = 3;
      *(_QWORD *)(v3 + 1004) = 0x505A643200000008LL;
      *(__int16 *)((char *)&word_2AC + v3) = 256;
      byte_2AE[v3] = 1;
      *(_QWORD *)(v3 + 1012) = 0x50A193246LL;
      *(_QWORD *)(v3 + 1020) = 0xF00000000LL;
      *(_QWORD *)(v3 + 1028) = 50;
      *(__int64 *)((char *)&qword_2D8 + v3) = 0;
      *(__int64 *)((char *)&qword_2D0 + v3) = 0;
      *(_QWORD *)(v3 + 1036) = 0x6432190C06030000LL;
      *(int *)((char *)&dword_41C + v3) = -1;
      *(_QWORD *)(v3 + 1060) = 0;
      *(_QWORD *)(v3 + 1068) = 0x19000000320LL;
      *((_BYTE *)&dword_2E0 + v3) = 1;
      *(_QWORD *)(v3 + 1076) = 0x64000000C8LL;
      *(int *)((char *)&dword_440 + v3) = 512;
      *(_QWORD *)(v3 + 1100) = 0x5000000000LL;
      *((_BYTE *)&qword_2E8 + v3) = 0;
      *(_QWORD *)(v3 + 1108) = 0xA0000000ALL;
      *(__int16 *)((char *)&word_314 + v3) = 257;
      *(__int64 *)((char *)&qword_460 + v3) = 0x1E0000003FLL;
      *(__int64 *)((char *)&qword_468 + v3) = 0x100000004LL;
      *(_QWORD *)(v3 + 1196) = 1;
      *(__int64 *)((char *)&qword_470 + v3) = 0x4B000000005LL;
      *(__int16 *)((char *)&word_328 + v3) = 0;
      *(__int64 *)((char *)&qword_480 + v3) = 0x6400000019LL;
      *(int *)((char *)&dword_334 + v3) = 1;
      *(__int64 *)((char *)&qword_488 + v3) = 0xFFFFFFBFFFFFFFB0LL;
      *(__int16 *)((char *)&word_338 + v3) = 0;
      *(__int64 *)((char *)&qword_490 + v3) = 0xFFFFFFEBFFFFFFE7LL;
      byte_370[v3] = 0;
      *(__int64 *)((char *)&qword_498 + v3) = 0xFFFFFFF0FFFFFFECLL;
      *(int *)((char *)&dword_414 + v3) = 0;
      *(__int64 *)((char *)&qword_4A0 + v3) = 0xFFFFFFF5FFFFFFF1LL;
      *(int *)((char *)&dword_4A8 + v3) = 65537;
      *(_QWORD *)(v3 + 1204) = 0x2E00000000LL;
      *(__int16 *)((char *)&word_418 + v3) = 256;
      byte_420[v3] = 0;
      byte_43C[v3] = 0;
      *(__int16 *)((char *)&word_448 + v3) = 256;
      *(int *)((char *)&dword_444 + v3) = 0;
      byte_45C[v3] = 1;
      *(__int64 *)((char *)&qword_478 + v3) = 3;
      *(_QWORD *)(v3 + 1220) = 0x300000021LL;
      *(int *)((char *)&dword_4CC + v3) = 3;
      sized_strscpy(
        v3 + 1232,
        "1,1,2,1,3,1,4,1,5,1,11,1,9,1,13,1,14,1,17,1,18,1,19,1,22,1,26,1,28,1,29,1,31,1,36,1,38,1,46,1,47,1,50,1,52,1,53,"
        "1,56,1,60,1,61,1,113,1",
        135);
      *(_WORD *)(v3 + 1745) = 1;
      *(_QWORD *)(v3 + 1748) = 0x2F000000FFLL;
      *(__int16 *)((char *)&word_6DC + v3) = 256;
      byte_6DE[v3] = 1;
      *(__int64 *)((char *)&qword_6E0 + v3) = 0x1700000000LL;
      byte_6E8[v3] = 0;
      *(int *)((char *)&dword_6EC + v3) = 1;
      sized_strscpy(v3 + 1776, "1,3,5,3,18,1,19,3,31,1,36,1,57,3", 33);
      v7 = v3 + 2308;
      *(int *)((char *)&dword_8F4 + v3) = 1;
      *(__int16 *)((char *)&word_8F8 + v3) = 256;
      *(int *)((char *)&dword_8FC + v3) = 0;
      *(__int16 *)((char *)&word_900 + v3) = 0;
      *(_QWORD *)(v3 + 2308) = 0;
      *(_QWORD *)(v3 + 2316) = 0;
      *(_UNKNOWN **)((char *)&off_10 + v7) = nullptr;
      *(_UNKNOWN **)((char *)&off_10 + v7 + 8) = nullptr;
      sized_strscpy(v3 + 2340, &unk_8B9E43, 1);
      *(__int64 *)((char *)&qword_9C8 + v3) = 0x5A00000000LL;
      *(__int64 *)((char *)&qword_9D0 + v3) = 0x6E00000046LL;
      *(__int64 *)((char *)&qword_9D8 + v3) = 0x7D0000005ALL;
      *(__int64 *)((char *)&qword_9E0 + v3) = 110;
      *(__int64 *)((char *)&qword_9E8 + v3) = 0x7500000074LL;
      byte_9F8[v3] = 0;
      *(__int64 *)((char *)&qword_9F0 + v3) = 0x7800000076LL;
      *(_QWORD *)(v3 + 2556) = 4000;
      *(_QWORD *)(v3 + 2564) = 0x1E0000000ALL;
      *(_QWORD *)(v3 + 2572) = 0x4600000032LL;
      *(_QWORD *)(v3 + 2580) = 0x640000005ALL;
      *(_QWORD *)(v3 + 2588) = 0x100000001LL;
      *(_QWORD *)(v3 + 2596) = 0x500000000LL;
      *(int *)((char *)&dword_A2C + v3) = 100;
      *(_QWORD *)(v3 + 2612) = 1;
      *(_QWORD *)(v3 + 2620) = 0x1E0000000ALL;
      *(_QWORD *)(v3 + 2628) = 0x4600000032LL;
      *(_QWORD *)(v3 + 2636) = 90;
      *(_QWORD *)(v3 + 2644) = 0x300000000LL;
      *(_QWORD *)(v3 + 2652) = 0x432100000000LL;
      *(_QWORD *)(v3 + 2660) = 3;
      *(_QWORD *)(v3 + 2676) = 0x600000001LL;
      *(int *)((char *)&dword_A80 + v3) = 2;
      *(__int64 *)((char *)&qword_A98 + v3) = 0x400000000LL;
      *(_DWORD *)(v3 + 2729) = 16777217;
      *(__int64 *)((char *)&qword_AB0 + v3) = 0x100000000LL;
      *(int *)((char *)&dword_AB8 + v3) = 5;
      *(int *)((char *)&dword_AC0 + v3) = 400;
      byte_A30[v3] = 0;
      *(int *)((char *)&dword_A6C + v3) = 0;
      byte_A70[v3] = 1;
      byte_A7C[v3] = 0;
      byte_A84[v3] = 0;
      *(__int64 *)((char *)&qword_A88 + v3) = 1;
      *(int *)((char *)&dword_A90 + v3) = 1;
      byte_A94[v3] = 1;
      byte_AA8[v3] = 0;
      *(__int64 *)((char *)&qword_AA0 + v3) = 0;
      byte_ABC[v3] = 1;
      byte_AC4[v3] = 1;
      *(__int64 *)((char *)&qword_AC8 + v3) = 0x20000001ELL;
      *(__int16 *)((char *)&word_AD0 + v3) = 1;
      sized_strscpy(v3 + 2770, &unk_8B9E43, 1);
      *(int *)((char *)&dword_B00 + v3) = -1;
      sized_strscpy(v3 + 2820, &unk_8B9E43, 1);
      *(int *)((char *)&dword_B24 + v3) = 250;
      *(__int64 *)((char *)&qword_B18 + v3) = 0x100000000000001LL;
      *(_QWORD *)(v3 + 2860) = 0x400000001LL;
      *(_QWORD *)(v3 + 2868) = 0x10000096CLL;
      *(_QWORD *)(v3 + 2876) = 0x1FFFFFFFFLL;
      byte_B20[v3] = 0;
      *(__int16 *)((char *)&word_B28 + v3) = 256;
      *(_QWORD *)(v3 + 2884) = 0xC00000003LL;
      *(__int16 *)((char *)&word_B4C + v3) = 256;
      byte_B4E[v3] = 1;
      sized_strscpy(v3 + 2895, &unk_8B9E43, 1);
      *(_QWORD *)(v3 + 3900) = 64424509740000LL;
      *(int *)((char *)&dword_F54 + v3) = 0;
      *(_QWORD *)(v3 + 3908) = 0x5000003E8LL;
      *(__int16 *)((char *)&word_F58 + v3) = 0;
      *(_QWORD *)(v3 + 3916) = 0xB0000000BLL;
      *(int *)((char *)&dword_F5C + v3) = 16000;
      byte_F60[v3] = 0;
      *(_QWORD *)(v3 + 3937) = 0x1000001000101LL;
      byte_F69[v3] = 0;
      *(int *)((char *)&dword_F6C + v3) = 100000;
      *(_QWORD *)(v3 + 3956) = 0;
      byte_F70[v3] = 0;
      *(__int64 *)((char *)&qword_F80 + v3) = 0;
      *(int *)((char *)&dword_F88 + v3) = 0;
      byte_F7C[v3] = 0;
      *(_QWORD *)(v3 + 3980) = 30;
      *(int *)((char *)&dword_F94 + v3) = 0;
      sized_strscpy(v3 + 3992, "e", 2);
      *(int *)((char *)&dword_FE0 + v3) = 0;
      *(int *)((char *)&dword_FBC + v3) = 64;
      *(int *)((char *)&dword_FC0 + v3) = 64;
      *(int *)((char *)&dword_FB8 + v3) = 20;
      *(int *)((char *)&dword_FC8 + v3) = 500000;
      *(int *)((char *)&dword_FD8 + v3) = 50;
      *(_DWORD *)(v3 + 4067) = 0;
      *(int *)((char *)&dword_FE8 + v3) = 22000;
      *(int *)((char *)&dword_FEC + v3) = 12000;
      *(int *)((char *)&dword_FF0 + v3) = 10000;
      *(int *)((char *)&dword_FF8 + v3) = 6000;
      *(int *)((char *)&dword_FFC + v3) = 2000;
      *(int *)((char *)&dword_1004 + v3) = 150;
      *(int *)((char *)&dword_1018 + v3) = 500;
      *(int *)((char *)&dword_1024 + v3) = 500;
      *(int *)((char *)&dword_1028 + v3) = 10;
      *(int *)((char *)&dword_FD0 + v3) = 500;
      *(int *)((char *)&dword_1000 + v3) = 500;
      byte_FB7[v3] = 0;
      *(int *)((char *)&dword_FC4 + v3) = 0;
      *(int *)((char *)&dword_FCC + v3) = 1;
      byte_FD4[v3] = 0;
      byte_FD5[v3] = 1;
      *(int *)((char *)&dword_FDC + v3) = 1;
      *(int *)((char *)&dword_FF4 + v3) = 0;
      *(int *)((char *)&dword_1008 + v3) = 100;
      byte_D1C[v4 + 87] = 1;
      *(int *)((char *)&dword_1010 + v3) = 1;
      byte_D1C[v4 + 95] = 1;
      *(int *)((char *)&dword_101C + v3) = 1000;
      *(int *)((char *)&dword_1020 + v3) = 30;
      byte_D1C[v4 + 119] = 0;
      *(int *)((char *)&dword_1030 + v3) = 0;
      byte_D1C[v4 + 127] = 1;
      sized_strscpy(v3 + 4149, "1, 6, 2, 126", 13);
      *(int *)((char *)&dword_104C + v3) = 23;
      *(_DWORD *)(v3 + 4178) = 0;
      byte_D1C[v4 + 155] = 1;
      *(_QWORD *)(v3 + 4183) = 0;
      *(_QWORD *)(v3 + 4188) = 0;
      byte_D1C[v4 + 156] = 1;
      byte_D1C[v4 + 161] = 1;
      byte_D1C[v4 + 175] = 1;
      byte_D1C[v4 + 176] = 1;
      *(int *)((char *)&dword_1068 + v3) = 8;
      sized_strscpy(v3 + 4204, &unk_8B9E43, 1);
      sized_strscpy(v3 + 4255, &unk_8B9E43, 1);
      sized_strscpy(v3 + 4306, &unk_8B9E43, 1);
      sized_strscpy(v3 + 4357, &unk_8B9E43, 1);
      byte_E20[v4 + 127] = 0;
      *(int *)((char *)&dword_113C + v3) = 16448250;
      byte_E20[v4 + 128] = 1;
      byte_E20[v4 + 135] = 0;
      byte_E20[v4 + 136] = 0;
      byte_E20[v4 + 137] = 1;
      sized_strscpy(
        v3 + 4419,
        "2407-5875=40, 5945-7125=90, 5975=100, 6055=100, 6135=100, 6215=100, 6295=100, 6375=100, 6615=100, 6695=100, 6775=100, 6855=100",
        127);
      *(int *)((char *)&dword_1344 + v3) = -62;
      *(int *)((char *)&dword_134C + v3) = 449;
      *(int *)((char *)&dword_1354 + v3) = 3;
      *(int *)((char *)&dword_135C + v3) = -1;
      *(int *)((char *)&dword_1360 + v3) = 10000;
      *(int *)((char *)&dword_1368 + v3) = 2600;
      *(_BYTE *)(v3 + 4920) = 0;
      *(__int64 *)((char *)&qword_1398 + v3) = 0x200000136LL;
      *(int *)((char *)&dword_133C + v3) = 1;
      *(int *)((char *)&dword_1340 + v3) = 0;
      *((_BYTE *)&off_10 + v6) = 1;
      *((_BYTE *)&off_10 + v6 + 1) = 1;
      *(int *)((char *)&dword_1350 + v3) = 100;
      *(int *)((char *)&dword_1358 + v3) = 0;
      *(int *)((char *)&dword_1364 + v3) = 8;
      *(int *)((char *)&dword_136C + v3) = 1;
      *(int *)((char *)&dword_1370 + v3) = 1;
      *((_BYTE *)&qword_38 + v6 + 4) = 0;
      *(__int64 *)((char *)&qword_1378 + v3) = 0;
      *(__int64 *)((char *)&qword_1380 + v3) = 0;
      *(__int64 *)((char *)&qword_1388 + v3) = 0;
      *(__int64 *)((char *)&qword_1390 + v3) = 0;
      *(__int64 *)((char *)&qword_13A8 + v3) = 0;
      *(int *)((char *)&dword_13B0 + v3) = 0;
      *(int *)((char *)&dword_13A0 + v3) = 0;
      *((_BYTE *)&off_0 + v3 + 5028) = 0;
      sized_strscpy(
        v3 + 5044,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 5132,
        "0x0, 0x2, 0x0, 0xf, 0x3, 0xff, 0x64, 0x0, 0x1f, 0x3, 0xff, 0x64, 0x0, 0xf, 0x3, 0xff, 0x64",
        91);
      sized_strscpy(
        v3 + 5223,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0xc8, 0x0, 0xf, 0x0, 0x1f, 0xbc, 0x0, 0x7, 0x0, 0xf, 0xc8",
        88);
      sized_strscpy(
        v3 + 5311,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x64, 0x0, 0x7, 0x0, 0xf, 0x66, 0x0, 0x3, 0x0, 0x7, 0x64",
        87);
      sized_strscpy(
        v3 + 5398,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 5486,
        "0x0, 0x2, 0x0, 0xf, 0x3, 0xff, 0x64, 0x0, 0x1f, 0x3, 0xff, 0x64, 0x0, 0xf, 0x3, 0xff, 0x64",
        91);
      sized_strscpy(
        v3 + 5577,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0xc8, 0x0, 0xf, 0x0, 0x1f, 0xbc, 0x0, 0x7, 0x0, 0xf, 0xc8",
        88);
      sized_strscpy(
        v3 + 5665,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x64, 0x0, 0x7, 0x0, 0xf, 0x66, 0x0, 0x3, 0x0, 0x7, 0x64",
        87);
      sized_strscpy(
        v3 + 5752,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 5840,
        "0x0, 0x3, 0x0, 0xf, 0x0, 0x3f, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x0, 0x3f, 0x0",
        88);
      sized_strscpy(
        v3 + 5928,
        "0x0, 0x1, 0x0, 0x7, 0x0, 0xf, 0x5e, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 6015,
        "0x0, 0x1, 0x0, 0x3, 0x0, 0x7, 0x2f, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      sized_strscpy(
        v3 + 6102,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        87);
      sized_strscpy(
        v3 + 6189,
        "0x0, 0x3, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        87);
      sized_strscpy(
        v3 + 6276,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0x5e, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 6363,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x2f, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      sized_strscpy(
        v3 + 6450,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0xbb, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        89);
      sized_strscpy(
        v3 + 6539,
        "0x0, 0x3, 0x0, 0xf, 0x0, 0x3f, 0xbb, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x0, 0x3f, 0x0",
        89);
      sized_strscpy(
        v3 + 6628,
        "0x0, 0x1, 0x0, 0x7, 0x0, 0xf, 0x7d, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 6715,
        "0x0, 0x1, 0x0, 0x3, 0x0, 0x7, 0x3e, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      sized_strscpy(
        v3 + 6802,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0xbb, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 6890,
        "0x0, 0x3, 0x0, 0xf, 0x3, 0xff, 0xbb, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 6978,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0x7d, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 7065,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x3e, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      *(int *)((char *)&dword_1BF8 + v3) = 3;
      *(int *)((char *)&dword_1C00 + v3) = 3;
      *(int *)((char *)&dword_1C04 + v3) = 4;
      *(int *)((char *)&dword_1C0C + v3) = 4;
      *(int *)((char *)&dword_1C18 + v3) = 4;
      *(int *)((char *)&dword_1BF4 + v3) = 2;
      *(int *)((char *)&dword_1BFC + v3) = 2;
      *(int *)((char *)&dword_1C08 + v3) = 2;
      byte_8B8[v6] = 0;
      *(int *)((char *)&dword_1C10 + v3) = 10;
      *(int *)((char *)&dword_1C14 + v3) = 7;
      *(int *)((char *)&dword_1C1C + v3) = 10;
      byte_8B8[v6 + 48] = 1;
      *(int *)((char *)&dword_1C24 + v3) = 3;
      *(int *)((char *)&dword_1C28 + v3) = 0;
      *((_BYTE *)&dword_8F4 + v6) = 1;
      *((_BYTE *)&dword_8F4 + v6 + 1) = 0;
      *(int *)((char *)&dword_1C30 + v3) = 100;
      sized_strscpy(v3 + 7220, "0x73,0x1A,0x91,0x00,0x04", 25);
      byte_925[v6] = 1;
      byte_925[v6 + 1] = 0;
      *(int *)((char *)&dword_1C60 + v3) = 0;
      byte_925[v6 + 7] = 0;
      sized_strscpy(v3 + 7269, "0x0", 4);
      sized_strscpy(v3 + 7288, "0x3000100000083", 16);
      sized_strscpy(v3 + 7307, "0xa", 4);
      sized_strscpy(v3 + 7326, "0x180D83", 9);
      *(int *)((char *)&dword_1CD4 + v3) = 5;
      *(int *)((char *)&dword_1CD8 + v3) = 200;
      *(int *)((char *)&dword_1D04 + v3) = 512;
      *(int *)((char *)&dword_1D10 + v3) = 15;
      *(int *)((char *)&dword_1D1C + v3) = 82;
      *(int *)((char *)&dword_1CB4 + v3) = 0;
      *(int *)((char *)&dword_1CB8 + v3) = 0;
      *(int *)((char *)&dword_1CBC + v3) = 1;
      byte_925[v6 + 99] = 0;
      *(int *)((char *)&dword_1CC4 + v3) = 1;
      *(int *)((char *)&dword_1CC8 + v3) = 1;
      byte_925[v6 + 111] = 1;
      *(int *)((char *)&dword_1CD0 + v3) = 1;
      byte_925[v6 + 127] = 1;
      byte_925[v6 + 128] = 1;
      byte_925[v6 + 129] = 1;
      *(int *)((char *)&dword_1CE0 + v3) = 7;
      byte_925[v6 + 135] = 0;
      *(int *)((char *)&dword_1CE8 + v3) = 0;
      byte_925[v6 + 143] = 1;
      byte_925[v6 + 144] = 0;
      byte_925[v6 + 145] = 0;
      byte_925[v6 + 146] = 1;
      *(_WORD *)&byte_925[v6 + 147] = 0;
      *(int *)((char *)&dword_1CF4 + v3) = 2;
      byte_925[v6 + 155] = 0;
      byte_925[v6 + 156] = 1;
      *(int *)((char *)&dword_1CFC + v3) = 0;
      *((_BYTE *)&qword_9C8 + v6) = 0;
      *((_BYTE *)&qword_9C8 + v6 + 1) = 1;
      *(int *)((char *)&dword_1D08 + v3) = 0;
      *((_BYTE *)&qword_9D0 + v6 + 4) = 0;
      *(_WORD *)((char *)&qword_9D8 + v6 + 4) = 0;
      *((_BYTE *)&qword_9D8 + v6 + 6) = 1;
      *(int *)((char *)&dword_1D18 + v3) = 0;
      *((_BYTE *)&qword_9E8 + v6) = 0;
      *(int *)((char *)&dword_1D24 + v3) = 0;
      *(int *)((char *)&dword_1D28 + v3) = 0;
      sized_strscpy(v3 + 7468, &unk_8B9E43, 1);
      *(int *)((char *)&dword_1D78 + v3) = 3;
      *(int *)((char *)&dword_1D84 + v3) = 3;
      *(int *)((char *)&dword_1D8C + v3) = 3;
      *(int *)((char *)&dword_1D98 + v3) = 3;
      *(int *)((char *)&dword_1D9C + v3) = 3;
      *(int *)((char *)&dword_1DA4 + v3) = 65450;
      *(int *)((char *)&dword_1DA8 + v3) = 65450;
      *(int *)((char *)&dword_1DAC + v3) = 65450;
      *(int *)((char *)&dword_1DB0 + v3) = 65450;
      *(int *)((char *)&dword_1DB4 + v3) = 65450;
      *(int *)((char *)&dword_1D7C + v3) = 16843009;
      *(int *)((char *)&dword_1DC0 + v3) = 364429998;
      *(__int16 *)((char *)&word_1D80 + v3) = 257;
      *(int *)((char *)&dword_1DC4 + v3) = -1;
      *(int *)((char *)&dword_1DD0 + v3) = 300;
      *(int *)((char *)&dword_1DD4 + v3) = -66;
      *(int *)((char *)&dword_1E2C + v3) = 300;
      *(int *)((char *)&dword_1DD8 + v3) = 5;
      *(int *)((char *)&dword_1DDC + v3) = 5;
      *(int *)((char *)&dword_1E30 + v3) = 25;
      *(int *)((char *)&dword_1DEC + v3) = -73;
      *(int *)((char *)&dword_1E34 + v3) = 83;
      *(int *)((char *)&dword_1DF0 + v3) = -43;
      *(int *)((char *)&dword_1E38 + v3) = 30;
      *(int *)((char *)&dword_1E04 + v3) = 1060;
      *(int *)((char *)&dword_1E3C + v3) = 5;
      *(int *)((char *)&dword_1E60 + v3) = 5;
      *(int *)((char *)&dword_1E64 + v3) = 5;
      *(int *)((char *)&dword_1E6C + v3) = 5;
      *(int *)((char *)&dword_1E70 + v3) = 5;
      *(int *)((char *)&dword_1E78 + v3) = 5;
      *(int *)((char *)&dword_1E14 + v3) = 2000;
      *(int *)((char *)&dword_1E24 + v3) = 200;
      *((_BYTE *)&qword_A34 + v6 + 1) = 1;
      *(int *)((char *)&dword_1D70 + v3) = 1;
      *((_BYTE *)&qword_A3C + v6) = 0;
      *((_BYTE *)&qword_A3C + v6 + 1) = 1;
      *((_BYTE *)&qword_A44 + v6 + 6) = 0;
      *(int *)((char *)&dword_1D88 + v3) = 0;
      *(int *)((char *)&dword_1D90 + v3) = 4;
      *((_BYTE *)&qword_A5C + v6) = 1;
      *(int *)((char *)&dword_1DA0 + v3) = 0;
      *(int *)((char *)&dword_1DB8 + v3) = 0;
      byte_A84[v6] = 1;
      byte_A85[v6] = 1;
      *(int *)((char *)&dword_1DC8 + v3) = 0;
      byte_A94[v6] = 0;
      *(__int64 *)((char *)&qword_1DE0 + v3) = 0;
      *((_BYTE *)&qword_AB0 + v6) = 1;
      *((_BYTE *)&qword_AB0 + v6 + 1) = 0;
      *(int *)((char *)&dword_1DF4 + v3) = 400;
      *(int *)((char *)&dword_1DF8 + v3) = 10;
      *(int *)((char *)&dword_1DFC + v3) = 3;
      *(int *)((char *)&dword_1E00 + v3) = -76;
      *(int *)((char *)&dword_1E08 + v3) = 40;
      *(int *)((char *)&dword_1E0C + v3) = 3;
      *(int *)((char *)&dword_1E10 + v3) = -70;
      *(int *)((char *)&dword_1E18 + v3) = 4;
      *(int *)((char *)&dword_1E1C + v3) = 3;
      *(int *)((char *)&dword_1E20 + v3) = 400;
      *(int *)((char *)&dword_1E28 + v3) = 60;
      *(int *)((char *)&dword_1E40 + v3) = 3;
      byte_B0C[v6] = 0;
      *(int *)((char *)&dword_1E48 + v3) = -60;
      *(int *)((char *)&dword_1E4C + v3) = 1;
      *(int *)((char *)&dword_1E50 + v3) = 10;
      *(int *)((char *)&dword_1E54 + v3) = -70;
      *(int *)((char *)&dword_1E58 + v3) = 1;
      *(int *)((char *)&dword_1E5C + v3) = 10;
      *((_BYTE *)&qword_B2C + v6 + 4) = 1;
      *((_BYTE *)&qword_B2C + v6 + 5) = 0;
      *((_BYTE *)&qword_B2C + v6 + 6) = 1;
      *(int *)((char *)&dword_1E74 + v3) = 0;
      *((_BYTE *)&qword_B44 + v6) = 0;
      *((_BYTE *)&qword_B44 + v6 + 1) = 1;
      sized_strscpy(v3 + 7806, &unk_8B9E43, 1);
      *(int *)((char *)&dword_2018 + v3) = -76;
      *(int *)((char *)&dword_2010 + v3) = 100;
      *(int *)((char *)&dword_2014 + v3) = 50;
      *(int *)((char *)&dword_202C + v3) = 20000;
      *(int *)((char *)&dword_2034 + v3) = 10;
      *(int *)((char *)&dword_2038 + v3) = 10;
      *(int *)((char *)&dword_2048 + v3) = 23;
      *(int *)((char *)&dword_204C + v3) = 15000;
      *(int *)((char *)&dword_2050 + v3) = -30;
      *(int *)((char *)&dword_2058 + v3) = 2;
      *(int *)((char *)&dword_2068 + v3) = 70;
      *(int *)((char *)&dword_206C + v3) = 70;
      *(int *)((char *)&dword_2080 + v3) = 4314;
      *(int *)((char *)&dword_2098 + v3) = 130;
      *(int *)((char *)&dword_20A0 + v3) = -70;
      *(int *)((char *)&dword_20A4 + v3) = -70;
      *(int *)((char *)&dword_20D0 + v3) = 0x7FFFF;
      *(int *)((char *)&dword_20E8 + v3) = 5;
      *(int *)((char *)&dword_20EC + v3) = 5;
      *(int *)((char *)&dword_20F8 + v3) = -72;
      *(int *)((char *)&dword_2100 + v3) = -75;
      *(int *)((char *)&dword_2020 + v3) = 5;
      *(int *)((char *)&dword_2024 + v3) = 20;
      *(int *)((char *)&dword_203C + v3) = 20;
      *(int *)((char *)&dword_20A8 + v3) = -60;
      *(int *)((char *)&dword_201C + v3) = 0;
      *(int *)((char *)&dword_2028 + v3) = 40;
      *(int *)((char *)&dword_2030 + v3) = 0;
      *(int *)((char *)&dword_2040 + v3) = 1;
      *(int *)((char *)&dword_2044 + v3) = 3;
      byte_D1C[v6] = 1;
      byte_D1C[v6 + 1] = 0;
      *(int *)((char *)&dword_205C + v3) = 0;
      *(int *)((char *)&dword_2060 + v3) = 20;
      byte_D1C[v6 + 16] = 0;
      *(int *)((char *)&dword_2070 + v3) = 10000;
      *(int *)((char *)&dword_2074 + v3) = 10;
      *(int *)((char *)&dword_2078 + v3) = 0;
      *(int *)((char *)&dword_207C + v3) = 10;
      byte_D1C[v6 + 48] = 1;
      byte_D1C[v6 + 49] = 1;
      byte_D1C[v6 + 50] = 0;
      *(int *)((char *)&dword_2088 + v3) = 0;
      *(int *)((char *)&dword_208C + v3) = 120;
      byte_D1C[v6 + 60] = 1;
      *(int *)((char *)&dword_2094 + v3) = 10;
      *(int *)((char *)&dword_209C + v3) = 10;
      *(int *)((char *)&dword_20AC + v3) = 0;
      byte_D1C[v6 + 92] = 0;
      byte_D1C[v6 + 93] = 1;
      byte_D1C[v6 + 94] = 1;
      byte_D1C[v6 + 95] = 1;
      byte_D1C[v6 + 96] = 0;
      *(int *)((char *)&dword_20B8 + v3) = 3;
      *(int *)((char *)&dword_20BC + v3) = 10000;
      *(int *)((char *)&dword_20C0 + v3) = 10;
      *(int *)((char *)&dword_20C4 + v3) = 10;
      *(int *)((char *)&dword_20C8 + v3) = -65;
      *(int *)((char *)&dword_20CC + v3) = 0;
      *(int *)((char *)&dword_20D4 + v3) = 0;
      *(int *)((char *)&dword_20D8 + v3) = 1;
      *(_WORD *)&byte_D1C[v6 + 136] = 0;
      byte_D1C[v6 + 138] = 1;
      byte_D1C[v6 + 139] = 1;
      byte_D1C[v6 + 140] = 0;
      *(int *)((char *)&dword_20E4 + v3) = 3;
      byte_D1C[v6 + 156] = 1;
      *(int *)((char *)&dword_20F4 + v3) = -65;
      *(int *)((char *)&dword_20FC + v3) = -65;
      *(int *)((char *)&dword_2104 + v3) = -70;
      sized_strscpy(v3 + 8456, "Mod", 4);
      byte_DDC[v6] = 1;
      *(int *)((char *)&dword_210C + v3) = 30;
      *(int *)((char *)&dword_2110 + v3) = 30;
      *(int *)((char *)&dword_2120 + v3) = 60;
      byte_E20[v6] = 1;
      *(int *)((char *)&dword_2128 + v3) = 38347922;
      *(int *)((char *)&dword_212C + v3) = 38347922;
      *(int *)((char *)&dword_2130 + v3) = 38347922;
      *(int *)((char *)&dword_2134 + v3) = 38347922;
      *(int *)((char *)&dword_2138 + v3) = 38347922;
      *(int *)((char *)&dword_213C + v3) = 38347922;
      *(int *)((char *)&dword_2140 + v3) = 38347922;
      *(int *)((char *)&dword_2144 + v3) = 38347922;
      *(int *)((char *)&dword_2148 + v3) = 38347922;
      *(int *)((char *)&dword_214C + v3) = 38347922;
      *(int *)((char *)&dword_2150 + v3) = 38347922;
      *(int *)((char *)&dword_2168 + v3) = 200;
      *(_QWORD *)(v3 + 8557) = 0x10101010101LL;
      byte_E20[v6 + 1] = 0;
      *(_DWORD *)(v3 + 8565) = 16843009;
      *(_WORD *)((char *)&off_0 + v3 + 8569) = 257;
      *(_QWORD *)(v3 + 8572) = 0x100000258LL;
      byte_E20[v6 + 2] = 0;
      *(_QWORD *)(v3 + 8580) = 0x500000001LL;
      byte_E20[v6 + 20] = 0;
      *(_QWORD *)(v3 + 8596) = 0;
      *(_QWORD *)(v3 + 8604) = 0;
      *(_WORD *)&byte_E20[v6 + 52] = 1;
      byte_E20[v6 + 54] = 0;
      *(_QWORD *)(v3 + 8636) = 0;
      *(_QWORD *)(v3 + 8644) = 0;
      byte_E20[v6 + 120] = 1;
      *(int *)((char *)&dword_2190 + v3) = 256;
      *(int *)((char *)&dword_21A4 + v3) = 256;
      *(__int64 *)((char *)&qword_2118 + v3) = 0;
      *(int *)((char *)&dword_2124 + v3) = 120;
      *(int *)((char *)&dword_2154 + v3) = 0;
      *(int *)((char *)&dword_215C + v3) = 0;
      *(int *)((char *)&dword_2160 + v3) = 10;
      *(int *)((char *)&dword_2164 + v3) = 20;
      *(__int64 *)((char *)&qword_21A8 + v3) = 0;
      *(__int64 *)((char *)&qword_21B0 + v3) = 0;
      *(int *)((char *)&dword_21B8 + v3) = 16;
      *(int *)((char *)&dword_21CC + v3) = 16;
      sized_strscpy(v3 + 8657, &unk_8B9E43, 1);
      *(int *)((char *)&dword_23C8 + v3) = 0;
      *(_BYTE *)(v3 + 9164) = 0;
      *(__int64 *)((char *)&qword_23D0 + v3) = 0;
      *(int *)((char *)&dword_23D8 + v3) = 0;
      sized_strscpy(v3 + 9180, "0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF", 47);
      *(int *)((char *)&dword_240C + v3) = 0;
      *(int *)((char *)&dword_242C + v3) = 3600000;
      *((_BYTE *)&qword_40 + v5 + 4) = 0;
      *(int *)((char *)&dword_2414 + v3) = 0;
      *((_BYTE *)&qword_48 + v5 + 4) = 1;
      *((_BYTE *)&qword_48 + v5 + 5) = 0;
      *(int *)((char *)&dword_241C + v3) = 6;
      *(_WORD *)((char *)&qword_50 + v5 + 4) = 0;
      *(int *)((char *)&dword_2424 + v3) = 1;
      *((_BYTE *)&qword_58 + v5 + 4) = 0;
      *((_BYTE *)&qword_60 + v5 + 4) = 0;
      *((_BYTE *)&qword_60 + v5 + 5) = 1;
      sized_strscpy(v3 + 9266, &unk_8B9E43, 1);
      *(int *)((char *)&dword_25D0 + v3) = 255;
      *(int *)((char *)&dword_25D4 + v3) = 255;
      *(int *)((char *)&dword_25D8 + v3) = 255;
      *(int *)((char *)&dword_25F0 + v3) = 2;
      *(int *)((char *)&dword_25F4 + v3) = 2;
      *(int *)((char *)&dword_25E0 + v3) = 5;
      *(int *)((char *)&dword_2604 + v3) = 5;
      *(_WORD *)((char *)&qword_8 + v3 + 9740) = 256;
      *(_QWORD *)(v3 + 9740) = 0;
      *(_DWORD *)(v3 + 9750) = 0;
      *(int *)((char *)&dword_261C + v3) = 49151;
      *(_QWORD *)(v3 + 9764) = 0xFFFFFFFFLL;
      *(_QWORD *)(v3 + 9772) = 0xF00000000LL;
      *((_BYTE *)&qword_1F4 + v5 + 3) = 0;
      *(__int64 *)((char *)&qword_2638 + v3) = 0xFFFFFFB5FFFFFFB5LL;
      *(__int64 *)((char *)&qword_2640 + v3) = 4294967226LL;
      *((_BYTE *)&qword_1F4 + v5 + 4) = 0;
      *((_BYTE *)&qword_1F4 + v5 + 5) = 1;
      *((_BYTE *)&qword_1F4 + v5 + 6) = 0;
      *(int *)((char *)&dword_25C8 + v3) = 100;
      *((_BYTE *)&qword_1FC + v5 + 4) = 0;
      *((_BYTE *)&qword_210 + v5) = 0;
      *(int *)((char *)&dword_25E4 + v3) = 0;
      *((_BYTE *)&qword_218 + v5 + 4) = 1;
      *((_BYTE *)&qword_218 + v5 + 5) = 0;
      *(int *)((char *)&dword_25EC + v3) = 10;
      *(int *)((char *)&dword_25F8 + v3) = 10;
      *((_BYTE *)&qword_230 + v5) = 1;
      *((_BYTE *)&qword_230 + v5 + 1) = 1;
      *((_BYTE *)&qword_230 + v5 + 2) = 0;
      *(int *)((char *)&dword_2600 + v3) = 0;
      *((_BYTE *)&qword_238 + v5 + 4) = 1;
      *((_BYTE *)&qword_248 + v5 + 6) = 1;
      *((_BYTE *)&qword_250 + v5 + 4) = 0;
      *((_BYTE *)&qword_268 + v5) = 1;
      *(int *)((char *)&dword_2648 + v3) = 0;
      sized_strscpy(v3 + 9804, "10,0,14,0", 10);
      *(int *)((char *)&dword_26DC + v3) = 10;
      *(int *)((char *)&dword_26E0 + v3) = 10;
      *(int *)((char *)&dword_26E8 + v3) = 30;
      *(int *)((char *)&dword_26F0 + v3) = 32;
      *(int *)((char *)&dword_2710 + v3) = 400;
      *(int *)((char *)&dword_272C + v3) = -55;
      *(int *)((char *)&dword_2734 + v3) = -80;
      *(int *)((char *)&dword_273C + v3) = 2347;
      *(int *)((char *)&dword_2740 + v3) = 8000;
      *(int *)((char *)&dword_2750 + v3) = 5000;
      *(int *)((char *)&dword_275C + v3) = 10000;
      *(int *)((char *)&dword_2774 + v3) = 1000;
      *(int *)((char *)&dword_2798 + v3) = 7;
      *(int *)((char *)&dword_27C4 + v3) = 7;
      *(int *)((char *)&dword_27D0 + v3) = 781;
      *(int *)((char *)&dword_27E0 + v3) = 32976;
      *(int *)((char *)&dword_2748 + v3) = 1000;
      *(int *)((char *)&dword_27E4 + v3) = 83200;
      *(int *)((char *)&dword_274C + v3) = 1000;
      *(int *)((char *)&dword_27E8 + v3) = 6000000;
      *(int *)((char *)&dword_2804 + v3) = 6000000;
      *(int *)((char *)&dword_2820 + v3) = 6000000;
      *(int *)((char *)&dword_283C + v3) = 6000000;
      *(int *)((char *)&dword_2758 + v3) = 1000;
      *((_BYTE *)&qword_8 + v3 + 10324) = 0;
      *(_QWORD *)(v3 + 10324) = 0;
      *(int *)((char *)&dword_2870 + v3) = 14;
      *(_WORD *)((char *)&dword_4A8 + v5) = 257;
      *(int *)((char *)&dword_2878 + v3) = 60;
      *(int *)((char *)&dword_2760 + v3) = 1000;
      *(__int64 *)((char *)&qword_2880 + v3) = 0x100000008LL;
      *(int *)((char *)&dword_2764 + v3) = 40;
      *(__int64 *)((char *)&qword_2898 + v3) = 0xA00000014LL;
      *(_DWORD *)(v3 + 10401) = 0;
      *(_WORD *)&byte_4D4[v5 + 12] = 257;
      *(_WORD *)&byte_4D4[v5 + 40] = 257;
      *(int *)((char *)&dword_2768 + v3) = 20;
      *(int *)((char *)&dword_2770 + v3) = 20;
      *(_QWORD *)(v3 + 10444) = 0;
      *(int *)((char *)&dword_27A0 + v3) = 2;
      *(int *)((char *)&dword_27A4 + v3) = 2;
      *(int *)((char *)&dword_27A8 + v3) = 2;
      *(int *)((char *)&dword_27AC + v3) = 2;
      *(int *)((char *)&dword_27B0 + v3) = 2;
      *(_QWORD *)(v3 + 10452) = 1;
      *(int *)((char *)&dword_27C8 + v3) = 2;
      *(int *)((char *)&dword_27EC + v3) = 8193;
      *(int *)((char *)&dword_2808 + v3) = 8193;
      *(int *)((char *)&dword_2824 + v3) = 8193;
      *(int *)((char *)&dword_2840 + v3) = 8193;
      *(__int64 *)((char *)&qword_28E8 + v3) = 0x200000003LL;
      *(_WORD *)&byte_4D4[v5 + 32] = 256;
      *(_WORD *)((char *)&unk_510 + v5) = 256;
      *(_QWORD *)(v3 + 10484) = 0x3200000000LL;
      *(_QWORD *)(v3 + 10492) = 0x3C00000000LL;
      *(int *)((char *)&dword_2904 + v3) = 16842752;
      *(_QWORD *)(v3 + 10516) = 0x1E00000000LL;
      *(int *)((char *)&dword_2728 + v3) = 10;
      *(int *)((char *)&dword_276C + v3) = 10;
      *(_QWORD *)(v3 + 10524) = 15461882265780000LL;
      *(_QWORD *)(v3 + 10532) = -1;
      *(_QWORD *)(v3 + 10540) = 500;
      *(_QWORD *)(v3 + 10556) = 0xA00000000LL;
      *(int *)((char *)&dword_2800 + v3) = 360000;
      *(__int64 *)((char *)&qword_2950 + v3) = 0x28000007D0LL;
      *(int *)((char *)&dword_2754 + v3) = 2000;
      *(__int64 *)((char *)&qword_2958 + v3) = 0x800000005LL;
      *(int *)((char *)&dword_27F4 + v3) = 2000;
      *(__int64 *)((char *)&qword_2960 + v3) = 0x300001388LL;
      *(int *)((char *)&dword_26F4 + v3) = 3;
      *(__int64 *)((char *)&qword_2968 + v3) = 0xFFFFFFB5FFFFFFB5LL;
      *(int *)((char *)&dword_27DC + v3) = 3;
      *(int *)((char *)&dword_27F8 + v3) = 3;
      *(__int64 *)((char *)&qword_2970 + v3) = 0x24FFFFFFECLL;
      *(int *)((char *)&dword_27FC + v3) = 34268;
      *(__int64 *)((char *)&qword_2978 + v3) = 0xF00001757LL;
      *(int *)((char *)&dword_2814 + v3) = 3;
      *(__int64 *)((char *)&qword_2980 + v3) = 0x138800000002LL;
      *(int *)((char *)&dword_2818 + v3) = 34268;
      *(__int64 *)((char *)&qword_2990 + v3) = 0xC800000060LL;
      *(int *)((char *)&dword_281C + v3) = 300000;
      *(int *)((char *)&dword_2830 + v3) = 3;
      *(int *)((char *)&dword_2834 + v3) = 34268;
      *(int *)((char *)&dword_2838 + v3) = 300000;
      *(int *)((char *)&dword_26E4 + v3) = 5;
      *(int *)((char *)&dword_26EC + v3) = 0;
      *((_BYTE *)&qword_32C + v5) = 0;
      *(int *)((char *)&dword_26FC + v3) = 0;
      *((_BYTE *)&dword_334 + v5) = 1;
      *((_BYTE *)&dword_334 + v5 + 1) = 0;
      *(int *)((char *)&dword_2704 + v3) = 0;
      *(int *)((char *)&dword_2708 + v3) = 2;
      *((_BYTE *)&qword_33C + v5 + 4) = 0;
      *((_BYTE *)&qword_33C + v5 + 5) = 1;
      *(int *)((char *)&dword_2714 + v3) = 0;
      *((_BYTE *)&qword_34C + v5) = 1;
      *(int *)((char *)&dword_271C + v3) = 1;
      *((_BYTE *)&qword_354 + v5) = 1;
      *(int *)((char *)&dword_2724 + v3) = 500;
      *(int *)((char *)&dword_2730 + v3) = -65;
      *(int *)((char *)&dword_2738 + v3) = 0;
      *(int *)((char *)&dword_2744 + v3) = 3000;
      *((_BYTE *)&qword_3AC + v5) = 1;
      *((_BYTE *)&qword_3AC + v5 + 1) = 1;
      *(int *)((char *)&dword_277C + v3) = 6;
      *(int *)((char *)&dword_2780 + v3) = 100;
      *(int *)((char *)&dword_2784 + v3) = 1;
      *((_BYTE *)&qword_3BC + v5) = 1;
      *((_BYTE *)&qword_3BC + v5 + 1) = 0;
      *((_BYTE *)&qword_3BC + v5 + 2) = 0;
      *(int *)((char *)&dword_278C + v3) = 0;
      *(int *)((char *)&dword_2790 + v3) = 0;
      *((_BYTE *)&qword_3C4 + v5 + 4) = 1;
      *((_BYTE *)&qword_3CC + v5 + 4) = 0;
      *((_BYTE *)&qword_3CC + v5 + 5) = 1;
      *((_BYTE *)&qword_3E4 + v5 + 4) = 1;
      *(int *)((char *)&dword_27B8 + v3) = 1;
      *((_BYTE *)&qword_3EC + v5 + 4) = 1;
      *((_BYTE *)&qword_3EC + v5 + 5) = 0;
      *((_BYTE *)&qword_3EC + v5 + 6) = 0;
      *((_BYTE *)&qword_3EC + v5 + 7) = 1;
      *((_BYTE *)&qword_3F4 + v5) = 1;
      *((_BYTE *)&qword_3FC + v5 + 4) = 1;
      *((_BYTE *)&qword_3FC + v5 + 5) = 1;
      *((_BYTE *)&qword_3FC + v5 + 6) = 0;
      *((_BYTE *)&qword_3FC + v5 + 7) = 1;
      *((_BYTE *)&qword_404 + v5 + 4) = 1;
      *((_BYTE *)&qword_404 + v5 + 5) = 0;
      *((_BYTE *)&qword_404 + v5 + 6) = 1;
      *(int *)((char *)&dword_27D8 + v3) = 0;
      *(int *)((char *)&dword_27F0 + v3) = 0;
      *(int *)((char *)&dword_280C + v3) = 0;
      *(int *)((char *)&dword_2810 + v3) = 2000;
      *(int *)((char *)&dword_2828 + v3) = 0;
      *(int *)((char *)&dword_282C + v3) = 2000;
      *(int *)((char *)&dword_2844 + v3) = 0;
      *(int *)((char *)&dword_2848 + v3) = 2000;
      *(int *)((char *)&dword_284C + v3) = 0;
      *((_BYTE *)&qword_480 + v5 + 4) = 0;
      *(int *)((char *)&dword_2860 + v3) = 0;
      *((_BYTE *)&qword_498 + v5) = 1;
      *(int *)((char *)&dword_2868 + v3) = 3000;
      *(_WORD *)((char *)&qword_4A0 + v5) = 1;
      *((_BYTE *)&dword_4A8 + v5 + 2) = 1;
      *((_BYTE *)&qword_4AC + v5 + 4) = 1;
      *(int *)((char *)&dword_2888 + v3) = 0;
      *((_BYTE *)&qword_4BC + v5 + 4) = 1;
      *(int *)((char *)&dword_2890 + v3) = 1;
      *((_BYTE *)&qword_4C4 + v5 + 4) = 1;
      byte_4D4[v5] = 1;
      *(int *)((char *)&dword_28A8 + v3) = 0;
      *(__int64 *)((char *)&qword_28B0 + v3) = 0;
      byte_4D4[v5 + 24] = 1;
      *(int *)((char *)&dword_28BC + v3) = 15;
      byte_4D4[v5 + 34] = 1;
      *(int *)((char *)&dword_28C4 + v3) = 1;
      byte_4D4[v5 + 42] = 0;
      *(__int64 *)((char *)&qword_28E0 + v3) = 1;
      byte_524[v5] = 1;
      byte_524[v5 + 24] = 0;
      *(int *)((char *)&dword_290C + v3) = 7;
      byte_524[v5 + 32] = 0;
      *(int *)((char *)&dword_2934 + v3) = 15;
      byte_524[v5 + 72] = 1;
      byte_524[v5 + 84] = 1;
      *(int *)((char *)&dword_2948 + v3) = 1;
      byte_524[v5 + 92] = 1;
      *(int *)((char *)&dword_2988 + v3) = 1;
      *(_WORD *)&byte_524[v5 + 156] = 257;
      *(int *)((char *)&dword_2998 + v3) = 2000;
      sized_strscpy(v3 + 10652, &unk_8B9E43, 1);
      sized_strscpy(
        v3 + 11493,
        "000C43 00 25 C2 001018 06 02FFF02C0000 BC 25 42 001018 06 02FF040C0000 BC 25 42 00037F 00 35 6C 001018 06 02FF009C0000 BC 25 48",
        128);
      sized_strscpy(
        v3 + 12334,
        "001018 06 02FFF0040000 BC 21 40 001018 06 02FFF0050000 BC 21 40 001018 06 02FFF4050000 BC 21 40",
        96);
      sized_strscpy(v3 + 13175, "001018 06 0202001c0000 FC 01", 29);
      sized_strscpy(v3 + 14016, "00037F 06 01010000FF7F FC 01 000AEB 02 0100 C0 01 000B86 03 010408 E0 01", 73);
      sized_strscpy(v3 + 14857, "FFFFFF 00 2A F85971000000 E0 50 FFFFFF 00 2A 14ABC5000000 E0 50", 64);
      sized_strscpy(v3 + 15698, &unk_8B9E43, 1);
      sized_strscpy(v3 + 16539, &unk_8B9E43, 1);
      sized_strscpy(v3 + 17380, "00904C 05 0418BF0CB2 F8 21 40", 30);
      sized_strscpy(v3 + 18221, "00E04C 00 01", 13);
      sized_strscpy(
        v3 + 19062,
        "001018 00 01 000986 00 01 000ce7 00 01 00e0fc 00 01 000b86 04 01040817 F0 01 000b86 04 0104080F F0 01 000b86 04 01040819 F0 01",
        127);
      sized_strscpy(v3 + 19903, "0017f2 01 0a 80 01", 19);
      sized_strscpy(v3 + 20744, &unk_8B9E43, 1);
      sized_strscpy(v3 + 21585, "00e04c 03 020160 E0 01 001018 06 02FF009c0000 BC 01", 52);
      sized_strscpy(v3 + 22426, "000C43 04 07000000 F0 21 C0 000C43 04 03000000 F0 21 C0", 56);
      sized_strscpy(v3 + 23267, &unk_8B9E43, 1);
      sized_strscpy(v3 + 24108, "8CFDF0 13 040000494c510302097201cb17000009110000 FFFFE0 01", 59);
      sized_strscpy(v3 + 24949, &unk_8B9E43, 1);
      sized_strscpy(v3 + 25790, &unk_8B9E43, 1);
      sized_strscpy(v3 + 26631, &unk_8B9E43, 1);
      sized_strscpy(v3 + 27472, &unk_8B9E43, 1);
      sized_strscpy(v3 + 28313, "ffffff 00 01", 13);
      sized_strscpy(v3 + 29154, "F832E4 00 01", 13);
      sized_strscpy(v3 + 29995, "000CE7 00 01", 13);
      sized_strscpy(v3 + 30836, "18FE34 00 01", 13);
      *(_DWORD *)(v3 + 31680) = 1;
      sized_strscpy(v3 + 31684, "F832E4 00 01", 13);
      v8 = v3 + 31680;
      *((_BYTE *)&qword_34C + v8 + 1) = 0;
      *(_DWORD *)((char *)&qword_34C + v8 + 4) = 5;
      v9 = v11[0];
      *((_BYTE *)&qword_354 + v8) = 0;
      v2 = qdf_ini_parse(a1);
      if ( v2 )
      {
        qdf_trace_msg(80, 2, "%s: Failed to parse *.ini file @ %s; status:%d", "cfg_ini_parse_to_store", a1, v2);
        cfg_store_free(v9);
      }
      else
      {
        _cfg_global_store = v9;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
