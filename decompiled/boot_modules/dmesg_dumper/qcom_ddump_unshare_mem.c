__int64 __fastcall qcom_ddump_unshare_mem(__int64 *a1, unsigned __int16 a2, char a3)
{
  __int64 v4; // x0
  int v5; // w0
  __int64 v6; // x5
  __int64 result; // x0
  __int64 v8; // x8
  unsigned int v9; // w19
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  _DWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned int *)a1 + 44);
  v11[0] = a2;
  v11[1] = 7;
  v10 = (1LL << a3) | (1LL << a2);
  v5 = ghd_rm_mem_reclaim(v4, 0);
  if ( v5 )
    dev_err(*a1, "Gunyah mem reclaim failed: %d\n", v5);
  result = qcom_scm_assign_mem(a1[7], a1[8] - a1[7] + 1, &v10, v11, 1, v6);
  if ( (_DWORD)result )
  {
    v8 = *a1;
    v9 = result;
    dev_err(v8, "unshare mem assign call failed with %d\n", result);
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
