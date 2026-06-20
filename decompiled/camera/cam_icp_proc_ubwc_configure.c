__int64 __fastcall cam_icp_proc_ubwc_configure(_DWORD *a1, char a2, unsigned int a3)
{
  __int64 v3; // x20
  int v4; // w9
  int v5; // w8
  const char *v6; // x5
  __int64 v7; // x4
  unsigned int v8; // w19
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v11; // x6
  int *v15; // x10
  unsigned int v16; // w9
  unsigned int v17; // w8
  unsigned int v18; // w10
  int v19; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v20; // [xsp+14h] [xbp-1Ch]
  int v21; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v22; // [xsp+1Ch] [xbp-14h]
  int v23; // [xsp+20h] [xbp-10h] BYREF
  unsigned int v24; // [xsp+24h] [xbp-Ch]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v4 = a1[2];
    v5 = *(_DWORD *)(*(_QWORD *)a1 + 48LL);
    if ( (v4 & 4) != 0 && (v5 & 4) == 0 )
    {
      v6 = "IPE does not have UBWC cfg value";
      v7 = 202;
LABEL_12:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_proc_validate_ubwc_cfg",
        v7,
        v6);
      v9 = "UBWC config failed validation rc:%d";
      v10 = 238;
      v11 = 4294967235LL;
      v8 = -61;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_proc_ubwc_configure",
        v10,
        v9,
        v11);
      goto LABEL_14;
    }
    if ( (v4 & 8) != 0 && (v5 & 8) == 0 )
    {
      v6 = "BPS does not have UBWC cfg value";
      v7 = 208;
      goto LABEL_12;
    }
    if ( (v4 & 0x10) != 0 && (v5 & 0x10) == 0 )
    {
      v6 = "OFE does not have UBWC cfg value";
      v7 = 214;
      goto LABEL_12;
    }
    v3 = *(_QWORD *)a1;
    v15 = (int *)(v3 + 4LL * ((cam_get_ddr_type() & 0xFFFFFFFE) == 8));
    v23 = *v15;
    v16 = v15[2];
    v24 = v16;
    v21 = v15[4];
    v17 = v15[6];
    v22 = v17;
    v19 = v15[8];
    v18 = v15[10];
    v20 = v18;
    if ( (a2 & 1) != 0 )
    {
      v24 = v16 & 0xFFFFFFFD;
      v22 = v17 & 0xFFFFFFFD;
      v20 = v18 & 0xFFFFFFFD;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_proc_ubwc_configure",
          262,
          "Force disable UBWC compression, ipe_ubwc_cfg: 0x%x, bps_ubwc_cfg: 0x%x ofe_ubwc_cfg: 0x%x",
          v16 & 0xFFFFFFFD,
          v17 & 0xFFFFFFFD,
          v18 & 0xFFFFFFFD);
    }
    v8 = hfi_cmd_ubwc_config_ext(a3, &v23, &v21, &v19);
    if ( v8 )
    {
      v9 = "Failed to write UBWC configure rc=%d";
      v10 = 267;
      v11 = v8;
      goto LABEL_13;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_proc_ubwc_configure",
      231,
      "ubwc config command is NULL");
    v8 = -22;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v8;
}
