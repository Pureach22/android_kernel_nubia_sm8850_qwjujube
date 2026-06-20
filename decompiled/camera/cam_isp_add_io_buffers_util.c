__int64 __fastcall cam_isp_add_io_buffers_util(_QWORD *a1, _DWORD *a2, __int64 a3)
{
  int v3; // w6
  unsigned int v4; // w20
  unsigned int v5; // w19
  __int64 v6; // x6
  const char *v7; // x5
  __int64 v8; // x0
  __int64 v9; // x4
  _QWORD *v10; // x9
  _QWORD *v11; // x10
  __int64 v12; // x8
  _QWORD *v13; // x24
  _DWORD *v15; // x9
  __int64 v16; // x0
  const char *v19; // x5
  __int64 v20; // x4
  __int64 result; // x0
  int v22; // w0
  unsigned int *v23; // x28
  unsigned int *v24; // x11
  int v25; // w0
  unsigned int v26; // w20
  __int64 v27; // x6
  const char *v28; // x5
  __int64 v29; // x4
  _DWORD *v30; // x8
  int v31; // w11
  __int64 v32; // x1
  __int64 v33; // x9
  __int64 *v34; // x10
  int v35; // w0
  unsigned int *v36; // x9
  unsigned int v37; // w20
  int v38; // w26
  __int64 v39; // x13
  unsigned int v40; // w11
  unsigned int v41; // w12
  __int64 v42; // x13
  const void *v43; // x6
  __int64 v44; // x13
  __int64 v45; // x10
  int v46; // w8
  __int64 v47; // x8
  _DWORD *v48; // x9
  __int64 v49; // x0
  int v50; // w11
  __int64 v51; // x1
  int v52; // w0
  unsigned int v53; // w20
  _QWORD *v54; // x8
  char v55; // w9
  __int64 v56; // x10
  _QWORD *v57; // x9
  _QWORD *v58; // x8
  _QWORD *v59; // x8
  int v60; // w11
  __int64 v61; // x1
  unsigned int v62; // [xsp+Ch] [xbp-E4h] BYREF
  __int64 v63; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v64; // [xsp+18h] [xbp-D8h]
  __int64 v65; // [xsp+20h] [xbp-D0h]
  __int64 v66; // [xsp+28h] [xbp-C8h]
  __int64 v67; // [xsp+30h] [xbp-C0h]
  unsigned int *v68; // [xsp+38h] [xbp-B8h]
  __int64 v69; // [xsp+40h] [xbp-B0h]
  __int64 v70; // [xsp+48h] [xbp-A8h]
  __int64 v71; // [xsp+50h] [xbp-A0h] BYREF
  __int64 v72; // [xsp+58h] [xbp-98h]
  const void *v73; // [xsp+60h] [xbp-90h]
  __int64 v74; // [xsp+68h] [xbp-88h]
  __int64 v75; // [xsp+70h] [xbp-80h]
  __int64 **v76; // [xsp+78h] [xbp-78h]
  __int64 v77; // [xsp+80h] [xbp-70h]
  __int64 *v78; // [xsp+88h] [xbp-68h] BYREF
  __int64 v79; // [xsp+90h] [xbp-60h]
  __int64 v80; // [xsp+98h] [xbp-58h]
  const void *v81; // [xsp+A0h] [xbp-50h]
  __int64 v82; // [xsp+A8h] [xbp-48h]
  __int64 v83; // [xsp+B0h] [xbp-40h]
  __int64 v84; // [xsp+B8h] [xbp-38h]
  _DWORD *v85; // [xsp+C0h] [xbp-30h]
  __int64 v86; // [xsp+C8h] [xbp-28h] BYREF
  __int64 v87; // [xsp+D0h] [xbp-20h]
  __int64 v88; // [xsp+D8h] [xbp-18h]
  __int64 v89; // [xsp+E0h] [xbp-10h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[56];
  v87 = 0;
  v88 = 0;
  v76 = nullptr;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = nullptr;
  v70 = 0;
  v71 = 0;
  v85 = nullptr;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = nullptr;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v78 = nullptr;
  v68 = nullptr;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v62 = 0;
  if ( v3 == 2 )
  {
    v4 = 6;
    v5 = 1;
  }
  else
  {
    if ( v3 != 1 )
    {
      v19 = "Invalid dir %d";
      v20 = 935;
LABEL_17:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_add_io_buffers_util",
        v20,
        v19);
LABEL_20:
      result = 4294967274LL;
      goto LABEL_21;
    }
    v4 = 7;
    v5 = 2;
  }
  v6 = *(unsigned int *)(a3 + 4);
  if ( *(_DWORD *)(a3 + 8) <= 1u )
  {
    v7 = "Inactive res ID: 0x%x state: %d";
    v8 = 3;
    v9 = 946;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      v8,
      8,
      1,
      "cam_isp_add_io_buffers_util",
      v9,
      v7,
      v6);
    goto LABEL_20;
  }
  if ( (_DWORD)v6 != a2[47] )
  {
    v7 = "err res id:%d io res id:%d";
    v8 = 3;
    v9 = 952;
    goto LABEL_19;
  }
  v10 = *(_QWORD **)(a1[2] + 328LL);
  v11 = (_QWORD *)*v10;
  v12 = *(_QWORD *)(a3 + 16);
  LODWORD(v64) = v4;
  v63 = a3;
  if ( v11 == v10 )
    v13 = nullptr;
  else
    v13 = v11;
  v68 = &v62;
  if ( !v12 )
  {
    v19 = "Invalid hw intf for res: 0x%x";
    v20 = 963;
    goto LABEL_17;
  }
  v15 = *(_DWORD **)(v12 + 88);
  v16 = *(_QWORD *)(v12 + 112);
  if ( *(v15 - 1) != -1055839300 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD, __int64 *, __int64))v15)(v16, v4, &v63, 56) )
  {
    v7 = "Get secure mode failed cmd_type %d res_id %d";
    v8 = 3;
    v9 = 972;
    v6 = v4;
    goto LABEL_19;
  }
  v22 = *a2;
  v87 = 0;
  v88 = 0;
  v86 = 0;
  if ( !v22 )
  {
    v27 = *(unsigned int *)(a3 + 4);
    v28 = "No valid planes for res%d";
    v29 = 1016;
LABEL_36:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_io_buffers_util",
      v29,
      v28,
      v27);
    result = 4294967284LL;
    goto LABEL_21;
  }
  v23 = (unsigned int *)a1 + 19;
  if ( (v22 & 0x8000) == 0 || (v24 = (unsigned int *)a1 + 19, v62 != 1) )
  {
    v24 = (unsigned int *)(a1 + 9);
    if ( v62 | v22 & 0x8000 )
      goto LABEL_27;
  }
  v26 = *v24;
  if ( (unsigned int)((__int64 (*)(void))cam_mem_get_io_buf)() )
  {
    v27 = 0;
LABEL_35:
    v28 = "no io addr for plane%d";
    v29 = 1001;
    goto LABEL_36;
  }
  v30 = a2;
  v31 = debug_priority;
  v32 = debug_mdl & 8;
  v86 += (unsigned int)a2[3];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v32,
      4,
      "cam_isp_add_io_buffers_util",
      1009,
      "get io_addr for plane %d: 0x%llx, mem_hdl=0x%x",
      0);
    v31 = debug_priority;
    v34 = a1;
    v30 = a2;
    v33 = a3;
    v32 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_42;
  }
  else
  {
    v33 = a3;
    v34 = a1;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_42;
  }
  if ( !v31 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v32,
      4,
      "cam_isp_add_io_buffers_util",
      1012,
      "mmu_hdl=0x%x, size=%d, end=0x%x",
      v26);
    v34 = a1;
    v30 = a2;
    v33 = a3;
  }
