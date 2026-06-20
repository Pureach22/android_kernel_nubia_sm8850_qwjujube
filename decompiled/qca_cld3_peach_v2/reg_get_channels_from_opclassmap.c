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
  unsigned int chwidth_from_bw; // w0
  unsigned int v17; // w8
  unsigned int v18; // w24
  bool v19; // cf
  __int64 v20; // x1
  __int64 v21; // x4
  char v22; // w8
  char v23; // w8
  unsigned int v24; // w28
  unsigned int v25; // w19
  unsigned __int64 v26; // x24
  unsigned __int8 *v27; // x27
  char v28; // w8
  int v29; // w20
  int v30; // w8
  int v31; // w9
  __int64 v32; // x11
  __int64 v33; // x12
  __int16 v34; // w9
  char v35; // w10
  __int64 v36; // x26
  __int16 v37; // w10
  __int16 v38; // w11
  __int16 v39; // w9
  unsigned int v40; // w22
  unsigned int v41; // w23
  unsigned int v42; // w0
  unsigned int v43; // w9
  bool v44; // cf
  unsigned int v45; // w23
  __int64 v46; // x1
  unsigned int v47; // w23
  _DWORD *v48; // x8
  _BOOL4 v49; // w8
  char v50; // w8
  unsigned int v52; // [xsp+20h] [xbp-60h]
  int v53; // [xsp+2Ch] [xbp-54h]
  unsigned int v54; // [xsp+2Ch] [xbp-54h]
  unsigned int v55; // [xsp+30h] [xbp-50h]
  int v56; // [xsp+30h] [xbp-50h]
  __int64 v58; // [xsp+38h] [xbp-48h]
  __int64 v59; // [xsp+40h] [xbp-40h] BYREF
  __int64 v60; // [xsp+48h] [xbp-38h]
  __int64 v61; // [xsp+50h] [xbp-30h]
  __int64 v62; // [xsp+58h] [xbp-28h]
  __int64 v63; // [xsp+60h] [xbp-20h]
  __int64 v64; // [xsp+68h] [xbp-18h]
  int v65; // [xsp+70h] [xbp-10h]
  __int64 v66; // [xsp+78h] [xbp-8h]

  v8 = a2 + 156LL * a3;
  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = result;
  if ( (unsigned int)*a4 - 131 > 6 )
  {
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = a4 + 16;
    v54 = a6 & 0xFFFFFFFD;
    v56 = *((_DWORD *)a4 + 3);
    while ( 1 )
    {
      LOWORD(v29) = v27[v26];
      if ( !v27[v26] )
        goto LABEL_64;
      v30 = *((unsigned __int16 *)a4 + 1);
      if ( v30 == 320 )
      {
        if ( v26 > 0x36 )
          goto LABEL_67;
        v36 = 16;
        v39 = v27[v26 + 1]
            + (_WORD)v29
            + v27[v26 + 2]
            + v27[v26 + 3]
            + v27[v26 + 4]
            + v27[v26 + 5]
            + v27[v26 + 6]
            + v27[v26 + 7]
            + v27[v26 + 8]
            + v27[v26 + 9]
            + v27[v26 + 10];
        LOWORD(v29) = v27[v26 + 13];
        v35 = 4;
        v33 = 15;
        v34 = v39 + v27[v26 + 11] + v27[v26 + 12];
        v32 = 14;
      }
      else if ( v30 == 160 )
      {
        if ( v26 > 0x3E )
          goto LABEL_67;
        v36 = 8;
        v37 = v27[v26 + 1] + (_WORD)v29;
        LOWORD(v29) = v27[v26 + 5];
        v38 = v37 + v27[v26 + 2] + v27[v26 + 3];
        v35 = 3;
        v33 = 7;
        v34 = v38 + v27[v26 + 4];
        v32 = 6;
      }
      else
      {
        if ( v30 != 80 || (v31 = *((unsigned __int16 *)a4 + 4), v31 != 8) && v31 != 1 )
        {
          v36 = 1;
          goto LABEL_42;
        }
        if ( v26 > 0x42 )
          goto LABEL_67;
        v32 = 2;
        v33 = 3;
        v34 = v27[v26 + 1];
        v35 = 2;
        v36 = 4;
      }
      v29 = (unsigned __int16)(v34 + v29 + v27[v32 + v26] + v27[v33 + v26]) >> v35;
LABEL_42:
      v40 = 5 * (unsigned __int8)v29 + v56;
      v41 = (20 * (*((unsigned __int16 *)a4 + 1) / 0x14u)) & 0xFFFC;
      v42 = ((__int64 (*)(void))reg_find_chwidth_from_bw)();
      v43 = v40 - 10;
      if ( v40 <= 9 )
        v43 = 0;
      v44 = *a4 == 132 || v41 >= 0x29;
      v45 = v42;
      if ( v44 )
        v46 = v43;
      else
        v46 = v40;
      if ( *((_WORD *)a4 + 1) == 80 && *((_WORD *)a4 + 4) == 8 )
      {
        result = *(_QWORD *)(v58 + 80);
        if ( !result )
          goto LABEL_62;
        v47 = v46;
        result = reg_get_psoc_tx_ops(result);
        if ( !result )
          goto LABEL_62;
        v48 = *(_DWORD **)(result + 224);
        if ( !v48 )
          goto LABEL_62;
        if ( *(v48 - 1) != -1949648479 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD))v48)(v58, v47);
        if ( (result & 1) == 0 )
          goto LABEL_62;
        v49 = 1;
      }
      else
      {
        v65 = 0;
        v63 = 0;
        v64 = 0;
        v61 = 0;
        v62 = 0;
        v59 = 0;
        v60 = 0;
        result = reg_fill_channel_list_for_pwrmode(v58, v46, 0, v42, 0, &v59, a7, 1);
        v49 = HIDWORD(v59) == v45;
      }
      if ( v54 == 1 && v49 )
      {
        if ( v25 > 0x45 )
          goto LABEL_67;
        v28 = *(_BYTE *)(v8 + 11) + 1;
        *(_BYTE *)(v8 + 13 + v25++) = v29;
        *(_BYTE *)(v8 + 11) = v28;
        goto LABEL_27;
      }
