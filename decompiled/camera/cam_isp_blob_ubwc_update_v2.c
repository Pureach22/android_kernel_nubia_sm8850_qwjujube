__int64 __fastcall cam_isp_blob_ubwc_update_v2(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x28
  __int64 v7; // x23
  unsigned __int64 v8; // x24
  __int64 result; // x0
  int v10; // w22
  _DWORD *v11; // x26
  int v12; // w27
  __int64 v13; // x8
  __int64 v14; // x9
  unsigned int *v15; // x8
  unsigned int v16; // w7
  __int64 v17; // x6
  __int64 *v18; // x10
  unsigned __int64 v19; // x11
  __int64 **v20; // x10
  __int64 v21; // x1
  __int64 v22; // x10
  __int64 v23; // x9
  int v24; // w10
  unsigned int v25; // w11
  unsigned int v26; // w5
  int v27; // w12
  __int64 v28; // x13
  __int64 v29; // x11
  int v30; // w12
  __int64 v31; // x13
  unsigned int v32; // w12
  unsigned int v33; // w14
  __int64 v34; // x13
  int v35; // w12
  int v36; // w12
  int v37; // w12
  int v38; // w12
  int v39; // w12
  int v40; // w12
  int v41; // w12
  int v42; // w12
  __int64 v43; // x8
  const char *v44; // x5
  __int64 v45; // x4
  unsigned int v46; // w21
  char v47; // w4
  int v48; // w6
  unsigned int v49; // w19
  unsigned int v50; // [xsp+10h] [xbp-B0h]
  int v51; // [xsp+14h] [xbp-ACh] BYREF
  __int64 v52; // [xsp+18h] [xbp-A8h] BYREF
  __int128 v53; // [xsp+20h] [xbp-A0h]
  __int64 v54; // [xsp+30h] [xbp-90h]
  __int64 v55; // [xsp+38h] [xbp-88h]
  unsigned __int64 v56; // [xsp+40h] [xbp-80h]
  __int64 v57; // [xsp+48h] [xbp-78h]
  __int128 v58; // [xsp+50h] [xbp-70h]
  __int128 v59; // [xsp+60h] [xbp-60h]
  __int64 v60; // [xsp+70h] [xbp-50h]
  __int64 v61; // [xsp+78h] [xbp-48h]
  __int64 v62; // [xsp+80h] [xbp-40h]
  __int64 v63; // [xsp+88h] [xbp-38h]
  __int64 v64; // [xsp+90h] [xbp-30h]
  __int64 v65; // [xsp+98h] [xbp-28h]
  __int64 v66; // [xsp+A0h] [xbp-20h]
  int v67; // [xsp+A8h] [xbp-18h]
  __int64 v68; // [xsp+B0h] [xbp-10h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 16);
  v51 = 0;
  v67 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v60 = 0;
  v59 = 0u;
  v57 = 0;
  v58 = 0u;
  v55 = 0;
  v56 = 0;
  v54 = 0;
  v52 = 0;
  v53 = 0u;
  if ( !v3 )
  {
    v44 = "Invalid ctx";
    v45 = 9732;
LABEL_33:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_ubwc_update_v2",
      v45,
      v44);
    result = 4294967274LL;
    goto LABEL_48;
  }
  if ( (unsigned int)(*(_DWORD *)(a3 + 40) + 1) >= *(_DWORD *)(a3 + 24) )
  {
    v44 = "Insufficient HW entries :%d max:%d, ctx_idx: %u";
    v45 = 9741;
    goto LABEL_33;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_ubwc_update_v2",
      9746,
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
    v11 = a2 + 22;
    while ( 1 )
    {
      v12 = *(v11 - 20);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v50 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_ubwc_update_v2",
          9754,
          "UBWC config idx %d, port_type=%d ctx_idx: %u",
          v8,
          v12,
          *(_DWORD *)(v3 + 56));
        result = v50;
      }
      if ( (unsigned __int8)v12 >= (unsigned int)max_ife_out_res )
      {
        v44 = "Invalid port type:0x%x ctx_idx: %u";
        v45 = 9758;
        goto LABEL_33;
      }
      v13 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8496) + (unsigned __int8)v12);
      if ( v13 == 255 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_ubwc_update_v2",
          9764,
          "Invalid index:%d for out_map",
          (unsigned __int8)v12);
        result = 4294967274LL;
        goto LABEL_48;
      }
      v14 = *(_QWORD *)(v3 + 272) + (v13 << 7);
      if ( !v14 )
      {
        v44 = "Invalid hw_mgr_res";
        v45 = 9771;
        goto LABEL_33;
      }
      v15 = *(unsigned int **)(a1 + 8);
      v16 = v15[2];
      v17 = *v15;
      if ( v16 == 7 )
        break;
      if ( v16 == 2 )
      {
        if ( (unsigned int)v17 > 7 )
          goto LABEL_49;
        v19 = 8 * v17 + 160;
        v20 = (__int64 **)((char *)g_ife_hw_mgr + v19);
LABEL_23:
        if ( v19 > 0x13FD8 )
        {
          __break(1u);
          return cam_isp_blob_ubwc_update_v3(result);
        }
        v18 = *v20;
        goto LABEL_25;
      }
      if ( v16 )
        goto LABEL_35;
      if ( (unsigned int)v17 >= 8 )
