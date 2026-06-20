__int64 __fastcall cam_isp_blob_csid_qcfa_update(int *a1, __int64 a2)
{
  __int64 v3; // x26
  __int64 *v4; // x22
  unsigned int v5; // w24
  __int64 v6; // x6
  __int64 v7; // x4
  const char *v8; // x5
  __int64 v9; // x9
  __int64 v10; // x27
  __int64 (__fastcall *v11)(__int64, __int64, __int64 *, __int64); // x8
  int v12; // w7
  __int64 v13; // x0
  __int64 v14; // x6
  __int64 v15; // x4
  const char *v16; // x5
  __int64 v17; // x8
  __int64 v18; // x27
  __int64 (__fastcall *v19)(__int64, __int64, __int64 *, __int64); // x8
  int v20; // w7
  __int64 v21; // x0
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 16);
  v23 = 0;
  v24 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_csid_qcfa_update",
      11049,
      "csid binning=%d, ctx_idx: %u",
      *a1,
      *(_DWORD *)(v3 + 56));
  v4 = *(__int64 **)(v3 + 208);
  if ( v4 != (__int64 *)(v3 + 208) )
  {
    v5 = -22;
    while ( 1 )
    {
      v9 = v4[4];
      if ( v9 && *((_DWORD *)v4 + 5) == 5 )
      {
        v10 = *(_QWORD *)(v9 + 16);
        if ( !v10 || (v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v10 + 88)) == nullptr )
        {
          v14 = *(unsigned int *)(v3 + 56);
          v15 = 11078;
          v16 = "NULL hw_intf! ctx_idx: %u";
          goto LABEL_21;
        }
        v12 = *a1;
        v23 = v4[4];
        LODWORD(v24) = v12;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_blob_csid_qcfa_update",
            11066,
            "i= %d QCFA binning=%d\n ctx_idx: %u",
            0,
            v12,
            *(_DWORD *)(v3 + 56));
          v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v10 + 88);
        }
        v13 = *(_QWORD *)(v10 + 112);
        if ( *((_DWORD *)v11 - 1) != -1055839300 )
          __break(0x8228u);
        v5 = v11(v13, 27, &v23, 16);
        if ( v5 )
        {
          v14 = *(unsigned int *)(v3 + 56);
          v15 = 11076;
          v16 = "QCFA Update failed, ctx_idx: %u";
LABEL_21:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_csid_qcfa_update",
            v15,
            v16,
            v14);
        }
      }
      v17 = v4[5];
      if ( v17 && *((_DWORD *)v4 + 5) == 5 )
      {
        v18 = *(_QWORD *)(v17 + 16);
        if ( v18 && (v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v18 + 88)) != nullptr )
        {
          v20 = *a1;
          LODWORD(v24) = *a1;
          v23 = v4[5];
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_isp_blob_csid_qcfa_update",
              11066,
              "i= %d QCFA binning=%d\n ctx_idx: %u",
              1,
              v20,
              *(_DWORD *)(v3 + 56));
            v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v18 + 88);
          }
          v21 = *(_QWORD *)(v18 + 112);
          if ( *((_DWORD *)v19 - 1) != -1055839300 )
            __break(0x8228u);
          v5 = v19(v21, 27, &v23, 16);
          if ( !v5 )
            goto LABEL_8;
          v6 = *(unsigned int *)(v3 + 56);
          v7 = 11076;
          v8 = "QCFA Update failed, ctx_idx: %u";
        }
        else
        {
          v6 = *(unsigned int *)(v3 + 56);
          v7 = 11078;
          v8 = "NULL hw_intf! ctx_idx: %u";
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_csid_qcfa_update",
          v7,
          v8,
          v6);
      }
LABEL_8:
      v4 = (__int64 *)*v4;
      if ( v4 == (__int64 *)(v3 + 208) )
        goto LABEL_34;
    }
  }
  v5 = -22;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v5;
}
