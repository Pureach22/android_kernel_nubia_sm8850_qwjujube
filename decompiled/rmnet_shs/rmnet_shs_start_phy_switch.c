__int64 __fastcall rmnet_shs_start_phy_switch(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v5; // w0
  __int16 v6; // w0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned __int8 v14; // w21
  char v15; // w1
  unsigned __int64 v16; // x8
  unsigned int v17; // w20
  char *v18; // x8
  int v19; // w21
  int v20; // w22
  __int64 result; // x0
  char *v22; // x9
  unsigned int v23; // w8
  unsigned int v24; // w8
  char *v25; // x0
  _QWORD v26[16]; // [xsp+0h] [xbp-80h] BYREF

  v26[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_BYTE *)(a1 + 216) = 1;
  v5 = *(_WORD *)(a2 + 2);
  *(_WORD *)(a1 + 212) = v5;
  *(_WORD *)(a1 + 214) = rmnet_shs_get_mask_len(v5);
  v6 = BYTE2(dword_19499);
  *(_WORD *)(a1 + 218) = 0;
  *(_WORD *)(a1 + 210) = v6;
  *(_WORD *)(a1 + 208) = v6;
  if ( (unsigned int)rmnet_shs_is_lpwr_cpu(v6) && !(unsigned int)rmnet_shs_is_lpwr_cpu(dword_19499) )
  {
    rmnet_shs_boost_gold_cpu((unsigned __int8)dword_19499);
    rmnet_shs_boost_cpus();
  }
  v14 = dword_19499;
  memset(&v26[8], 0, 56);
  if ( (unsigned int)rmnet_is_real_dev_registered(a3, v7, v8, v9, v10, v11, v12, v13, 0, 0, 0, 0, 0, 0, 0, 0) )
  {
    if ( !change_rps(*(_QWORD *)(a3 + 232), v14) )
    {
      v15 = BYTE2(dword_19499);
      BYTE2(dword_19499) = v14;
      BYTE1(dword_19499) = v15;
      byte_19496 = 1 << v14;
      rmnet_shs_create_phy_msg_resp(v26);
      rmnet_shs_genl_msg_direct_send_to_userspace(v26);
    }
  }
  else
  {
    ++qword_1A480;
  }
  v16 = *(unsigned __int16 *)(a1 + 210);
  if ( v16 >= 0x20 )
    goto LABEL_29;
  v17 = *(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v16] + 256)
      + *(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v16] + 32);
  if ( v17 > rmnet_shs_max_phy_backlog )
    rmnet_shs_max_phy_backlog = *(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v16] + 256)
                              + *(_DWORD *)((char *)&softnet_data + _per_cpu_offset[v16] + 32);
  *(_DWORD *)(a1 + 188) = rmnet_shs_get_cpu_qtail(dword_19499) + v17;
  if ( (unsigned __int8)dword_19499 > 0x1FuLL )
    goto LABEL_29;
  v18 = (char *)&softnet_data + _per_cpu_offset[(unsigned __int8)dword_19499];
  v19 = *((_DWORD *)v18 + 8);
  v20 = *((_DWORD *)v18 + 64);
  if ( (unsigned int)rmnet_shs_is_lpwr_cpu(*(_WORD *)(a1 + 210)) )
  {
    if ( *(unsigned __int16 *)(a1 + 210) > 7uLL )
      goto LABEL_29;
    result = hrtimer_active((char *)&rmnet_shs_cfg + 120 * *(unsigned __int16 *)(a1 + 210) + 368);
    if ( (result & 1) == 0 )
    {
      if ( *(unsigned __int16 *)(a1 + 210) <= 7uLL )
      {
        v22 = (char *)&rmnet_shs_cfg + 120 * *(unsigned __int16 *)(a1 + 210);
        v23 = rmnet_shs_max_qmap_wait;
LABEL_26:
        v25 = v22 + 368;
        goto LABEL_27;
      }
      goto LABEL_29;
    }
  }
  else
  {
    v24 = *(unsigned __int16 *)(a1 + 210);
    if ( v19 + v17 + v20 > 4 )
    {
      if ( v24 > 7 )
        goto LABEL_29;
      result = hrtimer_active((char *)&rmnet_shs_cfg + 120 * *(unsigned __int16 *)(a1 + 210) + 368);
      if ( (result & 1) == 0 )
      {
        if ( *(unsigned __int16 *)(a1 + 210) <= 7uLL )
        {
          v22 = (char *)&rmnet_shs_cfg + 120 * *(unsigned __int16 *)(a1 + 210);
          v23 = (unsigned int)rmnet_shs_max_qmap_wait >> 1;
          goto LABEL_26;
        }
LABEL_29:
        __break(0x5512u);
      }
    }
    else
    {
      if ( v24 > 7 )
        goto LABEL_29;
      result = hrtimer_active((char *)&rmnet_shs_cfg + 120 * *(unsigned __int16 *)(a1 + 210) + 368);
      if ( (result & 1) == 0 )
      {
        if ( *(unsigned __int16 *)(a1 + 210) <= 7uLL )
        {
          v23 = rmnet_shs_max_qmap_wait / 0x14u;
          v25 = (char *)&rmnet_shs_cfg + 120 * *(unsigned __int16 *)(a1 + 210) + 368;
LABEL_27:
          result = hrtimer_start_range_ns(v25, 1000000 * v23, 0, 1);
          goto LABEL_28;
        }
        goto LABEL_29;
      }
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
