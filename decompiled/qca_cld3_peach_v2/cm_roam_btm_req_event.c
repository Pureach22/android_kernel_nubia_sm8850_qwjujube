__int64 __fastcall cm_roam_btm_req_event(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4, char a5)
{
  unsigned int v10; // w25
  __int64 v11; // x0
  char v12; // w14
  int v13; // w11
  unsigned int v14; // w12
  unsigned int v15; // kr00_4
  unsigned int v16; // kr04_4
  unsigned int v17; // w22
  __int64 v18; // x0
  int v19; // w10
  int v20; // w9
  __int64 v21; // x22
  __int64 v22; // x21
  int v23; // w8
  unsigned int v24; // w26
  __int64 v25; // x0
  __int64 v27; // [xsp+8h] [xbp-78h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+10h] [xbp-70h]
  __int64 v29; // [xsp+18h] [xbp-68h]
  __int64 v30; // [xsp+20h] [xbp-60h]
  __int64 v31; // [xsp+28h] [xbp-58h]
  __int64 v32; // [xsp+30h] [xbp-50h]
  unsigned int v33; // [xsp+38h] [xbp-48h]
  __int64 v34; // [xsp+40h] [xbp-40h] BYREF
  unsigned __int64 v35; // [xsp+48h] [xbp-38h]
  __int64 v36; // [xsp+50h] [xbp-30h]
  __int64 v37; // [xsp+58h] [xbp-28h]
  __int64 v38; // [xsp+60h] [xbp-20h]
  __int64 v39; // [xsp+68h] [xbp-18h]
  int v40; // [xsp+70h] [xbp-10h]
  __int64 v41; // [xsp+78h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v27, 0x34u, 0);
  if ( (*(_BYTE *)a3 != 1 || *(_DWORD *)(a3 + 196) != 1 || !*(_DWORD *)(a2 + 8)) && *(_DWORD *)(a3 + 8) != 10 )
  {
    v10 = *(_DWORD *)(a1 + 16);
    if ( !v10 )
      v10 = *(_DWORD *)(a3 + 16);
    HIWORD(v27) = a4;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v11 = ktime_get();
    BYTE1(v32) = 19;
    v12 = *(_BYTE *)(a2 + 32);
    LOBYTE(v31) = 2;
    v13 = *(_DWORD *)(a2 + 4);
    v14 = *(_DWORD *)(a2 + 8);
    LOBYTE(v32) = v12;
    v15 = v14;
    BYTE2(v31) = v13;
    v16 = *(_DWORD *)(a2 + 12);
    BYTE4(v31) = *(_DWORD *)(a2 + 16);
    LOBYTE(v14) = *(_BYTE *)(a2 + 165);
    HIDWORD(v32) = v16 / 0x3E8;
    v33 = v15 / 0x3E8;
    v29 = 1000LL * v10;
    v30 = v11 / 1000;
    HIBYTE(v31) = HIBYTE(v31) & 1 | (2 * v14);
    host_diag_event_report_payload(3361, 52, &v27);
    if ( (a5 & 1) != 0 )
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v36 = 0;
      v37 = 0;
      v34 = 0;
      v35 = 0;
      qdf_mem_set(&v34, 0x34u, 0);
      v17 = *(_DWORD *)(a3 + 16);
      HIWORD(v34) = a4;
      v35 = qdf_get_time_of_the_day_us();
      v18 = ktime_get();
      LOBYTE(v38) = 1;
      BYTE1(v39) = 23;
      v19 = *(_DWORD *)(a3 + 28);
      BYTE1(v38) = *(_DWORD *)(a3 + 24);
      v20 = *(_DWORD *)(a3 + 60);
      BYTE3(v38) = v19;
      v36 = 1000LL * v17;
      v37 = v18 / 1000;
      WORD1(v39) = v20;
      host_diag_event_report_payload(3361, 52, &v34);
    }
    if ( *(_DWORD *)(a2 + 16) )
    {
      v21 = 0;
      v22 = a2 + 36;
      do
      {
        if ( v21 == 9 )
          __break(0x5512u);
        v37 = 0;
        v38 = 0;
        v35 = 0;
        v36 = 0;
        v34 = 0;
        qdf_mem_set(&v34, 0x28u, 0);
        v24 = *(_DWORD *)(v22 + 8);
        HIWORD(v34) = a4;
        v35 = qdf_get_time_of_the_day_us();
        v25 = ktime_get();
        v36 = 1000LL * v24;
        v37 = v25 / 1000;
        if ( v22 )
          qdf_mem_copy(&v34, (const void *)v22, 6u);
        v23 = *(unsigned __int8 *)(v22 + 12);
        LOBYTE(v38) = 1;
        HIDWORD(v38) = v23;
        WORD1(v38) = v21;
        host_diag_event_report_payload(3362, 40, &v34);
        ++v21;
        v22 += 16;
      }
      while ( *(_DWORD *)(a2 + 16) > (unsigned int)v21 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
