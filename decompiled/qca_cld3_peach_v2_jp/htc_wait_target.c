__int64 __fastcall htc_wait_target(_QWORD *a1)
{
  char v2; // w8
  unsigned int v3; // w0
  unsigned int v4; // w20
  char v5; // w8
  unsigned int v7; // w9
  unsigned int v8; // w10
  int v9; // w5
  int v10; // w11
  bool v11; // zf
  char v12; // w9
  int v13; // w4
  unsigned int v14; // w8
  _QWORD v15[3]; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD v16[3]; // [xsp+20h] [xbp-90h] BYREF
  _QWORD *v17; // [xsp+38h] [xbp-78h]
  __int64 (__fastcall *v18)(); // [xsp+40h] [xbp-70h]
  __int64 (__fastcall *v19)(); // [xsp+48h] [xbp-68h]
  __int64 v20; // [xsp+50h] [xbp-60h]
  __int64 v21; // [xsp+58h] [xbp-58h]
  __int64 v22; // [xsp+60h] [xbp-50h]
  __int64 v23; // [xsp+68h] [xbp-48h]
  __int64 v24; // [xsp+70h] [xbp-40h]
  __int64 v25; // [xsp+78h] [xbp-38h]
  __int64 v26; // [xsp+80h] [xbp-30h]
  __int64 v27; // [xsp+88h] [xbp-28h]
  __int64 v28; // [xsp+90h] [xbp-20h]
  __int64 v29; // [xsp+98h] [xbp-18h]
  __int64 v30; // [xsp+A0h] [xbp-10h]
  __int64 v31; // [xsp+A8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = dword_B0B4;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = nullptr;
  v20 = 0;
  v17 = nullptr;
  v18 = nullptr;
  memset(v16, 0, sizeof(v16));
  memset(v15, 0, sizeof(v15));
  if ( (dword_B0B4 & 8) != 0 )
  {
    qdf_trace_msg(56, 2, "%s: htc_wait_target - Enter (target:0x%pK)\n", "htc_wait_target", a1);
    v2 = dword_B0B4;
  }
  if ( (v2 & 0x10) != 0 )
    qdf_trace_msg(56, 2, "%s: +HWT\n", "htc_wait_target");
  v3 = ((__int64 (__fastcall *)(_QWORD))hif_start)(*a1);
  if ( v3 )
  {
    v4 = v3;
    if ( (dword_B0B4 & 1) != 0 )
      qdf_trace_msg(56, 2, "%s: hif_start failed\n", "htc_wait_target");
    goto LABEL_9;
  }
  v4 = htc_wait_recv_ctrl_message(a1);
  if ( v4 )
    goto LABEL_9;
  if ( *((_DWORD *)a1 + 840) <= 0xBu )
  {
    if ( (dword_B0B4 & 1) != 0 )
    {
      qdf_trace_msg(56, 2, "%s: Invalid HTC Ready Msg Len:%d!\n", "htc_wait_target");
LABEL_35:
      v4 = 7;
      goto LABEL_9;
    }
    goto LABEL_32;
  }
  if ( (unsigned __int16)*((_DWORD *)a1 + 776) != 1 )
  {
    if ( (dword_B0B4 & 1) != 0 )
    {
      qdf_trace_msg(56, 2, "%s: Invalid HTC Ready Msg : 0x%X!\n", "htc_wait_target");
      goto LABEL_35;
    }
LABEL_32:
    v4 = 7;
    goto LABEL_9;
  }
  v7 = *((_DWORD *)a1 + 766);
  v8 = *((_DWORD *)a1 + 778);
  v9 = *((unsigned __int16 *)a1 + 1554);
  if ( v7 >= HIWORD(*((_DWORD *)a1 + 776)) )
    v10 = HIWORD(*((_DWORD *)a1 + 776));
  else
    v10 = *((_DWORD *)a1 + 766);
  v11 = v7 == 0;
  v12 = dword_B0B4;
  if ( v11 )
    v13 = HIWORD(*((_DWORD *)a1 + 776));
  else
    v13 = v10;
  v14 = v8 >> 8;
  *((_DWORD *)a1 + 853) = v13;
  if ( (v8 & 0xFF00) == 0 )
    LOBYTE(v14) = 1;
  *((_DWORD *)a1 + 862) = v9;
  *((_BYTE *)a1 + 3496) = v14;
  if ( (v12 & 4) != 0 )
  {
    qdf_trace_msg(
      56,
      2,
      "%s: Target Ready! TX resource : %d size:%d, MaxMsgsPerHTCBundle = %d",
      "htc_wait_target",
      v13,
      v9,
      (unsigned __int8)v14);
    v13 = *((_DWORD *)a1 + 853);
  }
  if ( v13 && *((_DWORD *)a1 + 862) )
  {
    *((_BYTE *)a1 + 3408) = 0;
    htc_setup_target_buffer_assignments(a1);
    qdf_mem_set((int)v16, 0x88u, 0);
    qdf_mem_set((int)v15, 0x18u, 0);
    v17 = a1;
    v18 = htc_control_tx_complete;
    v19 = htc_control_rx_complete;
    LODWORD(v29) = 2;
    LOWORD(v16[0]) = 1;
    v4 = htc_connect_service(a1, v16, v15);
  }
  else
  {
    v4 = 10;
  }
LABEL_9:
  v5 = dword_B0B4;
  if ( (dword_B0B4 & 8) != 0 )
  {
    qdf_trace_msg(56, 2, "%s: htc_wait_target - Exit (%d)\n", "htc_wait_target", v4);
    v5 = dword_B0B4;
  }
  if ( (v5 & 0x10) != 0 )
    qdf_trace_msg(56, 2, "%s: -HWT\n", "htc_wait_target");
  _ReadStatusReg(SP_EL0);
  return v4;
}
