__int64 __fastcall cam_icp_mgr_prepare_hw_update(__int64 a1, unsigned int **a2)
{
  unsigned __int8 *v2; // x19
  unsigned int *v5; // x20
  __int64 result; // x0
  int v7; // w7
  int v8; // w9
  const char *v9; // x5
  unsigned __int8 *v10; // x6
  __int64 v11; // x4
  unsigned int v12; // w25
  __int64 v13; // x8
  unsigned int v14; // w9
  unsigned __int8 *v15; // x23
  unsigned __int64 v16; // x11
  int v17; // w22
  signed int v18; // w10
  int v19; // w12
  int v20; // w13
  unsigned int v21; // w15
  unsigned __int8 *v22; // x14
  int v23; // w16
  int v24; // w17
  unsigned __int8 *v25; // x11
  __int64 v26; // x12
  unsigned int v27; // w8
  unsigned __int8 *v28; // x24
  int *v29; // x28
  int v30; // w0
  unsigned int v31; // w8
  int v32; // w23
  __int64 v33; // x9
  int *v34; // x22
  int v35; // w0
  unsigned __int64 v36; // x9
  size_t v37; // x10
  size_t v38; // x9
  unsigned __int8 *v39; // x25
  int v40; // w24
  unsigned int cpu_buf; // w0
  size_t v42; // x9
  size_t v43; // x11
  int v44; // w20
  unsigned int v45; // w23
  void *v46; // x0
  void *v47; // x0
  __int64 v48; // x6
  unsigned int v49; // w0
  unsigned int updated; // w0
  __int64 v51; // x23
  unsigned int v52; // w0
  __int64 v54; // x9
  unsigned int v55; // w0
  unsigned __int8 *v56; // x10
  __int16 v57; // w9
  unsigned __int64 v63; // x10
  unsigned int v64; // [xsp+20h] [xbp-30h]
  unsigned int v65; // [xsp+20h] [xbp-30h]
  unsigned int v66; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v67; // [xsp+30h] [xbp-20h] BYREF
  size_t v68; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v69[2]; // [xsp+40h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !*a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_prepare_hw_update",
      7381,
      "Invalid args");
    result = 4294967274LL;
    goto LABEL_20;
  }
  v2 = (unsigned __int8 *)a2[2];
  mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * *((unsigned int *)v2 + 7306));
  if ( *((_DWORD *)v2 + 26) != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_prepare_hw_update",
      7388,
      "%s: is not in use",
      (const char *)v2 + 29824);
LABEL_17:
    v12 = -22;
    goto LABEL_18;
  }
  v5 = *a2;
  if ( (unsigned int)cam_packet_util_validate_packet(*a2, (unsigned __int64)a2[1]) )
  {
    mutex_unlock(v2 + 24);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v7 = *(unsigned __int8 *)v5;
  v8 = *(_DWORD *)(*((_QWORD *)v2 + 2) + 8LL);
  if ( *(_BYTE *)v5 && v8 == 2 || v7 != 1 && v8 == 3 || v7 != 4 && v8 == 4 )
  {
    v9 = "%s: Invalid Opcode in pkt: %d device: %s";
    v10 = v2 + 29824;
    v11 = 6421;
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int8 *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_pkt_validation",
      v11,
      v9,
      v10);
    goto LABEL_17;
  }
  v14 = v5[9];
  if ( !v14 )
  {
    v9 = "%s: Invalid number of io configs: %d";
    v10 = v2 + 29824;
    v11 = 6427;
    goto LABEL_16;
  }
  if ( v5[7] - 3 <= 0xFFFFFFFD )
  {
    v9 = "%s: Invalid number of cmd buffers: %d max cmd buf: %d";
    v10 = v2 + 29824;
    v11 = 6434;
    goto LABEL_16;
  }
  v15 = (unsigned __int8 *)(v5 + 14);
  v16 = (unsigned __int64)v5[8] >> 2;
  v13 = a1;
  if ( v14 + 0x7FFFFFFF < 0x80000001 )
  {
    v17 = 0;
    v18 = 0;
LABEL_34:
    v25 = &v15[4 * v16];
    do
    {
      v26 = v18++;
      if ( *(_DWORD *)&v25[256 * v26 + 224] == 1 )
        ++v17;
    }
    while ( v14 != v18 );
    goto LABEL_38;
  }
  v18 = v14 & 0xFFFFFFFE;
  v19 = 0;
  v20 = 0;
  v21 = v14 & 0xFFFFFFFE;
  v22 = (unsigned __int8 *)&v5[v16 + 134];
  do
  {
    v23 = *((_DWORD *)v22 - 64);
    v24 = *(_DWORD *)v22;
    v22 += 512;
    if ( v23 == 1 )
      ++v19;
    if ( v24 == 1 )
      ++v20;
    v21 -= 2;
  }
  while ( v21 );
  v17 = v20 + v19;
  if ( v14 != v18 )
    goto LABEL_34;
