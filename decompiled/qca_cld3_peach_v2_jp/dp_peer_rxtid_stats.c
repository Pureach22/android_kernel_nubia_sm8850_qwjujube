__int64 __fastcall dp_peer_rxtid_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x24
  __int64 v17; // x25
  unsigned int v18; // w23
  __int64 v19; // x9
  __int64 v20; // x27
  __int64 v21; // x4
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // [xsp+0h] [xbp-30h] BYREF
  __int64 v33; // [xsp+8h] [xbp-28h]
  __int64 v34; // [xsp+10h] [xbp-20h]
  __int64 v35; // [xsp+18h] [xbp-18h]
  __int64 v36; // [xsp+20h] [xbp-10h]
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL);
    v32 = 0;
    v7 = *(_QWORD *)(v6 + 8);
    v35 = 0;
    v36 = 0;
    v33 = 0;
    v34 = 0;
    qdf_mem_set(&v32, 0x28u, 0);
    v16 = 0;
    v17 = 0;
    v18 = 0;
    do
    {
      if ( (unsigned int)v17 < 8 || (_DWORD)v17 == 16 )
      {
        v19 = *(_QWORD *)(a1 + 88);
        if ( v19 + v16 )
        {
          v20 = v19 + v16;
          if ( *(_QWORD *)(v19 + v16 + 32) )
          {
            LOBYTE(v32) = 1;
            if ( a3 )
              v21 = a3;
            else
              v21 = v19 + v16;
            HIDWORD(v32) = *(_QWORD *)(v20 + 56);
            LOBYTE(v33) = *(_DWORD *)(v20 + 60);
            if ( !(unsigned int)dp_reo_send_cmd(v7, 0, v8, v9, v10, v11, v12, v13, v14, v15, (__int64)&v32, a2, v21) )
              ++v18;
            qdf_mem_set(&v32, 0x28u, 0);
            LOBYTE(v32) = 0;
            HIDWORD(v32) = *(_QWORD *)(v20 + 56);
            v22 = *(_DWORD *)(v20 + 60);
            HIBYTE(v33) = 1;
            LOBYTE(v33) = v22;
            dp_reo_send_cmd(v7, 2u, v23, v24, v25, v26, v27, v28, v29, v30, (__int64)&v32, 0, 0);
          }
        }
      }
      ++v17;
      v16 += 144;
    }
    while ( v17 != 17 );
  }
  else
  {
    v18 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
