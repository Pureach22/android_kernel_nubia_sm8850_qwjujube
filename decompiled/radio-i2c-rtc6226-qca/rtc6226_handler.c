__int64 __fastcall rtc6226_handler(__int64 a1)
{
  __int64 v2; // x8
  __int16 v3; // w10
  __int64 v4; // x0
  char v5; // w9
  __int64 v6; // x8
  __int16 v7; // w9
  __int64 v8; // x0
  __int64 result; // x0
  unsigned int v10; // w8
  __int64 v11; // x8
  __int16 v12; // w9
  __int64 v13; // x0
  __int64 v14; // x10
  __int16 v15; // x8^2
  __int16 v16; // w8
  __int64 v17; // x0
  unsigned int v18; // w8
  __int64 v19; // x8
  __int16 v20; // w9
  __int64 v21; // x0
  unsigned int v22; // w8
  __int64 v23; // x10
  __int16 v24; // w9
  __int64 v25; // x0
  int v26; // w9
  __int64 v27; // x8
  __int16 v28; // w10
  __int64 v29; // x0
  unsigned int v30; // w8
  __int16 v31; // w10
  __int64 v32; // x11
  __int64 v33; // x0
  __int64 v34; // x10
  __int16 v35; // w8
  __int16 v36; // w23
  __int16 v37; // w9
  __int64 v38; // x0
  int v39; // w8
  void *v40; // x0
  unsigned __int16 v41; // [xsp+0h] [xbp-30h] BYREF
  char v42; // [xsp+2h] [xbp-2Eh]
  _BYTE v43[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v44; // [xsp+8h] [xbp-28h] BYREF
  int v45; // [xsp+Ah] [xbp-26h]
  __int16 v46; // [xsp+Eh] [xbp-22h]
  unsigned __int16 *v47; // [xsp+10h] [xbp-20h]
  __int16 v48; // [xsp+18h] [xbp-18h]
  int v49; // [xsp+1Ah] [xbp-16h]
  __int16 v50; // [xsp+1Eh] [xbp-12h]
  unsigned __int16 *v51; // [xsp+20h] [xbp-10h]
  __int64 v52; // [xsp+28h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 1176);
  v41 = 0;
  v3 = *(_WORD *)(v2 + 2);
  v45 = 0x10000;
  v47 = (unsigned __int16 *)v43;
  v46 = 0;
  v49 = 131073;
  v51 = &v41;
  v4 = *(_QWORD *)(v2 + 24);
  v44 = v3;
  v48 = v3;
  v50 = 0;
  v43[0] = 10;
  if ( (unsigned int)i2c_transfer(v4, &v44, 2) != 2 )
  {
    v40 = &unk_D105;
    goto LABEL_22;
  }
  v5 = v41;
  *(_WORD *)(a1 - 530) = _byteswap_ushort(v41);
  if ( (v5 & 0x40) == 0 )
  {
    v6 = *(_QWORD *)(a1 + 1176);
    v7 = *(_WORD *)(v6 + 2);
    v51 = &v41;
    v8 = *(_QWORD *)(v6 + 24);
    v41 = 0;
    v44 = v7;
    v48 = v7;
    v45 = 0x10000;
    v46 = 0;
    v47 = (unsigned __int16 *)v43;
    v49 = 131073;
    v50 = 0;
    v43[0] = 11;
    result = i2c_transfer(v8, &v44, 2);
    if ( (_DWORD)result != 2 )
      goto LABEL_23;
    v10 = v41;
    v41 = 0;
    *(_WORD *)(a1 - 528) = bswap32(v10) >> 16;
    v11 = *(_QWORD *)(a1 + 1176);
    v12 = *(_WORD *)(v11 + 2);
    v51 = &v41;
    v13 = *(_QWORD *)(v11 + 24);
    v45 = 0x10000;
    v44 = v12;
    v48 = v12;
    v46 = 0;
    v47 = (unsigned __int16 *)v43;
    v49 = 131073;
    v50 = 0;
    v43[0] = 12;
    result = i2c_transfer(v13, &v44, 2);
    if ( (_DWORD)result != 2 )
      goto LABEL_23;
    v14 = *(_QWORD *)(a1 + 1176);
    v15 = bswap32(v41) >> 16;
    v41 = 0;
    *(_WORD *)(a1 - 526) = v15;
    v16 = *(_WORD *)(v14 + 2);
    v51 = &v41;
    v17 = *(_QWORD *)(v14 + 24);
    v45 = 0x10000;
    v44 = v16;
    v48 = v16;
    v46 = 0;
    v47 = (unsigned __int16 *)v43;
    v49 = 131073;
    v50 = 0;
    v43[0] = 13;
    result = i2c_transfer(v17, &v44, 2);
    if ( (_DWORD)result != 2 )
      goto LABEL_23;
    v18 = v41;
    v41 = 0;
    *(_WORD *)(a1 - 524) = bswap32(v18) >> 16;
    v19 = *(_QWORD *)(a1 + 1176);
    v20 = *(_WORD *)(v19 + 2);
    v51 = &v41;
    v21 = *(_QWORD *)(v19 + 24);
    v45 = 0x10000;
    v44 = v20;
    v48 = v20;
    v46 = 0;
    v47 = (unsigned __int16 *)v43;
    v49 = 131073;
    v50 = 0;
    v43[0] = 14;
    result = i2c_transfer(v21, &v44, 2);
    if ( (_DWORD)result != 2 )
      goto LABEL_23;
    v22 = v41;
    v23 = *(_QWORD *)(a1 + 1176);
    v41 = 0;
    *(_WORD *)(a1 - 522) = bswap32(v22) >> 16;
    v24 = *(_WORD *)(v23 + 2);
    v45 = 0x10000;
    v47 = (unsigned __int16 *)v43;
    v46 = 0;
    v49 = 131073;
    v51 = &v41;
    v25 = *(_QWORD *)(v23 + 24);
    v44 = v24;
    v48 = v24;
    v50 = 0;
    v43[0] = 15;
    result = i2c_transfer(v25, &v44, 2);
    if ( (_DWORD)result != 2 )
      goto LABEL_23;
    v26 = *(__int16 *)(a1 - 530);
    *(_WORD *)(a1 - 520) = bswap32(v41) >> 16;
    if ( v26 < 0 )
    {
      if ( (*(_WORD *)(a1 - 542) & 0x1000) != 0 )
        result = queue_work_on(32, system_wq, a1 - 256);
      goto LABEL_23;
    }
    v40 = &unk_D3B2;
LABEL_22:
    result = printk(v40, "rtc6226_i2c_interrupt_handler");
    goto LABEL_23;
  }
  v27 = *(_QWORD *)(a1 + 1176);
  v41 = 0;
  v28 = *(_WORD *)(v27 + 2);
  v45 = 0x10000;
  v47 = (unsigned __int16 *)v43;
  v51 = &v41;
  v29 = *(_QWORD *)(v27 + 24);
  v49 = 131073;
  v46 = 0;
  v44 = v28;
  v48 = v28;
  v50 = 0;
  v43[0] = 11;
  if ( (unsigned int)i2c_transfer(v29, &v44, 2) != 2 )
  {
    v40 = &unk_CC50;
    goto LABEL_22;
  }
  v30 = v41;
  v31 = *(_WORD *)(a1 - 540);
  LOBYTE(v41) = 5;
  *(_WORD *)(a1 - 540) = v31 & 0x7FFF;
  v32 = *(_QWORD *)(a1 + 1176);
  *(_WORD *)(a1 - 528) = bswap32(v30) >> 16;
  LOWORD(v30) = *(_WORD *)(v32 + 2);
  v33 = *(_QWORD *)(v32 + 24);
  HIBYTE(v41) = HIBYTE(v31) & 0x7F;
  v45 = 196608;
  v46 = 0;
  v47 = &v41;
  v44 = v30;
  v42 = v31;
  i2c_transfer(v33, &v44, 1);
  v34 = *(_QWORD *)(a1 + 1176);
  v35 = *(_WORD *)(a1 - 544);
  LOBYTE(v41) = 3;
  v36 = v35 & 0x7FFF;
  *(_WORD *)(a1 - 544) = v35 & 0x7FFF;
  v37 = *(_WORD *)(v34 + 2);
  v38 = *(_QWORD *)(v34 + 24);
  v45 = 196608;
  v46 = 0;
  v47 = &v41;
  HIBYTE(v41) = HIBYTE(v35) & 0x7F;
  v44 = v37;
  v42 = v35;
  if ( (unsigned int)i2c_transfer(v38, &v44, 1) != 1 )
    *(_WORD *)(a1 - 544) = v36;
  result = rtc6226_reset_rds_data(a1 - 2312);
  v39 = *(unsigned __int8 *)(a1 - 552);
  switch ( v39 )
  {
    case 1:
LABEL_18:
      result = rtc6226_q_event(a1 - 2312, 1);
      *(_BYTE *)(a1 - 552) = 0;
      break;
    case 3:
      result = complete(a1 + 1136);
      break;
    case 2:
      rtc6226_rds_on(a1 - 2312);
      rtc6226_q_event(a1 - 2312, 2);
      goto LABEL_18;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
