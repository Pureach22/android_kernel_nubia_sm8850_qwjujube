__int64 __fastcall cam_isp_blob_csid_clock_update(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x26
  _QWORD *v10; // x22
  unsigned int v11; // w24
  __int64 v12; // x6
  __int64 v13; // x4
  const char *v14; // x5
  __int64 v15; // x8
  __int64 v16; // x27
  __int64 (__fastcall *v17)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v18; // x7
  __int64 v19; // x0
  __int64 v20; // x6
  __int64 v21; // x4
  const char *v22; // x5
  __int64 v23; // x8
  __int64 v24; // x27
  __int64 (__fastcall *v25)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v26; // x7
  __int64 v27; // x0
  __int64 v29; // [xsp+0h] [xbp-10h] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 + 16);
  v29 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_csid_clock_update",
      11003,
      "csid clk=%llu, ctx_idx: %u",
      *a1,
      *(_DWORD *)(v9 + 56));
  v10 = *(_QWORD **)(v9 + 208);
  if ( v10 != (_QWORD *)(v9 + 208) )
  {
    v11 = -22;
    while ( 1 )
    {
      v15 = v10[4];
      if ( !v15 )
        goto LABEL_21;
      v16 = *(_QWORD *)(v15 + 16);
      if ( !v16 )
        break;
      v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v16 + 88);
      if ( !v17 )
        break;
      v18 = *a1;
      v29 = *a1;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_csid_clock_update",
          11014,
          "i= %d clk=%llu\n",
          0,
          v18);
        v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v16 + 88);
      }
      v19 = *(_QWORD *)(v16 + 112);
      if ( *((_DWORD *)v17 - 1) != -1055839300 )
        __break(0x8228u);
      v11 = v17(v19, 21, &v29, 8);
      if ( v11 )
      {
        v20 = *(unsigned int *)(v9 + 56);
        v21 = 11024;
        v22 = "Clock Update failed, ctx_idx: %u";
LABEL_20:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_csid_clock_update",
          v21,
          v22,
          v20);
      }
LABEL_21:
      v23 = v10[5];
      if ( v23 )
      {
        v24 = *(_QWORD *)(v23 + 16);
        if ( v24 && (v25 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v24 + 88)) != nullptr )
        {
          v26 = *a1;
          v29 = *a1;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_isp_blob_csid_clock_update",
              11014,
              "i= %d clk=%llu\n",
              1,
              v26);
            v25 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v24 + 88);
          }
          v27 = *(_QWORD *)(v24 + 112);
          if ( *((_DWORD *)v25 - 1) != -1055839300 )
            __break(0x8228u);
          v11 = v25(v27, 21, &v29, 8);
          if ( !v11 )
            goto LABEL_8;
          v12 = *(unsigned int *)(v9 + 56);
          v13 = 11024;
          v14 = "Clock Update failed, ctx_idx: %u";
        }
        else
        {
          v12 = *(unsigned int *)(v9 + 56);
          v13 = 11026;
          v14 = "NULL hw_intf! ctx_idx: %u";
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_csid_clock_update",
          v13,
          v14,
          v12,
          a8,
          v29,
          v30);
      }
LABEL_8:
      v10 = (_QWORD *)*v10;
      if ( v10 == (_QWORD *)(v9 + 208) )
        goto LABEL_32;
    }
    v20 = *(unsigned int *)(v9 + 56);
    v21 = 11026;
    v22 = "NULL hw_intf! ctx_idx: %u";
    goto LABEL_20;
  }
  v11 = -22;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v11;
}
