__int64 __fastcall dp_peer_get_rxtid_stats_ipa(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x24
  __int64 v16; // x25
  unsigned int v17; // w23
  __int64 v18; // x27
  int v19; // w8
  int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // [xsp+0h] [xbp-30h] BYREF
  __int64 v31; // [xsp+8h] [xbp-28h]
  __int64 v32; // [xsp+10h] [xbp-20h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  __int64 v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v4 = *(unsigned __int16 *)(a1 + 16);
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL);
    v30 = 0;
    v6 = *(_QWORD *)(v5 + 8);
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    qdf_mem_set(&v30, 0x28u, 0);
    v15 = 0;
    v16 = 0;
    v17 = 0;
    do
    {
      if ( (unsigned int)v16 < 8 || (_DWORD)v16 == 16 )
      {
        v18 = *(_QWORD *)(a1 + 88) + v15;
        if ( *(_QWORD *)(v18 + 32) )
        {
          LOBYTE(v30) = 1;
          HIDWORD(v30) = *(_QWORD *)(v18 + 56);
          v19 = *(_DWORD *)(v18 + 60);
          BYTE4(v31) = 1;
          LOBYTE(v31) = v19;
          if ( !(unsigned int)dp_reo_send_cmd(v6, 0, v7, v8, v9, v10, v11, v12, v13, v14, (__int64)&v30, a2, v4) )
            ++v17;
          qdf_mem_set(&v30, 0x28u, 0);
          LOBYTE(v30) = 0;
          HIDWORD(v30) = *(_QWORD *)(v18 + 56);
          v20 = *(_DWORD *)(v18 + 60);
          HIBYTE(v31) = 1;
          LOBYTE(v31) = v20;
          dp_reo_send_cmd(v6, 2u, v21, v22, v23, v24, v25, v26, v27, v28, (__int64)&v30, 0, 0);
        }
      }
      ++v16;
      v4 += 0x10000;
      v15 += 144;
    }
    while ( v16 != 17 );
  }
  else
  {
    v17 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
