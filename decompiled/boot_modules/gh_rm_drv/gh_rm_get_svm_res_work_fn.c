unsigned __int64 gh_rm_get_svm_res_work_fn()
{
  unsigned __int64 result; // x0
  unsigned __int16 v1; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v2; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = 0;
  if ( (unsigned int)ghd_rm_get_vmid(1, &v1) )
    result = printk(&unk_1223B, "gh_rm_get_svm_res_work_fn");
  else
    result = gh_rm_populate_hyp_res(v1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
