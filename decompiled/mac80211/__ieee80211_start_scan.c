__int64 __fastcall _ieee80211_start_scan(unsigned __int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x19
  bool v3; // w24
  __int64 result; // x0
  __int64 v7; // x8
  __int64 *i; // x8
  unsigned __int64 v9; // x11
  __int64 v10; // x12
  __int64 v12; // x22
  __int64 *j; // x8
  unsigned __int64 v14; // x11
  __int64 v15; // x12
  _QWORD *v16; // x26
  int v17; // w8
  int v18; // w8
  int v19; // w9
  int v20; // w11
  int v21; // w10
  unsigned __int8 v22; // w12
  _DWORD *v23; // x13
  __int64 v24; // x13
  unsigned __int64 v25; // x23
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x8
  int v29; // w9
  char v30; // w8
  char v31; // w9
  char v32; // w8
  char v33; // w9
  char v34; // w8
  char v35; // w9
  char v36; // w8
  char v37; // w9
  char v38; // w8
  char v39; // w9
  char v40; // w8
  unsigned int v41; // w23
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x2
  int v45; // w8
  unsigned __int64 v51; // x9
  _BYTE v52[8]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v53; // [xsp+28h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1616);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 464) + 184LL) != 0;
  if ( *(_QWORD *)(v2 + 4752) )
    goto LABEL_2;
  if ( *(_WORD *)(a1 + 5800) )
  {
    v7 = *(char *)(a2 + 144);
    if ( (v7 & 0x8000000000000000LL) == 0 && (((unsigned __int64)*(unsigned __int16 *)(a1 + 5802) >> v7) & 1) == 0 )
    {
      result = 4294967274LL;
      goto LABEL_3;
    }
  }
  if ( (ieee80211_is_radar_required(*(_QWORD *)(a1 + 1616)) & 1) != 0 )
  {
    if ( (regulatory_pre_cac_allowed(*(_QWORD *)(v2 + 72)) & 1) == 0 )
    {
LABEL_2:
      result = 4294967280LL;
      goto LABEL_3;
    }
    for ( i = *(__int64 **)(v2 + 4616); i != (__int64 *)(v2 + 4616); i = (__int64 *)*i )
    {
      v9 = 0;
      v10 = 57;
      do
      {
        if ( (!*((_WORD *)i + 744) || ((*((unsigned __int16 *)i + 744) >> v9) & 1) != 0) && (i[v10] & 1) != 0 )
          goto LABEL_2;
        if ( !*((_WORD *)i + 744) )
          break;
        _CF = v9++ >= 0xE;
        v10 += 9;
      }
      while ( !_CF );
    }
  }
  v12 = *(_QWORD *)(a1 + 1616);
  if ( (ieee80211_is_radar_required(v12) & 1) != 0 )
  {
    if ( (regulatory_pre_cac_allowed(*(_QWORD *)(v12 + 72)) & 1) == 0 )
    {
LABEL_30:
      result = 0;
      atomic_store(a2, (unsigned __int64 *)(v2 + 4752));
      atomic_store(a1, (unsigned __int64 *)(v2 + 4968));
      goto LABEL_3;
    }
    for ( j = *(__int64 **)(v12 + 4616); j != (__int64 *)(v12 + 4616); j = (__int64 *)*j )
    {
      v14 = 0;
      v15 = 57;
      do
      {
        if ( (!*((_WORD *)j + 744) || ((*((unsigned __int16 *)j + 744) >> v14) & 1) != 0) && (j[v15] & 1) != 0 )
          goto LABEL_30;
        if ( !*((_WORD *)j + 744) )
          break;
        _CF = v14++ >= 0xE;
        v15 += 9;
      }
      while ( !_CF );
    }
  }
  if ( *(_QWORD *)(v2 + 5264) != v2 + 5264 || *(_DWORD *)(a1 + 4720) == 2 && (*(_BYTE *)(a1 + 2500) & 2) != 0 )
    goto LABEL_30;
  v16 = (_QWORD *)(a2 + 160);
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v3 )
    {
      v18 = *(_DWORD *)(v2 + 4808) + *(_DWORD *)(a2 + 24);
      *(_DWORD *)(v2 + 4812) = v18;
      if ( (*(_QWORD *)(v2 + 96) & 0x10000000) != 0 )
      {
        v19 = *(_DWORD *)(a2 + 12);
        if ( v19 )
        {
          v20 = 0;
          v21 = 0;
          v22 = 0;
          do
          {
            v23 = (_DWORD *)v16[v20++];
            v24 = 1LL << *v23;
            if ( (v22 & (unsigned __int8)v24) != 0 )
              LOBYTE(v24) = 0;
            else
              ++v21;
            v22 |= v24;
          }
          while ( v19 != v20 );
        }
        else
        {
          v21 = 0;
        }
        *(_DWORD *)(v2 + 4812) = v21 * v18;
      }
      v25 = *(int *)(v2 + 4812) + 8LL * *(unsigned int *)(a2 + 12) + 272;
      v26 = _kmalloc_noprof(v25, 3264);
      *(_QWORD *)(v2 + 4760) = v26;
      if ( !v26 )
      {
        result = 4294967284LL;
        goto LABEL_3;
      }
      if ( v25 < 0x70 || (v25 & 0xFFFFFFFFFFFFFFF8LL) == 0x70 )
      {
        __break(1u);
        goto LABEL_78;
      }
      *(_QWORD *)(v26 + 112) = *(_QWORD *)a2;
      *(_DWORD *)(*(_QWORD *)(v2 + 4760) + 120LL) = *(_DWORD *)(a2 + 8);
      v27 = *(unsigned int *)(a2 + 12);
      *(_DWORD *)(*(_QWORD *)(v2 + 4760) + 124LL) = v27;
      *(_QWORD *)(*(_QWORD *)(v2 + 4760) + 128LL) = *(_QWORD *)(v2 + 4760) + 8 * v27 + 272;
      *(_DWORD *)(*(_QWORD *)(v2 + 4760) + 148LL) = *(_DWORD *)(a2 + 36);
      v28 = *(_QWORD *)(v2 + 4760);
      *(_WORD *)(v28 + 200) = -1;
      *(_DWORD *)(v28 + 196) = -1;
      *(_WORD *)(*(_QWORD *)(v2 + 4760) + 144LL) = *(_WORD *)(a2 + 32);
      *(_BYTE *)(*(_QWORD *)(v2 + 4760) + 146LL) = *(_BYTE *)(a2 + 34);
      *(_BYTE *)(*(_QWORD *)(v2 + 4760) + 256LL) = *(_BYTE *)(a2 + 144);
      *(_DWORD *)(v2 + 4800) = 0;
      *(_DWORD *)(*(_QWORD *)(v2 + 4760) + 244LL) = *(_DWORD *)(a2 + 132);
      *(_QWORD *)(*(_QWORD *)(v2 + 4760) + 248LL) = *(_QWORD *)(a2 + 136);
      *(_BYTE *)(*(_QWORD *)(v2 + 4760) + 242LL) = *(_BYTE *)(a2 + 130);
    }
    atomic_store(a2, (unsigned __int64 *)(v2 + 4752));
    atomic_store(a1, (unsigned __int64 *)(v2 + 4968));
    if ( (*(_BYTE *)(a2 + 36) & 8) != 0 )
    {
      get_random_bytes(v2 + 4872, 6);
      v30 = *(_BYTE *)(v2 + 4872) & ~*(_BYTE *)(a2 + 78);
      *(_BYTE *)(v2 + 4872) = v30;
      v31 = *(_BYTE *)(v2 + 4873);
      *(_BYTE *)(v2 + 4872) = *(_BYTE *)(a2 + 78) & *(_BYTE *)(a2 + 72) | v30;
      v32 = v31 & ~*(_BYTE *)(a2 + 79);
      *(_BYTE *)(v2 + 4873) = v32;
      v33 = *(_BYTE *)(v2 + 4874);
      *(_BYTE *)(v2 + 4873) = *(_BYTE *)(a2 + 79) & *(_BYTE *)(a2 + 73) | v32;
      v34 = v33 & ~*(_BYTE *)(a2 + 80);
      *(_BYTE *)(v2 + 4874) = v34;
      v35 = *(_BYTE *)(v2 + 4875);
      *(_BYTE *)(v2 + 4874) = *(_BYTE *)(a2 + 80) & *(_BYTE *)(a2 + 74) | v34;
      v36 = v35 & ~*(_BYTE *)(a2 + 81);
      *(_BYTE *)(v2 + 4875) = v36;
      v37 = *(_BYTE *)(v2 + 4876);
      *(_BYTE *)(v2 + 4875) = *(_BYTE *)(a2 + 81) & *(_BYTE *)(a2 + 75) | v36;
      v38 = v37 & ~*(_BYTE *)(a2 + 82);
      *(_BYTE *)(v2 + 4876) = v38;
      v39 = *(_BYTE *)(v2 + 4877);
      *(_BYTE *)(v2 + 4876) = *(_BYTE *)(a2 + 82) & *(_BYTE *)(a2 + 76) | v38;
      v40 = v39 & ~*(_BYTE *)(a2 + 83);
      *(_BYTE *)(v2 + 4877) = v40;
      *(_BYTE *)(v2 + 4877) = *(_BYTE *)(a2 + 83) & *(_BYTE *)(a2 + 77) | v40;
      if ( v3 )
      {
LABEL_59:
        *(_QWORD *)(v2 + 4696) |= 2uLL;
        ieee80211_recalc_idle(v2);
        if ( (ieee80211_prep_hw_scan(a1) & 1) == 0 )
          __break(0x800u);
        result = drv_hw_scan(v2, a1, *(_QWORD *)(v2 + 4760));
        if ( !(_DWORD)result )
          goto LABEL_3;
        goto LABEL_62;
      }
    }
    else
    {
      v29 = *(_DWORD *)(a1 + 5842);
      *(_WORD *)(v2 + 4876) = *(_WORD *)(a1 + 5846);
      *(_DWORD *)(v2 + 4872) = v29;
      if ( v3 )
        goto LABEL_59;
    }
    if ( *(_DWORD *)(a2 + 12) == 1 && *v16 == *(_QWORD *)(v2 + 24) )
      break;
    *(_QWORD *)(v2 + 4696) |= 1uLL;
    ieee80211_recalc_idle(v2);
    if ( (*(_BYTE *)(v2 + 1400) & 1) != 0 )
    {
      drv_sw_scan_start(v2, a1, v2 + 4872);
      v42 = jiffies;
      *(_DWORD *)(v2 + 4888) = 0;
      *(_DWORD *)(v2 + 4804) = 0;
      *(_QWORD *)(v2 + 4880) = v42;
      ieee80211_offchannel_stop_vifs(v2);
      ieee80211_flush_queues(v2, 0, 0);
      ieee80211_configure_filter(v2);
      ieee80211_hw_conf_chan(v2);
      v43 = *(_QWORD *)(v2 + 72);
      v44 = 0;
      goto LABEL_76;
    }
    LODWORD(result) = -95;