LABEL_42:
  v35 = v30[1];
  if ( !v35 )
  {
    v38 = 1;
    goto LABEL_49;
  }
  if ( (v35 & 0x8000) == 0 || (v36 = (unsigned int *)a1 + 19, v62 != 1) )
  {
    v36 = (unsigned int *)(a1 + 9);
    if ( v62 | v30[1] & 0x8000 )
      goto LABEL_27;
  }
  v37 = *v36;
  if ( (unsigned int)((__int64 (*)(void))cam_mem_get_io_buf)() )
  {
    v27 = 1;
    goto LABEL_35;
  }
  v50 = debug_priority;
  v30 = a2;
  v51 = debug_mdl & 8;
  v87 += (unsigned int)a2[4];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v51,
      4,
      "cam_isp_add_io_buffers_util",
      1009,
      "get io_addr for plane %d: 0x%llx, mem_hdl=0x%x",
      1);
    v50 = debug_priority;
    v34 = a1;
    v30 = a2;
    v33 = a3;
    v51 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_68;
  }
  else
  {
    v33 = a3;
    v34 = a1;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_68;
  }
  if ( !v50 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v51,
      4,
      "cam_isp_add_io_buffers_util",
      1012,
      "mmu_hdl=0x%x, size=%d, end=0x%x",
      v37);
    v34 = a1;
    v30 = a2;
    v33 = a3;
  }