LABEL_62:
      if ( v24 > 0x45 )
LABEL_67:
        __break(0x5512u);
      v50 = *(_BYTE *)(v8 + 12);
      *(_BYTE *)(v8 + 83 + v24++) = v29;
      *(_BYTE *)(v8 + 12) = v50 + 1;
LABEL_27:
      v26 += v36;
      if ( v26 >= 0x46 )
        goto LABEL_67;
    }
  }
  v9 = *((unsigned __int8 **)a4 + 11);
  if ( *v9 )
  {
    v10 = *((unsigned __int16 *)a4 + 1);
    v11 = 0;
    v12 = 0;
    v53 = *((_DWORD *)a4 + 3);
    v55 = 0;
    v52 = a6 & 0xFFFFFFFD;
    do
    {
      v13 = *(unsigned __int8 *)(*((_QWORD *)v9 + 1) + v11);
      if ( *((_WORD *)a4 + 1) == 80 && *((_WORD *)a4 + 4) == 8 )
        goto LABEL_22;
      v14 = *a4;
      v15 = 5 * v13 + v53;
      chwidth_from_bw = reg_find_chwidth_from_bw(v10);
      v17 = v15 - 10;
      if ( v15 <= 9 )
        v17 = 0;
      v18 = chwidth_from_bw;
      v19 = v14 == 132 || v10 >= 0x29;
      v20 = v19 ? v17 : v15;
      v21 = chwidth_from_bw == 7 ? v15 : 0LL;
      v65 = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      result = reg_fill_channel_list_for_pwrmode(v58, v20, 0, chwidth_from_bw, v21, &v59, a7, 1);
      if ( v52 != 1 || HIDWORD(v59) != v18 )
      {
LABEL_22:
        if ( v12 > 0x45 )
          goto LABEL_67;
        v23 = *(_BYTE *)(v8 + 12);
        *(_BYTE *)(v8 + 83 + v12++) = v13;
        *(_BYTE *)(v8 + 12) = v23 + 1;
      }
      else
      {
        if ( v55 >= 0x46 )
          goto LABEL_67;
        v22 = *(_BYTE *)(v8 + 11);
        *(_BYTE *)(v8 + 13 + v55) = v13;
        *(_BYTE *)(v8 + 11) = v22 + 1;
        ++v55;
      }
      ++v11;
    }
    while ( v11 < *v9 );
  }
LABEL_64:
  if ( *(_BYTE *)(v8 + 11) )
    *a5 = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
