__int64 __fastcall hfi_core_lb_cmd_update_payload(_QWORD **a1, int a2, int a3, int a4, __int64 a5)
{
  _QWORD *v5; // x24
  char v11; // w8
  __int64 v12; // x0

  v5 = *a1;
  if ( *a1 == a1 )
  {
    v11 = 0;
  }
  else
  {
    v11 = 0;
    do
    {
      if ( v5 != &_ksymtab_hfi_core_cmds_rx_buf_get && *((_DWORD *)v5 - 6) == a2 )
      {
        v12 = *(v5 - 2);
        *(v5 - 2) = a5;
        *((_DWORD *)v5 - 2) = a4;
        *((_DWORD *)v5 - 1) = a3;
        kfree(v12);
        v11 = 1;
      }
      v5 = (_QWORD *)*v5;
    }
    while ( v5 != a1 );
  }
  return v11 & 1;
}
