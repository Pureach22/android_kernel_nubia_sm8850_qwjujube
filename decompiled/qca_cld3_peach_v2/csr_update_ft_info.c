__int64 __fastcall csr_update_ft_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w3

  v10 = *(unsigned __int16 *)(a2 + 2940);
  *(_BYTE *)(a2 + 2942) = 1;
  return csr_send_assoc_cnf_msg(a3, a4, a5, a6, a7, a8, a9, a10, a1, a2, 4 * (unsigned int)(v10 != 0), v10);
}
