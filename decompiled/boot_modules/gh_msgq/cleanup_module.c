__int64 cleanup_module()
{
  _UNKNOWN ***v0; // x21
  _UNKNOWN **v1; // x22

  raw_spin_lock(&gh_msgq_cap_list_lock);
  v0 = (_UNKNOWN ***)gh_msgq_cap_list;
  if ( gh_msgq_cap_list != (_UNKNOWN *)&gh_msgq_cap_list )
  {
    do
    {
      v1 = *v0;
      kfree(*(v0 - 11));
      kfree(*(v0 - 10));
      kfree(v0 - 16);
      v0 = (_UNKNOWN ***)v1;
    }
    while ( v1 != &gh_msgq_cap_list );
  }
  return raw_spin_unlock(&gh_msgq_cap_list_lock);
}
