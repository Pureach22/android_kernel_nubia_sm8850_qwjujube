__int64 __fastcall cam_ife_hw_mgr_acquire_res_sfe_out_rdi(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v4; // w6
  int v5; // w19
  __int64 v6; // x9
  __int64 v7; // x10
  char v8; // w8
  __int64 v9; // x26
  char v10; // w8
  unsigned __int64 v11; // x20
  unsigned __int64 v12; // x23
  int v13; // w9
  __int64 v14; // x27
  unsigned __int64 v15; // x6
  __int64 v16; // x28
  unsigned int v17; // w21
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x25
  __int64 v21; // x10
  __int64 v22; // x22
  __int64 v23; // x24
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 (__fastcall *v26)(__int64, __int64 *, __int64); // x9
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x1
  _DWORD *v30; // x8
  __int64 v31; // x9
  __int64 v32; // x8
  __int64 v34; // x20
  __int64 v35; // x21
  __int64 v36; // x22
  __int64 v37; // [xsp+10h] [xbp-70h]
  __int64 v38; // [xsp+18h] [xbp-68h]
  __int64 v39; // [xsp+20h] [xbp-60h] BYREF
  __int64 v40; // [xsp+28h] [xbp-58h]
  __int64 v41; // [xsp+30h] [xbp-50h]
  __int64 (__fastcall *v42)(__int64, unsigned int, _DWORD *); // [xsp+38h] [xbp-48h]
  __int64 v43; // [xsp+40h] [xbp-40h]
  __int64 v44; // [xsp+48h] [xbp-38h]
  __int64 v45; // [xsp+50h] [xbp-30h]
  __int128 v46; // [xsp+58h] [xbp-28h]
  __int64 v47; // [xsp+68h] [xbp-18h]
  __int64 v48; // [xsp+70h] [xbp-10h]
  __int64 v49; // [xsp+78h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 32);
  v47 = 0;
  v48 = 0;
  v46 = 0u;
  v44 = 0;
  v45 = 0;
  v42 = nullptr;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0;
  v4 = *(_DWORD *)(v3 + 4);
  if ( (unsigned int)(v4 - 1) >= 5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_sfe_out_rdi",
      3115,
      "invalid SFE RDI resource type 0x%x, ctx_idx: %u",
      v4,
      *(_DWORD *)(a1 + 56));
    v17 = -22;
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return v17;
  }
  v5 = v4 + 24575;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v34 = a2;
    v35 = a1;
    v36 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_acquire_res_sfe_out_rdi",
      3121,
      "sfe_in_res_id: 0x%x sfe_out_res_id: 0x%x ctx_idx: %u",
      v4,
      v5,
      *(_DWORD *)(a1 + 56));
    a3 = v36;
    a1 = v35;
    a2 = v34;
  }
  v6 = *(_QWORD *)(a1 + 16);
  v7 = *(_QWORD *)(a1 + 8504);
  LODWORD(v39) = 12;
  v8 = *(_DWORD *)(a1 + 8516);
  v40 = v6;
  *(_BYTE *)(v7 + (v5 & 7)) = v8;
  if ( !*(_DWORD *)(a3 + 144) )
  {
    LODWORD(v15) = 0;
    v17 = -22;
LABEL_20:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_sfe_out_rdi",
      3166,
      "Cannot acquire out resource i: %d, num_out_res: %u ctx_idx: %u",
      v15,
      v15,
      *(_DWORD *)(a1 + 56));
    goto LABEL_24;
  }
  v9 = 0;
  v10 = debug_mdl;
  v11 = 0;
  v12 = *(_QWORD *)(a1 + 280) + ((unsigned __int64)*(unsigned int *)(a1 + 8516) << 7);
  v13 = debug_priority;
  while ( 1 )
  {
    v14 = *(_QWORD *)(a3 + 224);
    if ( (v10 & 8) != 0 && !v13 )
    {
      v16 = a3;
      v37 = a1;
      v38 = a2;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v10 & 8,
        4,
        "cam_ife_hw_mgr_acquire_res_sfe_out_rdi",
        3131,
        "i: %d sfe_out_res_id: 0x%x out_port: 0x%x ctx_idx: %u",
        v11,
        v5,
        *(_DWORD *)(v14 + v9),
        *(_DWORD *)(a1 + 56));
      a1 = v37;
      a2 = v38;
      a3 = v16;
      v10 = debug_mdl;
      v13 = debug_priority;
    }
    if ( v5 == *(_DWORD *)(v14 + v9) )
      break;
    v15 = *(unsigned int *)(a3 + 144);
    ++v11;
    v9 += 44;
    if ( v11 >= v15 )
    {
      v17 = -22;
      if ( (_DWORD)v15 == (_DWORD)v11 )
        goto LABEL_20;
LABEL_23:
      v32 = v44;
      *(_DWORD *)(v12 + 24) = 0;
      v17 = 0;
      *(_QWORD *)(v12 + 32) = v32;
      *(_BYTE *)(v12 + 120) = *(_BYTE *)(a2 + 120);
      *(_DWORD *)(v12 + 16) = 12;
      *(_DWORD *)(v12 + 20) = v5;
      ++*(_DWORD *)(a2 + 108);
      ++*(_DWORD *)(a1 + 8516);
      goto LABEL_24;
    }
  }
  v18 = *(_QWORD *)(a1 + 8728);
  v19 = *(_DWORD *)(a1 + 56);
  v20 = a1;
  v21 = *(_QWORD *)(a1 + 9336);
  v41 = a1;
  v22 = a3;
  v47 = v18;
  v23 = a2;
  LODWORD(v46) = v19;
  LOBYTE(v19) = *(_BYTE *)(a2 + 120);
  v45 = v14 + v9;
  v42 = cam_ife_hw_mgr_event_handler;
  v43 = v21;
  v24 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)((char *)&v46 + 4) = 0;
  LOBYTE(v48) = v19;
  v25 = *(_QWORD *)(v24 + 16);
  v26 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v25 + 40);
  v27 = *(_QWORD *)(v25 + 112);
  if ( *((_DWORD *)v26 - 1) != 1989616049 )
    __break(0x8229u);
  v28 = v26(v27, &v39, 88);
  if ( (_DWORD)v28 )
  {
    v17 = v28;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_acquire_res_sfe_out_rdi",
      3152,
      "Can not acquire out resource: 0x%x ctx_idx: %u",
      *(_DWORD *)(v14 + v9),
      *(_DWORD *)(v20 + 56));
    goto LABEL_24;
  }
  v30 = (_DWORD *)(*(_QWORD *)(v20 + 9480) + 292LL * HIDWORD(v48));
  v31 = (unsigned int)*v30;
  if ( (unsigned int)v31 <= 0x23 )
  {
    a1 = v20;
    *v30 = v31 + 1;
    v17 = 0;
    a2 = v23;
    v30[v31 + 1] = v5;
    LODWORD(v15) = *(_DWORD *)(v22 + 144);
    if ( (_DWORD)v15 == (_DWORD)v11 )
      goto LABEL_20;
    goto LABEL_23;
  }
  __break(0x5512u);
  return cam_ife_hw_mgr_acquire_res_ife_bus_rd(v28, v29);
}
