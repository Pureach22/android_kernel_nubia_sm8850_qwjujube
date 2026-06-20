__int64 __fastcall _qdf_nbuf_add_rx_frag(__int64 a1, __int64 a2, int a3, unsigned int a4, unsigned int a5, char a6)
{
  unsigned int v10; // w22
  unsigned __int64 v11; // x8
  __int64 v12; // x9
  __int64 result; // x0
  __int64 v14; // x24
  int v15; // w25
  __int64 v16; // x0

  v10 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 2LL);
  if ( v10 >= 0x11 )
  {
    v14 = a1;
    v15 = a3;
    v16 = printk(
            &unk_9BB309,
            "nr_frag < 17",
            "__qdf_nbuf_add_rx_frag",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/qdf/linux/src/qdf_nbuf.c");
    dump_stack(v16);
    a1 = v14;
    a3 = v15;
  }
  v11 = ((unsigned __int64)((a1 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
  v12 = *(_QWORD *)(((unsigned __int64)((a1 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFF8LL);
  if ( (v12 & 1) != 0 )
    v11 = v12 - 1;
  result = skb_add_rx_frag_netmem(a2, v10, v11, (unsigned int)a1 - ((unsigned int)v11 >> 6 << 12) + a3, a4, a5);
  if ( (a6 & 1) != 0 )
    return skb_frag_ref(a2, v10);
  return result;
}
