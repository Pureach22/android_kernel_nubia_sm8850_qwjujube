__int64 __fastcall get_policy_node_type(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x8

  result = kmemdup_noprof(&stp_policy_node_type, 40, 3264);
  if ( result )
  {
    v3 = result;
    v4 = _memcat_p(stp_policy_node_attrs, a1);
    if ( v4 )
    {
      v5 = v4;
      *(_QWORD *)(v3 + 24) = v5;
      return v3;
    }
    else
    {
      kfree(v3);
      return 0;
    }
  }
  return result;
}
