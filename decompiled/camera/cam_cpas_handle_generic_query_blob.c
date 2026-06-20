__int64 __fastcall cam_cpas_handle_generic_query_blob(__int64 a1, int a2, unsigned int a3, __int64 a4)
{
  _DWORD *v4; // x19
  __int64 result; // x0
  const char *v6; // x5
  __int64 v7; // x6
  __int64 v8; // x4
  __int64 v9; // x7
  int v10; // w19
  unsigned int v11; // w20
  __int64 v12; // x21
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x9
  unsigned __int64 v16; // x10
  _DWORD *v17; // x13
  __int64 v18; // x12
  int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v19 = 0;
  if ( (debug_mdl & 4) == 0 || debug_priority )
  {
    if ( a2 != 52 )
      goto LABEL_4;
LABEL_12:
    if ( a3 <= 0x507 )
    {
      v6 = "Invalid blob size %u, blob_type=%d for sys cache";
      v7 = a3;
      v8 = 1721;
      v9 = 52;
      goto LABEL_21;
    }
    if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_sys_cache_cap_populate",
        1665,
        "cpas intf not initialized");
      result = 4294967277LL;
      goto LABEL_23;
    }
    v13 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL) + 3392LL);
    v14 = *(_DWORD *)(v13 + 1592);
    *(_DWORD *)a4 = v14;
    if ( v14 )
    {
      v15 = 0;
      v16 = 0;
      do
      {
        if ( v16 == 20 )
          __break(0x5512u);
        v17 = (_DWORD *)(a4 + 12 + v15);
        ++v16;
        *v17 = *(_DWORD *)(*(_QWORD *)(v13 + 1600) + v15 + 4);
        v17[1] = *(_DWORD *)(*(_QWORD *)(v13 + 1600) + v15 + 24);
        v18 = *(_QWORD *)(v13 + 1600) + v15;
        v15 += 64;
        v17[2] = *(_DWORD *)(v18 + 60);
      }
      while ( v16 < *(unsigned int *)(v13 + 1592) );
    }
LABEL_9:
    result = 0;
    goto LABEL_23;
  }
  v10 = a2;
  v11 = a3;
  v12 = a4;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 4,
    4,
    "cam_cpas_handle_generic_query_blob",
    1694,
    "blob_type=%d, blob_size=%d",
    a2,
    a3);
  a2 = v10;
  a3 = v11;
  a4 = v12;
  if ( v10 == 52 )
    goto LABEL_12;
LABEL_4:
  if ( a2 != 51 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_handle_generic_query_blob",
      1729,
      "Unknown op code %d for CPAS",
      a2);
    goto LABEL_9;
  }
  if ( a3 < 0x228 )
  {
    v6 = "Invalid blob size %u, blob_type=%d for query cap v3";
    v7 = a3;
    v8 = 1702;
    v9 = 51;
LABEL_21:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_handle_generic_query_blob",
      v8,
      v6,
      v7,
      v9);
    result = 4294967274LL;
    goto LABEL_23;
  }
  v4 = (_DWORD *)a4;
  result = cam_cpas_get_hw_info(
             (_DWORD *)(a4 + 4),
             (_QWORD *)(a4 + 12),
             (_QWORD *)(a4 + 28),
             v20,
             &v19,
             v4 + 11,
             v4 + 76);
  if ( !(_DWORD)result )
    v4[2] = *(_DWORD *)v20[0];
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
