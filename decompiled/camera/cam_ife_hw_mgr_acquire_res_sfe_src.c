__int64 __fastcall cam_ife_hw_mgr_acquire_res_sfe_src(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v9; // x7
  __int64 *v10; // x20
  __int64 *v11; // x23
  __int64 v12; // x24
  __int64 v13; // x28
  int v14; // w21
  __int64 v15; // x27
  unsigned __int64 v16; // x25
  int v17; // w23
  unsigned int v18; // w8
  unsigned int v19; // w28
  __int64 v20; // x20
  _QWORD *v21; // x24
  _QWORD *v22; // x8
  __int64 v23; // x9
  __int64 v24; // x9
  char v25; // w8
  __int64 v26; // x8
  _QWORD *v27; // x1
  unsigned int v28; // w25
  _QWORD *v29; // x21
  __int64 v30; // x8
  __int64 v31; // x26
  __int64 *v32; // x8
  __int64 v33; // x8
  __int64 (__fastcall *v34)(__int64, __int64 *, __int64); // x9
  __int64 v35; // x0
  unsigned int v36; // w0
  __int64 v37; // x8
  __int64 v38; // x6
  int v39; // w8
  int v40; // w8
  const char *v41; // x6
  unsigned int v42; // w27
  unsigned __int64 v49; // x10
  _QWORD *v51; // [xsp+20h] [xbp-C0h]
  _QWORD *v52; // [xsp+28h] [xbp-B8h]
  __int64 v55; // [xsp+40h] [xbp-A0h] BYREF
  __int64 v56; // [xsp+48h] [xbp-98h] BYREF
  __int64 v57; // [xsp+50h] [xbp-90h]
  __int64 v58; // [xsp+58h] [xbp-88h]
  __int64 (__fastcall *v59)(__int64, unsigned int, _DWORD *); // [xsp+60h] [xbp-80h]
  __int64 v60; // [xsp+68h] [xbp-78h]
  __int64 v61; // [xsp+70h] [xbp-70h]
  __int64 v62; // [xsp+78h] [xbp-68h]
  __int64 v63; // [xsp+80h] [xbp-60h]
  __int64 v64; // [xsp+88h] [xbp-58h]
  __int64 v65; // [xsp+90h] [xbp-50h]
  __int64 v66; // [xsp+98h] [xbp-48h]
  _QWORD v67[8]; // [xsp+A0h] [xbp-40h] BYREF

  v9 = 0;
  v67[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (__int64 *)(a1 + 208);
  v11 = *(__int64 **)(a1 + 208);
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = nullptr;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  memset(v67, 0, 48);
  if ( v11 != (__int64 *)(a1 + 208) )
  {
    v12 = *(_QWORD *)(a1 + 72);
    v13 = 0;
    while ( 1 )
    {
      if ( *((_DWORD *)v11 + 27) )
        goto LABEL_5;
      v14 = *((_DWORD *)v11 + 5);
      if ( v14 <= 2 )
        break;
      if ( v14 <= 4 )
      {
        if ( v14 != 3 )
        {
          v13 = 5;
          if ( !*(_DWORD *)(a2 + 144) )
            goto LABEL_29;
LABEL_24:
          v15 = 0;
          v16 = 0;
          while ( (unsigned int)cam_ife_hw_mgr_get_ife_csid_rdi_res_type(*(_DWORD *)(*(_QWORD *)(a2 + 224) + v15)) != v14 )
          {
            ++v16;
            v15 += 44;
            if ( v16 >= *(unsigned int *)(a2 + 144) )
            {
              v9 = v55;
              goto LABEL_29;
            }
          }
          v9 = v55 | (1LL << v13);
          v55 = v9;
          v67[v13] = v11;
LABEL_29:
          if ( (v9 & 1) != 0
            || *(_DWORD *)(a2 + 184) && *(_BYTE *)(a2 + 222) != 1
            || 1LL << *((_DWORD *)v11 + 5) != *(_DWORD *)(v12 + 80488) )
          {
            goto LABEL_5;
          }
          goto LABEL_4;
        }
        v13 = 4;
        goto LABEL_23;
      }
      if ( v14 == 6 )
        goto LABEL_5;
      if ( v14 != 5 )
        goto LABEL_23;
      v13 = 0;
LABEL_4:
      v9 |= 1uLL;
      v67[0] = v11;
      v55 = v9;
LABEL_5:
      v11 = (__int64 *)*v11;
      if ( v11 == v10 )
        goto LABEL_36;
    }
    switch ( v14 )
    {
      case 0:
        v13 = 1;
        if ( *(_DWORD *)(a2 + 144) )
          goto LABEL_24;
        goto LABEL_29;
      case 1:
        v13 = 2;
        if ( *(_DWORD *)(a2 + 144) )
          goto LABEL_24;
        goto LABEL_29;
      case 2:
        v13 = 3;
        if ( *(_DWORD *)(a2 + 144) )
          goto LABEL_24;
        goto LABEL_29;
    }
LABEL_23:
    if ( !*(_DWORD *)(a2 + 144) )
      goto LABEL_29;
    goto LABEL_24;
  }
LABEL_36:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_res_sfe_src",
      3733,
      "ctx: %u Required SFE in resources: 0x%x",
      *(_DWORD *)(a1 + 56),
      v9);
    LODWORD(v9) = v55;
    v17 = 0;
    if ( v55 )
      goto LABEL_39;
  }
  else
  {
    v17 = 0;
    if ( v9 )
    {
LABEL_39:
      v51 = (_QWORD *)(a1 + 240);
      v52 = (_QWORD *)(a1 + 288);
      do
      {
        v18 = __clz(__rbit32(v9));
        if ( (_DWORD)v9 )
          v19 = v18;
        else
          v19 = -1;
        _X9 = (unsigned __int64 *)(&v55 + (v19 >> 6));
        __asm { PRFM            #0x11, [X9] }
        do
          v49 = __ldxr(_X9);
        while ( __stxr(v49 & ~(1LL << v19), _X9) );
        LODWORD(v62) = v19;
        if ( v19 > 5 )
        {
LABEL_101:
          __break(0x5512u);
          __break(1u);
        }
        v20 = v67[v19];
        v21 = (_QWORD *)*v52;
        if ( (_QWORD *)*v52 == v52 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_get_res",
            2078,
            "No more free ife hw mgr ctx");
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_acquire_res_sfe_src_util",
            3595,
            "Ctx : %u failed to get res",
            *(_DWORD *)(a1 + 56));
          v42 = -1;
          goto LABEL_95;
        }
        v22 = (_QWORD *)v21[1];
        if ( (_QWORD *)*v22 == v21 && (v23 = *v21, *(_QWORD **)(*v21 + 8LL) == v21) )
        {
          *(_QWORD *)(v23 + 8) = v22;
          *v22 = v23;
        }
        else
        {
          _list_del_entry_valid_or_report(*v52);
        }
        *v21 = v21;
        v21[1] = v21;
        LODWORD(v56) = 10;
        v24 = *(_QWORD *)(a1 + 8728);
        v25 = *(_BYTE *)(a1 + 9380);
        v65 = a2;
        v63 = v24;
        LOBYTE(v66) = v25;
        v26 = *(_QWORD *)(a1 + 16);
        v58 = a1;
        v59 = cam_ife_hw_mgr_event_handler;
        LODWORD(v24) = *(_DWORD *)(v20 + 24);
        v57 = v26;
        LODWORD(v64) = v24;
        if ( v21 )
        {
          v27 = *(_QWORD **)(a1 + 248);
          if ( v21 == v51 || v27 == v21 || (_QWORD *)*v27 != v51 )
          {
            _list_add_valid_or_report(v21);
          }
          else
          {
            *(_QWORD *)(a1 + 248) = v21;
            *v21 = v51;
            v21[1] = v27;
            *v27 = v21;
          }
        }
        *((_DWORD *)v21 + 4) = v56;
        *((_DWORD *)v21 + 5) = v62;
        v28 = *(_DWORD *)(v20 + 24);
        *((_DWORD *)v21 + 6) = v28;
        *((_BYTE *)v21 + 120) = *(_BYTE *)(v20 + 120);
        if ( (v28 & 0x80000000) != 0 )
        {
LABEL_40:
          ++*(_DWORD *)(v20 + 108);
          goto LABEL_41;
        }
        v29 = v21 + 4;
        while ( 1 )
        {
          v30 = 64;
          if ( !v28 )
            v30 = 60;
          v31 = *(unsigned int *)(a1 + v30);
          if ( (unsigned int)v31 > 2 || (v32 = *(__int64 **)(*(_QWORD *)(a1 + 72) + 8 * v31 + 224)) == nullptr )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_hw_mgr_acquire_sfe_hw",
              3564,
              "the hw index:%d is wrong",
              a7);
            v42 = -22;
            goto LABEL_88;
          }
          v33 = *v32;
          v34 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v33 + 40);
          v35 = *(_QWORD *)(v33 + 112);
          if ( *((_DWORD *)v34 - 1) != 1989616049 )
            __break(0x8229u);
          v36 = v34(v35, &v56, 88);
          if ( v36 )
            break;
          v37 = v61;
          if ( !v61 )
          {
            v42 = 0;
            goto LABEL_88;
          }
          if ( v28 >= 2 )
            goto LABEL_101;
          v29[v28] = v61;
          v38 = *(unsigned int *)(*(_QWORD *)(v37 + 16) + 4LL);
          if ( g_num_sfe_available <= (unsigned int)v38 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_convert_hw_idx_to_sfe_hw_num",
              3426,
              "SFE hw idx %d out-of-bounds max available %u",
              v38,
              g_num_sfe_available);
