__int64 __fastcall mem_buf_relinquish_all_mem(unsigned __int16 a1)
{
  _DWORD *v2; // x21
  _DWORD *v3; // x9
  __int64 v4; // x1
  int v5; // w8
  _QWORD *v6; // x8

  mutex_lock(&mem_buf_xfer_mem_list_lock);
  v2 = mem_buf_xfer_mem_list;
  if ( mem_buf_xfer_mem_list != (_UNKNOWN *)&mem_buf_xfer_mem_list )
  {
    do
    {
      v5 = v2[4];
      v3 = v2;
      v2 = *(_DWORD **)v2;
      if ( v5 == 1 && **((_DWORD **)v3 + 3) == a1 )
      {
        v6 = *((_QWORD **)v3 + 1);
        if ( (_DWORD *)*v6 == v3 && *((_DWORD **)v2 + 1) == v3 )
        {
          *((_QWORD *)v2 + 1) = v6;
          *v6 = v2;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
        }
        v4 = (unsigned int)*(v3 - 2);
        *(_QWORD *)v3 = 0xDEAD000000000100LL;
        *((_QWORD *)v3 + 1) = 0xDEAD000000000122LL;
        mem_buf_cleanup_alloc_req(v3 - 12, v4);
      }
    }
    while ( v2 != (_DWORD *)&mem_buf_xfer_mem_list );
  }
  return mutex_unlock(&mem_buf_xfer_mem_list_lock);
}
