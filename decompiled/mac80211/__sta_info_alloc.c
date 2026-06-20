__int64 __fastcall _sta_info_alloc(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, unsigned int a5)
{
  unsigned __int64 StatusReg; // x27
  __int64 v6; // x28
  __int64 v7; // x26
  unsigned __int64 v13; // x20
  __int64 v14; // x19
  __int64 v15; // x0
  _DWORD *v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x10
  __int16 v19; // w11
  __int16 v20; // w11
  __int16 v21; // w11
  __int16 v22; // w9
  __int16 v23; // w8
  _QWORD *inited; // x0
  int v25; // w8
  __int64 seconds; // x0
  signed int v27; // w24
  __int64 v28; // x23
  _QWORD *v29; // x8
  __int64 v30; // x0
  _DWORD *v31; // x8
  __int64 v32; // x0
  int v33; // w10
  __int64 v34; // x8
  __int64 v35; // x11
  int v36; // w12
  __int64 v37; // x17
  __int64 v38; // x13
  __int64 v39; // x14
  __int64 v40; // x16
  unsigned __int64 v41; // x15
  bool v44; // w16

  v7 = *(_QWORD *)(a1 + 1616);
  v13 = *(int *)(v7 + 116) + 3256LL;
  v14 = _kmalloc_noprof(v13, a5 | 0x100);
  if ( v14 )
  {
    while ( 1 )
    {
      if ( v13 < 0x48 )
        goto LABEL_143;
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 72) = v7;
      if ( v13 < 0x50 || (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x50 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 80) = a1;
      if ( (*(_QWORD *)(v7 + 96) & 0x400000000LL) != 0 )
      {
        v15 = pcpu_alloc_noprof(200, 8, 0, a5);
        if ( v13 < 0x6D0 || (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x6D0 )
          goto LABEL_143;
        *(_QWORD *)(v14 + 1744) = v15;
        if ( !v15 )
          goto LABEL_137;
      }
      if ( v13 < 0x6E0 )
        goto LABEL_143;
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x6E0 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 1760) = jiffies;
      if ( v13 < 0x910 || (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x910 )
        goto LABEL_143;
      v16 = (_DWORD *)(v14 + 1640);
      v17 = v14 + 2880;
      *(_QWORD *)(v14 + 2320) = 0;
      *(_QWORD *)(v14 + 1952) = 0;
      *(_QWORD *)(v14 + 1960) = 0;
      *(_QWORD *)(v14 + 1968) = 0;
      *(_QWORD *)(v14 + 1976) = 0;
      *(_QWORD *)(v14 + 1984) = 0;
      if ( (a3 & 0x80000000) != 0 )
      {
        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x688 )
          goto LABEL_143;
        *(_QWORD *)(v14 + 1672) = v14;
        *(_BYTE *)(v14 + 1646) = 0;
        if ( v13 < 0xA00 )
          goto LABEL_143;
        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xA00 )
          goto LABEL_143;
        *(_QWORD *)(v14 + 2560) = v17;
        if ( v13 < 0xB40 )
          goto LABEL_143;
        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xB40 )
          goto LABEL_143;
        *(_QWORD *)(v14 + 2880) = v14 + 2688;
        if ( v13 < 0xB4F )
          goto LABEL_143;
        *(_BYTE *)(v14 + 2894) = 0;
        atomic_store((unsigned __int64)v16, (unsigned __int64 *)(v14 + 2568));
        atomic_store(v17, (unsigned __int64 *)(v14 + 3128));
        if ( v13 == 2895 )
          goto LABEL_143;
        if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xB50 )
          goto LABEL_143;
        *(_DWORD *)(v14 + 2896) = 1;
        if ( v13 < 0xC04 || (v13 & 0xFFFFFFFFFFFFFFFELL) == 0xC04 )
          goto LABEL_143;
        *(_WORD *)(v14 + 3076) = 4095;
        goto LABEL_39;
      }
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x688 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 1672) = v14;
      *(_BYTE *)(v14 + 1646) = a3;
      if ( v13 < 0xA00 )
        goto LABEL_143;
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xA00 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 2560) = v17;
      if ( v13 < 0xB40 )
        goto LABEL_143;
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xB40 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 2880) = v14 + 2688;
      if ( v13 < 0xB4F )
        goto LABEL_143;
      *(_BYTE *)(v14 + 2894) = a3;
      if ( a3 < 0x10 )
        break;
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_sta_info_alloc__alloc_tag;
      v13 = *(int *)(v7 + 116) + 3256LL;
      v14 = _kmalloc_noprof(v13, a5 | 0x100);
      *(_QWORD *)(StatusReg + 80) = v6;
      if ( !v14 )
        return v14;
    }
    v18 = v14 + 8LL * a3;
    atomic_store((unsigned __int64)v16, (unsigned __int64 *)(v18 + 2568));
    atomic_store(v17, (unsigned __int64 *)(v18 + 3128));
    if ( v13 == 2895 )
      goto LABEL_143;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xB50 )
      goto LABEL_143;
    *(_DWORD *)(v14 + 2896) = 1;
    if ( v13 < 0xC04 )
      goto LABEL_143;
    if ( (v13 & 0xFFFFFFFFFFFFFFFELL) == 0xC04 )
      goto LABEL_143;
    *(_WORD *)(v14 + 3076) = 4095;
    if ( (v13 & 0xFFFFFFFFFFFFFFFELL) == 0xB38 )
      goto LABEL_143;
    *(_WORD *)(v14 + 2872) = 1LL << a3;
