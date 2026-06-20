__int64 __fastcall cam_ife_csid_ver2_rdi_bottom_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v3; // w21
  __int64 v4; // x22
  _DWORD *v5; // x24
  _DWORD *v6; // x7
  __int64 v7; // x8
  __int64 v8; // x19
  unsigned int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 *v13; // x9
  int v14; // w6
  __int64 v15; // x8
  unsigned int v16; // w10
  int v17; // w23
  const char *v18; // x6
  const char *v19; // x7
  unsigned int v20; // w20
  int v22; // w8
  unsigned int v23; // w9
  int v24; // w10
  char v25; // w3
  _DWORD *v26; // x9
  void (__fastcall *v27)(__int64, __int64, __int64 *); // x8
  __int64 v28; // x0
  void (__fastcall *v29)(__int64, __int64, __int64 *); // x8
  __int64 v30; // x0
  void (__fastcall *v31)(__int64, __int64, __int64 *); // x8
  __int64 v32; // x0
  void (__fastcall *v33)(__int64, __int64, __int64 *); // x8
  __int64 v34; // x0
  unsigned int v41; // w11
  __int64 v42; // [xsp+10h] [xbp-50h] BYREF
  __int64 v43; // [xsp+18h] [xbp-48h]
  __int64 v44; // [xsp+20h] [xbp-40h]
  __int64 v45; // [xsp+28h] [xbp-38h] BYREF
  __int64 v46; // [xsp+30h] [xbp-30h]
  __int64 v47; // [xsp+38h] [xbp-28h]
  __int64 v48; // [xsp+40h] [xbp-20h]
  __int64 *v49; // [xsp+48h] [xbp-18h]
  _QWORD v50[2]; // [xsp+50h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v49 = nullptr;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  if ( a1 && a2 )
  {
    v7 = *(_QWORD *)(a1 + 16);
    v6 = *(_DWORD **)(a1 + 24);
    v50[0] = a2;
    v8 = *(_QWORD *)(*(_QWORD *)(v7 + 112) + 3680LL);
    if ( v6 )
    {
      v9 = v6[55];
      if ( v9 < 0x10 )
      {
        v10 = *(_QWORD *)(a2 + 24);
        v11 = *(_QWORD *)(a2 + 32);
        v44 = *(_QWORD *)(a2 + 40);
        v42 = v10;
        v43 = v11;
        v12 = *(_QWORD *)(v8 + 31120);
        LODWORD(v45) = 3;
        v13 = &v42;
        v14 = *(_DWORD *)(v12 + 4);
        v15 = *(unsigned int *)(a1 + 4);
        v49 = &v42;
        HIDWORD(v46) = v14;
        if ( (unsigned int)v15 >= 0xC )
        {
          __break(0x5512u);
        }
        else
        {
          if ( !*(_QWORD *)(**(_QWORD **)(v8 + 31136) + 8 * v15 + 136) )
          {
LABEL_27:
            v20 = 0;
            goto LABEL_28;
          }
          v3 = *(_DWORD *)(a2 + 16);
          v16 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 3);
          if ( (*(_BYTE *)(v8 + 2148) & 1) == 0 )
          {
            if ( v16 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_csid_ver2_rdi_bottom_half",
                3651,
                "CSID:%u bottom-half after stop [0x%x]",
                v14,
                v3);
            goto LABEL_27;
          }
          v5 = v6;
          v2 = a2;
          v4 = a1;
          if ( v16 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver2_rdi_bottom_half",
              3657,
              "CSID[%u] RDI:%d status:0x%x",
              v14,
              v15,
              v3);
          raw_spin_lock(v8 + 30968);
          if ( *(_DWORD *)(*(_QWORD *)(v8 + 31128) + 92LL) != 1 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_csid_ver2_rdi_bottom_half",
              3662,
              "CSID[%u] powered down state",
              *(_DWORD *)(*(_QWORD *)(v8 + 31120) + 4LL));
            raw_spin_unlock(v8 + 30968);
            goto LABEL_27;
          }
          v17 = cam_ife_csid_ver2_parse_path_irq_status(
                  v8,
                  v4,
                  (unsigned int)v5[55],
                  *(unsigned int *)(*((_QWORD *)v5 + 33) + 500LL),
                  *(unsigned int *)(*((_QWORD *)v5 + 33) + 504LL),
                  v3,
                  v2);
          if ( (*(_DWORD *)(*((_QWORD *)v5 + 33) + 516LL) & v3) != 0 )
            cam_ife_csid_ver2_rup_miss_handler(v8, v3);
          raw_spin_unlock(v8 + 30968);
          if ( v17 )
          {
            cam_ife_csid_ver2_handle_event_err(v8, v3, v17, 0, v4);
            goto LABEL_27;
          }
          if ( !*(_QWORD *)(v8 + 31152) )
          {
            v20 = 0;
            if ( (debug_mdl & 8) == 0 || debug_priority )
              goto LABEL_28;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver2_rdi_bottom_half",
              3685,
              "CSID[%u] no cb registered",
              *(_DWORD *)(*(_QWORD *)(v8 + 31120) + 4LL));
            goto LABEL_27;
          }
          v22 = *(_DWORD *)(v4 + 4);
          a1 = (__int64)v5;
          v47 = v3;
          LODWORD(v46) = v22;
          v15 = v2;
          if ( (v3 & 0x10000000) == 0 )
          {
LABEL_47:
            v26 = *(_DWORD **)(a1 + 264);
            if ( (v26[131] & v3) != 0 && (*(_BYTE *)(v8 + 2163) != 1 || *(_BYTE *)(a1 + 256) == 1) )
            {
              *(_QWORD *)(a1 + 32) = *(_QWORD *)(v15 + 24);
              *(_QWORD *)(a1 + 40) = *(_QWORD *)(v15 + 32);
              v27 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v8 + 31152);
              v28 = *(_QWORD *)(v8 + 31144);
              if ( *((_DWORD *)v27 - 1) != 414296116 )
                __break(0x8228u);
              v27(v28, 4, &v45);
              v26 = *((_DWORD **)v5 + 33);
              a1 = (__int64)v5;
              v15 = v2;
            }
            if ( (v26[130] & v3) != 0 )
            {
              if ( *(_BYTE *)(a1 + 116) == 1 && (*(_BYTE *)(a1 + 112) & 1) != 0 )
                BYTE4(v45) = 1;
              v29 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v8 + 31152);
              v30 = *(_QWORD *)(v8 + 31144);
              if ( *((_DWORD *)v29 - 1) != 414296116 )
                __break(0x8228u);
              v29(v30, 1, &v45);
              v26 = *((_DWORD **)v5 + 33);
              a1 = (__int64)v5;
              v15 = v2;
            }
            if ( (v26[128] & v3) != 0 )
            {
              v31 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v8 + 31152);
              v32 = *(_QWORD *)(v8 + 31144);
              if ( *((_DWORD *)v31 - 1) != 414296116 )
                __break(0x8228u);
              v31(v32, 2, &v45);
              v26 = *((_DWORD **)v5 + 33);
              a1 = (__int64)v5;
              v15 = v2;
            }
            if ( (v26[132] & v3) != 0 )
            {
              if ( *(_BYTE *)(a1 + 116) == 1 && (*(_BYTE *)(a1 + 112) & 2) != 0 )
                BYTE4(v45) = 1;
              if ( *(_BYTE *)(v8 + 2163) != 1 || *(_BYTE *)(a1 + 256) == 1 )
              {
                if ( (v45 & 0x100000000LL) == 0 && *(_BYTE *)(v8 + 32255) == 1 )
                {
                  cam_ife_csid_hw_ver2_check_for_illegal_dt();
                  a1 = (__int64)v5;
                  v15 = v2;
                }
                *(_QWORD *)(a1 + 16) = *(_QWORD *)(v15 + 24);
                *(_QWORD *)(a1 + 24) = *(_QWORD *)(v15 + 32);
                v33 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v8 + 31152);
                v34 = *(_QWORD *)(v8 + 31144);
                if ( *((_DWORD *)v33 - 1) != 414296116 )
                  __break(0x8228u);
                v33(v34, 3, &v45);
              }
            }
            goto LABEL_27;
          }
          if ( *((_BYTE *)v5 + 116) == 1 )
          {
            v23 = v5[28];
            if ( (*(_BYTE *)(v4 + 144) & 1) == 0 )
            {
              if ( (v23 & 4) == 0 )
                goto LABEL_47;
              v25 = 1;
              goto LABEL_46;
            }
            LODWORD(v13) = (v23 >> 2) & 1;
          }
          else
          {
            if ( *(_BYTE *)(v4 + 144) != 1 )
              goto LABEL_47;
            LOBYTE(v13) = 0;
          }
        }
        _X10 = (unsigned int *)(a1 + 236);
        __asm { PRFM            #0x11, [X10] }
        do
          v41 = __ldxr(_X10);
        while ( __stxr(v41 + 1, _X10) );
        v24 = *(_DWORD *)(a1 + 236);
        v25 = v24 < 6;
        if ( v24 > 5 )
          LOBYTE(v13) = 1;
        if ( ((unsigned __int8)v13 & 1) == 0 )
          goto LABEL_47;
LABEL_46:
        cam_ife_csid_ver2_handle_event_err(v8, v3, 0x4000, v25, v4);
        v15 = v2;
        a1 = (__int64)v5;
        goto LABEL_47;
      }
    }
    else
    {
      v9 = -1;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_rdi_bottom_half",
      3628,
      "CSID:%u Invalid params: path_cfg: %pK, irq_reg_idx: %d",
      *(_DWORD *)(*(_QWORD *)(v8 + 31120) + 4LL),
      v6,
      v9);
    v20 = -22;
LABEL_28:
    cam_ife_csid_ver2_put_evt_payload(v8, v50, v8 + 30952, v8 + 30972);
    goto LABEL_29;
  }
  if ( a2 )
    v18 = "Non-NULL";
  else
    v18 = "NULL";
  if ( a1 )
    v19 = "Non-NULL";
  else
    v19 = "NULL";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_rdi_bottom_half",
    3615,
    "Invalid params. evt_payload_priv: %s, handler_priv: %s",
    v18,
    v19);
  v20 = -22;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v20;
}
