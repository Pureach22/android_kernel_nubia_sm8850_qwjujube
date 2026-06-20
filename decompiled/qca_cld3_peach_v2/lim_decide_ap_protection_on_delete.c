__int64 __fastcall lim_decide_ap_protection_on_delete(
        __int64 result,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x21
  __int64 v16; // x23
  int v17; // w8
  __int64 v18; // x24
  unsigned int v19; // w8
  __int64 i; // x24
  char v21; // w8
  char v22; // w8
  __int64 v23; // x24
  char v24; // w8
  __int64 v25; // x24
  __int64 j; // x24
  char v27; // w8
  char v28; // w8
  __int64 v29; // x23
  __int64 v30; // [xsp+0h] [xbp-10h]

  if ( !a2 )
    return result;
  v15 = result;
  v16 = a4 + 4096;
  if ( a4 )
  {
    v17 = *(_DWORD *)(a4 + 168);
    if ( v17 )
    {
      if ( v17 == 1 && *(_BYTE *)(a4 + 155) == 1 && *(_BYTE *)(a4 + 7161) && (a2[32] & 8) == 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: (%d) A 11A STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "lim_decide_ap_protection_on_delete",
                   *(unsigned __int8 *)(a4 + 438),
                   a2[350],
                   a2[351],
                   a2[352],
                   a2[355]);
        v18 = 0;
        while ( 1 )
        {
          if ( *(_BYTE *)(a4 + v18 + 1236) )
          {
            result = qdf_mem_cmp((const void *)(a4 + v18 + 1237), a2 + 350, 6u);
            if ( !(_DWORD)result )
              break;
          }
          v18 += 12;
          if ( v18 == 384 )
            goto LABEL_13;
        }
        *(_BYTE *)(a4 + v18 + 1236) = 0;
LABEL_13:
        if ( !*(_BYTE *)(a4 + 438) )
          result = lim_update_11a_protection(v15, 0, 0, a3, a4);
      }
      goto LABEL_37;
    }
    v19 = *(unsigned __int16 *)a2;
    if ( *(_DWORD *)(a4 + 7232) == 2 )
    {
      if ( (v19 & 4) != 0 )
        goto LABEL_28;
    }
    else if ( !*(_BYTE *)(a4 + 155) || ((v19 >> 2) & 1) != 0 )
    {
LABEL_28:
      if ( *(_BYTE *)(a4 + 155) && (a2[32] & 8) == 0 )
      {
        LODWORD(v30) = a2[355];
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: (%d) A 11g STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "lim_decide_ap_protection_on_delete",
                   *(unsigned __int8 *)(a4 + 436),
                   a2[350],
                   a2[351],
                   a2[352],
                   v30);
        v23 = 0;
        while ( 1 )
        {
          if ( *(_BYTE *)(a4 + v23 + 1236) )
          {
            result = qdf_mem_cmp((const void *)(a4 + v23 + 1237), a2 + 350, 6u);
            if ( !(_DWORD)result )
              break;
          }
          v23 += 12;
          if ( v23 == 384 )
            goto LABEL_35;
        }
        v24 = *(_BYTE *)(a4 + 440);
        *(_BYTE *)(a4 + v23 + 1236) = 0;
        *(_BYTE *)(a4 + 440) = v24 - 1;
LABEL_35:
        if ( !*(_BYTE *)(a4 + 440) )
          result = lim_enable_ht_protection_from11g(v15, 0, 0, a3, a4);
      }
      goto LABEL_37;
    }
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: (%d) A legacy STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "lim_decide_ap_protection_on_delete",
               *(unsigned __int8 *)(a4 + 436),
               a2[350],
               a2[351],
               a2[352],
               a2[355]);
    for ( i = 0; i != 384; i += 12 )
    {
      if ( *(_BYTE *)(a4 + i + 1236) )
      {
        result = qdf_mem_cmp((const void *)(a4 + i + 1237), a2 + 350, 6u);
        if ( !(_DWORD)result )
        {
          v21 = *(_BYTE *)(a4 + 436);
          *(_BYTE *)(a4 + i + 1236) = 0;
          v22 = v21 - 1;
          *(_BYTE *)(a4 + 436) = v22;
          goto LABEL_26;
        }
      }
    }
    v22 = *(_BYTE *)(a4 + 436);
