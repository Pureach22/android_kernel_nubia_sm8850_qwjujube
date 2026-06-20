__int64 __fastcall cds_print_htc_credit_history(unsigned int a1, __int64 a2, __int64 a3)
{
  return ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, __int64))htc_print_credit_history)(
           *(_QWORD *)(gp_cds_context + 40),
           a1,
           a2,
           a3);
}
