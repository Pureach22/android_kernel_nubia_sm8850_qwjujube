__int64 __fastcall dsi_ctrl_check_resource(__int64 a1)
{
  _UNKNOWN **v2; // x8
  __int64 *v3; // x10
  __int64 v4; // x10
  unsigned int v5; // w19

  mutex_lock(&dsi_ctrl_list_lock);
  v2 = (_UNKNOWN **)dsi_ctrl_list;
  while ( v2 != &dsi_ctrl_list )
  {
    v3 = (__int64 *)*(v2 - 1);
    if ( !v3 )
      break;
    v4 = *v3;
    if ( !v4 )
      break;
    v2 = (_UNKNOWN **)*v2;
    if ( *(_QWORD *)(v4 + 760) == a1 )
    {
      v5 = 1;
      goto LABEL_8;
    }
  }
  v5 = 0;
LABEL_8:
  mutex_unlock(&dsi_ctrl_list_lock);
  return v5;
}
