__int64 __fastcall cam_ife_csid_ver2_reserve(__int64 a1, __int64 a2)
{
  __int64 v2; // x7
  __int64 v3; // x19
  __int64 v5; // x25
  unsigned int v6; // w8
  unsigned int v7; // w21
  const char *v8; // x5
  __int64 v9; // x1
  __int64 v10; // x6
  __int64 v11; // x2
  __int64 v12; // x4
  __int64 v13; // x7
  __int64 v14; // x24
  int v15; // w8
  int v16; // w8
  __int64 v17; // x7
  const char *v18; // x5
  __int64 v19; // x6
  __int64 v20; // x4
  const char *v21; // x5
  __int64 v22; // x1
  __int64 v23; // x6
  __int64 v24; // x2
  __int64 v25; // x4
  _DWORD *v26; // x13
  int v27; // w12
  __int64 v28; // x22
  unsigned int v29; // w0
  unsigned int v30; // w0
  __int64 v32; // x9
  __int64 v33; // x9
  char v34; // w8
  int v35; // [xsp+0h] [xbp-40h]
  unsigned int v36; // [xsp+8h] [xbp-38h]
  int v37; // [xsp+10h] [xbp-30h]
  int v38; // [xsp+18h] [xbp-28h]
  int v39; // [xsp+20h] [xbp-20h]
  unsigned int v40; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a2 + 4);
  v40 = 0;
  if ( (unsigned int)v2 >= 0xD )
    goto LABEL_38;
  v3 = *(_QWORD *)(a1 + 3680);
  v5 = **(_QWORD **)(v3 + 31136);
  if ( *(_BYTE *)(a2 + 124) != 1 || (v6 = *(_DWORD *)(v3 + 2128)) == 0 )
  {
    v14 = v3 + 152LL * (unsigned int)v2;
    v15 = *(_DWORD *)(v14 + 8);
    if ( v15 != 1 )
    {
      v7 = -16;
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_34;
      v21 = "CSID %d Res_id %d state %d";
      v22 = debug_mdl & 8;
      v23 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
      v24 = 4;
      v25 = 4672;
LABEL_23:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int))cam_print_log)(
        3,
        v22,
        v24,
        "cam_ife_csid_ver2_reserve",
        v25,
        v21,
        v23,
        v2,
        v15,
        v36);
      goto LABEL_34;
    }
    if ( (*(_BYTE *)(a2 + 59) & 1) == 0 )
    {
      v7 = cam_ife_csid_check_in_port_args(a2, *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
      if ( v7 )
        goto LABEL_32;
    }
    v16 = *(_DWORD *)(v3 + 2128);
    if ( v16 )
    {
      if ( *(_QWORD *)(v3 + 31144) != *(_QWORD *)(a2 + 112) )
      {
        v17 = *(unsigned int *)(a2 + 4);
        v18 = "CSID[%u] different Context for res %d rx reserve count: %u";
        v19 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
        v20 = 4596;
LABEL_31:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int, int, int, int))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_in_port_validate",
          v20,
          v18,
          v19,
          v17,
          v16,
          v36,
          v37,
          v38,
          v39);
        v7 = -22;
