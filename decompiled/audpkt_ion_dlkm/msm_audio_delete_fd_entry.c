__int64 __fastcall msm_audio_delete_fd_entry(__int64 a1, int a2)
{
  __int64 v4; // x9
  __int64 *v5; // x8
  __int64 **v6; // x10
  __int64 v7; // x0
  __int64 v9; // x10

  if ( !a1 || !a2 )
    return printk(&unk_77AB, "msm_audio_delete_fd_entry");
  mutex_lock(&msm_audio_ion_fd_list);
  v4 = qword_7690;
  if ( (__int64 *)qword_7690 != &qword_7690 )
  {
    while ( 1 )
    {
      v5 = *(__int64 **)v4;
      if ( *(_QWORD *)(v4 - 24) == a1 && *(_DWORD *)(v4 - 48) == a2 )
        break;
      v4 = *(_QWORD *)v4;
      if ( v5 == &qword_7690 )
        return mutex_unlock(&msm_audio_ion_fd_list);
    }
    v6 = *(__int64 ***)(v4 + 8);
    v7 = v4 - 48;
    if ( *v6 == (__int64 *)v4 && v5[1] == v4 )
    {
      v5[1] = (__int64)v6;
      *v6 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v4);
      v7 = v9;
    }
    *(_QWORD *)v4 = 0xDEAD000000000100LL;
    *(_QWORD *)(v4 + 8) = 0xDEAD000000000122LL;
    kfree(v7);
  }
  return mutex_unlock(&msm_audio_ion_fd_list);
}
