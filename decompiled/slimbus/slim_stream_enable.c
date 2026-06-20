__int64 __fastcall slim_stream_enable(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w0
  unsigned int v5; // w19
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x22
  int v9; // w10
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w11
  int v13; // w10
  __int64 v14; // x9
  int v15; // kr00_4
  _DWORD *v16; // x11
  __int64 v17; // x25
  int v18; // w13
  int v19; // w11
  unsigned int v20; // w12
  char v21; // w9
  __int64 v22; // x8
  int v23; // w10
  char v24; // w9
  int v25; // w9
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x21
  __int64 v29; // x22
  __int64 v30; // x8
  char v31; // w9
  __int64 v32; // x9
  __int64 v33; // x20
  _QWORD *v34; // [xsp+8h] [xbp-68h]
  _QWORD v35[3]; // [xsp+10h] [xbp-60h] BYREF
  int v36; // [xsp+28h] [xbp-48h] BYREF
  __int16 v37; // [xsp+2Ch] [xbp-44h]
  char v38; // [xsp+2Eh] [xbp-42h]
  char v39; // [xsp+2Fh] [xbp-41h]
  __int128 *v40; // [xsp+30h] [xbp-40h]
  __int64 v41; // [xsp+38h] [xbp-38h]
  __int128 v42; // [xsp+40h] [xbp-30h] BYREF
  int *v43; // [xsp+50h] [xbp-20h]
  __int64 v44; // [xsp+58h] [xbp-18h]
  int v45; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+68h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = 0xFF00000003400003LL;
  v35[1] = 0;
  v35[2] = 0;
  if ( !a1 )
  {
    printk(&unk_87EB, "slim_stream_enable");
    result = 4294967274LL;
    goto LABEL_52;
  }
  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 8) + 920LL);
  if ( v2[36] )
  {
    mutex_lock(v2 + 39);
    v3 = (__int64 (__fastcall *)(_QWORD))v2[36];
    if ( *((_DWORD *)v3 - 1) != 843195780 )
      __break(0x8228u);
    v4 = v3(a1);
    if ( v4 )
    {
      v5 = v4;
      mutex_unlock(v2 + 39);
      result = v5;
    }
    else
    {
      if ( *(int *)(a1 + 36) >= 1 )
      {
        v26 = 0;
        v27 = 32;
        do
        {
          ++v26;
          *(_DWORD *)(*(_QWORD *)(a1 + 40) + v27) = 5;
          v27 += 36;
        }
        while ( v26 < *(int *)(a1 + 36) );
      }
      mutex_unlock(v2 + 39);
      result = 0;
    }
    goto LABEL_52;
  }
  result = slim_do_transfer(*(_QWORD **)(*(_QWORD *)(a1 + 8) + 920LL), (unsigned __int8 *)v35);
  if ( (_DWORD)result )
    goto LABEL_52;
  v34 = v2;
  if ( *(int *)(a1 + 36) < 1 )
    goto LABEL_50;
  v7 = 0;
  v8 = 0;
  do
  {
    v11 = *(_QWORD *)(a1 + 8);
    v12 = *(_DWORD *)(a1 + 32);
    v13 = -22;
    v42 = 0x40000u;
    v36 = 5242888;
    v39 = *(_BYTE *)(v11 + 932);
    v14 = *(_QWORD *)(a1 + 40);
    *(_QWORD *)((char *)&v42 + 3) = 0;
    v43 = &v45;
    v44 = 0;
    v37 = 0;
    v38 = 0;
    v40 = &v42;
    v41 = 0;
    if ( v12 > 191 )
    {
      if ( v12 <= 363 )
      {
        if ( v12 == 192 )
        {
          v16 = &unk_8CC8;
        }
        else
        {
          if ( v12 != 256 )
            goto LABEL_38;
          v16 = &unk_8C48;
        }
      }
      else
      {
        switch ( v12 )
        {
          case 364:
            v16 = &unk_8CD8;
            break;
          case 512:
            v16 = &unk_8C58;
            break;
          case 768:
            v16 = &unk_8CE8;
            break;
          default:
            goto LABEL_38;
        }
      }
LABEL_37:
      v13 = v16[2];
    }
    else
    {
      v15 = v12 - 1;
      v16 = &segdist_codes;
      switch ( v15 )
      {
        case 0:
          goto LABEL_37;
        case 1:
          v16 = &unk_8BD8;
          goto LABEL_37;
        case 2:
          v16 = &unk_8C68;
          goto LABEL_37;
        case 3:
          v16 = &unk_8BE8;
          goto LABEL_37;
        case 5:
          v16 = &unk_8C78;
          goto LABEL_37;
        case 7:
          v16 = &unk_8BF8;
          goto LABEL_37;
        case 11:
          v16 = &unk_8C88;
          goto LABEL_37;
        case 15:
          v16 = &unk_8C08;
          goto LABEL_37;
        case 23:
          v16 = &unk_8C98;
          goto LABEL_37;
        case 31:
          v16 = &unk_8C18;
          goto LABEL_37;
        case 47:
          v16 = &unk_8CA8;
          goto LABEL_37;
        case 63:
          v16 = &unk_8C28;
          goto LABEL_37;
        case 95:
          v16 = &unk_8CB8;
          goto LABEL_37;
        case 127:
          v16 = &unk_8C38;
          goto LABEL_37;
        default:
          break;
      }
    }
LABEL_38:
    v17 = v14 + v7;
    v45 = 0;
    *(_DWORD *)(v14 + v7 + 20) = v13;
    v18 = *(_DWORD *)(v14 + v7 + 12);
    v19 = *(_DWORD *)(a1 + 20);
    v20 = *(_DWORD *)(a1 + 28);
    BYTE1(v45) = v13;
    LOBYTE(v45) = v18;
    BYTE2(v45) = BYTE1(v13) & 0xF | (16 * v19);
    if ( v19 )
      v21 = (v20 >> 2) + 1;
    else
      v21 = v20 >> 2;
    HIBYTE(v45) = v21;
    *(_DWORD *)(v17 + 32) = 3;
    slim_do_transfer(*(_QWORD **)(v11 + 920), (unsigned __int8 *)&v36);
    v22 = *(_QWORD *)(a1 + 8);
    v45 = 0;
    v42 = 0x40000u;
    v23 = *(_DWORD *)(a1 + 20);
    v36 = 5308424;
    v24 = *(_BYTE *)(v22 + 932);
    *(_QWORD *)((char *)&v42 + 3) = 0;
    v43 = &v45;
    v44 = 0;
    v37 = 0;
    v38 = 0;
    v39 = v24;
    v40 = &v42;
    v41 = 0;
    LOBYTE(v45) = *(_DWORD *)(v17 + 12);
    v25 = *(_DWORD *)(v17 + 16);
    *(_WORD *)((char *)&v45 + 1) = (unsigned __int8)v25;
    if ( v23 )
      BYTE1(v45) = v25 | 0x80;
    v9 = *(_DWORD *)(a1 + 28) >> 2;
    BYTE2(v45) = *(_BYTE *)(v17 + 24) | (16 * *(_BYTE *)(v17 + 28));
    HIBYTE(v45) = v9;
    *(_DWORD *)(v17 + 32) = 4;
    slim_do_transfer(*(_QWORD **)(v22 + 920), (unsigned __int8 *)&v36);
    v10 = *(int *)(a1 + 36);
    ++v8;
    v7 += 36;
  }
  while ( v8 < v10 );
  if ( (int)v10 >= 1 )
  {
    v28 = 0;
    v29 = 0;
    do
    {
      v30 = *(_QWORD *)(a1 + 8);
      v42 = 0u;
      v36 = 5505029;
      v31 = *(_BYTE *)(v30 + 932);
      v37 = 0;
      v38 = 0;
      v39 = v31;
      v32 = *(_QWORD *)(a1 + 40);
      v40 = &v42;
      v41 = 0;
      BYTE2(v42) = 1;
      v33 = v32 + v28;
      v43 = &v45;
      v44 = 0;
      LOBYTE(v45) = *(_DWORD *)(v32 + v28 + 12);
      *(_DWORD *)(v32 + v28 + 32) = 5;
      slim_do_transfer(*(_QWORD **)(v30 + 920), (unsigned __int8 *)&v36);
      *(_DWORD *)(v33 + 8) = 2;
      ++v29;
      v28 += 36;
    }
    while ( v29 < *(int *)(a1 + 36) );
  }
LABEL_50:
  BYTE2(v35[0]) = 95;
  result = slim_do_transfer(v34, (unsigned __int8 *)v35);
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
