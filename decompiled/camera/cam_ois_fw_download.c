__int64 __fastcall cam_ois_fw_download(__int64 a1)
{
  __int64 v2; // x23
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  unsigned int v7; // w0
  unsigned int v8; // w22
  __int64 v9; // x27
  unsigned int v10; // w22
  unsigned int v11; // w21
  __int64 v12; // x20
  __int64 v13; // x8
  __int64 v14; // x12
  unsigned __int8 *v15; // x9
  int v16; // t1
  __int64 v17; // x14
  unsigned int v18; // w0
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  unsigned int v23; // w0
  const char *v24; // x5
  __int64 v25; // x4
  __int64 v26; // x23
  __int64 v27; // x0
  __int64 v28; // x8
  unsigned __int8 *v29; // x9
  int v30; // t1
  __int64 v31; // x12
  __int64 v32; // x4
  __int64 v34; // [xsp+8h] [xbp-78h] BYREF
  int v35; // [xsp+10h] [xbp-70h]
  _BYTE v36[12]; // [xsp+14h] [xbp-6Ch]
  __int64 v37; // [xsp+20h] [xbp-60h]
  __int64 v38; // [xsp+28h] [xbp-58h]
  __int64 *v39; // [xsp+30h] [xbp-50h] BYREF
  _QWORD s[4]; // [xsp+38h] [xbp-48h] BYREF
  char v41[8]; // [xsp+58h] [xbp-28h] BYREF
  __int64 v42; // [xsp+60h] [xbp-20h]
  __int64 v43; // [xsp+68h] [xbp-18h]
  __int64 v44; // [xsp+70h] [xbp-10h]
  __int64 v45; // [xsp+78h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v39 = nullptr;
  memset(s, 0, sizeof(s));
  v43 = 0;
  v44 = 0;
  *(_QWORD *)v41 = 0;
  v42 = 0;
  v37 = 0;
  v38 = 0;
  *(_QWORD *)&v36[4] = 0;
  snprintf((char *)s, 0x20u, "%s.coeff", (const char *)(a1 + 4516));
  snprintf(v41, 0x20u, "%s.prog", (const char *)(a1 + 4516));
  v7 = request_firmware(&v39, v41, v2 + 16, v3, v4, v5, v6);
  if ( !v7 )
  {
    v9 = *v39;
    *(_WORD *)&v36[8] = 0;
    *(_QWORD *)v36 = 0x100000001LL;
    v10 = 16 * (unsigned __int16)v9;
    v11 = (unsigned __int16)v9;
    v35 = (unsigned __int16)v9;
    v12 = vmalloc_noprof(v10);
    if ( v12 )
    {
      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "cam_ois_fw_download",
          982,
          "FW prog size:%d.",
          (unsigned __int16)v9);
      v34 = v12;
      if ( (_WORD)v9 )
      {
        v13 = 0;
        v14 = v12;
        v15 = (unsigned __int8 *)v39[1];
        do
        {
          *(_DWORD *)(v14 + v13) = *(_DWORD *)(a1 + 4550);
          v14 = v34;
          v16 = *v15++;
          v17 = v34 + v13;
          v13 += 16;
          *(_DWORD *)(v17 + 4) = v16;
          *(_QWORD *)(v17 + 8) = 0;
        }
        while ( 16LL * (unsigned __int16)v9 != v13 );
      }
      v18 = camera_io_dev_write_continuous(a1 + 3656, &v34, 1);
      if ( (v18 & 0x80000000) != 0 )
      {
        v8 = v18;
        v24 = "OIS FW(prog) size(%d) download failed. %d";
        v25 = 1000;
        goto LABEL_14;
      }
      vfree(v12);
      release_firmware(v39);
      v23 = request_firmware(&v39, s, v2 + 16, v19, v20, v21, v22);
      if ( v23 )
      {
        v8 = v23;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_fw_download",
          1009,
          "Failed to locate %s",
          (const char *)s);
        goto LABEL_28;
      }
      v26 = *v39;
      *(_WORD *)&v36[8] = 0;
      *(_QWORD *)v36 = 0x100000001LL;
      v10 = 16 * (unsigned __int16)v26;
      v11 = (unsigned __int16)v26;
      v35 = (unsigned __int16)v26;
      v27 = vmalloc_noprof(v10);
      v12 = v27;
      if ( v27 )
      {
        if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100000,
            4,
            "cam_ois_fw_download",
            1027,
            "FW coeff size:%d",
            (unsigned __int16)v26);
          v34 = v12;
          if ( (_WORD)v26 )
          {
LABEL_20:
            v28 = 0;
            v29 = (unsigned __int8 *)v39[1];
            do
            {
              *(_DWORD *)(v34 + v28) = *(_DWORD *)(a1 + 4554);
              v30 = *v29++;
              *(_DWORD *)(v34 + v28 + 4) = v30;
              *(_DWORD *)(v34 + v28 + 8) = 0;
              v31 = v34 + v28;
              v28 += 16;
              *(_DWORD *)(v31 + 12) = 0;
            }
            while ( 16LL * (unsigned __int16)v26 != v28 );
          }
        }
        else
        {
          v34 = v27;
          if ( (_WORD)v26 )
            goto LABEL_20;
        }
        v8 = camera_io_dev_write_continuous(a1 + 3656, &v34, 1);
        if ( (v8 & 0x80000000) == 0 )
          goto LABEL_15;
        v24 = "OIS FW(coeff) size(%d) download failed rc: %d";
        v25 = 1046;
LABEL_14:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_fw_download",
          v25,
          v24,
          v11,
          v8);
LABEL_15:
        vfree(v12);
        release_firmware(v39);
        goto LABEL_28;
      }
      v32 = 1022;
    }
    else
    {
      v32 = 977;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_fw_download",
      v32,
      "Failed in allocating i2c_array: fw_size: %u",
      v10);
    release_firmware(v39);
    v8 = -12;
    goto LABEL_28;
  }
  v8 = v7;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x100000,
    1,
    "cam_ois_fw_download",
    964,
    "Failed to locate %s",
    v41);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v8;
}
