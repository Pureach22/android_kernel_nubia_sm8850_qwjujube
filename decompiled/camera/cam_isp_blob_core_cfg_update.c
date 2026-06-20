__int64 __fastcall cam_isp_blob_core_cfg_update(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x24
  __int64 *v9; // x26
  unsigned int v11; // w23
  __int64 v12; // x6
  __int64 v13; // x2
  __int64 v14; // x4
  const char *v15; // x5
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 (__fastcall *v18)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v19; // x10
  __int64 v20; // x0
  __int64 v21; // x10
  __int64 v22; // x10
  __int64 v23; // x6
  __int64 v24; // x2
  __int64 v25; // x4
  const char *v26; // x5
  __int64 v27; // x10
  __int64 v28; // x9
  __int64 (__fastcall *v29)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v30; // x10
  __int64 v31; // x0
  __int64 v32; // x10
  __int64 v33; // x10
  __int64 v35; // [xsp+0h] [xbp-40h] BYREF
  __int64 v36; // [xsp+8h] [xbp-38h]
  __int64 v37; // [xsp+10h] [xbp-30h]
  __int64 v38; // [xsp+18h] [xbp-28h]
  __int64 v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  __int64 v41; // [xsp+30h] [xbp-10h]
  __int64 v42; // [xsp+38h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 16);
  v9 = *(__int64 **)(v8 + 224);
  if ( v9 != (__int64 *)(v8 + 224) )
  {
    v11 = 0;
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v35 = 0;
    while ( 1 )
    {
      v16 = v9[4];
      if ( v16 && (*((_DWORD *)v9 + 5) | 8) == 8 )
      {
        v17 = *(_QWORD *)(v16 + 16);
        if ( !v17 || (v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v17 + 88)) == nullptr )
        {
          v23 = *(unsigned int *)(v8 + 56);
          v24 = 2;
          v25 = 11131;
          v26 = "NULL hw_intf! ctx_idx: %u";
          goto LABEL_15;
        }
        v35 = v9[4];
        v19 = a1[3];
        v20 = *(_QWORD *)(v17 + 112);
        v38 = a1[2];
        v39 = v19;
        v21 = a1[5];
        v40 = a1[4];
        v41 = v21;
        v22 = a1[1];
        v36 = *a1;
        v37 = v22;
        if ( *((_DWORD *)v18 - 1) != -1055839300 )
          __break(0x8228u);
        v11 = v18(v20, 25, &v35, 56);
        if ( v11 )
        {
          v23 = *(unsigned int *)(v8 + 56);
          v24 = 1;
          v25 = 11128;
          v26 = "Core cfg parse fail, ctx_idx: %u";
LABEL_15:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            v24,
            "cam_isp_blob_core_cfg_update",
            v25,
            v26,
            v23);
        }
      }
      v27 = v9[5];
      if ( v27 && (*((_DWORD *)v9 + 5) | 8) == 8 )
      {
        v28 = *(_QWORD *)(v27 + 16);
        if ( v28 && (v29 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v28 + 88)) != nullptr )
        {
          v35 = v9[5];
          v30 = a1[3];
          v31 = *(_QWORD *)(v28 + 112);
          v38 = a1[2];
          v39 = v30;
          v32 = a1[5];
          v40 = a1[4];
          v41 = v32;
          v33 = a1[1];
          v36 = *a1;
          v37 = v33;
          if ( *((_DWORD *)v29 - 1) != -1055839300 )
            __break(0x8228u);
          v11 = v29(v31, 25, &v35, 56);
          if ( !v11 )
            goto LABEL_5;
          v12 = *(unsigned int *)(v8 + 56);
          v13 = 1;
          v14 = 11128;
          v15 = "Core cfg parse fail, ctx_idx: %u";
        }
        else
        {
          v12 = *(unsigned int *)(v8 + 56);
          v13 = 2;
          v14 = 11131;
          v15 = "NULL hw_intf! ctx_idx: %u";
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
          3,
          8,
          v13,
          "cam_isp_blob_core_cfg_update",
          v14,
          v15,
          v12,
          a8,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42);
      }
LABEL_5:
      v9 = (__int64 *)*v9;
      if ( v9 == (__int64 *)(v8 + 224) )
        goto LABEL_25;
    }
  }
  v11 = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v11;
}
