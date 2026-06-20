__int64 __fastcall rmnet_shs_wq_filter(__int64 a1)
{
  __int64 lock; // x0
  _UNKNOWN **v2; // x9
  unsigned __int64 v3; // x12

  qword_19670 = 0;
  qword_19678 = 0;
  rmnet_shs_cpu_rx_filter_flows = 0;
  qword_19668 = 0;
  dword_194C8 = 0;
  dword_194F0 = 0;
  dword_19518 = 0;
  dword_19540 = 0;
  dword_19568 = 0;
  dword_19590 = 0;
  dword_195B8 = 0;
  dword_195E0 = 0;
  lock = _rcu_read_lock(a1);
  v2 = (_UNKNOWN **)rmnet_shs_wq_hstat_tbl;
  if ( rmnet_shs_wq_hstat_tbl != (_UNKNOWN *)&rmnet_shs_wq_hstat_tbl )
  {
    do
    {
      if ( *((_BYTE *)v2 + 253) )
      {
        if ( (unsigned __int64)v2[14] >= 0x65 && (unsigned __int64)v2[8] >= 0xC9 )
        {
          v3 = *((unsigned __int16 *)v2 + 123);
          if ( v3 <= 7 )
            ++*((_DWORD *)&rmnet_shs_cpu_rx_filter_flows + v3);
        }
        if ( *((unsigned __int16 *)v2 + 123) <= 7uLL && *((_BYTE *)v2 + 256) )
          ++LODWORD(rmnet_shs_cpu_node_tbl[5 * *((unsigned __int16 *)v2 + 123) + 4]);
      }
      v2 = (_UNKNOWN **)*v2;
    }
    while ( v2 != &rmnet_shs_wq_hstat_tbl );
  }
  return _rcu_read_unlock(lock);
}
