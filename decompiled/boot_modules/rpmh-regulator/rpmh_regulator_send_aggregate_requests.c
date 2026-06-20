__int64 __fastcall rpmh_regulator_send_aggregate_requests(__int64 a1)
{
  unsigned int v1; // w20
  unsigned int v2; // w21
  _QWORD *v4; // x22
  char v5; // w8
  int v6; // w9
  char v7; // w23
  __int64 v8; // x8
  unsigned int v9; // w10
  __int64 v10; // x1
  __int64 v11; // x24
  unsigned int v12; // w10
  unsigned int v13; // w11
  unsigned int v14; // w13
  unsigned int v15; // w15
  unsigned int v16; // w17
  unsigned int v17; // w25
  unsigned int v18; // w12
  unsigned int v19; // w14
  unsigned int v20; // w16
  unsigned int v21; // w0
  _DWORD *v22; // x2
  int v23; // w1
  bool v24; // cc
  __int64 v25; // x11
  unsigned __int64 v26; // x12
  unsigned int v27; // w3
  int v28; // w26
  __int64 v29; // x16
  _DWORD *v30; // x17
  int v31; // w8
  char v32; // w9
  char *v33; // x8
  char *v34; // x9
  __int64 v35; // x10
  int v36; // w11
  __int64 v37; // x12
  int v38; // w13
  __int64 v39; // x9
  int v40; // w10
  int v41; // w12
  unsigned int v42; // w0
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x10
  unsigned int v45; // w8
  __int64 v46; // x9
  unsigned __int64 v47; // x10
  unsigned int v48; // w0
  __int64 v49; // x16
  _DWORD *v50; // x17
  unsigned int v51; // w0
  __int64 v52; // x0
  __int64 result; // x0
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x9
  unsigned int v56; // w10
  int v57; // w10
  char *v58; // x9
  char v59; // w10
  char *v60; // x10
  __int64 v61; // x11
  int v62; // w12
  __int64 v63; // x13
  int v64; // w14
  unsigned int v65; // w19
  __int64 v66; // x10
  int v67; // w11
  int v68; // w13
  __int64 v69; // x2
  void *v70; // x8
  unsigned int v71; // w19
  __int64 v72; // [xsp+8h] [xbp-78h]
  int v73; // [xsp+10h] [xbp-70h]
  __int64 v74; // [xsp+18h] [xbp-68h] BYREF
  _QWORD v75[2]; // [xsp+20h] [xbp-60h] BYREF
  __int64 v76; // [xsp+30h] [xbp-50h] BYREF
  _QWORD v77[2]; // [xsp+38h] [xbp-48h] BYREF
  unsigned __int64 v78; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int64 v79; // [xsp+50h] [xbp-30h]
  unsigned int v80; // [xsp+58h] [xbp-28h]
  unsigned __int64 v81; // [xsp+60h] [xbp-20h] BYREF
  unsigned __int64 v82; // [xsp+68h] [xbp-18h]
  unsigned int v83; // [xsp+70h] [xbp-10h]
  __int64 v84; // [xsp+78h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD **)(a1 + 336);
  v83 = 0;
  v81 = 0;
  v82 = 0;
  v5 = *((_BYTE *)v4 + 212);
  v6 = *((unsigned __int8 *)v4 + 214);
  v80 = 0;
  v78 = 0;
  v79 = 0;
  v77[0] = 0;
  v77[1] = 0;
  v75[1] = 0;
  v76 = 0;
  v74 = 0;
  v75[0] = 0;
  if ( (v5 & 1) != 0 )
    v7 = 1;
  else
    v7 = *((_BYTE *)v4 + 213);
  v8 = *((unsigned int *)v4 + 18);
  if ( (unsigned int)v8 <= 3 )
    v9 = max_reg_index_map[v8];
  else
    v9 = -22;
  v10 = *((unsigned int *)v4 + 56);
  v11 = v9;
  if ( (int)v10 < 1 )
  {
    v13 = 0;
    v18 = 0;
    v14 = 0;
    v19 = 0;
    v16 = 0;
    v21 = 0;
    v15 = 0;
    v12 = 0;
    v20 = 0;
    v17 = 0;
    if ( (_DWORD)v8 )
      goto LABEL_42;
LABEL_46:
    v23 = *((_DWORD *)v4 + 61);
    if ( v23 >= 1 )
    {
      if ( (v17 & 2) != 0 && !v20 )
      {
        v19 = *((_DWORD *)v4 + 61);
        LODWORD(v82) = v19;
      }
      if ( (v12 & 2) != 0 && !v15 )
      {
        v14 = v23;
        LODWORD(v79) = v23;
      }
    }
LABEL_53:
    v24 = (int)v11 < 1;
    if ( (v6 & 1) == 0 )
      goto LABEL_66;
LABEL_54:
    if ( v24 )
      goto LABEL_125;
    goto LABEL_69;
  }
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v22 = (_DWORD *)(v4[27] + 364LL);
  do
  {
    if ( *((_BYTE *)v22 - 20) == 1 )
    {
      if ( (int)v11 >= 1 )
      {
        if ( v21 <= *(v22 - 4) )
          v21 = *(v22 - 4);
        if ( (_DWORD)v11 != 1 )
        {
          if ( v20 <= *(v22 - 3) )
            v20 = *(v22 - 3);
          if ( (_DWORD)v11 != 2 )
          {
            if ( v19 <= *(v22 - 2) )
              v19 = *(v22 - 2);
            if ( (_DWORD)v11 != 3 )
            {
              if ( v18 <= *(v22 - 1) )
                v18 = *(v22 - 1);
              if ( (_DWORD)v11 != 4 )
                goto LABEL_116;
            }
          }
        }
      }
      v17 |= *v22;
    }
    if ( *((_BYTE *)v22 - 19) == 1 )
    {
      if ( (int)v11 >= 1 )
      {
        if ( v16 <= *(v22 - 4) )
          v16 = *(v22 - 4);
        if ( (_DWORD)v11 != 1 )
        {
          if ( v15 <= *(v22 - 3) )
            v15 = *(v22 - 3);
          if ( (_DWORD)v11 != 2 )
          {
            if ( v14 <= *(v22 - 2) )
              v14 = *(v22 - 2);
            if ( (_DWORD)v11 != 3 )
            {
              if ( v13 <= *(v22 - 1) )
                v13 = *(v22 - 1);
              if ( (_DWORD)v11 != 4 )
                goto LABEL_116;
            }
          }
        }
      }
      v12 |= *v22;
    }
    --v10;
    v22 += 94;
  }
  while ( v10 );
  v81 = __PAIR64__(v20, v21);
  v82 = __PAIR64__(v18, v19);
  v83 = v17;
  v78 = __PAIR64__(v15, v16);
  v79 = __PAIR64__(v13, v14);
  v80 = v12;
  if ( !(_DWORD)v8 )
    goto LABEL_46;
LABEL_42:
  if ( (_DWORD)v8 != 1 )
    goto LABEL_53;
  if ( *((_DWORD *)v4 + 20) )
  {
    v17 &= ~2u;
    v83 = v17;
  }
  else
  {
    if ( (v17 & 2) != 0 )
    {
      if ( !v20 )
      {
        v21 = 0;
        LODWORD(v81) = 0;
      }
    }
    else
    {
      v17 &= 0xFFFFFFFC;
    }
    v17 &= ~2u;
    v83 = v17;
    if ( (v12 & 2) != 0 )
    {
      if ( !v15 )
      {
        v16 = 0;
        LODWORD(v78) = 0;
      }
    }
    else
    {
      v12 &= 0xFFFFFFFC;
    }
  }
  v12 &= ~2u;
  v80 = v12;
  v24 = (int)v11 < 1;
  if ( (v6 & 1) != 0 )
    goto LABEL_54;
LABEL_66:
  if ( v24 )
    goto LABEL_125;
  if ( v21 != v16 && (v12 & 1) != 0 )
    goto LABEL_69;
  if ( (_DWORD)v11 == 1 )
  {
LABEL_87:
    v28 = 0;
    LODWORD(v8) = 0;
LABEL_107:
    v46 = 0;
    v47 = 0;
    v1 = 0;
    v2 = 0;
    while ( 1 )
    {
      v49 = 1LL << v47;
      if ( ((1LL << v47) & v17) != 0 )
      {
        if ( ((unsigned int)v49 & (_DWORD)v4[33]) == 0 )
          goto LABEL_160;
        if ( v47 > 3 )
          goto LABEL_116;
        if ( ((*(_DWORD *)((char *)v4 + v46 + 248) == *(_DWORD *)((char *)&v81 + v46)) & ~v28) == 0 )
        {
LABEL_160:
          if ( v2 > 3 )
            goto LABEL_116;
          v50 = (_DWORD *)&v75[-1] + 3 * v2;
          *v50 = v46 + *((_DWORD *)v4 + 4);
          if ( v47 > 3 )
            goto LABEL_116;
          v48 = *(_DWORD *)((char *)&v81 + v46);
          ++v2;
          v1 |= v49;
          v50[1] = v48;
          v50[2] = 1;
          v7 |= v48 > *(_DWORD *)((char *)v4 + v46 + 248);
        }
      }
      ++v47;
      v46 += 4;
      if ( v11 == v47 )
        goto LABEL_117;
    }
  }
  if ( v20 != v15 && (v12 & 2) != 0 )
    goto LABEL_69;
  if ( (_DWORD)v11 == 2 )
    goto LABEL_87;
  if ( v19 != v14 && (v12 & 4) != 0 )
    goto LABEL_69;
  if ( (_DWORD)v11 == 3 )
    goto LABEL_87;
  if ( v18 != v13 && (v12 & 8) != 0 )
  {
LABEL_69:
    v25 = 0;
    v26 = 0;
    v1 = 0;
    v27 = 0;
    v28 = v6 ^ 1;
    do
    {
      v29 = 1LL << v26;
      if ( ((1LL << v26) & v12) != 0 )
      {
        if ( ((unsigned int)v29 & *((_DWORD *)v4 + 71)) == 0 )
          goto LABEL_161;
        if ( v26 > 3 )
          goto LABEL_116;
        if ( *(_DWORD *)((char *)v4 + v25 + 268) != *(_DWORD *)((char *)&v78 + v25) )
        {
LABEL_161:
          if ( v27 > 3 )
            goto LABEL_116;
          v30 = (_DWORD *)&v75[-1] + 3 * v27;
          *v30 = v25 + *((_DWORD *)v4 + 4);
          if ( v26 > 3 )
            goto LABEL_116;
          ++v27;
          v1 |= v29;
          v30[1] = *(_DWORD *)((char *)&v78 + v25);
          v30[2] = 1;
        }
      }
      ++v26;
      v25 += 4;
    }
    while ( v11 != v26 );
    if ( (int)v27 < 1 )
    {
LABEL_105:
      if ( (int)v11 >= 1 )
      {
        LODWORD(v8) = 1;
        goto LABEL_107;
      }
      goto LABEL_125;
    }
    if ( v27 == 1 || (_DWORD)v8 )
      goto LABEL_103;
    v31 = *((_DWORD *)v4 + 4);
    if ( (((_DWORD)v74 - v31) & 0xFFFFFFFC) == 4 )
    {
      v32 = 1;
      v33 = (char *)&v74;
      goto LABEL_83;
    }
    if ( ((HIDWORD(v75[0]) - v31) & 0xFFFFFFFC) == 4 )
    {
      v32 = 0;
      v33 = (char *)v75 + 4;
      goto LABEL_83;
    }
    if ( v27 == 2 )
    {
LABEL_103:
      v42 = rpmh_write_async(*v4, 0, &v74);
      if ( v42 )
      {
        v65 = v42;
        printk(&unk_924B, "rpmh_regulator_send_aggregate_requests", v4[1]);
        result = v65;
        goto LABEL_129;
      }
      rpmh_regulator_req(a1, &v78, (char *)v4 + 268, v1, 0);
      v43 = v78;
      v44 = v79;
      *((_BYTE *)v4 + 214) = 1;
      v45 = v80;
      *(_QWORD *)((char *)v4 + 268) = v43;
      *(_QWORD *)((char *)v4 + 276) = v44;
      *((_DWORD *)v4 + 71) = v45;
      goto LABEL_105;
    }
    if ( (((_DWORD)v76 - v31) & 0xFFFFFFFC) == 4 )
    {
      v32 = 0;
      v33 = (char *)&v76;
      goto LABEL_83;
    }
    if ( v27 == 3 )
      goto LABEL_103;
    if ( ((HIDWORD(v77[0]) - v31) & 0xFFFFFFFC) == 4 )
    {
      v32 = 0;
      v33 = (char *)v77 + 4;
LABEL_83:
      if ( *((_DWORD *)v33 + 1) )
      {
        v34 = (char *)&v75[-2] + 12 * v27 - 4;
        if ( v33 != v34 )
        {
          v36 = *((_DWORD *)v33 + 2);
          v37 = *(_QWORD *)v34;
          v38 = *((_DWORD *)&v75[-1] + 3 * v27 - 1);
          v72 = *(_QWORD *)v33;
          v35 = v72;
          v73 = v36;
          *(_QWORD *)v33 = v37;
          *((_DWORD *)v33 + 2) = v38;
          *(_QWORD *)v34 = v35;
          *((_DWORD *)&v75[-1] + 3 * v27 - 1) = v36;
        }
      }
      else if ( (v32 & 1) == 0 )
      {
        v40 = *((_DWORD *)v33 + 2);
        v41 = v75[0];
        v72 = *(_QWORD *)v33;
        v39 = v72;
        v73 = v40;
        *(_QWORD *)v33 = v74;
        *((_DWORD *)v33 + 2) = v41;
        v74 = v39;
        LODWORD(v75[0]) = v40;
      }
      goto LABEL_103;
    }
    if ( v27 == 4 )
      goto LABEL_103;
LABEL_157:
    __break(1u);
  }
  if ( (_DWORD)v11 == 4 )
    goto LABEL_87;
LABEL_116:
  __break(0x5512u);
LABEL_117:
  if ( (int)v2 >= 1 )
  {
    if ( v2 == 1 || *((_DWORD *)v4 + 18) )
      goto LABEL_120;
    v57 = *((_DWORD *)v4 + 4);
    v58 = (char *)&v74;
    if ( (((_DWORD)v74 - v57) & 0xFFFFFFFC) == 4 )
    {
      v59 = 1;
    }
    else if ( ((HIDWORD(v75[0]) - v57) & 0xFFFFFFFC) == 4 )
    {
      v59 = 0;
      v58 = (char *)v75 + 4;
    }
    else
    {
      if ( v2 == 2 )
        goto LABEL_120;
      if ( (((_DWORD)v76 - v57) & 0xFFFFFFFC) == 4 )
      {
        v59 = 0;
        v58 = (char *)&v76;
      }
      else
      {
        if ( v2 == 3 )
          goto LABEL_120;
        if ( ((HIDWORD(v77[0]) - v57) & 0xFFFFFFFC) != 4 )
        {
          if ( v2 != 4 )
            goto LABEL_157;
LABEL_120:
          if ( (_DWORD)v8 )
          {
            v51 = rpmh_write_async(*v4, 1, &v74);
            if ( v51 )
            {
              v69 = v4[1];
              v70 = &unk_92EB;
              goto LABEL_147;
            }
            rpmh_regulator_req(a1, &v81, v4 + 31, v1, 1);
          }
          v52 = *v4;
          if ( (v7 & 1) != 0 )
            v51 = rpmh_write(v52, 2, &v74, v2);
          else
            v51 = rpmh_write_async(v52, 2, &v74);
          if ( !v51 )
          {
            rpmh_regulator_req(a1, &v81, v4 + 31, v1, 2);
            v54 = v81;
            v55 = v82;
            result = 0;
            v56 = v83;
            *((_BYTE *)v4 + 213) = 0;
            v4[31] = v54;
            v4[32] = v55;
            *((_DWORD *)v4 + 66) = v56;
            goto LABEL_129;
          }
          v69 = v4[1];
          v70 = &unk_960B;
LABEL_147:
          v71 = v51;
          printk(v70, "rpmh_regulator_send_aggregate_requests", v69);
          result = v71;
          goto LABEL_129;
        }
        v59 = 0;
        v58 = (char *)v77 + 4;
      }
    }
    if ( *((_DWORD *)v58 + 1) )
    {
      v60 = (char *)&v75[-2] + 12 * v2 - 4;
      if ( v58 != v60 )
      {
        v62 = *((_DWORD *)v58 + 2);
        v63 = *(_QWORD *)v60;
        v64 = *((_DWORD *)&v75[-1] + 3 * v2 - 1);
        v72 = *(_QWORD *)v58;
        v61 = v72;
        v73 = v62;
        *(_QWORD *)v58 = v63;
        *((_DWORD *)v58 + 2) = v64;
        *(_QWORD *)v60 = v61;
        *((_DWORD *)&v75[-1] + 3 * v2 - 1) = v62;
      }
    }
    else if ( (v59 & 1) == 0 )
    {
      v67 = *((_DWORD *)v58 + 2);
      v68 = v75[0];
      v72 = *(_QWORD *)v58;
      v66 = v72;
      v73 = v67;
      *(_QWORD *)v58 = v74;
      *((_DWORD *)v58 + 2) = v68;
      v74 = v66;
      LODWORD(v75[0]) = v67;
    }
    goto LABEL_120;
  }
LABEL_125:
  result = 0;
LABEL_129:
  _ReadStatusReg(SP_EL0);
  return result;
}
