__int64 __fastcall action_oui_is_empty(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  bool v4; // w19

  if ( (unsigned int)a2 >= 0x1C )
  {
    __break(0x5512u);
    return action_oui_search(a1, a2, a3);
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 8LL * (unsigned int)a2 + 23544);
    if ( v3 )
    {
      qdf_mutex_acquire(v3 + 32);
      v4 = qdf_list_empty((_QWORD *)(v3 + 8));
      qdf_mutex_release(v3 + 32);
    }
    else
    {
      return 1;
    }
    return v4;
  }
}
