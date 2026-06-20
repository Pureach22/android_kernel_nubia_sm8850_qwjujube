__int64 __fastcall cm_roam_btm_req_event(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4, char a5)
{
  unsigned int v10; // w25
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x0
  char v16; // w14
  int v17; // w11
  unsigned int v18; // w12
  unsigned int v19; // kr00_4
  unsigned int v20; // kr04_4
  unsigned int v21; // w22
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x0
  int v27; // w10
  int v28; // w9
  __int64 v29; // x22
  __int64 v30; // x21
  int v31; // w8
  unsigned int v32; // w26
  __int64 v33; // x1
  __int64 v34; // x2
  __int64 v35; // x3
  __int64 v36; // x4
  __int64 v37; // x0
  __int64 v39; // [xsp+8h] [xbp-78h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+10h] [xbp-70h]
  __int64 v41; // [xsp+18h] [xbp-68h]
  __int64 v42; // [xsp+20h] [xbp-60h]
  __int64 v43; // [xsp+28h] [xbp-58h]
  __int64 v44; // [xsp+30h] [xbp-50h]
  unsigned int v45; // [xsp+38h] [xbp-48h]
  __int64 v46; // [xsp+40h] [xbp-40h] BYREF
  unsigned __int64 v47; // [xsp+48h] [xbp-38h]
  __int64 v48; // [xsp+50h] [xbp-30h]
  __int64 v49; // [xsp+58h] [xbp-28h]
  __int64 v50; // [xsp+60h] [xbp-20h]
  __int64 v51; // [xsp+68h] [xbp-18h]
  int v52; // [xsp+70h] [xbp-10h]
  __int64 v53; // [xsp+78h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v39, 0x34u, 0);
  if ( (*(_BYTE *)a3 != 1 || *(_DWORD *)(a3 + 196) != 1 || !*(_DWORD *)(a2 + 8)) && *(_DWORD *)(a3 + 8) != 10 )
  {
    v10 = *(_DWORD *)(a1 + 16);
    if ( !v10 )
      v10 = *(_DWORD *)(a3 + 16);
    HIWORD(v39) = a4;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v15 = ktime_get(time_of_the_day_us, v11, v12, v13, v14);
    BYTE1(v44) = 19;
    v16 = *(_BYTE *)(a2 + 32);
    LOBYTE(v43) = 2;
    v17 = *(_DWORD *)(a2 + 4);
    v18 = *(_DWORD *)(a2 + 8);
    LOBYTE(v44) = v16;
    v19 = v18;
    BYTE2(v43) = v17;
    v20 = *(_DWORD *)(a2 + 12);
    BYTE4(v43) = *(_DWORD *)(a2 + 16);
    LOBYTE(v18) = *(_BYTE *)(a2 + 165);
    HIDWORD(v44) = v20 / 0x3E8;
    v45 = v19 / 0x3E8;
    v41 = 1000LL * v10;
    v42 = v15 / 1000;
    HIBYTE(v43) = HIBYTE(v43) & 1 | (2 * v18);
    host_diag_event_report_payload(3361, 52, &v39);
    if ( (a5 & 1) != 0 )
    {
      v52 = 0;
      v50 = 0;
      v51 = 0;
      v48 = 0;
      v49 = 0;
      v46 = 0;
      v47 = 0;
      qdf_mem_set(&v46, 0x34u, 0);
      v21 = *(_DWORD *)(a3 + 16);
      HIWORD(v46) = a4;
      v47 = qdf_get_time_of_the_day_us();
      v26 = ktime_get(v47, v22, v23, v24, v25);
      LOBYTE(v50) = 1;
      BYTE1(v51) = 23;
      v27 = *(_DWORD *)(a3 + 28);
      BYTE1(v50) = *(_DWORD *)(a3 + 24);
      v28 = *(_DWORD *)(a3 + 60);
      BYTE3(v50) = v27;
      v48 = 1000LL * v21;
      v49 = v26 / 1000;
      WORD1(v51) = v28;
      host_diag_event_report_payload(3361, 52, &v46);
    }
    if ( *(_DWORD *)(a2 + 16) )
    {
      v29 = 0;
      v30 = a2 + 36;
      do
      {
        if ( v29 == 9 )
          __break(0x5512u);
        v49 = 0;
        v50 = 0;
        v47 = 0;
        v48 = 0;
        v46 = 0;
        qdf_mem_set(&v46, 0x28u, 0);
        v32 = *(_DWORD *)(v30 + 8);
        HIWORD(v46) = a4;
        v47 = qdf_get_time_of_the_day_us();
        v37 = ktime_get(v47, v33, v34, v35, v36);
        v48 = 1000LL * v32;
        v49 = v37 / 1000;
        if ( v30 )
          qdf_mem_copy(&v46, (const void *)v30, 6u);
        v31 = *(unsigned __int8 *)(v30 + 12);
        LOBYTE(v50) = 1;
        HIDWORD(v50) = v31;
        WORD1(v50) = v29;
        host_diag_event_report_payload(3362, 40, &v46);
        ++v29;
        v30 += 16;
      }
      while ( *(_DWORD *)(a2 + 16) > (unsigned int)v29 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
