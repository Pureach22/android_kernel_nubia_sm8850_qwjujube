__int64 __fastcall msm_drm_commit_work_cb(__int64 a1)
{
  if ( !a1 )
    return _drm_err("%s: Invalid commit work data!\n", "_msm_drm_commit_work_cb");
  _ReadStatusReg(SP_EL0);
  return complete_commit(a1 - 32);
}
