__int64 __fastcall swr_master_bulk_write(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  _DWORD *v4; // x8
  __int64 v9; // x0
  int v11; // w25
  int v12; // w1

  v4 = *(_DWORD **)(a1 + 9088);
  if ( v4 )
  {
    v9 = *(_QWORD *)(a1 + 9064);
    if ( *(v4 - 1) != -363998022 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v4)(v9, a2, a3, a4);
  }
  else
  {
    mutex_lock(a1 + 8688);
    if ( a4 )
    {
      v11 = 0;
      do
      {
        usleep_range_state(50, 55, 2);
        v12 = *(_DWORD *)(a2 + 4LL * v11);
        if ( v12 == (*(_DWORD *)(a1 + 9056) << 12) + 16416 )
        {
          swrm_wait_for_fifo_avail(a1, 0);
          v12 = *(_DWORD *)(a2 + 4LL * v11);
        }
        swr_master_write(a1, v12, *(_DWORD *)(a3 + 4LL * v11++));
      }
      while ( a4 != v11 );
    }
    usleep_range_state(100, 110, 2);
    return mutex_unlock(a1 + 8688);
  }
}
