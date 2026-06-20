__int64 __fastcall ucfg_dp_create_intf(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 context; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  int v28; // w9
  unsigned __int64 StatusReg; // x8
  unsigned int v30; // w8
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  __int64 result; // x0
  int v36; // w10
  __int64 v37; // x8
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  context = dp_get_context();
  if ( a2 )
  {
    v14 = *a2;
    v15 = a2[1];
    v16 = a2[2];
    v17 = a2[5];
  }
  else
  {
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v17 = 0;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: DP interface create addr:%02x:%02x:%02x:**:**:%02x",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "ucfg_dp_create_intf",
    v14,
    v15,
    v16,
    v17);
  v18 = _qdf_mem_malloc(0xF28u, "ucfg_dp_create_intf", 212);
  if ( v18 )
  {
    *(_QWORD *)(v18 + 3664) = 0;
    v27 = v18;
    *(_QWORD *)v18 = context;
    *(_QWORD *)(v18 + 56) = a3;
    v28 = *(_DWORD *)a2;
    *(_WORD *)(v18 + 24) = *((_WORD *)a2 + 2);
    *(_DWORD *)(v18 + 20) = v28;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(context + 264);
      if ( (*(_QWORD *)(context + 360) & 1) == 0 )
      {
LABEL_9:
        v30 = 0;
LABEL_25:
        *(_BYTE *)(v27 + 48) = v30;
        v36 = *(_DWORD *)(context + 352) + 1;
        *(_QWORD *)(context + 360) |= 1LL << v30;
        *(_DWORD *)(context + 352) = v36;
        *(_DWORD *)(v27 + 52) = v36;
        *(_QWORD *)(context + 8LL * v30 + 304) = v27;
        qdf_list_insert_front((_QWORD *)(context + 280), (_QWORD *)(v27 + 32));
        v37 = *(_QWORD *)(context + 272);
        if ( (v37 & 1) != 0 )
        {
          *(_QWORD *)(context + 272) = v37 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(context + 264);
        }
        else
        {
          raw_spin_unlock(context + 264);
        }
        *(_DWORD *)(v27 + 3672) = 0;
        *(_QWORD *)(v27 + 3680) = 0;
        *(_QWORD *)(v27 + 3688) = v27 + 3688;
        *(_QWORD *)(v27 + 3696) = v27 + 3688;
        *(_QWORD *)(v27 + 3704) = 0;
        dp_nud_init_tracking(v27);
        dp_mic_init_work(v27);
        result = 0;
        *(_DWORD *)(context + 876) = 0;
        *(_DWORD *)(v27 + 3584) = 0;
        return result;
      }
    }
    else
    {
      raw_spin_lock_bh(context + 264);
      *(_QWORD *)(context + 272) |= 1uLL;
      if ( (*(_QWORD *)(context + 360) & 1) == 0 )
        goto LABEL_9;
    }
    if ( (*(_QWORD *)(context + 360) & 2) == 0 )
    {
      v30 = 1;
      goto LABEL_25;
    }
    if ( (*(_QWORD *)(context + 360) & 4) == 0 )
    {
      v30 = 2;
      goto LABEL_25;
    }
    if ( (*(_QWORD *)(context + 360) & 8) == 0 )
    {
      v30 = 3;
      goto LABEL_25;
    }
    if ( (*(_QWORD *)(context + 360) & 0x10) == 0 )
    {
      v30 = 4;
      goto LABEL_25;
    }
    if ( (*(_QWORD *)(context + 360) & 0x20) == 0 )
    {
      v30 = 5;
      goto LABEL_25;
    }
    v38 = *(_QWORD *)(context + 272);
    if ( (v38 & 1) != 0 )
    {
      *(_QWORD *)(context + 272) = v38 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(context + 264);
    }
    else
    {
      raw_spin_unlock(context + 264);
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Max dp interface already created",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "ucfg_dp_create_intf");
    _qdf_mem_free(v27);
    return 4;
  }
  else
  {
    if ( a2 )
    {
      v31 = *a2;
      v32 = a2[1];
      v33 = a2[2];
      v34 = a2[5];
    }
    else
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
      v34 = 0;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP intf memory alloc failed addr:%02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ucfg_dp_create_intf",
      v31,
      v32,
      v33,
      v34);
    return 16;
  }
}
