__int64 __fastcall hdd_get_num_tx_chains_config(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // [xsp+0h] [xbp-10h] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v14) = 0;
  if ( (hdd_is_vdev_in_conn_state(a1) & 1) != 0 )
  {
    if ( (unsigned int)hdd_get_num_tx_chains(a1, &v14) )
    {
      v12 = "%s: Failed to get num tx chains";
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: num_tx_chains %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "hdd_get_num_tx_chains_config",
        (unsigned __int8)v14);
      BYTE4(v14) = v14;
      result = nla_put(a2, 73, 1, (char *)&v14 + 4);
      if ( !(_DWORD)result )
        goto LABEL_6;
      v12 = "%s: nla_put failure";
    }
  }
  else
  {
    v12 = "%s: Not in connected state";
  }
  qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_get_num_tx_chains_config", v14, v15);
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
