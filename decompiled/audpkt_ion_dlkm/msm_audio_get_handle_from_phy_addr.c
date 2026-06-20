__int64 __fastcall msm_audio_get_handle_from_phy_addr(_DWORD *a1, __int64 a2, __int64 a3)
{
  __int64 *v6; // x8
  unsigned int v7; // w20

  mutex_lock(&msm_audio_ion_fd_list);
  v6 = (__int64 *)qword_7690;
  if ( (__int64 *)qword_7690 == &qword_7690 )
  {
LABEL_7:
    v7 = -22;
  }
  else
  {
    while ( *(v6 - 2) != a2 || *(v6 - 4) != a3 )
    {
      v6 = (__int64 *)*v6;
      if ( v6 == &qword_7690 )
        goto LABEL_7;
    }
    v7 = 0;
    *a1 = *((_DWORD *)v6 - 12);
  }
  mutex_unlock(&msm_audio_ion_fd_list);
  return v7;
}
