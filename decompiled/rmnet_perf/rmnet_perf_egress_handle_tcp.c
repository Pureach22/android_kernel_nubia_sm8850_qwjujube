__int64 __fastcall rmnet_perf_egress_handle_tcp(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x8
  _WORD *v6; // x9
  unsigned int v7; // w10
  __int64 v8; // x11
  __int64 v9; // x19
  int v10; // w10
  __int64 v11; // x8
  char v12; // w8
  __int64 v13; // x9
  __int64 v14; // x9
  unsigned __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  unsigned int v20; // w11
  unsigned int v21; // w10
  int v22; // w12
  unsigned int v23; // w8
  char v24; // w13
  unsigned int v25; // w20
  unsigned int v26; // w9
  __int64 v27; // x1
  unsigned __int64 v28; // x19
  __int64 v29; // [xsp+0h] [xbp-30h] BYREF
  __int64 v30; // [xsp+8h] [xbp-28h]
  __int64 v31; // [xsp+10h] [xbp-20h]
  __int64 v32; // [xsp+18h] [xbp-18h]
  __int64 v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int16 *)(result + 182);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  if ( v4 != 0xFFFF )
  {
    v5 = *(_QWORD *)(result + 216);
    v6 = (_WORD *)(v5 + v4);
    v7 = (unsigned __int16)v6[6];
    if ( (v7 & 0x200) == 0
      && (v7 & 0x1000) != 0
      && !(*(_DWORD *)(result + 112) - (_DWORD)v6 - ((v7 >> 2) & 0x3C) + *(_DWORD *)(result + 224)) )
    {
      v8 = *(unsigned __int16 *)(result + 184);
      v9 = result;
      LOWORD(v33) = v6[1];
      v10 = *(unsigned __int16 *)(result + 180);
      v11 = v5 + v8;
      WORD1(v33) = *v6;
      if ( v10 == 8 )
      {
        LODWORD(v29) = *(_DWORD *)(v11 + 16);
        LODWORD(v31) = *(_DWORD *)(v11 + 12);
        v12 = 4;
      }
      else
      {
        v13 = *(_QWORD *)(v11 + 32);
        v29 = *(_QWORD *)(v11 + 24);
        v30 = v13;
        v14 = *(_QWORD *)(v11 + 16);
        v31 = *(_QWORD *)(v11 + 8);
        v32 = v14;
        v12 = 6;
      }
      BYTE4(v33) = v12;
      _rcu_read_lock(result, a2, a3, a4);
      v15 = rmnet_perf_quickack_tuple_find((__int64)&v29, v9, 1);
      if ( v15 )
      {
        if ( jiffies - *(_QWORD *)(v15 + 72) <= 0x1F4u )
        {
          v20 = *(_DWORD *)(*(_QWORD *)(v9 + 216) + *(unsigned __int16 *)(v9 + 182) + 8LL);
          v21 = *(_DWORD *)(v15 + 80);
          v22 = *(_DWORD *)(v15 + 84);
          v23 = *(_DWORD *)(v15 + 92);
          v24 = *(_BYTE *)(v15 + 100);
          *(_QWORD *)(v15 + 72) = jiffies;
          if ( (v24 & 1) == 0 )
          {
            v25 = bswap32(v20);
            if ( ((v22 - v25) & 0x80000000) != 0 )
            {
              v26 = v25 - v21;
              if ( v25 < v21 )
                v26 = 0;
              if ( v26 > v23 )
              {
                v27 = v9;
                v28 = v15;
                rmnet_perf_quickack_force(v15, v27, v16, v17, v18, v19);
                v15 = v28;
              }
              *(_DWORD *)(v15 + 84) = v25;
            }
          }
        }
      }
      result = _rcu_read_unlock(v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
