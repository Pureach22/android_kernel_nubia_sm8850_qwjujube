__int64 __fastcall cm_roam_neigh_rpt_resp_event(__int64 a1, unsigned __int8 a2)
{
  unsigned int v4; // w22
  __int64 v5; // x0
  char v6; // w10
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x10
  int *v12; // x10
  _DWORD *v13; // x11
  __int64 v14; // x12
  int v15; // w13
  int v16; // w14
  char v17; // w9
  __int64 result; // x0
  _QWORD s[71]; // [xsp+8h] [xbp-238h] BYREF

  s[70] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x230u);
  qdf_mem_set(s, 0x230u, 0);
  v4 = *(_DWORD *)(a1 + 4);
  HIWORD(s[0]) = a2;
  s[1] = qdf_get_time_of_the_day_us();
  v5 = ktime_get();
  BYTE2(s[4]) = 42;
  v6 = *(_BYTE *)(a1 + 180);
  LOBYTE(s[4]) = 3;
  BYTE3(s[4]) = v6;
  v7 = *(unsigned __int8 *)(a1 + 20);
  s[2] = 1000LL * v4;
  s[3] = v5 / 1000;
  WORD2(s[4]) = v7;
  if ( (_DWORD)v7 )
  {
    if ( (unsigned int)v7 >= 3 )
    {
      v9 = v7 - 1;
      if ( (unsigned __int64)(v7 - 1) >= 0x26 )
        v9 = 38;
      v10 = v9 + 1;
      v11 = v10 & 1;
      if ( (v10 & 1) == 0 )
        v11 = 2;
      v8 = v10 - v11;
      v12 = (int *)(a1 + 28);
      v13 = &s[10];
      v14 = v8;
      do
      {
        v15 = *(v12 - 1);
        v16 = *v12;
        v14 -= 2;
        v12 += 2;
        *(v13 - 1) = v15;
        *v13 = v16;
        v13 += 2;
      }
      while ( v14 );
    }
    else
    {
      v8 = 0;
    }
    do
    {
      if ( v8 == 38 )
        __break(0x5512u);
      *((_DWORD *)&s[9] + v8 + 1) = *(_DWORD *)(a1 + 24 + 4 * v8);
      ++v8;
    }
    while ( v7 != v8 );
  }
  v17 = *(_BYTE *)(a1 + 183);
  BYTE1(s[4]) = *(_BYTE *)(a1 + 181);
  BYTE4(s[69]) = v17;
  result = host_diag_event_report_payload(3383, 560, s);
  _ReadStatusReg(SP_EL0);
  return result;
}