LABEL_49:
        __break(0x5512u);
      v18 = &g_ife_hw_mgr[v17 + 12];
LABEL_25:
      v21 = *v18;
      if ( !*v18 || (v22 = v15[1], (unsigned int)v22 >= 2) )
      {
LABEL_35:
        v44 = "Invalid base %u type %u";
        v45 = 9781;
        goto LABEL_33;
      }
      v23 = v14 + 32;
      if ( *(_QWORD *)(v23 + 8 * v22) )
      {
        v25 = *(_DWORD *)(v7 + 20);
        v24 = *(_DWORD *)(v7 + 24);
        v26 = v25 - (v24 + v10);
        if ( v25 <= v24 + v10 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_ubwc_update_v2",
            9798,
            "no free kmd memory for base=%d bytes_used=%u buf_size=%u ctx_idx: %u",
            v17,
            v51,
            v25,
            *(_DWORD *)(v3 + 56));
          result = 4294967284LL;
          goto LABEL_48;
        }
        v27 = *(v11 - 19);
        v28 = *((_QWORD *)v11 - 9);
        HIDWORD(v52) = *(v11 - 20);
        v29 = *(_QWORD *)(v7 + 8);
        LODWORD(v53) = v27;
        v30 = *(v11 - 16);
        *(_QWORD *)((char *)&v53 + 4) = v28;
        v31 = *(_QWORD *)(v11 - 15);
        HIDWORD(v53) = v30;
        v54 = v31;
        LODWORD(v31) = *(v11 - 12);
        LODWORD(v55) = *(v11 - 13);
        HIDWORD(v55) = v31;
        v33 = *(v11 - 11);
        v32 = *(v11 - 10);
        v57 = *(_QWORD *)(v11 - 9);
        v34 = *((_QWORD *)v11 - 3);
        v56 = __PAIR64__(v32, v33);
        v35 = *(v11 - 7);
        *(_QWORD *)((char *)&v58 + 4) = v34;
        LODWORD(v58) = v35;
        *(_QWORD *)((char *)&v59 + 4) = *(_QWORD *)v11;
        v36 = v11[3];
        HIDWORD(v59) = v11[2];
        LODWORD(v60) = v36;
        v37 = v11[5];
        HIDWORD(v60) = v11[4];
        LODWORD(v61) = v37;
        v38 = v11[7];
        HIDWORD(v61) = v11[6];
        LODWORD(v62) = v38;
        v39 = v11[9];
        HIDWORD(v62) = v11[8];
        LODWORD(v63) = v39;
        v40 = v11[11];
        HIDWORD(v63) = v11[10];
        LODWORD(v64) = v40;
        v41 = v11[13];
        HIDWORD(v64) = v11[12];
        LODWORD(v65) = v41;
        LODWORD(v34) = v11[14];
        v42 = v11[15];
        HIDWORD(v58) = *(v11 - 4);
        LODWORD(v59) = 0;
        HIDWORD(v65) = v34;
        LODWORD(v66) = v42;
        HIDWORD(v66) = v11[16];
        v67 = 0;
        v43 = v15[1];
        LODWORD(v52) = *a2;
        if ( (unsigned int)v43 >= 2 )
          goto LABEL_49;
        result = cam_isp_add_cmd_buf_update(
                   *(_QWORD *)(v23 + 8 * v43),
                   v21,
                   6,
                   0x18u,
                   (const void *)(v29 + (v10 & 0xFFFFFFFC) + (v24 & 0xFFFFFFFC)),
                   v26,
                   (__int64)&v52,
                   &v51);
        if ( (result & 0x80000000) != 0 )
        {
          v48 = **(_DWORD **)(a1 + 8);
          v49 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_ubwc_update_v2",
            9823,
            "Failed cmd_update, base_idx=%d, bytes_used=%u, res_id_out=0x%X, ctx_idx: %u",
            v48,
            v51,
            *(v11 - 20),
            *(_DWORD *)(v3 + 56));
          result = v49;
          goto LABEL_48;
        }
        v10 += v51;
      }
      ++v8;
      v11 += 40;
      if ( v8 >= (unsigned int)a2[1] )
      {
        if ( v10 )
        {
          v46 = result;
          v47 = *(_BYTE *)(a1 + 24) == 1
             && *(_DWORD *)(*(_QWORD *)(a3 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a3 + 40) - 1) + 12) == 2;
          cam_isp_update_hw_entry(2, a3, v7, v10, v47);
          result = v46;
          *(_BYTE *)(a1 + 24) = 1;
        }
        goto LABEL_48;
      }
    }
    if ( (unsigned int)v17 > 2 )
      goto LABEL_49;
    v19 = (8 * v17) | 0xE0;
    v20 = (__int64 **)&g_ife_hw_mgr[v17 + 28];
    goto LABEL_23;
  }
  result = 0;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