LABEL_38:
  if ( v17 >= 17 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_is_valid_inconfig",
      6366,
      "In config entries(%u) more than allowed(%u)",
      v17,
      16);
    v13 = a1;
  }
  if ( (debug_mdl & 0x100) == 0 || debug_priority )
  {
    if ( v17 <= 16 )
      goto LABEL_43;
LABEL_90:
    v12 = -22;
    goto LABEL_19;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x100,
    4,
    "cam_icp_mgr_is_valid_inconfig",
    6371,
    "number of io config: %u in config: %u max in res: %u",
    v5[9],
    v17,
    16);
  v13 = a1;
  if ( v17 > 16 )
    goto LABEL_90;
LABEL_43:
  if ( (cam_icp_mgr_is_valid_outconfig(v5) & 1) == 0 )
    goto LABEL_17;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_pkt_validation",
      6445,
      "%s: number of cmd/patch info: %u %u %u",
      (const char *)v2 + 29824,
      v5[7],
      v5[9],
      v5[11]);
  v27 = v5[6];
  v28 = (unsigned __int8 *)a2[41];
  v68 = 0;
  v69[0] = 0;
  v67 = 0;
  v29 = (int *)&v15[v27 & 0xFFFFFFFC];
  v30 = cam_packet_util_validate_cmd_desc(v29);
  if ( v30 )
  {
LABEL_68:
    v12 = v30;
    goto LABEL_18;
  }
  v31 = v5[7];
  if ( !v31 )
  {
LABEL_63:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_process_cmd_desc",
      6517,
      "%s: invalid number of cmd buf",
      (const char *)v2 + 29824);
LABEL_67:
    v30 = -22;
    goto LABEL_68;
  }
  v32 = 0;
  v33 = a1;
  v64 = 0;
  v66 = 0;
  while ( 1 )
  {
    v34 = &v29[6 * v32];
    if ( v34[4] == 8 )
      break;
LABEL_51:
    if ( ++v32 >= v31 )
    {
      if ( !v67 )
        goto LABEL_63;
      goto LABEL_71;
    }
  }
  v35 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD *, size_t *, _QWORD, unsigned __int8 *))cam_mem_get_io_buf)(
          (unsigned int)*v34,
          *(unsigned int *)(v33 + 148),
          v69,
          &v68,
          0,
          v28);
  if ( v35 )
  {
    v44 = v35;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_process_cmd_desc",
      6474,
      "%s: get cmd buf failed %x",
      (const char *)v2 + 29824,
      *(_DWORD *)(a1 + 148));
    v30 = v44;
    goto LABEL_68;
  }
  v36 = (unsigned int)v34[1];
  v37 = v68 - v36;
  v65 = v34[1];
  if ( v68 <= v36 )
  {
    LODWORD(v38) = v34[2];
LABEL_66:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_process_cmd_desc",
      6487,
      "%s: Invalid offset, i: %d offset: %u len: %zu size: %zu",
      (const char *)v2 + 29824,
      v32,
      v65,
      v68,
      v38);
    goto LABEL_67;
  }
  v38 = (unsigned int)v34[2];
  if ( v37 < v38 )
    goto LABEL_66;
  v39 = v28;
  v40 = v69[0];
  cpu_buf = cam_mem_get_cpu_buf(*v34, &v67, &v68);
  if ( !cpu_buf && v67 )
  {
    v42 = (unsigned int)v34[1];
    if ( v68 <= v42 || (v43 = (unsigned int)v34[3], v34[2] < (unsigned int)v43) || v68 - v42 < v43 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_process_cmd_desc",
        6506,
        "%s: Invalid offset or length",
        (const char *)v2 + 29824);
      cam_mem_put_cpu_buf(*v34);
      goto LABEL_67;
    }
    v67 += v42;
    v64 = v65 + v40;
    cam_mem_put_cpu_buf(*v34);
    v31 = v5[7];
    v33 = a1;
    v28 = v39;
    goto LABEL_51;
  }
  v45 = cpu_buf;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_process_cmd_desc",
    6497,
    "%s: get cmd buf failed %x",
    (const char *)v2 + 29824,
    *(_DWORD *)(a1 + 148));
  v13 = a1;
  v12 = v45;
  if ( v45 )
    goto LABEL_19;
  v64 = 0;
