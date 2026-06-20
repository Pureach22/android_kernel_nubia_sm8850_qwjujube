__int64 __fastcall ieee80211_rate_control_register(__int64 a1)
{
  _UNKNOWN **v2; // x21
  unsigned int v3; // w19
  __int64 v4; // x0
  __int64 *v5; // x1

  if ( *(_QWORD *)(a1 + 8) )
  {
    mutex_lock(&rate_ctrl_mutex);
    v2 = &rate_ctrl_algs;
    while ( 1 )
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &rate_ctrl_algs )
        break;
      if ( !strcmp(*((const char **)v2[2] + 1), *(const char **)(a1 + 8)) )
      {
        __break(0x800u);
        v3 = -114;
        goto LABEL_13;
      }
    }
    v4 = _kmalloc_cache_noprof(mod_timer, 3520, 24);
    if ( v4 )
    {
      *(_QWORD *)(v4 + 16) = a1;
      v5 = (__int64 *)off_51A0;
      if ( off_51A0 == (_UNKNOWN *)v4 || *(_UNKNOWN ***)off_51A0 != &rate_ctrl_algs )
      {
        _list_add_valid_or_report(v4, off_51A0);
        v3 = 0;
      }
      else
      {
        v3 = 0;
        off_51A0 = (_UNKNOWN *)v4;
        *(_QWORD *)v4 = &rate_ctrl_algs;
        *(_QWORD *)(v4 + 8) = v5;
        *v5 = v4;
      }
    }
    else
    {
      v3 = -12;
    }
LABEL_13:
    mutex_unlock(&rate_ctrl_mutex);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v3;
}
