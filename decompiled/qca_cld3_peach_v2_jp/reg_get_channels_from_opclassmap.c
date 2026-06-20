__int64 __fastcall reg_get_channels_from_opclassmap(
        __int64 result,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 *a4,
        _BYTE *a5,
        int a6,
        unsigned int a7)
{
  __int64 v8; // x25
  unsigned __int8 *v9; // x19
  unsigned int v10; // w23
  unsigned __int64 v11; // x20
  unsigned int v12; // w27
  int v13; // w26
  int v14; // w22
  unsigned int v15; // w28
  int chwidth_from_bw; // w0
  unsigned int v17; // w8
  int v18; // w24
  bool v19; // cf
  __int64 v20; // x1
  char v21; // w8
  char v22; // w8
  unsigned int v23; // w28
  unsigned int v24; // w19
  unsigned __int64 v25; // x24
  unsigned __int8 *v26; // x27
  char v27; // w8
  unsigned int v28; // w20
  int v29; // w8
  int v30; // w9
  __int64 v31; // x11
  __int64 v32; // x12
  unsigned int v33; // w9
  char v34; // w10
  __int64 v35; // x26
  unsigned int v36; // w10
  unsigned int v37; // w11
  unsigned int v38; // w22
  unsigned int v39; // w23
  int v40; // w0
  unsigned int v41; // w9
  bool v42; // cf
  int v43; // w23
  __int64 v44; // x1
  unsigned int v45; // w23
  _DWORD *v46; // x8
  _BOOL4 v47; // w8
  char v48; // w8
  unsigned int v50; // [xsp+18h] [xbp-38h]
  int v51; // [xsp+24h] [xbp-2Ch]
  unsigned int v52; // [xsp+24h] [xbp-2Ch]
  unsigned int v53; // [xsp+28h] [xbp-28h]
  int v54; // [xsp+28h] [xbp-28h]
  __int64 v56; // [xsp+30h] [xbp-20h]
  int v57; // [xsp+38h] [xbp-18h] BYREF
  __int64 v58; // [xsp+3Ch] [xbp-14h]
  int v59; // [xsp+44h] [xbp-Ch]
  __int64 v60; // [xsp+48h] [xbp-8h]

  v8 = a2 + 156LL * a3;
  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = result;
  if ( (unsigned int)*a4 - 131 > 6 )
  {
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = a4 + 16;
    v52 = a6 & 0xFFFFFFFD;
    v54 = *((_DWORD *)a4 + 3);
    while ( 1 )
    {
      v28 = v26[v25];
      if ( !v26[v25] )
        goto LABEL_58;
      v29 = *((unsigned __int16 *)a4 + 1);
      if ( v29 == 160 )
      {
        if ( v25 > 0x3E )
          goto LABEL_61;
        v35 = 8;
        v36 = v26[v25 + 1] + v28;
        v28 = v26[v25 + 5];
        v37 = v36 + v26[v25 + 2] + v26[v25 + 3];
        v34 = 3;
        v32 = 7;
        v33 = v37 + v26[v25 + 4];
        v31 = 6;
      }
      else
      {
        if ( v29 != 80 || (v30 = *((unsigned __int16 *)a4 + 4), v30 != 8) && v30 != 1 )
        {
          v35 = 1;
          goto LABEL_36;
        }
        if ( v25 > 0x42 )
          goto LABEL_61;
        v31 = 2;
        v32 = 3;
        v33 = v26[v25 + 1];
        v34 = 2;
        v35 = 4;
      }
      v28 = (v33 + v28 + v26[v31 + v25] + v26[v32 + v25]) >> v34;
LABEL_36:
      v38 = 5 * (unsigned __int8)v28 + v54;
      v39 = (20 * (*((unsigned __int16 *)a4 + 1) / 0x14u)) & 0xFFFC;
      v40 = ((__int64 (*)(void))reg_find_chwidth_from_bw)();
      v41 = v38 - 10;
      if ( v38 <= 9 )
        v41 = 0;
      v42 = *a4 == 132 || v39 >= 0x29;
      v43 = v40;
      if ( v42 )
        v44 = v41;
      else
        v44 = v38;
      if ( *((_WORD *)a4 + 1) == 80 && *((_WORD *)a4 + 4) == 8 )
      {
        result = *(_QWORD *)(v56 + 80);
        if ( !result )
          goto LABEL_56;
        v45 = v44;
        result = reg_get_psoc_tx_ops(result);
        if ( !result )
          goto LABEL_56;
        v46 = *(_DWORD **)(result + 224);
        if ( !v46 )
          goto LABEL_56;
        if ( *(v46 - 1) != -1949648479 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD))v46)(v56, v45);
        if ( (result & 1) == 0 )
          goto LABEL_56;
        v47 = 1;
      }
      else
      {
        v59 = 0;
        v58 = 0;
        v57 = v40;
        result = reg_set_channel_params_for_pwrmode(v56, v44, 0, &v57, a7, 1);
        v47 = v57 == v43;
      }
      if ( v52 == 1 && v47 )
      {
        if ( v24 > 0x45 )
          goto LABEL_61;
        v27 = *(_BYTE *)(v8 + 11) + 1;
        *(_BYTE *)(v8 + 13 + v24++) = v28;
        *(_BYTE *)(v8 + 11) = v27;
        goto LABEL_24;
      }
LABEL_56:
      if ( v23 > 0x45 )
LABEL_61:
        __break(0x5512u);
      v48 = *(_BYTE *)(v8 + 12);
      *(_BYTE *)(v8 + 83 + v23++) = v28;
      *(_BYTE *)(v8 + 12) = v48 + 1;
LABEL_24:
      v25 += v35;
      if ( v25 >= 0x46 )
        goto LABEL_61;
    }
  }
  v9 = *((unsigned __int8 **)a4 + 11);
  if ( *v9 )
  {
    v10 = *((unsigned __int16 *)a4 + 1);
    v11 = 0;
    v12 = 0;
    v51 = *((_DWORD *)a4 + 3);
    v53 = 0;
    v50 = a6 & 0xFFFFFFFD;
    do
    {
      v13 = *(unsigned __int8 *)(*((_QWORD *)v9 + 1) + v11);
      if ( *((_WORD *)a4 + 1) == 80 && *((_WORD *)a4 + 4) == 8 )
        goto LABEL_19;
      v14 = *a4;
      v15 = 5 * v13 + v51;
      chwidth_from_bw = reg_find_chwidth_from_bw(v10);
      v17 = v15 - 10;
      if ( v15 <= 9 )
        v17 = 0;
      v18 = chwidth_from_bw;
      v19 = v14 == 132 || v10 >= 0x29;
      v57 = chwidth_from_bw;
      v20 = v19 ? v17 : v15;
      v59 = 0;
      v58 = 0;
      result = reg_set_channel_params_for_pwrmode(v56, v20, 0, &v57, a7, 1);
      if ( v50 != 1 || v57 != v18 )
      {
LABEL_19:
        if ( v12 > 0x45 )
          goto LABEL_61;
        v22 = *(_BYTE *)(v8 + 12);
        *(_BYTE *)(v8 + 83 + v12++) = v13;
        *(_BYTE *)(v8 + 12) = v22 + 1;
      }
      else
      {
        if ( v53 >= 0x46 )
          goto LABEL_61;
        v21 = *(_BYTE *)(v8 + 11);
        *(_BYTE *)(v8 + 13 + v53) = v13;
        *(_BYTE *)(v8 + 11) = v21 + 1;
        ++v53;
      }
      ++v11;
    }
    while ( v11 < *v9 );
  }
LABEL_58:
  if ( *(_BYTE *)(v8 + 11) )
    *a5 = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