LABEL_71:
  if ( (debug_mdl & 0x1000100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000100,
      4,
      "cam_icp_mgr_prepare_hw_update",
      7410,
      "%s: req id = %lld",
      (const char *)v2 + 29824,
      *((_QWORD *)v5 + 1));
    v46 = *((void **)v2 + 3772);
    if ( v46 )
LABEL_74:
      memset(v46, 0, 0x640u);
  }
  else
  {
    v46 = *((void **)v2 + 3772);
    if ( v46 )
      goto LABEL_74;
  }
  v47 = *((void **)v2 + 3773);
  if ( v47 )
  {
    memset(v47, 0, 0x640u);
    v48 = *((_QWORD *)v2 + 3773);
  }
  else
  {
    v48 = 0;
  }
  v49 = cam_packet_util_process_patches(
          (__int64)v5,
          (__int64)a2[41],
          *(_DWORD *)(a1 + 148),
          *(_DWORD *)(a1 + 152),
          1,
          *((_QWORD **)v2 + 3772),
          v48);
  v13 = a1;
  v12 = v49;
  if ( v49 )
    goto LABEL_19;
  updated = cam_icp_mgr_update_hfi_frame_process(v2, v5, &v66);
  v13 = a1;
  v12 = updated;
  if ( updated )
    goto LABEL_19;
  v51 = v66;
  v52 = cam_icp_mgr_process_io_cfg(v2, v5, a2, v66);
  if ( v52 )
  {
    if ( (unsigned int)v51 < 0x28 )
    {
      v12 = v52;
      v55 = *(_DWORD *)&v2[4 * v51 + 4504];
      if ( v55 )
        cam_sync_destroy(v55);
      _X8 = *((unsigned __int64 **)v2 + 215);
      v54 = 1LL << v51;
LABEL_94:
      __asm { PRFM            #0x11, [X8] }
      do
        v63 = __ldxr(_X8);
      while ( __stxr(v63 & ~v54, _X8) );
      *(_QWORD *)&v2[8 * v51 + 1784] = -1;
LABEL_18:
      v13 = a1;
      goto LABEL_19;
    }
LABEL_93:
    __break(0x5512u);
    goto LABEL_94;
  }
  if ( (unsigned int)v51 > 0x28 )
    goto LABEL_93;
  cam_icp_mgr_prepare_frame_process_cmd(v2, &v2[40 * (unsigned int)v51 + 120], *((_QWORD *)v5 + 1), v64);
  v56 = (unsigned __int8 *)a2[4];
  *((_DWORD *)a2 + 10) = 1;
  v57 = debug_mdl;
  v12 = 0;
  *((_QWORD *)v56 + 2) = &v2[40 * (unsigned int)v51 + 120];
  a2[40] = (unsigned int *)&v2[64 * v51 + 26304];
  if ( (v57 & 0x100) == 0 )
    goto LABEL_18;
  v13 = a1;
  if ( !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v57 & 0x100,
      4,
      "cam_icp_mgr_prepare_hw_update",
      7452,
      "%s: X: req id = %lld",
      (const char *)v2 + 29824,
      *((_QWORD *)v5 + 1));
    v13 = a1;
    v12 = 0;
  }
LABEL_19:
  mutex_unlock(*(_QWORD *)(v13 + 88) + 48LL * *((unsigned int *)v2 + 7306));
  result = v12;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
