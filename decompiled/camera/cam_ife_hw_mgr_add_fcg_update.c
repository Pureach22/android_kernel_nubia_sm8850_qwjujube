__int64 __fastcall cam_ife_hw_mgr_add_fcg_update(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        _BYTE *a4,
        int *a5,
        __int64 *a6)
{
  __int64 *v8; // x23
  __int64 v9; // x8
  _BYTE *v10; // x21
  unsigned int v12; // w9
  unsigned int v13; // w10
  unsigned int *v14; // x24
  __int64 v15; // x8
  __int64 (__fastcall *v16)(__int64, __int64, __int64 *, __int64); // x10
  __int64 v17; // x0
  int v18; // w0
  __int64 v19; // x9
  unsigned int v20; // w8
  unsigned int v21; // w10
  __int64 v22; // x9
  __int64 (__fastcall *v23)(__int64, __int64, __int64 *, __int64); // x10
  __int64 v24; // x0
  int v25; // w21
  int *v26; // x9
  int v27; // w6
  unsigned int v28; // w7
  unsigned int v29; // w7
  int v30; // w8
  __int64 result; // x0
  unsigned int v32; // w19
  int v33; // w22
  __int64 v34; // [xsp+0h] [xbp-30h] BYREF
  __int64 v35; // [xsp+8h] [xbp-28h]
  unsigned __int64 v36; // [xsp+10h] [xbp-20h]
  __int64 v37; // [xsp+18h] [xbp-18h]
  __int64 v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v8 = a6;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v34 = 0;
  do
  {
    v8 = (__int64 *)*v8;
    if ( v8 == a6 )
      goto LABEL_21;
  }
  while ( !*((_DWORD *)v8 + 4) );
  v9 = v8[4];
  v10 = a4;
  if ( v9 )
  {
    v12 = a3[2];
    v13 = *a3;
    v14 = a3;
    v34 = v8[4];
    v36 = __PAIR64__(v13, v12);
    v15 = *(_QWORD *)(v9 + 16);
    LODWORD(v35) = 13;
    BYTE4(v35) = 1;
    v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v15 + 88);
    v17 = *(_QWORD *)(v15 + 112);
    if ( *((_DWORD *)v16 - 1) != -1055839300 )
      __break(0x822Au);
    v18 = v16(v17, 13, &v34, 40);
    if ( v18 )
      goto LABEL_23;
    LODWORD(v9) = v37;
    a3 = v14;
    if ( !(_DWORD)v37 )
      goto LABEL_23;
  }
  v19 = v8[5];
  if ( !v19 )
    goto LABEL_14;
  v20 = a3[2];
  v21 = *a3;
  LODWORD(v37) = 0;
  v36 = __PAIR64__(v21, v20);
  v34 = v19;
  v22 = *(_QWORD *)(v19 + 16);
  LODWORD(v35) = 13;
  v23 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v22 + 88);
  v24 = *(_QWORD *)(v22 + 112);
  BYTE4(v35) = 1;
  if ( *((_DWORD *)v23 - 1) != -1055839300 )
    __break(0x822Au);
  v18 = v23(v24, 13, &v34, 40);
  if ( v18 || (LODWORD(v9) = v37) == 0 )
  {
LABEL_23:
    v32 = v18;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_add_fcg_update",
      15119,
      "Failed in retrieving KMD buf size requirement, rc: %d",
      v18);
    result = v32;
  }
  else
  {
LABEL_14:
    a4 = v10;
    if ( (v37 & 0x100000000LL) == 0 )
    {
LABEL_21:
      *a4 = 0;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_hw_mgr_add_fcg_update",
        15128,
        "FCG is sent from userspace but not supported by the hardware");
LABEL_22:
      result = 0;
      goto LABEL_24;
    }
    v25 = 4 * v9;
    v26 = a5;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_hw_mgr_add_fcg_update",
        15133,
        "KMD buf usage for FCG config is %u",
        v25);
      v26 = a5;
    }
    v27 = *(_DWORD *)(a1 + 40);
    v28 = *(_DWORD *)(a1 + 24);
    if ( v27 + 1 >= v28 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_add_fcg_update",
        15138,
        "Insufficient HW entries: %u, %u",
        v27,
        v28);
      result = 4294967274LL;
    }
    else
    {
      v29 = *(_DWORD *)(a2 + 20);
      v30 = *(_DWORD *)(a2 + 24);
      if ( v30 + v25 > v29 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_hw_mgr_add_fcg_update",
          15145,
          "Insufficient space in kmd buffer, used_bytes: %u, buf size: %u",
          v30,
          v29);
        result = 4294967284LL;
        goto LABEL_24;
      }
      v33 = *(_DWORD *)(a1 + 40);
      *v26 = v27;
      cam_isp_update_hw_entry(2, a1, a2, v25, 0);
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_add_fcg_update",
          15154,
          "FCG dummy entry, num_ent: %u, entry_size: %u",
          v33,
          v25);
        goto LABEL_22;
      }
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
