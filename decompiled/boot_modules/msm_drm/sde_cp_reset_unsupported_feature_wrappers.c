_DWORD *__fastcall sde_cp_reset_unsupported_feature_wrappers(_DWORD *result)
{
  if ( !result )
    return (_DWORD *)_drm_err("invalid catalog\n");
  if ( result[4993] )
  {
    if ( result[4995] )
      goto LABEL_4;
  }
  else
  {
    qword_293D20 = (__int64)feature_unsupported;
    qword_293ED8 = (__int64)feature_unsupported;
    check_crtc_pu_feature_wrappers = feature_unsupported;
    set_crtc_pu_feature_wrappers[0] = (__int64)feature_unsupported;
    if ( result[4995] )
    {
LABEL_4:
      if ( result[4994] )
        return result;
LABEL_9:
      off_293DB8 = feature_unsupported;
      qword_293EE0 = (__int64)feature_unsupported;
      qword_293EF0 = (__int64)feature_unsupported;
      qword_293F70 = (__int64)feature_unsupported;
      return result;
    }
  }
  off_293DC0 = feature_unsupported;
  qword_293EF8 = (__int64)feature_unsupported;
  qword_293F78 = (__int64)feature_unsupported;
  if ( !result[4994] )
    goto LABEL_9;
  return result;
}
