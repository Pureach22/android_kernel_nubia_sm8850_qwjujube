__int64 __fastcall csr_qos_send_reassoc_ind(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  unsigned int v6; // w22
  __int64 result; // x0

  v6 = a2;
  sme_qos_csr_event_ind(a1, a2, 7, 0);
  sme_qos_csr_event_ind(a1, v6, 2, 0);
  sme_qos_csr_event_ind(a1, v6, 8, 0);
  result = sme_qos_csr_event_ind(a1, v6, 3, a3);
  if ( (*(_WORD *)(*((_QWORD *)a4 + 18) + 110LL) & 0xF) == 0xD )
    return sme_qos_csr_event_ind(a1, *a4, 11, 0);
  return result;
}
