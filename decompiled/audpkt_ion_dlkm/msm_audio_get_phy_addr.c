__int64 __fastcall msm_audio_get_phy_addr(int a1, _QWORD *a2, _QWORD *a3)
{
  __int64 *v6; // x8

  if ( a2 )
  {
    mutex_lock(&msm_audio_ion_fd_list);
    v6 = &qword_7690;
    while ( 1 )
    {
      v6 = (__int64 *)*v6;
      if ( v6 == &qword_7690 )
        break;
      if ( *((_DWORD *)v6 - 12) == a1 )
      {
        *a2 = *(v6 - 2);
        *a3 = *(v6 - 4);
        mutex_unlock(&msm_audio_ion_fd_list);
        return 0;
      }
    }
    mutex_unlock(&msm_audio_ion_fd_list);
  }
  else
  {
    printk(&unk_7D70, "msm_audio_get_phy_addr");
  }
  return 4294967274LL;
}
