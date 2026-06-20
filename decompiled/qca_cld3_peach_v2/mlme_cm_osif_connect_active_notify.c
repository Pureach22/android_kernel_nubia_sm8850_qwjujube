__int64 mlme_cm_osif_connect_active_notify()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( glbl_cm_ops )
  {
    v0 = *(__int64 (**)(void))glbl_cm_ops;
    if ( *(_QWORD *)glbl_cm_ops )
    {
      if ( *((_DWORD *)v0 - 1) != -1560483463 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
