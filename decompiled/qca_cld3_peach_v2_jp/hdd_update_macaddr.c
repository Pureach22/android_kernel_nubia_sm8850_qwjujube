__int64 __fastcall hdd_update_macaddr(_DWORD *a1, __int64 a2, char a3)
{
  unsigned __int8 *v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 result; // x0
  __int64 v18; // x24
  unsigned int v19; // w23
  __int64 v20; // x26
  unsigned __int8 *v21; // x21
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w8
  unsigned int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int8 v34; // w8
  int v35; // w10
  __int64 v36; // x5
  __int64 v37; // [xsp+0h] [xbp-20h]
  __int64 v38; // [xsp+8h] [xbp-18h]
  __int64 v39; // [xsp+10h] [xbp-10h] BYREF
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v39) = a2;
  WORD2(v39) = WORD2(a2);
  if ( (a3 & 1) != 0 )
  {
    v4 = (unsigned __int8 *)a1 + 3787;
    qdf_mem_copy((char *)a1 + 3787, &v39, 6u);
    v13 = "%s: hdd_ctx->derived_mac_addr[0]: %02x:%02x:%02x:**:**:%02x";
    v14 = 3789;
    v15 = 947;
    ++a1[957];
    v16 = 948;
  }
  else
  {
    v4 = (unsigned __int8 *)a1 + 3751;
    qdf_mem_copy((char *)a1 + 3751, &v39, 6u);
    v13 = "%s: hdd_ctx->provisioned_mac_addr[0]: %02x:%02x:%02x:**:**:%02x";
    v14 = 3753;
    v15 = 938;
    ++a1[956];
    v16 = 939;
  }
  result = qdf_trace_msg(
             0x33u,
             8u,
             v13,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "hdd_update_macaddr",
             *v4,
             LOBYTE(a1[v15]),
             *((unsigned __int8 *)a1 + v14),
             LOBYTE(a1[v16]));
  v18 = *((unsigned __int8 *)a1 + 3828);
  v19 = (char)v18;
  if ( 6 - a1[956] > (unsigned int)(char)v18 )
  {
    if ( (unsigned int)v18 <= 6 )
      v20 = 6;
    else
      v20 = *((unsigned __int8 *)a1 + 3828);
    v21 = (unsigned __int8 *)a1 + 6 * *((unsigned __int8 *)a1 + 3828) + 3787;
    do
    {
      if ( v20 == v18 )
        __break(0x5512u);
      qdf_mem_copy(v21, &v39, 6u);
      v34 = v21[3];
      v35 = *v21;
      v36 = v35 | 2u;
      *v21 = v35 | 2;
      v21[3] = (((v18 + (v34 >> 4)) & 7) + v34) ^ 0x80;
      if ( v21 )
      {
        v22 = v21[1];
        v23 = v21[2];
        v24 = v21[5];
      }
      else
      {
        v23 = 0;
        v36 = 0;
        v22 = 0;
        v24 = 0;
      }
      LODWORD(v37) = v24;
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: hdd_ctx->derived_mac_addr[%d]: %02x:%02x:%02x:**:**:%02x",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 "hdd_update_macaddr",
                 v19,
                 v36,
                 v22,
                 v23,
                 v37,
                 v38,
                 v39,
                 v40);
      ++v18;
      v21 += 6;
      v19 = v18;
      v25 = 6 - a1[956];
      ++a1[957];
    }
    while ( v25 > (unsigned int)v18 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
