__int64 __fastcall cam_isp_blob_ubwc_update_v3(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x28
  __int64 v7; // x23
  unsigned __int64 v8; // x24
  __int64 result; // x0
  int v10; // w22
  _DWORD *v11; // x26
  int v12; // w27
  unsigned int v13; // w9
  __int64 v14; // x8
  __int64 v15; // x10
  unsigned int *v16; // x8
  __int64 v17; // x7
  __int64 v18; // x6
  __int64 *v19; // x11
  unsigned __int64 v20; // x12
  __int64 **v21; // x11
  __int64 v22; // x1
  __int64 v23; // x11
  __int64 v24; // x10
  int v25; // w11
  unsigned int v26; // w12
  unsigned int v27; // w5
  int v28; // w13
  __int64 v29; // x14
  __int64 v30; // x12
  int v31; // w13
  __int64 v32; // x14
  unsigned int v33; // w13
  unsigned int v34; // w15
  __int64 v35; // x14
  int v36; // w13
  __int64 v37; // x14
  int v38; // w13
  int v39; // w13
  int v40; // w9
  int v41; // w9
  int v42; // w9
  int v43; // w9
  int v44; // w9
  int v45; // w9
  int v46; // w9
  __int64 v47; // x8
  const char *v48; // x5
  __int64 v49; // x4
  const char *v50; // x5
  unsigned int v51; // w19
  __int64 v52; // x4
  unsigned int v53; // w21
  char v54; // w4
  int v55; // [xsp+0h] [xbp-C0h]
  int v56; // [xsp+8h] [xbp-B8h]
  unsigned int v57; // [xsp+10h] [xbp-B0h]
  unsigned int v58; // [xsp+14h] [xbp-ACh] BYREF
  __int64 v59; // [xsp+18h] [xbp-A8h] BYREF
  __int128 v60; // [xsp+20h] [xbp-A0h]
  __int64 v61; // [xsp+30h] [xbp-90h]
  __int64 v62; // [xsp+38h] [xbp-88h]
  unsigned __int64 v63; // [xsp+40h] [xbp-80h]
  __int64 v64; // [xsp+48h] [xbp-78h]
  __int128 v65; // [xsp+50h] [xbp-70h]
  __int128 v66; // [xsp+60h] [xbp-60h]
  __int64 v67; // [xsp+70h] [xbp-50h]
  __int64 v68; // [xsp+78h] [xbp-48h]
  __int64 v69; // [xsp+80h] [xbp-40h]
  __int64 v70; // [xsp+88h] [xbp-38h]
  __int64 v71; // [xsp+90h] [xbp-30h]
  __int64 v72; // [xsp+98h] [xbp-28h]
  __int64 v73; // [xsp+A0h] [xbp-20h]
  int v74; // [xsp+A8h] [xbp-18h]
  __int64 v75; // [xsp+B0h] [xbp-10h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 16);
  v58 = 0;
  v74 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v67 = 0;
  v66 = 0u;
  v64 = 0;
  v65 = 0u;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  v59 = 0;
  v60 = 0u;
  if ( !v3 )
  {
    v48 = "Invalid ctx";
    v49 = 9914;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_ubwc_update_v3",
      v49,
      v48);
    result = 4294967274LL;
    goto LABEL_51;
  }
  if ( (unsigned int)(*(_DWORD *)(a3 + 40) + 1) >= *(_DWORD *)(a3 + 24) )
  {
    v48 = "Insufficient HW entries :%d max:%d, ctx_idx: %u";
    v49 = 9923;
    goto LABEL_34;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_ubwc_update_v3",
      9928,
      "ctx_idx: %u num_ports= %d",
      *(_DWORD *)(v3 + 56),
      a2[1]);
    if ( a2[1] )
      goto LABEL_6;
  }
  else if ( a2[1] )
  {
LABEL_6:
    v7 = *(_QWORD *)(a1 + 16);
    v8 = 0;
    result = 0;
    v10 = 0;
    v11 = a2 + 28;
    while ( 1 )
    {
      v12 = *(v11 - 26);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v57 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_ubwc_update_v3",
          9936,
          "UBWC config idx %d, port_type=%d ctx_idx: %u",
          v8,
          v12,
          *(_DWORD *)(v3 + 56));
        result = v57;
      }
      if ( (unsigned __int8)v12 >= (unsigned int)max_ife_out_res )
      {
        v48 = "Invalid port type:0x%x ctx_idx: %u";
        v49 = 9940;
        goto LABEL_34;
      }
      v13 = *(v11 - 9);
      if ( v13 >= 8 )
      {
        v48 = "Invalid hw ctxt port:0x%x ctx_idx: %u hw_ctxt_mask: 0x%x";
        v49 = 9948;
        goto LABEL_34;
      }
      v14 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8496) + (unsigned __int8)v12);
      if ( v14 == 255 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update_v3",
          9954,
          "Invalid index:%d for out_map",
          (unsigned __int8)v12);
        result = 4294967274LL;
        goto LABEL_51;
      }
      v15 = *(_QWORD *)(v3 + 272) + (v14 << 7);
      if ( !v15 )
      {
        v48 = "Invalid hw_mgr_res";
        v49 = 9961;
        goto LABEL_34;
      }
      v16 = *(unsigned int **)(a1 + 8);
      v17 = v16[2];
      v18 = *v16;
      if ( (_DWORD)v17 == 7 )
        break;
      if ( (_DWORD)v17 == 2 )
      {
        if ( (unsigned int)v18 > 7 )
          goto LABEL_52;
        v20 = 8 * v18 + 160;
        v21 = (__int64 **)((char *)g_ife_hw_mgr + v20);
LABEL_23:
        if ( v20 > 0x13FD8 )
        {
          __break(1u);
          return cam_isp_blob_csid_clock_update(result);
        }
        v19 = *v21;
        goto LABEL_25;
      }
      if ( (_DWORD)v17 )
        goto LABEL_36;
      if ( (unsigned int)v18 >= 8 )
