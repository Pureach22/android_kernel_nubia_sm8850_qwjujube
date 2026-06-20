__int64 __fastcall rmnet_shs_ll_handler(__int64 a1, unsigned __int64 a2)
{
  char v2; // w10
  unsigned __int8 v3; // w21
  int v4; // w22
  int v7; // w20
  int v8; // w28
  __int64 v9; // x8
  __int64 v10; // x20
  __int64 *v12; // x8
  __int64 v13; // x8
  char v14; // w0
  int v15; // w11
  __int16 v16; // w9
  __int64 v17; // x10
  __int16 v18; // w0
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x4
  unsigned __int64 v28; // x8
  __int64 v29; // x10
  unsigned __int64 *v30; // x10
  unsigned __int64 v31; // x8
  __int64 v32; // x1
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int16 v38; // w9
  unsigned __int8 v39; // w8
  __int64 v40; // x8
  char v41; // w8
  __int64 v42; // x8
  int v43; // w8
  __int64 v44; // x10
  __int64 v45; // x8
  __int64 v46; // x10
  unsigned __int64 v47; // x27
  __int64 v48; // x28
  __int64 v49; // x0
  unsigned __int64 v56; // x9

  v2 = *(_BYTE *)(a1 + 130);
  v3 = byte_19497;
  v4 = rmnet_shs_ll_flow_cpu;
  ++rmnet_shs_ll_pkts;
  if ( (v2 & 6) == 0 )
    _skb_get_hash_net(0, a1);
  v7 = *(_DWORD *)(a1 + 152);
  if ( (*(_WORD *)a2 & 1) == 0 && !(unsigned int)rmnet_shs_is_ll_skb_stamping_reqd(a1) )
    goto LABEL_60;
  v8 = v7 ^ 3;
  raw_spin_lock_bh(&rmnet_shs_ll_ht_splock);
  v9 = rmnet_shs_ll_ht[(1640531527 * (v7 ^ 3u)) >> 23];
  v10 = v9 - 128;
  if ( v9 )
    _ZF = v9 == 128;
  else
    _ZF = 1;
  if ( !_ZF )
  {
    do
    {
      if ( v8 == *(_DWORD *)(v10 + 192) )
      {
        v14 = rmnet_shs_ll_flow_cpu;
        *(_WORD *)(v10 + 210) = rmnet_shs_ll_flow_cpu;
        *(_WORD *)(v10 + 208) = rmnet_shs_idx_from_cpu(v14, v3);
        goto LABEL_27;
      }
      v13 = *(_QWORD *)(v10 + 128);
      if ( !v13 )
        break;
      v10 = v13 - 128;
    }
    while ( v13 != 128 );
  }
  if ( v4 < 0 )
  {
    v12 = &qword_1A438;
    goto LABEL_59;
  }
  if ( qword_19470 > 700 )
  {
    v12 = &qword_1A3E8;
LABEL_59:
    ++*v12;
    raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
    goto LABEL_60;
  }
  v10 = _kmalloc_cache_noprof(_rcu_read_unlock, 2336, 232);
  if ( !v10 )
  {
LABEL_58:
    v12 = &qword_1A3D8;
    goto LABEL_59;
  }
  while ( 1 )
  {
    _X8 = &qword_19470;
    __asm { PRFM            #0x11, [X8] }
    do
      v56 = __ldxr((unsigned __int64 *)&qword_19470);
    while ( __stxr(v56 + 1, (unsigned __int64 *)&qword_19470) );
    v15 = *(_DWORD *)(a1 + 152);
    v16 = (unsigned __int8)byte_19497;
    v17 = *(_QWORD *)(a1 + 16);
    *(_WORD *)(v10 + 212) = *(_WORD *)(a2 + 2);
    *(_DWORD *)(v10 + 192) = v15 ^ 3;
    *(_WORD *)(v10 + 214) = v16;
    *(_QWORD *)(v10 + 80) = v17;
    *(_WORD *)(v10 + 210) = v4;
    *(_BYTE *)(v10 + 223) = 3;
    v18 = rmnet_shs_idx_from_cpu(v4, v3);
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_WORD *)(v10 + 208) = v18;
    *(_WORD *)(v10 + 210) = *(_DWORD *)(StatusReg + 40);
    *(_QWORD *)(v10 + 64) = v10 + 64;
    *(_QWORD *)(v10 + 72) = v10 + 64;
    rmnet_shs_get_update_skb_hdr_info(a1, v10);
    *(_BYTE *)(v10 + 225) = rmnet_shs_is_skb_l4s(a1, v20, v21, v22, v23);
    *(_BYTE *)(v10 + 226) = rmnet_shs_is_skb_ecn_capable(a1, v24, v25, v26, v27);
    rmnet_shs_wq_create_new_flow(v10);
    v28 = *(unsigned __int16 *)(v10 + 210);
    if ( v28 > 8 )
      goto LABEL_57;
    v29 = *(_QWORD *)(v10 + 80);
    if ( v29 == -2688 )
      ++rmnet_shs_crit_err;
    else
      *(_BYTE *)(*(_QWORD *)(v10 + 88) + 324LL) = *(_BYTE *)(v29 + 2688);
    rmnet_shs_cpu_node_add(v10, (unsigned __int64 *)&rmnet_shs_ll_cpu_node_tbl[5 * (unsigned int)v28]);
    v30 = &rmnet_shs_ll_ht[(unsigned int)(1640531527 * *(_DWORD *)(v10 + 192)) >> 23];
    v31 = *v30;
    *(_QWORD *)(v10 + 128) = *v30;
    *(_QWORD *)(v10 + 136) = v30;
    atomic_store(v10 + 128, v30);
    if ( v31 )
      *(_QWORD *)(v31 + 8) = v10 + 128;
LABEL_27:
    raw_spin_unlock_bh(&rmnet_shs_ll_ht_splock);
    v38 = *(_WORD *)(v10 + 212);
    if ( v38 )
    {
      v39 = *(_BYTE *)(v10 + 214);
      if ( !(_BYTE)v38 )
        goto LABEL_30;
LABEL_29:
      *(_DWORD *)(a1 + 152) = rmnet_shs_form_hash(
                                *(unsigned __int16 *)(v10 + 208),
                                v39,
                                *(_DWORD *)(v10 + 192),
                                0,
                                v35,
                                v36,
                                v37);
      goto LABEL_30;
    }
    v39 = byte_19498;
    if ( byte_19497 )
      goto LABEL_29;
LABEL_30:
    if ( *(_BYTE *)(v10 + 224) )
    {
      if ( *(_BYTE *)(v10 + 224) == 2 )
        goto LABEL_47;
      goto LABEL_32;
    }
    a2 = _ReadStatusReg(SP_EL0);
    if ( (unsigned int)rmnet_shs_is_lpwr_cpu(*(_DWORD *)(a2 + 40)) )
      break;
    if ( *(_BYTE *)(v10 + 224) == 2 )
      goto LABEL_47;
LABEL_32:
    a2 = _ReadStatusReg(SP_EL0);
    if ( (unsigned int)rmnet_shs_is_lpwr_cpu(*(_DWORD *)(a2 + 40)) )
      goto LABEL_47;
    v40 = *(unsigned int *)(a2 + 40);
    if ( (unsigned int)v40 <= 0x1F )
    {
      if ( (unsigned int)(*(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v40] + 32)
                        + *(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v40] + 256)) > 0x13 )
      {
        v41 = 2;
        goto LABEL_46;
      }
LABEL_41:
      v43 = *(_DWORD *)(a1 + 129);
      *(_DWORD *)(a1 + 152) = 0;
      *(_DWORD *)(a1 + 129) = v43 | 0x400;
      goto LABEL_47;
    }