LABEL_68:
  v52 = v30[2];
  if ( !v52 )
  {
    v38 = 2;
    goto LABEL_49;
  }
  if ( (v52 & 0x8000) == 0 || v62 != 1 )
  {
    v23 = (unsigned int *)(a1 + 9);
    if ( v62 | v30[2] & 0x8000 )
    {
LABEL_27:
      v25 = __ratelimit(&cam_isp_add_io_buffers_util__rs, "cam_isp_add_io_buffers_util");
      v6 = v62;
      if ( v25 )
        v8 = 3;
      else
        v8 = 2;
      v7 = "Invalid hdl: port mode[%u], buf mode[%u]";
      v9 = 992;
      goto LABEL_19;
    }
  }
  v53 = *v23;
  if ( (unsigned int)((__int64 (*)(void))cam_mem_get_io_buf)() )
  {
    v27 = 2;
    goto LABEL_35;
  }
  v60 = debug_priority;
  v30 = a2;
  v61 = debug_mdl & 8;
  v88 += (unsigned int)a2[5];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v61,
      4,
      "cam_isp_add_io_buffers_util",
      1009,
      "get io_addr for plane %d: 0x%llx, mem_hdl=0x%x",
      2);
    v60 = debug_priority;
    v30 = a2;
    v61 = debug_mdl & 8;
  }
  v33 = a3;
  v34 = a1;
  v38 = 3;
  if ( v61 && !v60 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v61,
      4,
      "cam_isp_add_io_buffers_util",
      1012,
      "mmu_hdl=0x%x, size=%d, end=0x%x",
      v53);
    v34 = a1;
    v30 = a2;
    v33 = a3;
  }
LABEL_49:
  v39 = v34[3];
  v41 = *(_DWORD *)(v39 + 20);
  v40 = *(_DWORD *)(v39 + 24);
  if ( v41 <= v40 )
  {
    v28 = "no free kmd memory for base %d";
    v27 = *(unsigned int *)v34[6];
    v29 = 1026;
    goto LABEL_36;
  }
  LODWORD(v72) = v5;
  v42 = *(_QWORD *)(v39 + 8);
  v78 = &v86;
  v71 = v33;
  v43 = (const void *)(v42 + (v40 & 0xFFFFFFFC));
  v44 = *v34;
  v85 = v30;
  v73 = v43;
  v81 = nullptr;
  LOBYTE(v82) = 0;
  LODWORD(v80) = 0;
  HIDWORD(v80) = v38;
  v79 = 0;
  if ( (*(_BYTE *)v44 & 1) != 0 && !*(_DWORD *)(v44 + 16) )
  {
    v45 = v34[2];
    v81 = *(const void **)(v44 + 8);
    HIDWORD(v82) = *(_QWORD *)(*(_QWORD *)v45 + 8LL);
  }
  v46 = v30[56];
  LODWORD(v74) = v41 - v40;
  if ( (unsigned int)(v46 - 1) <= 1 )
    v76 = &v78;
  LOBYTE(v75) = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_add_io_buffers_util",
      1060,
      "cmd buffer 0x%pK, size %d",
      v43,
      v41 - v40);
    v33 = a3;
  }
  v47 = *(_QWORD *)(v33 + 16);
  v48 = *(_DWORD **)(v47 + 88);
  v49 = *(_QWORD *)(v47 + 112);
  if ( *(v48 - 1) != -1055839300 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD, __int64 *, __int64))v48)(v49, v5, &v71, 56) )
  {
    v27 = *(unsigned int *)(a3 + 4);
    v28 = "get buf cmd error:%d";
    v29 = 1068;
    goto LABEL_36;
  }
  v54 = a1;
  if ( (unsigned __int8)v82 == 1 )
  {
    v55 = debug_mdl;
    *(_DWORD *)(*a1 + 16LL) = *(_DWORD *)(a3 + 4);
    if ( (v55 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v55 & 8,
        4,
        "cam_isp_add_io_buffers_util",
        1078,
        "Frame header enabled for res: 0x%x iova: %pK",
        *(_DWORD *)(*a1 + 16LL),
        v81);
      v54 = a1;
    }
  }
  *(_DWORD *)(v54[3] + 24LL) += HIDWORD(v74);
  *(_DWORD *)(v54[3] + 16LL) += HIDWORD(v74);
  if ( a2[56] != 2 || *((_BYTE *)v54 + 92) != 1 )
  {
LABEL_91:
    result = 0;
    goto LABEL_21;
  }
  v56 = v54[2];
  v57 = (_QWORD *)(*(_QWORD *)(v56 + 48) + ((unsigned __int64)(unsigned int)(*(_DWORD *)(v56 + 56) - 1) << 6));
  if ( !v57 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_io_buffers_util",
      1090,
      "out_map_entry is NULL");
    goto LABEL_20;
  }
  if ( !*(_DWORD *)(v54[6] + 4LL) )
  {
    v57[4] = v86 + (unsigned int)v79;
    v57[5] = v87 + HIDWORD(v79);
    v57[6] = v88 + (unsigned int)v80;
    v56 = a1[2];
  }
  v58 = *(_QWORD **)(v56 + 328);
  result = 0;
  if ( (_QWORD *)*v58 == v58 )
    v59 = nullptr;
  else
    v59 = (_QWORD *)*v58;
  if ( v59 )
  {
    if ( v13 != v59 )
    {
      v57[7] = v59;
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_add_io_buffers_util",
          1112,
          "[SMMU_BT] Tracking io_buf, buf_handle: 0x%x, fd: 0x%x, res_id: %d",
          *a2,
          *((_DWORD *)v59 + 6),
          *(_DWORD *)(a3 + 4));
        goto LABEL_91;
      }
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
