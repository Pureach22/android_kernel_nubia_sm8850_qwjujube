__int64 __fastcall bss_free(__int64 result)
{
  __int64 v1; // x1
  _QWORD *v2; // x19
  __int64 v3; // x1

  if ( *(_DWORD *)(result + 80) )
  {
    __break(0x800u);
  }
  else
  {
    v1 = *(_QWORD *)(result + 128);
    v2 = (_QWORD *)result;
    if ( v1 && !*(_QWORD *)(result + 144) )
      kvfree_call_rcu(v1 + 8, v1);
    v3 = v2[17];
    if ( v3 )
      kvfree_call_rcu(v3 + 8, v3);
    if ( (_QWORD *)v2[2] != v2 + 2 )
    {
      _list_del_entry(v2 + 2);
      v2[2] = 0xDEAD000000000100LL;
      v2[3] = 0xDEAD000000000122LL;
    }
    return kfree(v2);
  }
  return result;
}
