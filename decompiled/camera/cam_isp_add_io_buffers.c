__int64 __fastcall cam_isp_add_io_buffers(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x8
  int v4; // w6
  unsigned int v5; // w7
  unsigned int *v6; // x23
  __int16 *v8; // x25
  __int64 v9; // x26
  __int16 *v10; // x24
  unsigned __int64 v11; // x21
  __int64 v12; // x20
  __int64 result; // x0
  char *v14; // x8
  unsigned __int64 v15; // x22
  unsigned int *v16; // x27
  char *v17; // x28
  unsigned int v18; // w6
  __int64 v19; // x8
  int v20; // w9
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x11
  bool v23; // cf
  unsigned int entries_util; // w0
  __int64 v25; // x9
  unsigned int v26; // w0
  const char *v27; // x5
  unsigned int v28; // w19
  __int64 v29; // x4
  unsigned int v30; // w23
  __int64 v31; // x9
  unsigned int v32; // w7
  unsigned int v33; // w8
  __int64 v34; // x1
  const void *v35; // x4
  unsigned int v36; // w0
  int v37; // w9
  int v38; // w27
  __int64 v39; // x8
  unsigned int v40; // w0
  __int64 v41; // x9
  unsigned int v42; // w7
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x9
  unsigned int v45; // w0
  __int64 v46; // x6
  const char *v47; // x5
  __int64 v48; // x4
  __int64 v49; // x7
  int v50; // w23
  int v51; // w20
  __int64 v52; // x10
  __int64 v53; // x11
  __int64 v54; // x6
  __int64 v55; // x8
  int v56; // w12
  char v57; // w9
  int v58; // w12
  unsigned __int64 StatusReg; // x22
  __int64 v60; // x27
  unsigned int v61; // [xsp+0h] [xbp-40h]
  int v62; // [xsp+14h] [xbp-2Ch]
  __int64 v63; // [xsp+18h] [xbp-28h] BYREF
  __int64 v64; // [xsp+20h] [xbp-20h] BYREF
  int v65; // [xsp+2Ch] [xbp-14h] BYREF
  unsigned int v66; // [xsp+30h] [xbp-10h] BYREF
  __int16 v67; // [xsp+34h] [xbp-Ch] BYREF
  char v68; // [xsp+36h] [xbp-Ah]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD **)(a1 + 16);
  v63 = 0;
  v68 = 0;
  v4 = v3[10];
  v5 = v3[6];
  v67 = 0;
  if ( v4 + 1 < v5 )
  {
    v6 = *(unsigned int **)v3;
    LODWORD(v8) = *(_DWORD *)(a1 + 88);
    v9 = *(unsigned __int8 *)(a1 + 84);
    v10 = (__int16 *)*(unsigned int *)(*(_QWORD *)v3 + 32LL);
    v62 = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 24LL);
    if ( (_DWORD)v8 == 3 )
    {
      v11 = (unsigned int)(24 * v9);
      v12 = vzalloc_noprof(v11);
      if ( !v12 )
        goto LABEL_79;
      goto LABEL_4;
    }
    v11 = 0;
    v12 = 0;
    if ( v6[9] )
    {
      do
      {
        v14 = (char *)v10 + (_QWORD)v6;
        v15 = 0;
        v10 = &v67;
        v16 = (unsigned int *)(v14 + 304);
        v17 = v14 + 56;
        while ( 1 )
        {
          v6 = v16 - 62;
          if ( (_DWORD)v8 == 3 )
          {
            if ( v16 == (unsigned int *)&dword_F8 )
            {
              v18 = 4569236;
LABEL_32:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_add_io_buffers",
                1256,
                "Invalid hw context id: 0x%x for io cfg: %d",
                v18,
                v15);
              v30 = -22;
              goto LABEL_67;
            }
            v18 = *v16;
            if ( *v16 > 4 || ((1 << v18) & 0x16) == 0 )
              goto LABEL_32;
            v19 = __clz(__rbit32(v18));
            if ( (unsigned int)v19 > 2 )
              goto LABEL_60;
            v20 = *((unsigned __int8 *)&v67 + v19);
            v21 = 8LL * (unsigned int)(v20 + v19 * v9);
            v23 = v11 >= v21;
            v22 = v11 - v21;
            v23 = v23 && v22 >= 8;
            if ( !v23 )
              goto LABEL_60;
            *(_QWORD *)(v12 + 8LL * (unsigned int)(v20 + v19 * v9)) = v17;
            *((_BYTE *)&v67 + v19) = v20 + 1;
            goto LABEL_10;
          }
          entries_util = cam_isp_io_buf_get_entries_util(a1, v16 - 62, &v63);
          if ( entries_util == -42 )
            goto LABEL_10;
          if ( entries_util )
          {
            v27 = "io_cfg[%d] failed rc %d";
            v28 = entries_util;
            v29 = 1279;
            goto LABEL_34;
          }
          if ( !v63 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              8,
              1,
              "cam_isp_add_io_buffers",
              1284,
              "hw_mgr res is NULL");
            goto LABEL_7;
          }
          v25 = *(unsigned int *)(*(_QWORD *)(a1 + 48) + 4LL);
          if ( (unsigned int)v25 > 1 )
            break;
          a3 = *(_QWORD *)(v63 + 8 * v25 + 32);
          if ( a3 )
          {
            v26 = cam_isp_add_io_buffers_util(a1, v16 - 62);
            if ( v26 )
            {
              v27 = "io_cfg[%d] add buf failed rc %d";
              v28 = v26;
              v29 = 1294;
LABEL_34:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
                3,
                8,
                1,
                "cam_isp_add_io_buffers",
                v29,
                v27,
                (unsigned int)v15,
                v28);
              result = v28;
              goto LABEL_80;
            }
          }
LABEL_10:
          ++v15;
          v16 += 64;
          v17 += 256;
          if ( v15 >= *(unsigned int *)(**(_QWORD **)(a1 + 16) + 36LL) )
            goto LABEL_29;
        }
