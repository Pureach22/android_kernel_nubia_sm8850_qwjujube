__int64 __fastcall ce_recv_buf_enqueue_srng(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  __int64 v4; // x20
  int v8; // w26
  unsigned __int64 StatusReg; // x8
  unsigned int v10; // w25
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x9
  unsigned int v24; // w10
  unsigned int v25; // w11
  unsigned int v26; // w12
  unsigned int v27; // w11
  __int64 v28; // x22
  int v29; // w8
  __int64 v30; // x23
  unsigned int v31; // w25
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x10

  v3 = *(_QWORD *)(a1 + 144);
  v4 = *(_QWORD *)a1;
  v8 = *(_DWORD *)(v3 + 4);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 168);
  }
  else
  {
    raw_spin_lock_bh(a1 + 168);
    *(_QWORD *)(a1 + 176) |= 1uLL;
  }
  v10 = *(_DWORD *)(v3 + 12);
  if ( (hif_target_sleep_state_adjust(v4) & 0x80000000) == 0 )
  {
    if ( (unsigned int)hal_srng_access_start_1(*(_QWORD *)(v4 + 2560)) )
    {
      v19 = *(_QWORD *)(a1 + 176);
      if ( (v19 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 176) = v19 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 168);
      }
      else
      {
        raw_spin_unlock(a1 + 168);
      }
      return 16;
    }
    v22 = *(_QWORD *)(v3 + 80);
    v23 = *(unsigned int *)(v22 + 120);
    v24 = *(_DWORD *)(v22 + 136);
    if ( v24 <= (unsigned int)v23 )
      v25 = v24 - v23 + *(_DWORD *)(v22 + 36);
    else
      v25 = v24 - v23;
    v26 = *(_DWORD *)(v22 + 44);
    if ( v25 / v26 == 1 || (v27 = (v26 + (unsigned int)v23) % *(_DWORD *)(v22 + 36), v27 == v24) )
    {
      v28 = 0;
    }
    else
    {
      v34 = *(_QWORD *)(v22 + 16);
      *(_DWORD *)(v22 + 120) = v27;
      *(_DWORD *)(v22 + 124) = v27;
      v28 = v34 + 4 * v23;
      if ( v28 )
      {
        *(_DWORD *)v28 = a3;
        v29 = 0;
        *(_BYTE *)(v28 + 4) = BYTE4(a3);
        *(_QWORD *)(*(_QWORD *)(v3 + 88) + 8LL * v10) = a2;
        v10 = (v10 + 1) & v8;
LABEL_20:
        v30 = *(_QWORD *)(v3 + 80);
        *(_DWORD *)(v3 + 12) = v10;
        v31 = v29;
        if ( !v30 )
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Error: Invalid hal_ring\n",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "hal_srng_access_end");
          goto LABEL_24;
        }
        if ( (*(_DWORD *)(v30 + 76) & 0x80000000) != 0 )
        {
          **(_DWORD **)(v30 + 144) = *(_DWORD *)(v30 + 120);
          v32 = *(_QWORD *)(v30 + 88);
          if ( (v32 & 1) == 0 )
            goto LABEL_23;
        }
        else
        {
          hal_delayed_reg_write(
            *(_QWORD *)(v4 + 2560),
            (unsigned __int8 *)v30,
            *(_QWORD *)(v30 + 144),
            *(_DWORD *)(v30 + 120));
          v32 = *(_QWORD *)(v30 + 88);
          if ( (v32 & 1) == 0 )
          {
LABEL_23:
            raw_spin_unlock(v30 + 80);
LABEL_24:
            ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, _QWORD))hif_record_ce_srng_desc_event)(
              v4,
              *(unsigned int *)(a1 + 8),
              36,
              v28,
              a2,
              *(unsigned int *)(v3 + 12));
            hif_target_sleep_state_adjust(v4);
            v33 = *(_QWORD *)(a1 + 176);
            if ( (v33 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 176) = v33 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 168);
            }
            else
            {
              raw_spin_unlock(a1 + 168);
            }
            return v31;
          }
        }
        *(_QWORD *)(v30 + 88) = v32 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v30 + 80);
        goto LABEL_24;
      }
    }
    v29 = 16;
    goto LABEL_20;
  }
  v21 = *(_QWORD *)(a1 + 176);
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 176) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 168);
  }
  else
  {
    raw_spin_unlock(a1 + 168);
  }
  return 23;
}
