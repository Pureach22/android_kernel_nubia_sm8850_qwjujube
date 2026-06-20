__int64 __fastcall crypto_hash_find_by_linkid_and_macaddr(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  int v6; // w22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w8
  __int64 result; // x0
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v6 = a2;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  qdf_mem_copy(v21, a3, 6u);
  v15 = *(_QWORD *)(*(_QWORD *)(a1 + 80)
                  + 16LL
                  * ((((unsigned __int16)(LOWORD(v21[0]) ^ v6 ^ WORD1(v21[0]) ^ WORD2(v21[0])) >> *(_DWORD *)(a1 + 76))
                    ^ (unsigned int)(unsigned __int16)(LOWORD(v21[0]) ^ v6 ^ WORD1(v21[0]) ^ WORD2(v21[0])))
                   & *(_DWORD *)(a1 + 72)));
  if ( v15 )
  {
    while ( *(unsigned __int8 *)(v15 + 9) != v6
         || LODWORD(v21[0]) != *(_DWORD *)v15
         || WORD2(v21[0]) != *(unsigned __int16 *)(v15 + 4) )
    {
      v15 = *(_QWORD *)(v15 + 152);
      if ( !v15 )
        goto LABEL_9;
    }
    if ( a3 )
    {
      v16 = *a3;
      v17 = a3[1];
      v18 = a3[2];
      v19 = a3[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x1Cu,
      8u,
      "%s: crypto found entry link id %d mac addr%02x:%02x:%02x:**:**:%02x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "crypto_hash_find_by_linkid_and_macaddr",
      a2,
      v16,
      v17,
      v18,
      v19);
    result = v15;
  }
  else
  {
LABEL_9:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
