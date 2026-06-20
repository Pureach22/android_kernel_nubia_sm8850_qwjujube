__int64 __fastcall cam_isp_blob_fe_update(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x24
  _QWORD *v10; // x25
  unsigned int v11; // w20
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
  __int64 v23; // x10
  __int64 v24; // x6
  __int64 v25; // x2
  __int64 v26; // x4
  const char *v27; // x5
  __int64 v28; // x10
  __int64 v29; // x9
  __int64 (__fastcall *v30)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v31; // x10
  __int64 v32; // x0
  __int64 v33; // x10
  __int64 v34; // x10
  __int64 v35; // x10
  __int64 *i; // x26
  __int64 v37; // x6
  __int64 v38; // x2
  __int64 v39; // x4
  const char *v40; // x5
  __int64 v41; // x10
  __int64 v42; // x9
  __int64 (__fastcall *v43)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v44; // x10
  __int64 v45; // x0
  __int64 v46; // x10
  __int64 v47; // x10
  __int64 v48; // x10
  __int64 v49; // x6
  __int64 v50; // x2
  __int64 v51; // x4
  const char *v52; // x5
  __int64 v53; // x10
  __int64 v54; // x9
  __int64 (__fastcall *v55)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v56; // x10
  __int64 v57; // x0
  __int64 v58; // x10
  __int64 v59; // x10
  __int64 v60; // x10
  __int64 v62; // [xsp+0h] [xbp-50h] BYREF
  __int64 v63; // [xsp+8h] [xbp-48h]
  __int64 v64; // [xsp+10h] [xbp-40h]
  __int64 v65; // [xsp+18h] [xbp-38h]
  __int64 v66; // [xsp+20h] [xbp-30h]
  __int64 v67; // [xsp+28h] [xbp-28h]
  __int64 v68; // [xsp+30h] [xbp-20h]
  __int64 v69; // [xsp+38h] [xbp-18h]
  __int64 v70; // [xsp+40h] [xbp-10h]
  __int64 v71; // [xsp+48h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 + 16);
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v10 = *(_QWORD **)(v9 + 256);
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v62 = 0;
  if ( v10 != (_QWORD *)(v9 + 256) )
  {
    v11 = -22;
    while ( 1 )
    {
      v16 = v10[4];
      if ( !v16 )
        goto LABEL_15;
      v17 = *(_QWORD *)(v16 + 16);
      if ( !v17 )
        break;
      v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v17 + 88);
      if ( !v18 )
        break;
      v62 = v10[4];
      v19 = a1[5];
      v20 = *(_QWORD *)(v17 + 112);
      v67 = a1[4];
      v68 = v19;
      v21 = a1[7];
      v69 = a1[6];
      v70 = v21;
      v22 = a1[1];
      v63 = *a1;
      v64 = v22;
      v23 = a1[3];
      v65 = a1[2];
      v66 = v23;
      if ( *((_DWORD *)v18 - 1) != -1055839300 )
        __break(0x8228u);
      v11 = v18(v20, 23, &v62, 64);
      if ( v11 )
      {
        v24 = *(unsigned int *)(v9 + 56);
        v25 = 1;
        v26 = 9490;
        v27 = "fs Update failed, ctx_idx: %u";
LABEL_14:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          v25,
          "cam_isp_blob_fe_update",
          v26,
          v27,
          v24);
      }
LABEL_15:
      v28 = v10[5];
      if ( v28 )
      {
        v29 = *(_QWORD *)(v28 + 16);
        if ( v29 && (v30 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v29 + 88)) != nullptr )
        {
          v62 = v10[5];
          v31 = a1[5];
          v32 = *(_QWORD *)(v29 + 112);
          v67 = a1[4];
          v68 = v31;
          v33 = a1[7];
          v69 = a1[6];
          v70 = v33;
          v34 = a1[1];
          v63 = *a1;
          v64 = v34;
          v35 = a1[3];
          v65 = a1[2];
          v66 = v35;
          if ( *((_DWORD *)v30 - 1) != -1055839300 )
            __break(0x8228u);
          v11 = v30(v32, 23, &v62, 64);
          if ( !v11 )
            goto LABEL_5;
          v12 = *(unsigned int *)(v9 + 56);
          v13 = 1;
          v14 = 9490;
          v15 = "fs Update failed, ctx_idx: %u";
        }
        else
        {
          v12 = *(unsigned int *)(v9 + 56);
          v13 = 2;
          v14 = 9492;
          v15 = "NULL hw_intf! ctx_idx: %u";
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
          3,
          8,
          v13,
          "cam_isp_blob_fe_update",
          v14,
          v15,
          v12,
          a8,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71);
      }
