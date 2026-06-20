__int64 __fastcall append_kv_pairs_if_needed_commit(__int64 a1, int *a2)
{
  __int64 v2; // x30
  __int64 v5; // x19
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x4
  int v9; // w22
  unsigned int appended; // w0
  __int64 v11; // x4
  unsigned int v12; // w0
  __int64 v13; // x4
  __int64 v14; // x3
  __int64 result; // x0
  unsigned int v16; // w20
  __int64 v17; // x30
  unsigned int v18; // w19
  int v19; // [xsp+18h] [xbp-218h] BYREF
  int v20; // [xsp+1Ch] [xbp-214h] BYREF
  __int64 v21; // [xsp+20h] [xbp-210h] BYREF
  __int64 v22; // [xsp+28h] [xbp-208h] BYREF
  __int64 v23; // [xsp+30h] [xbp-200h] BYREF
  _QWORD v24[2]; // [xsp+38h] [xbp-1F8h] BYREF
  _QWORD v25[3]; // [xsp+48h] [xbp-1E8h] BYREF
  __int64 v26; // [xsp+60h] [xbp-1D0h] BYREF
  __int64 v27; // [xsp+68h] [xbp-1C8h] BYREF
  unsigned __int64 v28; // [xsp+70h] [xbp-1C0h] BYREF
  __int64 v29; // [xsp+78h] [xbp-1B8h] BYREF
  __int64 v30; // [xsp+80h] [xbp-1B0h] BYREF
  __int64 v31; // [xsp+88h] [xbp-1A8h] BYREF
  __int64 v32; // [xsp+90h] [xbp-1A0h] BYREF
  _QWORD v33[2]; // [xsp+98h] [xbp-198h] BYREF
  _QWORD v34[3]; // [xsp+A8h] [xbp-188h] BYREF
  __int64 v35; // [xsp+C0h] [xbp-170h] BYREF
  __int64 v36; // [xsp+C8h] [xbp-168h] BYREF
  unsigned __int64 v37; // [xsp+D0h] [xbp-160h] BYREF
  __int64 v38; // [xsp+D8h] [xbp-158h] BYREF
  _QWORD s[42]; // [xsp+E0h] [xbp-150h] BYREF

  v5 = v2;
  s[40] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x140u);
  v26 = 0x78000000001LL;
  v27 = 0x43800000001LL;
  v19 = 2;
  v20 = 1;
  v28 = 0xDEADBEEF00000001LL;
  v29 = 0x100000500000001LL;
  v21 = 1;
  v22 = 0x3FF00000001LL;
  v30 = 0x100000002LL;
  v31 = 0x3FF00000002LL;
  v23 = 0x100000001LL;
  v24[0] = 1;
  v32 = 0x100000002LL;
  v33[0] = 0x3C000000002LL;
  v24[1] = 0x3C000000000LL;
  v25[0] = 0x100000438LL;
  v33[1] = 0x3C000000000LL;
  v34[0] = 0x200000438LL;
  v25[1] = 0;
  v25[2] = 0x438000003C0LL;
  v34[1] = 960;
  v34[2] = 0x438000003C0LL;
  v35 = 0x78000000002LL;
  v36 = 0x43800000002LL;
  v37 = 0xDEADBEEF00000002LL;
  v38 = 0x100000500000002LL;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_20:
      printk(&unk_1905C, "append_kv_pairs_if_needed_commit", 2381, v5, v7);
      result = 4294967274LL;
      goto LABEL_17;
    }
  }
  else
  {
    printk(&unk_1E83A, "append_kv_pairs_if_needed_commit", 2378, v6, v7);
    if ( !a1 )
      goto LABEL_20;
  }
  if ( !a2 )
    goto LABEL_20;
  v8 = (unsigned int)*a2;
  v9 = 33554433;
  if ( (_DWORD)v8 == 33554433 )
  {
    memset(s, 0, 0x140u);
    s[1] = &v20;
    LODWORD(s[0]) = 16908312;
    LODWORD(s[2]) = 16908312;
    s[3] = &v19;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      printk(&unk_1929C, "append_kv_pairs_if_needed_commit", 2400, 33554433, 2);
      v9 = *a2;
    }
    appended = hfi_append_packet_with_kv_pairs(a1, v9, 2, 0, (unsigned int *)s, 2, 0x10u);
    if ( appended )
    {
      v17 = v5;
      v18 = appended;
      printk(&unk_1D48C, "append_kv_pairs_if_needed_commit", 2404, v17, v11);
      result = v18;
      goto LABEL_17;
    }
    memset(s, 0, 0x140u);
    s[3] = &v22;
    s[1] = &v21;
    LODWORD(s[2]) = 33751043;
    LODWORD(s[4]) = 33751044;
    LODWORD(s[8]) = 84082694;
    LODWORD(s[10]) = 33751049;
    LODWORD(s[12]) = 33751048;
    s[11] = &v26;
    LODWORD(s[14]) = 33751050;
    s[13] = &v27;
    LODWORD(s[16]) = 33751051;
    LODWORD(s[0]) = 33751042;
    s[5] = &v23;
    LODWORD(s[6]) = 84082693;
    s[7] = v24;
    s[9] = (char *)v25 + 4;
    s[15] = &v28;
    s[17] = &v29;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1929C, "append_kv_pairs_if_needed_commit", 2437, (unsigned int)*a2, 9);
    v12 = hfi_append_packet_with_kv_pairs(a1, *a2, 2, 0, (unsigned int *)s, 9, 0x84u);
    if ( v12 )
      goto LABEL_18;
    memset(s, 0, 0x140u);
    LODWORD(s[2]) = 33751043;
    s[3] = &v31;
    LODWORD(s[4]) = 33751044;
    s[5] = &v32;
    s[7] = v33;
    LODWORD(s[8]) = 84082694;
    s[9] = (char *)v34 + 4;
    LODWORD(s[10]) = 33751049;
    s[11] = &v35;
    LODWORD(s[12]) = 33751048;
    s[13] = &v36;
    LODWORD(s[14]) = 33751050;
    s[15] = &v37;
    LODWORD(s[16]) = 33751051;
    LODWORD(s[0]) = 33751042;
    s[1] = &v30;
    LODWORD(s[6]) = 84082693;
    s[17] = &v38;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1929C, "append_kv_pairs_if_needed_commit", 2437, (unsigned int)*a2, 9);
    v12 = hfi_append_packet_with_kv_pairs(a1, *a2, 2, 0, (unsigned int *)s, 9, 0x84u);
    if ( v12 )
    {
LABEL_18:
      v16 = v12;
      printk(&unk_1D48C, "append_kv_pairs_if_needed_commit", 2442, v5, v13);
      result = v16;
      goto LABEL_17;
    }
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "append_kv_pairs_if_needed_commit", 2447, v14, v13);
  }
  else
  {
    printk(&unk_1DE25, "append_kv_pairs_if_needed_commit", 2386, v5, v8);
  }
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
