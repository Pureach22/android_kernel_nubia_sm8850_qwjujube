unsigned __int64 __fastcall a6xx_hwsched_hfi_init(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x8
  __int64 v4; // x20
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x20
  int v9; // w8
  __int64 v10; // x9
  unsigned __int64 v11; // x0

  v2 = to_a6xx_hfi((__int64)a1);
  v3 = a1[3076];
  v4 = v2;
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL
    || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                   a1,
                   0,
                   24000,
                   4,
                   0),
        a1[3076] = result,
        result < 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (*(_BYTE *)(a1[1783] + 33LL) & 0x80) == 0
      || (v6 = a1[3077]) != 0 && v6 < 0xFFFFFFFFFFFFF001LL
      || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                     a1,
                     0,
                     24000,
                     4,
                     0),
          a1[3077] = result,
          result < 0xFFFFFFFFFFFFF001LL) )
    {
      v7 = *(_QWORD *)(v4 + 8);
      if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
      {
        v8 = a1[3072];
        if ( !v8 )
          goto LABEL_16;
      }
      else
      {
        result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                   a1,
                   0,
                   70488,
                   4,
                   0);
        *(_QWORD *)(v4 + 8) = result;
        if ( result >= 0xFFFFFFFFFFFFF001LL )
          return result;
        v9 = *(_DWORD *)(result + 184);
        v10 = *(_QWORD *)(result + 8);
        *(_QWORD *)v10 = 0xD200000000LL;
        *(_QWORD *)(v10 + 8) = 0xC00000006LL;
        *(_QWORD *)(v10 + 48) = 0;
        *(_QWORD *)(v10 + 56) = 0;
        *(_QWORD *)(v10 + 16) = 0x1100000011LL;
        *(_DWORD *)(v10 + 24) = 1;
        *(_DWORD *)(v10 + 28) = v9 + 848;
        *(_QWORD *)(v10 + 32) = 0x40000000000LL;
        *(_QWORD *)(v10 + 40) = 0;
        *(_DWORD *)(v10 + 264) = 1;
        *(_DWORD *)(v10 + 312) = 1;
        *(_DWORD *)(v10 + 64) = 0;
        *(_DWORD *)(v10 + 68) = 0;
        *(_DWORD *)(v10 + 360) = 1;
        *(_DWORD *)(v10 + 72) = 1;
        *(_DWORD *)(v10 + 76) = v9 + 4944;
        *(_DWORD *)(v10 + 408) = 1;
        *(_QWORD *)(v10 + 80) = 0x40000000001LL;
        *(_QWORD *)(v10 + 88) = 0;
        *(_DWORD *)(v10 + 456) = 1;
        *(_DWORD *)(v10 + 504) = 1;
        *(_DWORD *)(v10 + 112) = 0;
        *(_DWORD *)(v10 + 116) = 0;
        *(_DWORD *)(v10 + 552) = 1;
        *(_DWORD *)(v10 + 120) = 1;
        *(_DWORD *)(v10 + 124) = v9 + 9040;
        *(_DWORD *)(v10 + 600) = 1;
        *(_QWORD *)(v10 + 128) = 0x40000000002LL;
        *(_QWORD *)(v10 + 136) = 0;
        *(_DWORD *)(v10 + 648) = 1;
        *(_DWORD *)(v10 + 696) = 1;
        *(_DWORD *)(v10 + 160) = 0;
        *(_DWORD *)(v10 + 164) = 0;
        *(_DWORD *)(v10 + 744) = 1;
        *(_DWORD *)(v10 + 168) = 1;
        *(_DWORD *)(v10 + 172) = v9 + 13136;
        *(_DWORD *)(v10 + 792) = 1;
        *(_QWORD *)(v10 + 176) = 0x40000000003LL;
        *(_QWORD *)(v10 + 184) = 0;
        *(_QWORD *)(v10 + 96) = 0;
        *(_QWORD *)(v10 + 104) = 0;
        *(_QWORD *)(v10 + 144) = 0;
        *(_QWORD *)(v10 + 152) = 0;
        *(_DWORD *)(v10 + 208) = 0;
        *(_DWORD *)(v10 + 212) = 0;
        *(_QWORD *)(v10 + 192) = 0;
        *(_QWORD *)(v10 + 200) = 0;
        *(_DWORD *)(v10 + 216) = 1;
        *(_DWORD *)(v10 + 220) = v9 + 17232;
        *(_QWORD *)(v10 + 240) = 0;
        *(_QWORD *)(v10 + 248) = 0;
        *(_QWORD *)(v10 + 224) = 0x40000000004LL;
        *(_QWORD *)(v10 + 232) = 0;
        *(_QWORD *)(v10 + 288) = 0;
        *(_QWORD *)(v10 + 296) = 0;
        *(_QWORD *)(v10 + 336) = 0;
        *(_QWORD *)(v10 + 344) = 0;
        *(_DWORD *)(v10 + 256) = 0;
        *(_DWORD *)(v10 + 260) = 0;
        *(_DWORD *)(v10 + 268) = v9 + 21328;
        *(_QWORD *)(v10 + 384) = 0;
        *(_QWORD *)(v10 + 392) = 0;
        *(_QWORD *)(v10 + 272) = 0x40000000005LL;
        *(_QWORD *)(v10 + 280) = 0;
        *(_QWORD *)(v10 + 432) = 0;
        *(_QWORD *)(v10 + 440) = 0;
        *(_QWORD *)(v10 + 480) = 0;
        *(_QWORD *)(v10 + 488) = 0;
        *(_DWORD *)(v10 + 304) = 0;
        *(_DWORD *)(v10 + 308) = 0;
        *(_DWORD *)(v10 + 316) = v9 + 25424;
        *(_QWORD *)(v10 + 536) = 0;
        *(_QWORD *)(v10 + 320) = 0x40000000006LL;
        *(_QWORD *)(v10 + 328) = 0;
        *(_QWORD *)(v10 + 528) = 0;
        *(_QWORD *)(v10 + 520) = 0;
        *(_DWORD *)(v10 + 352) = 0;
        *(_DWORD *)(v10 + 356) = 0;
        *(_DWORD *)(v10 + 364) = v9 + 29520;
        *(_QWORD *)(v10 + 584) = 0;
        *(_QWORD *)(v10 + 368) = 0x40000000107LL;
        *(_QWORD *)(v10 + 376) = 0;
        *(_QWORD *)(v10 + 576) = 0;
        *(_QWORD *)(v10 + 568) = 0;
        *(_DWORD *)(v10 + 400) = 0;
        *(_DWORD *)(v10 + 404) = 0;
        *(_DWORD *)(v10 + 412) = v9 + 33616;
        *(_DWORD *)(v10 + 448) = 0;
        *(_QWORD *)(v10 + 416) = 0x40000000108LL;
        *(_QWORD *)(v10 + 424) = 0;
        *(_QWORD *)(v10 + 632) = 0;
        *(_DWORD *)(v10 + 452) = 0;
        *(_DWORD *)(v10 + 460) = v9 + 37712;
        *(_QWORD *)(v10 + 624) = 0;
        *(_QWORD *)(v10 + 464) = 0x40000000109LL;
        *(_QWORD *)(v10 + 472) = 0;
        *(_QWORD *)(v10 + 616) = 0;
        *(_QWORD *)(v10 + 680) = 0;
        *(_DWORD *)(v10 + 496) = 0;
        *(_DWORD *)(v10 + 500) = 0;
        *(_DWORD *)(v10 + 508) = v9 + 41808;
        *(_QWORD *)(v10 + 672) = 0;
        *(_QWORD *)(v10 + 512) = 0x4000000010ALL;
        *(_QWORD *)(v10 + 664) = 0;
        *(_QWORD *)(v10 + 728) = 0;
        *(_DWORD *)(v10 + 544) = 0;
        *(_DWORD *)(v10 + 548) = 0;
        *(_DWORD *)(v10 + 556) = v9 + 45904;
        *(_QWORD *)(v10 + 720) = 0;
        *(_QWORD *)(v10 + 560) = 0x4000000020BLL;
        *(_QWORD *)(v10 + 712) = 0;
        *(_QWORD *)(v10 + 776) = 0;
        *(_DWORD *)(v10 + 592) = 0;
        *(_DWORD *)(v10 + 596) = 0;
        *(_DWORD *)(v10 + 604) = v9 + 50000;
        *(_QWORD *)(v10 + 768) = 0;
        *(_QWORD *)(v10 + 608) = 0x4000000020CLL;
        *(_QWORD *)(v10 + 760) = 0;
        *(_QWORD *)(v10 + 824) = 0;
        *(_DWORD *)(v10 + 640) = 0;
        *(_DWORD *)(v10 + 644) = 0;
        *(_DWORD *)(v10 + 652) = v9 + 54096;
        *(_QWORD *)(v10 + 816) = 0;
        *(_QWORD *)(v10 + 656) = 0x4000000020DLL;
        *(_QWORD *)(v10 + 808) = 0;
        *(_DWORD *)(v10 + 688) = 0;
        *(_DWORD *)(v10 + 692) = 0;
        *(_DWORD *)(v10 + 700) = v9 + 58192;
        *(_QWORD *)(v10 + 704) = 0x4000000030ELL;
        *(_DWORD *)(v10 + 736) = 0;
        *(_DWORD *)(v10 + 740) = 0;
        *(_DWORD *)(v10 + 748) = v9 + 62288;
        *(_DWORD *)(v10 + 796) = v9 + 66384;
        *(_QWORD *)(v10 + 752) = 0x4000000030FLL;
        *(_QWORD *)(v10 + 800) = 0x40000000310LL;
        *(_DWORD *)(v10 + 784) = 0;
        *(_DWORD *)(v10 + 788) = 0;
        *(_DWORD *)(v10 + 832) = 0;
        *(_DWORD *)(v10 + 836) = 0;
        v8 = a1[3072];
        if ( !v8 )
          goto LABEL_16;
      }
      if ( v8 < 0xFFFFFFFFFFFFF001LL )
      {
LABEL_19:
        if ( v8 <= 0xFFFFFFFFFFFFF000LL )
          return 0;
        else
          return (unsigned int)v8;
      }
LABEL_16:
      v11 = kthread_create_on_node(hfi_f2h_main, a1, 0xFFFFFFFFLL, "gmu_f2h");
      v8 = v11;
      if ( v11 <= 0xFFFFFFFFFFFFF000LL )
        wake_up_process(v11);
      a1[3072] = v8;
      goto LABEL_19;
    }
  }
  return result;
}
