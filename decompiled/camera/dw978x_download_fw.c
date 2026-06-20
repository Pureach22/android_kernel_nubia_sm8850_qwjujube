__int64 __fastcall dw978x_download_fw(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x21
  unsigned int v6; // w0
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  unsigned int v11; // w22
  const char *v12; // x5
  __int64 v13; // x4
  unsigned int v14; // w0
  const char *v15; // x5
  const char *v16; // x6
  __int64 v17; // x4
  int v19; // w9
  unsigned int v20; // w10
  __int16 v21; // w8
  int v22; // w22
  __int64 v23; // x25
  int v24; // w28
  unsigned __int16 *v25; // x27
  unsigned int v26; // w25
  __int64 v27; // x9
  unsigned int v28; // t1
  __int64 v29; // x10
  int v30; // w0
  unsigned int v31; // w0
  int v32; // w28
  unsigned __int16 v33; // w8
  unsigned __int16 v34; // w23
  unsigned int v35; // w25
  __int64 v36; // x9
  unsigned int v37; // t1
  __int64 v38; // x10
  __int64 v39; // [xsp+8h] [xbp-88h]
  __int64 v41; // [xsp+18h] [xbp-78h] BYREF
  unsigned __int64 v42; // [xsp+20h] [xbp-70h]
  __int64 v43; // [xsp+28h] [xbp-68h]
  __int64 v44; // [xsp+30h] [xbp-60h]
  __int64 v45; // [xsp+38h] [xbp-58h]
  _QWORD *v46; // [xsp+40h] [xbp-50h] BYREF
  _QWORD s[9]; // [xsp+48h] [xbp-48h] BYREF

  s[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v46 = nullptr;
  memset(s, 0, 64);
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v41 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw978x_download_fw",
      583,
      "Invalid Args");
    v11 = -22;
    goto LABEL_10;
  }
  *(_WORD *)(*(_QWORD *)(a1 + 3672) + 20LL) = *(_WORD *)(a2 + 4) >> 1;
  *(_DWORD *)(*(_QWORD *)(a1 + 3672) + 12LL) = 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x100000,
    3,
    "dw978x_download_fw",
    588,
    "cam_ois_dw978x_firmware_download %s E",
    (const char *)(a1 + 4516));
  snprintf((char *)s, 0x40u, "%s.prog", (const char *)(a1 + 4516));
  v6 = cam_ois_write_regs(a1, a2, *(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 24));
  if ( !v6 )
  {
    v14 = request_firmware(&v46, s, v3 + 16, v7, v8, v9, v10);
    if ( v14 )
    {
      v11 = v14;
      v15 = "Failed to locate %s";
      v16 = (const char *)s;
      v17 = 600;
    }
    else
    {
      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "dw978x_download_fw",
          602,
          "fw->size %d",
          *v46);
      v20 = *(_DWORD *)(a2 + 8);
      v19 = *(_DWORD *)(a2 + 12);
      v21 = *(_WORD *)v46;
      WORD2(v43) = 0;
      LODWORD(v43) = v19;
      v22 = (unsigned __int16)(v21 - 512) >> 1;
      v42 = __PAIR64__(v20, v22);
      v23 = vmalloc_noprof((unsigned int)(16 * v22));
      if ( !v23 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "dw978x_download_fw",
          615,
          "Failed in allocating i2c_array: fw_size: %u",
          16 * v22);
        release_firmware(v46);
        v11 = -12;
        goto LABEL_10;
      }
      *(_DWORD *)(a1 + 4550) = 0x8000;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw978x_download_fw",
        621,
        "FW prog size(word):%d. o_ctrl->opcode.prog[0x%x]",
        v22,
        0x8000);
      v24 = 0;
      v39 = v23;
      v25 = (unsigned __int16 *)v46[1];
      v41 = v23;
      do
      {
        if ( (v22 & 0xFF80) != 0 )
          v26 = 128;
        else
          v26 = (unsigned __int16)v22;
        if ( (_WORD)v22 )
        {
          v27 = 0;
          do
          {
            *(_DWORD *)(v41 + v27) = *(_DWORD *)(a1 + 4550) + v24;
            v28 = *v25++;
            *(_DWORD *)(v41 + v27 + 4) = bswap32(v28) >> 16;
            *(_DWORD *)(v41 + v27 + 8) = 0;
            v29 = v41 + v27;
            v27 += 16;
            *(_DWORD *)(v29 + 12) = 0;
          }
          while ( 16LL * v26 != v27 );
        }
        else
        {
          v26 = 0;
        }
        LODWORD(v42) = v26;
        v30 = camera_io_dev_write_continuous(a1 + 3656, &v41, 1);
        if ( v30 < 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x100000,
            1,
            "dw978x_download_fw",
            643,
            "OIS FW download failed %d",
            v30);
        LOWORD(v22) = v22 - v26;
        v24 += v26;
      }
      while ( (_WORD)v22 );
      v31 = cam_ois_write_regs(a1, a2, *(_QWORD *)(a2 + 32), *(_DWORD *)(a2 + 40));
      if ( v31 )
      {
        v11 = v31;
        v12 = "Failed to dw978x extra init %d";
        v13 = 650;
        goto LABEL_5;
      }
      v32 = 0;
      v33 = 256;
      do
      {
        v34 = v33;
        if ( (v33 & 0xFF80) != 0 )
          v35 = 128;
        else
          v35 = v33;
        if ( v33 )
        {
          v36 = 0;
          do
          {
            *(_DWORD *)(v41 + v36) = *(_DWORD *)(a1 + 4550) + v32;
            v37 = *v25++;
            *(_DWORD *)(v41 + v36 + 4) = bswap32(v37) >> 16;
            *(_DWORD *)(v41 + v36 + 8) = 0;
            v38 = v41 + v36;
            v36 += 16;
            *(_DWORD *)(v38 + 12) = 0;
          }
          while ( 16LL * v35 != v36 );
        }
        else
        {
          v35 = 0;
        }
        LODWORD(v42) = v35;
        v11 = camera_io_dev_write_continuous(a1 + 3656, &v41, 1);
        if ( (v11 & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x100000,
            1,
            "dw978x_download_fw",
            673,
            "OIS FW download failed %d",
            v11);
        v33 = v34 - v35;
        v32 += v35;
      }
      while ( v34 != (_WORD)v35 );
      *a3 = cam_ois_read_firmware_ver(a1, a2);
      vfree(v39);
      release_firmware(v46);
      v15 = "%s Exit\n";
      v17 = 689;
      v16 = "dw978x_download_fw";
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw978x_download_fw",
      v17,
      v15,
      v16);
    goto LABEL_10;
  }
  v11 = v6;
  v12 = "Failed to dw978x init %d";
  v13 = 596;
LABEL_5:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x100000,
    1,
    "dw978x_download_fw",
    v13,
    v12,
    v11);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v11;
}
