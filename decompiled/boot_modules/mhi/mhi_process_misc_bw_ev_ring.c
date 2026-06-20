__int64 __fastcall mhi_process_misc_bw_ev_ring(__int64 a1, __int64 a2)
{
  __int64 *v4; // x9
  unsigned int v5; // w8
  unsigned int v6; // w24
  __int64 result; // x0
  __int64 v8; // x21
  __int64 v9; // x23
  __int64 v10; // x22
  unsigned __int64 v11; // x21
  unsigned __int64 v12; // x8
  __int64 v13; // x11
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x12
  __int64 v17; // x14
  __int64 v18; // x11
  unsigned __int64 v19; // x12
  unsigned __int64 v20; // x8
  bool v21; // cf
  _QWORD *v22; // x11
  unsigned __int64 v23; // x8
  unsigned int v24; // w8
  unsigned int v25; // w4
  __int64 v26; // x9
  int v27; // w5
  int v28; // w3
  __int64 v29; // x8
  void (__fastcall *v30)(_QWORD); // x8
  __int64 (__fastcall *v31)(__int64, __int64 *); // x8
  unsigned int v32; // w0
  unsigned int v33; // w21
  int v34; // w10
  int v35; // w23
  __int64 v36; // x22
  int v37; // w3
  void (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x8
  int v40; // w3
  unsigned int v41; // w19
  __int64 v42; // x21
  __int64 v43; // x8
  __int64 v44; // [xsp+8h] [xbp-18h] BYREF
  int v45; // [xsp+10h] [xbp-10h]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a1 + 264);
  v5 = *(_DWORD *)(a1 + 344);
  v6 = *(_DWORD *)(a2 + 16);
  result = 4294967274LL;
  v8 = *v4;
  v45 = 0;
  v44 = 0;
  if ( v5 > 7 || ((1 << v5) & 0x94) == 0 )
  {
LABEL_44:
    v39 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v39 && !*(_DWORD *)(v39 + 24) )
    {
      v40 = *(_DWORD *)(a2 + 16);
      v41 = result;
      ipc_log_string(
        *(_QWORD *)(v39 + 32),
        "[D][%s] exit er_index:%u ret:%d\n",
        "mhi_process_misc_bw_ev_ring",
        v40,
        result);
      result = v41;
    }
    goto LABEL_47;
  }
  v9 = *(_QWORD *)(a1 + 16);
  v10 = *(_QWORD *)(v9 + 192);
  raw_spin_lock_bh(a2 + 240);
  v11 = *(_QWORD *)(v8 + 44LL * v6 + 28);
  v12 = *(_QWORD *)(a2 + 48);
  if ( v11 < v12 || (v11 & 0xF) != 0 || (v13 = *(_QWORD *)(a2 + 104), v13 + v12 <= v11) )
  {
    v36 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v9 + 40, "[E][%s] bw event ring pointer is invalid rp: %llx\n", "mhi_process_misc_bw_ev_ring", v11);
    if ( v36 && *(_DWORD *)(v36 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v36 + 32),
        "[E][%s] bw event ring pointer is invalid rp: %llx\n",
        "mhi_process_misc_bw_ev_ring",
        v11);
LABEL_36:
    raw_spin_unlock_bh(a2 + 240);
    result = 4294967274LL;
    goto LABEL_44;
  }
  v14 = *(_QWORD *)(a2 + 72);
  v15 = v14 + v11 - v12;
  if ( *(_QWORD *)(a2 + 80) != v15 )
  {
    if ( v11 == v12 )
      v15 = v14 + v13;
    v16 = v15 - 32;
    *(_QWORD *)(a2 + 80) = v15 - 16;
    v17 = *(_QWORD *)(a2 + 96);
    if ( v15 - 32 < v14 )
      v16 = v14 + v13 - v17;
    v19 = v16 + v17;
    v20 = v12 - v14;
    v21 = v19 >= v14 + v13;
    v22 = *(_QWORD **)(a2 + 56);
    if ( !v21 )
      v14 = v19;
    *(_QWORD *)(a2 + 88) = v14;
    *v22 = v20 + v14;
    v23 = *(_QWORD *)(a2 + 80) + *(_QWORD *)(a2 + 96);
    if ( v23 >= *(_QWORD *)(a2 + 72) + *(_QWORD *)(a2 + 104) )
      v23 = *(_QWORD *)(a2 + 72);
    *(_QWORD *)(a2 + 80) = v23;
    __dmb(0xAu);
    v24 = *(_DWORD *)(v15 - 4);
    if ( (v24 & 0xFF0000) == 0x500000 )
    {
      v25 = HIBYTE(v24);
      v26 = *(_QWORD *)(a1 + 16);
      LODWORD(v44) = HIBYTE(v24);
      v27 = (unsigned __int8)*(_DWORD *)(v15 - 8);
      v28 = (unsigned __int8)BYTE1(*(_DWORD *)(v15 - 8));
      v29 = *(_QWORD *)(v26 + 192);
      HIDWORD(v44) = v27;
      v45 = v28;
      if ( v29 && !*(_DWORD *)(v29 + 24) )
        ipc_log_string(
          *(_QWORD *)(v29 + 32),
          "[D][%s] Received BW_REQ with seq:%d link speed:0x%x width:0x%x\n",
          "mhi_process_misc_bw_ev_ring",
          v28,
          v25,
          v27);
      raw_read_lock_bh(a1 + 320);
      if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 )
        mhi_ring_er_db((__int64 *)a2);
      raw_read_unlock_bh(a1 + 320);
      raw_spin_unlock_bh(a2 + 240);
      result = mhi_device_get_sync(*(_QWORD *)(a1 + 16));
      if ( !(_DWORD)result )
      {
        v30 = *(void (__fastcall **)(_QWORD))(a1 + 512);
        if ( *((_DWORD *)v30 - 1) != -700558418 )
          __break(0x8228u);
        v30(a1);
        mutex_lock(a1 + 272);
        v31 = *(__int64 (__fastcall **)(__int64, __int64 *))(v10 + 72);
        if ( *((_DWORD *)v31 - 1) != -241154051 )
          __break(0x8228u);
        v32 = v31(a1, &v44);
        if ( v32 == -22 )
        {
          v33 = -22;
          v35 = 256;
        }
        else
        {
          v33 = v32;
          if ( v32 )
          {
            v35 = 3840;
          }
          else
          {
            v34 = v45;
            v35 = 0;
            *(_QWORD *)(a1 + 400) = v44;
            *(_DWORD *)(a1 + 408) = v34;
          }
        }
        raw_write_lock_bh(a1 + 320);
        v37 = v45;
        *(_DWORD *)(v10 + 92) = (unsigned __int8)v45 | v35;
        if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 )
        {
          mhi_write_reg(a1);
          *(_DWORD *)(v10 + 92) = 0;
        }
        else
        {
          v43 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          if ( v43 && !*(_DWORD *)(v43 + 24) )
            ipc_log_string(
              *(_QWORD *)(v43 + 32),
              "[D][%s] Cached BW response for seq: %u, result: %d\n",
              "mhi_process_misc_bw_ev_ring",
              v37,
              *(_DWORD *)(v43 + 92));
        }
        raw_write_unlock_bh(a1 + 320);
        v38 = *(void (__fastcall **)(_QWORD))(a1 + 528);
        if ( *((_DWORD *)v38 - 1) != -2145957670 )
          __break(0x8228u);
        v38(a1);
        mhi_device_put(*(_QWORD *)(a1 + 16));
        mutex_unlock(a1 + 272);
        result = v33;
      }
      goto LABEL_44;
    }
    __break(0x800u);
    v42 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v9 + 40, "[E][%s] !BW SCALE REQ event\n", "mhi_process_misc_bw_ev_ring");
    if ( v42 && *(_DWORD *)(v42 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v42 + 32), "[E][%s] !BW SCALE REQ event\n", "mhi_process_misc_bw_ev_ring");
    goto LABEL_36;
  }
  v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v18 && !*(_DWORD *)(v18 + 24) )
    ipc_log_string(
      *(_QWORD *)(v18 + 32),
      "[D][%s] Ignore BW event:0x%llx ev_ring RP:0x%llx\n",
      "mhi_process_misc_bw_ev_ring",
      *(_QWORD *)(v14 + v11 - v12),
      v11);
  raw_spin_unlock_bh(a2 + 240);
  result = 0;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
