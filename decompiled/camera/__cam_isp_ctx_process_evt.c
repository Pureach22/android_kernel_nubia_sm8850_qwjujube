__int64 __fastcall _cam_isp_ctx_process_evt(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x8
  int v4; // w6
  const char *v5; // x5
  __int64 v6; // x4
  unsigned int v7; // w19
  int v9; // w0
  __int64 v10; // x21
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 *v13; // x10
  __int64 (__fastcall *v14)(__int64, __int64 *); // x8
  __int64 v15; // x0
  __int64 v16; // x8
  char v17; // w10
  __int64 *v18; // x9
  __int64 v20; // x20
  __int64 (__fastcall *v21)(__int64, __int64 *); // x8
  __int64 v22; // x0
  int v23; // w10
  char v24; // w9
  const char *v25; // x6
  __int64 v26; // x8
  int v27; // w8
  __int64 *v28; // x9
  __int64 (__fastcall *v29)(__int64, __int64 *); // x8
  __int64 v30; // x0
  __int64 v32; // x20
  char v33; // w0
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x10
  __int64 v38; // x20
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 *v41; // x9
  __int64 (__fastcall *v42)(__int64, __int64 *); // x8
  __int64 v43; // x0
  __int64 v44; // x20
  unsigned int v45; // w0
  _QWORD v47[2]; // [xsp+18h] [xbp-F8h] BYREF
  __int64 v48; // [xsp+28h] [xbp-E8h]
  __int64 v49; // [xsp+30h] [xbp-E0h]
  __int64 v50; // [xsp+38h] [xbp-D8h]
  __int64 v51; // [xsp+40h] [xbp-D0h]
  __int64 v52; // [xsp+48h] [xbp-C8h]
  __int64 v53; // [xsp+50h] [xbp-C0h]
  __int64 v54; // [xsp+58h] [xbp-B8h]
  __int64 v55; // [xsp+60h] [xbp-B0h]
  __int64 v56; // [xsp+68h] [xbp-A8h]
  __int64 v57; // [xsp+70h] [xbp-A0h]
  __int64 v58; // [xsp+78h] [xbp-98h] BYREF
  __int64 v59; // [xsp+80h] [xbp-90h]
  _QWORD *v60; // [xsp+88h] [xbp-88h]
  __int64 v61; // [xsp+90h] [xbp-80h] BYREF
  __int64 v62; // [xsp+98h] [xbp-78h]
  __int64 v63; // [xsp+A0h] [xbp-70h]
  __int64 v64; // [xsp+A8h] [xbp-68h]
  __int64 v65; // [xsp+B0h] [xbp-60h]
  __int64 v66; // [xsp+B8h] [xbp-58h]
  __int64 v67; // [xsp+C0h] [xbp-50h]
  __int64 v68; // [xsp+C8h] [xbp-48h]
  __int64 v69; // [xsp+D0h] [xbp-40h]
  __int64 v70; // [xsp+D8h] [xbp-38h]
  __int64 v71; // [xsp+E0h] [xbp-30h]
  __int64 v72; // [xsp+E8h] [xbp-28h]
  __int64 v73; // [xsp+F0h] [xbp-20h] BYREF
  __int64 v74; // [xsp+F8h] [xbp-18h]
  __int64 *v75; // [xsp+100h] [xbp-10h]
  __int64 v76; // [xsp+108h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 240);
  v3 = *(_QWORD *)(a1 + 256);
  v4 = *(_DWORD *)(a2 + 20);
  v59 = 0;
  v60 = nullptr;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47[1] = 0;
  v48 = 0;
  v47[0] = 0;
  if ( v2 == 2 )
  {
    if ( v4 != 1 )
    {
      if ( v4 != 7 )
      {
        v5 = "Get unexpect evt:%d in acquired state, ctx: %u on link: 0x%x";
        v6 = 10063;
LABEL_37:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          2,
          "__cam_isp_ctx_process_evt",
          v6,
          v5);
        v7 = -22;
        goto LABEL_51;
      }
      goto LABEL_22;
    }
    goto LABEL_30;
  }
  v7 = 0;
  if ( v4 > 4 )
  {
    if ( v4 <= 6 )
    {
      if ( v4 != 5 )
        goto LABEL_51;
      if ( v2 == 5 )
      {
        if ( *(_BYTE *)(a2 + 16) == 1 )
        {
          v32 = a2;
          v33 = _cam_isp_ctx_try_internal_recovery_for_bubble(*(_QWORD *)(a2 + 8), a1);
          a2 = v32;
          if ( (v33 & 1) != 0 )
          {
            v7 = 0;
            *(_BYTE *)(v32 + 16) = 1;
            goto LABEL_51;
          }
        }
        v44 = a2;
        v45 = _cam_isp_ctx_trigger_reg_dump(3u, a1, 0);
        a2 = v44;
        v7 = v45;
      }
      else
      {
        v7 = 0;
      }
      *(_BYTE *)(a2 + 16) = 0;
      goto LABEL_51;
    }
    switch ( v4 )
    {
      case 7:
LABEL_22:
        v23 = *(_DWORD *)(a2 + 24);
        v7 = 0;
        v24 = debug_mdl;
        *(_BYTE *)(v3 + 45738) = v23 & 1;
        if ( (v24 & 8) != 0 && !debug_priority )
        {
          if ( (v23 & 1) != 0 )
            v25 = "Y";
          else
            v25 = "N";
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v24 & 8,
            4,
            "__cam_isp_ctx_process_evt",
            10112,
            "vfps_aux_context:%s on ctx: %u link: 0x%x",
            v25,
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
          v7 = 0;
        }
        goto LABEL_51;
      case 8:
        v35 = *(_QWORD *)(a1 + 264);
        v36 = *(_QWORD *)(a2 + 8);
        LODWORD(v47[0]) = 13;
        v38 = a2;
        v58 = v35;
        v39 = *(_QWORD *)(a2 + 32);
        v40 = *(_QWORD *)(a2 + 40);
        v48 = v36;
        LODWORD(v59) = 0;
        v50 = v39;
        v51 = v40;
        v41 = *(__int64 **)(a1 + 208);
        v60 = v47;
        v42 = (__int64 (__fastcall *)(__int64, __int64 *))v41[12];
        v43 = *v41;
        if ( *((_DWORD *)v42 - 1) != 1863972096 )
          __break(0x8228u);
        v7 = v42(v43, &v58);
        if ( v7 )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, unsigned int))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_process_evt",
            10130,
            "Failed to process drv info on ctx:%u link:0x%x, req_id:%llu rc:%d",
            *(unsigned int *)(a1 + 32),
            *(unsigned int *)(a1 + 64),
            *(_QWORD *)(v38 + 8),
            v7);
        goto LABEL_51;
      case 10:
        v16 = *(_QWORD *)(a1 + 264);
        v17 = *(_BYTE *)(a2 + 24);
        LODWORD(v47[0]) = 15;
        v18 = *(__int64 **)(a1 + 208);
        v58 = v16;
        v20 = a2;
        LODWORD(v59) = 0;
        LOBYTE(v48) = v17;
        v60 = v47;
        v21 = (__int64 (__fastcall *)(__int64, __int64 *))v18[12];
        v22 = *v18;
        if ( *((_DWORD *)v21 - 1) != 1863972096 )
          __break(0x8228u);
        v7 = v21(v22, &v58);
        if ( v7 )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, unsigned int))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_ctx_process_evt",
            10145,
            "Failed to process EOF register info on ctx: %u, link: 0x%x, req_id: %llu rc: %d",
            *(unsigned int *)(a1 + 32),
            *(unsigned int *)(a1 + 64),
            *(_QWORD *)(v20 + 8),
            v7);
        goto LABEL_51;
    }
