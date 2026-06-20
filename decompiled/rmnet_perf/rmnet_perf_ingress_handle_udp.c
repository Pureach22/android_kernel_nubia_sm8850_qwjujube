__int64 __fastcall rmnet_perf_ingress_handle_udp(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x11
  __int64 v7; // x19
  _WORD *v8; // x8
  int v9; // w10
  __int64 v10; // x8
  char v11; // w8
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // [xsp+0h] [xbp-30h] BYREF
  __int64 v20; // [xsp+8h] [xbp-28h]
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int16 *)(result + 182);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 0;
  if ( v4 != 0xFFFF && (*(_BYTE *)(result + 128) & 0x60) != 0 )
  {
    v5 = *(_QWORD *)(result + 216);
    v6 = *(unsigned __int16 *)(result + 184);
    v7 = result;
    v8 = (_WORD *)(v5 + v4);
    LOWORD(v23) = *v8;
    v9 = *(unsigned __int16 *)(result + 180);
    WORD1(v23) = v8[1];
    v10 = v5 + v6;
    if ( v9 == 8 )
    {
      LODWORD(v19) = *(_DWORD *)(v10 + 12);
      LODWORD(v21) = *(_DWORD *)(v10 + 16);
      v11 = 4;
    }
    else
    {
      v12 = *(_QWORD *)(v10 + 16);
      v19 = *(_QWORD *)(v10 + 8);
      v20 = v12;
      v13 = *(_QWORD *)(v10 + 32);
      v21 = *(_QWORD *)(v10 + 24);
      v22 = v13;
      v11 = 6;
    }
    BYTE4(v23) = v11;
    _rcu_read_lock(result, a2, a3, a4);
    v14 = rmnet_perf_udp_track_tuple_find(&v19);
    if ( v14 && jiffies - *(_QWORD *)(v14 + 80) <= 0x1F4u )
      v14 = rmnet_perf_udp_track_node_update(v14, v7, v15, v16, v17, v18);
    result = _rcu_read_unlock(v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
