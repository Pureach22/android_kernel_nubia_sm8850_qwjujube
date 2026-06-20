__int64 __fastcall rndis_rm_hdr(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v3; // x21

  v3 = *(_DWORD **)(a2 + 224);
  if ( *v3 == 1 )
  {
    if ( skb_pull(a2, (unsigned int)(v3[2] + 8)) )
    {
      skb_trim(a2, (unsigned int)v3[3]);
      skb_queue_tail(a3, a2);
      return 0;
    }
    else
    {
      dev_kfree_skb_any_reason(a2, 2);
      return 4294967221LL;
    }
  }
  else
  {
    dev_kfree_skb_any_reason(a2, 2);
    return 4294967274LL;
  }
}