LABEL_73:
            v39 = 0;
            goto LABEL_74;
          }
          if ( (unsigned int)v38 >= 3 )
            goto LABEL_73;
          v39 = dword_451498[v38];
LABEL_74:
          *a3 |= v39;
          a7 = *(unsigned int *)(v29[v28] + 4LL);
          if ( (unsigned int)a7 >= 6 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_convert_sfe_res_to_path",
              3514,
              "SFE res path invalid res_id: 0x%x",
              a7);
            v40 = 0;
          }
          else
          {
            v40 = dword_4514A4[a7];
          }
          *(_DWORD *)(a4 + 4LL * v28) |= v40;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            if ( v28 )
              v41 = "RIGHT";
            else
              v41 = "LEFT";
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_acquire_res_sfe_src_util",
              3642,
              "acquire success %s SFE: %u res_name: %s res_type: %u res_id: %u ctx_idx: %u",
              v41,
              *(_DWORD *)(*(_QWORD *)(v29[v28] + 16LL) + 4LL),
              (const char *)(v29[v28] + 128LL),
              *(_DWORD *)v29[v28],
              *(_DWORD *)(v29[v28] + 4LL),
              *(_DWORD *)(a1 + 56));
          }
          _ZF = v28 == 1;
          v28 = 0;
          if ( !_ZF )
            goto LABEL_40;
        }
        v42 = v36;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_acquire_sfe_hw",
            3575,
            "Can not acquire SFE HW: %d for res: %d ctx_idx: %u",
            v31,
            v62,
            *(_DWORD *)(a1 + 56));
LABEL_88:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_acquire_res_sfe_src_util",
          3623,
          "Failed to acquire split_id: %d SFE for res_type: %u id: %u ctx_idx: %u",
          v28,
          *((_DWORD *)v21 + 4),
          *((_DWORD *)v21 + 5),
          *(_DWORD *)(a1 + 56));
        if ( v42 )
        {
LABEL_95:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_hw_mgr_acquire_res_sfe_src",
            3754,
            "Acquire SFE failed ctx: %u acquired_res 0x%x sfe_res %u ctx_idx: %u",
            *(_DWORD *)(a1 + 56),
            v17,
            v19,
            *(_DWORD *)(a1 + 56));
          goto LABEL_100;
        }
LABEL_41:
        LODWORD(v9) = v55;
        v17 |= v19;
      }
      while ( v55 );
    }
  }
  v42 = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_res_sfe_src",
      3749,
      "ctx: %u Acquired SFE in resources: 0x%x",
      *(_DWORD *)(a1 + 56),
      v17);
    v42 = 0;
  }
LABEL_100:
  _ReadStatusReg(SP_EL0);
  return v42;
}
