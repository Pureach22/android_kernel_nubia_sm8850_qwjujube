__int64 __fastcall cam_ife_csid_ver2_set_discard_frame_cfg(__int64 a1, __int64 a2)
{
  const char *v2; // x5
  __int64 v3; // x6
  __int64 v4; // x4
  __int64 v5; // x7
  unsigned int v6; // w8
  unsigned int *v7; // x9
  __int64 v8; // x8
  unsigned int v16; // w8
  unsigned int v17; // [xsp+0h] [xbp-10h]

  if ( !a1 )
    return (unsigned int)-22;
  if ( *(_DWORD *)a2 )
  {
    if ( *(_DWORD *)a2 == -1 )
    {
      v2 = "CSID[%u] Invalid number of frames: 0x%x";
      v3 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v4 = 8588;
      v5 = 0xFFFFFFFFLL;
LABEL_15:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_set_discard_frame_cfg",
        v4,
        v2,
        v3,
        v5,
        v17);
      return (unsigned int)-22;
    }
    v7 = *(unsigned int **)(a2 + 8);
    v5 = *v7;
    if ( (_DWORD)v5 != 3 || v7[1] >= 0xC )
    {
      v2 = "CSID[%u] Invalid res_type: %d res id: %d";
      v3 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v4 = 8602;
      v17 = v7[1];
      goto LABEL_15;
    }
    if ( (v7[2] & 0xFFFFFFFE) != 2 )
      return 0;
    v8 = *((_QWORD *)v7 + 3);
    if ( (*(_BYTE *)(v8 + 249) & 1) != 0 || (*(_BYTE *)(v8 + 248) & 1) != 0 )
      return 0;
    *(_DWORD *)(v8 + 224) = 0;
    *(_BYTE *)(v8 + 248) = 1;
    *(_DWORD *)(v8 + 228) = *(_DWORD *)a2;
    _X10 = (unsigned int *)(a1 + 32248);
    __asm { PRFM            #0x11, [X10] }
    do
      v16 = __ldxr(_X10);
    while ( __stxr(v16 + 1, _X10) );
    v6 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_set_discard_frame_cfg",
        8622,
        "CSID[%u] discard num of frames: %u for path: %s discard_ref_cnt: %u",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        *(_DWORD *)a2,
        (const char *)v7 + 128,
        *_X10);
      return 0;
    }
  }
  else
  {
    v6 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_set_discard_frame_cfg",
        8593,
        "CSID[%u] No discard requested",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
      return 0;
    }
  }
  return v6;
}
