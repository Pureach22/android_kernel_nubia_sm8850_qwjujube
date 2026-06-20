_QWORD *__fastcall tsens_check_persist_data_feature(_QWORD *result, unsigned int a2, int a3)
{
  __int64 v3; // x20
  _QWORD *v4; // x19
  __int64 v5; // x8
  __int64 v6; // x1
  int v7; // w9
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x1
  int v16; // w9
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x1
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x1
  int v25; // w9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x1
  __int64 v30; // x9
  __int64 v31; // x10
  __int64 v32; // x8
  __int64 v33; // x1
  int v34; // w9
  __int64 v35; // x10
  __int64 v36; // x8
  __int64 v37; // [xsp+0h] [xbp-20h] BYREF
  __int64 v38; // [xsp+8h] [xbp-18h]
  int v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 3 )
  {
    if ( a3 )
    {
      v3 = *result;
      v4 = result;
      *(_BYTE *)(result[318] + 12LL) |= 1u;
      v5 = result[319];
      v6 = result[2];
      v7 = *(_DWORD *)(v5 + 6096);
      v8 = *(_QWORD *)(v5 + 6088);
      v9 = *(_QWORD *)(v5 + 6080);
      v39 = v7;
      v37 = v9;
      v38 = v8;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v6, &v37);
      v4[310] = result;
      if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      v10 = v4[319];
      v11 = v4[2];
      v12 = *(_QWORD *)(v10 + 6100);
      v13 = *(_QWORD *)(v10 + 6108);
      v39 = *(_DWORD *)(v10 + 6116);
      v37 = v12;
      v38 = v13;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v11, &v37);
      v4[311] = result;
      if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      v14 = v4[319];
      v15 = v4[2];
      v16 = *(_DWORD *)(v14 + 6136);
      v17 = *(_QWORD *)(v14 + 6128);
      v18 = *(_QWORD *)(v14 + 6120);
      v39 = v16;
      v37 = v18;
      v38 = v17;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v15, &v37);
      v4[312] = result;
      if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      v19 = v4[319];
      v20 = v4[2];
      v21 = *(_QWORD *)(v19 + 6140);
      v22 = *(_QWORD *)(v19 + 6148);
      v39 = *(_DWORD *)(v19 + 6156);
      v37 = v21;
      v38 = v22;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v20, &v37);
      v4[313] = result;
      if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      v23 = v4[319];
      v24 = v4[2];
      v25 = *(_DWORD *)(v23 + 6176);
      v26 = *(_QWORD *)(v23 + 6168);
      v27 = *(_QWORD *)(v23 + 6160);
      v39 = v25;
      v37 = v27;
      v38 = v26;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v24, &v37);
      v4[314] = result;
      if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      v28 = v4[319];
      v29 = v4[2];
      v30 = *(_QWORD *)(v28 + 6180);
      v31 = *(_QWORD *)(v28 + 6188);
      v39 = *(_DWORD *)(v28 + 6196);
      v37 = v30;
      v38 = v31;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v29, &v37);
      v4[315] = result;
      if ( (unsigned __int64)result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_10;
      v32 = v4[319];
      v33 = v4[2];
      v34 = *(_DWORD *)(v32 + 6216);
      v35 = *(_QWORD *)(v32 + 6208);
      v36 = *(_QWORD *)(v32 + 6200);
      v39 = v34;
      v37 = v36;
      v38 = v35;
      result = (_QWORD *)devm_regmap_field_alloc(v3, v33, &v37);
      v4[316] = result;
      if ( (unsigned __int64)result >= 0xFFFFFFFFFFFFF001LL )
LABEL_10:
        *(_BYTE *)(v4[318] + 12LL) &= ~1u;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
