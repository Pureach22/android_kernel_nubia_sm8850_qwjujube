__int64 __fastcall wlan_dp_stc_flow_sampling_timer(
        char *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  char *v13; // x19
  __int64 v14; // x23
  char v15; // w22
  __int64 v16; // x24
  char v17; // w9
  __int64 v18; // x27
  __int64 v19; // x28
  int v20; // w8
  int v21; // w10
  __int64 v22; // x21
  unsigned int v23; // w20
  unsigned int v24; // w26
  unsigned int v25; // w10
  unsigned int v26; // w9
  int v27; // w11
  char v28; // w9
  int v29; // w8
  __int64 v30; // x20
  unsigned int v31; // w25
  _DWORD *v32; // x21
  __int64 v33; // x25
  unsigned int v34; // w26
  _DWORD *v35; // x21
  __int64 v36; // x20
  char v37; // w9
  char v38; // w15
  _DWORD *v39; // x25
  __int64 v40; // x15
  __int64 v41; // x13
  int v42; // w10
  int v43; // w11
  __int64 v44; // x9
  __int64 v45; // x10
  _DWORD *v46; // x25
  __int64 v47; // x15
  __int64 v48; // x13
  int v49; // w10
  int v50; // w11
  __int64 v51; // x9
  __int64 v52; // x8
  int v53; // w9
  int v54; // w8
  int v55; // w8
  int v56; // w8
  unsigned __int64 v63; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v72; // x9
  __int64 v73; // x0
  __int64 result; // x0
  char v75; // w8
  char *v76; // [xsp+0h] [xbp-80h]
  __int64 v77; // [xsp+8h] [xbp-78h] BYREF
  __int64 v78; // [xsp+10h] [xbp-70h]
  __int64 v79; // [xsp+18h] [xbp-68h]
  __int64 v80; // [xsp+20h] [xbp-60h]
  __int64 v81; // [xsp+28h] [xbp-58h]
  __int64 v82; // [xsp+30h] [xbp-50h]
  __int64 v83; // [xsp+38h] [xbp-48h]
  __int64 v84; // [xsp+40h] [xbp-40h] BYREF
  __int64 v85; // [xsp+48h] [xbp-38h]
  __int64 v86; // [xsp+50h] [xbp-30h]
  __int64 v87; // [xsp+58h] [xbp-28h]
  __int64 v88; // [xsp+60h] [xbp-20h]
  __int64 v89; // [xsp+68h] [xbp-18h]
  __int64 v90; // [xsp+70h] [xbp-10h]
  __int64 v91; // [xsp+78h] [xbp-8h]

  v13 = a1;
  v14 = 0;
  v15 = 0;
  v16 = 128;
  v76 = a1 - 160;
  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  do
  {
    v18 = *((_QWORD *)v13 + 780);
    v89 = 0;
    v90 = 0;
    v87 = 0;
    v88 = 0;
    v85 = 0;
    v86 = 0;
    v19 = v18 + v14;
    v83 = 0;
    v84 = 0;
    v81 = 0;
    v82 = 0;
    v79 = 0;
    v80 = 0;
    v77 = 0;
    v78 = 0;
    v20 = *(_DWORD *)(v18 + v14 + 32);
    if ( (v20 & 0x100) != 0 )
    {
LABEL_2:
      v17 = 0;
      *(_DWORD *)(v19 + 16) = 6;
      goto LABEL_3;
    }
    v21 = *(_DWORD *)(v19 + 16);
    v17 = 0;
    if ( v21 > 2 )
    {
      if ( v21 != 3 )
      {
        if ( v21 != 4 )
          goto LABEL_3;
        v28 = *(_BYTE *)(v18 + v14 + 43) + 1;
        *(_BYTE *)(v18 + v14 + 43) = v28;
        if ( (v20 & 1) != 0 )
        {
          if ( *(unsigned __int16 *)(v18 + v14 + 48) >= 0x101uLL )
            goto LABEL_101;
          if ( *(_DWORD *)(v18 + v14 + 52) != *(_DWORD *)(*((_QWORD *)v13 + 782)
                                                        + 392LL * *(unsigned __int16 *)(v18 + v14 + 48)
                                                        + 8) )
            goto LABEL_2;
        }
        if ( (v20 & 2) != 0 )
        {
          if ( *(unsigned __int16 *)(v18 + v14 + 50) > 0x100uLL )
            goto LABEL_101;
          if ( *(_DWORD *)(v18 + v14 + 56) != *(_DWORD *)(*((_QWORD *)v13 + 781)
                                                        + 392LL * *(unsigned __int16 *)(v18 + v14 + 50)
                                                        + 8) )
            goto LABEL_2;
        }
        if ( v28 == 50 )
        {
          ((void (__fastcall *)(char *, __int64))wlan_dp_stc_save_burst_samples)(v76, v19 + 16);
          *(_DWORD *)(v19 + 32) |= 0x10u;
          *(_DWORD *)(v19 + 16) = 5;
          a1 = (char *)wlan_dp_stc_stop_flow_tracking(v76, v19 + 16);
          v17 = 0;
          goto LABEL_3;
        }
LABEL_41:
        v17 = 1;
        goto LABEL_3;
      }
      v37 = *(_BYTE *)(v18 + v14 + 43) + 1;
      *(_BYTE *)(v18 + v14 + 43) = v37;
      if ( (v20 & 1) != 0 )
      {
        if ( *(unsigned __int16 *)(v18 + v14 + 48) >= 0x101uLL )
          goto LABEL_101;
        if ( *(_DWORD *)(v18 + v14 + 52) != *(_DWORD *)(*((_QWORD *)v13 + 782)
                                                      + 392LL * *(unsigned __int16 *)(v18 + v14 + 48)
                                                      + 8) )
          goto LABEL_2;
      }
      if ( (v20 & 2) != 0 )
      {
        if ( *(unsigned __int16 *)(v18 + v14 + 50) > 0x100uLL )
          goto LABEL_101;
        if ( *(_DWORD *)(v18 + v14 + 56) != *(_DWORD *)(*((_QWORD *)v13 + 781)
                                                      + 392LL * *(unsigned __int16 *)(v18 + v14 + 50)
                                                      + 8) )
          goto LABEL_2;
      }
      if ( v37 != 18 )
        goto LABEL_41;
      a1 = (char *)((__int64 (__fastcall *)(char *, __int64))wlan_dp_stc_save_burst_samples)(v76, v19 + 16);
      v56 = *(_DWORD *)(v19 + 32);
      *(_DWORD *)(v19 + 32) = v56 | 8;
      if ( (v56 & 0x80) != 0 )
      {
        v55 = 4;
        goto LABEL_79;
      }
      *(_DWORD *)(v19 + 16) = 5;
      a1 = (char *)wlan_dp_stc_stop_flow_tracking(v76, v19 + 16);
      v17 = 1;
    }
    else
    {
      if ( v21 == 1 )
      {
        a1 = (char *)sched_clock(a1, a2);
        v29 = *(_DWORD *)(v19 + 32);
        v30 = v18 + v14;
        *(_QWORD *)(v30 + 72) = a1;
        *(_WORD *)(v30 + 41) = 0;
        if ( (v29 & 1) != 0 )
        {
          v31 = *(unsigned __int16 *)(v30 + 48);
          if ( v31 >= 0x101 )
            goto LABEL_101;
          v32 = (_DWORD *)(*((_QWORD *)v13 + 782) + 392LL * *(unsigned __int16 *)(v30 + 48));
          qdf_mem_set(v32, 0x188u, 0);
          *(_BYTE *)(*(_QWORD *)(*((_QWORD *)v13 - 20) + 2952LL) + 192LL * (unsigned __int8)v31 + 161) = 1;
          v32[2] = *(_DWORD *)(v18 + v14 + 52);
          v32[10] = *(unsigned __int8 *)(v30 + 42) | (*(unsigned __int8 *)(v30 + 41) << 16);
          a1 = (char *)qdf_mem_copy((void *)(v18 + v14 + 80), v32 + 12, 0x38u);
          v29 = *(_DWORD *)(v19 + 32);
        }
        if ( (v29 & 2) != 0 )
        {
          v33 = v18 + v14;
          v34 = *(unsigned __int16 *)(v18 + v14 + 50);
          if ( v34 > 0x100 )
            goto LABEL_101;
          v35 = (_DWORD *)(*((_QWORD *)v13 + 781) + 392LL * *(unsigned __int16 *)(v18 + v14 + 50));
          qdf_mem_set(v35, 0x188u, 0);
          *(_BYTE *)(**(_QWORD **)(*((_QWORD *)v13 - 20) + 1480LL) + 336LL * (unsigned __int8)v34 + 321) = 1;
          v35[2] = *(_DWORD *)(v33 + 56);
          v35[10] = *(unsigned __int8 *)(v30 + 42) | (*(unsigned __int8 *)(v30 + 41) << 16);
          a1 = (char *)qdf_mem_copy((void *)(v33 + 136), v35 + 12, 0x38u);
          v29 = *(_DWORD *)(v19 + 32);
        }
        v36 = v18 + v14;
        if ( (v29 & 1) != 0 )
        {
          a1 = (char *)qdf_mem_copy((void *)(v36 + 1456), (const void *)(v36 + 80), 0x38u);
          v29 = *(_DWORD *)(v19 + 32);
          if ( (v29 & 2) != 0 )
            goto LABEL_49;
LABEL_30:
          if ( (v29 & 1) == 0 )
            goto LABEL_31;
LABEL_50:
          a1 = (char *)qdf_mem_copy((void *)(v18 + v14 + 1672), (const void *)(v36 + 80), 0x38u);
          if ( (*(_DWORD *)(v19 + 32) & 2) != 0 )
LABEL_32:
            a1 = (char *)qdf_mem_copy((void *)(v18 + v14 + 1728), (const void *)(v36 + 136), 0x38u);
        }
        else
        {
          if ( (v29 & 2) == 0 )
            goto LABEL_30;
LABEL_49:
          a1 = (char *)qdf_mem_copy((void *)(v18 + v14 + 1512), (const void *)(v36 + 136), 0x38u);
          v29 = *(_DWORD *)(v19 + 32);
          if ( (v29 & 1) != 0 )
            goto LABEL_50;
LABEL_31:
          if ( (v29 & 2) != 0 )
            goto LABEL_32;
        }
        v17 = 1;
        *(_BYTE *)(v18 + v14 + 43) = 0;
        *(_DWORD *)(v19 + 16) = 2;
        goto LABEL_3;
      }
      if ( v21 != 2 )
        goto LABEL_3;
      v22 = v18 + v14;
      v23 = *(unsigned __int8 *)(v18 + v14 + 41);
      if ( v23 > 4 || (v24 = *(unsigned __int8 *)(v22 + 42), v24 > 2) )
LABEL_101:
        __break(0x5512u);
      if ( v24 == 1 )
      {
        v25 = v23 + 1;
        v26 = 0;
        v27 = 1200;
        *(_BYTE *)(v22 + 41) = v23 + 1;
      }
      else
      {
        v26 = v24 + 1;
        v27 = 600;
        v25 = *(unsigned __int8 *)(v18 + v14 + 41);
      }
      *(_BYTE *)(v22 + 42) = v26;
      v38 = *(_BYTE *)(v18 + v14 + 43);
      *(_DWORD *)(v18 + v14 + 120LL * v24 + 240LL * v23 + 248) = v27;
      *(_BYTE *)(v18 + v14 + 43) = v38 + 1;
      if ( (v20 & 1) != 0 )
      {
        if ( *(unsigned __int16 *)(v18 + v14 + 48) > 0x100uLL )
          goto LABEL_101;
        v39 = (_DWORD *)(*((_QWORD *)v13 + 782) + 392LL * *(unsigned __int16 *)(v18 + v14 + 48));
        if ( *(_DWORD *)(v18 + v14 + 52) != v39[2] )
          goto LABEL_2;
        v39[10] = v26 | (v25 << 16);
        if ( v24 == 1 )
        {
          _X8 = (unsigned __int64 *)(v39 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v63 = __ldxr(_X8);
          while ( __stxr(v63 | 1, _X8) );
        }
        else
        {
          _X8 = (unsigned __int64 *)(v39 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v66 = __ldxr(_X8);
          while ( __stxr(v66 | 2, _X8) );
        }
        a1 = (char *)qdf_mem_copy(&v84, v39 + 12, 0x38u);
        v40 = *(_QWORD *)(v18 + v14 + 120);
        v41 = v18 + v14 + 120LL * v24 + 240LL * v23;
        *(_QWORD *)(v41 + 256) = v84 - *(_QWORD *)(v18 + v14 + 80);
        v42 = *(_DWORD *)(v18 + v14 + 88);
        v43 = v85;
        *(_DWORD *)(v41 + 264) = v85 - v42;
        v44 = (__int64)&v39[12 * v23 + 26 + 6 * v24];
        *(_QWORD *)(v41 + 296) = v89 - v40;
        if ( v24 == 1 && (v43 == v42 || !*(_DWORD *)v44 && v39[12 * v23 + 26]) )
          v44 = (__int64)&v39[12 * v23 + 26];
        v45 = v18 + v14 + 120LL * v24 + 240LL * v23;
        *(_DWORD *)(v45 + 268) = *(_DWORD *)v44;
        *(_DWORD *)(v45 + 272) = *(_DWORD *)(v44 + 4);
        *(_QWORD *)(v45 + 280) = *(_QWORD *)(v44 + 8);
        v20 = *(_DWORD *)(v19 + 32);
        *(_QWORD *)(v45 + 288) = *(_QWORD *)(v44 + 16);
      }
      if ( (v20 & 2) != 0 )
      {
        if ( *(unsigned __int16 *)(v18 + v14 + 50) > 0x100uLL )
          goto LABEL_101;
        v46 = (_DWORD *)(*((_QWORD *)v13 + 781) + 392LL * *(unsigned __int16 *)(v18 + v14 + 50));
        if ( *(_DWORD *)(v18 + v14 + 56) != v46[2] )
          goto LABEL_2;
        v46[10] = *(unsigned __int8 *)(v22 + 42) | (*(unsigned __int8 *)(v22 + 41) << 16);
        if ( v24 == 1 )
        {
          _X8 = (unsigned __int64 *)(v46 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v69 = __ldxr(_X8);
          while ( __stxr(v69 | 1, _X8) );
        }
        else
        {
          _X8 = (unsigned __int64 *)(v46 + 8);
          __asm { PRFM            #0x11, [X8] }
          do
            v72 = __ldxr(_X8);
          while ( __stxr(v72 | 2, _X8) );
        }
        a1 = (char *)qdf_mem_copy(&v77, v46 + 12, 0x38u);
        v47 = *(_QWORD *)(v18 + v14 + 176);
        v48 = v18 + v14 + 120LL * v24 + 240LL * v23;
        *(_QWORD *)(v48 + 312) = v77 - *(_QWORD *)(v18 + v14 + 136);
        v49 = *(_DWORD *)(v18 + v14 + 144);
        v50 = v78;
        *(_DWORD *)(v48 + 320) = v78 - v49;
        v51 = (__int64)&v46[12 * v23 + 26 + 6 * v24];
        *(_QWORD *)(v48 + 352) = v82 - v47;
        if ( v24 == 1 && (v50 == v49 || !*(_DWORD *)v51 && v46[12 * v23 + 26]) )
          v51 = (__int64)&v46[12 * v23 + 26];
        v52 = v18 + v14 + 120LL * v24 + 240LL * v23;
        *(_DWORD *)(v52 + 324) = *(_DWORD *)v51;
        *(_DWORD *)(v52 + 328) = *(_DWORD *)(v51 + 4);
        *(_QWORD *)(v52 + 336) = *(_QWORD *)(v51 + 8);
        *(_QWORD *)(v52 + 344) = *(_QWORD *)(v51 + 16);
      }
      if ( !*(_BYTE *)(v22 + 42) )
      {
        qdf_mem_copy((void *)(v18 + v14 + 80), &v84, 0x38u);
        a1 = (char *)qdf_mem_copy((void *)(v18 + v14 + 136), &v77, 0x38u);
      }
      if ( *(_BYTE *)(v22 + 41) != 5 )
      {
        v17 = 1;
        goto LABEL_3;
      }
      v53 = *(_DWORD *)(v19 + 32);
      LOBYTE(v54) = v53 | 4;
      *(_DWORD *)(v19 + 32) = v53 | 4;
      if ( (v53 & 0x40) != 0 )
      {
        v55 = 3;
LABEL_79:
        *(_DWORD *)(v19 + 16) = v55;
        v17 = 1;
        goto LABEL_3;
      }
      *(_DWORD *)(v19 + 16) = 5;
      if ( (v53 & 1) != 0 )
      {
        *(_BYTE *)(*(_QWORD *)(*(_QWORD *)v76 + 2952LL) + 192LL * *(unsigned __int8 *)(v18 + v14 + 48) + 161) = 0;
        v54 = *(_DWORD *)(v19 + 32);
      }
      if ( (v54 & 2) == 0 )
        goto LABEL_41;
      v17 = 1;
      *(_BYTE *)(**(_QWORD **)(*(_QWORD *)v76 + 1480LL) + 336LL * *(unsigned __int8 *)(v18 + v14 + 50) + 321) = 0;
    }
LABEL_3:
    --v16;
    v15 |= v17;
    v14 += 1872;
  }
  while ( v16 );
  if ( (v15 & 1) != 0 )
  {
    v73 = ktime_get(a1, a2, a3, a4, a5);
    hrtimer_forward(v13, v73, 600000000);
    result = 1;
  }
  else
  {
    v75 = *(v13 - 12);
    *((_DWORD *)v13 + 22) = 1;
    if ( (v75 & 4) != 0 )
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: STC: Sampling timer stopped!",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "wlan_dp_stc_flow_sampling_timer");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