LABEL_62:
    v41 = result;
    kfree(*(_QWORD *)(v2 + 4760));
    *(_QWORD *)(v2 + 4760) = 0;
    *(_QWORD *)(v2 + 4696) = 0;
    ieee80211_recalc_idle(v2);
    result = v41;
    *(_QWORD *)(v2 + 4752) = 0;
    *(_QWORD *)(v2 + 4968) = 0;
    if ( v41 != 1 || !v3 )
      goto LABEL_3;
    v17 = *(_DWORD *)(a1 + 4720);
    if ( *(_BYTE *)(a1 + 5848) == 1 )
    {
      if ( v17 == 2 )
      {
        v17 = 8;
      }
      else if ( v17 == 3 )
      {
        result = 4294967201LL;
        goto LABEL_3;
      }
    }
    v3 = 0;
    result = 4294967201LL;
    if ( v17 == 9 )
      goto LABEL_3;
  }
  *(_QWORD *)(v2 + 4696) |= 4uLL;
  ieee80211_recalc_idle(v2);
  drv_sw_scan_start(v2, a1, v2 + 4872);
  ieee80211_configure_filter(v2);
  ieee80211_hw_conf_chan(v2);
  v45 = *(_DWORD *)(a2 + 8);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 160) + 12LL) & 0xA) == 0 )
  {
    if ( v45 )
    {
      ieee80211_scan_state_send_probe(v2, v52);
      v44 = 7;
      goto LABEL_75;
    }
    goto LABEL_74;
  }
  if ( !v45 )
  {
LABEL_74:
    v44 = 27;
    goto LABEL_75;
  }
LABEL_78:
  v44 = 27;
  _X8 = (unsigned __int64 *)(v2 + 4696);
  __asm { PRFM            #0x11, [X8] }
  do
    v51 = __ldxr(_X8);
  while ( __stxr(v51 | 0x40, _X8) );
LABEL_75:
  v43 = *(_QWORD *)(v2 + 72);
LABEL_76:
  wiphy_delayed_work_queue(v43, v2 + 4896, v44);
  result = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