LABEL_78:
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v60 = *(_QWORD *)(StatusReg + 80);
        v11 = 24 * v9;
        *(_QWORD *)(StatusReg + 80) = &cam_isp_add_io_buffers__alloc_tag;
        v12 = vzalloc_noprof(24 * v9);
        *(_QWORD *)(StatusReg + 80) = v60;
        if ( !v12 )
        {
LABEL_79:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_add_io_buffers",
            1246,
            "Memory allocation failed for MC cases");
          result = 4294967284LL;
          goto LABEL_80;
        }
LABEL_4:
        ;
      }
      while ( *(_DWORD *)(**(_QWORD **)(a1 + 16) + 36LL) );
    }
LABEL_29:
    if ( (_DWORD)v8 == 3 )
    {
      v15 = 0;
      v8 = &v67;
      while ( 1 )
      {
        v9 = *((unsigned __int8 *)&v67 + v15);
        if ( *((_BYTE *)&v67 + v15) )
          break;
LABEL_37:
        if ( ++v15 == 3 )
        {
          vfree(v12);
          goto LABEL_70;
        }
      }
      v31 = *(_QWORD *)(a1 + 24);
      v66 = v15;
      v64 = 0;
      v33 = *(_DWORD *)(v31 + 20);
      v32 = *(_DWORD *)(v31 + 24);
      if ( v33 <= v32 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_add_io_buffers_mc",
          1143,
          "no free kmd memory for base=%d bytes_used=%u buf_size=%u",
          **(unsigned int **)(a1 + 48));
        v30 = -12;
        goto LABEL_66;
      }
      v34 = *(_QWORD *)(a1 + 64);
      v35 = (const void *)(*(_QWORD *)(v31 + 8) + (v32 & 0xFFFFFFFC));
      v65 = 0;
      v36 = cam_isp_add_cmd_buf_update(0, v34, a3, 0x4Bu, v35, v33 - v32, (__int64)&v66, &v65);
      if ( v36 )
      {
        v46 = v66;
        v30 = v36;
        v47 = "Adding MC context[%u] failed for base[%d]";
        v49 = **(unsigned int **)(a1 + 48);
        v48 = 1161;
LABEL_63:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_add_io_buffers_mc",
          v48,
          v47,
          v46,
          v49,
          v61);
      }
      else
      {
        v37 = v65;
        *(_DWORD *)(*(_QWORD *)(a1 + 24) + 24LL) += v65;
        *(_DWORD *)(*(_QWORD *)(a1 + 24) + 16LL) += v37;
        v38 = *(unsigned __int8 *)(a1 + 84);
        v39 = v66 * v38;
        if ( v11 < 8 * v39 || v11 - 8 * v39 < 8 )
        {
LABEL_60:
          __break(1u);
        }
        else
        {
          v6 = nullptr;
          while ( 1 )
          {
            v40 = cam_isp_io_buf_get_entries_util(a1, *(_QWORD *)(v12 + 8 * v39), &v64);
            if ( !v64 )
              break;
            v41 = *(unsigned int *)(*(_QWORD *)(a1 + 48) + 4LL);
            if ( (unsigned int)v41 >= 2 )
              goto LABEL_78;
            a3 = *(_QWORD *)(v64 + 8 * v41 + 32);
            if ( a3 )
            {
              v42 = v66;
              if ( **(_BYTE **)a1 == 1 )
              {
                if ( v66 > 2 )
                  goto LABEL_78;
                *(_QWORD *)(*(_QWORD *)a1 + 8LL) = *(_QWORD *)(v64 + 8LL * v66 + 72);
                if ( !*(_QWORD *)(*(_QWORD *)a1 + 8LL) )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_isp_add_io_buffers_mc",
                    1192,
                    "[FRMHDR] No frameheader buffer configured for res_id: %u, ctxt_id: %u, req_id: %llu",
                    *(unsigned int *)(a3 + 4));
                  v30 = -22;
                  goto LABEL_66;
                }
                *(_DWORD *)(*(_QWORD *)a1 + 16LL) = 0;
              }
              v43 = 8LL * ((unsigned int)v6 + v42 * v38);
              v23 = v11 >= v43;
              v44 = v11 - v43;
              if ( !v23 || v44 < 8 )
                goto LABEL_60;
              v45 = cam_isp_add_io_buffers_util(a1, *(_QWORD *)(v12 + 8LL * ((unsigned int)v6 + v42 * v38)));
              if ( v45 )
              {
                v46 = v66;
                v47 = "ctxt[%d] io_cfg[%d] add buf failed rc %d";
                v48 = 1203;
                v49 = (unsigned int)v6;
                v30 = v45;
                v61 = v45;
                goto LABEL_63;
              }
              v6 = (unsigned int *)(unsigned int)((_DWORD)v6 + 1);
              if ( (_DWORD)v6 == (_DWORD)v9 )
                goto LABEL_37;
            }
            else
            {
              v6 = (unsigned int *)(unsigned int)((_DWORD)v6 + 1);
              if ( (_DWORD)v6 == (_DWORD)v9 )
              {
                v30 = v40;
                if ( v40 )
                  goto LABEL_66;
                goto LABEL_37;
              }
            }
            v39 = (unsigned int)v6 + v66 * v38;
            if ( v11 < 8 * v39 || v11 - 8 * v39 < 8 )
              goto LABEL_60;
          }
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_add_io_buffers_mc",
          1175,
          "hw_mgr res is NULL");
        v30 = -22;
      }
