__int64 __fastcall cam_isp_blob_bw_update(__int64 a1, __int64 a2)
{
  __int64 *v2; // x26
  int v3; // w19
  int v4; // w27
  unsigned int v5; // w24
  int v6; // w28
  __int64 v7; // x8
  unsigned int v8; // w7
  int v9; // w28
  __int64 *v10; // x9
  __int64 *v11; // x10
  unsigned int v12; // w9
  __int64 v13; // x9
  __int64 v14; // x12
  __int64 (__fastcall *v15)(__int64, __int64, __int64 *, __int64); // x11
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x6
  __int64 v22; // x4
  const char *v23; // x5
  __int64 v24; // x8
  unsigned int v25; // w7
  __int64 *v26; // x9
  __int64 *v27; // x10
  __int64 v28; // x12
  __int64 (__fastcall *v29)(__int64, __int64, __int64 *, __int64); // x11
  __int64 v30; // x10
  __int64 v31; // x9
  __int64 v32; // x0
  __int64 v33; // x1
  __int64 v34; // x2
  __int64 v35; // x6
  __int64 v36; // x4
  const char *v37; // x5
  unsigned int v38; // w9
  __int64 v39; // x9
  __int64 v41; // [xsp+28h] [xbp-48h]
  __int64 v44; // [xsp+50h] [xbp-20h] BYREF
  __int64 v45; // [xsp+58h] [xbp-18h]
  __int64 v46; // [xsp+60h] [xbp-10h]
  __int64 v47; // [xsp+68h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000008,
      4,
      "cam_isp_blob_bw_update",
      7536,
      "ctx_idx: %u ISP_BLOB usage=%u left cam_bw_bps=%llu ext_bw_bps=%llu, right cam_bw_bps=%llu ext_bw_bps=%llu",
      *(_DWORD *)(a2 + 56),
      *(_DWORD *)a1,
      *(_QWORD *)(a1 + 16),
      *(_QWORD *)(a1 + 24),
      *(_QWORD *)(a1 + 40),
      *(_QWORD *)(a1 + 48));
  v2 = *(__int64 **)(a2 + 224);
  if ( v2 == (__int64 *)(a2 + 224) )
    goto LABEL_41;
  v3 = 0;
  v4 = 0;
  v5 = -22;
  v41 = a1 + 56;
  while ( 1 )
  {
    v7 = v2[4];
    if ( !v7 )
      goto LABEL_25;
    v8 = *((_DWORD *)v2 + 5);
    if ( v8 <= 9 && ((1 << v8) & 0x305) != 0 )
    {
      v9 = 1;
      v10 = (__int64 *)(a1 + 24);
      v11 = (__int64 *)(a1 + 16);
      if ( (v4 & 1) != 0 )
      {
        v4 = 1;
        goto LABEL_25;
      }
LABEL_16:
      v14 = *(_QWORD *)(v7 + 16);
      if ( v14 && (v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v14 + 88)) != nullptr )
      {
        v16 = *v11;
        v17 = *v10;
        v18 = *(_QWORD *)(v14 + 112);
        v44 = v2[4];
        v45 = v16;
        v46 = v17;
        if ( *((_DWORD *)v15 - 1) != -1055839300 )
          __break(0x822Bu);
        v5 = v15(v18, 10, &v44, 24);
        if ( !v5 )
          goto LABEL_24;
        v19 = 0x2000000;
        v20 = 1;
        v21 = *(unsigned int *)(a2 + 56);
        v22 = 7604;
        v23 = "BW Update failed, ctx_idx: %u";
      }
      else
      {
        v19 = 8;
        v20 = 2;
        v21 = *(unsigned int *)(a2 + 56);
        v22 = 7606;
        v23 = "NULL hw_intf!ctx_idx: %u";
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v19,
        v20,
        "cam_isp_blob_bw_update",
        v22,
        v23,
        v21);
LABEL_24:
      v4 = v9;
      goto LABEL_25;
    }
    v12 = v8 - 3;
    if ( v8 - 3 > 4 )
      goto LABEL_40;
    if ( v12 < *(_DWORD *)(a1 + 4) )
    {
      v9 = v4;
      v13 = v41 + 24LL * v12;
      v11 = (__int64 *)(v13 + 8);
      v10 = (__int64 *)(v13 + 16);
      goto LABEL_16;
    }
LABEL_25:
    v24 = v2[5];
    if ( !v24 )
      goto LABEL_6;
    v25 = *((_DWORD *)v2 + 5);
    if ( v25 > 9 || ((1 << v25) & 0x305) == 0 )
      break;
    v26 = (__int64 *)(a1 + 48);
    v27 = (__int64 *)(a1 + 40);
    v6 = 1;
    if ( (v3 & 1) == 0 )
    {
      v28 = *(_QWORD *)(v24 + 16);
      if ( !v28 )
        goto LABEL_38;
      goto LABEL_30;
    }
LABEL_7:
    v2 = (__int64 *)*v2;
    v3 = v6;
    if ( v2 == (__int64 *)(a2 + 224) )
      goto LABEL_42;
  }
  v38 = v25 - 3;
  if ( v25 - 3 <= 4 )
  {
    if ( v38 < *(_DWORD *)(a1 + 4) )
    {
      v6 = v3;
      v39 = v41 + 24LL * v38;
      v27 = (__int64 *)(v39 + 8);
      v26 = (__int64 *)(v39 + 16);
      v28 = *(_QWORD *)(v24 + 16);
      if ( !v28 )
      {
LABEL_38:
        v33 = 8;
        v34 = 2;
        v35 = *(unsigned int *)(a2 + 56);
        v36 = 7606;
        v37 = "NULL hw_intf!ctx_idx: %u";
        goto LABEL_39;
      }
LABEL_30:
      v29 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v28 + 88);
      if ( !v29 )
        goto LABEL_38;
      v30 = *v27;
      v31 = *v26;
      v32 = *(_QWORD *)(v28 + 112);
      v44 = v2[5];
      v45 = v30;
      v46 = v31;
      if ( *((_DWORD *)v29 - 1) != -1055839300 )
        __break(0x822Bu);
      v5 = v29(v32, 10, &v44, 24);
      if ( !v5 )
        goto LABEL_7;
      v33 = 0x2000000;
      v34 = 1;
      v35 = *(unsigned int *)(a2 + 56);
      v36 = 7604;
      v37 = "BW Update failed, ctx_idx: %u";
LABEL_39:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v33,
        v34,
        "cam_isp_blob_bw_update",
        v36,
        v37,
        v35);
      goto LABEL_7;
    }
LABEL_6:
    v6 = v3;
    goto LABEL_7;
  }
LABEL_40:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_bw_update",
    7584,
    "Invalid ctx_idx: %u res_id %u",
    *(unsigned int *)(a2 + 56));
LABEL_41:
  v5 = -22;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v5;
}
