__int64 __fastcall cam_ife_hw_mgr_acquire_res_sfe_out_pix(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x8
  __int64 v7; // x26
  unsigned __int64 v8; // x27
  __int64 v9; // x22
  unsigned int v10; // w25
  unsigned __int64 v12; // x25
  __int64 v13; // x9
  unsigned int v14; // w8
  unsigned int v15; // w10
  __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x9
  bool v19; // zf
  __int64 v20; // x8
  int v21; // w9
  __int64 v22; // x0
  __int64 (__fastcall *v23)(__int64, __int64 *, __int64); // x9
  unsigned int v24; // w0
  __int64 v25; // x8
  _DWORD *v26; // x9
  __int64 v27; // x10
  int v28; // w8
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 (__fastcall *v31)(__int64, __int64 *, __int64); // x9
  __int64 v32; // x0
  __int64 v33; // x9
  __int64 result; // x0
  unsigned int v35; // w20
  __int64 v36; // [xsp+20h] [xbp-60h] BYREF
  __int64 v37; // [xsp+28h] [xbp-58h]
  __int64 v38; // [xsp+30h] [xbp-50h]
  __int64 (__fastcall *v39)(__int64, unsigned int, _DWORD *); // [xsp+38h] [xbp-48h]
  __int64 v40; // [xsp+40h] [xbp-40h]
  __int64 v41; // [xsp+48h] [xbp-38h]
  __int64 v42; // [xsp+50h] [xbp-30h]
  unsigned __int64 v43; // [xsp+58h] [xbp-28h]
  __int64 v44; // [xsp+60h] [xbp-20h]
  __int64 v45; // [xsp+68h] [xbp-18h]
  __int64 v46; // [xsp+70h] [xbp-10h]
  __int64 v47; // [xsp+78h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a3 + 144);
  if ( (_DWORD)v3 )
  {
    v7 = 0;
    v8 = 0;
    v45 = 0;
    v46 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = nullptr;
    v40 = 0;
    v37 = 0;
    v38 = 0;
    v36 = 0;
    do
    {
      v9 = *(_QWORD *)(a3 + 224);
      v10 = *(_DWORD *)(v9 + v7);
      if ( v10 < 0x6005 || max_sfe_out_res + 24576 <= v10 )
        goto LABEL_4;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_acquire_res_sfe_out_pix",
          3209,
          "ctx_idx: %u res_type: 0x%x",
          *(_DWORD *)(a1 + 56),
          v10);
      *(_BYTE *)(*(_QWORD *)(a1 + 8504) + (unsigned __int8)v10) = *(_DWORD *)(a1 + 8516);
      v12 = *(_QWORD *)(a1 + 280) + ((unsigned __int64)*(unsigned int *)(a1 + 8516) << 7);
      *(_DWORD *)(v12 + 24) = *(_DWORD *)(a3 + 80);
      v13 = *(_QWORD *)(a1 + 8728);
      LODWORD(v36) = 12;
      v14 = *(_DWORD *)(a2 + 24);
      v15 = *(_DWORD *)(a1 + 56);
      v16 = *(_QWORD *)(a1 + 9336);
      v42 = v9 + v7;
      v45 = v13;
      v17 = *(_QWORD *)(a1 + 16);
      v43 = __PAIR64__(v14, v15);
      v37 = v17;
      v38 = a1;
      v18 = *(_QWORD *)(a2 + 32);
      v39 = cam_ife_hw_mgr_event_handler;
      v40 = v16;
      if ( !v18 )
        goto LABEL_23;
      v19 = v14 == 0;
      v20 = *(_QWORD *)(v18 + 16);
      v21 = !v19;
      LODWORD(v44) = 0;
      HIDWORD(v44) = v21;
      v22 = *(_QWORD *)(v20 + 112);
      v23 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v20 + 40);
      if ( *((_DWORD *)v23 - 1) != 1989616049 )
        __break(0x8229u);
      v24 = v23(v22, &v36, 88);
      if ( v24 )
      {
LABEL_33:
        v35 = v24;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_acquire_res_sfe_out_pix",
          3248,
          "Can not acquire out resource 0x%x ctx_idx: %u",
          *(_DWORD *)(v9 + v7),
          *(_DWORD *)(a1 + 56));
        result = v35;
        goto LABEL_34;
      }
      v25 = v41;
      *(_QWORD *)(v12 + 32) = v41;
      v26 = (_DWORD *)(*(_QWORD *)(a1 + 9480) + 292LL * HIDWORD(v46));
      v27 = (unsigned int)*v26;
      if ( (unsigned int)v27 > 0x23 )
        __break(0x5512u);
      v28 = *(_DWORD *)(v25 + 4);
      *v26 = v27 + 1;
      v26[v27 + 1] = v28;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_acquire_res_sfe_out_pix",
          3267,
          "ctx:%u res_type:0x%x res: %s res id:0x%x comp grp id:%d",
          *(_DWORD *)(a1 + 56),
          **(_DWORD **)(v12 + 32),
          (const char *)(*(_QWORD *)(v12 + 32) + 128LL),
          *(_DWORD *)(*(_QWORD *)(v12 + 32) + 4LL),
          HIDWORD(v46));
        v29 = *(_QWORD *)(a2 + 40);
        if ( v29 )
        {
LABEL_24:
          v30 = *(_QWORD *)(v29 + 16);
          v44 = 1;
          v31 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(v30 + 40);
          v32 = *(_QWORD *)(v30 + 112);
          if ( *((_DWORD *)v31 - 1) != 1989616049 )
            __break(0x8229u);
          v24 = v31(v32, &v36, 88);
          if ( v24 )
            goto LABEL_33;
          v33 = v41;
          *(_QWORD *)(v12 + 40) = v41;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_hw_mgr_acquire_res_sfe_out_pix",
              3267,
              "ctx:%u res_type:0x%x res: %s res id:0x%x comp grp id:%d",
              *(_DWORD *)(a1 + 56),
              *(_DWORD *)v33,
              (const char *)(v33 + 128),
              *(_DWORD *)(v33 + 4),
              HIDWORD(v46));
        }
      }
      else
      {
LABEL_23:
        v29 = *(_QWORD *)(a2 + 40);
        if ( v29 )
          goto LABEL_24;
      }
      *(_DWORD *)(v12 + 16) = 12;
      *(_DWORD *)(v12 + 20) = *(_DWORD *)(v9 + v7);
      ++*(_DWORD *)(a2 + 108);
      ++*(_DWORD *)(a1 + 8516);
      v3 = *(unsigned int *)(a3 + 144);
LABEL_4:
      ++v8;
      v7 += 44;
    }
    while ( v8 < v3 );
  }
  result = 0;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
