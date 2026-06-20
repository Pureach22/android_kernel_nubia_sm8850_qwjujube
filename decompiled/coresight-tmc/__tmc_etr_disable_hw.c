__int64 __fastcall _tmc_etr_disable_hw(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  _DWORD *v6; // x9
  __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 result; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  writel_relaxed_1(3316436565LL, a1[1] + 4016LL);
  __dsb(0xFu);
  tmc_flush_and_stop((__int64)a1);
  tmc_disable_stop_on_flush((__int64)a1);
  if ( (unsigned int)*(_QWORD *)(a1[2] + 968LL) == 1 )
  {
    v2 = a1[15];
    if ( a1[36] == v2 )
    {
      tmc_sync_etr_buf(a1);
      if ( *(_BYTE *)(v2 + 8) == 1 )
      {
        v3 = *(_QWORD *)(v2 + 32);
        v4 = *(_QWORD *)(v2 + 48);
        v5 = *(_QWORD *)(v2 + 16) - v3;
        v12[0] = 0;
        v6 = *(_DWORD **)(v4 + 16);
        if ( v5 >= 0x10 )
          v7 = 16;
        else
          v7 = v5;
        if ( *(v6 - 1) != -256312645 )
          __break(0x8229u);
        if ( ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))v6)(v2, v3, v7, v12) <= 15 )
        {
          __break(0x800u);
        }
        else
        {
          v8 = v12[0];
          if ( v12[0] )
          {
            v9 = coresight_barrier_pkt[1];
            *(_QWORD *)v12[0] = coresight_barrier_pkt[0];
            *(_QWORD *)(v8 + 8) = v9;
          }
        }
      }
    }
    else
    {
      __break(0x800u);
      if ( a1[36] )
        tmc_free_etr_buf();
      a1[36] = 0;
    }
  }
  tmc_disable_hw((__int64)a1);
  v10 = a1[1];
  __dsb(0xFu);
  result = writel_relaxed_1(0, v10 + 4016);
  _ReadStatusReg(SP_EL0);
  return result;
}
