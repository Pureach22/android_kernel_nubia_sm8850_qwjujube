void *__fastcall qcedev_offload_translate_to_areq(__int64 a1, __int64 a2)
{
  void *result; // x0
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  unsigned int v8; // w8
  unsigned int v9; // w9
  char v10; // w9
  int v11; // w8

  result = memset((void *)(a1 + 56), 0, 0x2F8u);
  *(_QWORD *)(a1 + 56) = *(unsigned int *)(a2 + 8);
  *(_QWORD *)(a1 + 64) = *(_QWORD *)a2;
  *(_QWORD *)(a1 + 312) = *(unsigned int *)(a2 + 264);
  *(_QWORD *)(a1 + 320) = *(_QWORD *)(a2 + 256);
  *(_QWORD *)(a1 + 72) = *(unsigned int *)(a2 + 24);
  *(_QWORD *)(a1 + 80) = *(_QWORD *)(a2 + 16);
  *(_QWORD *)(a1 + 328) = *(unsigned int *)(a2 + 280);
  *(_QWORD *)(a1 + 336) = *(_QWORD *)(a2 + 272);
  *(_QWORD *)(a1 + 88) = *(unsigned int *)(a2 + 40);
  *(_QWORD *)(a1 + 96) = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a1 + 344) = *(unsigned int *)(a2 + 296);
  *(_QWORD *)(a1 + 352) = *(_QWORD *)(a2 + 288);
  *(_QWORD *)(a1 + 104) = *(unsigned int *)(a2 + 56);
  *(_QWORD *)(a1 + 112) = *(_QWORD *)(a2 + 48);
  *(_QWORD *)(a1 + 360) = *(unsigned int *)(a2 + 312);
  *(_QWORD *)(a1 + 368) = *(_QWORD *)(a2 + 304);
  *(_QWORD *)(a1 + 120) = *(unsigned int *)(a2 + 72);
  *(_QWORD *)(a1 + 128) = *(_QWORD *)(a2 + 64);
  *(_QWORD *)(a1 + 376) = *(unsigned int *)(a2 + 328);
  *(_QWORD *)(a1 + 384) = *(_QWORD *)(a2 + 320);
  *(_QWORD *)(a1 + 136) = *(unsigned int *)(a2 + 88);
  *(_QWORD *)(a1 + 144) = *(_QWORD *)(a2 + 80);
  *(_QWORD *)(a1 + 392) = *(unsigned int *)(a2 + 344);
  *(_QWORD *)(a1 + 400) = *(_QWORD *)(a2 + 336);
  *(_QWORD *)(a1 + 152) = *(unsigned int *)(a2 + 104);
  *(_QWORD *)(a1 + 160) = *(_QWORD *)(a2 + 96);
  *(_QWORD *)(a1 + 408) = *(unsigned int *)(a2 + 360);
  *(_QWORD *)(a1 + 416) = *(_QWORD *)(a2 + 352);
  *(_QWORD *)(a1 + 168) = *(unsigned int *)(a2 + 120);
  *(_QWORD *)(a1 + 176) = *(_QWORD *)(a2 + 112);
  *(_QWORD *)(a1 + 424) = *(unsigned int *)(a2 + 376);
  *(_QWORD *)(a1 + 432) = *(_QWORD *)(a2 + 368);
  *(_QWORD *)(a1 + 184) = *(unsigned int *)(a2 + 136);
  *(_QWORD *)(a1 + 192) = *(_QWORD *)(a2 + 128);
  *(_QWORD *)(a1 + 440) = *(unsigned int *)(a2 + 392);
  *(_QWORD *)(a1 + 448) = *(_QWORD *)(a2 + 384);
  *(_QWORD *)(a1 + 200) = *(unsigned int *)(a2 + 152);
  *(_QWORD *)(a1 + 208) = *(_QWORD *)(a2 + 144);
  *(_QWORD *)(a1 + 456) = *(unsigned int *)(a2 + 408);
  *(_QWORD *)(a1 + 464) = *(_QWORD *)(a2 + 400);
  *(_QWORD *)(a1 + 216) = *(unsigned int *)(a2 + 168);
  *(_QWORD *)(a1 + 224) = *(_QWORD *)(a2 + 160);
  *(_QWORD *)(a1 + 472) = *(unsigned int *)(a2 + 424);
  *(_QWORD *)(a1 + 480) = *(_QWORD *)(a2 + 416);
  *(_QWORD *)(a1 + 232) = *(unsigned int *)(a2 + 184);
  *(_QWORD *)(a1 + 240) = *(_QWORD *)(a2 + 176);
  *(_QWORD *)(a1 + 488) = *(unsigned int *)(a2 + 440);
  *(_QWORD *)(a1 + 496) = *(_QWORD *)(a2 + 432);
  *(_QWORD *)(a1 + 248) = *(unsigned int *)(a2 + 200);
  *(_QWORD *)(a1 + 256) = *(_QWORD *)(a2 + 192);
  *(_QWORD *)(a1 + 504) = *(unsigned int *)(a2 + 456);
  *(_QWORD *)(a1 + 512) = *(_QWORD *)(a2 + 448);
  *(_QWORD *)(a1 + 264) = *(unsigned int *)(a2 + 216);
  *(_QWORD *)(a1 + 272) = *(_QWORD *)(a2 + 208);
  *(_QWORD *)(a1 + 520) = *(unsigned int *)(a2 + 472);
  *(_QWORD *)(a1 + 528) = *(_QWORD *)(a2 + 464);
  *(_QWORD *)(a1 + 280) = *(unsigned int *)(a2 + 232);
  *(_QWORD *)(a1 + 288) = *(_QWORD *)(a2 + 224);
  *(_QWORD *)(a1 + 536) = *(unsigned int *)(a2 + 488);
  *(_QWORD *)(a1 + 544) = *(_QWORD *)(a2 + 480);
  *(_QWORD *)(a1 + 296) = *(unsigned int *)(a2 + 248);
  *(_QWORD *)(a1 + 304) = *(_QWORD *)(a2 + 240);
  *(_QWORD *)(a1 + 552) = *(unsigned int *)(a2 + 504);
  *(_QWORD *)(a1 + 560) = *(_QWORD *)(a2 + 496);
  v5 = *(_QWORD *)(a2 + 544);
  v6 = *(_QWORD *)(a2 + 528);
  v7 = *(_QWORD *)(a2 + 536);
  *(_QWORD *)(a1 + 624) = *(_QWORD *)(a2 + 552);
  *(_QWORD *)(a1 + 616) = v5;
  *(_QWORD *)(a1 + 608) = v7;
  *(_QWORD *)(a1 + 600) = v6;
  *(_DWORD *)(a1 + 568) = *(_DWORD *)(a2 + 512);
  *(_DWORD *)(a1 + 588) = *(_DWORD *)(a2 + 564);
  *(_DWORD *)(a1 + 592) = *(_DWORD *)(a2 + 560);
  *(_QWORD *)(a1 + 712) = *(unsigned int *)(a2 + 516);
  v8 = *(unsigned __int8 *)(a2 + 572);
  v9 = *(_DWORD *)(a2 + 568);
  *(_QWORD *)(a1 + 696) = 0;
  if ( v9 > v8 )
    LOBYTE(v8) = v9;
  *(_BYTE *)(a1 + 576) = v8;
  *(_BYTE *)(a1 + 577) = *(_BYTE *)(a2 + 575);
  *(_BYTE *)(a1 + 578) = *(_BYTE *)(a2 + 573);
  *(_BYTE *)(a1 + 579) = *(_BYTE *)(a2 + 574);
  *(_BYTE *)(a1 + 580) = *(_DWORD *)(a2 + 520);
  v10 = *(_BYTE *)(a2 + 578);
  *(_WORD *)(a1 + 792) = *(_WORD *)(a2 + 576);
  *(_BYTE *)(a1 + 794) = v10;
  *(_DWORD *)(a1 + 800) = *(_DWORD *)(a2 + 580);
  *(_DWORD *)(a1 + 804) = *(_DWORD *)(a2 + 584);
  *(_DWORD *)(a1 + 808) = *(_DWORD *)(a2 + 588);
  *(_DWORD *)(a1 + 812) = *(_DWORD *)(a2 + 592);
  v11 = *(_DWORD *)(a2 + 524);
  *(_DWORD *)(a1 + 724) = 1;
  *(_QWORD *)(a1 + 688) = 0;
  *(_QWORD *)(a1 + 680) = 0;
  *(_QWORD *)(a1 + 672) = 0;
  *(_QWORD *)(a1 + 664) = 0;
  *(_QWORD *)(a1 + 656) = 0;
  *(_QWORD *)(a1 + 648) = 0;
  *(_QWORD *)(a1 + 640) = 0;
  *(_QWORD *)(a1 + 632) = 0;
  *(_DWORD *)(a1 + 596) = 0;
  *(_DWORD *)(a1 + 720) = v11;
  *(_QWORD *)(a1 + 704) = 0;
  return result;
}
