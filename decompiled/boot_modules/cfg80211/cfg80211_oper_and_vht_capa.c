_BYTE *__fastcall cfg80211_oper_and_vht_capa(_BYTE *result, _BYTE *a2)
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
    result[11] = v22 & a2[11];
  }
  else
  {
    *((_DWORD *)result + 2) = 0;
    *(_QWORD *)result = 0;
  }
  return result;
}
