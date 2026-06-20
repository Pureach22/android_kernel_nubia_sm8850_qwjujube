__int64 __fastcall _cam_isp_ctx_apply_default_req_settings(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v7; // x21
  __int64 v9; // x8
  char v10; // w9
  __int64 *v11; // x10
  __int64 v12; // x8
  __int64 (__fastcall *v13)(__int64, __int64 *); // x8
  __int64 v14; // x0
  unsigned int v15; // w20
  unsigned int v22; // w8
  unsigned int v23; // w8
  __int64 v24; // x6
  _QWORD *v25; // x10
  _QWORD *v26; // x27
  _QWORD *v27; // x24
  _QWORD *v28; // x11
  __int64 v29; // x26
  __int64 v30; // x25
  __int64 v31; // x9
  __int64 v32; // x8
  __int64 *v33; // x8
  __int64 (__fastcall *v34)(__int64, __int64 *, __int64, __int64, __int64, __int64, __int64); // x9
  __int64 v35; // x0
  unsigned int v36; // w0
  __int64 v37; // x20
  _QWORD *v38; // [xsp+10h] [xbp-E0h]
  __int64 v39; // [xsp+18h] [xbp-D8h]
  __int64 v40; // [xsp+20h] [xbp-D0h]
  __int64 v41; // [xsp+28h] [xbp-C8h] BYREF
  __int64 v42; // [xsp+30h] [xbp-C0h]
  __int64 v43; // [xsp+38h] [xbp-B8h]
  __int64 v44; // [xsp+40h] [xbp-B0h]
  __int64 v45; // [xsp+48h] [xbp-A8h]
  __int64 v46; // [xsp+50h] [xbp-A0h]
  __int64 v47; // [xsp+58h] [xbp-98h]
  __int64 v48; // [xsp+60h] [xbp-90h]
  __int64 v49; // [xsp+68h] [xbp-88h] BYREF
  char *v50; // [xsp+70h] [xbp-80h]
  __int64 v51; // [xsp+78h] [xbp-78h]
  __int64 v52; // [xsp+80h] [xbp-70h]
  __int64 v53; // [xsp+88h] [xbp-68h]
  __int64 v54; // [xsp+90h] [xbp-60h]
  __int64 v55; // [xsp+98h] [xbp-58h]
  __int64 v56; // [xsp+A0h] [xbp-50h]
  __int64 v57; // [xsp+A8h] [xbp-48h]
  __int64 v58; // [xsp+B0h] [xbp-40h]
  __int64 v59; // [xsp+B8h] [xbp-38h]
  __int64 v60; // [xsp+C0h] [xbp-30h]
  __int64 v61; // [xsp+C8h] [xbp-28h] BYREF
  __int64 v62; // [xsp+D0h] [xbp-20h]
  __int64 *v63; // [xsp+D8h] [xbp-18h]
  char v64; // [xsp+E4h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+E8h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 256);
  v64 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  _X22 = (unsigned int *)(v7 + 45692);
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = nullptr;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  if ( *(_BYTE *)(v7 + 45751) == 1 && *(_BYTE *)(v7 + 45750) == 1 && *(__int64 *)(a2 + 16) >= 1 )
  {
    __asm { PRFM            #0x11, [X22] }
    do
    {
      v22 = __ldxr(_X22);
      v23 = v22 - 1;
    }
    while ( __stlxr(v23, _X22) );
    __dmb(0xBu);
    if ( !v23 )
    {
      v24 = *(_QWORD *)(a2 + 16);
      v26 = (_QWORD *)(a1 + 144);
      v25 = *(_QWORD **)(a1 + 144);
      if ( v25 == (_QWORD *)(a1 + 144) )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v37 = a2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_find_mup_for_default_settings",
            6100,
            "Pending list empty, unable to find mup for req: %lld ctx: %u",
            v24,
            *(_DWORD *)(a1 + 32));
          a2 = v37;
        }
      }
      else
      {
        v27 = nullptr;
        do
        {
          v28 = (_QWORD *)*v25;
          if ( v25[3] == v24 && *(_BYTE *)(v25[4] + 4368LL) == 1 )
          {
            if ( (debug_mdl & 8) == 0 || debug_priority )
            {
              v27 = v25;
            }
            else
            {
              v39 = a2;
              v40 = v24;
              v27 = v25;
              v38 = (_QWORD *)*v25;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "__cam_isp_ctx_find_mup_for_default_settings",
                6113,
                "Found mup for last applied max pd req: %lld in ctx: %u",
                v24,
                *(_DWORD *)(a1 + 32));
              v28 = v38;
              a2 = v39;
              v24 = v40;
            }
          }
          v25 = v28;
        }
        while ( v28 != v26 );
        if ( v27 )
        {
          v29 = v27[4];
          v30 = a2;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "__cam_isp_ctx_apply_default_req_settings",
              6144,
              "Applying IQ for mode switch req: %lld ctx: %u",
              v27[3],
              *(_DWORD *)(a1 + 32));
          v31 = *(_QWORD *)(v7 + 37296);
          v47 = v27[3];
          v32 = *(_QWORD *)(v29 + 8);
          v41 = v31;
          v43 = v32;
          LODWORD(v32) = *(_DWORD *)(v29 + 16);
          v46 = v29 + 80;
          LOBYTE(v31) = *(_BYTE *)(v29 + 4505);
          BYTE4(v48) = 0;
          LODWORD(v42) = v32;
          v33 = *(__int64 **)(a1 + 208);
          LODWORD(v48) = 1;
          BYTE5(v48) = v31;
          v34 = (__int64 (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64, __int64, __int64))v33[9];
          v35 = *v33;
          if ( *((_DWORD *)v34 - 1) != 1863972096 )
            __break(0x8229u);
          v36 = v34(v35, &v41, a3, a4, a5, a6, v24);
          if ( v36 )
          {
            v15 = v36;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_apply_default_req_settings",
              6158,
              "Failed to apply req: %lld IQ settings in ctx: %u",
              v27[3],
              *(_DWORD *)(a1 + 32));
            goto LABEL_14;
          }
          a2 = v30;
          v64 = 1;
          *(_DWORD *)(v29 + 4448) = 2;
        }
      }
    }
  }
  if ( *(_BYTE *)(v7 + 45747) != 1 )
    goto LABEL_13;
  v9 = *(_QWORD *)(v7 + 37296);
  v10 = *(_BYTE *)(a2 + 43);
  LODWORD(v49) = 7;
  v11 = *(__int64 **)(a1 + 208);
  v61 = v9;
  v12 = *(_QWORD *)(a2 + 16);
  LOBYTE(v52) = v10;
  v50 = &v64;
  v51 = v12;
  LODWORD(v62) = 0;
  v63 = &v49;
  v13 = (__int64 (__fastcall *)(__int64, __int64 *))v11[12];
  v14 = *v11;
  if ( *((_DWORD *)v13 - 1) != 1863972096 )
    __break(0x8228u);
  v15 = v13(v14, &v61);
  if ( v15 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_apply_default_req_settings",
      6186,
      "Failed to apply default settings rc %d ctx %u, link: 0x%x",
      v15,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    goto LABEL_14;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_apply_default_req_settings",
      6189,
      "Applied default settings rc %d ctx: %u link: 0x%x",
      0,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
LABEL_13:
    v15 = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v15;
}
