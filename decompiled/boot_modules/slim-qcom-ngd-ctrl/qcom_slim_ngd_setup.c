__int64 __fastcall qcom_slim_ngd_setup(__int64 a1)
{
  int v2; // w20
  int v3; // w8
  int v4; // w8
  __int64 v5; // x21
  unsigned __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD *v9; // x9
  __int64 v10; // x25
  __int64 *v11; // x24
  __int64 v12; // x8
  __int64 v13; // x28
  __int64 v14; // x22
  _DWORD *v15; // x8
  __int64 v16; // x0
  __int64 (*v17)(void); // x8
  int v18; // w0
  _DWORD *v19; // t1
  void (*v20)(void); // x8
  __int64 v21; // x21
  unsigned __int64 v22; // x0
  __int64 v23; // x0
  _QWORD *v24; // x9
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 result; // x0
  int v28; // w8
  int v29; // w8
  __int64 v30; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v31[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v32; // [xsp+18h] [xbp-18h]
  __int64 v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = readl_relaxed(*(unsigned int **)(*(_QWORD *)(a1 + 1960) + 8LL));
  _slimbus_dbg();
  v3 = *(_DWORD *)(a1 + 5476);
  if ( v3 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM: NGD setup\n");
    v3 = *(_DWORD *)(a1 + 5476);
  }
  if ( !v3 )
    ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM: NGD setup\n");
  if ( (*(_DWORD *)(a1 + 5384) & 0xFFFFFFFE) == 2 )
  {
    _slimbus_dbg();
    v4 = *(_DWORD *)(a1 + 5476);
    if ( v4 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM: NGD init dma\n");
      v4 = *(_DWORD *)(a1 + 5476);
    }
    if ( !v4 )
      ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM: NGD init dma\n");
    v5 = *(_QWORD *)(a1 + 1968);
    v30 = 0;
    v6 = dma_request_chan(v5, "rx");
    *(_QWORD *)(a1 + 1984) = v6;
    if ( v6 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(_BYTE *)(a1 + 5468) == 1 )
      {
        v7 = *(_QWORD *)(a1 + 5448);
        *(_QWORD *)(a1 + 5408) = v7;
        if ( !v7 )
          goto LABEL_44;
      }
      else
      {
        v8 = dma_alloc_attrs(v5, 1200, &v30, 3264, 0);
        *(_QWORD *)(a1 + 5408) = v8;
        if ( !v8 )
        {
LABEL_44:
          dma_release_channel(*(_QWORD *)(a1 + 1984));
LABEL_45:
          dev_err(*(_QWORD *)(a1 + 1968), "rx dma init failed\n");
          goto LABEL_46;
        }
      }
      if ( (*(_BYTE *)(a1 + 5468) & 1) != 0 )
      {
        *(_QWORD *)(a1 + 5392) = **(_QWORD **)(a1 + 5440);
        _memset_io();
        v9 = *(_QWORD **)(a1 + 5440);
        *(_QWORD *)(a1 + 5448) += 1200LL;
        *v9 += 1200LL;
      }
      else
      {
        *(_QWORD *)(a1 + 5392) = v30;
      }
      v10 = 0;
      v11 = (__int64 *)(a1 + 2000);
      while ( 1 )
      {
        v12 = *(_QWORD *)(a1 + 5392);
        v11[1] = a1;
        v32 = 0;
        v33 = 0;
        v13 = v10 + v12;
        v31[0] = 0;
        v31[1] = 0;
        v11[4] = v10 + v12;
        v11[5] = *(_QWORD *)(a1 + 5408) + v10;
        v14 = *(_QWORD *)(a1 + 1984);
        sg_init_table(v31, 1);
        v32 = v13;
        LODWORD(v33) = 40;
        if ( !v14 )
          break;
        if ( !*(_QWORD *)v14 )
          break;
        v15 = *(_DWORD **)(*(_QWORD *)v14 + 272LL);
        if ( !v15 )
          break;
        if ( *(v15 - 1) != -1221891457 )
          __break(0x8228u);
        v16 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, _QWORD))v15)(v14, v31, 1, 2, 1, 0);
        *v11 = v16;
        if ( !v16 )
          goto LABEL_42;
        *(_QWORD *)(v16 + 40) = qcom_slim_ngd_rx_msgq_cb;
        *(_QWORD *)(*v11 + 56) = v11;
        v17 = *(__int64 (**)(void))(*v11 + 24);
        if ( *((_DWORD *)v17 - 1) != 1188179853 )
          __break(0x8228u);
        v18 = v17();
        v19 = (_DWORD *)*v11;
        v11 += 6;
        v10 += 40;
        *v19 = v18;
        if ( v10 == 1200 )
        {
          v20 = *(void (**)(void))(**(_QWORD **)(a1 + 1984) + 360LL);
          if ( *((_DWORD *)v20 - 1) != 905352215 )
            __break(0x8228u);
          v20();
          goto LABEL_31;
        }
      }
      *v11 = 0;
