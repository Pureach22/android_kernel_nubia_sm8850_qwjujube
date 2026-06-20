__int64 __fastcall cam_ife_csid_ver2_rx_err_process_top_half(__int64 a1, unsigned int *a2, unsigned int a3, _DWORD *a4)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x11
  _BYTE *v7; // x8
  unsigned int v8; // w8
  __int64 v9; // x20
  __int64 v10; // x0
  const char *v11; // x5
  __int64 v12; // x6
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x4
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 v18; // x12
  __int64 v19; // x11
  char v21; // w10
  unsigned int v22; // w8
  unsigned int v23; // w7
  __int64 v24; // [xsp+10h] [xbp-20h]
  _DWORD *v25; // [xsp+18h] [xbp-18h]
  _BYTE *v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v4 = a1 + 28672;
  v5 = **(_QWORD **)(a1 + 31136);
  v6 = *(_QWORD *)(v5 + 128);
  v7 = *(_BYTE **)(v5 + 624);
  if ( !*(_DWORD *)(a1 + 32248) )
  {
    if ( *(_BYTE *)(a1 + 2153) == 1 )
    {
      v9 = a1;
      if ( (unsigned int)__ratelimit(
                           &cam_ife_csid_ver2_rx_err_process_top_half__rs,
                           "cam_ife_csid_ver2_rx_err_process_top_half") )
        v10 = 3;
      else
        v10 = 2;
      v11 = "CSID[%u] already handling fatal error";
      v12 = *(unsigned int *)(*(_QWORD *)(v9 + 31120) + 4LL);
      v13 = 8;
      v14 = 3;
      v15 = 1588;
      goto LABEL_10;
    }
    v16 = *a2;
    v17 = a3;
    *a4 = v16;
    if ( *(_DWORD *)(a1 + 2096) )
    {
      if ( (*(_QWORD *)&v7[8 * a3] & 0x800) != 0 )
      {
        v18 = 1LL << v7[27];
        if ( (v18 & v16) != 0 )
        {
          v8 = -19;
          if ( (debug_mdl & 8) == 0 || debug_priority )
            return v8;
          v11 = "CSID[%u] Rcvd Only ERROR_EOT for EPD sensor";
          v13 = debug_mdl & 8;
          v12 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
          v10 = 3;
          v14 = 4;
          v15 = 1598;
LABEL_10:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            v10,
            v13,
            v14,
            "cam_ife_csid_ver2_rx_err_process_top_half",
            v15,
            v11,
            v12);
          return (unsigned int)-19;
        }
      }
      else
      {
        v18 = 1LL << v7[27];
      }
      LODWORD(v16) = v16 & ~(_DWORD)v18;
      *a4 = v16;
    }
    v19 = v6 + 4LL * a3;
    if ( (*(_DWORD *)(v19 + 308) & (unsigned int)v16) != 0 )
      goto LABEL_21;
    if ( (*(_DWORD *)(v19 + 316) & (unsigned int)v16) != 0 )
    {
      if ( (*(_QWORD *)&v7[8 * a3] & 0x1000) != 0 && (((unsigned __int64)(unsigned int)v16 >> v7[28]) & 1) != 0 )
      {
        v21 = debug_mdl;
        ++*(_DWORD *)(a1 + 2136);
        if ( (v21 & 8) != 0 && !debug_priority )
        {
          v26 = v7;
          v27 = a1;
          v24 = a3;
          v25 = a4;
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v21 & 8,
            4,
            "cam_ife_csid_ver2_rx_err_process_top_half",
            1617,
            "CSID[%u] Recoverable Error Count:%u",
            *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
          v17 = v24;
          a4 = v25;
          v7 = v26;
          a1 = v27;
        }
      }
      if ( (v7[8 * v17 + 2] & 8) != 0 && (((unsigned __int64)(unsigned int)*a4 >> v7[35]) & 1) != 0 )
      {
        v22 = *(_DWORD *)(v4 + 3584);
        v23 = *(_DWORD *)(a1 + 2140) + 1;
        *(_DWORD *)(a1 + 2140) = v23;
        if ( v23 > v22 && (debug_mdl & 8) != 0 && !debug_priority )
        {
          v28 = a1;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver2_rx_err_process_top_half",
            1628,
            "CSID[%u] Recoverable CRC Error Count: %u, CRC Error threshold: %u",
            *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
          a1 = v28;
        }
      }
      if ( *(_DWORD *)(a1 + 2136) > 0x64u )
        goto LABEL_21;
      v8 = *(_DWORD *)(a1 + 2140);
      if ( v8 > *(_DWORD *)(v4 + 3584) )
        goto LABEL_21;
      if ( !v8 )
        return v8;
      if ( *(_BYTE *)(a1 + 2215) == 1 )
      {
LABEL_21:
        *(_BYTE *)(a1 + 2153) = 1;
        cam_ife_csid_ver2_stop_csi2_in_err();
      }
    }
    return 0;
  }
  v8 = -19;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_rx_err_process_top_half",
      1581,
      "ignoring rx error (error:0x%x, remaining frames:%d)",
      *a2);
    return (unsigned int)-19;
  }
  return v8;
}
