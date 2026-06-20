__int64 __fastcall hw_fence_lookup_and_create_range(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        __int64 *a7,
        unsigned int a8,
        unsigned int a9,
        char a10)
{
  __int64 v10; // x30
  __int64 v11; // x27
  unsigned int v17; // w0
  unsigned int v18; // w28
  __int64 v19; // x21
  __int64 v20; // x27
  int v21; // w22
  __int64 (*v22)(void); // x8
  __int64 v23; // x27
  char v24; // w21
  char v25; // w8
  __int64 result; // x0
  int v27; // w8
  int v28; // w9
  __int64 v29; // x2
  __int64 v30; // [xsp+18h] [xbp-28h]
  _QWORD v33[2]; // [xsp+30h] [xbp-10h] BYREF

  v11 = v10;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  if ( a1 && a7 )
  {
    v17 = hw_fence_iterator_init(a1, v33, a7, a4, a5, a8, a9);
    if ( v17 < a9 )
    {
      v18 = v17;
      v30 = v11;
      while ( 1 )
      {
        v19 = v33[0];
        v20 = *a7;
        if ( !*(_DWORD *)v33[0] )
        {
          *(_DWORD *)(v33[0] + 4LL) = 0;
          __dsb(0xEu);
          *(_QWORD *)(v19 + 48) = 0;
          *(_QWORD *)(v19 + 56) = -1;
          *(_QWORD *)(v19 + 64) = -1;
          *(_QWORD *)(v19 + 72) = -1;
          *(_DWORD *)v19 = 1;
          v22 = (__int64 (*)(void))arch_timer_read_counter;
          *(_QWORD *)(v19 + 24) = 0;
          *(_QWORD *)(v19 + 32) = 0;
          *(_QWORD *)(v19 + 80) = 0;
          *(_QWORD *)(v19 + 88) = 0;
          *(_QWORD *)(v19 + 96) = 0;
          *(_QWORD *)(v19 + 104) = 0;
          *(_QWORD *)(v19 + 112) = 0;
          *(_QWORD *)(v19 + 120) = 0;
          *(_QWORD *)(v19 + 8) = a4;
          *(_QWORD *)(v19 + 16) = a5;
          *(_DWORD *)(v19 + 32) = a2;
          if ( *((_DWORD *)v22 - 1) != -1073338243 )
            __break(0x8228u);
          *(_QWORD *)(v19 + 88) = v22();
          *(_DWORD *)(v19 + 112) = -2147483647;
          *(_DWORD *)(v19 + 84) = a6;
          *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (unsigned int)v20) = a3;
          if ( (~msm_hw_fence_debug_level & 0x10020) == 0 )
            printk(&unk_21823, "_reserve_hw_fence", 1325, a2, a4);
          __dsb(0xEu);
          v21 = 0;
          if ( (~msm_hw_fence_debug_level & 0x10002) != 0 )
          {
            v23 = v30;
            goto LABEL_18;
          }
          v23 = v30;
          v29 = 1376;
          goto LABEL_39;
        }
        if ( *(_QWORD *)(v33[0] + 8LL) == a4
          && *(_QWORD *)(v33[0] + 16LL) == a5
          && *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8 * v20) == a3 )
        {
          break;
        }
        v18 = hw_fence_iterator_next(a1, v33, a7, v18, a9, 0);
        if ( v18 >= a9 )
        {
          v21 = 0;
          v24 = 0;
          goto LABEL_19;
        }
      }
      if ( (a10 & 2) != 0 )
      {
        v27 = *(_DWORD *)(v33[0] + 112LL);
        if ( (~v27 & 0x3FFFFFFF) != 0 )
        {
          v28 = msm_hw_fence_debug_level;
          *(_DWORD *)(v33[0] + 112LL) = v27 + 1;
          if ( (~v28 & 0x10020) == 0 )
            printk(&unk_2A83D, "_fence_found", 1345, *(unsigned int *)(v19 + 32), a4);
          v21 = 0;
        }
        else
        {
          v21 = -22;
        }
      }
      else
      {
        v21 = -114;
      }
      v23 = v30;
      if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      {
        v29 = 1387;
LABEL_39:
        printk(&unk_202C0, "_hw_fence_lookup_and_create_range", v29, a2, a4);
      }
LABEL_18:
      v24 = 1;
      hw_fence_iterator_next(a1, v33, a7, v18, a9, 1);
      if ( v21 == -114 )
      {
        printk(&unk_2717A, "_hw_fence_lookup_and_create_range", 1393, v23, a4);
        goto LABEL_26;
      }
LABEL_19:
      if ( v21 )
        v25 = 0;
      else
        v25 = v24;
      if ( (v25 & 1) != 0 )
      {
        result = v33[0];
        goto LABEL_27;
      }
    }
    if ( (~msm_hw_fence_debug_level & 0x10020) == 0 )
      printk(&unk_25ADB, "_hw_fence_lookup_and_create_range", 1400, a4, a5);
  }
  else
  {
    printk(&unk_23F02, "_hw_fence_lookup_and_create_range", 1361, v10, a1);
  }
LABEL_26:
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
