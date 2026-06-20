__int64 __fastcall qrtr_gunyah_unshare_mem(__int64 a1, unsigned __int16 a2, char a3)
{
  __int64 v4; // x0
  __int64 v5; // x5
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _DWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 152);
  v7 = (1LL << a3) | (1LL << a2);
  v8[0] = a2;
  v8[1] = 7;
  if ( (unsigned int)ghd_rm_mem_reclaim(v4, 0) )
    dev_err(*(_QWORD *)(a1 + 24), "Gunyah reclaim failed\n");
  result = qcom_scm_assign_mem(*(_QWORD *)(a1 + 56), *(_QWORD *)(a1 + 64) - *(_QWORD *)(a1 + 56) + 1LL, &v7, v8, 1, v5);
  if ( (_DWORD)result )
    result = dev_err(
               *(_QWORD *)(a1 + 24),
               "qcom_scm_assign_mem failed addr=%llx size=%llu err=%d\n",
               *(_QWORD *)(a1 + 56),
               *(_QWORD *)(a1 + 64) - *(_QWORD *)(a1 + 56) + 1LL,
               result);
  _ReadStatusReg(SP_EL0);
  return result;
}
