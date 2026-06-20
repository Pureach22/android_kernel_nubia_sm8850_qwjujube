__int64 __fastcall mlo_mgr_update_ap_link_info(__int64 result, unsigned __int8 a2, unsigned __int16 *a3, __int16 *a4)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int16 *v9; // x20
  unsigned __int8 v10; // w22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int16 v19; // w8
  unsigned __int16 *v20; // x9
  __int64 v21; // x6
  __int64 v22; // x5
  __int64 v23; // x7
  int v24; // w9
  int v25; // w10
  int v26; // w11

  _ReadStatusReg(SP_EL0);
  if ( !result )
    goto LABEL_26;
  if ( !a3 )
    goto LABEL_26;
  v4 = *(_QWORD *)(result + 1360);
  if ( !v4 )
    goto LABEL_26;
  v5 = *(_QWORD *)(v4 + 3880);
  if ( *(_DWORD *)(v5 + 24) == *(_DWORD *)a3 && *(unsigned __int16 *)(v5 + 28) == a3[2] )
    goto LABEL_20;
  if ( *(_DWORD *)(v5 + 72) == *(_DWORD *)a3 && *(unsigned __int16 *)(v5 + 76) == a3[2] )
    goto LABEL_21;
  if ( *(_DWORD *)(v5 + 120) != *(_DWORD *)a3 || *(unsigned __int16 *)(v5 + 124) != a3[2] )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(result + 1360) + 3880LL);
    if ( *(_DWORD *)(v5 + 24) | *(unsigned __int16 *)(v5 + 28) )
    {
      if ( *(_DWORD *)(v5 + 72) | *(unsigned __int16 *)(v5 + 76) )
      {
        if ( *(_DWORD *)(v5 + 120) | *(unsigned __int16 *)(v5 + 124) )
          goto LABEL_26;
        goto LABEL_19;
      }
LABEL_21:
      v9 = a4;
      v10 = a2;
      v5 += 48;
      goto LABEL_22;
    }
LABEL_20:
    v9 = a4;
    v10 = a2;
    goto LABEL_22;
  }
LABEL_19:
  v9 = a4;
  v10 = a2;
  v5 += 96;
LABEL_22:
  qdf_mem_copy((void *)(v5 + 24), a3, 6u);
  qdf_mem_copy(*(void **)(v5 + 32), v9, 0x28u);
  v19 = *v9;
  v20 = *(unsigned __int16 **)(v5 + 32);
  *(_QWORD *)(v5 + 16) = 0;
  *(_BYTE *)(v5 + 6) = v10;
  v21 = *(unsigned __int8 *)(v5 + 12);
  *(_WORD *)(v5 + 10) = v19;
  v22 = *v20;
  if ( v5 == -24 )
  {
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v26 = 0;
  }
  else
  {
    v23 = *(unsigned __int8 *)(v5 + 24);
    v24 = *(unsigned __int8 *)(v5 + 25);
    v25 = *(unsigned __int8 *)(v5 + 26);
    v26 = *(unsigned __int8 *)(v5 + 29);
  }
  result = qdf_trace_msg(
             0x8Fu,
             8u,
             "%s: Update AP Link info for link_id: %d, freq: %d vdev_id:%d, link_addr:%02x:%02x:%02x:**:**:%02x",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "mlo_mgr_update_ap_link_info",
             v10,
             v22,
             v21,
             v23,
             v24,
             v25,
             v26);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
