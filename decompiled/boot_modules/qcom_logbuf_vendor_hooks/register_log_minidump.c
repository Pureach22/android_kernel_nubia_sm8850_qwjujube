__int64 __fastcall register_log_minidump(__int64 result)
{
  __int64 v1; // x9
  __int64 v2; // x12
  __int64 v3; // x13
  unsigned __int64 v4; // x14
  __int64 v5; // x8
  int v6; // w12
  int v7; // w19
  __int64 v8; // x22
  __int64 v9; // x24
  __int64 v10; // x8
  unsigned __int64 v11; // x13
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x9
  unsigned __int64 v15; // x13
  __int64 v16; // x8
  __int64 v17; // x9
  _QWORD v18[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result && (register_log_minidump_log_buf_registered & 1) == 0 )
  {
    v1 = *(_QWORD *)(result + 56);
    v2 = v1 << 8 >> 8;
    register_log_minidump_log_buf_registered = 1;
    v3 = v2 + 0x8000000000LL;
    strcpy((char *)v18, "KLOGBUF");
    v18[1] = 0;
    v4 = (unsigned __int64)(v2 + 0x8000000000LL) >> 38;
    v5 = v2 - kimage_voffset;
    v6 = *(_DWORD *)(result + 48);
    v18[2] = 0;
    v19 = v1;
    v7 = *(_DWORD *)result;
    v9 = *(_QWORD *)(result + 8);
    v8 = *(_QWORD *)(result + 16);
    if ( !v4 )
      v5 = v3 + memstart_addr;
    v20 = v5;
    v21 = 1LL << v6;
    if ( (msm_minidump_add_region(v18) & 0x80000000) != 0 )
      printk(&unk_63D6);
    v10 = v9 << 8 >> 8;
    v11 = (unsigned __int64)(v10 + 0x8000000000LL) >> 38;
    strcpy((char *)v18, "LOG_DESC");
    v12 = memstart_addr + v10 + 0x8000000000LL;
    v13 = v10 - kimage_voffset;
    if ( !v11 )
      v13 = v12;
    v19 = v9;
    v20 = v13;
    v21 = 24LL << v7;
    if ( (msm_minidump_add_region(v18) & 0x80000000) != 0 )
      printk(&unk_6426);
    v14 = v8 << 8 >> 8;
    v15 = (unsigned __int64)(v14 + 0x8000000000LL) >> 38;
    strcpy((char *)v18, "LOG_INFO");
    v16 = v14 - kimage_voffset;
    v17 = memstart_addr + v14 + 0x8000000000LL;
    if ( !v15 )
      v16 = v17;
    v19 = v8;
    v20 = v16;
    v21 = 88LL << v7;
    result = msm_minidump_add_region(v18);
    if ( (result & 0x80000000) != 0 )
      result = printk(&unk_6399);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
