__int64 __fastcall dp_update_pdev_ingress_stats(__int64 result, __int64 a2)
{
  int v2; // w8
  int v3; // w9
  int v4; // w9
  int v5; // w10
  int v6; // w10
  int v7; // w11
  int v8; // w11
  __int64 v9; // x12
  __int64 v10; // x12
  int v11; // w13
  __int64 v12; // x13
  int v13; // w14
  __int64 v14; // x14
  int v15; // w15
  __int64 v16; // x15
  int v17; // w16
  __int64 v18; // x16
  int v19; // w17
  __int64 v20; // x17
  int v21; // w2
  __int64 v22; // x8
  __int64 v23; // x3
  __int64 v24; // x11

  *(_QWORD *)(result + 616) += *(_QWORD *)(a2 + 496);
  *(_QWORD *)(result + 624) += *(_QWORD *)(a2 + 504);
  *(_QWORD *)(result + 520) += *(_QWORD *)(a2 + 400);
  *(_QWORD *)(result + 528) += *(_QWORD *)(a2 + 408);
  *(_QWORD *)(result + 536) += *(_QWORD *)(a2 + 416);
  *(_DWORD *)(result + 544) += *(_DWORD *)(a2 + 424);
  *(_DWORD *)(result + 548) += *(_DWORD *)(a2 + 428);
  *(_DWORD *)(result + 552) += *(_DWORD *)(a2 + 432);
  *(_DWORD *)(result + 556) += *(_DWORD *)(a2 + 436);
  *(_QWORD *)(result + 568) += *(_QWORD *)(a2 + 448);
  *(_QWORD *)(result + 576) += *(_QWORD *)(a2 + 456);
  *(_QWORD *)(result + 584) += *(_QWORD *)(a2 + 464);
  *(_QWORD *)(result + 592) += *(_QWORD *)(a2 + 472);
  *(_QWORD *)(result + 600) += *(_QWORD *)(a2 + 480);
  *(_QWORD *)(result + 608) += *(_QWORD *)(a2 + 488);
  *(_QWORD *)(result + 648) += *(_QWORD *)(a2 + 528);
  *(_QWORD *)(result + 656) += *(_QWORD *)(a2 + 536);
  *(_DWORD *)(result + 664) += *(_DWORD *)(a2 + 544);
  *(_DWORD *)(result + 672) += *(_DWORD *)(a2 + 552);
  *(_QWORD *)(result + 712) += *(_QWORD *)(a2 + 592);
  *(_DWORD *)(result + 728) += *(_DWORD *)(a2 + 608);
  *(_QWORD *)(result + 680) += *(_QWORD *)(a2 + 560);
  *(_QWORD *)(result + 688) += *(_QWORD *)(a2 + 568);
  *(_QWORD *)(result + 736) += *(_QWORD *)(a2 + 616);
  *(_QWORD *)(result + 744) += *(_QWORD *)(a2 + 624);
  *(_DWORD *)(result + 752) += *(_DWORD *)(a2 + 632);
  *(_DWORD *)(result + 756) += *(_DWORD *)(a2 + 636);
  *(_DWORD *)(result + 760) += *(_DWORD *)(a2 + 640);
  *(_DWORD *)(result + 764) += *(_DWORD *)(a2 + 644);
  *(_DWORD *)(result + 776) += *(_DWORD *)(a2 + 656);
  *(_DWORD *)(result + 780) += *(_DWORD *)(a2 + 660);
  v2 = *(_DWORD *)(result + 872) + *(_DWORD *)(a2 + 752);
  v3 = *(_DWORD *)(result + 864);
  *(_DWORD *)(result + 872) = v2;
  v4 = v3 + *(_DWORD *)(a2 + 744);
  v5 = *(_DWORD *)(result + 868);
  *(_DWORD *)(result + 864) = v4;
  v6 = v5 + *(_DWORD *)(a2 + 748);
  v7 = *(_DWORD *)(result + 884);
  *(_DWORD *)(result + 868) = v6;
  v8 = v7 + *(_DWORD *)(a2 + 764);
  v9 = *(_QWORD *)(result + 800);
  *(_DWORD *)(result + 884) = v8;
  v10 = v9 + *(_QWORD *)(a2 + 680);
  v11 = *(_DWORD *)(result + 876);
  *(_QWORD *)(result + 800) = v10;
  v12 = (unsigned int)(v11 + *(_DWORD *)(a2 + 756));
  v13 = *(_DWORD *)(result + 888);
  *(_DWORD *)(result + 876) = v12;
  v14 = (unsigned int)(v13 + *(_DWORD *)(a2 + 768));
  v15 = *(_DWORD *)(result + 880);
  *(_DWORD *)(result + 888) = v14;
  v16 = (unsigned int)(v15 + *(_DWORD *)(a2 + 760));
  v17 = *(_DWORD *)(result + 892);
  *(_DWORD *)(result + 880) = v16;
  v18 = (unsigned int)(v17 + *(_DWORD *)(a2 + 772));
  v19 = *(_DWORD *)(result + 896);
  *(_DWORD *)(result + 892) = v18;
  v20 = (unsigned int)(v19 + *(_DWORD *)(a2 + 776));
  v21 = *(_DWORD *)(result + 900);
  *(_DWORD *)(result + 896) = v20;
  v22 = v10 + v12 + v14 + (unsigned int)(v4 + v2 + v6 + v8) + v16 + v18 + v20;
  *(_DWORD *)(result + 900) = v21 + *(_DWORD *)(a2 + 780);
  *(_DWORD *)(result + 928) += *(_DWORD *)(a2 + 808);
  *(_DWORD *)(result + 932) += *(_DWORD *)(a2 + 812);
  *(_QWORD *)(result + 936) += *(_QWORD *)(a2 + 816);
  *(_QWORD *)(result + 944) += *(_QWORD *)(a2 + 824);
  *(_DWORD *)(result + 920) += *(_DWORD *)(a2 + 800);
  *(_DWORD *)(result + 924) += *(_DWORD *)(a2 + 804);
  *(_DWORD *)(result + 904) += *(_DWORD *)(a2 + 784);
  *(_DWORD *)(result + 908) += *(_DWORD *)(a2 + 788);
  *(_DWORD *)(result + 912) += *(_DWORD *)(a2 + 792);
  *(_QWORD *)(result + 2944) += *(_QWORD *)(a2 + 2824);
  *(_QWORD *)(result + 2952) += *(_QWORD *)(a2 + 2832);
  *(_QWORD *)(result + 2960) += *(_QWORD *)(a2 + 2840);
  *(_QWORD *)(result + 2968) += *(_QWORD *)(a2 + 2848);
  v23 = *(_QWORD *)(result + 2984);
  *(_QWORD *)(result + 2976) += *(_QWORD *)(a2 + 2856);
  v24 = *(_QWORD *)(a2 + 2864);
  *(_QWORD *)(result + 784) = v22;
  *(_QWORD *)(result + 2984) = v23 + v24;
  return result;
}
