__int64 init_module()
{
  unsigned int v0; // w19
  __int64 v1; // x24
  _QWORD *v2; // x26
  __int64 v3; // x0

  v0 = 0;
  v1 = 0x1FFFFFFFFFFFFF88LL;
  while ( 1 )
  {
    v2 = &gh_dbl_cap_table[v1];
    LODWORD(gh_dbl_cap_table[v1 + 121]) = 0;
    _init_waitqueue_head(&gh_dbl_cap_table[v1 + 129], "&entry->cap_wq", &gh_dbl_init___key);
    v2[122] = -1;
    v2[124] = -1;
    v3 = kasprintf(3264, "gh_dbl_rx_%d", v0);
    v2[126] = v3;
    if ( !v3 )
      break;
    v1 += 12;
    ++v0;
    if ( !(v1 * 8) )
    {
      gh_dbl_initialized = 1;
      return 0;
    }
  }
  gh_dbl_cleanup(v0);
  return 4294967284LL;
}
