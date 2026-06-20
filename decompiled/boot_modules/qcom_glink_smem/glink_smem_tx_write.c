__int64 __fastcall glink_smem_tx_write(unsigned __int64 *a1, void *src, __int64 a3, void *a4)
{
  unsigned __int64 v5; // x22
  int v7; // w0
  int v8; // w0
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x9
  int v11; // w19
  __int64 result; // x0

  v5 = a1[9];
  v7 = glink_smem_tx_write_one((int)a1, *(_DWORD *)a1[7], src);
  v8 = glink_smem_tx_write_one((int)a1, v7, a4);
  v9 = *a1;
  __dsb(0xEu);
  v10 = (v8 + 7) & 0xFFFFFFF8;
  if ( v9 > v10 )
    LODWORD(v9) = 0;
  v11 = v10 - v9;
  result = ipc_log_string(
             glink_ilctxt,
             "[%s]: TX: remote-pid=%d, head=0x%x, tail=0x%x\n",
             "glink_smem_tx_write",
             *(_DWORD *)(v5 + 1024),
             (int)v10 - (int)v9,
             *(_DWORD *)a1[6]);
  *(_DWORD *)a1[7] = v11;
  return result;
}
