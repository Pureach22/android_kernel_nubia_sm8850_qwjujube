__int64 __fastcall cdsprm_compute_vtcm_set_partition_map(int a1)
{
  __int64 result; // x0
  __int64 v3; // x19
  int v4; // w22
  __int64 v5; // x8
  unsigned __int64 v6; // x10
  __int64 v7; // x9
  int *v8; // x11
  char *v9; // x13
  char v10; // w12
  int v11; // w14
  __int64 v12; // x8
  __int64 v13; // x9
  char *v14; // x11
  _BYTE *v15; // x12
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w19
  int v19; // [xsp+4h] [xbp-11Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-118h]
  int v21; // [xsp+10h] [xbp-110h]
  _BYTE v22[260]; // [xsp+14h] [xbp-10Ch] BYREF
  __int64 v23; // [xsp+118h] [xbp-8h]

  result = 4294967274LL;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = qword_A350;
  if ( qword_A350 && gcdsprm[0] >= 2u )
  {
    v4 = a1;
    memset(v22, 0, sizeof(v22));
    v21 = v4;
    v20 = 0xD00000002LL;
    v5 = (unsigned __int8)byte_A1AD;
    v22[0] = byte_A1AC;
    v22[1] = byte_A1AD;
    if ( byte_A1AC )
    {
      v6 = 0;
      v7 = 12LL * (unsigned __int8)byte_A1AC;
      while ( v6 != 192 )
      {
        v8 = &gcdsprm[v6 / 4];
        v9 = (char *)&v19 + v6;
        v6 += 12LL;
        v10 = *((_BYTE *)v8 + 2072);
        v11 = v8[519];
        LODWORD(v8) = v8[520];
        v9[20] = v10;
        *((_DWORD *)v9 + 6) = v11;
        *((_DWORD *)v9 + 7) = (_DWORD)v8;
        if ( v7 == v6 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      if ( !(_DWORD)v5 )
      {
LABEL_13:
        v16 = *(_QWORD *)(v3 + 968);
        v19 = 276;
        v17 = rpmsg_send(v16, &v19, 276);
        dword_99A0 = v21;
        if ( v17 )
        {
          v18 = v17;
          printk(&unk_C1CD);
          result = v18;
        }
        else
        {
          printk(&unk_C676);
          result = 0;
        }
        goto LABEL_3;
      }
      v12 = 2 * v5;
      v13 = 0;
      while ( v13 != 64 )
      {
        v14 = (char *)gcdsprm + v13;
        v22[v13 + 196] = *((_BYTE *)&gcdsprm[566] + v13);
        if ( (unsigned __int64)(v13 - 64) < 0xFFFFFFFFFFFFFEEBLL )
          goto LABEL_17;
        v15 = &v22[v13 + 196];
        v13 += 2;
        v15[1] = v14[2265];
        if ( v12 == v13 )
          goto LABEL_13;
      }
    }
    __break(0x5512u);
LABEL_17:
    __break(1u);
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
