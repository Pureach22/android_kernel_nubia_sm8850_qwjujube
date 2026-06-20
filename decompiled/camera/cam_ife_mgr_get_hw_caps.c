__int64 __fastcall cam_ife_mgr_get_hw_caps(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x23
  __int64 v4; // x9
  __int64 v5; // x10
  unsigned __int64 v6; // x2
  int v7; // w8
  __int64 v8; // x1
  _QWORD *v9; // x5
  unsigned __int64 v10; // x4
  __int64 v11; // x3
  _QWORD *v12; // x6
  __int64 *v13; // x14
  __int64 v14; // x9
  int v15; // w7
  _QWORD *v16; // x21
  __int64 v17; // x1
  __int64 v18; // x2
  unsigned int v19; // w5
  __int64 v20; // x1
  __int64 v21; // x3
  int v22; // w6
  int v23; // w22
  __int64 v24; // x3
  int v25; // w4
  __int64 result; // x0
  __int64 v27; // x10
  unsigned __int64 v28; // x17
  __int64 v29; // x15
  _QWORD *v30; // x1
  unsigned __int64 v31; // x0
  __int64 v32; // x16
  _QWORD *v33; // x2
  __int64 *v34; // x12
  int v35; // w3
  _QWORD *v36; // x4
  __int64 v37; // x15
  __int64 v38; // x17
  unsigned int v39; // w1
  __int64 v40; // x15
  __int64 v41; // x16
  __int64 v42; // x0
  unsigned int v43; // w2
  __int64 v44; // x16
  unsigned __int64 StatusReg; // x10
  __int64 v46; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x9
  unsigned __int64 v54; // x10
  __int64 v55; // x0
  unsigned __int64 v56; // x8
  unsigned __int64 v58; // x9
  char v59; // w8
  __int64 v60; // x21
  __int64 v61; // x22
  unsigned int v62; // [xsp+4h] [xbp-FCh]
  __int128 v63; // [xsp+8h] [xbp-F8h] BYREF
  __int64 v64; // [xsp+18h] [xbp-E8h]
  _QWORD v65[28]; // [xsp+20h] [xbp-E0h] BYREF

  v65[27] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  memset(v65, 0, 216);
  v63 = 0u;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v60 = a2;
    v61 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_get_hw_caps",
      1247,
      "enter");
    a1 = v61;
    a2 = v60;
  }
  if ( *(_DWORD *)a2 != 240 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_get_hw_caps",
      1252,
      "Input query cap size:%u does not match expected query cap size: %u",
      *(_DWORD *)a2,
      240);
    goto LABEL_39;
  }
  v2 = a2;
  v3 = a1;
  if ( inline_copy_from_user_4((int)&v63, *(_QWORD *)(a2 + 8), 0xF0u) )
  {
LABEL_39:
    result = 4294967282LL;
    goto LABEL_40;
  }
  v4 = *(_QWORD *)(v3 + 68);
  v5 = 0;
  v6 = 0;
  LODWORD(v63) = *(_DWORD *)(v3 + 64);
  v7 = *(_DWORD *)(v3 + 76);
  v8 = 0;
  v9 = nullptr;
  v10 = 0;
  v11 = 0;
  v12 = nullptr;
  *(_QWORD *)((char *)&v63 + 4) = v4;
  HIDWORD(v63) = v7;
  LODWORD(v64) = 0;
  v13 = (__int64 *)(v3 + 80752);
  v14 = v2;
  while ( 1 )
  {
    if ( !*(_QWORD *)(v3 + 160 + v5) )
      goto LABEL_8;
    if ( *((_BYTE *)v13 + 12) == 1 )
    {
      if ( v9 )
      {
        if ( v8 + 4 < 0 || v6 < v8 + 4 || v6 - (v8 + 4) < 4 )
          break;
        v15 = *((_DWORD *)v9 + 1);
        v16 = v9;
      }
      else
      {
        v17 = (unsigned int)v64;
        if ( (unsigned int)v64 > 9 )
          goto LABEL_82;
        LODWORD(v64) = v64 + 1;
        if ( (_DWORD)v17 == 9 )
          break;
        v18 = *v13;
        v19 = *((_DWORD *)v13 + 2);
        v15 = 0;
        v20 = 3 * v17;
        v16 = &v65[v20];
        v8 = v20 * 8 + 24;
        *v16 = 5;
        v16[1] = v18;
        v6 = 240;
        v16[2] = v19;
      }
      if ( v8 + 4 < 0 )
        break;
      if ( v6 < v8 + 4 )
        break;
      v9 = v16;
      if ( v6 - (v8 + 4) < 4 )
        break;
      goto LABEL_7;
    }
    if ( v12 )
    {
      if ( v11 + 4 < 0 || v10 < v11 + 4 || v10 - (v11 + 4) < 4 )
        break;
      v15 = *((_DWORD *)v12 + 1);
      v16 = v12;
      goto LABEL_34;
    }
    v21 = (unsigned int)v64;
    if ( (unsigned int)v64 > 9 )
LABEL_82:
      __break(0x5512u);
    LODWORD(v64) = v64 + 1;
    if ( (_DWORD)v21 == 9 )
      break;
    v22 = *(_DWORD *)(v3 + 81308);
    v23 = *((_DWORD *)v13 + 2);
    v15 = 0;
    v24 = 3 * v21;
    v16 = &v65[v24];
    v11 = v24 * 8 + 24;
    v16[1] = *v13;
    if ( v22 == 65555 )
      v25 = 8;
    else
      v25 = 3;
    *(_DWORD *)v16 = v25;
    *((_DWORD *)v16 + 1) = 0;
    v10 = 240;
    *((_DWORD *)v16 + 4) = v23;
    *((_DWORD *)v16 + 5) = 0;
LABEL_34:
    if ( v11 + 4 < 0 )
      break;
    if ( v10 < v11 + 4 )
      break;
    v12 = v16;
    if ( v10 - (v11 + 4) < 4 )
      break;
LABEL_7:
    *((_DWORD *)v16 + 1) = v15 + 1;
LABEL_8:
    v5 += 8;
    v13 += 2;
    if ( v5 == 64 )
    {
      v27 = 0;
      v28 = 0;
      v29 = 0;
      v30 = nullptr;
      v31 = 0;
      v32 = 0;
      v33 = nullptr;
      v34 = (__int64 *)(v3 + 80476);
      while ( 1 )
      {
        if ( *(_QWORD *)(v3 + 96 + v27) )
        {
          if ( *((_BYTE *)v34 + 16) == 1 )
          {
            if ( v30 )
            {
              if ( v29 + 4 < 0 || v28 < v29 + 4 || v28 - (v29 + 4) < 4 )
                goto LABEL_69;
              v35 = *((_DWORD *)v30 + 1);
              v36 = v30;
            }
            else
            {
              v37 = (unsigned int)v64;
              if ( (unsigned int)v64 > 9 )
                goto LABEL_82;
              LODWORD(v64) = v64 + 1;
              if ( (_DWORD)v37 == 9 )
                goto LABEL_69;
              v38 = *v34;
              v39 = *((_DWORD *)v34 + 2);
              v35 = 0;
              v40 = 3 * v37;
              v36 = &v65[v40];
              v29 = v40 * 8 + 24;
              *v36 = 6;
              v36[1] = v38;
              v28 = 240;
              v36[2] = v39;
            }
            if ( v29 + 4 < 0 )
              goto LABEL_69;
            if ( v28 < v29 + 4 )
              goto LABEL_69;
            v30 = v36;
            if ( v28 - (v29 + 4) < 4 )
              goto LABEL_69;
          }
          else
          {
            if ( v33 )
            {
              if ( v32 + 4 < 0 || v31 < v32 + 4 || v31 - (v32 + 4) < 4 )
                goto LABEL_69;
              v35 = *((_DWORD *)v33 + 1);
              v36 = v33;
            }
            else
            {
              v41 = (unsigned int)v64;
              if ( (unsigned int)v64 > 9 )
                goto LABEL_82;
              LODWORD(v64) = v64 + 1;
              if ( (_DWORD)v41 == 9 )
                goto LABEL_69;
              v42 = *v34;
              v43 = *((_DWORD *)v34 + 2);
              v35 = 0;
              v44 = 3 * v41;
              v36 = &v65[v44];
              v32 = v44 * 8 + 24;
              *v36 = 1;
              v36[1] = v42;
              v31 = 240;
              v36[2] = v43;
            }
            if ( v32 + 4 < 0 )
              goto LABEL_69;
            if ( v31 < v32 + 4 )
              goto LABEL_69;
            v33 = v36;
            if ( v31 - (v32 + 4) < 4 )
              goto LABEL_69;
          }
          *((_DWORD *)v36 + 1) = v35 + 1;
        }
        v27 += 8;
        v34 = (__int64 *)((char *)v34 + 36);
        if ( v27 == 64 )
          goto LABEL_70;
      }
    }
  }
LABEL_69:
  __break(1u);
LABEL_70:
  StatusReg = _ReadStatusReg(SP_EL0);
  v46 = *(_QWORD *)(v14 + 8);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v47 = *(_QWORD *)(v14 + 8), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v47 = v46 & (v46 << 8 >> 8);
  if ( v47 > 0x7FFFFFFF10LL )
  {
    result = 4294967282LL;
    v59 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_40;
    goto LABEL_80;
  }
  v48 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v54 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v54 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v54);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v48);
  v55 = _arch_copy_to_user(v46 & 0xFF7FFFFFFFFFFFFFLL);
  v56 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v58 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v58 - 4096);
  _WriteStatusReg(TTBR1_EL1, v58);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v56);
  if ( v55 )
    result = 4294967282LL;
  else
    result = 0;
  v59 = debug_mdl;
  if ( (debug_mdl & 8) != 0 )
  {
LABEL_80:
    if ( !debug_priority )
    {
      v62 = result;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v59 & 8,
        4,
        "cam_ife_mgr_get_hw_caps",
        1367,
        "exit rc :%d",
        result);
      result = v62;
    }
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
