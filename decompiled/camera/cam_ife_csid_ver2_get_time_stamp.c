__int64 __fastcall cam_ife_csid_ver2_get_time_stamp(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x20
  __int64 v3; // x8
  unsigned int v4; // w8
  const char *v5; // x5
  __int64 v6; // x1
  __int64 v7; // x6
  __int64 v8; // x2
  __int64 v9; // x4
  __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 v13; // x25
  __int64 v14; // x8
  int v15; // w10
  __int64 v16; // x26
  __int64 v17; // x27
  int v18; // w28
  int v19; // w21
  __int64 v20; // x19
  unsigned int v21; // w0
  int v22; // w9
  unsigned int v23; // w8
  __int64 v24; // x8
  int v25; // w10
  __int64 v26; // x9
  __int64 v27; // x21
  __int64 v28; // x22
  int v29; // w23
  int v30; // w24
  __int64 v31; // x25
  unsigned int v32; // w19
  unsigned int v33; // w0
  int v34; // w9
  unsigned int v35; // w8
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x8
  __int64 v38; // x8
  unsigned __int64 v39; // x10
  __int64 v40; // x19
  __int64 (__fastcall *v41)(__int64); // x8
  unsigned __int64 v42; // x9
  char v43; // w8
  unsigned __int64 v44; // x9
  __int64 v46; // x19
  unsigned int v47; // [xsp+24h] [xbp-Ch]
  __int64 v48; // [xsp+28h] [xbp-8h]

  v2 = *(_DWORD **)a2;
  if ( **(_DWORD **)a2 == 3 && (v3 = (unsigned int)v2[1], (unsigned int)v3 < 0xC) )
  {
    v10 = *(_QWORD *)(a1 + 31128);
    if ( *(_DWORD *)(v10 + 92) != 1 )
    {
      v5 = "CSID:%u Invalid dev state :%d";
      v7 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v6 = 8;
      v8 = 1;
      v9 = 8098;
      goto LABEL_18;
    }
    v11 = **(_QWORD **)(a1 + 31136);
    v12 = *(_QWORD *)(v11 + 8 * v3 + 136);
    if ( !v12 )
    {
      v5 = "CSID:%u Invalid res :%d";
      v7 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v6 = 8;
      v8 = 1;
      v9 = 8107;
      goto LABEL_18;
    }
    v13 = *((_QWORD *)v2 + 3);
    v48 = a1;
    if ( *(_BYTE *)(a2 + 32) == 1 )
    {
      v14 = *(_QWORD *)(v13 + 264);
      v15 = *(_DWORD *)(v12 + 316);
      v16 = a2;
      v17 = *(_QWORD *)(v10 + 384);
      v18 = *(unsigned __int8 *)(v13 + 254);
      v19 = *(_DWORD *)(*(_QWORD *)(v11 + 120) + 696LL);
      v20 = (unsigned int)(*(_DWORD *)(v14 + 204) + v15);
      v47 = cam_io_r_mb(v17 + (unsigned int)(*(_DWORD *)(v14 + 208) + v15));
      v21 = cam_io_r_mb(v17 + v20);
      v22 = ~v19;
      v23 = v21;
      if ( !v18 )
        v22 = -1;
      a1 = v48;
      a2 = v16;
      *(_QWORD *)(v16 + 24) = (((((10000 * (unsigned __int64)(v22 & v23)) >> 32) + 10000LL * v47) / 0xC0) << 32)
                            | (unsigned int)((unsigned __int64)((((10000LL * (v22 & v23)) & 0xFFFFFFC0LL
                                                                | (((((10000 * (unsigned __int64)(v22 & v23)) >> 32)
                                                                   + 10000LL * v47)
                                                                  % 0xC0) << 32))
                                                               * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
    }
    if ( *(_BYTE *)(a2 + 33) == 1 )
    {
      v24 = *(_QWORD *)(v13 + 264);
      v25 = *(_DWORD *)(v12 + 316);
      v26 = *(_QWORD *)(v11 + 120);
      v27 = *(_QWORD *)(v10 + 384);
      v28 = a2;
      v29 = *(unsigned __int8 *)(v13 + 254);
      v30 = *(_DWORD *)(v26 + 696);
      v31 = (unsigned int)(*(_DWORD *)(v24 + 196) + v25);
      v32 = cam_io_r_mb(v27 + (unsigned int)(*(_DWORD *)(v24 + 200) + v25));
      v33 = cam_io_r_mb(v27 + v31);
      v34 = ~v30;
      v35 = v33;
      if ( !v29 )
        v34 = -1;
      a1 = v48;
      a2 = v28;
      v36 = (((((10000 * (unsigned __int64)(v34 & v35)) >> 32) + 10000LL * v32) / 0xC0) << 32)
          | (unsigned int)((unsigned __int64)((((10000LL * (v34 & v35)) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(v34 & v35)) >> 32) + 10000LL * v32)
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      *(_QWORD *)(v28 + 8) = v36;
    }
    else
    {
      if ( (*(_BYTE *)(v13 + 254) & 1) != 0 )
        v37 = *(_QWORD *)(a2 + 8) & ~(unsigned __int64)*(unsigned int *)(*(_QWORD *)(v11 + 120) + 696LL);
      else
        v37 = *(_QWORD *)(a2 + 8);
      v36 = (((((10000 * (unsigned __int64)(unsigned int)v37) >> 32) + 10000LL * HIDWORD(v37)) / 0xC0) << 32)
          | (unsigned int)((unsigned __int64)((((10000LL * (unsigned int)v37) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(unsigned int)v37) >> 32)
                                                 + 10000LL * HIDWORD(v37))
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      *(_QWORD *)(a2 + 8) = v36;
    }
    v38 = g_ref_time;
    if ( g_ref_time )
    {
      v39 = qword_394728;
    }
    else
    {
      v40 = a2;
      v41 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      qword_394728 = v41(a1);
      v38 = ktime_get_with_offset(1);
      a1 = v48;
      a2 = v40;
      v39 = (((((10000 * (unsigned __int64)(unsigned int)qword_394728) >> 32) + 10000LL * HIDWORD(qword_394728)) / 0xC0) << 32)
          | (unsigned int)((unsigned __int64)((((10000LL * (unsigned int)qword_394728) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(unsigned int)qword_394728) >> 32)
                                                 + 10000LL * HIDWORD(qword_394728))
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      g_ref_time = v38;
      qword_394728 = v39;
      v36 = *(_QWORD *)(v40 + 8);
    }
    v42 = v36 + v38;
    v43 = debug_mdl;
    v44 = v42 - v39;
    *(_QWORD *)(a2 + 16) = v44;
    if ( (v43 & 8) != 0 && !debug_priority )
    {
      v46 = a2;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v43 & 8,
        4,
        "cam_ife_csid_ver2_get_time_stamp",
        8147,
        "CSID[%u] Resource[id:%d name:%s timestamp:%llu:%09llu]",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        v2[1],
        (const char *)v2 + 128,
        v44 / 0x3B9ACA00,
        v44 % 0x3B9ACA00);
      a1 = v48;
      a2 = v46;
    }
    v4 = 0;
    *(_QWORD *)(a1 + 2256) = *(_QWORD *)(a2 + 8);
    *(_QWORD *)(a1 + 2248) = *(_QWORD *)(a2 + 16);
  }
  else
  {
    v4 = -22;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v5 = "CSID:%u Invalid res_type:%d res id%d";
      v6 = debug_mdl & 8;
      v7 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v8 = 4;
      v9 = 8091;
LABEL_18:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v6,
        v8,
        "cam_ife_csid_ver2_get_time_stamp",
        v9,
        v5,
        v7);
      return (unsigned int)-22;
    }
  }
  return v4;
}
