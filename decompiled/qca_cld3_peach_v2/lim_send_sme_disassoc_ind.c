__int64 __fastcall lim_send_sme_disassoc_ind(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  char v8; // w8
  __int16 v9; // w2
  __int64 v10; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  result = _qdf_mem_malloc(0x28u, "lim_send_sme_disassoc_ind", 1093);
  if ( result )
  {
    v7 = result;
    *(_DWORD *)result = 2626570;
    v8 = *(_BYTE *)(a3 + 10);
    *(_DWORD *)(result + 8) = 539;
    *(_BYTE *)(result + 4) = v8;
    *(_DWORD *)(result + 32) = *(_DWORD *)(a2 + 24);
    qdf_mem_copy((void *)(result + 12), (const void *)(a3 + 24), 6u);
    qdf_mem_copy((void *)(v7 + 18), (const void *)(a2 + 350), 6u);
    if ( *(_DWORD *)(a3 + 88) == 2 )
      *(_BYTE *)(v7 + 36) = (*(_WORD *)(a2 + 34) & 0xFFFB) == 1;
    v9 = *(_WORD *)(a3 + 8);
    v11 = v7;
    LOWORD(v10) = 5130;
    HIDWORD(v10) = 0;
    qdf_trace(53, 6u, v9, 5130);
    lim_diag_event_report(a1, 13, a3, 0);
    if ( *(_DWORD *)(a3 + 88) == 2 )
      result = lim_send_sta_disconnect_ind(a1, (unsigned __int16 *)&v10);
    else
      result = sys_process_mmh_msg(a1, &v10);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
