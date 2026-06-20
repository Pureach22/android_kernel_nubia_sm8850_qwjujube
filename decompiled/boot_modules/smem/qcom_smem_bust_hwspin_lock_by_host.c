__int64 __fastcall qcom_smem_bust_hwspin_lock_by_host(int a1)
{
  if ( (unsigned int)(a1 - 25) >= 0xFFFFFFE8 )
    return hwspin_lock_bust(*(_QWORD *)(_smem + 8), (unsigned int)(a1 + 1));
  else
    return 4294967274LL;
}
