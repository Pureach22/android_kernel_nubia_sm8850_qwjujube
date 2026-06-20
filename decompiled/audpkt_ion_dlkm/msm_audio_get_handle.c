__int64 __fastcall msm_audio_get_handle(int a1, _QWORD *a2)
{
  __int64 *v4; // x8

  mutex_lock(&msm_audio_ion_fd_list);
  v4 = &qword_7690;
  *a2 = 0;
  while ( 1 )
  {
    v4 = (__int64 *)*v4;
    if ( v4 == &qword_7690 )
      break;
    if ( *((_DWORD *)v4 - 12) == a1 )
    {
      *a2 = *(v4 - 3);
      return mutex_unlock(&msm_audio_ion_fd_list);
    }
  }
  return mutex_unlock(&msm_audio_ion_fd_list);
}
