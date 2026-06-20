__int64 __fastcall aw_dev_reg_fw_update(__int64 a1)
{
  __int64 prof_data; // x0
  __int64 result; // x0
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1
  int v8; // w0
  unsigned int v9; // w21
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 v12; // x28
  int v13; // w21
  int v14; // w27
  __int16 *v15; // x8
  unsigned int v16; // w25
  unsigned int v17; // w26
  int v18; // w8
  int v19; // w8
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x0
  _DWORD *v22; // x8
  __int64 v23; // x0
  __int64 *v24; // x8
  __int64 v25; // x1
  __int64 *v26; // x8
  __int64 v27; // x1
  __int64 *v28; // x8
  __int64 v29; // x1
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x0
  int v32; // w21
  bool v33; // zf
  int v34; // w21
  __int64 (__fastcall *v35)(__int64, __int64, int *); // x8
  __int64 v36; // x0
  __int64 v37; // x1
  int v38; // w8
  unsigned int v39; // w9
  __int64 (__fastcall *v40)(__int64, __int64, int *); // x8
  __int64 v41; // x0
  __int64 v42; // x1
  int v43; // w22
  int v44; // w22
  __int64 (__fastcall *v45)(__int64, __int64, int *); // x8
  __int64 v46; // x0
  __int64 v47; // x1
  int v48; // w8
  unsigned int v49; // w9
  int v50; // w8
  int v51; // w4
  __int64 *v52; // x8
  __int64 v53; // x1
  unsigned int v54; // w21
  __int64 *v55; // x8
  __int64 v56; // x1
  _DWORD *v57; // x8
  __int64 v58; // x0
  __int64 v59; // x1
  int v60; // w0
  __int64 *v61; // x8
  int v62; // w21
  __int64 v63; // x1
  __int64 *v64; // x8
  unsigned int v65; // w20
  __int64 v66; // x1
  int v67; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v68; // [xsp+8h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !aw882xx_dev_get_prof_name(a1, *(unsigned __int8 *)(a1 + 49)) )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_2825F, v5, "aw_dev_reg_fw_update");
    goto LABEL_3;
  }
  prof_data = aw882xx_dev_get_prof_data(a1, *(unsigned __int8 *)(a1 + 49), 0);
  if ( !prof_data )
  {
LABEL_3:
    result = 4294967274LL;
    goto LABEL_4;
  }
  if ( *(_DWORD *)prof_data >= 2u )
  {
    v12 = *(_QWORD *)(prof_data + 8);
    v13 = *(_DWORD *)prof_data >> 1;
    v14 = 0;
    do
    {
      v15 = (__int16 *)(v12 + 2LL * v14);
      v16 = *v15;
      v17 = v15[1];
      if ( *(_DWORD *)(a1 + 296) == v16 )
      {
        *(_DWORD *)(a1 + 308) = v17;
        v17 = *(_DWORD *)(a1 + 304);
      }
      v18 = *(_DWORD *)(a1 + 260);
      if ( v18 != 255 )
      {
        if ( v18 == v16 )
          *(_DWORD *)(a1 + 272) = v17 & ~*(_DWORD *)(a1 + 264);
        if ( *(_DWORD *)(a1 + 276) == v16 )
          *(_DWORD *)(a1 + 292) = v17 & ~*(_DWORD *)(a1 + 280);
      }
      if ( *(_DWORD *)(a1 + 200) == v16 )
        v17 = *(_DWORD *)(a1 + 204) & v17 | *(_DWORD *)(a1 + 208);
      if ( *(_DWORD *)(a1 + 360) == v16 )
        v17 = *(_DWORD *)(a1 + 364) & v17 | *(_DWORD *)(a1 + 368);
      v19 = *(_DWORD *)(a1 + 244);
      if ( v19 != 255 && v19 == v16 )
      {
        v24 = *(__int64 **)(a1 + 112);
        *(_DWORD *)(a1 + 20) = (v17 & ~*(_DWORD *)(a1 + 248)) == *(_DWORD *)(a1 + 256);
        v25 = v24[14];
        if ( !v25 )
          v25 = *v24;
        printk(&unk_25267, v25, "aw_dev_reg_value_check");
      }
      if ( *(_DWORD *)(a1 + 312) == v16 )
        *(_DWORD *)(a1 + 8) = (v17 & ~*(_DWORD *)(a1 + 316)) != *(_DWORD *)(a1 + 324);
      if ( *(_DWORD *)(a1 + 336) == v16 )
        v17 = *(_DWORD *)(a1 + 340) & v17 | *(_DWORD *)(a1 + 344);
      if ( *(_DWORD *)(a1 + 384) == v16 )
        v17 = *(_DWORD *)(a1 + 388) & v17 | *(_DWORD *)(a1 + 392);
      if ( *(_DWORD *)(a1 + 408) == v16 )
        v17 = *(_DWORD *)(a1 + 412) & v17 | *(_DWORD *)(a1 + 416);
      if ( *(_DWORD *)(a1 + 424) == v16 )
      {
        v26 = *(__int64 **)(a1 + 112);
        *(_DWORD *)(a1 + 440) = v17 & ~*(_DWORD *)(a1 + 428);
        v27 = v26[14];
        if ( !v27 )
          v27 = *v26;
        printk(&unk_27965, v27, "aw_dev_reg_value_check");
        v17 = *(_DWORD *)(a1 + 428) & v17 | *(_DWORD *)(a1 + 436);
      }
      if ( *(_DWORD *)(a1 + 596) == v16 )
      {
        v20 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1176);
        if ( v20 )
        {
          v21 = (v17 & ~*(_DWORD *)(a1 + 600)) >> *(_DWORD *)(a1 + 604);
          if ( *((_DWORD *)v20 - 1) != 2010610996 )
            __break(0x8228u);
          *(_DWORD *)(a1 + 608) = v20(v21);
        }
      }
      if ( *(_DWORD *)(a1 + 1000) == v16 )
      {
        v28 = *(__int64 **)(a1 + 112);
        *(_DWORD *)(a1 + 40) = v17 & ~*(_DWORD *)(a1 + 1004);
        v29 = v28[14];
        if ( !v29 )
          v29 = *v28;
        printk(&unk_240B3, v29, "aw_dev_reg_value_check");
      }
      if ( *(_DWORD *)(a1 + 516) != v16 )
      {
        v22 = *(_DWORD **)(a1 + 1152);
        v23 = *(_QWORD *)(a1 + 120);
        if ( *(v22 - 1) != -1860236611 )
          __break(0x8228u);
        if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v22)(v23, v16, v17) & 0x80000000) != 0 )
          break;
      }
      v14 += 2;
    }
    while ( v14 < v13 );
  }
  ((void (__fastcall *)(__int64))aw882xx_spin_set_record_val)(a1);
  if ( *(_DWORD *)(a1 + 444) == 255 || *(_DWORD *)(a1 + 516) == 255 )
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = v6[14];
    if ( !v7 )
      v7 = *v6;
    printk(&unk_2243D, v7, "aw_dev_set_vcalb");
    v8 = 0;
