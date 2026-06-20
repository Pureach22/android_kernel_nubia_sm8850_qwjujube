__int64 __fastcall wlan_dp_stc_flow_sampling_timer(
        char *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char *v10; // x19
  __int64 v11; // x23
  char v12; // w22
  __int64 v13; // x24
  char v14; // w9
  __int64 v15; // x27
  __int64 v16; // x28
  int v17; // w8
  int v18; // w10
  __int64 v19; // x21
  unsigned int v20; // w20
  unsigned int v21; // w26
  unsigned int v22; // w10
  unsigned int v23; // w9
  int v24; // w11
  char v25; // w9
  int v26; // w8
  __int64 v27; // x20
  unsigned int v28; // w25
  _DWORD *v29; // x21
  __int64 v30; // x25
  unsigned int v31; // w26
  _DWORD *v32; // x21
  __int64 v33; // x20
  char v34; // w9
  char v35; // w15
  _DWORD *v36; // x25
  __int64 v37; // x15
  __int64 v38; // x13
  int v39; // w10
  int v40; // w11
  __int64 v41; // x9
  __int64 v42; // x10
  _DWORD *v43; // x25
  __int64 v44; // x15
  __int64 v45; // x13
  int v46; // w10
  int v47; // w11
  __int64 v48; // x9
  __int64 v49; // x8
  int v50; // w9
  int v51; // w8
  int v52; // w8
  int v53; // w8
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v69; // x9
  __int64 v70; // x0
  __int64 result; // x0
  char v72; // w8
  char *v73; // [xsp+0h] [xbp-80h]
  __int64 v74; // [xsp+8h] [xbp-78h] BYREF
  __int64 v75; // [xsp+10h] [xbp-70h]
  __int64 v76; // [xsp+18h] [xbp-68h]
  __int64 v77; // [xsp+20h] [xbp-60h]
  __int64 v78; // [xsp+28h] [xbp-58h]
  __int64 v79; // [xsp+30h] [xbp-50h]
  __int64 v80; // [xsp+38h] [xbp-48h]
  __int64 v81; // [xsp+40h] [xbp-40h] BYREF
  __int64 v82; // [xsp+48h] [xbp-38h]
  __int64 v83; // [xsp+50h] [xbp-30h]
  __int64 v84; // [xsp+58h] [xbp-28h]
  __int64 v85; // [xsp+60h] [xbp-20h]
  __int64 v86; // [xsp+68h] [xbp-18h]
  __int64 v87; // [xsp+70h] [xbp-10h]
  __int64 v88; // [xsp+78h] [xbp-8h]

  v10 = a1;
  v11 = 0;
  v12 = 0;
  v13 = 128;
  v73 = a1 - 160;
  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    v15 = *((_QWORD *)v10 + 780);
    v86 = 0;
    v87 = 0;
    v84 = 0;
    v85 = 0;
    v82 = 0;
    v83 = 0;
    v16 = v15 + v11;
    v80 = 0;
    v81 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v17 = *(_DWORD *)(v15 + v11 + 32);
    if ( (v17 & 0x100) != 0 )
    {
LABEL_2:
      v14 = 0;
      *(_DWORD *)(v16 + 16) = 6;
      goto LABEL_3;
    }
    v18 = *(_DWORD *)(v16 + 16);
    v14 = 0;
    if ( v18 > 2 )
    {
      if ( v18 != 3 )
      {
        if ( v18 != 4 )
          goto LABEL_3;
        v25 = *(_BYTE *)(v15 + v11 + 43) + 1;
        *(_BYTE *)(v15 + v11 + 43) = v25;
        if ( (v17 & 1) != 0 )
        {
          if ( *(unsigned __int16 *)(v15 + v11 + 48) >= 0x101uLL )
            goto LABEL_101;
          if ( *(_DWORD *)(v15 + v11 + 52) != *(_DWORD *)(*((_QWORD *)v10 + 782)
                                                        + 392LL * *(unsigned __int16 *)(v15 + v11 + 48)
                                                        + 8) )
            goto LABEL_2;
        }
        if ( (v17 & 2) != 0 )
        {
          if ( *(unsigned __int16 *)(v15 + v11 + 50) > 0x100uLL )
            goto LABEL_101;
          if ( *(_DWORD *)(v15 + v11 + 56) != *(_DWORD *)(*((_QWORD *)v10 + 781)
                                                        + 392LL * *(unsigned __int16 *)(v15 + v11 + 50)
                                                        + 8) )
            goto LABEL_2;
        }
        if ( v25 == 50 )
        {
          ((void (__fastcall *)(char *, __int64))wlan_dp_stc_save_burst_samples)(v73, v16 + 16);
          *(_DWORD *)(v16 + 32) |= 0x10u;
          *(_DWORD *)(v16 + 16) = 5;
          a1 = (char *)wlan_dp_stc_stop_flow_tracking(v73, v16 + 16);
          v14 = 0;
          goto LABEL_3;
        }
LABEL_41:
        v14 = 1;
        goto LABEL_3;
      }
      v34 = *(_BYTE *)(v15 + v11 + 43) + 1;
      *(_BYTE *)(v15 + v11 + 43) = v34;
      if ( (v17 & 1) != 0 )
      {
        if ( *(unsigned __int16 *)(v15 + v11 + 48) >= 0x101uLL )
          goto LABEL_101;
        if ( *(_DWORD *)(v15 + v11 + 52) != *(_DWORD *)(*((_QWORD *)v10 + 782)
                                                      + 392LL * *(unsigned __int16 *)(v15 + v11 + 48)
                                                      + 8) )
          goto LABEL_2;
      }
      if ( (v17 & 2) != 0 )
      {
        if ( *(unsigned __int16 *)(v15 + v11 + 50) > 0x100uLL )
          goto LABEL_101;
        if ( *(_DWORD *)(v15 + v11 + 56) != *(_DWORD *)(*((_QWORD *)v10 + 781)
                                                      + 392LL * *(unsigned __int16 *)(v15 + v11 + 50)
                                                      + 8) )
          goto LABEL_2;
      }
      if ( v34 != 18 )
        goto LABEL_41;
      a1 = (char *)((__int64 (__fastcall *)(char *, __int64))wlan_dp_stc_save_burst_samples)(v73, v16 + 16);
      v53 = *(_DWORD *)(v16 + 32);
      *(_DWORD *)(v16 + 32) = v53 | 8;
      if ( (v53 & 0x80) != 0 )
      {
        v52 = 4;
        goto LABEL_79;
      }
      *(_DWORD *)(v16 + 16) = 5;
      a1 = (char *)wlan_dp_stc_stop_flow_tracking(v73, v16 + 16);
      v14 = 1;
    }
    else
    {
      if ( v18 == 1 )
      {
        a1 = (char *)sched_clock(a1, a2);
        v26 = *(_DWORD *)(v16 + 32);
        v27 = v15 + v11;
        *(_QWORD *)(v27 + 72) = a1;
        *(_WORD *)(v27 + 41) = 0;
        if ( (v26 & 1) != 0 )
        {
          v28 = *(unsigned __int16 *)(v27 + 48);
          if ( v28 >= 0x101 )
            goto LABEL_101;
          v29 = (_DWORD *)(*((_QWORD *)v10 + 782) + 392LL * *(unsigned __int16 *)(v27 + 48));
          qdf_mem_set(v29, 0x188u, 0);
          *(_BYTE *)(*(_QWORD *)(*((_QWORD *)v10 - 20) + 2952LL) + 192LL * (unsigned __int8)v28 + 161) = 1;
          v29[2] = *(_DWORD *)(v15 + v11 + 52);
          v29[10] = *(unsigned __int8 *)(v27 + 42) | (*(unsigned __int8 *)(v27 + 41) << 16);
          a1 = (char *)qdf_mem_copy((void *)(v15 + v11 + 80), v29 + 12, 0x38u);
          v26 = *(_DWORD *)(v16 + 32);
        }
        if ( (v26 & 2) != 0 )
        {
          v30 = v15 + v11;
          v31 = *(unsigned __int16 *)(v15 + v11 + 50);
          if ( v31 > 0x100 )
            goto LABEL_101;
          v32 = (_DWORD *)(*((_QWORD *)v10 + 781) + 392LL * *(unsigned __int16 *)(v15 + v11 + 50));
          qdf_mem_set(v32, 0x188u, 0);
          *(_BYTE *)(**(_QWORD **)(*((_QWORD *)v10 - 20) + 1480LL) + 336LL * (unsigned __int8)v31 + 321) = 1;
          v32[2] = *(_DWORD *)(v30 + 56);
          v32[10] = *(unsigned __int8 *)(v27 + 42) | (*(unsigned __int8 *)(v27 + 41) << 16);
          a1 = (char *)qdf_mem_copy((void *)(v30 + 136), v32 + 12, 0x38u);
          v26 = *(_DWORD *)(v16 + 32);
        }
        v33 = v15 + v11;
        if ( (v26 & 1) != 0 )
        {
          a1 = (char *)qdf_mem_copy((void *)(v33 + 1456), (const void *)(v33 + 80), 0x38u);
          v26 = *(_DWORD *)(v16 + 32);
          if ( (v26 & 2) != 0 )
            goto LABEL_49;
LABEL_30:
          if ( (v26 & 1) == 0 )
            goto LABEL_31;
LABEL_50:
          a1 = (char *)qdf_mem_copy((void *)(v15 + v11 + 1672), (const void *)(v33 + 80), 0x38u);
          if ( (*(_DWORD *)(v16 + 32) & 2) != 0 )
LABEL_32:
            a1 = (char *)qdf_mem_copy((void *)(v15 + v11 + 1728), (const void *)(v33 + 136), 0x38u);
        }
        else
        {
          if ( (v26 & 2) == 0 )
            goto LABEL_30;
LABEL_49:
          a1 = (char *)qdf_mem_copy((void *)(v15 + v11 + 1512), (const void *)(v33 + 136), 0x38u);
          v26 = *(_DWORD *)(v16 + 32);
          if ( (v26 & 1) != 0 )
            goto LABEL_50;
LABEL_31:
          if ( (v26 & 2) != 0 )
            goto LABEL_32;
        }
        v14 = 1;
        *(_BYTE *)(v15 + v11 + 43) = 0;
        *(_DWORD *)(v16 + 16) = 2;
        goto LABEL_3;
      }
      if ( v18 != 2 )
        goto LABEL_3;
      v19 = v15 + v11;
      v20 = *(unsigned __int8 *)(v15 + v11 + 41);
      if ( v20 > 4 || (v21 = *(unsigned __int8 *)(v19 + 42), v21 > 2) )
LABEL_101:
        __break(0x5512u);
      if ( v21 == 1 )
      {
        v22 = v20 + 1;
        v23 = 0;
        v24 = 1200;
        *(_BYTE *)(v19 + 41) = v20 + 1;
      }
      else
      {
        v23 = v21 + 1;
        v24 = 600;
        v22 = *(unsigned __int8 *)(v15 + v11 + 41);
      }
      *(_BYTE *)(v19 + 42) = v23;
      v35 = *(_BYTE *)(v15 + v11 + 43);
      *(_DWORD *)(v15 + v11 + 120LL * v21 + 240LL * v20 + 248) = v24;
      *(_BYTE *)(v15 + v11 + 43) = v35 + 1;
      if ( (v17 & 1) != 0 )
      {
        if ( *(unsigned __int16 *)(v15 + v11 + 48) > 0x100uLL )
          goto LABEL_101;
        v36 = (_DWORD *)(*((_QWORD *)v10 + 782) + 392LL * *(unsigned __int16 *)(v15 + v11 + 48));
        if ( *(_DWORD *)(v15 + v11 + 52) != v36[2] )
          goto LABEL_2;
        v36[10] = v23 | (v22 << 16);
        if ( v21 == 1 )
        {
          _X8 = (unsigned __int64 *)(v36 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v60 = __ldxr(_X8);
          while ( __stxr(v60 | 1, _X8) );
        }
        else
        {
          _X8 = (unsigned __int64 *)(v36 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v63 = __ldxr(_X8);
          while ( __stxr(v63 | 2, _X8) );
        }
        a1 = (char *)qdf_mem_copy(&v81, v36 + 12, 0x38u);
        v37 = *(_QWORD *)(v15 + v11 + 120);
        v38 = v15 + v11 + 120LL * v21 + 240LL * v20;
        *(_QWORD *)(v38 + 256) = v81 - *(_QWORD *)(v15 + v11 + 80);
        v39 = *(_DWORD *)(v15 + v11 + 88);
        v40 = v82;
        *(_DWORD *)(v38 + 264) = v82 - v39;
        v41 = (__int64)&v36[12 * v20 + 26 + 6 * v21];
        *(_QWORD *)(v38 + 296) = v86 - v37;
        if ( v21 == 1 && (v40 == v39 || !*(_DWORD *)v41 && v36[12 * v20 + 26]) )
          v41 = (__int64)&v36[12 * v20 + 26];
        v42 = v15 + v11 + 120LL * v21 + 240LL * v20;
        *(_DWORD *)(v42 + 268) = *(_DWORD *)v41;
        *(_DWORD *)(v42 + 272) = *(_DWORD *)(v41 + 4);
        *(_QWORD *)(v42 + 280) = *(_QWORD *)(v41 + 8);
        v17 = *(_DWORD *)(v16 + 32);
        *(_QWORD *)(v42 + 288) = *(_QWORD *)(v41 + 16);
      }
      if ( (v17 & 2) != 0 )
      {
        if ( *(unsigned __int16 *)(v15 + v11 + 50) > 0x100uLL )
          goto LABEL_101;
        v43 = (_DWORD *)(*((_QWORD *)v10 + 781) + 392LL * *(unsigned __int16 *)(v15 + v11 + 50));
        if ( *(_DWORD *)(v15 + v11 + 56) != v43[2] )
          goto LABEL_2;
        v43[10] = *(unsigned __int8 *)(v19 + 42) | (*(unsigned __int8 *)(v19 + 41) << 16);
        if ( v21 == 1 )
        {
          _X8 = (unsigned __int64 *)(v43 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v66 = __ldxr(_X8);
          while ( __stxr(v66 | 1, _X8) );
        }
        else
        {
          _X8 = (unsigned __int64 *)(v43 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v69 = __ldxr(_X8);
          while ( __stxr(v69 | 2, _X8) );
        }
        a1 = (char *)qdf_mem_copy(&v74, v43 + 12, 0x38u);
        v44 = *(_QWORD *)(v15 + v11 + 176);
        v45 = v15 + v11 + 120LL * v21 + 240LL * v20;
        *(_QWORD *)(v45 + 312) = v74 - *(_QWORD *)(v15 + v11 + 136);
        v46 = *(_DWORD *)(v15 + v11 + 144);
        v47 = v75;
        *(_DWORD *)(v45 + 320) = v75 - v46;
        v48 = (__int64)&v43[12 * v20 + 26 + 6 * v21];
        *(_QWORD *)(v45 + 352) = v79 - v44;
        if ( v21 == 1 && (v47 == v46 || !*(_DWORD *)v48 && v43[12 * v20 + 26]) )
          v48 = (__int64)&v43[12 * v20 + 26];
        v49 = v15 + v11 + 120LL * v21 + 240LL * v20;
        *(_DWORD *)(v49 + 324) = *(_DWORD *)v48;
        *(_DWORD *)(v49 + 328) = *(_DWORD *)(v48 + 4);
        *(_QWORD *)(v49 + 336) = *(_QWORD *)(v48 + 8);
        *(_QWORD *)(v49 + 344) = *(_QWORD *)(v48 + 16);
      }
      if ( !*(_BYTE *)(v19 + 42) )
      {
        qdf_mem_copy((void *)(v15 + v11 + 80), &v81, 0x38u);
        a1 = (char *)qdf_mem_copy((void *)(v15 + v11 + 136), &v74, 0x38u);
      }
      if ( *(_BYTE *)(v19 + 41) != 5 )
      {
        v14 = 1;
        goto LABEL_3;
      }
      v50 = *(_DWORD *)(v16 + 32);
      LOBYTE(v51) = v50 | 4;
      *(_DWORD *)(v16 + 32) = v50 | 4;
      if ( (v50 & 0x40) != 0 )
      {
        v52 = 3;
LABEL_79:
        *(_DWORD *)(v16 + 16) = v52;
        v14 = 1;
        goto LABEL_3;
      }
      *(_DWORD *)(v16 + 16) = 5;
      if ( (v50 & 1) != 0 )
      {
        *(_BYTE *)(*(_QWORD *)(*(_QWORD *)v73 + 2952LL) + 192LL * *(unsigned __int8 *)(v15 + v11 + 48) + 161) = 0;
        v51 = *(_DWORD *)(v16 + 32);
      }
      if ( (v51 & 2) == 0 )
        goto LABEL_41;
      v14 = 1;
      *(_BYTE *)(**(_QWORD **)(*(_QWORD *)v73 + 1480LL) + 336LL * *(unsigned __int8 *)(v15 + v11 + 50) + 321) = 0;
    }
LABEL_3:
    --v13;
    v12 |= v14;
    v11 += 1872;
  }
  while ( v13 );
  if ( (v12 & 1) != 0 )
  {
    v70 = ktime_get(a1);
    hrtimer_forward(v10, v70, 600000000);
    result = 1;
  }
  else
  {
    v72 = *(v10 - 12);
    *((_DWORD *)v10 + 22) = 1;
    if ( (v72 & 4) != 0 )
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: STC: Sampling timer stopped!",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_dp_stc_flow_sampling_timer");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
