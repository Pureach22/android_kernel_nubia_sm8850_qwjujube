__int64 __fastcall dp_catalog_panel_setup_vsc_sdp(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v3; // w9
  _DWORD **v4; // x23
  bool v5; // w10
  unsigned __int8 v6; // w11
  unsigned int v7; // w10
  unsigned int v8; // w12
  __int64 v9; // x0
  __int64 v10; // x20
  int v11; // w22
  _DWORD *v12; // x8
  __int64 v13; // x1
  unsigned int v14; // w3
  bool v15; // w8
  unsigned __int8 v16; // w9
  unsigned int v17; // w8
  unsigned int v18; // w10
  __int64 v19; // x3
  _DWORD *v20; // x8
  unsigned int v21; // w8
  bool v22; // w9
  unsigned __int8 v23; // w10
  unsigned int v24; // w9
  unsigned int v25; // w11
  int v26; // w24
  _DWORD *v27; // x8
  unsigned int v28; // w0
  _DWORD *v29; // x8
  _DWORD *v30; // x8
  _DWORD *v31; // x8
  _DWORD *v32; // x8
  _DWORD *v33; // x8
  __int64 v34; // x3
  _DWORD *v35; // x8
  _DWORD *v36; // x8
  _DWORD *v37; // x8
  _DWORD *v38; // x8
  __int64 v40; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 204);
    if ( v1 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_setup_vsc_sdp");
    }
    else
    {
      v3 = *(unsigned __int8 *)(a1 + 33);
      v4 = (_DWORD **)(a1 - 448);
      v5 = (v3 & 8) != 0;
      v6 = v5 ^ v3 & 0xF;
      v7 = (v6 & 1
          | (4 * (((*(_BYTE *)(a1 + 33) >> 2) & 3 ^ (*(_BYTE *)(a1 + 33) >> 1) & 7) & 1)) & 0xF5
          | (8 * (((*(_BYTE *)(a1 + 33) >> 2) & 3 ^ v5) & 1))
          | (2 * ((v6 ^ (*(_BYTE *)(a1 + 33) >> 1) & 7) & 1)))
         ^ (v3 >> 4);
      v9 = a1 - 576;
      v10 = *(_QWORD *)(a1 - 552);
      if ( v1 == 1 )
        v11 = 400;
      else
        v11 = 0;
      v12 = *v4;
      v13 = *(_QWORD *)(a1 - 552);
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      v8 = v7 >> 3;
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v12)(
        v9,
        v13,
        (unsigned int)(v11 + 768),
        ((((v8 ^ v7) & 1
         | (4 * (((unsigned __int8)(v7 >> 2) ^ (unsigned __int8)(v7 >> 1)) & 1)) & 0xF5
         | (8 * (((v7 >> 2) ^ v8) & 1))
         | (2 * (((unsigned __int8)(v8 ^ v7) ^ (unsigned __int8)(v7 >> 1)) & 1)))
        ^ ((2 * v3) & 0xC | (2 * (v6 & 1)) | (v3 >> 3) & 1)) << 24)
      | (((2 * v7) & 0xC | (2 * ((v8 ^ v7) & 1)) | v8) << 28)
      | (v3 << 16));
      v14 = *(unsigned __int8 *)(a1 + 34);
      v15 = (v14 & 8) != 0;
      v16 = v15 ^ v14 & 0xF;
      v17 = (v16 & 1
           | (4 * (((*(_BYTE *)(a1 + 34) >> 2) & 3 ^ (*(_BYTE *)(a1 + 34) >> 1) & 7) & 1)) & 0xF5
           | (8 * (((*(_BYTE *)(a1 + 34) >> 2) & 3 ^ v15) & 1))
           | (2 * ((v16 ^ (*(_BYTE *)(a1 + 34) >> 1) & 7) & 1)))
          ^ (v14 >> 4);
      v18 = v17 >> 3;
      v19 = v14 & 0xFFFF00FF
          | (((((unsigned __int8)v18 ^ (unsigned __int8)v17) & 1
             | (4 * (((unsigned __int8)(v17 >> 2) ^ (unsigned __int8)(v17 >> 1)) & 1)) & 0xF5
             | (unsigned __int8)(8 * (((v17 >> 2) ^ v18) & 1))
             | (unsigned __int8)(2 * ((v18 ^ v17 ^ (v17 >> 1)) & 1)))
            ^ ((2 * (_BYTE)v14) & 0xC | (unsigned __int8)(2 * (v16 & 1)) | ((v14 & 8) != 0))
            | (unsigned __int8)(16 * ((2 * v17) & 0xC | (2 * ((v18 ^ v17) & 1)) | v18))) << 8);
      v20 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v20)(a1 - 576, v10, (unsigned int)(v11 + 772), v19);
      v21 = *(unsigned __int8 *)(a1 + 35);
      v22 = (v21 & 8) != 0;
      v23 = v22 ^ v21 & 0xF;
      v24 = (v23 & 1
           | (4 * (((*(_BYTE *)(a1 + 35) >> 2) & 3 ^ (*(_BYTE *)(a1 + 35) >> 1) & 7) & 1)) & 0xF5
           | (8 * (((*(_BYTE *)(a1 + 35) >> 2) & 3 ^ v22) & 1))
           | (2 * ((v23 ^ (*(_BYTE *)(a1 + 35) >> 1) & 7) & 1)))
          ^ (v21 >> 4);
      v25 = v24 >> 3;
      v26 = ((((v25 ^ v24) & 1
             | (4 * (((unsigned __int8)(v24 >> 2) ^ (unsigned __int8)(v24 >> 1)) & 1)) & 0xF5
             | (8 * (((v24 >> 2) ^ v25) & 1))
             | (2 * (((unsigned __int8)(v25 ^ v24) ^ (unsigned __int8)(v24 >> 1)) & 1)))
            ^ ((2 * v21) & 0xC | (2 * (v23 & 1)) | (v21 >> 3) & 1)) << 24)
          | (((2 * v24) & 0xC | (2 * ((v25 ^ v24) & 1)) | v25) << 28)
          | (v21 << 16);
      v27 = *(_DWORD **)(a1 - 456);
      if ( *(v27 - 1) != -1879227436 )
        __break(0x8228u);
      v28 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v27)(a1 - 576, v10, (unsigned int)(v11 + 772));
      v29 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v29)(a1 - 576, v10, (unsigned int)(v11 + 772), v26 | v28);
      v30 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v30)(a1 - 576, v10, (unsigned int)(v11 + 776), 0);
      v31 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v31)(a1 - 576, v10, (unsigned int)(v11 + 780), 0);
      v32 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v32)(a1 - 576, v10, (unsigned int)(v11 + 784), 0);
      v33 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v33)(a1 - 576, v10, (unsigned int)(v11 + 788), 0);
      v34 = *(unsigned __int16 *)(a1 + 52) | ((unsigned __int8)(*(_BYTE *)(a1 + 54) & 7) << 16);
      v35 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v35)(a1 - 576, v10, (unsigned int)(v11 + 792), v34);
      v36 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v36)(a1 - 576, v10, (unsigned int)(v11 + 796), 0);
      v37 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v37)(a1 - 576, v10, (unsigned int)(v11 + 800), 0);
      v38 = *v4;
      if ( *(*v4 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v38)(
               a1 - 576,
               v10,
               (unsigned int)(v11 + 804),
               0);
    }
  }
  else
  {
    v40 = get_ipc_log_context(0);
    ipc_log_string(v40, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_setup_vsc_sdp");
  }
}
