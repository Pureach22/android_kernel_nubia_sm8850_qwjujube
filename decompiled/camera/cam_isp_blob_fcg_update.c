__int64 __fastcall cam_isp_blob_fcg_update(__int64 a1, unsigned int a2, unsigned int a3, __int64 **a4, __int64 a5)
{
  __int64 *v5; // x8
  __int64 v6; // x19
  unsigned int v7; // w7
  __int64 v8; // x8
  __int64 v10; // x8
  int v11; // w6
  __int64 v12; // x11
  __int64 v13; // x8
  __int64 (__fastcall *v14)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v15; // x0
  __int64 result; // x0
  unsigned int v17; // w19
  __int64 v18; // [xsp+10h] [xbp-30h] BYREF
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  int v21; // [xsp+28h] [xbp-18h]
  int v22; // [xsp+2Ch] [xbp-14h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v19 = 0;
  if ( v5 == (__int64 *)a4 )
  {
LABEL_18:
    result = 4294967274LL;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_23;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_fcg_update",
      7812,
      "No matching ISP resources when filling FCG hw update entry, request id: %llu",
      *(_QWORD *)(a5 + 48));
LABEL_22:
    result = 4294967274LL;
    goto LABEL_23;
  }
  while ( 1 )
  {
    if ( *((_DWORD *)v5 + 4) )
    {
      v6 = v5[4];
      if ( v6 )
        break;
      v6 = v5[5];
      if ( v6 )
        break;
    }
    v5 = (__int64 *)*v5;
    if ( v5 == (__int64 *)a4 )
      goto LABEL_18;
  }
  v7 = *(_DWORD *)(a5 + 8);
  if ( v7 <= a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_fcg_update",
      7774,
      "Entry index %d exceed number of hw update entries %u, request id %llu",
      a2,
      v7,
      *(_QWORD *)(a5 + 48));
    goto LABEL_22;
  }
  v8 = *(_QWORD *)(a5 + 16);
  v18 = v6;
  v10 = v8 + 32LL * a2;
  LODWORD(v19) = 13;
  if ( *(_DWORD *)(a1 + 4) >= a3 )
    v11 = a3;
  else
    v11 = *(_DWORD *)(a1 + 4);
  v21 = *(_DWORD *)(v10 + 8);
  v12 = *(_QWORD *)(v10 + 16);
  v23 = a1;
  v22 = v11;
  v20 = v12;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_fcg_update",
      7795,
      "Replace FCG config with predicted ones, prediction idx: %d, request id: %llu",
      v11,
      *(_QWORD *)(a5 + 48));
  v13 = *(_QWORD *)(v6 + 16);
  v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v13 + 88);
  v15 = *(_QWORD *)(v13 + 112);
  if ( *((_DWORD *)v14 - 1) != -1055839300 )
    __break(0x8229u);
  result = v14(v15, 13, &v18, 40);
  if ( (_DWORD)result )
  {
    v17 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_fcg_update",
      7803,
      "Failed in writing FCG values to the hw update entry, rc: %d, request id: %llu",
      result,
      *(_QWORD *)(a5 + 48));
    result = v17;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
