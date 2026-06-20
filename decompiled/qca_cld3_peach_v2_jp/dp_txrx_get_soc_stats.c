__int64 __fastcall dp_txrx_get_soc_stats(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x0
  unsigned int v8; // w0
  int v9; // w8
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9

  v2 = *(_QWORD *)(a1 + 13352);
  *(_QWORD *)a2 = *(_QWORD *)(a1 + 13344);
  *(_QWORD *)(a2 + 8) = v2;
  v5 = *(_QWORD *)(a1 + 13456);
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a1 + 13448);
  *(_QWORD *)(a2 + 24) = v5;
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 13424);
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(a1 + 13464);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 13428);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(a1 + 13468);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 13432);
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(a1 + 13472);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a1 + 13436);
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a1 + 13476);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a1 + 13440);
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a1 + 13480);
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(a1 + 13484);
  *(_DWORD *)(a2 + 76) = *(_DWORD *)(a1 + 13488);
  *(_DWORD *)(a2 + 80) = *(_DWORD *)(a1 + 13492);
  *(_DWORD *)(a2 + 84) = *(_DWORD *)(a1 + 13496);
  *(_DWORD *)(a2 + 88) = *(_DWORD *)(a1 + 13500);
  *(_DWORD *)(a2 + 92) = *(_DWORD *)(a1 + 13504);
  *(_DWORD *)(a2 + 96) = *(_DWORD *)(a1 + 13508);
  *(_DWORD *)(a2 + 100) = *(_DWORD *)(a1 + 13512);
  *(_DWORD *)(a2 + 104) = *(_DWORD *)(a1 + 13516);
  *(_DWORD *)(a2 + 108) = *(_DWORD *)(a1 + 13520);
  *(_DWORD *)(a2 + 112) = *(_DWORD *)(a1 + 13524);
  *(_DWORD *)(a2 + 116) = *(_DWORD *)(a1 + 13528);
  *(_DWORD *)(a2 + 120) = *(_DWORD *)(a1 + 13532);
  v6 = *(_QWORD *)(a1 + 13592);
  *(_QWORD *)(a2 + 128) = *(_QWORD *)(a1 + 13584);
  *(_QWORD *)(a2 + 136) = v6;
  *(_DWORD *)(a2 + 144) = *(_DWORD *)(a1 + 13600);
  *(_DWORD *)(a2 + 148) = *(_DWORD *)(a1 + 13604);
  *(_DWORD *)(a2 + 152) = *(_DWORD *)(a1 + 13628);
  *(_DWORD *)(a2 + 156) = *(_DWORD *)(a1 + 13648);
  *(_DWORD *)(a2 + 160) = *(_DWORD *)(a1 + 13620);
  *(_DWORD *)(a2 + 164) = *(_DWORD *)(a1 + 13624);
  *(_DWORD *)(a2 + 168) = *(_DWORD *)(a1 + 13608);
  *(_DWORD *)(a2 + 172) = *(_DWORD *)(a1 + 13612);
  *(_DWORD *)(a2 + 176) = *(_DWORD *)(a1 + 13616);
  *(_DWORD *)(a2 + 180) = *(_DWORD *)(a1 + 13632);
  *(_DWORD *)(a2 + 184) = *(_DWORD *)(a1 + 13636);
  *(_DWORD *)(a2 + 188) = *(_DWORD *)(a1 + 13640);
  *(_DWORD *)(a2 + 192) = *(_DWORD *)(a1 + 13644);
  *(_DWORD *)(a2 + 196) = *(_DWORD *)(a1 + 13652);
  LODWORD(v6) = *(_DWORD *)(a1 + 13656);
  v7 = _cpu_possible_mask;
  *(_DWORD *)(a2 + 200) = v6;
  v8 = _sw_hweight64(v7);
  if ( v8 >= 8 )
    v9 = 8;
  else
    v9 = v8;
  *(_BYTE *)(a2 + 208) = v9;
  if ( v9 )
  {
    *(_QWORD *)(a2 + 216) = *(_QWORD *)(a1 + 14168);
    *(_QWORD *)(a2 + 224) = *(_QWORD *)(a1 + 14176);
    *(_QWORD *)(a2 + 232) = *(_QWORD *)(a1 + 14184);
    *(_QWORD *)(a2 + 240) = *(_QWORD *)(a1 + 14192);
    *(_QWORD *)(a2 + 248) = *(_QWORD *)(a1 + 14200);
    *(_QWORD *)(a2 + 256) = *(_QWORD *)(a1 + 14208);
    *(_QWORD *)(a2 + 264) = *(_QWORD *)(a1 + 14216);
    *(_QWORD *)(a2 + 272) = *(_QWORD *)(a1 + 14224);
    if ( v8 != 1 )
    {
      *(_QWORD *)(a2 + 280) = *(_QWORD *)(a1 + 14232);
      *(_QWORD *)(a2 + 288) = *(_QWORD *)(a1 + 14240);
      *(_QWORD *)(a2 + 296) = *(_QWORD *)(a1 + 14248);
      *(_QWORD *)(a2 + 304) = *(_QWORD *)(a1 + 14256);
      *(_QWORD *)(a2 + 312) = *(_QWORD *)(a1 + 14264);
      *(_QWORD *)(a2 + 320) = *(_QWORD *)(a1 + 14272);
      *(_QWORD *)(a2 + 328) = *(_QWORD *)(a1 + 14280);
      *(_QWORD *)(a2 + 336) = *(_QWORD *)(a1 + 14288);
      if ( v8 != 2 )
      {
        *(_QWORD *)(a2 + 344) = *(_QWORD *)(a1 + 14296);
        *(_QWORD *)(a2 + 352) = *(_QWORD *)(a1 + 14304);
        *(_QWORD *)(a2 + 360) = *(_QWORD *)(a1 + 14312);
        *(_QWORD *)(a2 + 368) = *(_QWORD *)(a1 + 14320);
        *(_QWORD *)(a2 + 376) = *(_QWORD *)(a1 + 14328);
        *(_QWORD *)(a2 + 384) = *(_QWORD *)(a1 + 14336);
        *(_QWORD *)(a2 + 392) = *(_QWORD *)(a1 + 14344);
        *(_QWORD *)(a2 + 400) = *(_QWORD *)(a1 + 14352);
        if ( v8 != 3 )
        {
          *(_QWORD *)(a2 + 408) = *(_QWORD *)(a1 + 14360);
          *(_QWORD *)(a2 + 416) = *(_QWORD *)(a1 + 14368);
          *(_QWORD *)(a2 + 424) = *(_QWORD *)(a1 + 14376);
          *(_QWORD *)(a2 + 432) = *(_QWORD *)(a1 + 14384);
          *(_QWORD *)(a2 + 440) = *(_QWORD *)(a1 + 14392);
          *(_QWORD *)(a2 + 448) = *(_QWORD *)(a1 + 14400);
          *(_QWORD *)(a2 + 456) = *(_QWORD *)(a1 + 14408);
          *(_QWORD *)(a2 + 464) = *(_QWORD *)(a1 + 14416);
          if ( v8 != 4 )
          {
            *(_QWORD *)(a2 + 472) = *(_QWORD *)(a1 + 14424);
            *(_QWORD *)(a2 + 480) = *(_QWORD *)(a1 + 14432);
            *(_QWORD *)(a2 + 488) = *(_QWORD *)(a1 + 14440);
            *(_QWORD *)(a2 + 496) = *(_QWORD *)(a1 + 14448);
            *(_QWORD *)(a2 + 504) = *(_QWORD *)(a1 + 14456);
            *(_QWORD *)(a2 + 512) = *(_QWORD *)(a1 + 14464);
            *(_QWORD *)(a2 + 520) = *(_QWORD *)(a1 + 14472);
            *(_QWORD *)(a2 + 528) = *(_QWORD *)(a1 + 14480);
            if ( v8 != 5 )
            {
              *(_QWORD *)(a2 + 536) = *(_QWORD *)(a1 + 14488);
              *(_QWORD *)(a2 + 544) = *(_QWORD *)(a1 + 14496);
              *(_QWORD *)(a2 + 552) = *(_QWORD *)(a1 + 14504);
              *(_QWORD *)(a2 + 560) = *(_QWORD *)(a1 + 14512);
              *(_QWORD *)(a2 + 568) = *(_QWORD *)(a1 + 14520);
              *(_QWORD *)(a2 + 576) = *(_QWORD *)(a1 + 14528);
              *(_QWORD *)(a2 + 584) = *(_QWORD *)(a1 + 14536);
              *(_QWORD *)(a2 + 592) = *(_QWORD *)(a1 + 14544);
              if ( v8 != 6 )
              {
                *(_QWORD *)(a2 + 600) = *(_QWORD *)(a1 + 14552);
                *(_QWORD *)(a2 + 608) = *(_QWORD *)(a1 + 14560);
                *(_QWORD *)(a2 + 616) = *(_QWORD *)(a1 + 14568);
                *(_QWORD *)(a2 + 624) = *(_QWORD *)(a1 + 14576);
                *(_QWORD *)(a2 + 632) = *(_QWORD *)(a1 + 14584);
                *(_QWORD *)(a2 + 640) = *(_QWORD *)(a1 + 14592);
                *(_QWORD *)(a2 + 648) = *(_QWORD *)(a1 + 14600);
                *(_QWORD *)(a2 + 656) = *(_QWORD *)(a1 + 14608);
                if ( v8 != 7 )
                {
                  *(_QWORD *)(a2 + 664) = *(_QWORD *)(a1 + 14616);
                  *(_QWORD *)(a2 + 672) = *(_QWORD *)(a1 + 14624);
                  *(_QWORD *)(a2 + 680) = *(_QWORD *)(a1 + 14632);
                  *(_QWORD *)(a2 + 688) = *(_QWORD *)(a1 + 14640);
                  *(_QWORD *)(a2 + 696) = *(_QWORD *)(a1 + 14648);
                  *(_QWORD *)(a2 + 704) = *(_QWORD *)(a1 + 14656);
                  *(_QWORD *)(a2 + 712) = *(_QWORD *)(a1 + 14664);
                  *(_QWORD *)(a2 + 720) = *(_QWORD *)(a1 + 14672);
                }
              }
            }
          }
        }
      }
    }
  }
  *(_DWORD *)(a2 + 728) = *(_DWORD *)(a1 + 14092);
  *(_DWORD *)(a2 + 732) = *(_DWORD *)(a1 + 14100);
  *(_DWORD *)(a2 + 736) = *(_DWORD *)(a1 + 13768);
  *(_DWORD *)(a2 + 740) = *(_DWORD *)(a1 + 13772);
  *(_DWORD *)(a2 + 744) = *(_DWORD *)(a1 + 13968);
  *(_DWORD *)(a2 + 748) = *(_DWORD *)(a1 + 13972);
  *(_DWORD *)(a2 + 752) = *(_DWORD *)(a1 + 13976);
  *(_DWORD *)(a2 + 756) = *(_DWORD *)(a1 + 13980);
  *(_DWORD *)(a2 + 760) = *(_DWORD *)(a1 + 13984);
  *(_DWORD *)(a2 + 764) = *(_DWORD *)(a1 + 13988);
  *(_DWORD *)(a2 + 768) = *(_DWORD *)(a1 + 13992);
  *(_DWORD *)(a2 + 772) = *(_DWORD *)(a1 + 13996);
  *(_DWORD *)(a2 + 776) = *(_DWORD *)(a1 + 14000);
  *(_DWORD *)(a2 + 780) = *(_DWORD *)(a1 + 14004);
  *(_DWORD *)(a2 + 784) = *(_DWORD *)(a1 + 14008);
  *(_DWORD *)(a2 + 788) = *(_DWORD *)(a1 + 13688);
  *(_DWORD *)(a2 + 792) = *(_DWORD *)(a1 + 13692);
  *(_DWORD *)(a2 + 796) = *(_DWORD *)(a1 + 13696);
  *(_DWORD *)(a2 + 800) = *(_DWORD *)(a1 + 13700);
  *(_DWORD *)(a2 + 804) = *(_DWORD *)(a1 + 13704);
  *(_DWORD *)(a2 + 808) = *(_DWORD *)(a1 + 13708);
  *(_DWORD *)(a2 + 812) = *(_DWORD *)(a1 + 13712);
  v11 = *(_QWORD *)(a1 + 13720);
  *(_QWORD *)(a2 + 824) = *(_QWORD *)(a1 + 13728);
  *(_QWORD *)(a2 + 816) = v11;
  v12 = *(_QWORD *)(a1 + 13736);
  *(_QWORD *)(a2 + 840) = *(_QWORD *)(a1 + 13744);
  *(_QWORD *)(a2 + 832) = v12;
  v13 = *(_QWORD *)(a1 + 13752);
  *(_QWORD *)(a2 + 856) = *(_QWORD *)(a1 + 13760);
  *(_QWORD *)(a2 + 848) = v13;
  *(_DWORD *)(a2 + 864) = *(_DWORD *)(a1 + 13776);
  *(_DWORD *)(a2 + 868) = *(_DWORD *)(a1 + 13780);
  *(_DWORD *)(a2 + 872) = *(_DWORD *)(a1 + 13784);
  *(_DWORD *)(a2 + 876) = *(_DWORD *)(a1 + 13788);
  *(_DWORD *)(a2 + 880) = *(_DWORD *)(a1 + 13792);
  *(_DWORD *)(a2 + 884) = *(_DWORD *)(a1 + 13796);
  *(_DWORD *)(a2 + 888) = *(_DWORD *)(a1 + 13800);
  *(_DWORD *)(a2 + 892) = *(_DWORD *)(a1 + 13804);
  *(_DWORD *)(a2 + 896) = *(_DWORD *)(a1 + 13808);
  *(_DWORD *)(a2 + 900) = *(_DWORD *)(a1 + 13812);
  *(_DWORD *)(a2 + 904) = *(_DWORD *)(a1 + 13816);
  *(_DWORD *)(a2 + 908) = *(_DWORD *)(a1 + 13820);
  *(_DWORD *)(a2 + 912) = *(_DWORD *)(a1 + 13824);
  *(_DWORD *)(a2 + 916) = *(_DWORD *)(a1 + 13828);
  *(_DWORD *)(a2 + 920) = *(_DWORD *)(a1 + 13832);
  *(_DWORD *)(a2 + 924) = *(_DWORD *)(a1 + 13836);
  *(_DWORD *)(a2 + 928) = *(_DWORD *)(a1 + 13840);
  *(_DWORD *)(a2 + 932) = *(_DWORD *)(a1 + 13844);
  *(_DWORD *)(a2 + 936) = *(_DWORD *)(a1 + 13848);
  *(_DWORD *)(a2 + 940) = *(_DWORD *)(a1 + 13852);
  *(_DWORD *)(a2 + 944) = *(_DWORD *)(a1 + 13856);
  *(_DWORD *)(a2 + 948) = *(_DWORD *)(a1 + 13860);
  *(_DWORD *)(a2 + 952) = *(_DWORD *)(a1 + 13864);
  *(_DWORD *)(a2 + 956) = *(_DWORD *)(a1 + 13868);
  *(_DWORD *)(a2 + 960) = *(_DWORD *)(a1 + 13872);
  *(_DWORD *)(a2 + 964) = *(_DWORD *)(a1 + 13876);
  *(_DWORD *)(a2 + 968) = *(_DWORD *)(a1 + 13880);
  *(_DWORD *)(a2 + 972) = *(_DWORD *)(a1 + 13884);
  *(_DWORD *)(a2 + 976) = *(_DWORD *)(a1 + 13888);
  *(_DWORD *)(a2 + 980) = *(_DWORD *)(a1 + 13892);
  *(_DWORD *)(a2 + 984) = *(_DWORD *)(a1 + 13896);
  *(_DWORD *)(a2 + 988) = *(_DWORD *)(a1 + 13900);
  *(_DWORD *)(a2 + 996) = *(_DWORD *)(a1 + 13908);
  *(_DWORD *)(a2 + 1000) = *(_DWORD *)(a1 + 13912);
  *(_DWORD *)(a2 + 1004) = *(_DWORD *)(a1 + 13916);
  *(_DWORD *)(a2 + 1008) = *(_DWORD *)(a1 + 13920);
  *(_DWORD *)(a2 + 1012) = *(_DWORD *)(a1 + 13924);
  *(_DWORD *)(a2 + 1016) = *(_DWORD *)(a1 + 13928);
  *(_DWORD *)(a2 + 1020) = *(_DWORD *)(a1 + 13932);
  *(_DWORD *)(a2 + 1024) = *(_DWORD *)(a1 + 13936);
  *(_DWORD *)(a2 + 1028) = *(_DWORD *)(a1 + 13940);
  *(_DWORD *)(a2 + 1032) = *(_DWORD *)(a1 + 13944);
  *(_DWORD *)(a2 + 1036) = *(_DWORD *)(a1 + 13948);
  *(_DWORD *)(a2 + 1040) = *(_DWORD *)(a1 + 13952);
  *(_DWORD *)(a2 + 1044) = *(_DWORD *)(a1 + 13956);
  *(_DWORD *)(a2 + 1048) = *(_DWORD *)(a1 + 13960);
  *(_DWORD *)(a2 + 1052) = *(_DWORD *)(a1 + 13964);
  *(_DWORD *)(a2 + 992) = *(_DWORD *)(a1 + 13904);
  *(_DWORD *)(a2 + 1056) = *(_DWORD *)(a1 + 14036);
  *(_DWORD *)(a2 + 1060) = *(_DWORD *)(a1 + 14040);
  *(_DWORD *)(a2 + 1064) = *(_DWORD *)(a1 + 14044);
  *(_DWORD *)(a2 + 1068) = *(_DWORD *)(a1 + 14052);
  *(_DWORD *)(a2 + 1072) = *(_DWORD *)(a1 + 14056);
  *(_DWORD *)(a2 + 1076) = *(_DWORD *)(a1 + 14060);
  *(_DWORD *)(a2 + 1080) = *(_DWORD *)(a1 + 14064);
  *(_DWORD *)(a2 + 1084) = *(_DWORD *)(a1 + 14068);
  *(_DWORD *)(a2 + 1088) = *(_DWORD *)(a1 + 14072);
  *(_DWORD *)(a2 + 1092) = *(_DWORD *)(a1 + 14076);
  *(_DWORD *)(a2 + 1096) = *(_DWORD *)(a1 + 14080);
  *(_DWORD *)(a2 + 1104) = *(_DWORD *)(a1 + 14084);
  *(_DWORD *)(a2 + 1108) = *(_DWORD *)(a1 + 14088);
  *(_DWORD *)(a2 + 1112) = *(_DWORD *)(a1 + 14096);
  *(_DWORD *)(a2 + 1116) = *(_DWORD *)(a1 + 14104);
  *(_DWORD *)(a2 + 1120) = *(_DWORD *)(a1 + 14108);
  *(_DWORD *)(a2 + 1124) = *(_DWORD *)(a1 + 14112);
  *(_DWORD *)(a2 + 1128) = *(_DWORD *)(a1 + 14116);
  *(_DWORD *)(a2 + 1132) = *(_DWORD *)(a1 + 14120);
  *(_DWORD *)(a2 + 1136) = *(_DWORD *)(a1 + 14124);
  *(_DWORD *)(a2 + 1140) = *(_DWORD *)(a1 + 14128);
  *(_DWORD *)(a2 + 1144) = *(_DWORD *)(a1 + 14132);
  *(_DWORD *)(a2 + 1148) = *(_DWORD *)(a1 + 14136);
  *(_DWORD *)(a2 + 1152) = *(_DWORD *)(a1 + 14140);
  *(_DWORD *)(a2 + 1160) = *(_DWORD *)(a1 + 13312);
  *(_DWORD *)(a2 + 1164) = *(_DWORD *)(a1 + 13316);
  *(_DWORD *)(a2 + 1168) = *(_DWORD *)(a1 + 13320);
  *(_DWORD *)(a2 + 1172) = *(_DWORD *)(a1 + 13324);
  *(_DWORD *)(a2 + 1176) = *(_DWORD *)(a1 + 13328);
  *(_DWORD *)(a2 + 1180) = *(_DWORD *)(a1 + 13332);
  *(_DWORD *)(a2 + 1184) = *(_DWORD *)(a1 + 13336);
  return 0;
}
