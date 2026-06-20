__int64 __fastcall hdd_fill_ipv6_ac_addr(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int *a5)
{
  _QWORD *v10; // x24
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x5
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w28
  unsigned int v30; // w20

  raw_read_lock_bh(a1 + 712);
  v10 = *(_QWORD **)(a1 + 704);
  if ( v10 )
  {
    while ( *a5 <= 0xF )
    {
      v20 = _ipv6_addr_type(v10);
      if ( v20 )
        v29 = v20 >> 16;
      else
        v29 = -1;
      if ( v29 == 14 || v29 == 2 )
      {
        qdf_mem_copy((void *)(a2 + 16LL * *a5), v10, 0x10u);
        *(_BYTE *)(a3 + *a5) = 1;
        *(_DWORD *)(a4 + 4LL * *a5) = ucfg_pmo_ns_addr_scope(v29);
        if ( v29 == 2 )
          v19 = "LINK LOCAL";
        else
          v19 = "GLOBAL";
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Index %d scope = %s AC-Address: %pI6",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "hdd_fill_ipv6_ac_addr",
          *a5,
          v19,
          a2 + 16LL * *a5);
        ++*a5;
        v10 = (_QWORD *)v10[3];
        if ( !v10 )
        {
LABEL_14:
          v30 = 0;
          goto LABEL_17;
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: The Scope %d is not supported",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "hdd_fill_ipv6_ac_addr",
          v29);
        v10 = (_QWORD *)v10[3];
        if ( !v10 )
          goto LABEL_14;
      }
    }
    v30 = -22;
  }
  else
  {
    v30 = 0;
  }
LABEL_17:
  raw_read_unlock_bh(a1 + 712);
  return v30;
}
