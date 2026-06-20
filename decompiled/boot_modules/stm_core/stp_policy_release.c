__int64 __fastcall stp_policy_release(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 v3; // x20

  v1 = *(_QWORD *)(result + 136);
  if ( v1 )
  {
    v2 = result;
    mutex_lock(v1 + 928);
    v3 = *(_QWORD *)(v2 + 136);
    if ( v3 )
    {
      *(_QWORD *)(v3 + 920) = 0;
      *(_QWORD *)(v2 + 136) = 0;
      stm_put_protocol(*(_QWORD **)(v3 + 1064));
      *(_QWORD *)(v3 + 1064) = 0;
      stm_put_device(v3);
    }
    else
    {
      __break(0x800u);
    }
    mutex_unlock(v1 + 928);
    return kfree(v2);
  }
  return result;
}
