__int64 __fastcall send_fw_diag_nl_data(const void *a1, unsigned int a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 is_initialized; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  int radio_index; // w0
  __int64 result; // x0
  int v12; // w23
  _DWORD *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  int v23; // w8
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  __int64 v34; // [xsp+8h] [xbp-38h]

  if ( a2 >= 0x5DD )
  {
    __break(0x800u);
    return 4294967277LL;
  }
  else
  {
    v34 = v3;
    is_initialized = nl_srv_is_initialized();
    if ( (_DWORD)is_initialized )
      return 4294967291LL;
    radio_index = cds_get_radio_index(is_initialized, v7, v8, v9);
    if ( radio_index == -22 )
    {
      return 4294967291LL;
    }
    else
    {
      v12 = radio_index;
      if ( (unsigned __int8)cds_is_multicast_logging() )
      {
        v13 = (_DWORD *)_alloc_skb(((_WORD)a2 + 23) & 0xFFC, 3264, 0, 0xFFFFFFFFLL);
        if ( v13 )
        {
          v22 = (__int64)v13;
          if ( v13[29] )
            v23 = 0;
          else
            v23 = v13[53] - v13[52];
          if ( v23 >= (unsigned __int16)((a2 + 23) & 0xFFC) && (v24 = _nlmsg_put(v13, 0)) != 0 )
          {
            *(_DWORD *)(v24 + 16) = v12;
            memcpy((void *)(v24 + 20), a1, a2);
            result = nl_srv_bcast(v22, 2u, 27);
            if ( (result & 0x80000000) != 0 && (_DWORD)result != -3 && (dword_17AC4 & 0x10) != 0 )
            {
              v33 = result;
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: %s: nl_srv_bcast_fw_logs failed 0x%x\n",
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                "send_fw_diag_nl_data",
                "send_fw_diag_nl_data",
                (unsigned int)result,
                v2,
                v34);
              return v33;
            }
          }
          else
          {
            sk_skb_reason_drop(0, v22, 2);
            return 4294967206LL;
          }
        }
        else
        {
          if ( (dword_17AC4 & 1) != 0 )
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Failed to allocate new skb\n",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "send_fw_diag_nl_data",
              v2,
              v34);
          return 4294967284LL;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
