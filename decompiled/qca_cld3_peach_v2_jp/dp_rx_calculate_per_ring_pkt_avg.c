__int64 __fastcall dp_rx_calculate_per_ring_pkt_avg(__int64 a1)
{
  __int64 v1; // x19
  __int64 *v2; // x25
  __int64 v3; // x22
  unsigned __int64 StatusReg; // x20
  unsigned __int64 *v5; // x8
  unsigned int v6; // w8
  unsigned __int64 v7; // x28
  __int64 v8; // x26
  __int64 *v9; // x21
  __int64 result; // x0
  __int64 v11; // t1
  _QWORD *v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x11
  unsigned __int64 v18; // x10
  __int64 v19; // x11

  v1 = 0;
  v2 = (__int64 *)(a1 + 14168);
  v3 = a1 + 16216;
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  do
  {
    v6 = _cpu_possible_mask;
    v7 = 0;
    v8 = 0;
    v9 = v2;
    while ( 1 )
    {
      result = _sw_hweight64(v6);
      if ( v7 >= (unsigned int)result )
        break;
      if ( v7 == 32 )
      {
        __break(0x5512u);
        return dp_rx_get_per_ring_pkt_avg();
      }
      v11 = *v9;
      v9 += 8;
      v6 = _cpu_possible_mask;
      ++v7;
      v8 += v11;
    }
    v12 = (_QWORD *)(v3 + 32 * v1);
    v13 = v12[1];
    *v12 = v8;
    if ( v13 )
    {
      v5 = v12 + 3;
      v14 = v12[3];
      v15 = 1000000 * (v8 - v13);
      v12[1] = v8;
      v16 = StatusReg - v14;
      if ( 10 * v16 < v16 )
        v17 = 10 * (v16 / 0xC0);
      else
        v17 = 10 * v16 / 0xC0;
      v18 = v15 / v17;
      v19 = v12[2];
      if ( v19 )
        v18 = 25 * v19 / 0x64uLL + 75 * v18 / 0x64;
      v12[2] = v18;
    }
    else
    {
      v12[1] = v8;
      v5 = v12 + 3;
    }
    ++v1;
    ++v2;
    *v5 = StatusReg;
  }
  while ( v1 != 8 );
  return result;
}
