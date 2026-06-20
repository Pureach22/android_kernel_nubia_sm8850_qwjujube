__int64 __fastcall rmnet_vnd_start_xmit(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int v5; // w21
  unsigned int v6; // w22
  unsigned int v7; // w23
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x9
  unsigned int *v10; // x9
  unsigned int v11; // w12
  __int64 v12; // x9
  char v13; // w8
  __int64 v14; // x9
  __int16 v15; // w24
  unsigned __int64 v16; // x0
  _QWORD *v17; // x24
  _QWORD *v18; // x0
  char v19; // w1
  _QWORD *v20; // x19
  unsigned int v21; // w8
  unsigned int v22; // w10
  int v23; // w25
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x26
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x19
  char v30; // w1
  unsigned __int64 v31; // x8
  __int64 v32; // x9
  unsigned int *v33; // x9
  int v34; // w10
  unsigned int v35; // w12
  __int64 v36; // x9
  __int64 rmnet_port; // x0
  __int64 v39; // x9
  unsigned int *v40; // x9
  unsigned int v41; // w12
  __int64 v42; // x9
  unsigned int *v43; // x9
  unsigned int v44; // w12
  _BYTE v45[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v46[4]; // [xsp+10h] [xbp-10h] BYREF
  int v47; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v46[0] = 0;
  v45[0] = 0;
  v4 = rmnet_module_hook_aps_post_queue(&v47, a2, a1);
  if ( (_DWORD)v4 && v47 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v42 = *(_QWORD *)(a2 + 2704);
    v43 = (unsigned int *)(v42 + _ReadStatusReg(TPIDR_EL1) + 32);
    do
      v44 = __ldxr(v43);
    while ( __stxr(v44 + 1, v43) );
LABEL_12:
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v4);
    goto LABEL_44;
  }
  if ( !*(_QWORD *)(a2 + 2696) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v9 = *(_QWORD *)(a2 + 2704);
    v10 = (unsigned int *)(v9 + _ReadStatusReg(TPIDR_EL1) + 32);
    do
      v11 = __ldxr(v10);
    while ( __stxr(v11 + 1, v10) );
    goto LABEL_12;
  }
  v5 = *(_DWORD *)(a1 + 168);
  v6 = *(_DWORD *)(a1 + 112);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 184)) & 0xF0) == 0x40 )
    v7 = 2;
  else
    v7 = 10;
  rmnet_module_hook_perf_tether_egress(a1);
  rmnet_module_hook_wlan_flow_match(a1);
  v4 = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, char *))qmi_rmnet_get_flow_state)(a2, a1, v45, v46);
  if ( v45[0] == 1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v39 = *(_QWORD *)(a2 + 2704);
    v40 = (unsigned int *)(v39 + _ReadStatusReg(TPIDR_EL1) + 32);
    do
      v41 = __ldxr(v40);
    while ( __stxr(v41 + 1, v40) );
    goto LABEL_12;
  }
  if ( *(_DWORD *)rmnet_ll_get_ipa_ready_status(v4) )
  {
    v46[0] = 0;
  }
  else if ( (*(_DWORD *)(a1 + 144) & 0xFFFF0100) == 0x9B6D0100 )
  {
    v46[0] = 1;
  }
  if ( *(_WORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 4LL) )
    rmnet_module_hook_perf_seg_stat(*(unsigned __int8 *)(a2 + 2688), a1);
  v13 = v46[0];
  if ( (v46[0] & 1) != 0 )
  {
    if ( !*(_WORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 4LL) )
      goto LABEL_47;
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v15 = *(_WORD *)(v14 + 4);
    if ( (*(_DWORD *)(a1 + 144) & 0xFFFF0200) != 0x9B6D0200 )
    {
      if ( *(_WORD *)(v14 + 4) )
      {
        v21 = *(_DWORD *)(*(_QWORD *)(a2 + 2696) + 44LL);
        v22 = HIWORD(v21);
        if ( v21 <= 1 )
          v21 = 1;
        if ( v22 || *(_DWORD *)(a1 + 112) < v21 )
        {
          v13 = 0;
          ++*(_QWORD *)(a2 + 3136);
        }
        else
        {
          v23 = *(_DWORD *)(v14 + 24);
          *(_WORD *)(v14 + 4) *= (unsigned __int16)v21 / *(_WORD *)(v14 + 4);
          v24 = _skb_gso_segment(a1, 19, 0);
          if ( v24 && v24 < 0xFFFFFFFFFFFFF001LL )
          {
            v25 = v24;
            consume_skb(a1);
            v26 = v25;
            do
            {
              v27 = *(_QWORD *)(v26 + 216);
              v28 = *(unsigned int *)(v26 + 212);
              *(_QWORD *)(v26 + 16) = a2;
              v29 = *(_QWORD *)v26;
              *(_WORD *)(v27 + v28 + 4) = v15;
              *(_DWORD *)(*(_QWORD *)(v26 + 216) + *(unsigned int *)(v26 + 212) + 24LL) = v23;
              v30 = v46[0];
              ++*(_QWORD *)(a2 + 3120);
              *(_QWORD *)v26 = 0;
              rmnet_egress_handler(v26, v30);
              v26 = v29;
            }
            while ( v29 );
            goto LABEL_48;
          }
          *(_WORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 4LL) = v15;
          *(_DWORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 24LL) = v23;
          v13 = v46[0];
          ++*(_QWORD *)(a2 + 3128);
        }
      }
      goto LABEL_47;
    }
    if ( !*(_WORD *)(v14 + 4) )
    {
LABEL_47:
      rmnet_egress_handler(a1, v13 & 1);
LABEL_48:
      qmi_rmnet_burst_fc_check(a2, v7, v5, v6);
      rmnet_port = rmnet_get_rmnet_port(a2);
      qmi_rmnet_work_maybe_restart(rmnet_port, 0, 0);
      goto LABEL_49;
    }
  }
  v16 = _skb_gso_segment(a1, *(_QWORD *)(a2 + 184) & 0xFFFFFFF80000FFFFLL, 1);
  if ( v16 && v16 < 0xFFFFFFFFFFFFF001LL )
  {
    v17 = (_QWORD *)v16;
    consume_skb(a1);
    v18 = v17;
    do
    {
      v18[2] = a2;
      v19 = v46[0];
      v20 = (_QWORD *)*v18;
      ++*(_QWORD *)(a2 + 3144);
      *v18 = 0;
      rmnet_egress_handler((__int64)v18, v19);
      v18 = v20;
    }
    while ( v20 );
    goto LABEL_48;
  }
  v31 = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(v31 + 16);
  v32 = *(_QWORD *)(a2 + 2704);
  v33 = (unsigned int *)(v32 + _ReadStatusReg(TPIDR_EL1) + 32);
  v34 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL);
  do
    v35 = __ldxr(v33);
  while ( __stxr(v35 + v34, v33) );
  v36 = *(_QWORD *)(v31 + 16) - 1LL;
  *(_DWORD *)(v31 + 16) = v36;
  if ( !v36 || !*(_QWORD *)(v31 + 16) )
    preempt_schedule_notrace(v16);
  ++*(_QWORD *)(a2 + 3152);
LABEL_44:
  sk_skb_reason_drop(0, a1, 2);
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return 0;
}
