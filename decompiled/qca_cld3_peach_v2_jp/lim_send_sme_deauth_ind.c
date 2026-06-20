__int64 __fastcall lim_send_sme_deauth_ind(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  int v8; // w8
  int v9; // w8
  __int64 v10; // x1
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h]
  __int64 v13; // [xsp+18h] [xbp-28h]
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  result = _qdf_mem_malloc(0x28u, "lim_send_sme_deauth_ind", 1151);
  if ( result )
  {
    v7 = result;
    *(_DWORD *)result = 2626574;
    *(_BYTE *)(result + 4) = *(_BYTE *)(a3 + 10);
    if ( *(_DWORD *)(a3 + 92) == 1 )
      v8 = *(unsigned __int16 *)(a2 + 34);
    else
      v8 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(result + 8) = v8;
    qdf_mem_copy((void *)(result + 12), (const void *)(a3 + 24), 6u);
    qdf_mem_copy((void *)(v7 + 18), (const void *)(a2 + 338), 6u);
    v9 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(v7 + 32) = v9;
    if ( v9 == 36 )
      *(_BYTE *)(v7 + 36) = *(_BYTE *)(a2 + 644);
    if ( *(_DWORD *)(a3 + 88) == 2 )
      *(_BYTE *)(v7 + 37) = (*(_WORD *)(a2 + 34) & 0xFFFB) == 1;
    v10 = *(unsigned __int8 *)(a3 + 8);
    v12 = v7;
    LOWORD(v11) = 5134;
    HIDWORD(v11) = 0;
    mac_trace_msg_tx(a1, v10, 5134);
    lim_diag_event_report(a1, 17, a3, 0);
    if ( *(_DWORD *)(a3 + 88) == 2 )
      result = lim_send_sta_disconnect_ind(a1, (unsigned __int16 *)&v11);
    else
      result = sys_process_mmh_msg(a1, &v11);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
