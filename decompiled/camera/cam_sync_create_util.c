__int64 __fastcall cam_sync_create_util(unsigned int *a1, const char *a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x21
  __int64 first_zero_bit; // x0
  __int64 v9; // x25
  __int64 v10; // x20
  __int64 v11; // x25
  __int64 v18; // x8
  __int64 v19; // x24
  __int64 v20; // x8
  int v21; // w19
  __int64 v22; // x22
  __int64 v23; // x23
  unsigned int put_ref; // w23
  __int64 v26; // x9
  __int64 v27; // x20
  __int64 v28; // x7
  const char *v29; // x5
  __int64 v30; // x1
  __int64 v31; // x4
  const char *v32; // x6
  unsigned __int64 v35; // x9
  unsigned __int64 v38; // x11
  unsigned __int64 v41; // x10
  int v42; // [xsp+0h] [xbp-30h]

  v7 = 8416;
  while ( 1 )
  {
    first_zero_bit = find_first_zero_bit(sync_dev + 8416, 2048);
    if ( first_zero_bit >= 2048 )
      break;
    if ( (debug_mdl & 0x80) != 0 && !debug_priority )
    {
      v11 = first_zero_bit;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int8)debug_mdl & 0x80,
        4,
        "cam_sync_create_util",
        73,
        "Index location available at idx: %ld",
        first_zero_bit);
      first_zero_bit = v11;
    }
    v9 = 1LL << first_zero_bit;
    v10 = (unsigned int)first_zero_bit >> 6;
    _X9 = (unsigned __int64 *)(sync_dev + 8416 + 8 * v10);
    __asm { PRFM            #0x11, [X9] }
    do
      v18 = __ldxr(_X9);
    while ( __stlxr(v18 | v9, _X9) );
    __dmb(0xBu);
    if ( (v18 & v9) == 0 )
    {
      if ( (unsigned __int64)first_zero_bit >= 0x801 )
      {
        __break(0x5512u);
        goto LABEL_35;
      }
      v19 = first_zero_bit;
      raw_spin_lock_bh(sync_dev + 4 * first_zero_bit + 136);
      v7 = v19;
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, const char *, _QWORD))cam_sync_init_row)(
                           *(_QWORD *)(sync_dev + 128),
                           (unsigned int)v19,
                           a2,
                           0) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_create_util",
          83,
          "Error: Unable to init row at idx = %ld",
          v19);
        v18 = sync_dev + 8416;
LABEL_35:
        _X8 = (unsigned __int64 *)(v18 + 8 * v10);
        __asm { PRFM            #0x11, [X8] }
        do
          v35 = __ldxr(_X8);
        while ( __stxr(v35 & ~v9, _X8) );
        put_ref = -22;
LABEL_12:
        v20 = v7;
        goto LABEL_13;
      }
      v20 = v19;
      *a1 = v19;
      if ( a4 )
      {
        v26 = *(_QWORD *)(sync_dev + 128) + 216 * v19;
        *(_DWORD *)(v26 + 208) = *(_DWORD *)(a4 + 4);
        *(_BYTE *)(v26 + 212) = *(_BYTE *)(a4 + 8);
        *(_DWORD *)(v26 + 204) = *(_DWORD *)a4;
        _X10 = (unsigned __int64 *)(v26 + 184);
        __asm { PRFM            #0x11, [X10] }
        do
          v38 = __ldxr(_X10);
        while ( __stxr(v38 | 8, _X10) );
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int8)debug_mdl & 0x80,
            4,
            "cam_sync_create_util",
            103,
            "sync_obj: %s[%d] associated with synx_obj: %d",
            a2,
            *a1,
            *(_DWORD *)(v26 + 204));
          v20 = v19;
        }
      }
      if ( a3 )
      {
        v27 = *(_QWORD *)(sync_dev + 128) + 216 * v20;
        *(_DWORD *)(v27 + 192) = *(_DWORD *)(a3 + 4);
        *(_DWORD *)(v27 + 196) = *(_DWORD *)a3;
        *(_BYTE *)(v27 + 200) = *(_BYTE *)(a3 + 8);
        _X9 = (unsigned __int64 *)(v27 + 184);
        __asm { PRFM            #0x11, [X9] }
        do
          v41 = __ldxr(_X9);
        while ( __stxr(v41 | 4, _X9) );
        if ( *(_BYTE *)(a3 + 8) == 1 )
        {
          put_ref = cam_dma_fence_get_put_ref(1, *(unsigned int *)(v27 + 196));
          if ( put_ref )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              128,
              1,
              "cam_sync_create_util",
              123,
              "Failed to getref on dma fence idx: %u fd: %d sync_obj: %d rc: %d",
              *(_DWORD *)(v27 + 196),
              *(_DWORD *)(v27 + 192),
              *a1,
              put_ref);
          goto LABEL_12;
        }
        put_ref = 0;
        if ( (debug_mdl & 0x80) == 0 || debug_priority )
        {
LABEL_13:
          raw_spin_unlock_bh(sync_dev + 4 * v20 + 136);
          return put_ref;
        }
        v28 = *a1;
        v29 = "sync_obj: %s[%d] associated with dma fence fd: %d";
        v30 = (unsigned __int8)debug_mdl & 0x80;
        v31 = 128;
        v32 = a2;
        v42 = *(_DWORD *)(a3 + 4);
      }
      else
      {
        put_ref = 0;
        if ( (debug_mdl & 0x80) == 0 || debug_priority )
          goto LABEL_13;
        v28 = *a1;
        v29 = "sync_obj: %s[%i]";
        v30 = (unsigned __int8)debug_mdl & 0x80;
        v31 = 132;
        v32 = a2;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int))cam_print_log)(
        3,
        v30,
        4,
        "cam_sync_create_util",
        v31,
        v29,
        v32,
        v28,
        v42);
      v20 = v19;
      put_ref = 0;
      goto LABEL_13;
    }
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    128,
    1,
    "cam_sync_create_util",
    68,
    "Error: Unable to create sync idx = %d sync name = %s reached max!",
    first_zero_bit,
    a2);
  v21 = 0;
  v22 = 0;
  v23 = 136;
  do
  {
    raw_spin_lock_bh(sync_dev + v23);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      3,
      "cam_sync_print_fence_table",
      48,
      "index[%u]: sync_id=%d, name=%s, type=%d, state=%d, ref_cnt=%d",
      v21,
      *(_DWORD *)(*(_QWORD *)(sync_dev + 128) + v22 + 68),
      (const char *)(*(_QWORD *)(sync_dev + 128) + v22),
      *(_DWORD *)(*(_QWORD *)(sync_dev + 128) + v22 + 64),
      *(_DWORD *)(*(_QWORD *)(sync_dev + 128) + v22 + 104),
      *(_DWORD *)(*(_QWORD *)(sync_dev + 128) + v22 + 176));
    raw_spin_unlock_bh(sync_dev + v23);
    v22 += 216;
    v23 += 4;
    ++v21;
  }
  while ( v22 != 442368 );
  return (unsigned int)-12;
}
