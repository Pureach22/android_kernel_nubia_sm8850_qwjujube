__int64 __fastcall dw9785_write_ois_firmware(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x24
  unsigned int v5; // w0
  __int64 v6; // x8
  unsigned int *v7; // x9
  unsigned __int16 *v8; // x10
  unsigned int v9; // w11
  unsigned int v10; // w0
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // t2
  unsigned int v13; // w19
  __int64 result; // x0
  unsigned int v15; // w19
  _QWORD v16[2]; // [xsp+8h] [xbp-268h] BYREF
  int v17; // [xsp+18h] [xbp-258h]
  __int64 v18; // [xsp+1Ch] [xbp-254h]
  __int64 v19; // [xsp+24h] [xbp-24Ch]
  int v20; // [xsp+2Ch] [xbp-244h]
  _QWORD v21[2]; // [xsp+30h] [xbp-240h] BYREF
  int v22; // [xsp+40h] [xbp-230h]
  __int64 v23; // [xsp+44h] [xbp-22Ch]
  __int64 v24; // [xsp+4Ch] [xbp-224h]
  int v25; // [xsp+54h] [xbp-21Ch]
  int v26; // [xsp+58h] [xbp-218h] BYREF
  int v27; // [xsp+5Ch] [xbp-214h]
  int v28; // [xsp+60h] [xbp-210h]
  int v29; // [xsp+64h] [xbp-20Ch]
  _DWORD v30[128]; // [xsp+68h] [xbp-208h] BYREF
  __int64 v31; // [xsp+268h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  memset(&v30[1], 0, 0x1FCu);
  v4 = 0;
  v21[0] = &v26;
  v21[1] = 0x200000001LL;
  v22 = 2;
  v17 = 2;
  v16[0] = v30;
  v16[1] = 0x200000020LL;
  v25 = 0;
  v26 = dword_BC390;
  v28 = dword_BC398;
  v29 = dword_BC39C;
  v23 = 0;
  v24 = 0;
  v18 = 0;
  v19 = 0;
  v30[0] = dword_BC3A0;
  v30[2] = dword_BC3A8;
  v30[3] = dword_BC3AC;
  v30[4] = dword_BC3A0;
  v30[6] = dword_BC3A8;
  v30[7] = dword_BC3AC;
  v30[8] = dword_BC3A0;
  v30[10] = dword_BC3A8;
  v30[11] = dword_BC3AC;
  v30[12] = dword_BC3A0;
  v30[14] = dword_BC3A8;
  v30[15] = dword_BC3AC;
  v30[16] = dword_BC3A0;
  v30[18] = dword_BC3A8;
  v30[19] = dword_BC3AC;
  v30[20] = dword_BC3A0;
  v30[22] = dword_BC3A8;
  v30[23] = dword_BC3AC;
  v30[24] = dword_BC3A0;
  v30[26] = dword_BC3A8;
  v30[27] = dword_BC3AC;
  v30[28] = dword_BC3A0;
  v30[30] = dword_BC3A8;
  v30[31] = dword_BC3AC;
  v30[32] = dword_BC3A0;
  v30[34] = dword_BC3A8;
  v30[35] = dword_BC3AC;
  v30[36] = dword_BC3A0;
  v30[38] = dword_BC3A8;
  v30[39] = dword_BC3AC;
  v30[40] = dword_BC3A0;
  v30[42] = dword_BC3A8;
  v30[43] = dword_BC3AC;
  v30[44] = dword_BC3A0;
  v30[46] = dword_BC3A8;
  v30[47] = dword_BC3AC;
  v30[48] = dword_BC3A0;
  v30[50] = dword_BC3A8;
  v30[51] = dword_BC3AC;
  v30[52] = dword_BC3A0;
  v30[54] = dword_BC3A8;
  v30[55] = dword_BC3AC;
  v30[56] = dword_BC3A0;
  v30[58] = dword_BC3A8;
  v30[59] = dword_BC3AC;
  v30[60] = dword_BC3A0;
  v30[62] = dword_BC3A8;
  v30[63] = dword_BC3AC;
  v30[64] = dword_BC3A0;
  v30[66] = dword_BC3A8;
  v30[67] = dword_BC3AC;
  v30[68] = dword_BC3A0;
  v30[70] = dword_BC3A8;
  v30[71] = dword_BC3AC;
  v30[72] = dword_BC3A0;
  v30[74] = dword_BC3A8;
  v30[75] = dword_BC3AC;
  v30[76] = dword_BC3A0;
  v30[78] = dword_BC3A8;
  v30[79] = dword_BC3AC;
  v30[80] = dword_BC3A0;
  v30[82] = dword_BC3A8;
  v30[83] = dword_BC3AC;
  v30[84] = dword_BC3A0;
  v30[86] = dword_BC3A8;
  v30[87] = dword_BC3AC;
  v30[88] = dword_BC3A0;
  v30[90] = dword_BC3A8;
  v30[91] = dword_BC3AC;
  v30[92] = dword_BC3A0;
  v30[94] = dword_BC3A8;
  v30[95] = dword_BC3AC;
  v30[96] = dword_BC3A0;
  v30[98] = dword_BC3A8;
  v30[99] = dword_BC3AC;
  v30[100] = dword_BC3A0;
  v30[102] = dword_BC3A8;
  v30[103] = dword_BC3AC;
  v30[104] = dword_BC3A0;
  v30[106] = dword_BC3A8;
  v30[107] = dword_BC3AC;
  v30[108] = dword_BC3A0;
  v30[110] = dword_BC3A8;
  v30[111] = dword_BC3AC;
  v30[112] = dword_BC3A0;
  v30[114] = dword_BC3A8;
  v30[115] = dword_BC3AC;
  v30[116] = dword_BC3A0;
  v30[118] = dword_BC3A8;
  v30[119] = dword_BC3AC;
  v30[120] = dword_BC3A0;
  v30[122] = dword_BC3A8;
  v30[123] = dword_BC3AC;
  v30[124] = dword_BC3A0;
  v30[126] = dword_BC3A8;
  v30[127] = dword_BC3AC;
  v20 = 0;
  do
  {
    v27 = 2 * v4;
    v5 = camera_io_dev_write_continuous(a1 + 3656, v21, 1);
    if ( v5 )
    {
      v13 = v5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_write_ois_firmware",
        467,
        "Address write failed at block %d (0x%04X)",
        (unsigned int)v4 >> 5,
        2 * v4);
      result = v13;
      goto LABEL_12;
    }
    v6 = 0;
    v7 = &v30[5];
    do
    {
      v8 = (unsigned __int16 *)(a2 + v6);
      v6 += 4;
      v9 = bswap32(*v8);
      LODWORD(v8) = bswap32(v8[1]);
      *(v7 - 4) = HIWORD(v9);
      *v7 = (unsigned int)v8 >> 16;
      v7 += 8;
    }
    while ( v6 != 64 );
    v10 = camera_io_dev_write_continuous(a1 + 3656, v16, 1);
    if ( v10 )
    {
      v15 = v10;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_write_ois_firmware",
        480,
        "Data write failed at block %d",
        (unsigned int)v4 >> 5);
      result = v15;
      goto LABEL_12;
    }
    v11 = v4 >> 5;
    HIDWORD(v12) = -858993459 * v4;
    LODWORD(v12) = -858993459 * v4;
    if ( (unsigned int)(v12 >> 6) <= 0xCCCCCC )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_write_ois_firmware",
        486,
        "procession: %d/%d",
        v11,
        504);
    v4 += 32LL;
    a2 += 64;
  }
  while ( v11 < 0x1F7 );
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
