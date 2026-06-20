__int64 __fastcall cam_isp_add_reg_update(__int64 a1, _QWORD *a2, int a3, __int64 a4, char a5)
{
  int v5; // w6
  unsigned int v6; // w7
  _QWORD *v7; // x27
  int v13; // w24
  __int64 result; // x0
  __int64 v15; // x26
  unsigned int v16; // w7
  int v17; // w9
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 (__fastcall *v20)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v21; // x0
  __int64 v22; // x26
  unsigned int v23; // w7
  int v24; // w9
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 (__fastcall *v27)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v28; // x0
  const char *v29; // x5
  __int64 v30; // x4
  __int64 v31; // [xsp+10h] [xbp-40h] BYREF
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 40);
  v6 = *(_DWORD *)(a1 + 24);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 0;
  if ( v5 + 1 >= v6 )
  {
    v29 = "Insufficient  HW entries :%d %d";
    v30 = 1357;
LABEL_27:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_reg_update",
      v30,
      v29);
    goto LABEL_28;
  }
  v7 = (_QWORD *)*a2;
  if ( (_QWORD *)*a2 == a2 )
  {
LABEL_28:
    result = 4294967274LL;
    goto LABEL_29;
  }
  v13 = 0;
  result = 4294967274LL;
  do
  {
    if ( *((_DWORD *)v7 + 4) )
    {
      v15 = v7[4];
      if ( v15 && *(_DWORD *)(*(_QWORD *)(v15 + 16) + 4LL) == a3 )
      {
        v16 = *(_DWORD *)(a4 + 20);
        v17 = *(_DWORD *)(a4 + 24);
        if ( v16 <= v17 + v13 )
          goto LABEL_32;
        v18 = *(_QWORD *)(a4 + 8);
        LODWORD(v34) = v16 - (v17 + v13);
        LODWORD(v32) = 3;
        v31 = v15;
        v33 = v18 + (v13 & 0xFFFFFFFC) + (v17 & 0xFFFFFFFC);
        v19 = *(_QWORD *)(v15 + 16);
        v20 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v19 + 88);
        v21 = *(_QWORD *)(v19 + 112);
        if ( *((_DWORD *)v20 - 1) != -1055839300 )
          __break(0x8229u);
        result = v20(v21, 3, &v31, 56);
        if ( (_DWORD)result )
          goto LABEL_29;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_add_reg_update",
            1404,
            "Reg update added for res %d hw_id %d cdm_idx %d",
            *(_DWORD *)(v15 + 4),
            *(_DWORD *)(*(_QWORD *)(v15 + 16) + 4LL),
            a3);
        result = 0;
        v13 += HIDWORD(v34);
      }
      v22 = v7[5];
      if ( v22 && *(_DWORD *)(*(_QWORD *)(v22 + 16) + 4LL) == a3 )
      {
        v23 = *(_DWORD *)(a4 + 20);
        v24 = *(_DWORD *)(a4 + 24);
        if ( v23 <= v24 + v13 )
        {
LABEL_32:
          v29 = "no free mem %d %d %d";
          v30 = 1383;
          goto LABEL_27;
        }
        v25 = *(_QWORD *)(a4 + 8);
        LODWORD(v34) = v23 - (v24 + v13);
        LODWORD(v32) = 3;
        v31 = v22;
        v33 = v25 + (v13 & 0xFFFFFFFC) + (v24 & 0xFFFFFFFC);
        v26 = *(_QWORD *)(v22 + 16);
        v27 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v26 + 88);
        v28 = *(_QWORD *)(v26 + 112);
        if ( *((_DWORD *)v27 - 1) != -1055839300 )
          __break(0x8229u);
        result = v27(v28, 3, &v31, 56);
        if ( (_DWORD)result )
          goto LABEL_29;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_add_reg_update",
            1404,
            "Reg update added for res %d hw_id %d cdm_idx %d",
            *(_DWORD *)(v22 + 4),
            *(_DWORD *)(*(_QWORD *)(v22 + 16) + 4LL),
            a3);
        result = 0;
        v13 += HIDWORD(v34);
      }
    }
    v7 = (_QWORD *)*v7;
  }
  while ( v7 != a2 );
  if ( v13 )
  {
    cam_isp_update_hw_entry(1, a1, a4, v13, a5 & 1);
    result = 0;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
