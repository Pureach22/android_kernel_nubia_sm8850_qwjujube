__int64 __fastcall cfg_parse(char *a1)
{
  unsigned int v2; // w20
  __int64 v3; // x26
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x28
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
      *(__int64 *)((char *)&qword_28 + v11[0] + 4) = 0x700000005LL;
      *(_WORD *)((char *)&qword_38 + v3) = 257;
      *(_WORD *)((char *)&qword_40 + v3) = 257;
      *(_UNKNOWN **)((char *)&off_20 + v3 + 4) = (_UNKNOWN *)0x1E0000000ALL;
      *(__int64 *)((char *)&qword_40 + v3 + 4) = 0x6E00000050LL;
      *(_DWORD *)((char *)&qword_30 + v3 + 4) = 20;
      *(__int64 *)((char *)&qword_48 + v3 + 4) = 0x3C00000019LL;
      *(_DWORD *)((char *)&qword_38 + v3 + 4) = 40;
      *(_UNKNOWN **)((char *)&off_50 + v3 + 4) = (_UNKNOWN *)0x280000003CLL;
      *(__int16 *)((char *)&word_C0 + v3) = 257;
      *(__int64 *)((char *)&qword_60 + v3 + 4) = 0x100000014LL;
      *(int *)((char *)&dword_6C + v3) = 4;
      *(__int64 *)((char *)&qword_58 + v3 + 4) = 40;
      *(__int64 *)((char *)&qword_74 + v3) = 0x280000006ELL;
      *(_UNKNOWN **)((char *)&off_18 + v3 + 4) = (_UNKNOWN *)0x300000005LL;
      *(__int64 *)((char *)&qword_7C + v3) = 0x3200000064LL;
      v4 = v3 + 669;
      *(int *)((char *)&dword_84 + v3) = 25;
      *(__int64 *)((char *)&qword_3B0 + v3) = 0x300000005LL;
      *(__int64 *)((char *)&qword_8C + v3) = 0x10000001ELL;
      *(__int64 *)((char *)&qword_178 + v3) = 0x100000001000LL;
      *(__int64 *)((char *)&qword_178 + v3 + 8) = 0x100000001000LL;
      *(__int64 *)((char *)&qword_AC + v3) = 0x200000004LL;
      *(__int64 *)((char *)&qword_3B8 + v3) = 0x140000001ELL;
      *(__int64 *)((char *)&qword_B8 + v3) = 0xE100000000ALL;
      *(__int64 *)((char *)&qword_3C0 + v3) = 0x4600000037LL;
      *(__int64 *)((char *)&qword_C4 + v3) = 0x60000001ELL;
      *(__int64 *)((char *)&qword_3C8 + v3) = 0x5000000050LL;
      *(__int64 *)((char *)&qword_D0 + v3) = 0xA00000003LL;
      *(__int64 *)((char *)&qword_D0 + v3 + 8) = 0x10000EA60LL;
      *(__int64 *)((char *)&qword_3D0 + v3) = 0x500000019LL;
      *(__int64 *)((char *)&qword_E8 + v3) = 0x271000000003LL;
      *(int *)((char *)&dword_F0 + v3) = 60000;
      *(__int64 *)((char *)&qword_3D8 + v3) = 0x4C00000005LL;
      *(__int64 *)((char *)&qword_F8 + v3) = 0x3C00007530LL;
      *(__int64 *)((char *)&qword_F8 + v3 + 8) = 0x100000002LL;
      *(__int64 *)((char *)&qword_108 + v3) = 1;
      *(__int64 *)((char *)&qword_108 + v3 + 8) = 0x100000000LL;
      *(__int64 *)((char *)&qword_118 + v3) = 0x80000001ELL;
      *(__int64 *)((char *)&qword_118 + v3 + 8) = 0x20000000100LL;
      *((_BYTE *)&qword_38 + v3 + 2) = 0;
      *(__int64 *)((char *)&qword_128 + v3) = 0x20000000000008LL;
      *(__int64 *)((char *)&qword_128 + v3 + 8) = 0x4000000040LL;
      *(__int64 *)((char *)&qword_3E0 + v3) = 0x552A150AFFFFFFB5LL;
      *(__int64 *)((char *)&qword_138 + v3) = 0x300000008LL;
      *(__int64 *)((char *)&qword_138 + v3 + 8) = 0x200000003LL;
      *(__int64 *)((char *)&qword_148 + v3) = 0x100000000002LL;
      *(__int64 *)((char *)&qword_148 + v3 + 8) = 0x100000001000LL;
      *(__int64 *)((char *)&qword_168 + v3) = 3;
      *(__int64 *)((char *)&qword_168 + v3 + 8) = 0x6400000000LL;
      *(__int64 *)((char *)&qword_198 + v3) = 0x80000000800LL;
      *(__int64 *)((char *)&qword_198 + v3 + 8) = 0x2000;
      *(__int64 *)((char *)&qword_158 + v3) = 0x100000001000LL;
      *(__int64 *)((char *)&qword_158 + v3 + 8) = 0x100000000400LL;
      *(__int64 *)((char *)&qword_1A8 + v3) = 3000;
      *(__int64 *)((char *)&qword_1A8 + v3 + 8) = 0x10100000001LL;
      *(_QWORD *)(v3 + 444) = 0;
      *(_QWORD *)(v3 + 452) = 0x101010100000000LL;
      byte_1CC[v3] = 1;
      *(__int64 *)((char *)&qword_188 + v3) = 0x80000001000LL;
      *(__int64 *)((char *)&qword_188 + v3 + 8) = 0x80000000800LL;
      *(__int64 *)((char *)&qword_1F0 + v3) = 0x80000000800LL;
      *(__int64 *)((char *)&qword_1F0 + v3 + 8) = 0x80000000800LL;
      *(__int64 *)((char *)&qword_1D0 + v3) = 0x20000000400LL;
      *(__int64 *)((char *)&qword_1D0 + v3 + 8) = 0x100000000020LL;
      *(__int64 *)((char *)&qword_200 + v3) = 0x10000000080LL;
      *(__int64 *)((char *)&qword_1E0 + v3) = 0x40000000080LL;
      *(__int64 *)((char *)&qword_1E0 + v3 + 8) = 0x80000000100LL;
      *(_QWORD *)(v3 + 532) = 0;
      *(_QWORD *)(v3 + 540) = 0x1000000000000LL;
      *(_QWORD *)(v3 + 548) = 0x40000000400LL;
      *(__int64 *)((char *)&qword_208 + v3) = 0x100000000400LL;
      *(_QWORD *)(v3 + 556) = 0x4000000C000LL;
      *(_QWORD *)(v3 + 564) = 0x80000001000LL;
      *(_QWORD *)(v3 + 572) = 0x100000000400LL;
      *(_QWORD *)(v3 + 580) = 1024;
      *(int *)((char *)&dword_25C + v3) = 1024;
      *(__int64 *)((char *)&qword_2F0 + v3) = 1024;
      *(__int64 *)((char *)&qword_3E8 + v3) = 0x6443005032190CLL;
      *(__int64 *)((char *)&qword_2F8 + v3) = 0x200000001LL;
      *(__int64 *)((char *)&qword_310 + v3) = 0x1000000000000LL;
      *(__int64 *)((char *)&qword_300 + v3) = 0x8000000003LL;
      *(__int64 *)((char *)&qword_3F0 + v3) = 0x505A643200000008LL;
      *(__int64 *)((char *)&qword_308 + v3) = 0x68000000010LL;
      *(_QWORD *)(v3 + 588) = 0xF0000000ALL;
      *(_QWORD *)(v3 + 796) = 0x96000007D0LL;
      *(_QWORD *)(v3 + 804) = 0xA00000003LL;
      *(__int64 *)((char *)&qword_3F8 + v3) = 0x50A193246LL;
      *(__int64 *)((char *)&qword_348 + v3) = 0x1E0000001ELL;
      *(__int64 *)((char *)&qword_400 + v3) = 0xF00000000LL;
      *(__int64 *)((char *)&qword_408 + v3) = 50;
      *(__int64 *)((char *)&qword_350 + v3) = 0x1F40000001ELL;
      *(_QWORD *)(v3 + 596) = 0xBB800000800LL;
      *(__int64 *)((char *)&qword_358 + v3) = 0x320000012CLL;
      *(__int64 *)((char *)&qword_410 + v3) = 0x6432190C06030000LL;
      *(__int64 *)((char *)&qword_360 + v3) = 0x6000003E8LL;
      *(__int64 *)((char *)&qword_420 + v3) = 0x4B402064FFFFFFFFLL;
      *(__int64 *)((char *)&qword_368 + v3) = 0x30000000ALL;
      *(int *)((char *)&dword_370 + v3) = 30;
      *(__int64 *)((char *)&qword_428 + v3) = 0x215584B3FLL;
      *(__int64 *)((char *)&qword_378 + v3) = 0x60600000200LL;
      *(__int64 *)((char *)&qword_430 + v3) = 0x3200000032LL;
      *(__int64 *)((char *)&qword_380 + v3) = 0x1400000000LL;
      *(_QWORD *)(v3 + 612) = 0x100000001LL;
      *(__int64 *)((char *)&qword_390 + v3) = 0x1400000002LL;
      *(__int64 *)((char *)&qword_440 + v3) = 0x4B403F35342A2A1FLL;
      *(__int64 *)((char *)&qword_398 + v3) = 0x1400000003LL;
      *(__int64 *)((char *)&qword_3A0 + v3) = 0xA00000002LL;
      *(__int64 *)((char *)&qword_448 + v3) = 0x485A5148574E4455LL;
      *(__int64 *)((char *)&qword_3A8 + v3) = 0x200000019LL;
      *(int *)((char *)&dword_438 + v3) = 50;
      *(__int64 *)((char *)&qword_450 + v3) = 0x645E58524B5F5850LL;
      *(int *)((char *)&dword_458 + v3) = 6574105;
      *(_QWORD *)(v3 + 1116) = 50462976;
      *(_QWORD *)(v3 + 1140) = 0x32000000000LL;
      *((_BYTE *)&qword_40 + v3 + 2) = 0;
      *(_QWORD *)(v3 + 1148) = 0xC800000190LL;
      *(int *)((char *)&dword_484 + v3) = 100;
      *(int *)((char *)&dword_48C + v3) = 512;
      v5 = v3 + 5004;
      *(__int64 *)((char *)&qword_498 + v3) = 0x5000000000LL;
      *(_QWORD *)(v3 + 620) = 0x8000001000LL;
      *(__int64 *)((char *)&qword_4A0 + v3) = 0xA0000000ALL;
      *(_QWORD *)(v3 + 1196) = 0x1E0000003FLL;
      *(int *)((char *)&dword_274 + v3) = 0x1000000;
      *(_QWORD *)(v3 + 1204) = 0x100000004LL;
      byte_70[v3] = 1;
      *(_QWORD *)(v3 + 1212) = 0x4B000000005LL;
      *(_QWORD *)(v3 + 1220) = 3;
      *(__int64 *)((char *)&qword_278 + v3) = 0xA00000020LL;
      *(_QWORD *)(v3 + 1228) = 0x6400000019LL;
      *(_QWORD *)(v3 + 644) = 7;
      *(int *)((char *)&dword_28C + v3) = 0x10000;
      *(_QWORD *)(v3 + 1236) = 0xFFFFFFBFFFFFFFB0LL;
      *(_QWORD *)(v3 + 660) = 0x1FFFF0001FFFFLL;
      *(_QWORD *)(v3 + 1244) = 0xFFFFFFEBFFFFFFE7LL;
      *(_QWORD *)(v3 + 676) = 0x20000000ALL;
      *(_QWORD *)(v3 + 1252) = 0xFFFFFFF0FFFFFFECLL;
      *(_QWORD *)(v3 + 692) = 0x40000001000LL;
      *(_QWORD *)(v3 + 700) = 2048;
      *(_QWORD *)(v3 + 1260) = 0xFFFFFFF5FFFFFFF1LL;
      *(_QWORD *)(v3 + 708) = 0x40000000000LL;
      *(int *)((char *)&dword_4F4 + v3) = 65537;
      *(__int64 *)((char *)&qword_500 + v3) = 0x2E00000000LL;
      *(_QWORD *)(v3 + 716) = 0x12C00000400LL;
      *(_QWORD *)(v3 + 724) = 0;
      *(_QWORD *)(v3 + 732) = 0;
      *(__int64 *)((char *)&qword_508 + v3) = 0x1010000001ALL;
      *(_DWORD *)((char *)&qword_2E8 + v3) = 15;
      *(__int16 *)((char *)&word_88 + v3) = 256;
      v6 = v3 + 9256;
      *(__int64 *)((char *)&qword_94 + v3) = 0;
      *(int *)((char *)&dword_9C + v3) = 0;
      byte_A0[v3] = 1;
      *(int *)((char *)&dword_A4 + v3) = 0;
      byte_A8[v3] = 1;
      *(__int16 *)((char *)&word_B4 + v3) = 0;
      byte_CC[v3] = 0;
      *(int *)((char *)&dword_E0 + v3) = 0;
      byte_E4[v3] = 0;
      byte_F4[v3] = 1;
      byte_1B8[v3] = 0;
      *(__int16 *)((char *)&word_210 + v3) = 0;
      byte_260[v3] = 0;
      byte_280[v3] = 0;
      *(__int16 *)((char *)&word_290 + v3) = 256;
      byte_29C[v3] = 1;
      *(_DWORD *)(v3 + 669) = 0;
      *(int *)((char *)&dword_2AC + v3) = 3;
      *(__int16 *)((char *)&word_2B0 + v3) = 256;
      byte_2B2[v3] = 1;
      byte_2E4[v3] = 1;
      *((_BYTE *)&qword_2E8 + v3 + 4) = 0;
      *(__int16 *)((char *)&word_318 + v3) = 257;
      *(__int16 *)((char *)&word_32C + v3) = 0;
      *(__int64 *)((char *)&qword_330 + v3) = 0;
      *(int *)((char *)&dword_338 + v3) = 1;
      *(__int16 *)((char *)&word_33C + v3) = 0;
      *(__int64 *)((char *)&qword_340 + v3) = 0x100000000LL;
      byte_374[v3] = 0;
      *(__int64 *)((char *)&qword_388 + v3) = 0x100000001LL;
      *(int *)((char *)&dword_418 + v3) = 0;
      *(__int16 *)((char *)&word_41C + v3) = 256;
      *(__int16 *)((char *)&word_43C + v3) = 257;
      byte_43E[v3] = 1;
      *(int *)((char *)&dword_464 + v3) = 2;
      byte_468[v3] = 0;
      *(int *)((char *)&dword_46C + v3) = 0;
      byte_470[v3] = 0;
      byte_488[v3] = 0;
      *(__int16 *)((char *)&word_494 + v3) = 256;
      *(int *)((char *)&dword_490 + v3) = 0;
      byte_4A8[v3] = 1;
      *(__int64 *)((char *)&qword_4F8 + v3) = 1;
      *(__int64 *)((char *)&qword_510 + v3) = 0x300000021LL;
      *(int *)((char *)&dword_518 + v3) = 3;
      sized_strscpy(
        v3 + 1308,
        "1,1,2,1,3,1,4,1,5,1,11,1,9,1,13,1,14,1,17,1,18,1,19,1,22,1,26,1,28,1,29,1,31,1,36,1,38,1,46,1,47,1,50,1,52,1,53,"
        "1,56,1,60,1,61,1,113,1",
        135);
      *(_WORD *)(v3 + 1821) = 1;
      *(__int64 *)((char *)&qword_720 + v3) = 0x2F000000FFLL;
      *(__int16 *)((char *)&word_728 + v3) = 256;
      byte_72A[v3] = 1;
      *(_QWORD *)(v3 + 1836) = 0x1700000000LL;
      byte_734[v3] = 0;
      *(int *)((char *)&dword_738 + v3) = 1;
      sized_strscpy(v3 + 1852, "1,3,5,3,18,1,19,3,31,1,36,1,57,3", 33);
      *(int *)((char *)&dword_940 + v3) = 1;
      *(__int16 *)((char *)&word_944 + v3) = 256;
      *(int *)((char *)&dword_948 + v3) = 0;
      *(__int16 *)((char *)&word_94C + v3) = 0;
      *(__int64 *)((char *)&qword_950 + v3) = 0;
      *(__int64 *)((char *)&qword_958 + v3) = 0;
      *(__int64 *)((char *)&qword_960 + v3) = 0;
      *(__int64 *)((char *)&qword_968 + v3) = 0;
      sized_strscpy(v3 + 2416, &unk_98C763, 1);
      *(_QWORD *)(v3 + 2580) = 0x5A00000000LL;
      *(_QWORD *)(v3 + 2588) = 0x6E00000046LL;
      *(_QWORD *)(v3 + 2596) = 0x7D0000005ALL;
      *(_QWORD *)(v3 + 2604) = 110;
      byte_A44[v3] = 0;
      *(_QWORD *)(v3 + 2612) = 0x7500000074LL;
      *(__int64 *)((char *)&qword_A50 + v3) = 0x1E0000000ALL;
      *(_QWORD *)(v3 + 2620) = 0x7800000076LL;
      *(__int64 *)((char *)&qword_A48 + v3) = 4000;
      *(__int64 *)((char *)&qword_A60 + v3) = 0x640000005ALL;
      *(__int64 *)((char *)&qword_A58 + v3) = 0x4600000032LL;
      *(__int64 *)((char *)&qword_A90 + v3) = 0x4600000032LL;
      *(__int64 *)((char *)&qword_A98 + v3) = 90;
      *(__int64 *)((char *)&qword_AA0 + v3) = 0x300000000LL;
      *(__int64 *)((char *)&qword_AA8 + v3) = 0x432100000000LL;
      *(__int64 *)((char *)&qword_A68 + v3) = 0x100000001LL;
      *(__int64 *)((char *)&qword_A70 + v3) = 0x500000000LL;
      *(__int64 *)((char *)&qword_AC0 + v3) = 0x600000001LL;
      *(int *)((char *)&dword_A78 + v3) = 100;
      *(_QWORD *)(v3 + 2772) = 1;
      *(_QWORD *)(v3 + 2788) = 0x400000000LL;
      *(_QWORD *)(v3 + 2796) = 0;
      byte_A7C[v3] = 0;
      *(_DWORD *)(v3 + 2805) = 16777217;
      *(_QWORD *)(v3 + 2812) = 0x100000000LL;
      *(int *)((char *)&dword_B04 + v3) = 5;
      *(int *)((char *)&dword_B0C + v3) = 400;
      *(__int64 *)((char *)&qword_A80 + v3) = 1;
      *(__int64 *)((char *)&qword_A88 + v3) = 0x1E0000000ALL;
      *(__int64 *)((char *)&qword_AB0 + v3) = 3;
      *(int *)((char *)&dword_AB8 + v3) = 0;
      byte_ABC[v3] = 1;
      byte_AC8[v3] = 0;
      *(int *)((char *)&dword_ACC + v3) = 2;
      byte_AD0[v3] = 0;
      *(int *)((char *)&dword_ADC + v3) = 1;
      byte_AE0[v3] = 1;
      byte_AF4[v3] = 0;
      byte_B08[v3] = 1;
      byte_B10[v3] = 1;
      *(_QWORD *)(v3 + 2836) = 0x20000001ELL;
      *(__int16 *)((char *)&word_B1C + v3) = 1;
      sized_strscpy(v3 + 2846, &unk_98C763, 1);
      *(_DWORD *)((char *)&qword_B48 + v3 + 4) = -1;
      sized_strscpy(v3 + 2896, &unk_98C763, 1);
      *(_QWORD *)(v3 + 2916) = 0x100000000000001LL;
      *(int *)((char *)&dword_B70 + v3) = 250;
      byte_B6C[v3] = 0;
      *(__int64 *)((char *)&qword_B78 + v3) = 0x400000001LL;
      *(__int16 *)((char *)&word_B74 + v3) = 256;
      *(__int64 *)((char *)&qword_B80 + v3) = 0x10000096CLL;
      *(__int64 *)((char *)&qword_B88 + v3) = 0x1FFFFFFFFLL;
      *(__int16 *)((char *)&word_B98 + v3) = 256;
      *(__int64 *)((char *)&qword_B90 + v3) = 0xC00000003LL;
      byte_B9A[v3] = 1;
      sized_strscpy(v3 + 2971, &unk_98C763, 1);
      *(int *)((char *)&dword_FB0 + v3) = 400;
      *(int *)((char *)&dword_F88 + v3) = 300000;
      *(int *)((char *)&dword_F98 + v3) = 11;
      *(int *)((char *)&dword_F9C + v3) = 11;
      *(int *)((char *)&dword_FA8 + v3) = 16000;
      *(int *)((char *)&dword_F8C + v3) = 15000;
      *(int *)((char *)&dword_F90 + v3) = 1000;
      *(int *)((char *)&dword_F94 + v3) = 5;
      *(int *)((char *)&dword_FA0 + v3) = 0;
      *(__int16 *)((char *)&word_FA4 + v3) = 0;
      byte_FAC[v3] = 0;
      byte_FB4[v3] = 1;
      byte_FB5[v3] = 1;
      byte_FB6[v3] = 0;
      byte_FB7[v3] = 1;
      *(__int16 *)((char *)&word_FB8 + v3) = 0;
      byte_FBA[v3] = 1;
      byte_FBB[v3] = 0;
      byte_FBC[v3] = 0;
      *(int *)((char *)&dword_FC0 + v3) = 100000;
      byte_FC4[v3] = 0;
      *(int *)((char *)&dword_FD4 + v3) = 0;
      *(__int64 *)((char *)&qword_FD8 + v3) = 0;
      byte_FD0[v3] = 0;
      *(__int64 *)((char *)&qword_FC8 + v3) = 0;
      *(__int64 *)((char *)&qword_FE0 + v3) = 30;
      *(int *)((char *)&dword_FE8 + v3) = 0;
      sized_strscpy(v3 + 4076, "e", 2);
      *(int *)((char *)&dword_1034 + v3) = 0;
      *(int *)((char *)&dword_100C + v3) = 20;
      *(int *)((char *)&dword_1010 + v3) = 64;
      *(int *)((char *)&dword_1014 + v3) = 64;
      byte_D24[v4 + 74] = 0;
      *(int *)((char *)&dword_101C + v3) = 500000;
      *(int *)((char *)&dword_102C + v3) = 50;
      *(int *)((char *)&dword_1018 + v3) = 0;
      *(_DWORD *)(v3 + 4151) = 0;
      *(int *)((char *)&dword_103C + v3) = 22000;
      *(int *)((char *)&dword_1040 + v3) = 12000;
      *(int *)((char *)&dword_1044 + v3) = 10000;
      *(int *)((char *)&dword_104C + v3) = 6000;
      *(int *)((char *)&dword_1050 + v3) = 2000;
      *(int *)((char *)&dword_1058 + v3) = 150;
      *(int *)((char *)&dword_105C + v3) = 100;
      *(int *)((char *)&dword_106C + v3) = 500;
      *(int *)((char *)&dword_1078 + v3) = 500;
      *(int *)((char *)&dword_107C + v3) = 10;
      *(int *)((char *)&dword_1020 + v3) = 1;
      *(int *)((char *)&dword_1024 + v3) = 500;
      byte_D24[v4 + 103] = 0;
      byte_D24[v4 + 104] = 1;
      *(int *)((char *)&dword_1030 + v3) = 1;
      *(int *)((char *)&dword_1048 + v3) = 0;
      *(int *)((char *)&dword_1054 + v3) = 500;
      byte_D24[v4 + 159] = 1;
      *(int *)((char *)&dword_1064 + v3) = 1;
      byte_D24[v4 + 167] = 1;
      *(int *)((char *)&dword_1070 + v3) = 1000;
      *(int *)((char *)&dword_1074 + v3) = 30;
      byte_DE3[v4] = 0;
      *(int *)((char *)&dword_1084 + v3) = 0;
      byte_DE3[v4 + 8] = 1;
      sized_strscpy(v3 + 4233, "1, 6, 2, 126", 13);
      *(int *)((char *)&dword_10A0 + v3) = 23;
      *(_DWORD *)(v3 + 4262) = 0;
      *(_QWORD *)(v3 + 4267) = 0;
      byte_E07[v4] = 1;
      byte_E07[v4 + 1] = 1;
      byte_E07[v4 + 6] = 1;
      *(__int64 *)((char *)&qword_10B0 + v3) = 0;
      byte_E07[v4 + 20] = 1;
      byte_E07[v4 + 21] = 1;
      *(int *)((char *)&dword_10BC + v3) = 8;
      sized_strscpy(v3 + 4288, &unk_98C763, 1);
      sized_strscpy(v3 + 4339, &unk_98C763, 1);
      sized_strscpy(v3 + 4390, &unk_98C763, 1);
      sized_strscpy(v3 + 4441, &unk_98C763, 1);
      byte_EA0[v4 + 79] = 0;
      *(int *)((char *)&dword_1190 + v3) = 16448250;
      byte_EA0[v4 + 80] = 1;
      byte_EA0[v4 + 87] = 0;
      byte_EA0[v4 + 88] = 0;
      byte_EA0[v4 + 89] = 1;
      sized_strscpy(
        v3 + 4503,
        "2407-5875=40, 5945-7125=90, 5975=100, 6055=100, 6135=100, 6215=100, 6295=100, 6375=100, 6615=100, 6695=100, 6775=100, 6855=100",
        127);
      *(int *)((char *)&dword_1398 + v3) = -62;
      *(int *)((char *)&dword_13A0 + v3) = 449;
      *(int *)((char *)&dword_13A8 + v3) = 3;
      *(int *)((char *)&dword_13B0 + v3) = -1;
      *(int *)((char *)&dword_13B4 + v3) = 10000;
      *(int *)((char *)&dword_13BC + v3) = 2600;
      v7 = v3 + 5068;
      *(_BYTE *)(v3 + 5004) = 0;
      *(_QWORD *)(v3 + 5068) = 0;
      *(_QWORD *)(v3 + 5076) = 0;
      *(_UNKNOWN **)((char *)&off_10 + v7) = nullptr;
      *(_UNKNOWN **)((char *)&off_10 + v7 + 8) = nullptr;
      *(_QWORD *)(v3 + 5100) = 0x200000136LL;
      *(_QWORD *)(v3 + 5116) = 0;
      *(int *)((char *)&dword_1390 + v3) = 1;
      *(int *)((char *)&dword_1394 + v3) = 0;
      *((_BYTE *)&off_10 + v5) = 1;
      *((_BYTE *)&off_10 + v5 + 1) = 1;
      *(int *)((char *)&dword_13A4 + v3) = 100;
      *(int *)((char *)&dword_13AC + v3) = 0;
      *(int *)((char *)&dword_13B8 + v3) = 8;
      *(int *)((char *)&dword_13C0 + v3) = 1;
      *(int *)((char *)&dword_13C4 + v3) = 1;
      *((_BYTE *)&qword_38 + v5 + 4) = 0;
      *(int *)((char *)&dword_1404 + v3) = 0;
      *(int *)((char *)&dword_13F4 + v3) = 0;
      *((_BYTE *)&off_0 + v3 + 5112) = 0;
      sized_strscpy(
        v3 + 5128,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 5216,
        "0x0, 0x2, 0x0, 0xf, 0x3, 0xff, 0x64, 0x0, 0x1f, 0x3, 0xff, 0x64, 0x0, 0xf, 0x3, 0xff, 0x64",
        91);
      sized_strscpy(
        v3 + 5307,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0xc8, 0x0, 0xf, 0x0, 0x1f, 0xbc, 0x0, 0x7, 0x0, 0xf, 0xc8",
        88);
      sized_strscpy(
        v3 + 5395,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x64, 0x0, 0x7, 0x0, 0xf, 0x66, 0x0, 0x3, 0x0, 0x7, 0x64",
        87);
      sized_strscpy(
        v3 + 5482,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 5570,
        "0x0, 0x2, 0x0, 0xf, 0x3, 0xff, 0x64, 0x0, 0x1f, 0x3, 0xff, 0x64, 0x0, 0xf, 0x3, 0xff, 0x64",
        91);
      sized_strscpy(
        v3 + 5661,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0xc8, 0x0, 0xf, 0x0, 0x1f, 0xbc, 0x0, 0x7, 0x0, 0xf, 0xc8",
        88);
      sized_strscpy(
        v3 + 5749,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x64, 0x0, 0x7, 0x0, 0xf, 0x66, 0x0, 0x3, 0x0, 0x7, 0x64",
        87);
      sized_strscpy(
        v3 + 5836,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 5924,
        "0x0, 0x3, 0x0, 0xf, 0x0, 0x3f, 0x0, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x0, 0x3f, 0x0",
        88);
      sized_strscpy(
        v3 + 6012,
        "0x0, 0x1, 0x0, 0x7, 0x0, 0xf, 0x5e, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 6099,
        "0x0, 0x1, 0x0, 0x3, 0x0, 0x7, 0x2f, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      sized_strscpy(
        v3 + 6186,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        87);
      sized_strscpy(
        v3 + 6273,
        "0x0, 0x3, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        87);
      sized_strscpy(
        v3 + 6360,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0x5e, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 6447,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x2f, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      sized_strscpy(
        v3 + 6534,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0xbb, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        89);
      sized_strscpy(
        v3 + 6623,
        "0x0, 0x3, 0x0, 0xf, 0x0, 0x3f, 0xbb, 0x0, 0x1f, 0x3, 0xff, 0x0, 0x0, 0xf, 0x0, 0x3f, 0x0",
        89);
      sized_strscpy(
        v3 + 6712,
        "0x0, 0x1, 0x0, 0x7, 0x0, 0xf, 0x7d, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 6799,
        "0x0, 0x1, 0x0, 0x3, 0x0, 0x7, 0x3e, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      sized_strscpy(
        v3 + 6886,
        "0x0, 0x7, 0x0, 0xf, 0x3, 0xff, 0xbb, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 6974,
        "0x0, 0x3, 0x0, 0xf, 0x3, 0xff, 0xbb, 0x0, 0xf, 0x3, 0xff, 0x0, 0x0, 0xf, 0x3, 0xff, 0x0",
        88);
      sized_strscpy(
        v3 + 7062,
        "0x0, 0x2, 0x0, 0x7, 0x0, 0xf, 0x7d, 0x0, 0x7, 0x0, 0xf, 0xbc, 0x0, 0x7, 0x0, 0xf, 0x5e",
        87);
      sized_strscpy(
        v3 + 7149,
        "0x0, 0x2, 0x0, 0x3, 0x0, 0x7, 0x3e, 0x0, 0x3, 0x0, 0x7, 0x66, 0x0, 0x3, 0x0, 0x7, 0x2f",
        87);
      *(int *)((char *)&dword_1C48 + v3) = 2;
      *(int *)((char *)&dword_1C50 + v3) = 2;
      *(int *)((char *)&dword_1C5C + v3) = 2;
      *(int *)((char *)&dword_1C64 + v3) = 10;
      *(int *)((char *)&dword_1C70 + v3) = 10;
      *(int *)((char *)&dword_1C4C + v3) = 3;
      *(int *)((char *)&dword_1C54 + v3) = 3;
      byte_8B8[v5] = 0;
      *(int *)((char *)&dword_1C58 + v3) = 4;
      *(int *)((char *)&dword_1C60 + v3) = 4;
      *(int *)((char *)&dword_1C68 + v3) = 7;
      *(int *)((char *)&dword_1C6C + v3) = 4;
      byte_8B8[v5 + 48] = 1;
      *(int *)((char *)&dword_1C78 + v3) = 3;
      *(int *)((char *)&dword_1C7C + v3) = 0;
      byte_8B8[v5 + 60] = 1;
      byte_8B8[v5 + 61] = 0;
      *(int *)((char *)&dword_1C84 + v3) = 100;
      sized_strscpy(v3 + 7304, "0x73,0x1A,0x91,0x00,0x04", 25);
      byte_8B8[v5 + 109] = 1;
      byte_8B8[v5 + 110] = 0;
      *(int *)((char *)&dword_1CB4 + v3) = 0;
      byte_8B8[v5 + 116] = 0;
      sized_strscpy(v3 + 7353, "0x0", 4);
      sized_strscpy(v3 + 7372, "0x3000100000083", 16);
      sized_strscpy(v3 + 7391, "0xa", 4);
      sized_strscpy(v3 + 7410, "0x180D83", 9);
      *(int *)((char *)&dword_1D28 + v3) = 5;
      *(int *)((char *)&dword_1D2C + v3) = 200;
      *(__int64 *)((char *)&qword_1D08 + v3) = 0;
      *(int *)((char *)&dword_1D30 + v3) = 196623;
      *(int *)((char *)&dword_1D5C + v3) = 512;
      *(int *)((char *)&dword_1D68 + v3) = 15;
      *(int *)((char *)&dword_1D74 + v3) = 82;
      *(int *)((char *)&dword_1D10 + v3) = 1;
      byte_988[v5] = 0;
      *(int *)((char *)&dword_1D18 + v3) = 1;
      *(int *)((char *)&dword_1D1C + v3) = 1;
      byte_988[v5 + 12] = 1;
      *(int *)((char *)&dword_1D24 + v3) = 1;
      byte_988[v5 + 32] = 1;
      byte_988[v5 + 33] = 1;
      byte_988[v5 + 34] = 1;
      *(int *)((char *)&dword_1D38 + v3) = 7;
      byte_988[v5 + 40] = 0;
      *(int *)((char *)&dword_1D40 + v3) = 0;
      byte_988[v5 + 48] = 1;
      byte_988[v5 + 49] = 0;
      byte_988[v5 + 50] = 0;
      byte_988[v5 + 51] = 1;
      *(_WORD *)&byte_988[v5 + 52] = 0;
      *(int *)((char *)&dword_1D4C + v3) = 2;
      byte_988[v5 + 60] = 0;
      byte_988[v5 + 61] = 1;
      *(int *)((char *)&dword_1D54 + v3) = 0;
      byte_988[v5 + 68] = 0;
      byte_988[v5 + 69] = 1;
      *(int *)((char *)&dword_1D60 + v3) = 0;
      byte_988[v5 + 80] = 0;
      *(_WORD *)&byte_988[v5 + 88] = 0;
      byte_988[v5 + 90] = 1;
      *(int *)((char *)&dword_1D70 + v3) = 0;
      byte_988[v5 + 100] = 0;
      *(int *)((char *)&dword_1D7C + v3) = 0;
      *(int *)((char *)&dword_1D80 + v3) = 0;
      sized_strscpy(v3 + 7556, &unk_98C763, 1);
      *(int *)((char *)&dword_1DD4 + v3) = 3;
      *(int *)((char *)&dword_1DE0 + v3) = 3;
      *(int *)((char *)&dword_1DE8 + v3) = 3;
      *(int *)((char *)&dword_1DF4 + v3) = 3;
      *(int *)((char *)&dword_1DF8 + v3) = 3;
      *(int *)((char *)&dword_1E00 + v3) = 65450;
      *(int *)((char *)&dword_1E04 + v3) = 65450;
      *(int *)((char *)&dword_1E08 + v3) = 65450;
      *(int *)((char *)&dword_1E0C + v3) = 65450;
      *(int *)((char *)&dword_1E10 + v3) = 65450;
      *(int *)((char *)&dword_1DD8 + v3) = 16843009;
      *(int *)((char *)&dword_1E1C + v3) = 364429998;
      *(__int16 *)((char *)&word_1DDC + v3) = 257;
      *(int *)((char *)&dword_1E20 + v3) = -1;
      *(int *)((char *)&dword_1E2C + v3) = 300;
      *(int *)((char *)&dword_1E30 + v3) = -66;
      *(int *)((char *)&dword_1E88 + v3) = 300;
      *(int *)((char *)&dword_1E34 + v3) = 5;
      *(int *)((char *)&dword_1E38 + v3) = 5;
      *(int *)((char *)&dword_1E8C + v3) = 25;
      *(int *)((char *)&dword_1E48 + v3) = -73;
      *(int *)((char *)&dword_1E90 + v3) = 83;
      *(int *)((char *)&dword_1E4C + v3) = -43;
      *(int *)((char *)&dword_1E94 + v3) = 30;
      *(int *)((char *)&dword_1E60 + v3) = 1060;
      *(int *)((char *)&dword_1E98 + v3) = 5;
      *(int *)((char *)&dword_1EBC + v3) = 5;
      *(int *)((char *)&dword_1EC0 + v3) = 5;
      *(int *)((char *)&dword_1EC8 + v3) = 5;
      *(int *)((char *)&dword_1ECC + v3) = 5;
      *(int *)((char *)&dword_1ED4 + v3) = 5;
      *(int *)((char *)&dword_1E70 + v3) = 2000;
      *(int *)((char *)&dword_1E80 + v3) = 200;
      *((_BYTE *)&qword_A34 + v5 + 5) = 1;
      *((_BYTE *)&qword_A34 + v5 + 6) = 1;
      *(int *)((char *)&dword_1DC8 + v3) = 1;
      *(int *)((char *)&dword_1DCC + v3) = 1;
      *(_WORD *)&byte_A44[v5] = 0;
      byte_A46[v5] = 1;
      *((_BYTE *)&qword_A50 + v5 + 2) = 0;
      *(int *)((char *)&dword_1DE4 + v3) = 0;
      *(int *)((char *)&dword_1DEC + v3) = 4;
      *((_BYTE *)&qword_A60 + v5 + 4) = 1;
      *(int *)((char *)&dword_1DFC + v3) = 0;
      *(int *)((char *)&dword_1E14 + v3) = 0;
      *((_BYTE *)&qword_A88 + v5 + 4) = 1;
      *((_BYTE *)&qword_A88 + v5 + 5) = 1;
      *(int *)((char *)&dword_1E24 + v3) = 0;
      *((_BYTE *)&qword_A98 + v5 + 4) = 0;
      *(int *)((char *)&dword_1E3C + v3) = 0;
      *(int *)((char *)&dword_1E40 + v3) = 0;
      *((_BYTE *)&dword_AB8 + v5) = 1;
      *((_BYTE *)&dword_AB8 + v5 + 1) = 0;
      *(int *)((char *)&dword_1E50 + v3) = 400;
      *(int *)((char *)&dword_1E54 + v3) = 10;
      *(int *)((char *)&dword_1E58 + v3) = 3;
      *(int *)((char *)&dword_1E5C + v3) = -76;
      *(int *)((char *)&dword_1E64 + v3) = 40;
      *(int *)((char *)&dword_1E68 + v3) = 3;
      *(int *)((char *)&dword_1E6C + v3) = -70;
      *(int *)((char *)&dword_1E74 + v3) = 4;
      *(int *)((char *)&dword_1E78 + v3) = 3;
      *(int *)((char *)&dword_1E7C + v3) = 400;
      *(int *)((char *)&dword_1E84 + v3) = 60;
      *(int *)((char *)&dword_1E9C + v3) = 3;
      *((_BYTE *)&qword_B14 + v5) = 0;
      *(int *)((char *)&dword_1EA4 + v3) = -60;
      *(int *)((char *)&dword_1EA8 + v3) = 1;
      *(int *)((char *)&dword_1EAC + v3) = 10;
      *(int *)((char *)&dword_1EB0 + v3) = -70;
      *(int *)((char *)&dword_1EB4 + v3) = 1;
      *(int *)((char *)&dword_1EB8 + v3) = 10;
      byte_B38[v5] = 1;
      byte_B38[v5 + 1] = 0;
      byte_B38[v5 + 2] = 1;
      *(int *)((char *)&dword_1ED0 + v3) = 0;
      *((_BYTE *)&qword_B48 + v5 + 4) = 0;
      *((_BYTE *)&qword_B48 + v5 + 5) = 1;
      sized_strscpy(v3 + 7898, &unk_98C763, 1);
      *(int *)((char *)&dword_2074 + v3) = -76;
      *(int *)((char *)&dword_206C + v3) = 100;
      *(int *)((char *)&dword_2070 + v3) = 50;
      *(int *)((char *)&dword_2088 + v3) = 20000;
      *(int *)((char *)&dword_2090 + v3) = 10;
      *(int *)((char *)&dword_2094 + v3) = 10;
      *(int *)((char *)&dword_20A4 + v3) = 23;
      *(int *)((char *)&dword_20A8 + v3) = 15000;
      *(int *)((char *)&dword_20AC + v3) = -30;
      *(int *)((char *)&dword_20B4 + v3) = 2;
      *(int *)((char *)&dword_20C4 + v3) = 70;
      *(int *)((char *)&dword_20C8 + v3) = 70;
      *(int *)((char *)&dword_20DC + v3) = 4314;
      *(int *)((char *)&dword_20F4 + v3) = 130;
      *(int *)((char *)&dword_20FC + v3) = -70;
      *(int *)((char *)&dword_2100 + v3) = -70;
      *(int *)((char *)&dword_212C + v3) = 0x7FFFF;
      *(int *)((char *)&dword_2144 + v3) = 5;
      *(int *)((char *)&dword_2148 + v3) = 5;
      *(int *)((char *)&dword_2154 + v3) = -72;
      *(int *)((char *)&dword_215C + v3) = -75;
      *(int *)((char *)&dword_207C + v3) = 5;
      *(int *)((char *)&dword_2080 + v3) = 20;
      *(int *)((char *)&dword_2098 + v3) = 20;
      *(int *)((char *)&dword_2104 + v3) = -60;
      *(int *)((char *)&dword_2078 + v3) = 0;
      *(int *)((char *)&dword_2084 + v3) = 40;
      *(int *)((char *)&dword_208C + v3) = 0;
      *(int *)((char *)&dword_209C + v3) = 1;
      *(int *)((char *)&dword_20A0 + v3) = 3;
      byte_D24[v5] = 1;
      byte_D24[v5 + 1] = 0;
      *(int *)((char *)&dword_20B8 + v3) = 0;
      *(int *)((char *)&dword_20BC + v3) = 20;
      byte_D24[v5 + 16] = 0;
      *(int *)((char *)&dword_20CC + v3) = 10000;
      *(int *)((char *)&dword_20D0 + v3) = 10;
      *(int *)((char *)&dword_20D4 + v3) = 0;
      *(int *)((char *)&dword_20D8 + v3) = 10;
      byte_D24[v5 + 48] = 1;
      byte_D24[v5 + 49] = 1;
      byte_D24[v5 + 50] = 0;
      *(int *)((char *)&dword_20E4 + v3) = 0;
      *(int *)((char *)&dword_20E8 + v3) = 120;
      byte_D24[v5 + 60] = 1;
      *(int *)((char *)&dword_20F0 + v3) = 10;
      *(int *)((char *)&dword_20F8 + v3) = 10;
      *(int *)((char *)&dword_2108 + v3) = 0;
      byte_D24[v5 + 92] = 0;
      byte_D24[v5 + 93] = 1;
      byte_D24[v5 + 94] = 1;
      byte_D24[v5 + 95] = 1;
      byte_D24[v5 + 96] = 0;
      *(int *)((char *)&dword_2114 + v3) = 3;
      *(int *)((char *)&dword_2118 + v3) = 10000;
      *(int *)((char *)&dword_211C + v3) = 10;
      *(int *)((char *)&dword_2120 + v3) = 10;
      *(int *)((char *)&dword_2124 + v3) = -65;
      *(int *)((char *)&dword_2128 + v3) = 0;
      *(int *)((char *)&dword_2130 + v3) = 0;
      *(int *)((char *)&dword_2134 + v3) = 1;
      *(_WORD *)&byte_D24[v5 + 136] = 0;
      byte_D24[v5 + 138] = 1;
      byte_D24[v5 + 139] = 1;
      byte_D24[v5 + 140] = 0;
      *(int *)((char *)&dword_2140 + v3) = 3;
      byte_D24[v5 + 156] = 1;
      *(int *)((char *)&dword_2150 + v3) = -65;
      *(int *)((char *)&dword_2158 + v3) = -65;
      *(int *)((char *)&dword_2160 + v3) = -70;
      sized_strscpy(v3 + 8548, "Mod", 4);
      byte_DE3[v5 + 1] = 1;
      *(int *)((char *)&dword_2168 + v3) = 30;
      *(int *)((char *)&dword_216C + v3) = 30;
      *(int *)((char *)&dword_217C + v3) = 60;
      byte_E07[v5 + 33] = 1;
      *(int *)((char *)&dword_2184 + v3) = 38347922;
      *(int *)((char *)&dword_2188 + v3) = 38347922;
      *(int *)((char *)&dword_218C + v3) = 38347922;
      *(int *)((char *)&dword_2190 + v3) = 38347922;
      *(int *)((char *)&dword_2194 + v3) = 38347922;
      *(int *)((char *)&dword_2198 + v3) = 38347922;
      *(int *)((char *)&dword_219C + v3) = 38347922;
      *(int *)((char *)&dword_21A0 + v3) = 38347922;
      *(int *)((char *)&dword_21A4 + v3) = 38347922;
      *(int *)((char *)&dword_21A8 + v3) = 38347922;
      *(int *)((char *)&dword_21AC + v3) = 38347922;
      *(int *)((char *)&dword_21C4 + v3) = 200;
      *(_QWORD *)(v3 + 8649) = 0x10101010101LL;
      byte_E07[v5 + 34] = 0;
      *(_DWORD *)(v3 + 8657) = 16843009;
      *(_WORD *)((char *)&off_0 + v3 + 8661) = 257;
      byte_E07[v5 + 35] = 0;
      *(__int64 *)((char *)&qword_21D8 + v3) = 0x100000258LL;
      byte_E07[v5 + 53] = 0;
      *(__int64 *)((char *)&qword_21E0 + v3) = 0x500000001LL;
      *(_WORD *)&byte_E07[v5 + 85] = 1;
      *(_QWORD *)(v3 + 8708) = 0;
      *(_QWORD *)(v3 + 8716) = 0;
      byte_E07[v5 + 87] = 0;
      *(int *)((char *)&dword_2214 + v3) = 16;
      *(int *)((char *)&dword_2228 + v3) = 16;
      byte_EA0[v5] = 1;
      *(int *)((char *)&dword_2174 + v3) = 0;
      *(int *)((char *)&dword_2178 + v3) = 0;
      *(int *)((char *)&dword_2180 + v3) = 120;
      *(int *)((char *)&dword_21B0 + v3) = 0;
      *(int *)((char *)&dword_21B8 + v3) = 0;
      *(int *)((char *)&dword_21BC + v3) = 10;
      *(int *)((char *)&dword_21C0 + v3) = 20;
      *(int *)((char *)&dword_21EC + v3) = 256;
      *(__int64 *)((char *)&qword_21F0 + v3) = 0;
      *(__int64 *)((char *)&qword_21F8 + v3) = 0;
      *(int *)((char *)&dword_2200 + v3) = 256;
      *(__int64 *)((char *)&qword_2218 + v3) = 0;
      *(__int64 *)((char *)&qword_2220 + v3) = 0;
      sized_strscpy(v3 + 8749, &unk_98C763, 1);
      *(int *)((char *)&dword_2424 + v3) = 0;
      *(_BYTE *)(v3 + 9256) = 0;
      *(int *)((char *)&dword_242C + v3) = 0;
      *(__int64 *)((char *)&qword_2430 + v3) = 0;
      sized_strscpy(v3 + 9272, "0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF", 47);
      *(int *)((char *)&dword_2468 + v3) = 0;
      *(int *)((char *)&dword_2488 + v3) = 3600000;
      *((_BYTE *)&qword_40 + v6 + 4) = 0;
      *(int *)((char *)&dword_2470 + v3) = 0;
      *((_BYTE *)&qword_48 + v6 + 4) = 1;
      *((_BYTE *)&qword_48 + v6 + 5) = 0;
      *(int *)((char *)&dword_2478 + v3) = 6;
      *(_WORD *)((char *)&off_50 + v6 + 4) = 0;
      *(int *)((char *)&dword_2480 + v3) = 1;
      *((_BYTE *)&qword_58 + v6 + 4) = 0;
      *((_BYTE *)&qword_60 + v6 + 4) = 0;
      *((_BYTE *)&qword_60 + v6 + 5) = 1;
      sized_strscpy(v3 + 9358, &unk_98C763, 1);
      *(int *)((char *)&dword_262C + v3) = 255;
      *(int *)((char *)&dword_2630 + v3) = 255;
      *(int *)((char *)&dword_2634 + v3) = 255;
      *(int *)((char *)&dword_264C + v3) = 2;
      *(int *)((char *)&dword_2650 + v3) = 2;
      *(int *)((char *)&dword_263C + v3) = 5;
      *(int *)((char *)&dword_2660 + v3) = 5;
      *(_WORD *)((char *)&qword_8 + v3 + 9832) = 256;
      *(_DWORD *)(v3 + 9842) = 0;
      *(int *)((char *)&dword_2678 + v3) = 49151;
      *(__int64 *)((char *)&qword_2680 + v3) = 0xFFFFFFFFLL;
      *(__int64 *)((char *)&qword_2688 + v3) = 0xF00000000LL;
      *(_QWORD *)(v3 + 9876) = 0xFFFFFFB5FFFFFFB5LL;
      *(_QWORD *)(v3 + 9884) = 4294967226LL;
      *((_BYTE *)&qword_1F0 + v6 + 7) = 0;
      *((_BYTE *)&qword_1F8 + v6) = 0;
      *((_BYTE *)&qword_1F8 + v6 + 1) = 1;
      *((_BYTE *)&qword_1F8 + v6 + 2) = 0;
      *(int *)((char *)&dword_2624 + v3) = 100;
      *((_BYTE *)&qword_200 + v6) = 0;
      *((_BYTE *)&word_210 + v6) = 0;
      *(int *)((char *)&dword_2640 + v3) = 0;
      *((_BYTE *)&qword_21C + v6) = 1;
      *((_BYTE *)&qword_21C + v6 + 1) = 0;
      *(int *)((char *)&dword_2648 + v3) = 10;
      *(int *)((char *)&dword_2654 + v3) = 10;
      *((_BYTE *)&qword_22C + v6 + 4) = 1;
      *((_BYTE *)&qword_22C + v6 + 5) = 1;
      *((_BYTE *)&qword_22C + v6 + 6) = 0;
      *(int *)((char *)&dword_265C + v3) = 0;
      *((_BYTE *)&qword_23C + v6) = 1;
      *(__int64 *)((char *)&qword_2668 + v3) = 0;
      *((_BYTE *)&qword_24C + v6 + 2) = 1;
      *((_BYTE *)&qword_254 + v6) = 0;
      *((_BYTE *)&qword_264 + v6 + 4) = 1;
      *(int *)((char *)&dword_26A4 + v3) = 0;
      sized_strscpy(v3 + 9896, "10,0,14,0", 10);
      *(int *)((char *)&dword_2738 + v3) = 10;
      *(int *)((char *)&dword_273C + v3) = 10;
      *(int *)((char *)&dword_2744 + v3) = 30;
      *(int *)((char *)&dword_274C + v3) = 32;
      *(int *)((char *)&dword_276C + v3) = 400;
      *(int *)((char *)&dword_2788 + v3) = 119;
      *(int *)((char *)&dword_2798 + v3) = -55;
      *(int *)((char *)&dword_27A0 + v3) = -80;
      *(int *)((char *)&dword_27A8 + v3) = 2347;
      *(int *)((char *)&dword_27AC + v3) = 8000;
      *(int *)((char *)&dword_27BC + v3) = 5000;
      *(int *)((char *)&dword_27C8 + v3) = 10000;
      *(int *)((char *)&dword_27E0 + v3) = 1000;
      *(int *)((char *)&dword_2804 + v3) = 7;
      *(int *)((char *)&dword_2830 + v3) = 7;
      *(int *)((char *)&dword_283C + v3) = 781;
      *(int *)((char *)&dword_284C + v3) = 32976;
      *(int *)((char *)&dword_27B4 + v3) = 1000;
      *(int *)((char *)&dword_2850 + v3) = 83200;
      *(int *)((char *)&dword_27B8 + v3) = 1000;
      *(int *)((char *)&dword_27C4 + v3) = 1000;
      *(int *)((char *)&dword_27CC + v3) = 1000;
      *(int *)((char *)&dword_27D0 + v3) = 40;
      *(int *)((char *)&dword_2854 + v3) = 6000000;
      *(int *)((char *)&dword_2870 + v3) = 6000000;
      *(int *)((char *)&dword_288C + v3) = 6000000;
      *(int *)((char *)&dword_28A8 + v3) = 6000000;
      *(int *)((char *)&dword_27D4 + v3) = 20;
      *(int *)((char *)&dword_27DC + v3) = 20;
      *(int *)((char *)&dword_280C + v3) = 2;
      *(int *)((char *)&dword_2810 + v3) = 2;
      *(int *)((char *)&dword_2814 + v3) = 2;
      *(int *)((char *)&dword_2818 + v3) = 2;
      *(int *)((char *)&dword_281C + v3) = 2;
      *((_BYTE *)&qword_8 + v3 + 10432) = 0;
      *(int *)((char *)&dword_2834 + v3) = 2;
      *(int *)((char *)&dword_28DC + v3) = 14;
      *(int *)((char *)&dword_2858 + v3) = 8193;
      *(int *)((char *)&dword_2874 + v3) = 8193;
      *(int *)((char *)&dword_2890 + v3) = 8193;
      *(int *)((char *)&dword_28AC + v3) = 8193;
      *(_WORD *)((char *)&qword_4B4 + v6 + 4) = 257;
      *(int *)((char *)&dword_28E4 + v3) = 60;
      *(_QWORD *)(v3 + 10476) = 0x100000008LL;
      *(_QWORD *)(v3 + 10500) = 0xA00000014LL;
      *(_DWORD *)(v3 + 10509) = 0;
      *(_QWORD *)(v3 + 10524) = 0;
      *(_WORD *)((char *)&qword_500 + v6 + 4) = 256;
      *(_WORD *)((char *)&unk_520 + v6) = 256;
      *(_WORD *)((char *)&qword_4EC + v6 + 4) = 257;
      *(_WORD *)((char *)&qword_508 + v6 + 4) = 257;
      *(_QWORD *)(v3 + 10572) = 1;
      *(_QWORD *)(v3 + 10580) = 0x200000003LL;
      *(__int64 *)((char *)&qword_2960 + v3) = 0x3200000000LL;
      *(__int64 *)((char *)&qword_2968 + v3) = 0x3C00000000LL;
      *(int *)((char *)&dword_2970 + v3) = 16842752;
      *(__int64 *)((char *)&qword_2980 + v3) = 0x1E00000000LL;
      *(int *)((char *)&dword_278C + v3) = 10;
      *(int *)((char *)&dword_2794 + v3) = 10;
      *(int *)((char *)&dword_27D8 + v3) = 10;
      *(__int64 *)((char *)&qword_2988 + v3) = 15461882265780000LL;
      *(__int64 *)((char *)&qword_2990 + v3) = -1;
      *(__int64 *)((char *)&qword_29A8 + v3) = 0xA00000000LL;
      *(_QWORD *)(v3 + 10684) = 0x28000007D0LL;
      *(_QWORD *)(v3 + 10692) = 0x800000005LL;
      *(int *)((char *)&dword_27C0 + v3) = 2000;
      *(_QWORD *)(v3 + 10700) = 0x300001388LL;
      *(int *)((char *)&dword_2860 + v3) = 2000;
      *(_QWORD *)(v3 + 10708) = 0xFFFFFFB5FFFFFFB5LL;
      *(int *)((char *)&dword_286C + v3) = 360000;
      *(int *)((char *)&dword_2750 + v3) = 3;
      *(_QWORD *)(v3 + 10716) = 0x24FFFFFFECLL;
      *(int *)((char *)&dword_2848 + v3) = 3;
      *(_QWORD *)(v3 + 10724) = 0xF00001757LL;
      *(int *)((char *)&dword_2864 + v3) = 3;
      *(_QWORD *)(v3 + 10732) = 0x138800000002LL;
      *(int *)((char *)&dword_2868 + v3) = 34268;
      *(_QWORD *)(v3 + 10748) = 0xC800000060LL;
      *(int *)((char *)&dword_287C + v3) = 2000;
      *(int *)((char *)&dword_2880 + v3) = 3;
      *(int *)((char *)&dword_2884 + v3) = 34268;
      *(int *)((char *)&dword_2888 + v3) = 300000;
      *(int *)((char *)&dword_2898 + v3) = 2000;
      *(int *)((char *)&dword_289C + v3) = 3;
      *(int *)((char *)&dword_28A0 + v3) = 34268;
      *(int *)((char *)&dword_28A4 + v3) = 300000;
      *(int *)((char *)&dword_28B4 + v3) = 2000;
      *(int *)((char *)&dword_2740 + v3) = 5;
      *(int *)((char *)&dword_2748 + v3) = 0;
      *((_BYTE *)&word_32C + v6) = 0;
      *(int *)((char *)&dword_2758 + v3) = 0;
      *((_BYTE *)&qword_330 + v6 + 4) = 1;
      *((_BYTE *)&qword_330 + v6 + 5) = 0;
      *(int *)((char *)&dword_2760 + v3) = 0;
      *(int *)((char *)&dword_2764 + v3) = 2;
      *((_BYTE *)&qword_340 + v6) = 0;
      *((_BYTE *)&qword_340 + v6 + 1) = 1;
      *(int *)((char *)&dword_2770 + v3) = 0;
      *((_BYTE *)&qword_348 + v6 + 4) = 1;
      *(int *)((char *)&dword_2778 + v3) = 1;
      *((_BYTE *)&qword_350 + v6 + 4) = 1;
      *(int *)((char *)&dword_2780 + v3) = 500;
      *(int *)((char *)&dword_2784 + v3) = 2;
      *((_BYTE *)&qword_368 + v6) = 1;
      *((_BYTE *)&qword_368 + v6 + 1) = 0;
      *(int *)((char *)&dword_279C + v3) = -65;
      *(int *)((char *)&dword_27A4 + v3) = 0;
      *(int *)((char *)&dword_27B0 + v3) = 3000;
      *((_BYTE *)&qword_3B8 + v6 + 4) = 1;
      *((_BYTE *)&qword_3B8 + v6 + 5) = 1;
      *(int *)((char *)&dword_27E8 + v3) = 6;
      *(int *)((char *)&dword_27EC + v3) = 100;
      *(int *)((char *)&dword_27F0 + v3) = 1;
      *((_BYTE *)&qword_3C8 + v6 + 4) = 1;
      *((_BYTE *)&qword_3C8 + v6 + 5) = 0;
      *((_BYTE *)&qword_3C8 + v6 + 6) = 0;
      *(__int64 *)((char *)&qword_27F8 + v3) = 0;
      *((_BYTE *)&qword_3D8 + v6) = 1;
      *((_BYTE *)&qword_3E0 + v6) = 0;
      *((_BYTE *)&qword_3E0 + v6 + 1) = 1;
      *((_BYTE *)&qword_3F8 + v6) = 1;
      *(int *)((char *)&dword_2824 + v3) = 1;
      *((_BYTE *)&qword_400 + v6) = 1;
      *((_BYTE *)&qword_400 + v6 + 1) = 0;
      *((_BYTE *)&qword_400 + v6 + 2) = 0;
      *((_BYTE *)&qword_400 + v6 + 3) = 1;
      *((_BYTE *)&qword_400 + v6 + 4) = 1;
      *((_BYTE *)&qword_410 + v6) = 1;
      *((_BYTE *)&qword_410 + v6 + 1) = 1;
      *((_BYTE *)&qword_410 + v6 + 2) = 0;
      *((_BYTE *)&qword_410 + v6 + 3) = 1;
      *((_BYTE *)&dword_418 + v6) = 1;
      *((_BYTE *)&dword_418 + v6 + 1) = 0;
      *((_BYTE *)&dword_418 + v6 + 2) = 1;
      *(int *)((char *)&dword_2844 + v3) = 0;
      *(int *)((char *)&dword_285C + v3) = 0;
      *(int *)((char *)&dword_2878 + v3) = 0;
      *(int *)((char *)&dword_2894 + v3) = 0;
      *(int *)((char *)&dword_28B0 + v3) = 0;
      *(int *)((char *)&dword_28B8 + v3) = 0;
      *((_BYTE *)&word_494 + v6) = 0;
      *(int *)((char *)&dword_28CC + v3) = 0;
      *(__int64 *)((char *)&qword_28C0 + v3) = 0;
      byte_4A8[v6] = 1;
      *(int *)((char *)&dword_28D4 + v3) = 3000;
      *(_WORD *)((char *)&qword_4AC + v6 + 4) = 1;
      *((_BYTE *)&qword_4B4 + v6 + 6) = 1;
      *((_BYTE *)&qword_4BC + v6 + 4) = 1;
      *(int *)((char *)&dword_28F4 + v3) = 0;
      *((_BYTE *)&qword_4CC + v6 + 4) = 1;
      *(int *)((char *)&dword_28FC + v3) = 1;
      *((_BYTE *)&qword_4D4 + v6 + 4) = 1;
      *((_BYTE *)&qword_4E4 + v6) = 1;
      *(int *)((char *)&dword_2914 + v3) = 0;
      *((_BYTE *)&qword_4F8 + v6 + 4) = 1;
      *(int *)((char *)&dword_2928 + v3) = 15;
      *((_BYTE *)&qword_500 + v6 + 6) = 1;
      *(int *)((char *)&dword_2930 + v3) = 1;
      *((_BYTE *)&qword_508 + v6 + 6) = 0;
      *(__int64 *)((char *)&qword_2938 + v3) = 0;
      *(__int64 *)((char *)&qword_2940 + v3) = 1;
      byte_534[v6] = 1;
      byte_534[v6 + 24] = 0;
      *(int *)((char *)&dword_2978 + v3) = 7;
      byte_534[v6 + 32] = 0;
      *(__int64 *)((char *)&qword_2998 + v3) = 500;
      *(int *)((char *)&dword_29A0 + v3) = 15;
      byte_534[v6 + 72] = 1;
      byte_588[v6] = 1;
      *(int *)((char *)&dword_29B4 + v3) = 1;
      byte_588[v6 + 8] = 1;
      *(int *)((char *)&dword_29F4 + v3) = 1;
      *(_WORD *)&byte_588[v6 + 72] = 257;
      *(int *)((char *)&dword_2A04 + v3) = 2000;
      sized_strscpy(v3 + 10760, &unk_98C763, 1);
      sized_strscpy(
        v3 + 11601,
        "000C43 00 25 C2 001018 06 02FFF02C0000 BC 25 42 001018 06 02FF040C0000 BC 25 42 00037F 00 35 6C 001018 06 02FF009C0000 BC 25 48",
        128);
      sized_strscpy(
        v3 + 12442,
        "001018 06 02FFF0040000 BC 21 40 001018 06 02FFF0050000 BC 21 40 001018 06 02FFF4050000 BC 21 40",
        96);
      sized_strscpy(v3 + 13283, "001018 06 0202001c0000 FC 01", 29);
      sized_strscpy(v3 + 14124, "00037F 06 01010000FF7F FC 01 000AEB 02 0100 C0 01 000B86 03 010408 E0 01", 73);
      sized_strscpy(v3 + 14965, "FFFFFF 00 2A F85971000000 E0 50 FFFFFF 00 2A 14ABC5000000 E0 50", 64);
      sized_strscpy(v3 + 15806, &unk_98C763, 1);
      sized_strscpy(v3 + 16647, &unk_98C763, 1);
      sized_strscpy(v3 + 17488, "00904C 05 0418BF0CB2 F8 21 40", 30);
      sized_strscpy(v3 + 18329, "00E04C 00 01", 13);
      sized_strscpy(
        v3 + 19170,
        "001018 00 01 000986 00 01 000ce7 00 01 00e0fc 00 01 000b86 04 01040817 F0 01 000b86 04 0104080F F0 01 000b86 04 01040819 F0 01",
        127);
      sized_strscpy(v3 + 20011, "0017f2 01 0a 80 01", 19);
      sized_strscpy(v3 + 20852, &unk_98C763, 1);
      sized_strscpy(v3 + 21693, "00e04c 03 020160 E0 01 001018 06 02FF009c0000 BC 01", 52);
      sized_strscpy(v3 + 22534, "000C43 04 07000000 F0 21 C0 000C43 04 03000000 F0 21 C0", 56);
      sized_strscpy(v3 + 23375, &unk_98C763, 1);
      sized_strscpy(v3 + 24216, "8CFDF0 13 040000494c510302097201cb17000009110000 FFFFE0 01", 59);
      sized_strscpy(v3 + 25057, &unk_98C763, 1);
      sized_strscpy(v3 + 25898, &unk_98C763, 1);
      sized_strscpy(v3 + 26739, &unk_98C763, 1);
      sized_strscpy(v3 + 27580, &unk_98C763, 1);
      sized_strscpy(v3 + 28421, "ffffff 00 01", 13);
      sized_strscpy(v3 + 29262, "F832E4 00 01", 13);
      sized_strscpy(v3 + 30103, "000CE7 00 01", 13);
      sized_strscpy(v3 + 30944, "18FE34 00 01", 13);
      *(_DWORD *)(v3 + 31788) = 1;
      sized_strscpy(v3 + 31792, "F832E4 00 01", 13);
      v8 = v3 + 31788;
      *((_BYTE *)&qword_348 + v8 + 5) = 0;
      *(_DWORD *)((char *)&qword_350 + v8) = 5;
      v9 = v11[0];
      *((_BYTE *)&qword_350 + v8 + 4) = 0;
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
