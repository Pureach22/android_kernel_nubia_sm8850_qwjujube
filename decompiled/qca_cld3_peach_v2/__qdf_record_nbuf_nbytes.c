__int64 __fastcall _qdf_record_nbuf_nbytes(int a1, int a2, char a3)
{
  __int64 v3; // x19

  LODWORD(v3) = a1;
  if ( (a3 & 1) != 0 )
  {
    if ( a2 == 1 )
    {
      qdf_mem_dp_tx_skb_cnt_inc();
      v3 = (int)v3;
      qdf_mem_dp_tx_skb_inc((int)v3);
    }
    else if ( a2 == 2 )
    {
      qdf_mem_dp_rx_skb_cnt_inc();
      v3 = (int)v3;
      qdf_mem_dp_rx_skb_inc((int)v3);
    }
    else
    {
      v3 = a1;
    }
    return qdf_mem_skb_total_inc(v3);
  }
  else
  {
    if ( a2 == 1 )
    {
      qdf_mem_dp_tx_skb_cnt_dec();
      v3 = (int)v3;
      qdf_mem_dp_tx_skb_dec((int)v3);
    }
    else if ( a2 == 2 )
    {
      qdf_mem_dp_rx_skb_cnt_dec();
      v3 = (int)v3;
      qdf_mem_dp_rx_skb_dec((int)v3);
    }
    else
    {
      v3 = a1;
    }
    return qdf_mem_skb_total_dec(v3);
  }
}