LABEL_32:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_in_port_validate",
          4634,
          "Invalid args CSID[%u] rc %d",
          *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
          v7);
        v13 = *(unsigned int *)(a2 + 4);
        v8 = "CSID %d Res_id %d port validation failed";
        v10 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
        v9 = 8;
        v11 = 1;
        v12 = 4679;
        goto LABEL_33;
      }
      v26 = *(_DWORD **)(a2 + 8);
      v17 = *(unsigned int *)(v3 + 32192);
      v16 = v26[2];
      if ( (_DWORD)v17 != v16 )
      {
        v18 = "CSID[%u] Invalid res[%d] in_res_type[%d]";
        v19 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
        v20 = 4606;
        goto LABEL_31;
      }
      v16 = v26[4];
      v17 = *(unsigned int *)(v3 + 2076);
      v27 = v26[3];
      if ( *(_DWORD *)(v3 + 2080) != v26[5]
        || *(_DWORD *)(v3 + 2072) != v27
        || (v27 = *(_DWORD *)(v3 + 2072), (_DWORD)v17 != v16) )
      {
        v18 = "CSID[%u] lane: num[%d %d] type[%d %d] cfg[%d %d]";
        v19 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
        v20 = 4625;
        v39 = v26[5];
        v38 = *(_DWORD *)(v3 + 2080);
        v37 = v27;
        v36 = *(_DWORD *)(v3 + 2072);
        goto LABEL_31;
      }
    }
    v28 = *(_QWORD *)(v14 + 24);
    if ( !v28 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_reserve",
        4688,
        "CSID %d Unallocated Res_id %d state %d",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(v14 + 8));
      v7 = -22;
      goto LABEL_34;
    }
    v29 = ((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, __int64))cam_ife_csid_cid_reserve)(
            v3 + 1824,
            &v40,
            *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL),
            a2);
    if ( v29 )
    {
      v7 = v29;
      v2 = *(unsigned int *)(a2 + 4);
      v23 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
      v15 = *(_DWORD *)(v14 + 8);
      v21 = "CSID %d Res_id %d state %d invalid cid %d";
      v36 = v40;
      v22 = 8;
      v24 = 1;
      v25 = 4698;
      goto LABEL_23;
    }
    if ( (*(_BYTE *)(a2 + 59) & 1) != 0 || (v30 = cam_ife_csid_hw_ver2_prepare_hw_cfg(v3, v28, a2, v40)) == 0 )
    {
      *(_QWORD *)(a2 + 40) = v14;
      v7 = 0;
      *(_DWORD *)(v14 + 8) = 2;
      v32 = *(_QWORD *)(v3 + 31112);
      *(_QWORD *)(v3 + 31152) = *(_QWORD *)(a2 + 96);
      *(_QWORD *)(v3 + 32200) = *(_QWORD *)(a2 + 64);
      *(_QWORD *)(v3 + 31144) = *(_QWORD *)(a2 + 112);
      *(_QWORD *)(a2 + 72) = v32;
      v33 = *(_QWORD *)(a2 + 88);
      *(_QWORD *)(a2 + 80) = *(_QWORD *)(v3 + 30984);
      *(_QWORD *)(v14 + 48) = v33;
      *(_BYTE *)(v3 + 2160) = *(_BYTE *)(a2 + 120);
      *(_BYTE *)(v28 + 250) = *(_BYTE *)(a2 + 58);
      *(_BYTE *)(v28 + 253) = *(_BYTE *)(a2 + 122);
      *(_BYTE *)(v28 + 255) = *(_BYTE *)(*(_QWORD *)(a2 + 8) + 221LL);
      *(_BYTE *)(v3 + 2158) = *(_BYTE *)(a2 + 59);
      *(_BYTE *)(a2 + 60) = *(_DWORD *)(v5 + 264) != 0;
      v34 = debug_mdl;
      *(_BYTE *)(a2 + 123) = *(_BYTE *)(v5 + 665);
      if ( (v34 & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v34 & 8,
          4,
          "cam_ife_csid_ver2_reserve",
          4740,
          "CSID[%u] Resource[id: %d name:%s] state %d cid %d",
          *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
          *(_DWORD *)(a2 + 4),
          (const char *)(v14 + 128),
          *(_DWORD *)(v14 + 8),
          v40);
        v7 = 0;
      }
      goto LABEL_34;
    }
    v7 = v30;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_reserve",
      4708,
      "CSID[%u] res %d hw_cfg fail",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      *(_DWORD *)(a2 + 4));
    if ( v40 < 5 )
    {
      cam_ife_csid_cid_release(
        v3 + 1824 + 56LL * v40,
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        *(_DWORD *)(v28 + 120));
      cam_ife_csid_ver2_reset_csid_params(v3);
      goto LABEL_34;
    }
LABEL_38:
    __break(0x5512u);
  }
  v7 = -16;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v8 = "CSID %d already acquired csi2_reserve_cnt: %d";
    v9 = debug_mdl & 8;
    v10 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
    v11 = 4;
    v12 = 4662;
    v13 = v6;
LABEL_33:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, unsigned int))cam_print_log)(
      3,
      v9,
      v11,
      "cam_ife_csid_ver2_reserve",
      v12,
      v8,
      v10,
      v13,
      v35,
      v36);
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v7;
}
