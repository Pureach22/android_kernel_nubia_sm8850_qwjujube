__int64 __fastcall cds_send_delba(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned __int8 a6)
{
  return wma_dp_send_delba_ind(a2, a3, a4, a5, a6);
}
