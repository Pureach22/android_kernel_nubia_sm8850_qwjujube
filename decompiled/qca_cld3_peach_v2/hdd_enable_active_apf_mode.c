__int64 __fastcall hdd_enable_active_apf_mode(unsigned __int8 *a1)
{
  return sme_enable_active_apf_mode_ind(
           *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL),
           *(unsigned int *)(*(_QWORD *)a1 + 40LL),
           *(_QWORD *)a1 + 1617LL,
           a1[8]);
}
