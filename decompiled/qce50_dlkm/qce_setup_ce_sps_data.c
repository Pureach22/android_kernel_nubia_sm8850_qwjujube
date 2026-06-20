void *__fastcall qce_setup_ce_sps_data(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v4; // x23
  __int64 v5; // x25
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x9
  int v9; // w11
  void *result; // x0
  __int64 v11; // x28
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x10
  int v16; // w8
  int v17; // w8
  int v18; // w12
  int v19; // w11
  __int64 v20; // x9
  int v21; // w12
  __int64 v22; // x8
  int v23; // w10
  __int64 v24; // x11
  int v25; // w13
  __int64 v26; // x27
  __int64 v27; // x26
  unsigned __int64 v28; // x11
  __int64 v29; // x12
  __int64 v30; // x13
  unsigned __int64 v31; // x14
  __int64 v32; // x11
  __int64 v33; // x10
  __int64 v34; // x12
  bool v35; // zf
  int v36; // w14
  __int64 v37; // x9
  __int64 v38; // x9
  __int64 v39; // x8
  int v40; // w10
  int v41; // w11
  int v42; // w10
  int v43; // w10
  int v44; // w10
  int v45; // w9
  int v46; // w10
  __int64 v47; // x9
  int v48; // w10
  int v49; // w11
  int v50; // w10
  int v51; // w11
  int v52; // w10
  int v53; // w11
  _QWORD *v54; // x24
  __int64 v55; // x1
  __int64 v56; // x2
  int v57; // [xsp+Ch] [xbp-14h]
  _QWORD v58[2]; // [xsp+10h] [xbp-10h] BYREF

  v2 = 0;
  v3 = 0;
  v4 = 8752;
  v58[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1 + 69632;
  v6 = *(_QWORD *)(a1 + 16);
  v7 = *(int *)(a1 + 400);
  v8 = *(_QWORD *)(a1 + 40);
  v9 = *(_DWORD *)(a1 + 48);
  result = &unk_18000;
  v11 = v8 << 8;
  v57 = v9;
  v12 = (v6 + v7 - 1) & -v7;
  do
  {
    v26 = a1 + v2;
    *(_QWORD *)(v26 + 2664) = v8;
    v27 = v8 + 4096;
    v28 = (v11 >> 8) + 0x8000000000LL;
    v29 = memstart_addr;
    v30 = kimage_voffset;
    v31 = v28 >> 38;
    *(_QWORD *)(v26 + 2696) = v8 + 4096;
    v32 = v29 + v28;
    v33 = (v11 >> 8) - v30;
    v34 = (v11 + 0x100000) >> 8;
    v35 = v31 == 0;
    v36 = *(unsigned __int8 *)(a1 + 68);
    if ( v35 )
      v33 = v32;
    *(_QWORD *)(v26 + 2656) = v33;
    v37 = memstart_addr + v34 + 0x8000000000LL;
    if ( (unsigned __int64)(v34 + 0x8000000000LL) >> 38 )
      v37 = v34 - kimage_voffset;
    *(_QWORD *)(v26 + 2688) = v37;
    if ( v36 == 1 )
    {
      v58[0] = (v12 + *(int *)(a1 + 400) - 1) & -(__int64)*(int *)(a1 + 400);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 1);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 1);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 1);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 3, 1);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 0);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 0);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 0);
      setup_cipher_aes_cmdlistptrs(a1, (unsigned int)v3, v58, 3, 0);
      setup_cipher_des_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 1);
      setup_cipher_des_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 0);
      setup_cipher_des_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 1);
      setup_cipher_des_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 0);
      setup_auth_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 0);
      setup_auth_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 0);
      setup_auth_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 0);
      setup_auth_cmdlistptrs(a1, (unsigned int)v3, v58, 3, 0);
      setup_auth_cmdlistptrs(a1, (unsigned int)v3, v58, 4, 1);
      setup_auth_cmdlistptrs(a1, (unsigned int)v3, v58, 4, 0);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 8, 1);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 24, 1);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 16, 1);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 32, 1);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 0, 8, 0);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 1, 24, 0);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 16, 0);
      setup_aead_cmdlistptrs(a1, (unsigned int)v3, v58, 2, 32, 0);
      v38 = *(int *)(a1 + 400);
      v39 = (v58[0] + v38 - 1) & -v38;
      v40 = *(_DWORD *)(a1 + 88);
      *(_QWORD *)(v26 + 8544) = v39;
      v41 = *(_DWORD *)(v5 + 624);
      v58[0] = v39;
      *(_QWORD *)(v39 + 8) = 0xFFFFFFFFLL;
      *(_DWORD *)v39 = v41 & (v40 + 106768) & 0xFFFFFF;
      *(_DWORD *)(v39 + 4) = v38;
      LODWORD(v38) = *(_DWORD *)(v5 + 624) & (*(_DWORD *)(a1 + 88) + 107008);
      v42 = *(_DWORD *)(a1 + 164);
      *(_QWORD *)(v39 + 24) = 0xFFFFFFFFLL;
      *(_DWORD *)(v39 + 16) = v38 & 0xFFFFFF;
      *(_DWORD *)(v39 + 20) = v42;
      LODWORD(v38) = *(_DWORD *)(a1 + 88);
      v43 = *(_DWORD *)(v5 + 624);
      *(_QWORD *)(v39 + 36) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v39 + 44) = 0;
      *(_DWORD *)(v39 + 32) = v43 & (v38 + 107012) & 0xFFFFFF;
      LODWORD(v38) = *(_DWORD *)(a1 + 88);
      v44 = *(_DWORD *)(v5 + 624);
      *(_QWORD *)(v39 + 52) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v39 + 60) = 0;
      *(_DWORD *)(v39 + 48) = v44 & (v38 + 107016) & 0xFFFFFF;
      if ( *(_BYTE *)(a1 + 73) == 1 )
      {
        v45 = *(_DWORD *)(a1 + 88);
        v46 = *(_DWORD *)(v5 + 624);
        *(_QWORD *)(v39 + 68) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v39 + 76) = 0;
        *(_DWORD *)(v39 + 64) = v46 & (v45 + 107524) & 0xFFFFFF;
        v47 = v39 + 80;
      }
      else
      {
        v47 = v39 + 64;
      }
      v48 = *(_DWORD *)(a1 + 88);
      v49 = *(_DWORD *)(v5 + 624);
      *(_QWORD *)(v47 + 4) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v47 + 12) = 0;
      *(_DWORD *)v47 = v49 & (v48 + 107264) & 0xFFFFFF;
      v50 = *(_DWORD *)(a1 + 88);
      v51 = *(_DWORD *)(v5 + 624);
      *(_QWORD *)(v47 + 20) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v47 + 28) = 0;
      *(_DWORD *)(v47 + 16) = v51 & (v50 + 107268) & 0xFFFFFF;
      v52 = *(_DWORD *)(a1 + 88);
      v53 = *(_DWORD *)(v5 + 624);
      *(_QWORD *)(v47 + 36) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v47 + 44) = 0;
      v54 = (_QWORD *)(a1 + v2);
      *(_DWORD *)(v47 + 32) = v53 & (v52 + 107272) & 0xFFFFFF;
      *(_DWORD *)(v47 + 48) = *(_DWORD *)(v5 + 624) & (*(_DWORD *)(a1 + 88) + 106784) & 0xFFFFFF;
      *(_QWORD *)(v47 + 52) = 0xFFFFFFFF00000007LL;
      *(_DWORD *)(v47 + 60) = 0;
      if ( a1 + v4 )
        v54[1094] = v47 + 48;
      v13 = v47 + 64;
      v54[1095] = v13 - v39;
      v58[0] = v13;
      setup_aead_ccm_cmdlistptrs(a1, (unsigned int)v3, v58, 1);
      setup_aead_ccm_cmdlistptrs(a1, (unsigned int)v3, v58, 0);
      setup_f8_cmdlistptrs(a1, (unsigned int)v3, v58, 0);
      setup_f8_cmdlistptrs(a1, (unsigned int)v3, v58, 1);
      setup_f9_cmdlistptrs(a1, (unsigned int)v3, v58, 0);
      setup_f9_cmdlistptrs(a1, (unsigned int)v3, v58, 1);
      v14 = v58[0];
      result = &unk_18000;
      v15 = (v58[0] + *(int *)(a1 + 400) - 1LL) & -(__int64)*(int *)(a1 + 400);
      v16 = *(_DWORD *)(a1 + 88) + 106768;
      v54[1208] = v15;
      v17 = *(_DWORD *)(v5 + 624) & (v16 + 760);
      v18 = *(unsigned __int8 *)(v5 + 620) ^ 1;
      *(_QWORD *)(v15 + 8) = 0xFFFFFFFFLL;
      v19 = v17 & 0xFFFFFF;
      v12 = v15 + 16;
      *(_DWORD *)v15 = v19;
      *(_DWORD *)(v15 + 4) = v18;
      v54[1235] = v15 + 16 - v14;
    }
    v20 = *(int *)(a1 + 400);
    v21 = *(_DWORD *)(a1 + 16);
    ++v3;
    v2 += 7432;
    v11 += 0x200000;
    v4 += 7432;
    v22 = (v12 + v20 - 1) & -v20;
    v23 = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(v26 + 9888) = v22;
    v24 = v22 + 128;
    *(_QWORD *)(v26 + 9912) = v22;
    v25 = v22 + v23;
    v22 += 256;
    *(_DWORD *)(v26 + 9904) = v22;
    v12 = v22 + 2 * (int)v20;
    v8 = v27 + 4096;
    *(_DWORD *)(v26 + 9892) = v24;
    *(_QWORD *)(v26 + 9920) = v24;
    *(_DWORD *)(v26 + 9896) = v25 - v21;
    *(_DWORD *)(v26 + 9900) = v23 - v21 + v24;
    v58[0] = v12;
  }
  while ( v3 != 9 );
  v55 = *(int *)(a1 + 32);
  v56 = v12 - *(_QWORD *)(a1 + 16);
  if ( v56 > v55 || v57 - 73728 < 0 )
    panic("qce50: Not enough coherent memory. Allocate %x , need %lx\n", v55, v56);
  _ReadStatusReg(SP_EL0);
  return result;
}