LABEL_36:
    v5 = "Unsupported event type: 0x%x on ctx: %u link: 0x%x";
    v6 = 10151;
    goto LABEL_37;
  }
  if ( v4 <= 1 )
  {
    if ( !v4 )
      goto LABEL_51;
    if ( v4 == 1 )
    {
LABEL_30:
      v26 = *(_QWORD *)(a1 + 264);
      v71 = 0;
      v72 = 0;
      v69 = 0;
      v70 = 0;
      v73 = v26;
      v74 = 0;
      v27 = 1;
      v67 = 0;
      v68 = 0;
      v65 = 0;
      v66 = 0;
      v63 = 0;
      v64 = 0;
LABEL_31:
      v61 = 0;
      v62 = 0;
      v28 = *(__int64 **)(a1 + 208);
      LODWORD(v61) = v27;
      v75 = &v61;
      v29 = (__int64 (__fastcall *)(__int64, __int64 *))v28[12];
      v30 = *v28;
      if ( *((_DWORD *)v29 - 1) != 1863972096 )
        __break(0x8228u);
      v7 = v29(v30, &v73);
      goto LABEL_51;
    }
    goto LABEL_36;
  }
  if ( v4 == 2 )
  {
    v34 = *(_QWORD *)(a1 + 264);
    v71 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v65 = 0;
    v66 = 0;
    v63 = 0;
    v64 = 0;
    v73 = v34;
    v74 = 0;
    v27 = 2;
    goto LABEL_31;
  }
  if ( v4 == 3 )
  {
    v7 = _cam_isp_ctx_issue_resume_util();
  }
  else
  {
    v9 = _cam_isp_ctx_trigger_reg_dump(3u, a1, 0);
    if ( v9 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_process_evt",
        10085,
        "Reg dump on sof freeze failed ctx:%d rc:%d",
        *(_DWORD *)(a1 + 32),
        v9);
    v10 = a1;
    v11 = *(_QWORD *)(a1 + 256);
    v74 = 0;
    v71 = 0;
    v72 = 0;
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v65 = 0;
    v66 = 0;
    v63 = 0;
    v64 = 0;
    v61 = 0;
    v62 = 0;
    _cam_isp_ctx_print_event_record((__int64 *)v11);
    v12 = *(_QWORD *)(v10 + 264);
    v13 = *(__int64 **)(v10 + 208);
    LODWORD(v61) = 3;
    LODWORD(v63) = 1;
    v73 = v12;
    v14 = (__int64 (__fastcall *)(__int64, __int64 *))v13[12];
    v75 = &v61;
    v15 = *v13;
    if ( *((_DWORD *)v14 - 1) != 1863972096 )
      __break(0x8228u);
    v7 = v14(v15, &v73);
    *(_BYTE *)(v11 + 45746) = 1;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return v7;
}
