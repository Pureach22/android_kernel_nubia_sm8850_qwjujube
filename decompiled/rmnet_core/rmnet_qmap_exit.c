void rmnet_qmap_exit()
{
  void (__fastcall *v0)(_QWORD); // x8
  __int64 v1; // x0

  if ( rmnet_ctl )
  {
    v0 = *(void (__fastcall **)(_QWORD))(rmnet_ctl + 8);
    if ( v0 )
    {
      v1 = rmnet_ctl_handle;
      if ( *((_DWORD *)v0 - 1) != -1066802076 )
        __break(0x8228u);
      v0(v1);
    }
  }
  rmnet_ctl_handle = 0;
  real_data_dev = 0;
  rmnet_port = 0;
}
