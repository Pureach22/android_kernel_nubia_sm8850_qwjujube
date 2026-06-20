__int64 __fastcall htc_add_receive_pkt_multiple(__int64 a1, __int64 a2)
{
  int v2; // w5
  __int64 v3; // x20
  int v5; // w4
  __int64 v6; // x21
  _DWORD *v7; // x25
  unsigned __int64 StatusReg; // x8
  int v9; // w22
  __int64 v10; // x8
  unsigned int v11; // w20
  __int64 v12; // x2
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x0
  __int64 *v17; // x24
  __int64 v18; // x8
  _QWORD *v19; // x9
  void (__fastcall *v20)(__int64, __int64 *); // x8
  __int64 v21; // x0

  v2 = *(_DWORD *)(a2 + 16);
  if ( !v2 || (v3 = *(_QWORD *)(a2 + 8)) == 0 )
  {
    v12 = 552;
LABEL_17:
    printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_recv.c", v12, "false");
    return 14;
  }
  v5 = *(_DWORD *)(v3 + 48);
  if ( v5 > 8 )
  {
    v12 = 557;
    goto LABEL_17;
  }
  v6 = a1;
  if ( (dword_B804 & 0x200) != 0 )
  {
    a1 = qdf_trace_msg(
           56,
           2,
           "%s: +- htc_add_receive_pkt_multiple : endPointId: %d, cnt:%d, length: %d\n",
           "htc_add_receive_pkt_multiple",
           v5,
           v2,
           *(_DWORD *)(v3 + 40));
    v5 = *(_DWORD *)(v3 + 48);
  }
  if ( (unsigned int)v5 < 0xA )
  {
    v7 = (_DWORD *)(v6 + 328LL * (unsigned int)v5 + 8);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v6 + 2976);
      v9 = *(_DWORD *)(v6 + 3008);
      if ( (v9 & 1) == 0 )
        goto LABEL_11;
    }
    else
    {
      raw_spin_lock_bh(v6 + 2976);
      *(_QWORD *)(v6 + 2984) |= 1uLL;
      v9 = *(_DWORD *)(v6 + 3008);
      if ( (v9 & 1) == 0 )
      {
LABEL_11:
        if ( *(_QWORD *)a2 != a2 || *(_QWORD *)(a2 + 8) != a2 )
        {
          *(_QWORD *)(*(_QWORD *)a2 + 8LL) = v7 + 62;
          v10 = *((_QWORD *)v7 + 31);
          **(_QWORD **)(a2 + 8) = v10;
          *(_QWORD *)(v10 + 8) = *(_QWORD *)(a2 + 8);
          *((_QWORD *)v7 + 31) = *(_QWORD *)a2;
          *(_QWORD *)a2 = a2;
          *(_QWORD *)(a2 + 8) = a2;
        }
        v11 = 0;
        v7[66] += *(_DWORD *)(a2 + 16);
        *(_DWORD *)(a2 + 16) = 0;
LABEL_20:
        v13 = *(_QWORD *)(v6 + 2984);
        if ( (v13 & 1) != 0 )
        {
          *(_QWORD *)(v6 + 2984) = v13 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v6 + 2976);
          if ( (v9 & 1) != 0 )
            goto LABEL_22;
        }
        else
        {
          raw_spin_unlock(v6 + 2976);
          if ( (v9 & 1) != 0 )
          {
LABEL_22:
            v14 = *(_QWORD *)(a2 + 8);
            if ( v14 != a2 )
            {
              do
              {
                v15 = *(_QWORD *)(v14 + 8);
                *(_DWORD *)(v14 + 52) = 9;
                v14 = v15;
              }
              while ( v15 != a2 );
            }
            while ( *(_DWORD *)(a2 + 16) )
            {
              v17 = *(__int64 **)(a2 + 8);
              if ( v17 == (__int64 *)a2 )
              {
                v17 = nullptr;
              }
              else
              {
                v18 = *v17;
                v19 = (_QWORD *)v17[1];
                if ( v19 )
                  *v19 = v18;
                if ( v18 )
                  *(_QWORD *)(v18 + 8) = v17[1];
                *v17 = (__int64)v17;
                v17[1] = (__int64)v17;
                if ( v17 )
                  --*(_DWORD *)(a2 + 16);
              }
              v20 = *((void (__fastcall **)(__int64, __int64 *))v7 + 3);
              if ( v20 )
              {
                if ( (dword_B804 & 0x200) != 0 )
                {
                  qdf_trace_msg(
                    56,
                    2,
                    "%s: HTC calling ep %d recv callback on packet %pK\n",
                    "do_recv_completion_pkt",
                    *v7,
                    v17);
                  v20 = *((void (__fastcall **)(__int64, __int64 *))v7 + 3);
                }
                v16 = *((_QWORD *)v7 + 1);
                if ( *((_DWORD *)v20 - 1) != 1226475842 )
                  __break(0x8228u);
                v20(v16, v17);
              }
              else
              {
                if ( (dword_B804 & 1) != 0 )
                  qdf_trace_msg(
                    56,
                    2,
                    "%s: HTC ep %d has NULL recv callback on packet %pK\n",
                    "do_recv_completion_pkt",
                    *v7,
                    v17);
                if ( v17 )
                {
                  v21 = v17[2];
                  if ( v21 )
                    _qdf_nbuf_free(v21);
                }
              }
            }
          }
        }
        return v11;
      }
    }
    v11 = -1;
    goto LABEL_20;
  }
  __break(0x5512u);
  return htc_flush_rx_hold_queue(a1, a2);
}
