__int64 __fastcall cam_generic_fence_dump_monitor_array(__int64 result)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x8
  __int64 v3; // x19
  unsigned int v4; // w28
  int v5; // w27
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x7
  __int64 v8; // x6
  int v9; // w10
  __int64 v10; // x9
  int v11; // w11
  int v12; // w12
  __int64 v13; // x10
  const char *v14; // x5
  __int64 v15; // x1
  __int64 v16; // x4
  __int64 v17; // x25
  unsigned __int64 v18; // x10
  __int64 v19; // x9
  unsigned __int64 *v20; // x9
  const char *v21; // x8
  __int64 v22; // x10
  unsigned __int64 v23; // x8
  unsigned int v24; // w27
  int v25; // w21
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x7
  __int64 v28; // x6
  int v29; // w10
  const char *v30; // x5
  __int64 v31; // x1
  __int64 v32; // x4
  __int64 v33; // x25
  unsigned __int64 v34; // x10
  __int64 v35; // x9
  unsigned __int64 *v36; // x9
  const char *v37; // x8
  __int64 v38; // x10
  __int64 v39; // [xsp+8h] [xbp-68h]
  __int64 v40; // [xsp+10h] [xbp-60h]
  int v41; // [xsp+18h] [xbp-58h]
  int v42; // [xsp+20h] [xbp-50h]
  int v43; // [xsp+28h] [xbp-48h]
  int v44; // [xsp+28h] [xbp-48h]
  int v45; // [xsp+30h] [xbp-40h]
  int v46; // [xsp+38h] [xbp-38h]
  int v47; // [xsp+38h] [xbp-38h]
  int v48; // [xsp+40h] [xbp-30h]
  unsigned __int64 v49; // [xsp+58h] [xbp-18h] BYREF
  __int64 v50; // [xsp+60h] [xbp-10h]
  __int64 v51; // [xsp+68h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 40);
  v49 = 0;
  v50 = 0;
  v2 = *(_QWORD *)v1;
  if ( *(_QWORD *)v1 == -1 )
    goto LABEL_31;
  v3 = result;
  if ( v2 > 0x1D )
  {
    v5 = 30;
    v4 = (v2 + 1) % 0x1E;
  }
  else
  {
    v4 = 0;
    v5 = v2 + 1;
  }
  ktime_get_real_ts64(&v49);
  v6 = v49 % 0x3C;
  v7 = v49 / 0x3C - 60 * ((unsigned __int64)((v49 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1);
  v8 = v49 / 0xE10 - 24 * ((v49 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64);
  v9 = *(_DWORD *)(v3 + 32);
  v10 = v50 / 1000000;
  switch ( v9 )
  {
    case 3:
      v11 = *(_DWORD *)(v3 + 12);
      v12 = *(_DWORD *)(v3 + 16);
      v13 = *(_QWORD *)v3;
      v14 = "======== %llu:%llu:%llu:%llu Dumping monitor information for synx obj %s, synx_id %d sync_id %d state %d ref"
            "_cnt %d num_entries %u ===========";
      v15 = 0x1000000000LL;
      v16 = 231;
      v47 = v5;
      v45 = *(_DWORD *)(v3 + 28);
      v43 = *(_DWORD *)(v3 + 20);
      goto LABEL_11;
    case 2:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, unsigned __int64, __int64, _QWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))cam_print_log)(
        3,
        0x400000000LL,
        3,
        "cam_generic_fence_dump_monitor_array",
        224,
        "======== %llu:%llu:%llu:%llu Dumping monitor information for dma obj %s, fd %d sync_id %d state %d ref_cnt %d nu"
        "m_entries %u ===========",
        v8,
        v7,
        v6,
        v10,
        *(_QWORD *)v3,
        *(_DWORD *)(v3 + 12),
        *(_DWORD *)(v3 + 16),
        *(_DWORD *)(v3 + 20),
        *(_DWORD *)(v3 + 28),
        v5);
      break;
    case 1:
      v11 = *(_DWORD *)(v3 + 8);
      v12 = *(_DWORD *)(v3 + 12);
      v13 = *(_QWORD *)v3;
      v48 = v5;
      v14 = "======== %llu:%llu:%llu:%llu Dumping monitor information for sync obj %s, type %d, sync_id %d state %d remai"
            "ning %d ref_cnt %d num_entries %u ===========";
      v47 = *(_DWORD *)(v3 + 28);
      v45 = *(_DWORD *)(v3 + 24);
      v15 = 128;
      v43 = *(_DWORD *)(v3 + 20);
      v16 = 217;
LABEL_11:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, unsigned __int64, __int64, __int64, int, int, int, int, int, int))cam_print_log)(
        3,
        v15,
        3,
        "cam_generic_fence_dump_monitor_array",
        v16,
        v14,
        v8,
        v7,
        v6,
        v10,
        v13,
        v11,
        v12,
        v43,
        v45,
        v47,
        v48);
      break;
  }
  v17 = *(_QWORD *)(v3 + 48);
  do
  {
    v20 = (unsigned __int64 *)(v17 + 24LL * v4);
    v21 = "INVALID";
    v22 = *((unsigned int *)v20 + 4);
    if ( (unsigned int)v22 <= 7 )
      v21 = off_44A7E0[v22];
    v18 = *v20;
    v19 = (unsigned __int128)((__int64)v20[1] * (__int128)0x431BDE82D7B634DBLL) >> 64;
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               128,
               3,
               "__cam_generic_fence_dump_monitor_entries",
               164,
               "**** %llu:%llu:%llu.%llu : Index[%d] Op[%s]",
               (_QWORD)(v18 / 0xE10 - 24 * ((v18 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
               v18 / 0x3C - 60 * ((unsigned __int64)((v18 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
               v18 % 0x3C,
               (v19 >> 18) + ((unsigned __int64)v19 >> 63),
               v4,
               v21);
    --v5;
    v4 = (v4 + 1) % 0x1E;
  }
  while ( v5 );
  v23 = *(_QWORD *)(v1 + 160);
  if ( v23 != -1 )
  {
    if ( v23 > 0x1D )
    {
      v25 = 30;
      v24 = (v23 + 1) % 0x1E;
    }
    else
    {
      v24 = 0;
      v25 = v23 + 1;
    }
    ktime_get_real_ts64(&v49);
    v26 = v49 % 0x3C;
    v27 = v49 / 0x3C - 60 * ((unsigned __int64)((v49 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1);
    v28 = v49 / 0xE10 - 24 * ((v49 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64);
    v29 = *(_DWORD *)(v3 + 32);
    if ( v29 == 3 )
    {
      v30 = "======== %llu:%llu:%llu:%llu Dumping previous monitor information for synx obj %s, synx_id %d sync_id %d sta"
            "te %d num_entries %u ===========";
      v31 = 0x1000000000LL;
      v32 = 272;
      v44 = *(_DWORD *)(v1 + 152);
      v42 = *(_DWORD *)(v1 + 144);
      v41 = *(_DWORD *)(v1 + 140);
      v39 = v50 / 1000000;
      v40 = v1 + 8;
    }
    else
    {
      if ( v29 != 2 )
      {
        if ( v29 == 1 )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, unsigned __int64, __int64, __int64, _DWORD, _DWORD, _DWORD, _DWORD, int))cam_print_log)(
            3,
            128,
            3,
            "cam_generic_fence_dump_monitor_array",
            258,
            "======== %llu:%llu:%llu:%llu Dumping previous monitor information for sync obj %s, type %d, sync_id %d state"
            " %d remaining %d num_entries %u ===========",
            v28,
            v27,
            v26,
            v50 / 1000000,
            v1 + 8,
            *(_DWORD *)(v1 + 136),
            *(_DWORD *)(v1 + 140),
            *(_DWORD *)(v1 + 152),
            *(_DWORD *)(v1 + 148),
            v25);
        goto LABEL_27;
      }
      v39 = v50 / 1000000;
      v40 = v1 + 8;
      v30 = "======== %llu:%llu:%llu:%llu Dumping previous monitor information for dma obj %s, fd %d sync_id %d state %d "
            "num_entries %u ===========";
      v44 = *(_DWORD *)(v1 + 152);
      v42 = *(_DWORD *)(v1 + 144);
      v31 = 0x400000000LL;
      v41 = *(_DWORD *)(v1 + 140);
      v32 = 265;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, unsigned __int64, __int64, __int64, int, int, int, int, int))cam_print_log)(
      3,
      v31,
      3,
      "cam_generic_fence_dump_monitor_array",
      v32,
      v30,
      v28,
      v27,
      v26,
      v39,
      v40,
      v41,
      v42,
      v44,
      v25,
      v46);
LABEL_27:
    v33 = *(_QWORD *)(v3 + 56);
    do
    {
      v36 = (unsigned __int64 *)(v33 + 24LL * v24);
      v37 = "INVALID";
      v38 = *((unsigned int *)v36 + 4);
      if ( (unsigned int)v38 <= 7 )
        v37 = off_44A7E0[v38];
      v34 = *v36;
      v35 = (unsigned __int128)((__int64)v36[1] * (__int128)0x431BDE82D7B634DBLL) >> 64;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 128,
                 3,
                 "__cam_generic_fence_dump_monitor_entries",
                 164,
                 "**** %llu:%llu:%llu.%llu : Index[%d] Op[%s]",
                 (_QWORD)(v34 / 0xE10 - 24 * ((v34 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
                 v34 / 0x3C
               - 60 * ((unsigned __int64)((v34 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
                 v34 % 0x3C,
                 (v35 >> 18) + ((unsigned __int64)v35 >> 63),
                 v24,
                 v37);
      --v25;
      v24 = (v24 + 1) % 0x1E;
    }
    while ( v25 );
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