LABEL_39:
    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xAA0 )
      goto LABEL_143;
    *(_QWORD *)(v14 + 2720) = v14 + 3074;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x94 )
      goto LABEL_143;
    *(_DWORD *)(v14 + 148) = 0;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xE0 )
      goto LABEL_143;
    *(_DWORD *)(v14 + 224) = 0;
    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xA8 )
      goto LABEL_143;
    *(_QWORD *)(v14 + 168) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v14 + 176) = v14 + 176;
    *(_QWORD *)(v14 + 184) = v14 + 176;
    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0xC0 )
      goto LABEL_143;
    *(_QWORD *)(v14 + 192) = sta_deliver_ps_frames;
    *(_QWORD *)(v14 + 880) = v14 + 880;
    *(_QWORD *)(v14 + 888) = v14 + 880;
    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x380 )
      goto LABEL_143;
    *(_QWORD *)(v14 + 896) = ieee80211_ba_session_work;
    v19 = *(_WORD *)(a2 + 4);
    *(_DWORD *)(v14 + 64) = *(_DWORD *)a2;
    *(_WORD *)(v14 + 68) = v19;
    v20 = *(_WORD *)(a2 + 4);
    *(_DWORD *)(v14 + 2688) = *(_DWORD *)a2;
    *(_WORD *)(v14 + 2692) = v20;
    v21 = *(_WORD *)(a4 + 4);
    *v16 = *(_DWORD *)a4;
    *(_WORD *)(v14 + 1644) = v21;
    v22 = *(_WORD *)(a4 + 4);
    *(_DWORD *)(v14 + 2888) = *(_DWORD *)a4;
    *(_WORD *)(v14 + 2892) = v22;
    if ( (v13 & 0xFFFFFFFFFFFFFFFELL) == 0xA88 )
      goto LABEL_143;
    v23 = *(_WORD *)(v7 + 136);
    *(_BYTE *)(v14 + 120) = 2;
    *(_WORD *)(v14 + 2696) = v23;
    inited = ieee80211_init_frag_cache((_QWORD *)(v14 + 1368));
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xD0 )
      goto LABEL_143;
    v25 = *(_DWORD *)(a1 + 4720);
    *(_DWORD *)(v14 + 208) = 1;
    if ( v25 == 7 )
      *(_BYTE *)(v14 + 1333) = -1;
    *(_BYTE *)(v14 + 1332) = -1;
    seconds = ktime_get_seconds(inited);
    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x1C0 )
      goto LABEL_143;
    *(_QWORD *)(v14 + 448) = seconds;
    v27 = ((*(_DWORD *)(v7 + 124) + 7) & 0xFFFFFFF8) + 256;
    if ( !is_mul_ok(v27, 0x11u) )
      goto LABEL_137;
    v28 = _kmalloc_noprof(17LL * v27, a5 | 0x100);
    if ( !v28 )
      goto LABEL_137;
    ieee80211_txq_init(a1, v14, v28, 0);
    ieee80211_txq_init(a1, v14, v28 + v27, 1);
    StatusReg = (unsigned int)(2 * v27);
    ieee80211_txq_init(a1, v14, v28 + (int)StatusReg, 2);
    v6 = (unsigned int)(3 * v27);
    ieee80211_txq_init(a1, v14, v28 + (int)v6, 3);
    ieee80211_txq_init(a1, v14, v28 + 4 * v27, 4);
    ieee80211_txq_init(a1, v14, v28 + 5 * v27, 5);
    ieee80211_txq_init(a1, v14, v28 + 6 * v27, 6);
    ieee80211_txq_init(a1, v14, v28 + 7 * v27, 7);
    ieee80211_txq_init(a1, v14, v28 + 8 * v27, 8);
    ieee80211_txq_init(a1, v14, v28 + 9 * v27, 9);
    ieee80211_txq_init(a1, v14, v28 + 10 * v27, 10);
    ieee80211_txq_init(a1, v14, v28 + 11 * v27, 11);
    ieee80211_txq_init(a1, v14, v28 + 12 * v27, 12);
    ieee80211_txq_init(a1, v14, v28 + 13 * v27, 13);
    ieee80211_txq_init(a1, v14, v28 + 14 * v27, 14);
    ieee80211_txq_init(a1, v14, v28 + 15 * v27, 15);
    ieee80211_txq_init(a1, v14, v28 + 16 * v27, 16);
    if ( (*(_QWORD *)(v7 + 96) & 1) == 0 )
    {
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x80 )
        goto LABEL_143;
      v29 = *(_QWORD **)(v7 + 2536);
      *(_QWORD *)(v14 + 128) = v29;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x90 )
        goto LABEL_143;
      *(_DWORD *)(v14 + 144) = 0;
      v30 = v29[1];
      v31 = *(_DWORD **)(*v29 + 40LL);
      if ( *(v31 - 1) != -1542417076 )
        __break(0x8228u);
      v32 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v31)(v30, v14 + 2688, a5);
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x88 )
        goto LABEL_143;
      *(_QWORD *)(v14 + 136) = v32;
      if ( !v32 )
      {
        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0xAB0 )
        {
          kfree(*(_QWORD *)(v14 + 2736) - 232LL);
          goto LABEL_137;
        }
        goto LABEL_143;
      }
    }
    if ( (v13 & 0xFFFFFFFFFFFFFFFELL) != 0x2B0 )
    {
      *(_WORD *)(v14 + 688) = 256;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0xFC )
      {
        *(_DWORD *)(v14 + 252) = 0;
        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0xE8 )
        {
          *(_QWORD *)(v14 + 232) = v14 + 232;
          if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0xF0 )
          {
            *(_QWORD *)(v14 + 240) = v14 + 232;
            if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0xF8 )
            {
              *(_DWORD *)(v14 + 248) = 0;
              if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x15C )
              {
                *(_DWORD *)(v14 + 348) = 0;
                if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x148 )
                {
                  *(_QWORD *)(v14 + 328) = v14 + 328;
                  if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x150 )
                  {
                    *(_QWORD *)(v14 + 336) = v14 + 328;
                    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x158 )
                    {
                      *(_DWORD *)(v14 + 344) = 0;
                      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x228 )
                      {
                        *(_QWORD *)(v14 + 552) = 256;
                        if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x230 )
                        {
                          *(_DWORD *)(v14 + 560) = *(_DWORD *)(v7 + 408);
                          if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x234 )
                          {
                            *(_DWORD *)(v14 + 564) = *(_DWORD *)(v7 + 424);
                            if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x114 )
                            {
                              *(_DWORD *)(v14 + 276) = 0;
                              if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x100 )
                              {
                                *(_QWORD *)(v14 + 256) = v14 + 256;
                                if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x108 )
                                {
                                  *(_QWORD *)(v14 + 264) = v14 + 256;
                                  if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x110 )
                                  {
                                    *(_DWORD *)(v14 + 272) = 0;
                                    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x174 )
                                    {
                                      *(_DWORD *)(v14 + 372) = 0;
                                      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x160 )
                                      {
                                        *(_QWORD *)(v14 + 352) = v14 + 352;
                                        if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x168 )
                                        {
                                          *(_QWORD *)(v14 + 360) = v14 + 352;
                                          if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x170 )
                                          {
                                            *(_DWORD *)(v14 + 368) = 0;
                                            if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x250 )
                                            {
                                              *(_QWORD *)(v14 + 592) = 256;
                                              if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x258 )
                                              {
                                                *(_DWORD *)(v14 + 600) = *(_DWORD *)(v7 + 412);
                                                if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x25C )
                                                {
                                                  *(_DWORD *)(v14 + 604) = *(_DWORD *)(v7 + 428);
                                                  if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x12C )
                                                  {
                                                    *(_DWORD *)(v14 + 300) = 0;
                                                    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x118 )
                                                    {
                                                      *(_QWORD *)(v14 + 280) = v14 + 280;
                                                      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x120 )
                                                      {
                                                        *(_QWORD *)(v14 + 288) = v14 + 280;
                                                        if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x128 )
                                                        {
                                                          *(_DWORD *)(v14 + 296) = 0;
                                                          if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x18C )
                                                          {
                                                            *(_DWORD *)(v14 + 396) = 0;
                                                            if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x178 )
                                                            {
                                                              *(_QWORD *)(v14 + 376) = v14 + 376;
                                                              if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x180 )
                                                              {
                                                                *(_QWORD *)(v14 + 384) = v14 + 376;
                                                                if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x188 )
                                                                {
                                                                  *(_DWORD *)(v14 + 392) = 0;
                                                                  if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x278 )
                                                                  {
                                                                    *(_QWORD *)(v14 + 632) = 256;
                                                                    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x280 )
                                                                    {
                                                                      *(_DWORD *)(v14 + 640) = *(_DWORD *)(v7 + 416);
                                                                      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x284 )
                                                                      {
                                                                        *(_DWORD *)(v14 + 644) = *(_DWORD *)(v7 + 432);
                                                                        if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x144 )
                                                                        {
                                                                          *(_DWORD *)(v14 + 324) = 0;
                                                                          if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x130 )
                                                                          {
                                                                            *(_QWORD *)(v14 + 304) = v14 + 304;
                                                                            if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x138 )
                                                                            {
                                                                              *(_QWORD *)(v14 + 312) = v14 + 304;
                                                                              if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x140 )
                                                                              {
                                                                                *(_DWORD *)(v14 + 320) = 0;
                                                                                if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x1A4 )
                                                                                {
                                                                                  *(_DWORD *)(v14 + 420) = 0;
                                                                                  if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x190 )
                                                                                  {
                                                                                    *(_QWORD *)(v14 + 400) = v14 + 400;
                                                                                    if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) != 0x198 )
                                                                                    {
                                                                                      *(_QWORD *)(v14 + 408) = v14 + 400;
                                                                                      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x1A0 )
                                                                                      {
                                                                                        *(_DWORD *)(v14 + 416) = 0;
                                                                                        if ( (v13 & 0xFFFFFFFFFFFFFFFELL) != 0x2B0
                                                                                          && (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x2A0 )
                                                                                        {
                                                                                          *(_QWORD *)(v14 + 672) = *(unsigned __int16 *)(v14 + 688);
                                                                                          if ( (v13
                                                                                              & 0xFFFFFFFFFFFFFFFCLL) != 0x2A8 )
                                                                                          {
                                                                                            *(_DWORD *)(v14 + 680) = *(_DWORD *)(v7 + 420);
                                                                                            if ( (v13
                                                                                                & 0xFFFFFFFFFFFFFFFCLL) != 0x2AC )
                                                                                            {
                                                                                              v33 = *(_DWORD *)(v7 + 436);
                                                                                              v34 = 0;
                                                                                              *(_QWORD *)(v14 + 456) = -1;
                                                                                              *(_QWORD *)(v14 + 464) = -1;
                                                                                              *(_DWORD *)(v14 + 684) = v33;
                                                                                              *(_QWORD *)(v14 + 472) = -1;
                                                                                              *(_QWORD *)(v14 + 480) = -1;
                                                                                              v35 = *(_QWORD *)(v7 + 72);
                                                                                              while ( !*(_QWORD *)(v35 + 8 * v34 + 328) )
                                                                                              {
LABEL_106:
                                                                                                if ( ++v34 == 6 )
                                                                                                {
                                                                                                  if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x524 )
                                                                                                  {
                                                                                                    *(_DWORD *)(v14 + 1316) = 0x7FFFFFFF;
                                                                                                    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x520 )
                                                                                                    {
                                                                                                      *(_DWORD *)(v14 + 1312) = 19531;
                                                                                                      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) != 0x528 )
                                                                                                      {
                                                                                                        *(_BYTE *)(v14 + 1330) = 0;
                                                                                                        *(_WORD *)(v14 + 1328) = 1;
                                                                                                        *(_DWORD *)(v14 + 1320) = 97656;
                                                                                                        return v14;
                                                                                                      }
                                                                                                    }
                                                                                                  }
                                                                                                  goto LABEL_143;
                                                                                                }
                                                                                              }
                                                                                              v36 = 0;
                                                                                              if ( (int)v34 > 1 )
                                                                                              {
                                                                                                if ( (_DWORD)v34 == 2 )
                                                                                                {
                                                                                                  __break(0x800u);
                                                                                                  v35 = *(_QWORD *)(v7 + 72);
                                                                                                  v36 = 0;
                                                                                                  goto LABEL_116;
                                                                                                }
                                                                                                if ( (_DWORD)v34 != 5 )
                                                                                                  goto LABEL_116;
                                                                                              }
                                                                                              else if ( (_DWORD)v34 )
                                                                                              {
                                                                                                if ( (_DWORD)v34 == 1 )
                                                                                                  v36 = 2;
LABEL_116:
                                                                                                v37 = *(_QWORD *)(v35 + 8 * v34 + 328);
                                                                                                if ( *(int *)(v37 + 24) >= 1 )
                                                                                                {
                                                                                                  v38 = 0;
                                                                                                  v39 = 0;
                                                                                                  v40 = 4 * v34 + 2900;
                                                                                                  v41 = v13 - v40;
                                                                                                  v44 = v13 < v40 || v41 < 4 || v40 < 0;
                                                                                                  while ( 1 )
                                                                                                  {
                                                                                                    if ( (*(_DWORD *)(*(_QWORD *)(v37 + 8) + v38) & v36) != 0 )
                                                                                                    {
                                                                                                      if ( v44 || v41 < 4 )
                                                                                                        goto LABEL_143;
                                                                                                      *(_DWORD *)(v14 + 2900 + 4 * v34) |= 1LL << v39;
                                                                                                      v35 = *(_QWORD *)(v7 + 72);
                                                                                                    }
                                                                                                    ++v39;
                                                                                                    v38 += 12;
                                                                                                    v37 = *(_QWORD *)(v35 + 8 * v34 + 328);
                                                                                                    if ( v39 >= *(int *)(v37 + 24) )
                                                                                                      goto LABEL_106;
                                                                                                  }
                                                                                                }
                                                                                                goto LABEL_106;
                                                                                              }
                                                                                              v36 = 12;
                                                                                              goto LABEL_116;
                                                                                            }
                                                                                          }
                                                                                        }
                                                                                      }
                                                                                    }
                                                                                  }
                                                                                }
                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    do
    {
LABEL_143:
      __break(1u);
      *(_QWORD *)(StatusReg + 80) = v6;
LABEL_137:
      ;
    }
    while ( v13 < 0x6D0 || (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x6D0 );
    free_percpu(*(_QWORD *)(v14 + 1744));
    kfree(v14);
    return 0;
  }
  return v14;
}
