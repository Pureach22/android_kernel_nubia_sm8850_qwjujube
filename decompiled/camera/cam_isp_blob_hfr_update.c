__int64 __fastcall cam_isp_blob_hfr_update(
        unsigned int a1,
        __int64 a2,
        unsigned int *a3,
        __int64 a4,
        unsigned int a5,
        int a6)
{
  int v6; // w14
  unsigned int v8; // w15
  __int64 v9; // x21
  __int64 v10; // x6
  __int64 v11; // x7
  __int64 v12; // x17
  unsigned __int64 v13; // x28
  __int64 result; // x0
  int v15; // w25
  unsigned __int8 *v16; // x27
  __int64 v17; // x24
  __int64 *v18; // x9
  unsigned int v19; // w8
  unsigned int *v20; // x10
  __int64 v21; // x9
  __int64 *v22; // x11
  unsigned __int64 v23; // x12
  __int64 **v24; // x11
  __int64 v25; // x10
  __int64 v26; // x8
  int v27; // w9
  unsigned int v28; // w10
  unsigned int *v29; // x26
  unsigned int v30; // w19
  int v31; // w24
  __int64 v32; // x21
  unsigned int v33; // w22
  unsigned int *v34; // x26
  unsigned int v35; // w19
  unsigned int v36; // w22
  __int64 v37; // x21
  const char *v38; // x5
  __int64 v39; // x4
  unsigned int v40; // w21
  char v41; // w4
  unsigned int v42; // w19
  __int64 v43; // x4
  __int64 v44; // x27
  unsigned int *v45; // x25
  unsigned int v46; // w19
  int v49; // [xsp+0h] [xbp-50h]
  int v50; // [xsp+8h] [xbp-48h]
  int v51; // [xsp+18h] [xbp-38h]
  unsigned int v52; // [xsp+1Ch] [xbp-34h]
  __int64 v53; // [xsp+20h] [xbp-30h]
  __int64 *v54; // [xsp+28h] [xbp-28h]
  __int64 *v55; // [xsp+30h] [xbp-20h]
  __int64 v56; // [xsp+38h] [xbp-18h]
  int v57; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v58; // [xsp+48h] [xbp-8h]

  v6 = a6;
  v8 = a1;
  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a4 + 16);
  v57 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v44 = a4;
    v45 = a3;
    v46 = a5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_hfr_update",
      10616,
      "ctx_idx: %u num_ports= %d",
      *(_DWORD *)(v9 + 56),
      *a3);
    a4 = v44;
    a3 = v45;
    a5 = v46;
    v8 = a1;
    v6 = a6;
  }
  v10 = *(unsigned int *)(a4 + 40);
  v11 = *(unsigned int *)(a4 + 24);
  if ( (int)v10 + 1 < (unsigned int)v11 )
  {
    if ( !*a3 )
    {
      result = 0;
      goto LABEL_47;
    }
    v12 = *(_QWORD *)(a2 + 16);
    v53 = a4;
    v13 = 0;
    result = 0;
    v15 = 0;
    v16 = (unsigned __int8 *)(a3 + 2);
    v55 = (__int64 *)(v9 + 272);
    v54 = (__int64 *)(v9 + 280);
    v56 = v9;
    while ( 1 )
    {
      v17 = *v16;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v51 = v6;
        v52 = result;
        v34 = a3;
        v35 = a5;
        v50 = *(_DWORD *)(v9 + 56);
        v36 = v8;
        v37 = v12;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_hfr_update",
          10633,
          "type %d hfr config idx %d, type=%d ctx_idx: %u",
          v6,
          v13,
          v17,
          v50);
        v6 = v51;
        result = v52;
        v12 = v37;
        v9 = v56;
        a3 = v34;
        a5 = v35;
        v8 = v36;
        if ( (unsigned int)v17 >= v35 )
        {
LABEL_33:
          v10 = *(unsigned int *)v16;
          v11 = *(unsigned int *)(v9 + 56);
          v38 = "invalid out restype:%x, ctx_idx: %u";
          v39 = 10637;
          goto LABEL_35;
        }
      }
      else if ( (unsigned int)v17 >= a5 )
      {
        goto LABEL_33;
      }
      if ( v6 == 7 )
      {
        v18 = v54;
        v19 = *(unsigned __int8 *)(*(_QWORD *)(v9 + 8504) + v17);
        if ( v19 == 255 )
        {
          v43 = 10643;
LABEL_44:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_hfr_update",
            v43,
            "Invalid index:%d for out_map",
            (unsigned int)v17);
          result = 4294967274LL;
          goto LABEL_47;
        }
      }
      else
      {
        v18 = v55;
        v19 = *(unsigned __int8 *)(*(_QWORD *)(v9 + 8496) + v17);
        if ( v19 == 255 )
        {
          v43 = 10650;
          goto LABEL_44;
        }
      }
      v20 = *(unsigned int **)(a2 + 8);
      v21 = *v18;
      v11 = v20[2];
      v10 = *v20;
      if ( (_DWORD)v11 == 7 )
      {
        if ( (unsigned int)v10 > 2 )
          goto LABEL_48;
        v23 = (8 * v10) | 0xE0;
        v24 = (__int64 **)&g_ife_hw_mgr[v10 + 28];
      }
      else
      {
        if ( (_DWORD)v11 != 2 )
        {
          if ( (_DWORD)v11 )
            goto LABEL_37;
          if ( (unsigned int)v10 >= 8 )
          {
LABEL_48:
            __break(0x5512u);
LABEL_49:
            __break(1u);
          }
          v22 = &g_ife_hw_mgr[v10 + 12];
          goto LABEL_26;
        }
        if ( (unsigned int)v10 > 7 )
          goto LABEL_48;
        v23 = 8 * v10 + 160;
        v24 = (__int64 **)((char *)g_ife_hw_mgr + v23);
      }
      if ( v23 > 0x13FD8 )
        goto LABEL_49;
      v22 = *v24;
