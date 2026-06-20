__int64 __fastcall hal_rx_flow_cmem_update_reo_dst_ind_0(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(result + 74392) + 1912LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != 1934203253 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
