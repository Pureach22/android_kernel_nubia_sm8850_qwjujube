__int64 __fastcall mhi_init_mmio(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x10
  unsigned __int64 v6; // x11
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x11
  __int64 v10; // x8
  __int64 result; // x0
  __int64 v12; // x2
  int v13; // w9
  unsigned int v14; // w8
  _QWORD *v15; // x9
  __int64 v16; // x10
  unsigned int v17; // w8
  unsigned int v18; // w2
  unsigned int v19; // w9
  _BYTE *v20; // x10
  __int64 v21; // x22
  __int64 v22; // x2
  unsigned int v23; // w0
  unsigned int v24; // w20
  __int64 v25; // x19
  __int64 v26; // x19
  unsigned int v27; // [xsp+Ch] [xbp-84h] BYREF
  _DWORD v28[28]; // [xsp+10h] [xbp-80h] BYREF
  __int64 v29; // [xsp+80h] [xbp-10h]
  __int64 v30; // [xsp+88h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 264);
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_QWORD *)(a1 + 32);
  v29 = 0;
  v6 = v2[3];
  v5 = v2[4];
  v7 = v2[5];
  v28[2] = 88;
  v28[3] = v5;
  v28[6] = 96;
  v28[7] = v6;
  v27 = 0;
  v28[0] = 92;
  v8 = HIDWORD(v6);
  v9 = HIDWORD(v7);
  v28[1] = HIDWORD(v5);
  v28[4] = 100;
  v28[5] = v8;
  v28[10] = 104;
  v28[11] = v7;
  LODWORD(v7) = *(_DWORD *)(a1 + 72);
  LODWORD(v8) = *(_DWORD *)(a1 + 76);
  v28[8] = 108;
  v28[9] = v9;
  v28[12] = 132;
  v28[13] = v8;
  v28[14] = 128;
  v28[15] = v7;
  v28[16] = 156;
  v28[17] = v8;
  v28[18] = 152;
  v28[19] = v7;
  LODWORD(v5) = *(_DWORD *)(a1 + 80);
  LODWORD(v8) = *(_DWORD *)(a1 + 84);
  v28[20] = 140;
  v28[21] = v8;
  v28[22] = 136;
  v28[23] = v5;
  v28[24] = 164;
  v28[25] = v8;
  v10 = *(_QWORD *)(v3 + 192);
  v28[26] = 160;
  v28[27] = v5;
  if ( v10 && !*(_DWORD *)(v10 + 24) )
    ipc_log_string(*(_QWORD *)(v10 + 32), "[D][%s] Initializing MHI registers\n", "mhi_init_mmio");
  result = mhi_get_channel_doorbell_offset(a1, &v27);
  if ( (_DWORD)result )
    goto LABEL_25;
  v12 = v27;
  if ( *(_QWORD *)(a1 + 144) - 1016LL <= (unsigned __int64)v27 )
  {
    dev_err(v3 + 40, "CHDB offset: 0x%x is out of range: 0x%zx\n");
LABEL_35:
    result = 4294967262LL;
    goto LABEL_25;
  }
  v13 = *(_DWORD *)(a1 + 208);
  *(_BYTE *)(a1 + 615) = 0;
  *(_QWORD *)(a1 + 56) = v4 + v12 + 1016;
  if ( v13 )
  {
    v14 = 0;
    v15 = (_QWORD *)(*(_QWORD *)(a1 + 176) + 192LL);
    do
    {
      v16 = v4 + (unsigned int)v12;
      ++v14;
      LODWORD(v12) = v12 + 8;
      *v15 = v16;
      v15 += 50;
    }
    while ( v14 < *(_DWORD *)(a1 + 208) );
    v27 = v12;
  }
  if ( (unsigned int)mhi_read_reg(a1, v4, 32, &v27) )
  {
    v26 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v3 + 40, "[E][%s] Unable to read ERDBOFF register\n", "mhi_init_mmio");
    if ( v26 && *(_DWORD *)(v26 + 24) <= 2u )
    {
      ipc_log_string(*(_QWORD *)(v26 + 32), "[E][%s] Unable to read ERDBOFF register\n", "mhi_init_mmio");
      result = 4294967291LL;
    }
    else
    {
      result = 4294967291LL;
    }
    goto LABEL_25;
  }
  v17 = *(_DWORD *)(a1 + 212);
  v18 = v27;
  if ( *(_QWORD *)(a1 + 144) - (unsigned __int64)(8 * v17) <= v27 )
  {
    dev_err(v3 + 40, "ERDB offset: 0x%x is out of range: 0x%zx\n");
    goto LABEL_35;
  }
  if ( v17 )
  {
    v19 = 0;
    v20 = (_BYTE *)(*(_QWORD *)(a1 + 248) + 258LL);
    do
    {
      if ( (*v20 & 1) == 0 )
      {
        *(_QWORD *)(v20 - 130) = v4 + v18;
        v17 = *(_DWORD *)(a1 + 212);
      }
      ++v19;
      v20 += 264;
      v18 += 8;
    }
    while ( v19 < v17 );
    v27 = v18;
  }
  v21 = 0;
  *(_QWORD *)(*(_QWORD *)(a1 + 256) + 88LL) = v4 + 112;
  while ( 1 )
  {
    v22 = (unsigned int)v28[v21];
    if ( !(_DWORD)v22 )
      break;
    mhi_write_reg(a1, v4, v22, (unsigned int)v28[v21 + 1]);
    v21 += 2;
    if ( v21 == 30 )
    {
      __break(0x5512u);
      break;
    }
  }
  v23 = mhi_write_reg_field(a1, v4, 16, 16711680, *(unsigned int *)(a1 + 212));
  if ( v23 || (v23 = mhi_write_reg_field(a1, v4, 16, 4278190080LL, *(unsigned int *)(a1 + 216))) != 0 )
  {
    v24 = v23;
    v25 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v3 + 40, "[E][%s] Unable to write MHICFG register\n", "mhi_init_mmio");
    if ( v25 && *(_DWORD *)(v25 + 24) <= 2u )
    {
      ipc_log_string(*(_QWORD *)(v25 + 32), "[E][%s] Unable to write MHICFG register\n", "mhi_init_mmio");
      result = v24;
    }
    else
    {
      result = v24;
    }
  }
  else
  {
    mhi_misc_init_mmio(a1);
    result = 0;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