LABEL_52:
        __break(0x5512u);
      v19 = &g_ife_hw_mgr[v18 + 12];
LABEL_25:
      v22 = *v19;
      if ( !*v19 || (v23 = v16[1], (unsigned int)v23 >= 2) )
      {
LABEL_36:
        v50 = "Invalid base %u type %u";
        v51 = result;
        v52 = 9971;
LABEL_43:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update_v3",
          v52,
          v50,
          v18,
          v17,
          v55,
          v56);
        result = v51;
        goto LABEL_51;
      }
      v24 = v15 + 32;
      if ( !*(_QWORD *)(v24 + 8 * v23) )
        goto LABEL_51;
      v26 = *(_DWORD *)(v7 + 20);
      v25 = *(_DWORD *)(v7 + 24);
      v27 = v26 - (v25 + v10);
      if ( v26 <= v25 + v10 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update_v3",
          9987,
          "no free kmd memory for base=%d bytes_used=%u buf_size=%u ctx_idx: %u",
          v18,
          v58,
          v26,
          *(_DWORD *)(v3 + 56));
        result = 4294967284LL;
        goto LABEL_51;
      }
      v28 = *(v11 - 25);
      v29 = *((_QWORD *)v11 - 12);
      v30 = *(_QWORD *)(v7 + 8);
      HIDWORD(v59) = *(v11 - 26);
      LODWORD(v60) = v28;
      v31 = *(v11 - 22);
      *(_QWORD *)((char *)&v60 + 4) = v29;
      v32 = *(_QWORD *)(v11 - 21);
      HIDWORD(v60) = v31;
      v61 = v32;
      LODWORD(v32) = *(v11 - 18);
      LODWORD(v62) = *(v11 - 19);
      HIDWORD(v62) = v32;
      v34 = *(v11 - 17);
      v33 = *(v11 - 16);
      v64 = *(_QWORD *)(v11 - 15);
      v35 = *((_QWORD *)v11 - 6);
      v63 = __PAIR64__(v33, v34);
      v36 = *(v11 - 13);
      *(_QWORD *)((char *)&v65 + 4) = v35;
      v37 = *(_QWORD *)v11;
      LODWORD(v65) = v36;
      v38 = *(v11 - 10);
      *(_QWORD *)((char *)&v66 + 4) = v37;
      HIDWORD(v65) = v38;
      LODWORD(v66) = v13;
      v39 = v11[3];
      HIDWORD(v66) = v11[2];
      LODWORD(v67) = v39;
      v40 = v11[5];
      HIDWORD(v67) = v11[4];
      LODWORD(v68) = v40;
      v41 = v11[7];
      HIDWORD(v68) = v11[6];
      LODWORD(v69) = v41;
      v42 = v11[9];
      HIDWORD(v69) = v11[8];
      LODWORD(v70) = v42;
      v43 = v11[11];
      HIDWORD(v70) = v11[10];
      LODWORD(v71) = v43;
      v44 = v11[13];
      HIDWORD(v71) = v11[12];
      LODWORD(v72) = v44;
      v45 = v11[15];
      HIDWORD(v72) = v11[14];
      LODWORD(v73) = v45;
      v46 = v11[17];
      HIDWORD(v73) = v11[16];
      v74 = v46;
      v47 = v16[1];
      LODWORD(v59) = *a2;
      if ( (unsigned int)v47 >= 2 )
        goto LABEL_52;
      result = cam_isp_add_cmd_buf_update(
                 *(_QWORD *)(v24 + 8 * v47),
                 v22,
                 34,
                 0x50u,
                 (const void *)(v30 + (v10 & 0xFFFFFFFC) + (v25 & 0xFFFFFFFC)),
                 v27,
                 (__int64)&v59,
                 &v58);
      if ( (result & 0x80000000) != 0 )
      {
        v17 = v58;
        v50 = "Failed cmd_update, base_idx=%d, bytes_used=%u, res_id_out=0x%X, ctx_idx: %u";
        v18 = **(unsigned int **)(a1 + 8);
        v56 = *(_DWORD *)(v3 + 56);
        v51 = result;
        v52 = 10012;
        v55 = *(v11 - 26);
        goto LABEL_43;
      }
      ++v8;
      v11 += 52;
      v10 += v58;
      if ( v8 >= (unsigned int)a2[1] )
      {
        if ( v10 )
        {
          v53 = result;
          v54 = *(_BYTE *)(a1 + 24) == 1
             && *(_DWORD *)(*(_QWORD *)(a3 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a3 + 40) - 1) + 12) == 2;
          cam_isp_update_hw_entry(2, a3, v7, v10, v54);
          result = v53;
          *(_BYTE *)(a1 + 24) = 1;
        }
        goto LABEL_51;
      }
    }
    if ( (unsigned int)v18 > 2 )
      goto LABEL_52;
    v20 = (8 * v18) | 0xE0;
    v21 = (__int64 **)&g_ife_hw_mgr[v18 + 28];
    goto LABEL_23;
  }
  result = 0;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
