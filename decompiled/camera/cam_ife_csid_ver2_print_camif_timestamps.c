__int64 __fastcall cam_ife_csid_ver2_print_camif_timestamps(__int64 result, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x23
  __int64 v4; // x24
  unsigned int v5; // w10
  int v6; // w10
  __int64 v7; // x7
  __int64 v8; // x9
  int v9; // w21
  __int64 v11; // x25
  int v12; // w26
  int v13; // w28
  __int64 v14; // x27
  unsigned int v15; // w19
  unsigned int v16; // w0
  int v17; // w8
  unsigned __int64 v18; // x21
  __int64 v19; // x0
  int v20; // w25
  __int64 v21; // x22
  int v22; // w26
  int v23; // w21
  __int64 v24; // x27
  unsigned int v25; // w19
  unsigned int v26; // w0
  int v27; // w8
  int v28; // w25
  int v29; // w24
  __int64 v30; // x23
  int v31; // w22
  unsigned __int64 v32; // x26
  __int64 v33; // x27
  unsigned int v34; // w19
  unsigned int v35; // w0
  int v36; // w8
  unsigned __int64 v37; // x22
  unsigned __int64 v38; // x21
  __int64 v39; // x0
  __int64 v40; // [xsp+30h] [xbp-30h]
  __int64 v41; // [xsp+38h] [xbp-28h]
  _DWORD *v42; // [xsp+40h] [xbp-20h]
  char v43; // [xsp+4Ch] [xbp-14h]
  __int64 v44; // [xsp+50h] [xbp-10h]
  __int64 v45; // [xsp+58h] [xbp-8h]

  v2 = 0;
  v3 = **(_QWORD **)(result + 31136);
  while ( 1 )
  {
    v4 = *(_QWORD *)(result + v2 + 24);
    if ( !v4 )
      goto LABEL_2;
    if ( !*(_DWORD *)(v4 + 208) )
      goto LABEL_2;
    v5 = *(_DWORD *)(result + v2 + 4);
    if ( v5 > 0xB )
      goto LABEL_2;
    v6 = 1 << v5;
    if ( (v6 & 0x1F) == 0 )
      break;
    if ( *(_BYTE *)(v4 + 253) == 1 && (*(_BYTE *)(result + v2 + 144) & 1) != 0 )
      goto LABEL_12;
LABEL_2:
    v2 += 152;
    if ( v2 == 1824 )
      return result;
  }
  if ( (v6 & 0xC20) == 0 || (*(_BYTE *)(v4 + 253) & 1) == 0 )
    goto LABEL_2;
LABEL_12:
  v7 = *(unsigned int *)(result + v2 + 4);
  if ( (unsigned int)v7 > 0xB )
  {
    __break(0x5512u);
    return cam_ife_csid_ver2_read_debug_err_vectors(result);
  }
  else
  {
    v8 = *(_QWORD *)(v3 + 8 * v7 + 136);
    if ( v8 )
    {
      v9 = *(_DWORD *)(v8 + 316);
      v11 = *(_QWORD *)(*(_QWORD *)(result + 31128) + 384LL);
      v44 = *(_QWORD *)(result + 31128);
      v45 = result;
      v41 = *(_QWORD *)(v3 + 8 * v7 + 136);
      v42 = *(_DWORD **)(v4 + 264);
      v12 = *(unsigned __int8 *)(v4 + 254);
      v13 = *(_DWORD *)(*(_QWORD *)(v3 + 120) + 696LL);
      v14 = (unsigned int)(v42[49] + v9);
      v15 = cam_io_r_mb(v11 + (unsigned int)(v42[50] + v9));
      v16 = cam_io_r_mb(v11 + v14);
      v17 = ~v13;
      if ( !(v9 + v12) )
        v17 = -1;
      v43 = a2;
      v18 = g_ref_time
          - qword_394728
          + (((((10000 * (unsigned __int64)(v17 & v16)) >> 32) + 10000LL * v15) / 0xC0) << 32)
          + (unsigned int)((unsigned __int64)((((10000LL * (v17 & v16)) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(v17 & v16)) >> 32) + 10000LL * v15)
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      if ( (a2 & 1) != 0 )
      {
        if ( (unsigned int)__ratelimit(
                             &cam_ife_csid_ver2_print_camif_timestamps__rs,
                             "cam_ife_csid_ver2_print_camif_timestamps") )
          v19 = 3;
        else
          v19 = 2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
          v19,
          8,
          3,
          "cam_ife_csid_ver2_print_camif_timestamps",
          353,
          "CSID[%u] %s boot time current SOF[%lld:%09lld] EPOCH[%lld:%09lld] EOF[%lld:%09lld]",
          *(unsigned int *)(*(_QWORD *)(v45 + 31120) + 4LL),
          v45 + v2 + 128,
          v18 / 0x3B9ACA00,
          v18 % 0x3B9ACA00,
          *(_QWORD *)(v4 + 16),
          *(_QWORD *)(v4 + 24),
          *(_QWORD *)(v4 + 32),
          *(_QWORD *)(v4 + 40));
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
          3,
          8,
          3,
          "cam_ife_csid_ver2_print_camif_timestamps",
          363,
          "CSID[%u] %s boot time current SOF[%lld:%09lld] EPOCH[%lld:%09lld] EOF[%lld:%09lld]",
          *(unsigned int *)(*(_QWORD *)(v45 + 31120) + 4LL),
          v45 + v2 + 128,
          v18 / 0x3B9ACA00,
          v18 % 0x3B9ACA00,
          *(_QWORD *)(v4 + 16),
          *(_QWORD *)(v4 + 24),
          *(_QWORD *)(v4 + 32),
          *(_QWORD *)(v4 + 40));
      }
      v40 = v3;
      v20 = *(unsigned __int8 *)(v4 + 254);
      v21 = *(_QWORD *)(v44 + 384);
      v22 = *(_DWORD *)(*(_QWORD *)(v3 + 120) + 696LL);
      v23 = *(_DWORD *)(v41 + 316);
      v24 = (unsigned int)(v42[51] + v23);
      v25 = cam_io_r_mb(v21 + (unsigned int)(v42[52] + v23));
      v26 = cam_io_r_mb(v21 + v24);
      v27 = ~v22;
      if ( !(v23 + v20) )
        v27 = -1;
      v28 = *(_DWORD *)(v41 + 316);
      v29 = *(unsigned __int8 *)(v4 + 254);
      v30 = *(_QWORD *)(v44 + 384);
      v31 = *(_DWORD *)(*(_QWORD *)(v40 + 120) + 696LL);
      v32 = (((((10000 * (unsigned __int64)(v27 & v26)) >> 32) + 10000LL * v25) / 0xC0) << 32)
          | (unsigned int)((unsigned __int64)((((10000LL * (v27 & v26)) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(v27 & v26)) >> 32) + 10000LL * v25)
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      v33 = (unsigned int)(v42[55] + v28);
      v34 = cam_io_r_mb(v30 + (unsigned int)(v42[56] + v28));
      v35 = cam_io_r_mb(v30 + v33);
      v36 = ~v31;
      if ( !(v28 + v29) )
        v36 = -1;
      v37 = v32 + g_ref_time - qword_394728;
      v38 = g_ref_time
          - qword_394728
          + (((((10000 * (unsigned __int64)(v36 & v35)) >> 32) + 10000LL * v34) / 0xC0) << 32)
          + (unsigned int)((unsigned __int64)((((10000LL * (v36 & v35)) & 0xFFFFFFC0LL
                                              | (((((10000 * (unsigned __int64)(v36 & v35)) >> 32) + 10000LL * v34)
                                                % 0xC0) << 32))
                                             * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5);
      if ( (v43 & 1) != 0 )
      {
        if ( (unsigned int)__ratelimit(
                             &cam_ife_csid_ver2_print_camif_timestamps__rs_183,
                             "cam_ife_csid_ver2_print_camif_timestamps") )
          v39 = 3;
        else
          v39 = 2;
        return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))cam_print_log)(
                 v39,
                 8,
                 3,
                 "cam_ife_csid_ver2_print_camif_timestamps",
                 386,
                 "CSID[%u] %s boot time previous SOF[%lld:%09lld] EOF[%lld:%09lld]",
                 *(unsigned int *)(*(_QWORD *)(v45 + 31120) + 4LL),
                 v45 + v2 + 128,
                 v37 / 0x3B9ACA00,
                 v37 % 0x3B9ACA00,
                 v38 / 0x3B9ACA00,
                 v38 % 0x3B9ACA00);
      }
      else
      {
        return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))cam_print_log)(
                 3,
                 8,
                 3,
                 "cam_ife_csid_ver2_print_camif_timestamps",
                 392,
                 "CSID[%u] %s boot time previous SOF[%lld:%09lld] EOF[%lld:%09lld]",
                 *(unsigned int *)(*(_QWORD *)(v45 + 31120) + 4LL),
                 v45 + v2 + 128,
                 v37 / 0x3B9ACA00,
                 v37 % 0x3B9ACA00,
                 v38 / 0x3B9ACA00,
                 v38 % 0x3B9ACA00);
      }
    }
    else
    {
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_csid_ver2_print_camif_timestamps",
               330,
               "CSID:%d no path registers for res :%d",
               *(unsigned int *)(*(_QWORD *)(result + 31120) + 4LL));
    }
  }
}
