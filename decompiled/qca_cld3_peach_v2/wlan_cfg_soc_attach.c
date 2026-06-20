__int64 __fastcall wlan_cfg_soc_attach(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  int v12; // w9
  int v13; // w8
  int v14; // w8
  int v15; // w9
  char v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w9
  __int64 v34; // x8

  v2 = _qdf_mem_malloc(0x348u, "wlan_cfg_soc_attach", 4662);
  v11 = v2;
  if ( v2 )
  {
    wlan_minidump_log(v3, v4, v5, v6, v7, v8, v9, v10, v2, 840, a1);
    *(_BYTE *)(v11 + 633) = 1;
    *(_DWORD *)v11 = 18;
    *(_DWORD *)(v11 + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 276);
    *(_DWORD *)(v11 + 8) = *(_DWORD *)(cfg_psoc_get_values(a1) + 272);
    *(_DWORD *)(v11 + 12) = *(_DWORD *)(cfg_psoc_get_values(a1) + 340);
    *(_DWORD *)(v11 + 36) = *(_DWORD *)(cfg_psoc_get_values(a1) + 284);
    *(_DWORD *)(v11 + 20) = *(_DWORD *)(cfg_psoc_get_values(a1) + 292);
    *(_DWORD *)(v11 + 16) = *(_DWORD *)(cfg_psoc_get_values(a1) + 288);
    *(_DWORD *)(v11 + 40) = *(_DWORD *)(cfg_psoc_get_values(a1) + 296);
    *(_DWORD *)(v11 + 24) = *(_DWORD *)(cfg_psoc_get_values(a1) + 300);
    *(_DWORD *)(v11 + 28) = *(_DWORD *)(cfg_psoc_get_values(a1) + 336);
    v12 = *(_DWORD *)(cfg_psoc_get_values(a1) + 392);
    *(_DWORD *)(v11 + 44) = 6;
    *(_DWORD *)(v11 + 32) = v12;
    *(_DWORD *)(v11 + 48) = *(_DWORD *)(cfg_psoc_get_values(a1) + 332);
    *(_DWORD *)(v11 + 60) = *(_DWORD *)(cfg_psoc_get_values(a1) + 304);
    *(_DWORD *)(v11 + 64) = *(_DWORD *)(cfg_psoc_get_values(a1) + 324);
    *(_DWORD *)(v11 + 68) = 16;
    *(_DWORD *)(v11 + 72) = *(_DWORD *)(cfg_psoc_get_values(a1) + 328);
    *(_DWORD *)(v11 + 80) = *(_DWORD *)(cfg_psoc_get_values(a1) + 228);
    *(_DWORD *)(v11 + 76) = *(_DWORD *)(cfg_psoc_get_values(a1) + 280);
    *(_DWORD *)(v11 + 124) = *(_DWORD *)(cfg_psoc_get_values(a1) + 396);
    *(_DWORD *)(v11 + 132) = *(_DWORD *)(cfg_psoc_get_values(a1) + 400);
    *(_DWORD *)(v11 + 140) = *(_DWORD *)(cfg_psoc_get_values(a1) + 348);
    *(_DWORD *)(v11 + 136) = *(_DWORD *)(cfg_psoc_get_values(a1) + 368);
    *(_DWORD *)(v11 + 144) = *(_DWORD *)(cfg_psoc_get_values(a1) + 464);
    *(_DWORD *)(v11 + 148) = *(_DWORD *)(cfg_psoc_get_values(a1) + 388);
    *(_DWORD *)(v11 + 92) = *(_DWORD *)(cfg_psoc_get_values(a1) + 248);
    *(_DWORD *)(v11 + 96) = *(_DWORD *)(cfg_psoc_get_values(a1) + 268);
    *(_DWORD *)(v11 + 100) = *(_DWORD *)(cfg_psoc_get_values(a1) + 244);
    *(_DWORD *)(v11 + 104) = *(_DWORD *)(cfg_psoc_get_values(a1) + 264);
    *(_DWORD *)(v11 + 108) = *(_DWORD *)(cfg_psoc_get_values(a1) + 232);
    *(_DWORD *)(v11 + 112) = *(_DWORD *)(cfg_psoc_get_values(a1) + 256);
    *(_DWORD *)(v11 + 116) = *(_DWORD *)(cfg_psoc_get_values(a1) + 236);
    *(_DWORD *)(v11 + 120) = *(_DWORD *)(cfg_psoc_get_values(a1) + 260);
    *(_DWORD *)(v11 + 84) = *(_DWORD *)(cfg_psoc_get_values(a1) + 240);
    *(_DWORD *)(v11 + 88) = *(_DWORD *)(cfg_psoc_get_values(a1) + 252);
    v13 = *(_DWORD *)(cfg_psoc_get_values(a1) + 608);
    *(_DWORD *)(v11 + 512) = 0;
    *(_BYTE *)(v11 + 712) = v13;
    *(_DWORD *)(v11 + 524) = *(_DWORD *)(cfg_psoc_get_values(a1) + 404);
    *(_BYTE *)(v11 + 528) = *(_BYTE *)(cfg_psoc_get_values(a1) + 408);
    *(_BYTE *)(v11 + 529) = *(_BYTE *)(cfg_psoc_get_values(a1) + 410);
    *(_BYTE *)(v11 + 530) = *(_BYTE *)(cfg_psoc_get_values(a1) + 411);
    *(_BYTE *)(v11 + 531) = *(_BYTE *)(cfg_psoc_get_values(a1) + 412);
    v14 = *(_DWORD *)(cfg_psoc_get_values(a1) + 416);
    if ( (v14 & 1) != 0 )
    {
      *(_BYTE *)(v11 + 532) = 1;
      if ( (v14 & 2) != 0 )
        *(_BYTE *)(v11 + 533) = 1;
    }
    *(_DWORD *)(v11 + 536) = *(_DWORD *)(cfg_psoc_get_values(a1) + 420);
    *(_BYTE *)(v11 + 541) = *(_BYTE *)(cfg_psoc_get_values(a1) + 424);
    *(_BYTE *)(v11 + 542) = *(_BYTE *)(cfg_psoc_get_values(a1) + 425);
    *(_BYTE *)(v11 + 543) = *(_BYTE *)(cfg_psoc_get_values(a1) + 426);
    *(_BYTE *)(v11 + 544) = *(_BYTE *)(cfg_psoc_get_values(a1) + 427);
    *(_BYTE *)(v11 + 545) = *(_BYTE *)(cfg_psoc_get_values(a1) + 428);
    *(_BYTE *)(v11 + 546) = *(_BYTE *)(cfg_psoc_get_values(a1) + 431);
    *(_BYTE *)(v11 + 547) = *(_BYTE *)(cfg_psoc_get_values(a1) + 430);
    *(_BYTE *)(v11 + 548) = *(_BYTE *)(cfg_psoc_get_values(a1) + 429);
    *(_BYTE *)(v11 + 549) = *(_BYTE *)(cfg_psoc_get_values(a1) + 640);
    *(_DWORD *)(v11 + 620) = *(_DWORD *)(cfg_psoc_get_values(a1) + 556);
    *(_BYTE *)(v11 + 550) = *(_BYTE *)(cfg_psoc_get_values(a1) + 432);
    *(_DWORD *)(v11 + 564) = *(_DWORD *)(cfg_psoc_get_values(a1) + 344);
    *(_DWORD *)(v11 + 568) = *(_DWORD *)(cfg_psoc_get_values(a1) + 436);
    *(_DWORD *)(v11 + 572) = *(_DWORD *)(cfg_psoc_get_values(a1) + 440);
    *(_DWORD *)(v11 + 576) = *(_DWORD *)(cfg_psoc_get_values(a1) + 444);
    *(_DWORD *)(v11 + 580) = *(_DWORD *)(cfg_psoc_get_values(a1) + 452);
    *(_DWORD *)(v11 + 584) = *(_DWORD *)(cfg_psoc_get_values(a1) + 456);
    *(_DWORD *)(v11 + 588) = *(_DWORD *)(cfg_psoc_get_values(a1) + 460);
    *(_DWORD *)(v11 + 592) = *(_DWORD *)(cfg_psoc_get_values(a1) + 484);
    *(_DWORD *)(v11 + 596) = *(_DWORD *)(cfg_psoc_get_values(a1) + 488);
    *(_DWORD *)(v11 + 600) = *(_DWORD *)(cfg_psoc_get_values(a1) + 496);
    *(_DWORD *)(v11 + 608) = *(_DWORD *)(cfg_psoc_get_values(a1) + 448);
    *(_BYTE *)(v11 + 604) = *(_BYTE *)(cfg_psoc_get_values(a1) + 501);
    *(_BYTE *)(v11 + 612) = *(_BYTE *)(cfg_psoc_get_values(a1) + 500);
    *(_DWORD *)(v11 + 644) = *(_DWORD *)(cfg_psoc_get_values(a1) + 504);
    *(_DWORD *)(v11 + 648) = *(_DWORD *)(cfg_psoc_get_values(a1) + 508);
    *(_DWORD *)(v11 + 652) = *(_DWORD *)(cfg_psoc_get_values(a1) + 512);
    *(_DWORD *)(v11 + 656) = *(_DWORD *)(cfg_psoc_get_values(a1) + 516);
    *(_DWORD *)(v11 + 660) = *(_DWORD *)(cfg_psoc_get_values(a1) + 520);
    *(_DWORD *)(v11 + 664) = *(_DWORD *)(cfg_psoc_get_values(a1) + 524);
    *(_DWORD *)(v11 + 616) = *(_DWORD *)(cfg_psoc_get_values(a1) + 552);
    *(_DWORD *)(v11 + 628) = *(_DWORD *)(cfg_psoc_get_values(a1) + 584);
    *(_DWORD *)(v11 + 560) = *(_DWORD *)(cfg_psoc_get_values(a1) + 560);
    *(_DWORD *)(v11 + 556) = *(_DWORD *)(cfg_psoc_get_values(a1) + 564);
    *(_BYTE *)(v11 + 632) = *(_BYTE *)(cfg_psoc_get_values(a1) + 580);
    *(_DWORD *)(v11 + 688) = *(_DWORD *)(cfg_psoc_get_values(a1) + 588);
    v15 = *(_DWORD *)(cfg_psoc_get_values(a1) + 592);
    *(_QWORD *)(v11 + 704) = &rx_fst_toeplitz_key;
    *(_DWORD *)(v11 + 692) = v15;
    *(_WORD *)(v11 + 702) = 16;
    *(_BYTE *)(v11 + 697) = *(_BYTE *)(cfg_psoc_get_values(a1) + 600);
    *(_BYTE *)(v11 + 698) = *(_BYTE *)(cfg_psoc_get_values(a1) + 601);
    *(_BYTE *)(v11 + 699) = *(_BYTE *)(cfg_psoc_get_values(a1) + 602);
    *(_WORD *)(v11 + 700) = *(_DWORD *)(cfg_psoc_get_values(a1) + 596);
    *(_BYTE *)(v11 + 696) = *(_BYTE *)(cfg_psoc_get_values(a1) + 603);
    *(_DWORD *)(v11 + 668) = *(_DWORD *)(cfg_psoc_get_values(a1) + 604);
    *(_DWORD *)(v11 + 720) = *(_DWORD *)(cfg_psoc_get_values(a1) + 616);
    *(_DWORD *)(v11 + 724) = *(_DWORD *)(cfg_psoc_get_values(a1) + 620);
    *(_BYTE *)(v11 + 732) = *(_BYTE *)(cfg_psoc_get_values(a1) + 624);
    *(_BYTE *)(v11 + 756) = *(_BYTE *)(cfg_psoc_get_values(a1) + 625);
    *(_BYTE *)(v11 + 757) = *(_BYTE *)(cfg_psoc_get_values(a1) + 626);
    *(_BYTE *)(v11 + 733) = *(_BYTE *)(cfg_psoc_get_values(a1) + 627);
    *(_BYTE *)(v11 + 734) = *(_BYTE *)(cfg_psoc_get_values(a1) + 628);
    v16 = *(_BYTE *)(cfg_psoc_get_values(a1) + 629);
    *(_DWORD *)(v11 + 736) = 2048;
    *(_BYTE *)(v11 + 735) = v16;
    *(_DWORD *)(v11 + 740) = *(_DWORD *)(cfg_psoc_get_values(a1) + 632);
    *(_DWORD *)(v11 + 744) = *(_DWORD *)(cfg_psoc_get_values(a1) + 636);
    *(_BYTE *)(v11 + 748) = *(_BYTE *)(cfg_psoc_get_values(a1) + 641);
    *(_BYTE *)(v11 + 749) = *(_BYTE *)(cfg_psoc_get_values(a1) + 642);
    *(_BYTE *)(v11 + 750) = *(_BYTE *)(cfg_psoc_get_values(a1) + 644);
    *(_BYTE *)(v11 + 751) = *(_BYTE *)(cfg_psoc_get_values(a1) + 643);
    *(_BYTE *)(v11 + 752) = *(_DWORD *)(cfg_psoc_get_values(a1) + 648);
    *(_BYTE *)(v11 + 753) = *(_DWORD *)(cfg_psoc_get_values(a1) + 652);
    *(_BYTE *)(v11 + 754) = *(_DWORD *)(cfg_psoc_get_values(a1) + 656);
    *(_BYTE *)(v11 + 755) = *(_BYTE *)(cfg_psoc_get_values(a1) + 660);
    *(_BYTE *)(v11 + 634) = *(_BYTE *)(cfg_psoc_get_values(a1) + 662);
    *(_DWORD *)(v11 + 52) = *(_DWORD *)(cfg_psoc_get_values(a1) + 528);
    *(_DWORD *)(v11 + 56) = *(_DWORD *)(cfg_psoc_get_values(a1) + 532);
    *(_DWORD *)(v11 + 784) = *(_DWORD *)(cfg_psoc_get_values(a1) + 536);
    *(_DWORD *)(v11 + 788) = *(_DWORD *)(cfg_psoc_get_values(a1) + 664);
    *(_DWORD *)(v11 + 792) = *(_DWORD *)(cfg_psoc_get_values(a1) + 668);
    *(_BYTE *)(v11 + 828) = *(_DWORD *)(cfg_psoc_get_values(a1) + 744);
    *(_BYTE *)(v11 + 829) = *(_DWORD *)(cfg_psoc_get_values(a1) + 748);
    if ( (ucfg_ipa_get_pld_enable() & 1) != 0 )
    {
      *(_BYTE *)(v11 + 540) = get_ipa_config(a1) & 1;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: is IPA enabled from ini: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_soc_ipa_cfg_attach");
    }
    else
    {
      *(_BYTE *)(v11 + 540) = 0;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: IPA disabled from platform driver",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_soc_ipa_cfg_attach");
    }
    *(_DWORD *)(v11 + 760) = *(_DWORD *)(cfg_psoc_get_values(a1) + 684);
    *(_DWORD *)(v11 + 764) = *(_DWORD *)(cfg_psoc_get_values(a1) + 688);
    v33 = *(_BYTE *)(cfg_psoc_get_values(a1) + 661);
    *(_BYTE *)(v11 + 804) = 2;
    *(_BYTE *)(v11 + 768) = v33;
    *(_BYTE *)(v11 + 808) = 2;
    *(_BYTE *)(v11 + 809) = *(_DWORD *)(cfg_psoc_get_values(a1) + 676);
    *(_BYTE *)(v11 + 810) = *(_DWORD *)(cfg_psoc_get_values(a1) + 680);
    *(_BYTE *)(v11 + 811) = *(_DWORD *)(cfg_psoc_get_values(a1) + 696);
    *(_BYTE *)(v11 + 813) = *(_BYTE *)(cfg_psoc_get_values(a1) + 701);
    *(_BYTE *)(v11 + 806) = *(_BYTE *)(cfg_psoc_get_values(a1) + 702);
    *(_BYTE *)(v11 + 807) = *(_BYTE *)(cfg_psoc_get_values(a1) + 703);
    *(_WORD *)(v11 + 814) = *(_DWORD *)(cfg_psoc_get_values(a1) + 704);
    *(_BYTE *)(v11 + 816) = *(_DWORD *)(cfg_psoc_get_values(a1) + 708);
    *(_BYTE *)(v11 + 817) = *(_BYTE *)(cfg_psoc_get_values(a1) + 712);
    *(_BYTE *)(v11 + 830) = *(_BYTE *)(cfg_psoc_get_values(a1) + 720);
    *(_DWORD *)(v11 + 820) = *(_DWORD *)(cfg_psoc_get_values(a1) + 716);
    *(_DWORD *)(v11 + 128) = *(_DWORD *)(cfg_psoc_get_values(a1) + 752);
    *(_WORD *)(v11 + 826) = *(_DWORD *)(cfg_psoc_get_values(a1) + 756);
    if ( a1 )
      v34 = *(_QWORD *)(a1 + 2120);
    else
      v34 = 0;
    *(_BYTE *)(v11 + 831) = pld_is_audio_shared_iommu_group(*(_QWORD *)(v34 + 40)) & 1;
    *(_BYTE *)(v11 + 833) = *(_BYTE *)(cfg_psoc_get_values(a1) + 761);
    *(_BYTE *)(v11 + 832) = *(_BYTE *)(cfg_psoc_get_values(a1) + 760);
    *(_BYTE *)(v11 + 834) = *(_BYTE *)(cfg_psoc_get_values(a1) + 762);
    *(_BYTE *)(v11 + 835) = *(_BYTE *)(cfg_psoc_get_values(a1) + 763);
  }
  return v11;
}
