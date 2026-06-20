__int64 __fastcall cam_ife_csid_ver1_print_hbi_vbi(__int64 result, unsigned int *a2)
{
  __int64 v2; // x7
  __int64 v3; // x19
  unsigned int v4; // w8
  __int64 v5; // x8
  __int64 *v6; // x8
  __int64 v7; // x20
  __int64 v8; // x22
  int v10; // w0
  __int64 v11; // x8
  int v12; // w19
  int v13; // w20
  __int64 v14; // x0
  const char *v15; // x5
  __int64 v16; // x6
  __int64 v17; // x4

  if ( *a2 != 3 || (v2 = a2[1], (unsigned int)v2 >= 0xC) )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, unsigned int *))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_ife_csid_ver1_print_hbi_vbi",
               3425,
               "CSID[%u] Invalid res_type:%d res [id: %d name: %s]",
               *(unsigned int *)(*(_QWORD *)result + 4LL),
               *a2,
               a2[1],
               a2 + 32);
    return result;
  }
  v3 = *(_QWORD *)(result + 8);
  v4 = *(_DWORD *)(v3 + 92);
  if ( v4 != 1 )
  {
    v15 = "CSID[%u] Invalid dev state :%d";
    v16 = *(unsigned int *)(*(_QWORD *)result + 4LL);
    v17 = 3432;
    v2 = v4;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
             3,
             8,
             1,
             "cam_ife_csid_ver1_print_hbi_vbi",
             v17,
             v15,
             v16,
             v2);
  }
  v5 = **(_QWORD **)(result + 16);
  if ( (unsigned int)v2 >= 5 )
  {
    if ( (_DWORD)v2 == 6 )
    {
      v6 = (__int64 *)(v5 + 16);
    }
    else
    {
      if ( (_DWORD)v2 != 5 )
      {
        v15 = "CSID[%u] invalid res %d";
        v16 = *(unsigned int *)(*(_QWORD *)result + 4LL);
        v17 = 3452;
        return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_ife_csid_ver1_print_hbi_vbi",
                 v17,
                 v15,
                 v16,
                 v2);
      }
      v6 = (__int64 *)(v5 + 8);
    }
  }
  else
  {
    v6 = (__int64 *)(v5 + 8 * v2 + 24);
  }
  v7 = *v6;
  if ( !*v6 )
  {
    v15 = "CSID[%u] invalid res: %d";
    v16 = *(unsigned int *)(*(_QWORD *)result + 4LL);
    v17 = 3458;
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
             3,
             8,
             1,
             "cam_ife_csid_ver1_print_hbi_vbi",
             v17,
             v15,
             v16,
             v2);
  }
  v8 = result;
  v10 = cam_io_r_mb(*(_QWORD *)(v3 + 384) + *(unsigned int *)(v7 + 108));
  v11 = *(_QWORD *)(v3 + 384);
  v12 = v10;
  v13 = cam_io_r_mb(v11 + *(unsigned int *)(v7 + 112));
  if ( (unsigned int)__ratelimit(&cam_ife_csid_ver1_print_hbi_vbi__rs, "cam_ife_csid_ver1_print_hbi_vbi") )
    v14 = 3;
  else
    v14 = 2;
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int *, int, int))cam_print_log)(
           v14,
           8,
           3,
           "cam_ife_csid_ver1_print_hbi_vbi",
           3469,
           "CSID[%u] res[id: %d name: %s] hbi 0x%x vbi 0x%x",
           *(unsigned int *)(*(_QWORD *)v8 + 4LL),
           a2[1],
           a2 + 32,
           v12,
           v13);
}
