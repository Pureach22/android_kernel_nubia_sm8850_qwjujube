__int64 __fastcall dp_catalog_panel_config_spd(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x19
  _DWORD **v3; // x25
  __int64 v4; // x21
  _DWORD *v5; // x9
  __int64 v6; // x20
  int v7; // w27
  __int64 v8; // x0
  int v9; // w22
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x24
  _DWORD **v12; // x26
  _DWORD *v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x0
  int v16; // w22
  __int64 v17; // x0
  _DWORD *v18; // x8
  _DWORD *v19; // x8
  __int64 v20; // x0
  int v21; // w22
  __int64 v22; // x0
  _DWORD *v23; // x8
  _BYTE *v24; // x22
  _BYTE *v25; // x23
  _DWORD *v26; // x9
  __int64 v27; // x3
  _DWORD *v28; // x9
  __int64 v29; // x3
  _DWORD *v30; // x9
  __int64 v31; // x3
  _DWORD *v32; // x9
  __int64 v33; // x3
  _DWORD *v34; // x9
  __int64 v35; // x3
  _DWORD *v36; // x9
  __int64 v37; // x3
  _DWORD *v38; // x8
  _DWORD *v39; // x8
  _DWORD *v40; // x9
  int v41; // w22
  int v42; // w0
  _DWORD *v43; // x8
  _DWORD *v44; // x8
  int v45; // w0
  _DWORD *v46; // x8
  __int64 v47; // x0
  unsigned int v48; // w8
  __int64 v49; // x0
  __int64 v50; // x19
  _DWORD *v51; // x10
  unsigned int v52; // w21
  __int64 v53; // x1
  _DWORD *v54; // x8
  __int64 v55; // x0
  __int64 *v56; // [xsp+8h] [xbp-8h]

  if ( result )
  {
    v1 = *(_DWORD *)(result + 204);
    v2 = result;
    if ( v1 <= 1 )
    {
      v3 = (_DWORD **)(result - 456);
      v4 = *(_QWORD *)(result - 552);
      v56 = (__int64 *)(result - 552);
      v5 = *(_DWORD **)(result - 456);
      v6 = result - 576;
      if ( v1 == 1 )
        v7 = 400;
      else
        v7 = 0;
      if ( *(v5 - 1) != -1879227436 )
        __break(0x8229u);
      v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v5)(result - 576, v4, (unsigned int)(v7 + 808));
      v9 = v8;
      ipc_log_context = get_ipc_log_context(v8);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        ipc_log_context,
        "[d][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
        *(_DWORD *)(StatusReg + 1800),
        v9 | 0x92830000,
        146);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]Header Byte 1: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(StatusReg + 1800),
          v9 | 0x92830000,
          146);
      v12 = (_DWORD **)(v2 - 448);
      v13 = *(_DWORD **)(v2 - 448);
      if ( *(v13 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v13)(
        v2 - 576,
        v4,
        (unsigned int)(v7 + 808),
        v9 | 0x92830000);
      v14 = *v3;
      if ( *(*v3 - 1) != -1879227436 )
        __break(0x8228u);
      v15 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v14)(v2 - 576, v4, (unsigned int)(v7 + 812));
      v16 = v15;
      v17 = get_ipc_log_context(v15);
      ipc_log_string(
        v17,
        "[d][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
        *(_DWORD *)(StatusReg + 1800),
        v16 | 0xD71B,
        215);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]Header Byte 2: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(StatusReg + 1800),
          v16 | 0xD71B,
          215);
      v18 = *v12;
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v18)(
        v2 - 576,
        v4,
        (unsigned int)(v7 + 812),
        v16 | 0xD71Bu);
      v19 = *v3;
      if ( *(*v3 - 1) != -1879227436 )
        __break(0x8228u);
      v20 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v19)(v2 - 576, v4, (unsigned int)(v7 + 812));
      v21 = v20;
      v22 = get_ipc_log_context(v20);
      ipc_log_string(
        v22,
        "[d][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
        *(_DWORD *)(StatusReg + 1800),
        72,
        209);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]Header Byte 3: value = 0x%x, parity_byte = 0x%x\n",
          *(_DWORD *)(StatusReg + 1800),
          72,
          209);
      v23 = *v12;
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v23)(
        v2 - 576,
        v4,
        (unsigned int)(v7 + 812),
        v21 | 0xD1480000);
      v25 = *(_BYTE **)(v2 + 16);
      v24 = *(_BYTE **)(v2 + 24);
      v26 = *v12;
      v27 = *v25 & 0x7F | ((v25[1] & 0x7F) << 8) | ((v25[2] & 0x7F) << 16) & 0x80FFFFFF | ((v25[3] & 0x7F) << 24);
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v26)(v2 - 576, v4, (unsigned int)(v7 + 816), v27);
      v28 = *v12;
      v29 = v25[4] & 0x7F | ((v25[5] & 0x7F) << 8) | ((v25[6] & 0x7F) << 16) & 0x80FFFFFF | ((v25[7] & 0x7F) << 24);
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v28)(v2 - 576, v4, (unsigned int)(v7 + 820), v29);
      v30 = *v12;
      v31 = *v24 & 0x7F | ((v24[1] & 0x7F) << 8) | ((v24[2] & 0x7F) << 16) & 0x80FFFFFF | ((v24[3] & 0x7F) << 24);
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v30)(v2 - 576, v4, (unsigned int)(v7 + 824), v31);
      v32 = *v12;
      v33 = v24[4] & 0x7F | ((v24[5] & 0x7F) << 8) | ((v24[6] & 0x7F) << 16) & 0x80FFFFFF | ((v24[7] & 0x7F) << 24);
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v32)(v2 - 576, v4, (unsigned int)(v7 + 828), v33);
      v34 = *v12;
      v35 = v24[8] & 0x7F | ((v24[9] & 0x7F) << 8) | ((v24[10] & 0x7F) << 16) & 0x80FFFFFF | ((v24[11] & 0x7F) << 24);
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v34)(v2 - 576, v4, (unsigned int)(v7 + 832), v35);
      v36 = *v12;
      v37 = v24[12] & 0x7F | ((v24[13] & 0x7F) << 8) | ((v24[14] & 0x7F) << 16) & 0x80FFFFFF | ((v24[15] & 0x7F) << 24);
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v36)(v2 - 576, v4, (unsigned int)(v7 + 836), v37);
      v38 = *v12;
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v38)(v2 - 576, v4, (unsigned int)(v7 + 840), 0);
      v39 = *v12;
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v39)(v2 - 576, v4, (unsigned int)(v7 + 844), 0);
      v40 = *v3;
      if ( *(_DWORD *)(v2 + 204) == 1 )
        v41 = 696;
      else
        v41 = 0;
      if ( *(v40 - 1) != -1879227436 )
        __break(0x8229u);
      v42 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v40)(v2 - 576, v4, (unsigned int)(v41 + 552));
      v43 = *v12;
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v43)(
        v2 - 576,
        v4,
        (unsigned int)(v41 + 552),
        v42 | 0x40000u);
      v44 = *v3;
      if ( *(*v3 - 1) != -1879227436 )
        __break(0x8228u);
      v45 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v44)(v2 - 576, v4, (unsigned int)(v41 + 556));
      v46 = *v12;
      if ( *(*v12 - 1) != -626862723 )
        __break(0x8228u);
      v47 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v46)(
              v2 - 576,
              v4,
              (unsigned int)(v41 + 556),
              v45 | 0x20000u);
      v48 = *(_DWORD *)(v2 + 204);
      if ( v48 >= 2 )
      {
        v55 = get_ipc_log_context(v47);
        ipc_log_string(v55, "[e][%-4d]invalid stream_id:%d\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(v2 + 204));
        return printk(&unk_272496, "dp_catalog_panel_sdp_update");
      }
      else
      {
        v49 = v2 - 576;
        v50 = *v56;
        v51 = *v12;
        if ( v48 == 1 )
          v52 = 1256;
        else
          v52 = 588;
        v53 = *v56;
        if ( *(v51 - 1) != -626862723 )
          __break(0x822Au);
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v51)(v49, v53, v52, 1);
        v54 = *v12;
        if ( *(*v12 - 1) != -626862723 )
          __break(0x8228u);
        return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v54)(v6, v50, v52, 0);
      }
    }
  }
  return result;
}