LABEL_26:
    if ( !v22 )
      result = lim_enable11g_protection(v15, 0, 0, a3, a4);
    goto LABEL_28;
  }
LABEL_37:
  if ( *(_BYTE *)(a4 + 155) == 1 && (a2[32] & 8) != 0 )
  {
    if ( (a2[344] & 1) == 0 )
    {
      LODWORD(v30) = a2[355];
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: (%d) A non-GF STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "lim_decide_ap_protection_on_delete",
                 *(unsigned __int8 *)(a4 + 442),
                 a2[350],
                 a2[351],
                 a2[352],
                 v30);
      v25 = 0;
      while ( 1 )
      {
        if ( *(_BYTE *)(a4 + v25 + 1236) )
        {
          result = qdf_mem_cmp((const void *)(a4 + v25 + 1237), a2 + 350, 6u);
          if ( !(_DWORD)result )
            break;
        }
        v25 += 12;
        if ( v25 == 384 )
          goto LABEL_45;
      }
      *(_BYTE *)(a4 + v25 + 1236) = 0;
LABEL_45:
      if ( !*(_BYTE *)(a4 + 442) )
        result = lim_enable_ht_non_gf_protection(v15, 0, 0, a3, a4);
    }
    if ( *(_BYTE *)(v16 + 3068) && (a2[346] & 8) == 0 )
    {
      LODWORD(v30) = a2[355];
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: (%d) A HT 20 STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "lim_decide_ap_protection_on_ht20_delete",
                 *(unsigned __int8 *)(a4 + 444),
                 a2[350],
                 a2[351],
                 a2[352],
                 v30);
      if ( !*(_BYTE *)(a4 + 444) )
        goto LABEL_57;
      for ( j = 0; j != 384; j += 12 )
      {
        if ( *(_BYTE *)(a4 + j + 1236) )
        {
          result = qdf_mem_cmp((const void *)(a4 + j + 1237), a2 + 350, 6u);
          if ( !(_DWORD)result )
          {
            v27 = *(_BYTE *)(a4 + 444);
            *(_BYTE *)(a4 + j + 1236) = 0;
            v28 = v27 - 1;
            *(_BYTE *)(a4 + 444) = v28;
            goto LABEL_56;
          }
        }
      }
      v28 = *(_BYTE *)(a4 + 444);
LABEL_56:
      if ( !v28 )
      {
LABEL_57:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: No 11B STA exists, PESessionID %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "lim_decide_ap_protection_on_ht20_delete",
          *(unsigned __int16 *)(a4 + 8));
        result = lim_enable_ht20_protection(v15, 0, 0, a3, a4);
      }
    }
    if ( !*(_BYTE *)(v16 + 3071) && (a2[344] & 0x10) == 0 )
    {
      LODWORD(v30) = a2[355];
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: (%d) A HT LSIG not supporting STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "lim_decide_ap_protection_on_delete",
                 *(unsigned __int8 *)(a4 + 446),
                 a2[350],
                 a2[351],
                 a2[352],
                 v30);
      v29 = 0;
      while ( 1 )
      {
        if ( *(_BYTE *)(a4 + v29 + 1236) )
        {
          result = qdf_mem_cmp((const void *)(a4 + v29 + 1237), a2 + 350, 6u);
          if ( !(_DWORD)result )
            break;
        }
        v29 += 12;
        if ( v29 == 384 )
          goto LABEL_65;
      }
      *(_BYTE *)(a4 + v29 + 1236) = 0;
LABEL_65:
      if ( !*(_BYTE *)(a4 + 446) )
        return lim_enable_ht_lsig_txop_protection(v15, 1, 0, a3, a4);
    }
  }
  return result;
}
