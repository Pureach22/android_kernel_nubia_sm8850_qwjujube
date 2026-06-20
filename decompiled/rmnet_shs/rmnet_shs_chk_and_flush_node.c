__int64 __fastcall rmnet_shs_chk_and_flush_node(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, __int64 a4)
{
  __int64 v4; // x23
  __int64 v6; // x24
  int v8; // w0
  __int16 v9; // w0
  __int64 result; // x0
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x8
  __int16 v15; // w10
  unsigned __int8 v16; // w9
  bool v17; // zf
  __int64 v18; // x3
  __int64 *v19; // x20
  __int64 v20; // x19
  int v21; // w25
  int v22; // w9
  int v23; // w26
  unsigned int v24; // w28
  __int64 *v25; // x27
  int v26; // w23
  __int64 v27; // x21
  unsigned int v28; // w22
  __int16 v29; // w24
  int v30; // w19
  unsigned __int64 v31; // x0
  unsigned __int64 v32; // x8
  unsigned int v33; // w11
  __int64 v34; // x9
  unsigned __int64 v35; // x19
  __int64 v36; // x8
  int v37; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // [xsp+10h] [xbp-30h]
  __int64 v42; // [xsp+20h] [xbp-20h]
  unsigned __int8 v43; // [xsp+2Ch] [xbp-14h]
  int v45; // [xsp+38h] [xbp-8h]
  int v46; // [xsp+3Ch] [xbp-4h]

  LOWORD(v4) = *(_WORD *)(a1 + 212);
  v6 = a1;
  while ( 1 )
  {
    if ( (unsigned int)rmnet_shs_cpu_from_idx(*(_BYTE *)(v6 + 208), v4) == *(unsigned __int16 *)(v6 + 210) )
      goto LABEL_23;
    v8 = rmnet_shs_idx_from_cpu(*(_WORD *)(v6 + 210), v4);
    if ( v8 < 0 )
    {
      if ( (v4 & 1) == 0 )
      {
        if ( (v4 & 2) != 0 )
        {
          v9 = 1;
          goto LABEL_21;
        }
        if ( (v4 & 4) != 0 )
        {
          v9 = 2;
          goto LABEL_21;
        }
        if ( (v4 & 8) != 0 )
        {
          v9 = 3;
          goto LABEL_21;
        }
        if ( (v4 & 0x10) != 0 )
        {
          v9 = 4;
          goto LABEL_21;
        }
        if ( (v4 & 0x20) != 0 )
        {
          v9 = 5;
          goto LABEL_21;
        }
        if ( (v4 & 0x40) != 0 )
        {
          v9 = 6;
          goto LABEL_21;
        }
        if ( (v4 & 0x80) != 0 )
        {
          v9 = 7;
          goto LABEL_21;
        }
      }
      v9 = 0;
LABEL_21:
      *(_WORD *)(v6 + 208) = 0;
      goto LABEL_22;
    }
    *(_WORD *)(v6 + 208) = v8;
    v9 = rmnet_shs_cpu_from_idx(v8, v4);
LABEL_22:
    *(_WORD *)(v6 + 210) = v9;
    ++qword_1A438;
    a2 = 1;
LABEL_23:
    result = rmnet_shs_node_can_flush_pkts(v6, a2);
    if ( !(_DWORD)result )
      return result;
    v4 = v6 + 96;
    v14 = *(_QWORD *)(v6 + 96);
    if ( !v14 )
      return 1;
    v15 = *(_WORD *)(v6 + 212);
    if ( v15 )
    {
      v16 = *(_BYTE *)(v6 + 214);
    }
    else
    {
      LOBYTE(v15) = byte_19497;
      v16 = byte_19498;
    }
    if ( *(unsigned __int8 *)(v6 + 210) < 8u )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v39 = _traceiter_rmnet_shs_high(0, 8, 50, a2, a3, 3567, 3567, v6);
      v40 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v40;
      if ( !v40 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v39);
    }
  }
  if ( BYTE6(rmnet_shs_cpu_node_tbl[5 * *(unsigned __int8 *)(v6 + 210) + 4]) )
    v17 = rmnet_shs_no_sync_off == 0;
  else
    v17 = 1;
  v18 = !v17;
  v46 = v18;
  if ( !(_BYTE)v15 )
  {
    v45 = 0;
    *(_BYTE *)(v6 + 222) = 0;
    if ( !rmnet_shs_debug )
      goto LABEL_40;
    goto LABEL_39;
  }
  v45 = rmnet_shs_form_hash(*(unsigned __int16 *)(v6 + 208), v16, *(_DWORD *)(v14 + 152), v18, v11, v12, v13);
  if ( rmnet_shs_debug )
LABEL_39:
    v18 = *(unsigned int *)(v6 + 192);
