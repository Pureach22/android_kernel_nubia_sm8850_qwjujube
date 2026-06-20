__int64 __fastcall boot_nvmem_show(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // w12
  char v4; // w13
  char v5; // w15
  char v6; // w14
  char v7; // w16
  bool v8; // zf
  char v9; // w14
  char v10; // w16
  char v11; // w12
  char v12; // w13
  char v13; // w12
  char v14; // w15
  char v15; // w16
  char v16; // w12
  char v17; // w15
  char v18; // w13
  char v19; // w13
  char v20; // w12
  char v21; // w12
  char v22; // w13
  char v23; // w14
  char v24; // w13
  char v25; // w9
  char v26; // w14
  char v27; // w8
  __int64 result; // x0
  _BYTE v29[12]; // [xsp+8h] [xbp-48h] BYREF
  __int16 v30; // [xsp+14h] [xbp-3Ch]
  __int64 v31; // [xsp+16h] [xbp-3Ah]
  __int64 v32; // [xsp+1Eh] [xbp-32h]
  __int64 v33; // [xsp+26h] [xbp-2Ah]
  __int64 v34; // [xsp+2Eh] [xbp-22h]
  __int64 v35; // [xsp+36h] [xbp-1Ah]
  __int64 v36; // [xsp+3Eh] [xbp-12h]
  __int16 v37; // [xsp+46h] [xbp-Ah]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = read_nvmem_buf;
  v4 = byte_D;
  v5 = byte_E;
  v6 = *((_BYTE *)&ctype + (unsigned __int8)read_nvmem_buf);
  v7 = *((_BYTE *)&ctype + (unsigned __int8)byte_D);
  v37 = 0;
  v36 = 0;
  v8 = (v6 & 0x97) == 0;
  v9 = byte_10;
  v35 = 0;
  if ( v8 )
    v3 = 42;
  v8 = (v7 & 0x97) == 0;
  v10 = *((_BYTE *)&ctype + (unsigned __int8)byte_E);
  v29[0] = v3;
  v11 = *((_BYTE *)&ctype + (unsigned __int8)byte_F);
  if ( v8 )
    v4 = 42;
  v29[1] = v4;
  v12 = byte_11;
  if ( (v10 & 0x97) == 0 )
    v5 = 42;
  v8 = (v11 & 0x97) == 0;
  v13 = *((_BYTE *)&ctype + (unsigned __int8)byte_10);
  v29[2] = v5;
  v14 = *((_BYTE *)&ctype + (unsigned __int8)byte_11);
  if ( v8 )
    v15 = 42;
  else
    v15 = byte_F;
  v8 = (v13 & 0x97) == 0;
  v16 = byte_12;
  v29[3] = v15;
  if ( v8 )
    v9 = 42;
  v8 = (v14 & 0x97) == 0;
  v17 = *((_BYTE *)&ctype + (unsigned __int8)byte_12);
  if ( v8 )
    v12 = 42;
  v29[4] = v9;
  v29[5] = v12;
  v18 = *((_BYTE *)&ctype + (unsigned __int8)byte_13);
  v34 = 0;
  if ( (v17 & 0x97) == 0 )
    v16 = 42;
  v8 = (v18 & 0x97) == 0;
  v19 = *((_BYTE *)&ctype + (unsigned __int8)byte_14);
  v29[6] = v16;
  if ( v8 )
    v20 = 42;
  else
    v20 = byte_13;
  v29[7] = v20;
  v21 = byte_16;
  if ( (v19 & 0x97) != 0 )
    v22 = byte_14;
  else
    v22 = 42;
  v23 = *((_BYTE *)&ctype + (unsigned __int8)byte_15);
  v29[8] = v22;
  v24 = *((_BYTE *)&ctype + (unsigned __int8)byte_16);
  v25 = *((_BYTE *)&ctype + (unsigned __int8)byte_17);
  v33 = 0;
  if ( (v23 & 0x97) != 0 )
    v26 = byte_15;
  else
    v26 = 42;
  v32 = 0;
  if ( (v24 & 0x97) == 0 )
    v21 = 42;
  v31 = 0;
  if ( (v25 & 0x97) != 0 )
    v27 = byte_17;
  else
    v27 = 42;
  v29[9] = v26;
  v29[11] = v27;
  v29[10] = v21;
  v30 = 10;
  LODWORD(result) = scnprintf(a3, 4096, "%s", v29);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
