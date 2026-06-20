__int64 __fastcall lim_send_sta_disconnect_ind(__int64 a1, unsigned __int16 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x8
  int v7; // w10
  int v8; // w11
  __int64 v9; // x9
  int v10; // w8
  __int16 v11; // w9
  __int64 v12; // x0
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // [xsp+8h] [xbp-38h] BYREF
  __int64 v24; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v25)(__int64); // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = nullptr;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v4 = _qdf_mem_malloc(0x20u, "lim_send_sta_disconnect_ind", 791);
  if ( !v4 )
  {
    v22 = *((_QWORD *)a2 + 1);
    goto LABEL_11;
  }
  v5 = v4;
  *(_QWORD *)v4 = *(_QWORD *)(a1 + 21624);
  v6 = *((_QWORD *)a2 + 1);
  v7 = *a2;
  *(_BYTE *)(v4 + 8) = *(_BYTE *)(v6 + 4);
  v8 = *(_DWORD *)(v6 + 12);
  *(_WORD *)(v4 + 24) = *(_WORD *)(v6 + 16);
  *(_DWORD *)(v4 + 20) = v8;
  *(_DWORD *)(v4 + 16) = *(_DWORD *)(v6 + 32);
  if ( v7 == 5130 )
    v9 = 36;
  else
    v9 = 37;
  if ( *(_BYTE *)(v6 + v9) )
    v10 = 6;
  else
    v10 = 7;
  *(_DWORD *)(v4 + 12) = v10;
  v11 = *a2;
  v24 = v4;
  v25 = cm_send_sb_disconnect_req;
  v12 = *((_QWORD *)a2 + 1);
  LOWORD(v23) = v11;
  _qdf_mem_free(v12);
  result = scheduler_post_message_debug(
             0x35u,
             0x48u,
             72,
             (unsigned __int16 *)&v23,
             0x337u,
             (__int64)"lim_send_sta_disconnect_ind");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev_id: %d, source %d, reason %d, type %d msg post fails",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_send_sta_disconnect_ind",
      *(unsigned __int8 *)(v5 + 8),
      *(unsigned int *)(v5 + 12),
      *(unsigned int *)(v5 + 16),
      (unsigned __int16)v23);
    v22 = v5;
LABEL_11:
    result = _qdf_mem_free(v22);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
