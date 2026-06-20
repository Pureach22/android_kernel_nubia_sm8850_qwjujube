__int64 __fastcall msm_audio_update_fd_list(__int64 a1)
{
  __int64 *v2; // x9
  _QWORD *v3; // x1
  __int64 v4; // x0

  mutex_lock(&msm_audio_ion_fd_list);
  v2 = &qword_7690;
  while ( 1 )
  {
    v2 = (__int64 *)*v2;
    if ( v2 == &qword_7690 )
      break;
    if ( *((_DWORD *)v2 - 12) == *(_DWORD *)a1 )
    {
      printk(&unk_7D07, "msm_audio_update_fd_list");
      return mutex_unlock(&msm_audio_ion_fd_list);
    }
  }
  v3 = (_QWORD *)qword_7698;
  v4 = a1 + 48;
  if ( (_UNKNOWN *)a1 == &msm_audio_ion_fd_list || qword_7698 == v4 || *(__int64 **)qword_7698 != &qword_7690 )
  {
    _list_add_valid_or_report(v4, qword_7698, &qword_7690);
  }
  else
  {
    qword_7698 = a1 + 48;
    *(_QWORD *)(a1 + 48) = &qword_7690;
    *(_QWORD *)(a1 + 56) = v3;
    *v3 = v4;
  }
  return mutex_unlock(&msm_audio_ion_fd_list);
}
