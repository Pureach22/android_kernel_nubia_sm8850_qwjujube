__int64 __fastcall glink_smem_rx_peek(__int64 result, unsigned __int8 *a2, int a3, unsigned __int64 a4)
{
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x9
  __int64 v7; // x24
  unsigned __int64 v8; // x10
  __int64 v10; // x21
  __int64 v12; // x19
  unsigned __int64 v13; // x25
  unsigned __int64 v14; // x23

  v4 = **(unsigned int **)(result + 48);
  v5 = *(_QWORD *)result;
  if ( *(_QWORD *)result < v4 )
  {
    __break(0x800u);
  }
  else
  {
    v6 = (unsigned int)(v4 + a3);
    v7 = *(_QWORD *)(result + 72);
    __dsb(0xFu);
    v8 = *(_QWORD *)result;
    if ( v5 > v6 )
      LODWORD(v5) = 0;
    v10 = result;
    v12 = (unsigned int)(v6 - v5);
    v13 = v8 - v12;
    if ( v8 - v12 >= a4 )
      v14 = a4;
    else
      v14 = v8 - v12;
    if ( v14 )
      result = _memcpy_fromio(a2, *(_QWORD *)(result + 64) + v12, v14);
    if ( v13 < a4 )
      result = _memcpy_fromio(&a2[v14], *(_QWORD *)(v10 + 64), a4 - v14);
    if ( a4 )
    {
      if ( a4 == 1 )
        return ipc_log_string(
                 glink_ilctxt,
                 "[%s]: RX: remote-pid=%d, head=0x%x, tail=0x%x, [%02x]\n",
                 "glink_smem_rx_peek",
                 *(_DWORD *)(v7 + 1024),
                 **(_DWORD **)(v10 + 56),
                 v12,
                 *a2);
      else
        return ipc_log_string(
                 glink_ilctxt,
                 "[%s]: RX: remote-pid=%d, head=0x%x, tail=0x%x, [%02x %02x]\n",
                 "glink_smem_rx_peek",
                 *(_DWORD *)(v7 + 1024),
                 **(_DWORD **)(v10 + 56),
                 v12,
                 a2[1],
                 *a2);
    }
  }
  return result;
}
