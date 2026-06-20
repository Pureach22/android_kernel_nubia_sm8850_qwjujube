__int64 __fastcall cm_roam_neigh_rpt_resp_event(__int64 a1, unsigned __int8 a2)
{
  unsigned int v4; // w22
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x0
  char v10; // w10
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x10
  int *v16; // x10
  _DWORD *v17; // x11
  __int64 v18; // x12
  int v19; // w13
  int v20; // w14
  char v21; // w9
  __int64 result; // x0
  _QWORD s[71]; // [xsp+8h] [xbp-238h] BYREF

  s[70] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x230u);
  qdf_mem_set(s, 0x230u, 0);
  v4 = *(_DWORD *)(a1 + 4);
  HIWORD(s[0]) = a2;
  s[1] = qdf_get_time_of_the_day_us();
  v9 = ktime_get(s[1], v5, v6, v7, v8);
  BYTE2(s[4]) = 42;
  v10 = *(_BYTE *)(a1 + 180);
  LOBYTE(s[4]) = 3;
  BYTE3(s[4]) = v10;
  v11 = *(unsigned __int8 *)(a1 + 20);
  s[2] = 1000LL * v4;
  s[3] = v9 / 1000;
  WORD2(s[4]) = v11;
  if ( (_DWORD)v11 )
  {
    if ( (unsigned int)v11 >= 3 )
    {
      v13 = v11 - 1;
      if ( (unsigned __int64)(v11 - 1) >= 0x26 )
        v13 = 38;
      v14 = v13 + 1;
      v15 = v14 & 1;
      if ( (v14 & 1) == 0 )
        v15 = 2;
      v12 = v14 - v15;
      v16 = (int *)(a1 + 28);
      v17 = &s[10];
      v18 = v12;
      do
      {
        v19 = *(v16 - 1);
        v20 = *v16;
        v18 -= 2;
        v16 += 2;
        *(v17 - 1) = v19;
        *v17 = v20;
        v17 += 2;
      }
      while ( v18 );
    }
    else
    {
      v12 = 0;
    }
    do
    {
      if ( v12 == 38 )
        __break(0x5512u);
      *((_DWORD *)&s[9] + v12 + 1) = *(_DWORD *)(a1 + 24 + 4 * v12);
      ++v12;
    }
    while ( v11 != v12 );
  }
  v21 = *(_BYTE *)(a1 + 183);
  BYTE1(s[4]) = *(_BYTE *)(a1 + 181);
  BYTE4(s[69]) = v21;
  result = host_diag_event_report_payload(3383, 560, s);
  _ReadStatusReg(SP_EL0);
  return result;
}
