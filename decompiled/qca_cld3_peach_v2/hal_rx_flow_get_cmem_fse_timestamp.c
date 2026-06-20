__int64 __fastcall hal_rx_flow_get_cmem_fse_timestamp(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 74392) + 1096LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != -1861014852 )
    __break(0x8228u);
  return v1();
}
