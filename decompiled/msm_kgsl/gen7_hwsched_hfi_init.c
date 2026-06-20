unsigned __int64 __fastcall gen7_hwsched_hfi_init(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x8
  __int64 v4; // x20
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  int v8; // w8
  __int64 v9; // x9
  unsigned __int64 v10; // x20

  v2 = to_gen7_hfi((__int64)a1);
  v3 = a1[3077];
  v4 = v2;
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL
    || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                   a1,
                   0,
                   24000,
                   4,
                   0),
        a1[3077] = result,
        result < 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (*(_BYTE *)(a1[1783] + 33LL) & 0x80) == 0
      || (v6 = a1[3078]) != 0 && v6 < 0xFFFFFFFFFFFFF001LL
      || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                     a1,
                     0,
                     24000,
                     4,
                     0),
          a1[3078] = result,
          result < 0xFFFFFFFFFFFFF001LL) )
    {
      v7 = *(_QWORD *)(v4 + 8);
      if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
      {
        result = a1[3073];
        if ( !result )
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
        v8 = *(_DWORD *)(result + 184);
        v9 = *(_QWORD *)(result + 8);
        *(_QWORD *)v9 = 0xD200000000LL;
        *(_QWORD *)(v9 + 8) = 0xC00000006LL;
        *(_QWORD *)(v9 + 48) = 0;
        *(_QWORD *)(v9 + 56) = 0;
        *(_QWORD *)(v9 + 16) = 0x1100000011LL;
        *(_DWORD *)(v9 + 24) = 1;
        *(_DWORD *)(v9 + 28) = v8 + 848;
        *(_QWORD *)(v9 + 32) = 0x40000000000LL;
        *(_QWORD *)(v9 + 40) = 0;
        *(_DWORD *)(v9 + 264) = 1;
        *(_DWORD *)(v9 + 312) = 1;
        *(_DWORD *)(v9 + 64) = 0;
        *(_DWORD *)(v9 + 68) = 0;
        *(_DWORD *)(v9 + 360) = 1;
        *(_DWORD *)(v9 + 72) = 1;
        *(_DWORD *)(v9 + 76) = v8 + 4944;
        *(_DWORD *)(v9 + 408) = 1;
        *(_QWORD *)(v9 + 80) = 0x40000000001LL;
        *(_QWORD *)(v9 + 88) = 0;
        *(_DWORD *)(v9 + 456) = 1;
        *(_DWORD *)(v9 + 504) = 1;
        *(_DWORD *)(v9 + 112) = 0;
        *(_DWORD *)(v9 + 116) = 0;
        *(_DWORD *)(v9 + 552) = 1;
        *(_DWORD *)(v9 + 120) = 1;
        *(_DWORD *)(v9 + 124) = v8 + 9040;
        *(_DWORD *)(v9 + 600) = 1;
        *(_QWORD *)(v9 + 128) = 0x40000000002LL;
        *(_QWORD *)(v9 + 136) = 0;
        *(_DWORD *)(v9 + 648) = 1;
        *(_DWORD *)(v9 + 696) = 1;
        *(_DWORD *)(v9 + 160) = 0;
        *(_DWORD *)(v9 + 164) = 0;
        *(_DWORD *)(v9 + 744) = 1;
        *(_DWORD *)(v9 + 168) = 1;
        *(_DWORD *)(v9 + 172) = v8 + 13136;
        *(_DWORD *)(v9 + 792) = 1;
        *(_QWORD *)(v9 + 176) = 0x40000000003LL;
        *(_QWORD *)(v9 + 184) = 0;
        *(_QWORD *)(v9 + 96) = 0;
        *(_QWORD *)(v9 + 104) = 0;
        *(_QWORD *)(v9 + 144) = 0;
        *(_QWORD *)(v9 + 152) = 0;
        *(_DWORD *)(v9 + 208) = 0;
        *(_DWORD *)(v9 + 212) = 0;
        *(_QWORD *)(v9 + 192) = 0;
        *(_QWORD *)(v9 + 200) = 0;
        *(_DWORD *)(v9 + 216) = 1;
        *(_DWORD *)(v9 + 220) = v8 + 17232;
        *(_QWORD *)(v9 + 240) = 0;
        *(_QWORD *)(v9 + 248) = 0;
        *(_QWORD *)(v9 + 224) = 0x40000000004LL;
        *(_QWORD *)(v9 + 232) = 0;
        *(_QWORD *)(v9 + 288) = 0;
        *(_QWORD *)(v9 + 296) = 0;
        *(_QWORD *)(v9 + 336) = 0;
        *(_QWORD *)(v9 + 344) = 0;
        *(_DWORD *)(v9 + 256) = 0;
        *(_DWORD *)(v9 + 260) = 0;
        *(_DWORD *)(v9 + 268) = v8 + 21328;
        *(_QWORD *)(v9 + 384) = 0;
        *(_QWORD *)(v9 + 392) = 0;
        *(_QWORD *)(v9 + 272) = 0x40000000005LL;
        *(_QWORD *)(v9 + 280) = 0;
        *(_QWORD *)(v9 + 432) = 0;
        *(_QWORD *)(v9 + 440) = 0;
        *(_QWORD *)(v9 + 480) = 0;
        *(_QWORD *)(v9 + 488) = 0;
        *(_DWORD *)(v9 + 304) = 0;
        *(_DWORD *)(v9 + 308) = 0;
        *(_DWORD *)(v9 + 316) = v8 + 25424;
        *(_QWORD *)(v9 + 536) = 0;
        *(_QWORD *)(v9 + 320) = 0x40000000006LL;
        *(_QWORD *)(v9 + 328) = 0;
        *(_QWORD *)(v9 + 528) = 0;
        *(_QWORD *)(v9 + 520) = 0;
        *(_DWORD *)(v9 + 352) = 0;
        *(_DWORD *)(v9 + 356) = 0;
        *(_DWORD *)(v9 + 364) = v8 + 29520;
        *(_QWORD *)(v9 + 584) = 0;
        *(_QWORD *)(v9 + 368) = 0x40000000107LL;
        *(_QWORD *)(v9 + 376) = 0;
        *(_QWORD *)(v9 + 576) = 0;
        *(_QWORD *)(v9 + 568) = 0;
        *(_DWORD *)(v9 + 400) = 0;
        *(_DWORD *)(v9 + 404) = 0;
        *(_DWORD *)(v9 + 412) = v8 + 33616;
        *(_DWORD *)(v9 + 448) = 0;
        *(_QWORD *)(v9 + 416) = 0x40000000108LL;
        *(_QWORD *)(v9 + 424) = 0;
        *(_QWORD *)(v9 + 632) = 0;
        *(_DWORD *)(v9 + 452) = 0;
        *(_DWORD *)(v9 + 460) = v8 + 37712;
        *(_QWORD *)(v9 + 624) = 0;
        *(_QWORD *)(v9 + 464) = 0x40000000109LL;
        *(_QWORD *)(v9 + 472) = 0;
        *(_QWORD *)(v9 + 616) = 0;
        *(_QWORD *)(v9 + 680) = 0;
        *(_DWORD *)(v9 + 496) = 0;
        *(_DWORD *)(v9 + 500) = 0;
        *(_DWORD *)(v9 + 508) = v8 + 41808;
        *(_QWORD *)(v9 + 672) = 0;
        *(_QWORD *)(v9 + 512) = 0x4000000010ALL;
        *(_QWORD *)(v9 + 664) = 0;
        *(_QWORD *)(v9 + 728) = 0;
        *(_DWORD *)(v9 + 544) = 0;
        *(_DWORD *)(v9 + 548) = 0;
        *(_DWORD *)(v9 + 556) = v8 + 45904;
        *(_QWORD *)(v9 + 720) = 0;
        *(_QWORD *)(v9 + 560) = 0x4000000020BLL;
        *(_QWORD *)(v9 + 712) = 0;
        *(_QWORD *)(v9 + 776) = 0;
        *(_DWORD *)(v9 + 592) = 0;
        *(_DWORD *)(v9 + 596) = 0;
        *(_DWORD *)(v9 + 604) = v8 + 50000;
        *(_QWORD *)(v9 + 768) = 0;
        *(_QWORD *)(v9 + 608) = 0x4000000020CLL;
        *(_QWORD *)(v9 + 760) = 0;
        *(_QWORD *)(v9 + 824) = 0;
        *(_DWORD *)(v9 + 640) = 0;
        *(_DWORD *)(v9 + 644) = 0;
        *(_DWORD *)(v9 + 652) = v8 + 54096;
        *(_QWORD *)(v9 + 816) = 0;
        *(_QWORD *)(v9 + 656) = 0x4000000020DLL;
        *(_QWORD *)(v9 + 808) = 0;
        *(_DWORD *)(v9 + 688) = 0;
        *(_DWORD *)(v9 + 692) = 0;
        *(_DWORD *)(v9 + 700) = v8 + 58192;
        *(_QWORD *)(v9 + 704) = 0x4000000030ELL;
        *(_DWORD *)(v9 + 736) = 0;
        *(_DWORD *)(v9 + 740) = 0;
        *(_DWORD *)(v9 + 748) = v8 + 62288;
        *(_DWORD *)(v9 + 796) = v8 + 66384;
        *(_QWORD *)(v9 + 752) = 0x4000000030FLL;
        *(_QWORD *)(v9 + 800) = 0x40000000410LL;
        *(_DWORD *)(v9 + 784) = 0;
        *(_DWORD *)(v9 + 788) = 0;
        *(_DWORD *)(v9 + 832) = 0;
        *(_DWORD *)(v9 + 836) = 0;
        result = a1[3073];
        if ( !result )
          goto LABEL_16;
      }
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
LABEL_19:
        if ( result <= 0xFFFFFFFFFFFFF000LL )
          return 0;
        else
          return (unsigned int)result;
      }
LABEL_16:
      result = kthread_create_on_node(hfi_f2h_main_0, a1, 0xFFFFFFFFLL, "gmu_f2h");
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
        v10 = result;
        wake_up_process(result);
        a1[3073] = v10;
        sched_set_fifo(v10);
        result = a1[3073];
      }
      else
      {
        a1[3073] = result;
      }
      goto LABEL_19;
    }
  }
  return result;
}
