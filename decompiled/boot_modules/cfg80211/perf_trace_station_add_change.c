__int64 __fastcall perf_trace_station_add_change(__int64 result, __int64 a2, __int64 a3, int *a4, __int64 *a5)
{
  __int64 v5; // x30
  __int64 v6; // x26
  __int64 v9; // x8
  int v10; // w28
  int v11; // w19
  int v12; // w21
  int v13; // w27
  _QWORD *v14; // x9
  __int64 v15; // x22
  const char *v16; // x26
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x10
  __int64 v20; // x8
  int *v21; // x9
  __int16 v22; // w8
  int v23; // w9
  char v24; // w9
  __int64 *v25; // x9
  __int16 v26; // w10
  __int64 v27; // x12
  __int64 v28; // x9
  __int64 v29; // x11
  __int64 *v30; // t2
  __int64 *v31; // x9
  int v32; // w10
  __int64 v33; // x9
  __int64 v34; // x9
  __int64 v35; // x10
  __int64 v36; // x3
  unsigned __int64 v37; // x9
  __int64 v38; // x2
  __int64 v39; // x5
  __int64 v40; // x1
  __int64 v41; // x0
  __int64 v42; // [xsp+0h] [xbp-50h] BYREF
  unsigned int v43; // [xsp+Ch] [xbp-44h]
  __int64 v44; // [xsp+10h] [xbp-40h]
  int *v45; // [xsp+18h] [xbp-38h]
  __int64 v46; // [xsp+20h] [xbp-30h]
  unsigned __int64 StatusReg; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  unsigned int v49; // [xsp+3Ch] [xbp-14h] BYREF
  _QWORD v50[2]; // [xsp+40h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+50h] [xbp+0h] BYREF

  v44 = a3;
  v45 = a4;
  v6 = v5;
  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(result + 104);
  v50[0] = 0;
  v10 = *((unsigned __int8 *)a5 + 136);
  v49 = 0;
  v11 = *((unsigned __int8 *)a5 + 56);
  v12 = *((unsigned __int8 *)a5 + 72);
  v48 = v9;
  v13 = *((unsigned __int8 *)a5 + 88);
  v46 = result;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v48)
    || (v43 = (((_WORD)v13 + (_WORD)v11 + (_WORD)v10 + (_WORD)v12 + 175) & 0x7F8) - 4,
        (result = perf_trace_buf_alloc(v43, v50, &v49)) == 0) )
  {
LABEL_33:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v14 = (_QWORD *)v50[0];
  *(_QWORD *)(v50[0] + 248LL) = &v42;
  v14[29] = &vars0;
  v15 = result;
  v14[32] = v6;
  v14[33] = 5;
  *(_DWORD *)(result + 148) = (v10 << 16) | 0xA4;
  *(_DWORD *)(result + 152) = (v10 | (v11 << 16)) + 164;
  *(_DWORD *)(result + 156) = ((v11 + v10) | (v12 << 16)) + 164;
  *(_DWORD *)(result + 160) = ((v11 + v10 + v12) | (v13 << 16)) + 164;
  v16 = *(const char **)(a2 + 504);
  if ( !v16 )
    v16 = *(const char **)(a2 + 392);
  v17 = strnlen(v16, 0x20u);
  if ( v17 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v17 == 32 )
      v18 = 32;
    else
      v18 = v17 + 1;
    if ( v18 < 0x21 )
    {
      sized_strscpy(v15 + 8, v16);
      v19 = v44;
      v20 = *(_QWORD *)(v44 + 304);
      *(_QWORD *)(v15 + 40) = *(_QWORD *)(v44 + 296);
      *(_QWORD *)(v15 + 48) = v20;
      v21 = v45;
      *(_DWORD *)(v15 + 56) = *(_DWORD *)(v19 + 224);
      if ( v21 )
      {
        v22 = *((_WORD *)v21 + 2);
        v23 = *v21;
        *(_WORD *)(v15 + 64) = v22;
        *(_DWORD *)(v15 + 60) = v23;
      }
      else
      {
        *(_WORD *)(v15 + 64) = 0;
        *(_DWORD *)(v15 + 60) = 0;
      }
      *(_DWORD *)(v15 + 68) = *((_DWORD *)a5 + 2);
      *(_DWORD *)(v15 + 72) = *((_DWORD *)a5 + 3);
      *(_DWORD *)(v15 + 76) = *((_DWORD *)a5 + 4);
      *(_DWORD *)(v15 + 80) = *((_DWORD *)a5 + 5);
      *(_WORD *)(v15 + 86) = *((_WORD *)a5 + 12);
      *(_BYTE *)(v15 + 88) = *((_BYTE *)a5 + 30);
      *(_BYTE *)(v15 + 89) = *((_BYTE *)a5 + 31);
      v24 = *((_BYTE *)a5 + 32);
      *(_QWORD *)(v15 + 94) = 0;
      *(_QWORD *)(v15 + 102) = 0;
      *(_QWORD *)(v15 + 110) = 0;
      *(_BYTE *)(v15 + 90) = v24;
      *(_WORD *)(v15 + 118) = 0;
      v25 = (__int64 *)a5[18];
      if ( v25 )
      {
        v26 = *((_WORD *)v25 + 12);
        v27 = *v25;
        v30 = v25 + 1;
        v28 = v25[1];
        v29 = v30[1];
        *(_WORD *)(v15 + 118) = v26;
        *(_QWORD *)(v15 + 94) = v27;
        *(_QWORD *)(v15 + 102) = v28;
        *(_QWORD *)(v15 + 110) = v29;
      }
      *(_QWORD *)(v15 + 120) = 0;
      *(_DWORD *)(v15 + 128) = 0;
      v31 = (__int64 *)a5[19];
      if ( v31 )
      {
        v32 = *((_DWORD *)v31 + 2);
        v33 = *v31;
        *(_DWORD *)(v15 + 128) = v32;
        *(_QWORD *)(v15 + 120) = v33;
      }
      *(_QWORD *)(v15 + 132) = 0;
      *(_QWORD *)(v15 + 140) = 0;
      v34 = *a5;
      if ( *a5 )
      {
        v35 = *(_QWORD *)(v34 + 304);
        *(_QWORD *)(v15 + 132) = *(_QWORD *)(v34 + 296);
        *(_QWORD *)(v15 + 140) = v35;
      }
      if ( a5[16] && *((_BYTE *)a5 + 136) )
        memcpy((void *)(v15 + *(unsigned __int16 *)(v15 + 148)), (const void *)a5[16], *((unsigned __int8 *)a5 + 136));
      if ( a5[6] && *((_BYTE *)a5 + 56) )
        memcpy((void *)(v15 + *(unsigned __int16 *)(v15 + 152)), (const void *)a5[6], *((unsigned __int8 *)a5 + 56));
      if ( a5[8] && *((_BYTE *)a5 + 72) )
        memcpy((void *)(v15 + *(unsigned __int16 *)(v15 + 156)), (const void *)a5[8], *((unsigned __int8 *)a5 + 72));
      if ( a5[10] )
      {
        if ( *((_BYTE *)a5 + 88) )
          memcpy((void *)(v15 + *(unsigned __int16 *)(v15 + 160)), (const void *)a5[10], *((unsigned __int8 *)a5 + 88));
      }
      v36 = v46;
      v37 = StatusReg;
      v38 = v49;
      *(_BYTE *)(v15 + 91) = *((_BYTE *)a5 + 33);
      v39 = v50[0];
      v40 = v43;
      *(_WORD *)(v15 + 84) = *((_WORD *)a5 + 20);
      *(_BYTE *)(v15 + 92) = *((_BYTE *)a5 + 160);
      *(_BYTE *)(v15 + 93) = *((_BYTE *)a5 + 161);
      result = perf_trace_run_bpf_submit(v15, v40, v38, v36, 1, v39, v37 + v48, 0);
      goto LABEL_33;
    }
  }
  v41 = _fortify_panic(7, 32);
  return trace_event_raw_event_wiphy_netdev_mac_evt(v41);
}
