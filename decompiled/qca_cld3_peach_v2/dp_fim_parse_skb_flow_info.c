_QWORD *__fastcall dp_fim_parse_skb_flow_info(_QWORD *result, _DWORD *a2)
{
  int v2; // w8
  __int64 v3; // x11
  int v4; // w8
  unsigned int v5; // w10
  unsigned int v6; // w9
  int v7; // w9
  _QWORD *v8; // x8
  __int64 v9; // x10
  unsigned __int8 *v10; // x9
  __int64 v11; // x10
  int v12; // w9
  unsigned __int16 *v13; // x8
  _DWORD *v14; // x19
  unsigned __int16 *v15; // x11
  unsigned int v16; // w12
  char v17; // [xsp+8h] [xbp-38h]
  __int16 v18; // [xsp+Ah] [xbp-36h]
  __int64 v19; // [xsp+10h] [xbp-30h] BYREF
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h] BYREF
  __int64 v22; // [xsp+28h] [xbp-18h]
  int v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((unsigned __int16 *)result + 90);
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( v2 != 56710 )
  {
    if ( v2 != 8 )
      goto LABEL_23;
    v3 = result[28];
    v4 = *(unsigned __int8 *)(v3 + 23);
    v5 = *(_DWORD *)(v3 + 26);
    v6 = *(_DWORD *)(v3 + 30);
    if ( v4 != 17 && v4 != 6 )
      goto LABEL_23;
    if ( (*(_WORD *)(v3 + 20) & 0xFF1F) != 0 )
    {
      v7 = 128;
LABEL_22:
      a2[10] |= v7;
      goto LABEL_23;
    }
    v15 = (unsigned __int16 *)(v3 + 14 + 4LL * (*(_BYTE *)(v3 + 14) & 0xF));
    v16 = *v15;
    LODWORD(v15) = v15[1];
    *a2 = bswap32(v5);
    a2[4] = bswap32(v6);
    v7 = 31;
    *((_WORD *)a2 + 16) = bswap32(v16) >> 16;
    *((_WORD *)a2 + 17) = bswap32((unsigned int)v15) >> 16;
LABEL_21:
    *((_BYTE *)a2 + 36) = v4;
    goto LABEL_22;
  }
  v8 = (_QWORD *)(result[27] + *((unsigned __int16 *)result + 92));
  v9 = v8[2];
  v19 = v8[1];
  v20 = v9;
  v11 = v8[4];
  v21 = v8[3];
  v22 = v11;
  v10 = (unsigned __int8 *)v8 + 6;
  for ( LOBYTE(v11) = 40; ; LOBYTE(v11) = v11 + 8 * v10[1] + 8 )
  {
    v12 = *v10;
    if ( v12 <= 42 )
      break;
    if ( v12 != 60 && v12 != 43 )
      goto LABEL_23;
LABEL_9:
    v10 = (unsigned __int8 *)v8 + (unsigned __int8)v11;
  }
  switch ( v12 )
  {
    case 0:
      goto LABEL_9;
    case 6:
      v11 = (unsigned __int8)v11;
      if ( (unsigned __int64)(unsigned __int8)v11 + 20 > *((unsigned int *)result + 28) )
        break;
      goto LABEL_19;
    case 17:
      v11 = (unsigned __int8)v11;
      if ( (unsigned __int64)(unsigned __int8)v11 + 8 <= *((unsigned int *)result + 28) )
      {
LABEL_19:
        v13 = (unsigned __int16 *)((char *)v8 + v11);
        v14 = a2;
        v18 = bswap32(*v13) >> 16;
        LODWORD(v13) = v13[1];
        *((_WORD *)a2 + 16) = v18;
        v17 = v12;
        *((_WORD *)a2 + 17) = bswap32((unsigned int)v13) >> 16;
        qdf_mem_copy(a2, &v19, 0x10u);
        result = qdf_mem_copy(v14 + 4, &v21, 0x10u);
        LOBYTE(v4) = v17;
        a2 = v14;
        v7 = 103;
        goto LABEL_21;
      }
      break;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
