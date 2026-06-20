__int64 __fastcall wlan_cfg_fill_interrupt_mask(__int64 result, __int64 a2, int a3, char a4)
{
  __int64 v4; // x8
  __int64 v5; // x10
  char v6; // w4
  _BYTE *v7; // x1
  __int64 v8; // x1
  char v9; // w4

  v4 = 0;
  v5 = result + 404;
  *(_QWORD *)(result + 152) = 537137153;
  *(_QWORD *)(result + 160) = 0;
  *(_WORD *)(result + 168) = 0;
  do
  {
    if ( tx_ring_mask_msi[v4] )
      *(_DWORD *)(result + 800) |= 1LL << v4;
    v8 = v5 + v4;
    *(_BYTE *)(v8 - 216) = rx_mon_ring_mask_msi[v4];
    *(_BYTE *)(v8 - 198) = tx_mon_ring_mask_msi[v4];
    v9 = rx_wbm_rel_ring_mask_msi[v4];
    *(_BYTE *)(v8 - 126) = v9;
    *(_BYTE *)(v8 - 108) = v9;
    *(_BYTE *)(v8 - 90) = reo_status_ring_mask_msi[v4];
    if ( (a4 & 1) == 0 )
    {
      *(_BYTE *)(v8 - 234) = rx_ring_mask_msi[v4];
LABEL_3:
      v6 = rxdma2host_ring_mask_msi[v4];
      goto LABEL_4;
    }
    v6 = 0;
    *(_BYTE *)(v8 - 234) = 0;
    if ( a3 != 2 )
      goto LABEL_3;
LABEL_4:
    v7 = (_BYTE *)(v5 + v4++);
    *(v7 - 72) = v6;
    *(v7 - 54) = 0;
    *(v7 - 180) = 0;
    *(v7 - 162) = 0;
    *(v7 - 36) = 0;
    *(v7 - 18) = 0;
    *v7 = 0;
  }
  while ( v4 != 18 );
  return result;
}
