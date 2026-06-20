__int64 __fastcall lim_restore_from_auth_state(__int64 a1, unsigned int a2, __int16 a3, __int64 a4)
{
  __int64 v8; // x0
  char v9; // w9
  unsigned int v10; // w8
  int v11; // w3
  __int16 v12; // w2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int64 v23; // [xsp+8h] [xbp-18h]
  int v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v22 = 0;
  v23 = 0;
  lim_diag_event_report(a1, 63, a4, a2);
  qdf_mem_copy(&v22, *(const void **)(a1 + 11376), 6u);
  v8 = *(_QWORD *)(a1 + 11376);
  v9 = *(_BYTE *)(a4 + 8);
  v10 = *(_DWORD *)(v8 + 8);
  LOWORD(v24) = a3;
  BYTE2(v24) = v9;
  v23 = __PAIR64__(a2, v10);
  _qdf_mem_free(v8);
  *(_QWORD *)(a1 + 11376) = 0;
  v11 = *(_DWORD *)(a4 + 76);
  v12 = *(_WORD *)(a4 + 8);
  *(_DWORD *)(a4 + 72) = v11;
  qdf_trace(53, 0, v12, v11);
  *(_DWORD *)(a1 + 21660) = 1;
  if ( (tx_timer_running(a1 + 2928) & 1) != 0 )
    lim_deactivate_and_change_timer(a1, 20);
  if ( (tx_timer_running(a1 + 808) & 1) != 0 )
    lim_deactivate_and_change_timer(a1, 3);
  if ( *(_DWORD *)(a4 + 80) == 11 )
    *(_BYTE *)(a1 + 11388) = 0;
  result = lim_process_mlm_rsp_messages(a1, 1007, (unsigned __int8 *)&v22, v13, v14, v15, v16, v17, v18, v19, v20);
  _ReadStatusReg(SP_EL0);
  return result;
}