LABEL_42:
      dev_err(*(_QWORD *)(a1 + 1968), "Unable to prepare rx channel\n");
      dev_err(v5, "post_rx_msgq() failed 0x%x\n", -22);
      if ( (*(_BYTE *)(a1 + 5468) & 1) == 0 )
        dma_free_attrs(v5, 1200, *(_QWORD *)(a1 + 5408), *(_QWORD *)(a1 + 5392), 0);
      goto LABEL_44;
    }
    dev_err(v5, "Failed to request RX dma channel");
    v28 = *(_DWORD *)(a1 + 1984);
    *(_QWORD *)(a1 + 1984) = 0;
    if ( v28 )
      goto LABEL_45;
LABEL_31:
    v21 = *(_QWORD *)(a1 + 1968);
    v31[0] = 0;
    v22 = dma_request_chan(v21, "tx");
    *(_QWORD *)(a1 + 1992) = v22;
    if ( v22 > 0xFFFFFFFFFFFFF000LL )
    {
      dev_err(v21, "Failed to request TX dma channel");
      v29 = *(_DWORD *)(a1 + 1992);
      *(_QWORD *)(a1 + 1992) = 0;
      if ( !v29 )
        goto LABEL_46;
    }
    else
    {
      if ( *(_BYTE *)(a1 + 5468) == 1 )
      {
        v23 = *(_QWORD *)(a1 + 5448);
        *(_QWORD *)(a1 + 5416) = v23;
        if ( v23 )
        {
LABEL_34:
          if ( (*(_BYTE *)(a1 + 5468) & 1) != 0 )
          {
            *(_QWORD *)(a1 + 5400) = **(_QWORD **)(a1 + 5440);
            _memset_io();
            v24 = *(_QWORD **)(a1 + 5440);
            *(_QWORD *)(a1 + 5448) += 1240LL;
            *v24 += 1240LL;
          }
          else
          {
            *(_QWORD *)(a1 + 5400) = v31[0];
          }
          v26 = raw_spin_lock_irqsave(a1 + 5144);
          *(_QWORD *)(a1 + 5424) = 0;
          raw_spin_unlock_irqrestore(a1 + 5144, v26);
          goto LABEL_46;
        }
      }
      else
      {
        v25 = dma_alloc_attrs(v21, 1240, v31, 3264, 0);
        *(_QWORD *)(a1 + 5416) = v25;
        if ( v25 )
          goto LABEL_34;
      }
      dma_release_channel(*(_QWORD *)(a1 + 1992));
    }
    dev_err(*(_QWORD *)(a1 + 1968), "tx dma init failed\n");
  }
LABEL_46:
  result = writel_relaxed(v2 | 7u, *(_QWORD *)(*(_QWORD *)(a1 + 1960) + 8LL));
  _ReadStatusReg(SP_EL0);
  return result;
}