LABEL_57:
    __break(0x5512u);
    v47 = _ReadStatusReg(SP_EL0);
    v48 = *(_QWORD *)(v47 + 80);
    v49 = _rcu_read_unlock;
    *(_QWORD *)(v47 + 80) = &rmnet_shs_ll_handler__alloc_tag;
    v10 = _kmalloc_cache_noprof(v49, 2336, 232);
    *(_QWORD *)(v47 + 80) = v48;
    if ( !v10 )
      goto LABEL_58;
  }
  v42 = *(unsigned int *)(a2 + 40);
  if ( (unsigned int)v42 > 0x1F )
    goto LABEL_57;
  if ( (unsigned int)(*(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v42] + 32)
                    + *(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v42] + 256)) <= 0x13 )
    goto LABEL_41;
  if ( !*(_BYTE *)(v10 + 224) )
  {
    v41 = 1;
LABEL_46:
    *(_BYTE *)(v10 + 224) = v41;
    *(_WORD *)(v10 + 210) = v4;
    *(_WORD *)(v10 + 208) = rmnet_shs_idx_from_cpu(v4, v3);
  }
LABEL_47:
  v44 = *(_QWORD *)(v10 + 152);
  if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL) <= 1u )
    v45 = 1;
  else
    v45 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 6LL);
  *(_QWORD *)(v10 + 144) += v45;
  *(_QWORD *)(v10 + 152) = v44 + 1;
  v46 = *(_QWORD *)(v10 + 176);
  *(_QWORD *)(v10 + 168) += *(unsigned int *)(a1 + 44);
  *(_QWORD *)(v10 + 176) = v46 + *(unsigned int *)(a1 + 48);
  if ( *(_DWORD *)(a1 + 144) == 55834 )
  {
    ++*(_DWORD *)(v10 + 184);
    if ( !*(_BYTE *)(v10 + 225) )
      goto LABEL_55;
LABEL_52:
    if ( !*(_BYTE *)(v10 + 226) )
LABEL_56:
      *(_BYTE *)(v10 + 226) = rmnet_shs_is_skb_ecn_capable(a1, v32, v33, v34, v35);
  }
  else
  {
    if ( *(_BYTE *)(v10 + 225) )
      goto LABEL_52;
LABEL_55:
    *(_BYTE *)(v10 + 225) = rmnet_shs_is_skb_l4s(a1, v32, v33, v34, v35);
    if ( !*(_BYTE *)(v10 + 226) )
      goto LABEL_56;
  }
  *(_QWORD *)(v10 + 160) += *(unsigned int *)(a1 + 112);
LABEL_60:
  rmnet_shs_deliver_skb();
  return 0;
}
