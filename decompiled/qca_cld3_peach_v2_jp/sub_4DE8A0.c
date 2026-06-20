__int64 __fastcall sub_4DE8A0(__int64 a1, __int64 a2)
{
  _ReadStatusReg(CNTVCTSS_EL0);
  return dp_rx_reorder_flush_frag(a1, a2);
}