LABEL_26:
      if ( !*v22 || (v25 = v20[1], (unsigned int)v25 >= 2) )
      {
LABEL_37:
        v38 = "Invalid base %u type %u";
        v39 = 10661;
        goto LABEL_35;
      }
      v26 = *(_QWORD *)(v21 + ((unsigned __int64)v19 << 7) + 8 * v25 + 32);
      if ( v26 )
      {
        v28 = *(_DWORD *)(v12 + 20);
        v27 = *(_DWORD *)(v12 + 24);
        if ( v28 <= v27 + v15 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_hfr_update",
            10677,
            "no free kmd memory for base %d, ctx_idx: %u",
            v10,
            *(_DWORD *)(v9 + 56));
          result = 4294967284LL;
          goto LABEL_47;
        }
        v29 = a3;
        v30 = a5;
        v31 = v6;
        v32 = v12;
        v33 = v8;
        result = cam_isp_add_cmd_buf_update(
                   v26,
                   *v22,
                   v8,
                   4u,
                   (const void *)(*(_QWORD *)(v12 + 8) + (v15 & 0xFFFFFFFC) + (v27 & 0xFFFFFFFC)),
                   v28 - (v27 + v15),
                   (__int64)v16,
                   &v57);
        if ( (result & 0x80000000) != 0 )
        {
          v42 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_hfr_update",
            10698,
            "Failed cmd_update, base_idx=%d, rc=%d, res_id_out=0x%X hw_type=%d, ctx_idx: %u",
            **(_DWORD **)(a2 + 8),
            v57,
            *(_DWORD *)v16,
            v31,
            *(_DWORD *)(v56 + 56));
          result = v42;
          goto LABEL_47;
        }
        v12 = v32;
        v9 = v56;
        v6 = v31;
        v8 = v33;
        a5 = v30;
        v15 += v57;
        a3 = v29;
      }
      ++v13;
      v16 += 24;
      if ( v13 >= *a3 )
      {
        if ( v15 )
        {
          v40 = result;
          v41 = *(_BYTE *)(a2 + 24) == 1
             && *(_DWORD *)(*(_QWORD *)(v53 + 32) + 32LL * (unsigned int)(*(_DWORD *)(v53 + 40) - 1) + 12) == 2;
          cam_isp_update_hw_entry(2, v53, v12, v15, v41);
          result = v40;
          *(_BYTE *)(a2 + 24) = 1;
        }
        goto LABEL_47;
      }
    }
  }
  v38 = "Insufficient  HW entries :%d %d ctx_idx: %u";
  v39 = 10623;
  v49 = *(_DWORD *)(v9 + 56);
LABEL_35:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_hfr_update",
    v39,
    v38,
    v10,
    v11,
    v49);
  result = 4294967274LL;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
