__int64 __fastcall cam_vfe_camif_process_cmd(__int64 a1, int a2, _DWORD *a3, int a4)
{
  const char *v4; // x3
  const char *v5; // x5
  __int64 v6; // x4
  __int64 result; // x0
  __int64 v8; // x8
  int v9; // w6
  int v10; // w7
  __int64 v11; // x19
  __int64 (__fastcall *v12)(_QWORD); // x8
  int v15; // w0
  unsigned int v16; // w6
  int v17; // w20
  _QWORD *v18; // x8
  __int64 v21; // x9
  _DWORD *v22; // x8
  int v23; // w7
  int v24; // w6
  _DWORD *v25; // x9
  __int64 v26; // x0
  _DWORD *v27; // x19
  _DWORD v28[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a3 )
  {
    v4 = "cam_vfe_camif_process_cmd";
    v5 = "Invalid input arguments";
    v6 = 679;
    goto LABEL_9;
  }
  if ( a2 <= 19 )
  {
    if ( a2 != 3 )
    {
      if ( a2 == 18 )
      {
        result = 0;
        *(_BYTE *)(*(_QWORD *)(a1 + 24) + 22664LL) = *a3 == 1;
        goto LABEL_11;
      }
      if ( a2 == 19 )
      {
        *(_DWORD *)(*(_QWORD *)(a1 + 24) + 22672LL) = *a3;
LABEL_10:
        result = 4294967274LL;
        goto LABEL_11;
      }
LABEL_26:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_camif_process_cmd",
        710,
        "unsupported process command:%d",
        a2);
      goto LABEL_10;
    }
    if ( a4 == 56 )
    {
      if ( *(_QWORD *)a3 )
      {
        v11 = *(_QWORD *)(*(_QWORD *)a3 + 48LL);
        if ( v11 )
        {
          v12 = *(__int64 (__fastcall **)(_QWORD))(v11 + 24);
          if ( *((_DWORD *)v12 - 1) != 2010610996 )
            __break(0x8228u);
          v15 = v12(1);
          v16 = a3[6];
          v17 = 4 * v15;
          if ( 4 * v15 > v16 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_camif_get_reg_update",
              230,
              "buf size:%d is not sufficient, expected: %d",
              v16,
              v15);
            goto LABEL_10;
          }
          v21 = *(_QWORD *)(a1 + 24);
          v22 = a3;
          v23 = *(_DWORD *)(*(_QWORD *)(v21 + 16) + 36LL);
          v24 = *(_DWORD *)(*(_QWORD *)(v21 + 32) + 72LL);
          v28[0] = v23;
          v28[1] = v24;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_camif_get_reg_update",
              238,
              "CAMIF reg_update_cmd %x offset %x",
              v24,
              v23);
            v22 = a3;
          }
          v25 = *(_DWORD **)(v11 + 120);
          v26 = *((_QWORD *)v22 + 2);
          v27 = v22;
          if ( *(v25 - 1) != -1401492769 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _DWORD *))v25)(v26, 1, v28);
          result = 0;
          v27[7] = v17;
          goto LABEL_11;
        }
        v4 = "cam_vfe_camif_get_reg_update";
        v5 = "Invalid CDM ops";
        v6 = 222;
      }
      else
      {
        v4 = "cam_vfe_camif_get_reg_update";
        v5 = "Invalid args";
        v6 = 215;
      }
    }
    else
    {
      v4 = "cam_vfe_camif_get_reg_update";
      v5 = "Invalid cmd size";
      v6 = 210;
    }
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v4,
      v6,
      v5);
    goto LABEL_10;
  }
  if ( a2 == 20 )
  {
    v18 = *(_QWORD **)(a1 + 24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_dump_timestamps",
      650,
      "CAMIF ERROR timestamp:[%lld.%09lld] SOF timestamp:[%lld.%09lld] EPOCH timestamp:[%lld.%09lld] EOF timestamp:[%lld.%09lld]",
      v18[2842],
      v18[2843],
      v18[2836],
      v18[2837],
      v18[2838],
      v18[2839],
      v18[2840],
      v18[2841]);
    result = 0;
    goto LABEL_11;
  }
  if ( a2 == 30 )
  {
    result = 0;
    *(_QWORD *)a3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL);
    goto LABEL_11;
  }
  if ( a2 != 39 )
    goto LABEL_26;
  v8 = *(_QWORD *)(a1 + 24);
  v9 = *a3;
  result = 0;
  v8 += 20480;
  *(_DWORD *)(v8 + 2176) = *a3;
  v10 = a3[1];
  *(_DWORD *)(v8 + 2180) = v10;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_blanking_update",
      668,
      "hbi:%d vbi:%d",
      v9,
      v10);
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
