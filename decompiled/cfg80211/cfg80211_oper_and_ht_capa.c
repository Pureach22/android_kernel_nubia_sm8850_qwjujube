_BYTE *__fastcall cfg80211_oper_and_ht_capa(_BYTE *result, _BYTE *a2)
{
  char v2; // w9
  char v3; // w8
  char v4; // w9
  char v5; // w8
  char v6; // w9
  char v7; // w8
  char v8; // w9
  char v9; // w8
  char v10; // w9
  char v11; // w8
  char v12; // w9
  char v13; // w8
  char v14; // w9
  char v15; // w8
  char v16; // w9
  char v17; // w8
  char v18; // w9
  char v19; // w8
  char v20; // w9
  char v21; // w8
  char v22; // w9
  char v23; // w8
  char v24; // w9
  char v25; // w8
  char v26; // w9
  char v27; // w8
  char v28; // w9
  char v29; // w8
  char v30; // w9
  char v31; // w8
  char v32; // w9
  char v33; // w8
  char v34; // w9
  char v35; // w8
  char v36; // w9
  char v37; // w8
  char v38; // w9
  char v39; // w8
  char v40; // w9
  char v41; // w8
  char v42; // w9
  char v43; // w8
  char v44; // w9
  char v45; // w8
  char v46; // w9
  char v47; // w8
  char v48; // w9
  char v49; // w8
  char v50; // w9

  if ( a2 )
  {
    v2 = result[1];
    *result &= *a2;
    v3 = v2 & a2[1];
    v4 = result[2];
    result[1] = v3;
    v5 = v4 & a2[2];
    v6 = result[3];
    result[2] = v5;
    v7 = v6 & a2[3];
    v8 = result[4];
    result[3] = v7;
    v9 = v8 & a2[4];
    v10 = result[5];
    result[4] = v9;
    v11 = v10 & a2[5];
    v12 = result[6];
    result[5] = v11;
    v13 = v12 & a2[6];
    v14 = result[7];
    result[6] = v13;
    v15 = v14 & a2[7];
    v16 = result[8];
    result[7] = v15;
    v17 = v16 & a2[8];
    v18 = result[9];
    result[8] = v17;
    v19 = v18 & a2[9];
    v20 = result[10];
    result[9] = v19;
    v21 = v20 & a2[10];
    v22 = result[11];
    result[10] = v21;
    v23 = v22 & a2[11];
    v24 = result[12];
    result[11] = v23;
    v25 = v24 & a2[12];
    v26 = result[13];
    result[12] = v25;
    v27 = v26 & a2[13];
    v28 = result[14];
    result[13] = v27;
    v29 = v28 & a2[14];
    v30 = result[15];
    result[14] = v29;
    v31 = v30 & a2[15];
    v32 = result[16];
    result[15] = v31;
    v33 = v32 & a2[16];
    v34 = result[17];
    result[16] = v33;
    v35 = v34 & a2[17];
    v36 = result[18];
    result[17] = v35;
    v37 = v36 & a2[18];
    v38 = result[19];
    result[18] = v37;
    v39 = v38 & a2[19];
    v40 = result[20];
    result[19] = v39;
    v41 = v40 & a2[20];
    v42 = result[21];
    result[20] = v41;
    v43 = v42 & a2[21];
    v44 = result[22];
    result[21] = v43;
    v45 = v44 & a2[22];
    v46 = result[23];
    result[22] = v45;
    v47 = v46 & a2[23];
    v48 = result[24];
    result[23] = v47;
    v49 = v48 & a2[24];
    v50 = result[25];
    result[24] = v49;
    result[25] = v50 & a2[25];
  }
  else
  {
    *((_WORD *)result + 12) = 0;
    *((_QWORD *)result + 1) = 0;
    *((_QWORD *)result + 2) = 0;
    *(_QWORD *)result = 0;
  }
  return result;
}
