__int64 __fastcall cam_ife_mgr_isp_add_reg_update(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  unsigned __int64 v7; // x19
  int *v8; // x27
  int v9; // w7
  char v10; // w9
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 result; // x0
  unsigned int v14; // w20
  int v15; // w8
  int v16; // [xsp+8h] [xbp-18h]
  __int64 v17; // [xsp+10h] [xbp-10h] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 8716);
  v17 = 0;
  if ( !v3 )
  {
LABEL_14:
    result = 0;
    goto LABEL_18;
  }
  v7 = 0;
  v8 = (int *)(a1 + 8584);
  while ( 1 )
  {
    if ( v7 == 11 )
      __break(0x5512u);
    v9 = *v8;
    v10 = *(_BYTE *)(a1 + 9382);
    LODWORD(v17) = *(_DWORD *)(a1 + 8744);
    HIDWORD(v17) = v9;
    if ( (v10 & 1) == 0 )
      break;
LABEL_10:
    v12 = cam_isp_add_reg_update(a2, (_QWORD *)(a1 + 224), v9, a3, (*(_BYTE *)(a1 + 9382) & 1) == 0);
    if ( v12 )
    {
      v16 = *(_DWORD *)(a1 + 56);
      v14 = v12;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, int, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_isp_add_reg_update",
        14966,
        "Add Reg Update cmd Failed i=%d, idx=%d, rc=%d ctx_idx: %u",
        (unsigned int)v7,
        (unsigned int)*v8,
        v12,
        v16,
        v17,
        v18);
      goto LABEL_17;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_isp_add_reg_update",
        14972,
        "Add Reg Update cmd i=%d, idx=%d, rc=%d ctx_idx: %u",
        v7,
        *v8,
        0,
        *(_DWORD *)(a1 + 56));
    ++v7;
    v8 += 3;
    if ( v7 >= *(unsigned int *)(a1 + 8716) )
      goto LABEL_14;
  }
  v11 = cam_isp_add_change_base(a2, (__int64 **)(a1 + 224), (int *)&v17, a3);
  if ( !v11 )
  {
    v9 = *v8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_isp_add_reg_update",
        14955,
        "Add Change base cmd i=%d, idx=%d, rc=%d ctx_idx: %u",
        v7,
        v9,
        0,
        *(_DWORD *)(a1 + 56));
      v9 = *v8;
    }
    goto LABEL_10;
  }
  v15 = *(_DWORD *)(a1 + 56);
  v14 = v11;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, int, __int64, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_isp_add_reg_update",
    14949,
    "Add Change base cmd Failed i=%d, idx=%d, rc=%d ctx_idx: %u",
    (unsigned int)v7,
    (unsigned int)*v8,
    v11,
    v15,
    v17,
    v18);
LABEL_17:
  result = v14;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
