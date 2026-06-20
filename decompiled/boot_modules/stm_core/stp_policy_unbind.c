__int64 __fastcall stp_policy_unbind(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 136);
  if ( v1 )
  {
    *(_QWORD *)(v1 + 920) = 0;
    *(_QWORD *)(result + 136) = 0;
    stm_put_protocol(*(_QWORD **)(v1 + 1064));
    *(_QWORD *)(v1 + 1064) = 0;
    return stm_put_device(v1);
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
