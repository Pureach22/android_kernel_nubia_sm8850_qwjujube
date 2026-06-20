__int64 mlme_psoc_ops_ext_hdl_create()
{
  __int64 (*v0)(void); // x8

  if ( !glbl_ops )
    return 0;
  v0 = *(__int64 (**)(void))glbl_ops;
  if ( !*(_QWORD *)glbl_ops )
    return 0;
  if ( *((_DWORD *)v0 - 1) != -326064460 )
    __break(0x8228u);
  return v0();
}
