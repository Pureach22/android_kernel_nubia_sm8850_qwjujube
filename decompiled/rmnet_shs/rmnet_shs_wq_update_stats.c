__int64 rmnet_shs_wq_update_stats()
{
  __int64 v0; // x0
  __int64 v1; // x0
  _QWORD *v2; // x22
  int v3; // w23
  __int64 v4; // x1
  __int64 halted_cpus; // x0
  int v6; // w10
  unsigned int v7; // w9
  int v8; // w11
  __int16 *v9; // x11
  __int64 *v10; // x20
  __int64 lock; // x0
  _UNKNOWN **v12; // x24
  __int64 v13; // x19
  void *v14; // x9
  _QWORD *v15; // x28
  void *v16; // x14
  void *v17; // x15
  int v18; // w11
  void *v19; // x10
  void *v20; // x8
  void *v21; // x9
  void *v22; // x16
  void *v23; // x17
  __int64 v24; // x14
  void *v25; // x0
  unsigned __int64 v26; // x15
  int v27; // w12
  void *v28; // x13
  void *v29; // x12
  void *v30; // x11
  void *v31; // x1
  unsigned __int64 v32; // x16
  unsigned __int64 v34; // x22
  unsigned __int64 v35; // x14
  __int64 v36; // x17
  void *v37; // x16
  unsigned __int64 v38; // x17
  unsigned __int64 v39; // x10
  __int64 unlock; // x0
  __int64 result; // x0
  _QWORD v42[16]; // [xsp+20h] [xbp-80h] BYREF

  v42[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ktime_get_with_offset(1);
  v1 = ns_to_timespec64(v0);
  v2 = rmnet_shs_flow_gold_to_silver;
  v3 = rmnet_shs_halt_mask;
  rmnet_shs_wq_tnsec = v4 + 1000000000 * v1;
  v42[0] = walt_get_cpus_taken();
  halted_cpus = walt_get_halted_cpus();
  if ( !rmnet_shs_reserve_on )
    goto LABEL_48;
  if ( (byte_19497 & 1) != 0 )
  {
    v6 = halted_cpus & 1;
    if ( (byte_19497 & 2) == 0 )
      goto LABEL_7;
  }
  else
  {
    v6 = 0;
    if ( (byte_19497 & 2) == 0 )
      goto LABEL_7;
  }
  if ( (halted_cpus & 2) == 0 )
  {
LABEL_7:
    v7 = v6;
    if ( (byte_19497 & 4) == 0 )
      goto LABEL_13;
    goto LABEL_10;
  }
  v7 = v6++ | 2;
  if ( (byte_19497 & 4) == 0 )
    goto LABEL_13;
LABEL_10:
  if ( (halted_cpus & 4) != 0 )
  {
    if ( (unsigned int)v6 > 1 )
      goto LABEL_32;
    ++v6;
    v7 |= 4u;
  }
LABEL_13:
  if ( (byte_19497 & 8) != 0 && (halted_cpus & 8) != 0 )
  {
    if ( (unsigned int)v6 > 1 )
      goto LABEL_32;
    ++v6;
    v7 |= 8u;
  }
  if ( (byte_19497 & 0x10) != 0 && (halted_cpus & 0x10) != 0 )
  {
    if ( (unsigned int)v6 > 1 )
      goto LABEL_32;
    ++v6;
    v7 |= 0x10u;
  }
  if ( (byte_19497 & 0x20) != 0 && (halted_cpus & 0x20) != 0 )
  {
    if ( (unsigned int)v6 > 1 )
      goto LABEL_32;
    ++v6;
    v7 |= 0x20u;
  }
  if ( (byte_19497 & 0x40) != 0 && (halted_cpus & 0x40) != 0 )
  {
    if ( (unsigned int)v6 <= 1 )
    {
      ++v6;
      v7 |= 0x40u;
      goto LABEL_29;
    }
LABEL_32:
    v8 = 0;
    ++qword_1A4C8;
    goto LABEL_40;
  }
LABEL_29:
  if ( byte_19497 < 0 && (halted_cpus & 0x80) != 0 )
  {
    if ( (unsigned int)v6 > 1 )
      goto LABEL_32;
    ++v6;
    v7 |= 0x80u;
  }
  if ( (unsigned int)v6 <= 1 )
  {
    if ( (byte_19497 & 1) != 0 && (v42[0] & 1) != 0 )
    {
      ++v6;
      v7 |= 1u;
      v8 = 1;
      if ( v6 > 1 )
        goto LABEL_40;
    }
    else
    {
      v8 = 0;
    }
    if ( (byte_19497 & 2) != 0 && (v42[0] & 2) != 0 )
    {
      ++v6;
      v8 |= 2u;
      v7 |= 2u;
    }
    if ( v6 <= 1 )
    {
      if ( (byte_19497 & 4) != 0 && (v42[0] & 4) != 0 )
      {
        ++v6;
        v8 |= 4u;
        v7 |= 4u;
      }
      if ( v6 <= 1 )
      {
        if ( (byte_19497 & 8) != 0 && (v42[0] & 8) != 0 )
        {
          ++v6;
          v8 |= 8u;
          v7 |= 8u;
        }
        if ( v6 <= 1 )
        {
          if ( (byte_19497 & 0x10) != 0 && (v42[0] & 0x10) != 0 )
          {
            ++v6;
            v8 |= 0x10u;
            v7 |= 0x10u;
          }
          if ( v6 <= 1 )
          {
            if ( (byte_19497 & 0x20) != 0 && (v42[0] & 0x20) != 0 )
            {
              ++v6;
              v8 |= 0x20u;
              v7 |= 0x20u;
            }
            if ( v6 <= 1 )
            {
              if ( (byte_19497 & 0x40) != 0 && (v42[0] & 0x40) != 0 )
              {
                ++v6;
                v8 |= 0x40u;
                v7 |= 0x40u;
              }
              if ( v6 <= 1 && byte_19497 < 0 && (v42[0] & 0x80) != 0 )
              {
                v8 |= 0x80u;
                v7 |= 0x80u;
              }
            }
          }
        }
      }
    }
    goto LABEL_40;
  }
  v8 = 0;
LABEL_40:
  if ( v3 != v7 )
    ++qword_1A2C0;
  rmnet_shs_halt_mask = v7;
  rmnet_shs_reserve_mask = v8;
  if ( ((v7 >> SBYTE2(dword_19499)) & 1) != 0 )
  {
    v9 = (word_1948E & 8) != 0 ? &word_1949D : (__int16 *)((char *)&word_1949D + 1);
    halted_cpus = rmnet_shs_wq_get_least_utilized_core((unsigned __int8)(*(_BYTE *)v9 & byte_19497) & ~(v7 | (unsigned __int8)byte_19496));
    if ( (int)halted_cpus >= 1 )
    {
      LOBYTE(dword_19499) = halted_cpus;
      ++qword_1A2B8;
      halted_cpus = rmnet_shs_switch_enable();
    }
  }
LABEL_48:
  if ( (word_1948E & 1) == 0 )
    goto LABEL_55;
  v42[0] = 0;
  halted_cpus = walt_get_cpus_in_state1(v42);
  if ( (v42[0] & 0x40 | v42[0] & 0x20) == 0x60 )
  {
    if ( HIBYTE(dword_19499) == 4 )
      goto LABEL_55;
    *(_WORD *)((char *)&dword_19499 + 3) = -25596;
    HIBYTE(word_1949D) = 99;
    qword_15CF8 = 0;
    qword_15D00 = 0;
    off_15CB8 = &unk_186A0;
    off_15CC0 = &unk_186A0;
    v10 = &qword_1A2A0;
  }
  else
  {
    if ( HIBYTE(dword_19499) == 2 )
      goto LABEL_55;
    *(_WORD *)((char *)&dword_19499 + 3) = -1022;
    HIBYTE(word_1949D) = 3;
    qword_15CF8 = 40000;
    qword_15D00 = 40000;
    off_15CB8 = (_UNKNOWN *)210000;
    off_15CC0 = (_UNKNOWN *)210000;
    v10 = &qword_1A2A8;
  }
  ++*v10;
LABEL_55:
  if ( (~rmnet_shs_wq_tick & 0x7F) == 0 )
  {
    memset(v42, 0, 120);
    rmnet_shs_create_phy_msg_resp(v42);
    halted_cpus = rmnet_shs_genl_msg_direct_send_to_userspace(v42);
  }
  lock = _rcu_read_lock(halted_cpus);
  v12 = (_UNKNOWN **)rmnet_shs_wq_hstat_tbl;
  if ( rmnet_shs_wq_hstat_tbl != (_UNKNOWN *)&rmnet_shs_wq_hstat_tbl )
  {
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( *((_BYTE *)v12 + 253) )
      {
        v13 = (__int64)v12[2];
        if ( v13 )
        {
          if ( v12 == (_UNKNOWN **)&unk_48 )
          {
            ++qword_1A448;
          }
          else if ( *(_UNKNOWN **)(v13 + 144) == v12[8] )
          {
            v12[14] = nullptr;
            v14 = v12[5];
            v12[11] = nullptr;
            v12[12] = nullptr;
            v12[7] = (_UNKNOWN *)(v2[157] - (_QWORD)v14);
            lock = rmnet_shs_wq_update_hash_stats_debug((__int64)(v12 - 9), v13);
          }
          else
          {
            v12[7] = nullptr;
            v15 = v2;
            v16 = *(void **)(*(_QWORD *)(v13 + 88) + 112LL);
            v12[6] = v16;
            v17 = *(void **)(*(_QWORD *)(v13 + 88) + 136LL);
            v12[22] = v17;
            v18 = *(_DWORD *)(*(_QWORD *)(v13 + 88) + 276LL);
            *((_DWORD *)v12 + 50) = v18;
            v19 = *(void **)(*(_QWORD *)(v13 + 88) + 152LL);
            v12[23] = v19;
            v20 = *(void **)(*(_QWORD *)(v13 + 88) + 232LL);
            v12[18] = v20;
            v21 = *(void **)(*(_QWORD *)(v13 + 88) + 240LL);
            v12[19] = v21;
            v22 = *(void **)(*(_QWORD *)(v13 + 88) + 144LL);
            v12[24] = v22;
            v23 = (void *)v2[157];
            v12[5] = v23;
            v24 = (_BYTE *)v23 - (_BYTE *)v16;
            v25 = *(void **)(v13 + 144);
            v12[8] = v25;
            v26 = (_BYTE *)v25 - (_BYTE *)v17;
            v27 = *(_DWORD *)(v13 + 184);
            *((_DWORD *)v12 + 51) = v27;
            *((_BYTE *)v12 + 251) = v27 != v18;
            *((_BYTE *)v12 + 250) = *(_BYTE *)(v13 + 223);
            v28 = *(void **)(v13 + 152);
            v12[10] = v28;
            v29 = *(void **)(v13 + 168);
            v12[20] = v29;
            v30 = *(void **)(v13 + 176);
            v12[21] = v30;
            v31 = *(void **)(v13 + 160);
            v12[9] = v31;
            v32 = 1000000000 * ((_BYTE *)v31 - (_BYTE *)v22);
            if ( v24 <= (unsigned int)(1000000 * rmnet_shs_wq_interval_ms) || rmnet_shs_wq_interval_ms == 0 )
              v34 = 100000000;
            else
              v34 = v24;
            v35 = 1000000000 * v26 / v34;
            v36 = 8 * (v32 / v34);
            v37 = v12[13];
            v12[11] = (_UNKNOWN *)v35;
            v12[12] = (_UNKNOWN *)v36;
            v38 = v35;
            if ( v37 )
              v38 = ((((unsigned __int64)v37 + (unsigned __int64)v12[14]) >> 1) * (unsigned __int16)rmnet_shs_wq_tuning
                   + v35 * (unsigned __int16)(100 - rmnet_shs_wq_tuning))
                  / ((unsigned __int16)rmnet_shs_wq_tuning + (unsigned int)(unsigned __int16)(100 - rmnet_shs_wq_tuning));
            v39 = (_BYTE *)v28 - (_BYTE *)v19;
            v12[14] = (_UNKNOWN *)v38;
            if ( v39 )
              v39 = v26 / v39;
            v12[13] = (_UNKNOWN *)v35;
            v12[15] = (_UNKNOWN *)v39;
            v12[16] = (_UNKNOWN *)((_BYTE *)v29 - (_BYTE *)v20);
            v12[17] = (_UNKNOWN *)((_BYTE *)v30 - (_BYTE *)v21);
            *((_WORD *)v12 + 123) = *(_WORD *)(v13 + 210);
            lock = rmnet_shs_wq_update_hash_stats_debug((__int64)(v12 - 9), v13);
            v2 = v15;
            *((_DWORD *)v12 + 58) = *(_DWORD *)(v13 + 196);
            *((_DWORD *)v12 + 59) = *(_DWORD *)(v13 + 200);
          }
        }
      }
      v12 = (_UNKNOWN **)*v12;
    }
    while ( v12 != &rmnet_shs_wq_hstat_tbl );
  }
  unlock = _rcu_read_unlock(lock);
  if ( rmnet_shs_userspace_connected )
  {
    ((void (__fastcall *)(__int64))rmnet_shs_wq_mem_update_global)(unlock);
    unlock = rmnet_shs_genl_send_int_to_userspace_no_info(828);
  }
  result = rmnet_shs_wq_filter(unlock);
  _ReadStatusReg(SP_EL0);
  return result;
}
