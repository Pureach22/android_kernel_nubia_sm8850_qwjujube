__int64 __fastcall rmnet_qmap_init(__int64 a1)
{
  __int64 (__fastcall **v1)(_QWORD); // x0
  __int64 v2; // x1
  __int64 (__fastcall *v3)(_QWORD); // x8
  void *v5; // x0

  if ( !rmnet_ctl_handle )
  {
    qmap_txid = 0;
    rmnet_port = a1;
    real_data_dev = rmnet_get_real_dev(a1);
    v1 = (__int64 (__fastcall **)(_QWORD))rmnet_ctl_if();
    rmnet_ctl = (__int64)v1;
    if ( !v1 )
    {
      v5 = &unk_2D4DE;
      goto LABEL_12;
    }
    v3 = *v1;
    if ( *v1 )
    {
      if ( *((_DWORD *)v3 - 1) != -421918554 )
        __break(0x8228u);
      rmnet_ctl_handle = v3(&cb);
      if ( rmnet_ctl_handle )
        return 0;
      goto LABEL_10;
    }
    if ( !rmnet_ctl_handle )
    {
LABEL_10:
      v5 = &unk_2CC1D;
LABEL_12:
      printk(v5, v2);
      return 4294967282LL;
    }
  }
  return 0;
}