LABEL_14:
    if ( *(unsigned __int8 *)(a1 + 48) != *(unsigned __int8 *)(a1 + 49) )
      *(_DWORD *)(a1 + 616) = 0;
    v9 = v8;
    if ( *(_DWORD *)(a1 + 24) )
      aw882xx_dev_set_volume(a1, *(unsigned int *)(a1 + 612));
    v10 = *(__int64 **)(a1 + 112);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_26A3A, v11, "aw_dev_reg_fw_update");
    result = v9;
    goto LABEL_4;
  }
  v30 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1160);
  v31 = *(_QWORD *)(a1 + 120);
  v32 = *(_DWORD *)(a1 + 456);
  v67 = 0;
  if ( *((_DWORD *)v30 - 1) != 1983062130 )
    __break(0x8228u);
  v8 = v30(v31);
  v33 = v32 == 255;
  v34 = v67 & ~*(_DWORD *)(a1 + 448);
  if ( !v33 )
  {
    v35 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
    v36 = *(_QWORD *)(a1 + 120);
    v37 = *(unsigned int *)(a1 + 456);
    if ( *((_DWORD *)v35 - 1) != 1983062130 )
      __break(0x8228u);
    v8 = v35(v36, v37, &v67);
    v38 = (unsigned __int16)v34 >> *(_DWORD *)(a1 + 452);
    v39 = ((unsigned __int16)v67 & (*(unsigned __int16 *)(a1 + 460) ^ 0xFFFFu)) >> *(_DWORD *)(a1 + 464);
    if ( *(_DWORD *)(a1 + 20) == 1 )
      v34 = v39 | v38;
    else
      v34 = v39 & v38;
  }
  if ( (v34 & (*(unsigned __int16 *)(a1 + 468) ^ 0xFFFF)) != 0 )
    v34 |= ~*(_DWORD *)(a1 + 472);
  if ( (v8 & 0x80000000) == 0 )
  {
    v40 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
    v41 = *(_QWORD *)(a1 + 120);
    v42 = *(unsigned int *)(a1 + 480);
    v43 = *(_DWORD *)(a1 + 492);
    v67 = 0;
    if ( *((_DWORD *)v40 - 1) != 1983062130 )
      __break(0x8228u);
    v8 = v40(v41, v42, &v67);
    v33 = v43 == 255;
    v44 = v67 & ~*(_DWORD *)(a1 + 484);
    if ( !v33 )
    {
      v45 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
      v46 = *(_QWORD *)(a1 + 120);
      v47 = *(unsigned int *)(a1 + 492);
      if ( *((_DWORD *)v45 - 1) != 1983062130 )
        __break(0x8228u);
      v8 = v45(v46, v47, &v67);
      v48 = (unsigned __int16)v44 >> *(_DWORD *)(a1 + 488);
      v49 = ((unsigned __int16)v67 & (*(unsigned __int16 *)(a1 + 496) ^ 0xFFFFu)) >> *(_DWORD *)(a1 + 500);
      if ( *(_DWORD *)(a1 + 20) == 1 )
        v44 = v49 | v48;
      else
        v44 = v49 & v48;
    }
    if ( (v44 & (*(unsigned __int16 *)(a1 + 504) ^ 0xFFFF)) != 0 )
      v44 |= ~*(_DWORD *)(a1 + 508);
    if ( (v8 & 0x80000000) == 0 )
    {
      v50 = *(_DWORD *)(a1 + 520);
      v51 = v50 + *(_DWORD *)(a1 + 512) * (__int16)v44;
      if ( v51 )
      {
        v54 = (v50 + *(_DWORD *)(a1 + 476) * (__int16)v34) * *(_DWORD *)(a1 + 524) / v51;
        v55 = *(__int64 **)(a1 + 112);
        v56 = v55[14];
        if ( !v56 )
          v56 = *v55;
        printk(&unk_240D7, v56, "aw_dev_set_vcalb");
        v57 = *(_DWORD **)(a1 + 1152);
        v58 = *(_QWORD *)(a1 + 120);
        v59 = *(unsigned int *)(a1 + 516);
        if ( *(v57 - 1) != -1860236611 )
          __break(0x8228u);
        v60 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v57)(v58, v59, v54);
        v61 = *(__int64 **)(a1 + 112);
        v62 = v60;
        v63 = v61[14];
        if ( !v63 )
          v63 = *v61;
        printk(&unk_22D82, v63, "aw_dev_set_vcalb");
        v8 = v62;
        if ( (v62 & 0x80000000) == 0 )
          goto LABEL_14;
      }
      else
      {
        v52 = *(__int64 **)(a1 + 112);
        v53 = v52[14];
        if ( !v53 )
          v53 = *v52;
        printk(&unk_28977, v53, "aw_dev_set_vcalb");
        v8 = -22;
      }
    }
  }
  v64 = *(__int64 **)(a1 + 112);
  v65 = v8;
  v66 = v64[14];
  if ( !v66 )
    v66 = *v64;
  printk(&unk_24F76, v66, "aw_dev_reg_fw_update");
  result = v65;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
