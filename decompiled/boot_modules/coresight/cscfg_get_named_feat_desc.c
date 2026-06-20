_QWORD *__fastcall cscfg_get_named_feat_desc(const char *a1)
{
  __int64 v2; // x20
  _QWORD *v3; // x21
  _QWORD *v4; // x19

  mutex_lock(&cscfg_mutex);
  v2 = cscfg_mgr + 928;
  v3 = (_QWORD *)(cscfg_mgr + 928);
  while ( 1 )
  {
    v3 = (_QWORD *)*v3;
    if ( v3 == (_QWORD *)v2 )
      break;
    if ( !strcmp((const char *)*(v3 - 2), a1) )
    {
      v4 = v3 - 2;
      goto LABEL_6;
    }
  }
  v4 = nullptr;
LABEL_6:
  mutex_unlock(&cscfg_mutex);
  return v4;
}
