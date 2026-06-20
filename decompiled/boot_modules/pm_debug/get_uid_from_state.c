__int64 __fastcall get_uid_from_state(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w19

  if ( result )
  {
    v1 = result;
    if ( *(_QWORD *)(result + 24) )
    {
      _rcu_read_lock();
      v2 = *(_QWORD *)(v1 + 24);
      if ( v2 && ((1 << *(_BYTE *)(v2 + 18)) & 0xFFFFEFBF) != 0 )
        v3 = sock_i_uid();
      else
        v3 = 0;
      _rcu_read_unlock();
      return v3;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