LABEL_66:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_add_io_buffers",
        1308,
        "MC context[%u] failed for base[%d]",
        v15,
        **(_DWORD **)(a1 + 48));
LABEL_67:
      vfree(v12);
      result = v30;
      goto LABEL_80;
    }
LABEL_70:
    v50 = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 24LL);
    v51 = v50 - v62;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_add_io_buffers",
        1318,
        "io_cfg_used_bytes %d, fill_fence %d",
        v51,
        *(unsigned __int8 *)(a1 + 92));
      if ( v50 == v62 )
        goto LABEL_73;
    }
    else if ( v50 == v62 )
    {
      goto LABEL_73;
    }
    result = 0;
    *(_DWORD *)(*(_QWORD *)(a1 + 24) + 16LL) -= v51;
    *(_DWORD *)(*(_QWORD *)(a1 + 24) + 24LL) -= v51;
    v52 = *(_QWORD *)(a1 + 16);
    v53 = *(_QWORD *)(a1 + 24);
    v54 = *(unsigned int *)(v52 + 40);
    v55 = *(_QWORD *)(v52 + 32) + 32 * v54;
    *(_DWORD *)v55 = *(_DWORD *)v53;
    *(_DWORD *)(v55 + 8) = v51;
    v56 = *(_DWORD *)(v53 + 16);
    *(_DWORD *)(v55 + 12) = 3;
    *(_DWORD *)(v55 + 4) = v56;
    *(_QWORD *)(v55 + 16) = *(_QWORD *)(v53 + 8) + (*(_DWORD *)(v53 + 24) & 0xFFFFFFFC);
    v57 = debug_mdl;
    v58 = *(_DWORD *)(v53 + 16) + v51;
    *(_DWORD *)(v53 + 24) += v51;
    *(_DWORD *)(v53 + 16) = v58;
    *(_DWORD *)(v52 + 40) = v54 + 1;
    if ( (v57 & 8) == 0 || debug_priority )
      goto LABEL_80;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v57 & 8,
      4,
      "cam_isp_add_update_entry",
      44,
      "Add new entry: num_ent=%d handle=0x%x, len=%u, offset=%u",
      v54,
      *(_DWORD *)v55,
      *(_DWORD *)(v55 + 8),
      *(_DWORD *)(v55 + 4));
LABEL_73:
    result = 0;
    goto LABEL_80;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_add_io_buffers",
    1236,
    "Insufficient  HW entries :%d %d",
    v4,
    v5);
LABEL_7:
  result = 4294967274LL;
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
