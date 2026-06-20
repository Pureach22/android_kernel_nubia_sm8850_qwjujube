__int64 __fastcall cam_ife_csid_ver2_ipp_bottom_half(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x24
  char **irq_reg_tag_ptr; // x0
  unsigned int v9; // w8
  __int64 v10; // x11
  __int64 v11; // x12
  unsigned int v12; // w23
  __int64 v13; // x8
  __int64 v14; // x10
  unsigned int v15; // w8
  int *v16; // x8
  int *v17; // x9
  int *v18; // x10
  int *v19; // x11
  int *v20; // x12
  const char *v21; // x6
  const char *v22; // x7
  unsigned int v23; // w20
  __int64 v25; // x0
  int *v26; // x12
  int v27; // w10
  int v28; // w25
  int v29; // w24
  int v30; // w26
  void (__fastcall *v31)(__int64, __int64, __int64 *); // x8
  __int64 v32; // x0
  void (__fastcall *v33)(__int64, __int64, __int64 *); // x8
  __int64 v34; // x0
  void (__fastcall *v35)(__int64, __int64, __int64 *); // x8
  __int64 v36; // x0
  void (__fastcall *v37)(__int64, __int64, __int64 *); // x8
  __int64 v38; // x0
  int v39; // w25
  int v40; // w21
  int v41; // w2
  const char *v42; // x7
  unsigned int v49; // w9
  __int64 v50; // [xsp+10h] [xbp-50h] BYREF
  __int64 v51; // [xsp+18h] [xbp-48h]
  __int64 v52; // [xsp+20h] [xbp-40h]
  __int64 v53; // [xsp+28h] [xbp-38h] BYREF
  __int64 v54; // [xsp+30h] [xbp-30h]
  __int64 v55; // [xsp+38h] [xbp-28h]
  __int64 v56; // [xsp+40h] [xbp-20h]
  __int64 *v57; // [xsp+48h] [xbp-18h]
  _QWORD v58[2]; // [xsp+50h] [xbp-10h] BYREF

  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v57 = nullptr;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 16);
    v5 = *(_QWORD *)(a1 + 24);
    v58[0] = a2;
    v6 = *(_QWORD *)(*(_QWORD *)(v4 + 112) + 3680LL);
    v7 = **(_QWORD **)(v6 + 31136);
    irq_reg_tag_ptr = cam_ife_csid_get_irq_reg_tag_ptr();
    if ( v5 )
    {
      v9 = *(_DWORD *)(v5 + 220);
      if ( v9 < 0x10 )
      {
        v10 = *(_QWORD *)(a2 + 32);
        v11 = *(_QWORD *)(a2 + 40);
        v12 = *(_DWORD *)(a2 + 16);
        v50 = *(_QWORD *)(a2 + 24);
        v51 = v10;
        v52 = v11;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          if ( (*(_BYTE *)(a2 + 48) & 1) != 0 )
            v42 = "COMP_IRQ";
          else
            v42 = irq_reg_tag_ptr[v9];
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver2_ipp_bottom_half",
            3398,
            "CSID[%u] %s status:0x%x",
            *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
            v42,
            v12);
          if ( (*(_BYTE *)(v6 + 2148) & 1) != 0 )
          {
LABEL_8:
            v13 = *(_QWORD *)(v6 + 31120);
            v14 = *(_QWORD *)(v6 + 31152);
            LODWORD(v53) = 3;
            HIDWORD(v54) = *(_DWORD *)(v13 + 4);
            v55 = v12;
            v57 = &v50;
            if ( !v14 )
            {
              if ( (unsigned int)__ratelimit(
                                   &cam_ife_csid_ver2_ipp_bottom_half__rs,
                                   "cam_ife_csid_ver2_ipp_bottom_half") )
                v25 = 3;
              else
                v25 = 2;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                v25,
                8,
                1,
                "cam_ife_csid_ver2_ipp_bottom_half",
                3414,
                "CSID[%u] event cb not registered",
                *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL));
LABEL_65:
              v23 = 0;
              goto LABEL_21;
            }
            v15 = *(_DWORD *)(a1 + 4);
            if ( v15 >= 0xC )
            {
              __break(0x5512u);
            }
            else
            {
              if ( *(_BYTE *)(a2 + 48) == 1 )
              {
                v16 = *(int **)(v7 + 240);
                v17 = v16 + 3;
                v18 = v16 + 4;
                v19 = v16 + 6;
                v20 = v16 + 5;
                v15 = 5;
              }
              else
              {
                v26 = *(int **)(v5 + 264);
                v17 = v26 + 130;
                v18 = v26 + 131;
                v19 = v26 + 128;
                v20 = v26 + 132;
              }
              v27 = *v18;
              v28 = *v19;
              v29 = *v20;
              v30 = *v17;
              LODWORD(v54) = v15;
              if ( (v27 & v12) != 0 && (*(_BYTE *)(v6 + 2163) != 1 || *(_BYTE *)(v5 + 256) == 1) )
              {
                *(_QWORD *)(v5 + 32) = *(_QWORD *)(a2 + 24);
                *(_QWORD *)(v5 + 40) = *(_QWORD *)(a2 + 32);
                v31 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v6 + 31152);
                v32 = *(_QWORD *)(v6 + 31144);
                if ( *((_DWORD *)v31 - 1) != 414296116 )
                  __break(0x8228u);
                v31(v32, 4, &v53);
              }
              if ( (v30 & v12) != 0 )
              {
                v33 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v6 + 31152);
                v34 = *(_QWORD *)(v6 + 31144);
                if ( *((_DWORD *)v33 - 1) != 414296116 )
                  __break(0x8228u);
                v33(v34, 1, &v53);
              }
              if ( (v28 & v12) != 0 )
              {
                v35 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v6 + 31152);
                v36 = *(_QWORD *)(v6 + 31144);
                if ( *((_DWORD *)v35 - 1) != 414296116 )
                  __break(0x8228u);
                v35(v36, 2, &v53);
              }
              if ( (v29 & v12) != 0 && (*(_BYTE *)(v6 + 2163) != 1 || *(_BYTE *)(v5 + 256) == 1) )
              {
                if ( *(_BYTE *)(v6 + 32255) == 1 )
                  cam_ife_csid_hw_ver2_check_for_illegal_dt(v5, a1, v6);
                *(_QWORD *)(v5 + 16) = *(_QWORD *)(a2 + 24);
                *(_QWORD *)(v5 + 24) = *(_QWORD *)(a2 + 32);
                v37 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v6 + 31152);
                v38 = *(_QWORD *)(v6 + 31144);
                if ( *((_DWORD *)v37 - 1) != 414296116 )
                  __break(0x8228u);
                v37(v38, 3, &v53);
              }
              if ( *(_BYTE *)(a2 + 48) == 1 )
              {
                v23 = 0;
                *(_BYTE *)(a2 + 48) = 0;
                goto LABEL_21;
              }
              if ( (v12 & 0x10000000) == 0 )
              {
                v39 = 0;
LABEL_55:
                raw_spin_lock(v6 + 30968);
                if ( *(_DWORD *)(*(_QWORD *)(v6 + 31128) + 92LL) == 1 )
                {
                  v40 = cam_ife_csid_ver2_parse_path_irq_status(
                          v6,
                          a1,
                          *(unsigned int *)(v5 + 220),
                          *(unsigned int *)(*(_QWORD *)(v5 + 264) + 500LL),
                          *(unsigned int *)(*(_QWORD *)(v5 + 264) + 504LL),
                          v12,
                          a2);
                  if ( (*(_DWORD *)(*(_QWORD *)(v5 + 264) + 516LL) & v12) != 0 )
                    cam_ife_csid_ver2_rup_miss_handler(v6, v12);
                  if ( ((v40 == 0) & ~v39) == 0 )
                  {
                    if ( v39 )
                      v41 = 4096;
                    else
                      v41 = v40;
                    cam_ife_csid_ver2_handle_event_err(v6, v12, v41, 0, a1);
                  }
                }
                else
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_ife_csid_ver2_ipp_bottom_half",
                    3484,
                    "CSID[%u] powered down state",
                    *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL));
                }
                raw_spin_unlock(v6 + 30968);
                goto LABEL_65;
              }
            }
            _X8 = (unsigned int *)(v5 + 236);
            __asm { PRFM            #0x11, [X8] }
            do
              v49 = __ldxr(_X8);
            while ( __stxr(v49 + 1, _X8) );
            v39 = *(_DWORD *)(v5 + 236) > 5;
            goto LABEL_55;
          }
        }
        else if ( (*(_BYTE *)(v6 + 2148) & 1) != 0 )
        {
          goto LABEL_8;
        }
        v23 = 0;
        if ( (debug_mdl & 8) == 0 || debug_priority )
          goto LABEL_21;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver2_ipp_bottom_half",
          3402,
          "CSID[%u] bottom-half after stop [0x%x]",
          *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
          v12);
        goto LABEL_65;
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
      "cam_ife_csid_ver2_ipp_bottom_half",
      3386,
      "CSID[%u] Invalid params: path_cfg: %pK, irq_reg_idx: %d",
      *(_DWORD *)(*(_QWORD *)(v6 + 31120) + 4LL),
      (const void *)v5,
      v9);
    v23 = -22;
LABEL_21:
    cam_ife_csid_ver2_put_evt_payload(v6, v58, v6 + 30952, v6 + 30972);
    goto LABEL_22;
  }
  if ( a2 )
    v21 = "Non-NULL";
  else
    v21 = "NULL";
  if ( a1 )
    v22 = "Non-NULL";
  else
    v22 = "NULL";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_ipp_bottom_half",
    3371,
    "Invalid params. evt_payload_priv: %s, handler_priv: %s",
    v21,
    v22);
  v23 = -22;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v23;
}
