__int64 __fastcall htc_send_data_pkt(__int64 a1, __int64 a2, unsigned int a3, _OWORD *a4)
{
  __int128 v4; // q28
  __int64 v7; // x23
  unsigned int v8; // w20
  unsigned __int16 free_queue_number; // w0
  unsigned int v11; // w1
  __int64 v13; // x8
  int *v14; // x24
  int v15; // w8
  int v16; // w8
  int v17; // w22
  unsigned __int64 StatusReg; // x8
  unsigned int v19; // w0
  __int64 v20; // x8
  unsigned int v21; // w20

  if ( a3 >= 0xA )
  {
    __break(0x5512u);
    *a4 = v4;
    return htc_tx_completion_handler();
  }
  else
  {
    v7 = a1 + 328LL * a3;
    v8 = (unsigned int)a4;
    free_queue_number = hif_get_free_queue_number(*(_QWORD *)a1, *(_BYTE *)(v7 + 144));
    if ( free_queue_number <= 0xFFu )
    {
      if ( *(_DWORD *)(v7 + 148) )
      {
        hif_send_complete_check(**(_QWORD **)(v7 + 288), *(unsigned __int8 *)(v7 + 144), 1);
        free_queue_number = hif_get_free_queue_number(*(_QWORD *)a1, *(_BYTE *)(v7 + 144));
      }
      if ( free_queue_number < 2u )
        return 16;
    }
    v11 = *(_WORD *)(v7 + 12) == 768 ? 3 : 2;
    if ( (unsigned int)hif_rtpm_get(0, v11) )
    {
      return 16;
    }
    else
    {
      v13 = 72;
      if ( (*(_BYTE *)(a2 + 68) & 4) == 0 )
        v13 = 224;
      v14 = *(int **)(a2 + v13);
      if ( !v14 )
        printk(&unk_881311, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 2253, "p_htc_hdr");
      if ( *(_BYTE *)(a1 + 3562) )
        v15 = (v8 << 16) - 0x80000;
      else
        v15 = v8 << 16;
      v16 = v15 | a3;
      v17 = *(_DWORD *)(a2 + 52);
      *v14 = v16;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 2992);
      }
      else
      {
        raw_spin_lock_bh(a1 + 2992);
        *(_QWORD *)(a1 + 3000) |= 1uLL;
      }
      v14[1] = (unsigned __int8)(*(_BYTE *)(v7 + 280))++ << 8;
      ((void (__fastcall *)(__int64, __int64))qdf_nbuf_set_state)(a2, 6);
      qdf_dp_trace(a2, 39, 255, a2 + 224, 8, 0);
      v19 = hif_send_head(*(_QWORD *)a1, *(_BYTE *)(v7 + 144), *(_DWORD *)(v7 + 8), v8, a2, v17);
      v20 = *(_QWORD *)(a1 + 3000);
      v21 = v19;
      if ( (v20 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 3000) = v20 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2992);
      }
      else
      {
        raw_spin_unlock(a1 + 2992);
      }
      return v21;
    }
  }
}
