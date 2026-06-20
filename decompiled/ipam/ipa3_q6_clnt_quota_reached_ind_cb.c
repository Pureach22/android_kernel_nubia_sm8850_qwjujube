__int64 __fastcall ipa3_q6_clnt_quota_reached_ind_cb(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  _BOOL4 v5; // w20
  __int64 ipc_logbuf; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0

  if ( ipa_q6_clnt == a1 )
  {
    if ( *((_BYTE *)a4 + 16) )
    {
      v5 = *((_BYTE *)a4 + 17) != 0;
      if ( *((_BYTE *)a4 + 17) )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf(a1);
        if ( ipc_logbuf )
        {
          v7 = ipa3_get_ipc_logbuf(ipc_logbuf);
          ipc_logbuf = ipc_log_string(
                         v7,
                         "ipa-wan %s:%d Warning reached indication on qmux(%d) Mbytes(%lu)\n",
                         "ipa3_q6_clnt_quota_reached_ind_cb",
                         1615,
                         *a4,
                         *((_QWORD *)a4 + 1));
        }
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
        if ( ipc_logbuf_low )
        {
          v9 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
          ipc_log_string(
            v9,
            "ipa-wan %s:%d Warning reached indication on qmux(%d) Mbytes(%lu)\n",
            "ipa3_q6_clnt_quota_reached_ind_cb",
            1615,
            *a4,
            *((_QWORD *)a4 + 1));
        }
        v5 = 1;
        return ipa3_broadcast_quota_reach_ind(*a4, 1, v5);
      }
    }
    else
    {
      v5 = 0;
    }
    v10 = ipa3_get_ipc_logbuf(a1);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf(v10);
      v10 = ipc_log_string(
              v11,
              "ipa-wan %s:%d Quota reached indication on qmux(%d) Mbytes(%lu)\n",
              "ipa3_q6_clnt_quota_reached_ind_cb",
              1619,
              *a4,
              *((_QWORD *)a4 + 1));
    }
    v12 = ipa3_get_ipc_logbuf_low(v10);
    if ( v12 )
    {
      v13 = ipa3_get_ipc_logbuf_low(v12);
      ipc_log_string(
        v13,
        "ipa-wan %s:%d Quota reached indication on qmux(%d) Mbytes(%lu)\n",
        "ipa3_q6_clnt_quota_reached_ind_cb",
        1619,
        *a4,
        *((_QWORD *)a4 + 1));
    }
    return ipa3_broadcast_quota_reach_ind(*a4, 1, v5);
  }
  v15 = printk(&unk_3D01E5, "ipa3_q6_clnt_quota_reached_ind_cb");
  v16 = ipa3_get_ipc_logbuf(v15);
  if ( v16 )
  {
    v17 = ipa3_get_ipc_logbuf(v16);
    v16 = ipc_log_string(v17, "ipa-wan %s:%d Wrong client\n", "ipa3_q6_clnt_quota_reached_ind_cb", 1604);
  }
  result = ipa3_get_ipc_logbuf_low(v16);
  if ( result )
  {
    v18 = ipa3_get_ipc_logbuf_low(result);
    return ipc_log_string(v18, "ipa-wan %s:%d Wrong client\n", "ipa3_q6_clnt_quota_reached_ind_cb", 1604);
  }
  return result;
}
