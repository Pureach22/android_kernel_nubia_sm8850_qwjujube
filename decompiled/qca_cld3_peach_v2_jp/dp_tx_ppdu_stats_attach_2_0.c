__int64 __fastcall dp_tx_ppdu_stats_attach_2_0(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x8
  __int64 *v3; // x21
  _QWORD *v4; // x8

  if ( result )
  {
    v1 = result;
    v2 = *(_QWORD **)(result + 95560);
    if ( v2 )
    {
      v3 = v2 + 4920;
      v2[4932] = 0;
      v2[4933] = v2 + 4932;
      v2[4935] = 0;
      v2[4936] = v2 + 4935;
      v4 = v2 + 4925;
      *v3 = result;
      *((_BYTE *)v3 + 8) = 0;
      *((_DWORD *)v3 + 22) = 0;
      *((_DWORD *)v3 + 28) = 0;
      *((_DWORD *)v3 + 4) = 0;
      v3[8] = (__int64)dp_tx_mon_ppdu_process;
      v3[9] = (__int64)v3;
      v3[3] = 0;
      v3[4] = 0xFFFFFFFE00000LL;
      v3[5] = (__int64)v4;
      v3[6] = (__int64)v4;
      v3[7] = (__int64)_qdf_defer_func;
      v3[10] = alloc_workqueue("tx_mon_ppdu_work_queue", 2, 0);
      *((_BYTE *)v3 + 2584) = 1;
      v3[335] = (__int64)(v3 + 334);
      v3[338] = (__int64)(v3 + 337);
      v3[331] = (__int64)(v3 + 322);
      v3[322] = v1;
      v3[334] = 0;
      *((_DWORD *)v3 + 666) = 0;
      v3[337] = 0;
      *((_DWORD *)v3 + 672) = 0;
      *((_DWORD *)v3 + 648) = 0;
      v3[325] = 0;
      v3[330] = (__int64)dp_tx_mon_ppdu_process;
      v3[326] = 0xFFFFFFFE00000LL;
      v3[327] = (__int64)(v3 + 327);
      v3[328] = (__int64)(v3 + 327);
      v3[329] = (__int64)_qdf_defer_func;
      result = alloc_workqueue("tx_mon_ppdu_work_queue", 2, 0);
      v3[332] = result;
    }
  }
  return result;
}
