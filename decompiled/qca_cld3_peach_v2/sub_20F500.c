__int64 __fastcall sub_20F500(const char *a1, __int64 *a2, _DWORD *a3)
{
  int v3; // w24

  if ( v3 )
    return qdf_file_read_bytes(a1, a2, a3);
  else
    return ucfg_reg_11d_vdev_delete_update();
}