LABEL_5:
      v10 = (_QWORD *)*v10;
      if ( v10 == (_QWORD *)(v9 + 256) )
        goto LABEL_23;
    }
    v24 = *(unsigned int *)(v9 + 56);
    v25 = 2;
    v26 = 9492;
    v27 = "NULL hw_intf! ctx_idx: %u";
    goto LABEL_14;
  }
  v11 = -22;
LABEL_23:
  for ( i = *(__int64 **)(v9 + 224); i != (__int64 *)(v9 + 224); i = (__int64 *)*i )
  {
    v41 = i[4];
    if ( v41 && *((_DWORD *)i + 5) == 2 )
    {
      v42 = *(_QWORD *)(v41 + 16);
      if ( !v42 || (v43 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v42 + 88)) == nullptr )
      {
        v49 = *(unsigned int *)(v9 + 56);
        v50 = 2;
        v51 = 9522;
        v52 = "NULL hw_intf! ctx_idx: %u";
        goto LABEL_37;
      }
      v62 = i[4];
      v44 = a1[5];
      v45 = *(_QWORD *)(v42 + 112);
      v67 = a1[4];
      v68 = v44;
      v46 = a1[7];
      v69 = a1[6];
      v70 = v46;
      v47 = a1[1];
      v63 = *a1;
      v64 = v47;
      v48 = a1[3];
      v65 = a1[2];
      v66 = v48;
      if ( *((_DWORD *)v43 - 1) != -1055839300 )
        __break(0x8228u);
      v11 = v43(v45, 22, &v62, 72);
      if ( v11 )
      {
        v49 = *(unsigned int *)(v9 + 56);
        v50 = 1;
        v51 = 9520;
        v52 = "fe Update failed, ctx_idx: %u";
LABEL_37:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          v50,
          "cam_isp_blob_fe_update",
          v51,
          v52,
          v49);
      }
    }
    v53 = i[5];
    if ( v53 && *((_DWORD *)i + 5) == 2 )
    {
      v54 = *(_QWORD *)(v53 + 16);
      if ( v54 && (v55 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v54 + 88)) != nullptr )
      {
        v62 = i[5];
        v56 = a1[5];
        v57 = *(_QWORD *)(v54 + 112);
        v67 = a1[4];
        v68 = v56;
        v58 = a1[7];
        v69 = a1[6];
        v70 = v58;
        v59 = a1[1];
        v63 = *a1;
        v64 = v59;
        v60 = a1[3];
        v65 = a1[2];
        v66 = v60;
        if ( *((_DWORD *)v55 - 1) != -1055839300 )
          __break(0x8228u);
        v11 = v55(v57, 22, &v62, 72);
        if ( !v11 )
          continue;
        v37 = *(unsigned int *)(v9 + 56);
        v38 = 1;
        v39 = 9520;
        v40 = "fe Update failed, ctx_idx: %u";
      }
      else
      {
        v37 = *(unsigned int *)(v9 + 56);
        v38 = 2;
        v39 = 9522;
        v40 = "NULL hw_intf! ctx_idx: %u";
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        v38,
        "cam_isp_blob_fe_update",
        v39,
        v40,
        v37);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
