__int64 __fastcall cam_vfe_camif_ver3_process_cmd(_QWORD *a1, int a2, int *a3, int a4)
{
  _DWORD *v6; // x8
  __int64 result; // x0
  int v8; // w6
  __int64 v9; // x8
  int v10; // w7
  __int64 v11; // x22
  __int64 (__fastcall *v12)(_QWORD); // x8
  int v13; // w0
  unsigned int v14; // w6
  int v15; // w21
  _QWORD *v16; // x8
  __int64 v17; // x8
  int v18; // w7
  _DWORD *v19; // x8
  __int64 v20; // x0
  _DWORD v21[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_process_cmd",
      859,
      "Invalid input arguments rsesource node:%pK cmd_args:%pK",
      a1,
      a3);
    goto LABEL_9;
  }
  if ( a2 > 19 )
  {
    if ( a2 <= 29 )
    {
      if ( a2 == 20 )
      {
        v16 = (_QWORD *)a1[3];
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_ver3_dump_timestamps",
          827,
          "CAMIF ERROR timestamp:[%lld.%09lld] SOF timestamp:[%lld.%09lld] EPOCH timestamp:[%lld.%09lld] EOF timestamp:[%lld.%09lld]",
          v16[2850],
          v16[2851],
          v16[2844],
          v16[2845],
          v16[2846],
          v16[2847],
          v16[2848],
          v16[2849]);
        result = 0;
        goto LABEL_10;
      }
      if ( a2 == 25 )
      {
        v6 = (_DWORD *)a1[3];
        result = 0;
        v6[12] = a3[3];
        v6[13] = a3[4];
        v6[14] = a3[5];
        v6[15] = a3[6];
        v6[16] = a3[7];
        v6[17] = a3[8];
        v6[18] = a3[9];
        v6[19] = a3[10];
        v6[20] = a3[11];
        v6[21] = a3[12];
        goto LABEL_10;
      }
      goto LABEL_27;
    }
    if ( a2 == 30 )
    {
      result = 0;
      *(_QWORD *)a3 = *(_QWORD *)(a1[3] + 40LL);
      goto LABEL_10;
    }
    if ( a2 == 39 )
    {
      v8 = *a3;
      result = 0;
      v9 = a1[3] + 20480LL;
      *(_DWORD *)(v9 + 2232) = *a3;
      v10 = a3[1];
      *(_DWORD *)(v9 + 2236) = v10;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_camif_ver3_blanking_update",
          845,
          "hbi:%d vbi:%d",
          v8,
          v10);
        result = 0;
      }
      goto LABEL_10;
    }
LABEL_27:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_process_cmd",
      893,
      "unsupported process command:%d",
      a2);
    goto LABEL_9;
  }
  if ( a2 != 3 )
  {
    if ( a2 == 18 )
    {
      result = 0;
      *(_BYTE *)(a1[3] + 22720LL) = *a3 == 1;
      goto LABEL_10;
    }
    if ( a2 != 19 )
      goto LABEL_27;
    *(_DWORD *)(a1[3] + 22728LL) = *a3;
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( a4 != 56 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_get_reg_update",
      215,
      "Invalid arg size: %d expected:%ld",
      a4,
      56);
    goto LABEL_9;
  }
  if ( !*(_QWORD *)a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_get_reg_update",
      220,
      "Invalid args: %pK",
      a3);
    goto LABEL_9;
  }
  v11 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
  if ( !v11 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_get_reg_update",
      227,
      "Invalid CDM ops");
    goto LABEL_9;
  }
  v12 = *(__int64 (__fastcall **)(_QWORD))(v11 + 24);
  if ( *((_DWORD *)v12 - 1) != 2010610996 )
    __break(0x8228u);
  v13 = v12(1);
  v14 = a3[6];
  v15 = 4 * v13;
  if ( 4 * v13 > v14 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_get_reg_update",
      235,
      "buf size:%d is not sufficient, expected: %d",
      v14,
      v15);
    goto LABEL_9;
  }
  v17 = a1[3];
  v18 = *(_DWORD *)(*(_QWORD *)(v17 + 32) + 52LL);
  v21[0] = *(_DWORD *)(*(_QWORD *)(v17 + 16) + 56LL);
  v21[1] = v18;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_ver3_get_reg_update",
      244,
      "VFE:%d CAMIF reg_update_cmd 0x%X offset 0x%X",
      *(unsigned int *)(a1[2] + 4LL));
  v19 = *(_DWORD **)(v11 + 120);
  v20 = *((_QWORD *)a3 + 2);
  if ( *(v19 - 1) != -1401492769 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _DWORD *))v19)(v20, 1, v21);
  result = 0;
  a3[7] = v15;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
