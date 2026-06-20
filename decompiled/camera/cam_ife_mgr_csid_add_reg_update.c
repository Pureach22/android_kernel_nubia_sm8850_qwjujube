__int64 __fastcall cam_ife_mgr_csid_add_reg_update(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v6; // x23
  __int64 v7; // x28
  __int64 v8; // x25
  __int64 v9; // x8
  unsigned int v10; // w7
  unsigned int *v11; // x9
  __int64 v12; // x10
  char v13; // w10
  __int64 v14; // x8
  unsigned int v15; // w7
  unsigned int *v16; // x9
  __int64 v17; // x10
  char v18; // w10
  __int64 v19; // x23
  _QWORD *v20; // x25
  unsigned int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x6
  unsigned int v24; // w19
  const char *v25; // x5
  __int64 v26; // x4
  __int64 v27; // x7
  __int64 result; // x0
  unsigned int v29; // [xsp+14h] [xbp-45Ch]
  int v30[2]; // [xsp+18h] [xbp-458h] BYREF
  _QWORD s[138]; // [xsp+20h] [xbp-450h] BYREF

  s[136] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x440u);
  v6 = *(__int64 **)(a1 + 208);
  v7 = *(_QWORD *)(a1 + 72);
  if ( v6 != (__int64 *)(a1 + 208) )
  {
    v8 = *(_QWORD *)(a2 + 320);
    do
    {
      if ( *((_DWORD *)v6 + 4) )
      {
        v9 = v6[4];
        if ( !v9 )
          goto LABEL_11;
        v10 = *(_DWORD *)(*(_QWORD *)(v9 + 16) + 4LL);
        if ( v10 > 7 || (v11 = (unsigned int *)&s[17 * v10], v12 = v11[28], (unsigned int)v12 > 0xB) )
        {
LABEL_40:
          __break(0x5512u);
LABEL_41:
          __break(1u);
        }
        if ( 8 * v12 + 136 * (unsigned __int64)v10 + 16 > 0x43F )
          goto LABEL_41;
        *(_QWORD *)&v11[2 * v12 + 4] = v9;
        ++v11[28];
        v11[31] = *(unsigned __int8 *)(v8 + 4288);
        v13 = debug_mdl;
        v11[30] = *(_DWORD *)(v8 + 4280);
        if ( (v13 & 8) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v13 & 8,
            4,
            "cam_ife_mgr_csid_add_reg_update",
            14883,
            "Reg update queued for res %d hw_id %d, ctx_idx: %u",
            *(unsigned int *)(v9 + 4));
          v14 = v6[5];
          if ( !v14 )
            goto LABEL_3;
        }
        else
        {
LABEL_11:
          v14 = v6[5];
          if ( !v14 )
            goto LABEL_3;
        }
        v15 = *(_DWORD *)(*(_QWORD *)(v14 + 16) + 4LL);
        if ( v15 > 8 )
          goto LABEL_40;
        if ( (*(_BYTE *)(v7 + 80464 + 36LL * v15 + 31) & 1) == 0 )
        {
          if ( v15 == 8 )
            goto LABEL_40;
          v16 = (unsigned int *)&s[17 * v15];
          v17 = v16[28];
          if ( (unsigned int)v17 > 0xB )
            goto LABEL_40;
          if ( 8 * v17 + 136 * (unsigned __int64)v15 + 16 > 0x43F )
            goto LABEL_41;
          *(_QWORD *)&v16[2 * v17 + 4] = v14;
          ++v16[28];
          v16[31] = *(unsigned __int8 *)(v8 + 4288);
          v18 = debug_mdl;
          v16[30] = *(_DWORD *)(v8 + 4280);
          if ( (v18 & 8) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v18 & 8,
              4,
              "cam_ife_mgr_csid_add_reg_update",
              14883,
              "Reg update queued for res %d hw_id %d, ctx_idx: %u",
              *(unsigned int *)(v14 + 4));
        }
      }
LABEL_3:
      v6 = (__int64 *)*v6;
    }
    while ( v6 != (__int64 *)(a1 + 208) );
  }
  v19 = 0;
  v20 = s;
  while ( !*((_DWORD *)v20 + 28) )
  {
LABEL_23:
    ++v19;
    v20 += 17;
    if ( v19 == 8 )
    {
      result = 0;
      goto LABEL_39;
    }
  }
  v30[0] = *(_DWORD *)(a1 + 8744);
  v30[1] = v19;
  v21 = cam_isp_add_change_base(a2, (__int64 **)(a1 + 208), v30, a3);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v29 = v21;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_csid_add_reg_update",
      14898,
      "Ctx:%u Change base added for num_res %d",
      *(_DWORD *)(a1 + 56),
      *((_DWORD *)v20 + 28));
    v21 = v29;
    if ( v29 )
    {
LABEL_35:
      v23 = *(unsigned int *)(a1 + 56);
      v24 = v21;
      v25 = "Change base Failed Ctx:%u hw_idx=%d, rc=%d";
      v26 = 14903;
      v27 = (unsigned int)v19;
      goto LABEL_38;
    }
  }
  else if ( v21 )
  {
    goto LABEL_35;
  }
  if ( *(_DWORD *)(v7 + 80972) == 1 )
    *((_BYTE *)v20 + 129) = 1;
  v22 = cam_isp_add_csid_reg_update(a2, a3, (__int64)v20, 1);
  if ( !v22 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_csid_add_reg_update",
        14921,
        "Ctx:%u Reg update added id:%d num_res %d",
        *(_DWORD *)(a1 + 56),
        v19,
        *((_DWORD *)v20 + 28));
    goto LABEL_23;
  }
  v23 = *(unsigned int *)(a1 + 56);
  v25 = "Ctx:%u Reg Update failed idx:%u";
  v24 = v22;
  v26 = 14916;
  v27 = (unsigned int)v19;
LABEL_38:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_csid_add_reg_update",
    v26,
    v25,
    v23,
    v27);
  result = v24;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
