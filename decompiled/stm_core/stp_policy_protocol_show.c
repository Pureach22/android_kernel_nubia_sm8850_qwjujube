__int64 __fastcall stp_policy_protocol_show(__int64 a1, char *s)
{
  __int64 v2; // x8
  const char *v3; // x2

  if ( a1 && (v2 = *(_QWORD *)(a1 + 136)) != 0 )
    v3 = *(const char **)(*(_QWORD *)(v2 + 1064) + 8LL);
  else
    v3 = "<none>";
  return sprintf(s, "%s\n", v3);
}