LABEL_40:
  v19 = *(__int64 **)(v6 + 96);
  if ( !v19 )
    goto LABEL_84;
  v20 = a4;
  v21 = 0;
  v22 = v46;
  v23 = 0;
  v42 = v6;
  v24 = *(unsigned __int8 *)(*(_QWORD *)(v6 + 88) + 328LL);
  v43 = a3;
  _ReadStatusReg(SP_EL0);
  v41 = v6 + 96;
  while ( 2 )
  {
    v25 = v19;
    if ( *(_BYTE *)(v6 + 222) )
      *((_DWORD *)v19 + 38) = v45;
    v19 = (__int64 *)*v19;
    *v25 = 0;
    if ( v22 )
      ++rmnet_shs_no_sync_packets;
    v26 = *((_DWORD *)v25 + 28);
    if ( v24 && !*(_BYTE *)(v6 + 216) )
    {
      if ( *(_WORD *)(v6 + 220) == 17 )
        ++qword_1A470;
      v27 = v25[27] + *((unsigned int *)v25 + 53);
      v28 = *(unsigned __int16 *)(v27 + 6);
      if ( v28 > v24 )
      {
        v29 = *(_WORD *)(v27 + 4);
        v30 = *(_DWORD *)(v27 + 24);
        *(_WORD *)(v27 + 4) = v29 * v24;
        *(_WORD *)(v27 + 6) = (v24 - 1 + v28) / v24;
        v31 = _skb_gso_segment(v25, 1, 0, v18);
        if ( v31 && v31 < 0xFFFFFFFFFFFFF001LL )
        {
          if ( v24 == 1 )
          {
            v6 = v42;
          }
          else
          {
            v32 = v31;
            do
            {
              v33 = (unsigned __int16)v28;
              LOWORD(v28) = v28 - v24;
              v34 = *(_QWORD *)(v32 + 216) + *(unsigned int *)(v32 + 212);
              if ( v33 >= v24 )
                LOWORD(v33) = v24;
              *(_DWORD *)(v34 + 24) = v30;
              *(_WORD *)(v34 + 4) = v29;
              *(_WORD *)(v34 + 6) = v33;
              if ( (unsigned __int16)v28 < 2u )
                break;
              v32 = *(_QWORD *)v32;
            }
            while ( v32 );
            v6 = v42;
          }
          a3 = v43;
          do
          {
            while ( 1 )
            {
              v35 = *(_QWORD *)v31;
              *(_DWORD *)(v31 + 152) = *((_DWORD *)v25 + 38);
              v36 = v25[2];
              *(_QWORD *)v31 = 0;
              *(_QWORD *)(v31 + 16) = v36;
              if ( !v43 )
                break;
              netif_rx(v31);
              v31 = v35;
              if ( !v35 )
                goto LABEL_77;
            }
            netif_receive_skb(v31);
            v31 = v35;
          }
          while ( v35 );
LABEL_77:
          consume_skb(v25);
          v20 = a4;
          goto LABEL_44;
        }
        *(_WORD *)(v27 + 4) = v29;
        v6 = v42;
        v20 = a4;
        *(_WORD *)(v27 + 6) = v28;
      }
      a3 = v43;
      if ( v43 )
        netif_rx(v25);
      else
        netif_receive_skb(v25);
LABEL_44:
      v22 = v46;
      goto LABEL_45;
    }
    if ( a3 == 1 )
    {
      if ( !*(_BYTE *)(v6 + 216) )
      {
        rmnet_shs_deliver_skb_wq();
        goto LABEL_44;
      }
LABEL_43:
      ++qword_1A320;
      netif_rx(v25);
      goto LABEL_44;
    }
    if ( a3 )
      goto LABEL_43;
    if ( !*(_BYTE *)(v6 + 216) )
    {
      rmnet_shs_deliver_skb();
      goto LABEL_44;
    }
    if ( !v20 )
      goto LABEL_43;
    if ( *(_QWORD *)v20 )
    {
      **(_QWORD **)(*(_QWORD *)v20 + 8LL) = v25;
      *(_QWORD *)(*(_QWORD *)v20 + 8LL) = v25;
    }
    else
    {
      v25[1] = (__int64)v25;
      *(_QWORD *)v20 = v25;
    }
LABEL_45:
    ++v23;
    v21 += v26;
    if ( v19 )
      continue;
    break;
  }
  v4 = v41;
LABEL_84:
  v37 = rmnet_shs_debug;
  *(_DWORD *)(v4 + 24) = 0;
  *(_QWORD *)(v4 + 8) = 0;
  *(_QWORD *)(v4 + 16) = 0;
  *(_QWORD *)v4 = 0;
  if ( v37 )
    return 1;
  else
    return 1;
}
